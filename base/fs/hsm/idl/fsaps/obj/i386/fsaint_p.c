

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for fsaint.idl:
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


#include "fsaint.h"

#define TYPE_FORMAT_STRING_SIZE   557                               
#define PROC_FORMAT_STRING_SIZE   9745                              
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


extern const MIDL_SERVER_INFO IFsaFilter_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaFilter_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaFilterClient_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaFilterClient_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaFilterRecall_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaFilterRecall_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaResource_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaResource_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaScanItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaScanItem_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaTruncator_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaTruncator_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaPostIt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaPostIt_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaRecallNotifyClient_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifyClient_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaRecallNotifyServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifyServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaRecallNotifySend_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifySend_ProxyInfo;



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

	/* Procedure Cancel */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 24 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelRecall */

/* 30 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 32 */	NdrFcLong( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x4 ),	/* 4 */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	NdrFcShort( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 46 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 54 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 56 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 58 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIdentifier */

/* 66 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x5 ),	/* 5 */
/* 74 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 76 */	NdrFcShort( 0x30 ),	/* 48 */
/* 78 */	NdrFcShort( 0x22 ),	/* 34 */
/* 80 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 82 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 90 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 92 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 94 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter pResult */

/* 96 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 98 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 100 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIFilter */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x6 ),	/* 6 */
/* 116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x22 ),	/* 34 */
/* 122 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 124 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFilter */

/* 132 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 136 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Parameter pResult */

/* 138 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 146 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteRecall */

/* 150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x7 ),	/* 7 */
/* 158 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 164 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 166 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 174 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 176 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 178 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 180 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 182 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumRecalls */

/* 186 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 188 */	NdrFcLong( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 194 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 200 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 202 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 210 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 212 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 214 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 216 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 218 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 222 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 224 */	NdrFcLong( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x9 ),	/* 9 */
/* 230 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x4c ),	/* 76 */
/* 236 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 238 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 246 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 248 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 250 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 254 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMachineName */


	/* Procedure GetLogicalName */

/* 258 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0xa ),	/* 10 */
/* 266 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 272 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 274 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 282 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 284 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 286 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 288 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 290 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResult */


	/* Procedure GetAutosave */


	/* Procedure GetRecallCount */


	/* Procedure GetMaxRecallBuffers */

/* 300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0xb ),	/* 11 */
/* 308 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x24 ),	/* 36 */
/* 314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 316 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pHr */


	/* Parameter pMilliseconds */


	/* Parameter pCount */


	/* Parameter pMaxBuffers */

/* 324 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxRecalls */

/* 336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0xc ),	/* 12 */
/* 344 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x24 ),	/* 36 */
/* 350 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 352 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMaxRecalls */

/* 360 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecallFlags */


	/* Procedure GetMinRecallInterval */

/* 372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0xd ),	/* 13 */
/* 380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x24 ),	/* 36 */
/* 386 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 388 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recallFlags */


	/* Parameter pMinIterval */

/* 396 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 398 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 404 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0xe ),	/* 14 */
/* 416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x24 ),	/* 36 */
/* 422 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 424 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 432 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 434 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 436 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsEnabled */

/* 444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0xf ),	/* 15 */
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

/* 468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Pause */

/* 474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x10 ),	/* 16 */
/* 482 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 488 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 490 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 500 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateDefaultRules */


	/* Procedure Resume */

/* 504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x11 ),	/* 17 */
/* 512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 518 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 520 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 530 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAdminExemption */

/* 534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x12 ),	/* 18 */
/* 542 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x24 ),	/* 36 */
/* 548 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 550 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isExempt */

/* 558 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 560 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 564 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 566 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMode */


	/* Procedure SetIsEnabled */

/* 570 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 572 */	NdrFcLong( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x13 ),	/* 19 */
/* 578 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 582 */	NdrFcShort( 0x8 ),	/* 8 */
/* 584 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 586 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mode */


	/* Parameter isEnabled */

/* 594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 596 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 602 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxRecalls */

/* 606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 612 */	NdrFcShort( 0x14 ),	/* 20 */
/* 614 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 620 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 622 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter maxRecalls */

/* 630 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 632 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 638 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRecallCount */


	/* Procedure SetMinRecallInterval */

/* 642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x15 ),	/* 21 */
/* 650 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 652 */	NdrFcShort( 0x8 ),	/* 8 */
/* 654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 656 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 658 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter count */


	/* Parameter minIterval */

/* 666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 674 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxRecallBuffers */

/* 678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x16 ),	/* 22 */
/* 686 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 692 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 694 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter maxBuffers */

/* 702 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 704 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 710 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ScanForResources */


	/* Procedure StartIdentify */


	/* Procedure Start */

/* 714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0x17 ),	/* 23 */
/* 722 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 728 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 730 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 740 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StopIoctlThread */

/* 744 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 750 */	NdrFcShort( 0x18 ),	/* 24 */
/* 752 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 758 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 760 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 770 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindRecall */

/* 774 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x19 ),	/* 25 */
/* 782 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 784 */	NdrFcShort( 0x30 ),	/* 48 */
/* 786 */	NdrFcShort( 0x8 ),	/* 8 */
/* 788 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 790 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recallId */

/* 798 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 800 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 802 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter pRecall */

/* 804 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 806 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 808 */	NdrFcShort( 0x66 ),	/* Type Offset=102 */

	/* Return value */

/* 810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 812 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAdminExemption */

/* 816 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x1a ),	/* 26 */
/* 824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 830 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 832 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isExempt */

/* 840 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 842 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 848 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareBy */

/* 852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x3 ),	/* 3 */
/* 860 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 862 */	NdrFcShort( 0x6 ),	/* 6 */
/* 864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 866 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 868 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter by */

/* 876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 878 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 880 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 882 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 884 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToAuthenticationId */

/* 888 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 890 */	NdrFcLong( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x4 ),	/* 4 */
/* 896 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 898 */	NdrFcShort( 0x10 ),	/* 16 */
/* 900 */	NdrFcShort( 0x22 ),	/* 34 */
/* 902 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 904 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter luidHigh */

/* 912 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 914 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter luidLow */

/* 918 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 920 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 924 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 926 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 928 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 930 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 932 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIClient */

/* 936 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 938 */	NdrFcLong( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x5 ),	/* 5 */
/* 944 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 948 */	NdrFcShort( 0x22 ),	/* 34 */
/* 950 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 952 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClient */

/* 960 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 962 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 964 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter pResult */

/* 966 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 968 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 970 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 974 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToMachineName */

/* 978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0x6 ),	/* 6 */
/* 986 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x22 ),	/* 34 */
/* 992 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 994 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1002 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1004 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1006 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 1008 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1010 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1012 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1014 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1016 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAuthenticationId */

/* 1020 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1026 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1028 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1034 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1036 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLuidHigh */

/* 1044 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1046 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pluidLow */

/* 1050 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1052 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1058 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */


	/* Procedure GetDomainName */

/* 1062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1070 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1072 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1076 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1078 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 1086 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1088 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1090 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 1092 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1094 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1098 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1100 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLastRecallTime */

/* 1104 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1112 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1118 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1120 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 1128 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1130 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1132 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 1134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1136 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUserName */


	/* Procedure GetDbPath */


	/* Procedure GetUserName */

/* 1140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0xc ),	/* 12 */
/* 1148 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1154 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1156 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pPath */


	/* Parameter pName */

/* 1164 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1166 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1168 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 1170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1172 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1178 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WasCancelled */


	/* Procedure HasRecallDisabled */

/* 1182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0xd ),	/* 13 */
/* 1190 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1196 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1198 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1206 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1208 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure KickStart */


	/* Procedure HitRecallLimit */

/* 1212 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1214 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0xe ),	/* 14 */
/* 1220 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1224 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1226 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1228 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1238 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAuthenticationId */

/* 1242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0xf ),	/* 15 */
/* 1250 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1252 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1254 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1256 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1258 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter luidHigh */

/* 1266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1268 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter luidLow */

/* 1272 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1274 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDomainName */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1298 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1300 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1308 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1310 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1312 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 1314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1316 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHasRecallDisabled */

/* 1320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1328 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1334 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1336 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isDisabled */

/* 1344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HasCompleted */


	/* Procedure SetHitRecallLimit */

/* 1356 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1364 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1370 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1372 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter resultHr */


	/* Parameter hitLimit */

/* 1380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1382 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1388 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLastRecallTime */

/* 1392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1400 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1402 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1406 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1408 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter time */

/* 1416 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1418 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1420 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 1422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1424 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPath */


	/* Procedure SetMachineName */

/* 1428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1434 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1436 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1442 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1444 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */


	/* Parameter pName */

/* 1452 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1454 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1456 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */


	/* Return value */

/* 1458 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1460 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUserName */

/* 1464 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1470 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1472 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1476 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1478 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1480 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1488 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1490 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1492 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 1494 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1496 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTokenSource */

/* 1500 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1502 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1506 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1508 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1510 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1514 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1516 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1522 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter source */

/* 1524 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1526 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1528 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1532 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendRecallInfo */

/* 1536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1542 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1544 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1546 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1548 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1550 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1552 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1558 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 1560 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1562 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1564 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter starting */

/* 1566 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1568 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rHr */

/* 1572 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1574 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1578 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1580 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IdentifyThread */

/* 1584 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1586 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1592 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1598 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1600 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1606 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1608 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1610 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1612 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsAdmin */

/* 1614 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1616 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1620 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1622 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1624 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1626 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1628 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1630 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1636 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isAdmin */

/* 1638 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1640 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1642 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 1644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1646 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIsAdmin */

/* 1650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1656 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1658 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1662 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1664 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1666 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isAdmin */

/* 1674 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1676 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1678 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 1680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1682 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckRecallLimit */

/* 1686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1692 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1694 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1696 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1700 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1702 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1708 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter minRecallInterval */

/* 1710 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1712 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter maxRecalls */

/* 1716 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1718 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter exemptAdmin */

/* 1722 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1724 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1726 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 1728 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1730 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIdentifier */

/* 1734 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1740 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1742 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1744 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1746 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1748 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1750 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1756 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 1758 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1760 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1762 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter pResult */

/* 1764 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1766 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1768 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1772 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIRecall */

/* 1776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1784 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1790 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1792 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 1800 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1802 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1804 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pResult */

/* 1806 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1808 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1810 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1814 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToDriversRecallId */

/* 1818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1826 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1828 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1830 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1832 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1834 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 1842 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1846 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 1848 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1850 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1852 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1854 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1856 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToDriversContextId */

/* 1860 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1868 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1870 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1872 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1874 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1876 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1882 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 1884 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1886 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1888 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 1890 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1892 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1894 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1898 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareBy */

/* 1902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1908 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1910 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1912 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1914 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1916 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1918 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1924 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter by */

/* 1926 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1928 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1930 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 1932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1934 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 1938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1946 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1950 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1952 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1954 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 1962 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1964 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1966 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 1968 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1970 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecallFlags */


	/* Procedure GetMode */

/* 1974 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1976 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1980 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1982 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1988 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1990 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1996 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recallFlags */


	/* Parameter pMode */

/* 1998 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2000 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2006 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSize */


	/* Procedure GetRequestSize */


	/* Procedure GetOffset */

/* 2010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0xa ),	/* 10 */
/* 2018 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2022 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2024 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2026 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2032 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */


	/* Parameter pRequestSize */


	/* Parameter pOffset */

/* 2034 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2036 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2038 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2040 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2042 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2044 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 2046 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2048 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0xb ),	/* 11 */
/* 2054 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2056 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2058 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2060 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2062 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 2070 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2072 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2074 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 2076 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2078 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2082 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2084 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResource */

/* 2088 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2090 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2094 */	NdrFcShort( 0xc ),	/* 12 */
/* 2096 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2100 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2102 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2104 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppResource */

/* 2112 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2114 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2116 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 2118 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2120 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 2124 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2126 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2130 */	NdrFcShort( 0xe ),	/* 14 */
/* 2132 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2136 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2138 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2140 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2146 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 2148 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2150 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2152 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 2154 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2156 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUSN */


	/* Procedure GetFileUsn */


	/* Procedure GetSize */

/* 2160 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2162 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2166 */	NdrFcShort( 0xf ),	/* 15 */
/* 2168 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2172 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2174 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2176 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pUsn */


	/* Parameter pFileUsn */


	/* Parameter pSize */

/* 2184 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2186 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2188 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2192 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 2196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2202 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2204 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2208 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2210 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2212 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 2220 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2222 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2224 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 2226 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIDbPath */


	/* Procedure GetGroup */


	/* Procedure GetUserName */

/* 2232 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2240 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2244 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2246 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2248 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2254 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */


	/* Parameter pOwner */


	/* Parameter pName */

/* 2256 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2258 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2260 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 2262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2264 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2270 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WasCancelled */

/* 2274 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2280 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2282 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2288 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2290 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2296 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2298 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2300 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateLocalStream */

/* 2304 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2310 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2312 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2316 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2318 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2320 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2326 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppStream */

/* 2328 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2330 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2332 */	NdrFcShort( 0xc4 ),	/* Type Offset=196 */

	/* Return value */

/* 2334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2336 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckRecallLimit */

/* 2340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2348 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2350 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2354 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 2356 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter minRecallInterval */

/* 2364 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2366 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter maxRecalls */

/* 2370 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2372 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter exemptAdmin */

/* 2376 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2378 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2380 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 2382 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2384 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2386 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddClient */

/* 2388 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2390 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2394 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2396 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2400 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2402 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2404 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2410 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWaitingClient */

/* 2412 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2414 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2416 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 2418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2420 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddPremigrated */

/* 2424 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2430 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2432 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2434 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2438 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2440 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2446 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 2448 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2450 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2452 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 2454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2456 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2458 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 2460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2462 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2464 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter isWaitingForClose */

/* 2466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2468 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter usn */

/* 2472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2474 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2476 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2480 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddTruncated */

/* 2484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2490 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2492 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2494 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2498 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2500 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 2508 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2510 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2512 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 2514 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2516 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2518 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 2520 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2522 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2524 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2528 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BeginSession */

/* 2532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2538 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2540 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2542 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2546 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2548 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2556 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2558 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2560 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter logControl */

/* 2562 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2564 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter runId */

/* 2568 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2570 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter subRunId */

/* 2574 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2576 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppSession */

/* 2580 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2582 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2584 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 2586 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2588 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BeginValidate */

/* 2592 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2594 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2598 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2600 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2604 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2606 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2608 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2614 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2616 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2618 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckForValidate */

/* 2622 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2628 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2630 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2634 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2636 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2638 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2644 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bForceValidate */

/* 2646 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2648 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2652 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2654 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareBy */

/* 2658 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2660 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2664 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2666 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2668 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2672 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2674 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2680 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter by */

/* 2682 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2684 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2686 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 2688 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2690 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToAlternatePath */

/* 2694 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2700 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2702 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2706 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2708 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2710 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2716 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 2718 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2720 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2722 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 2724 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2726 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2728 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2730 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2732 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIdentifier */

/* 2736 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2742 */	NdrFcShort( 0xa ),	/* 10 */
/* 2744 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2746 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2748 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2750 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2752 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2758 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 2760 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2762 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2764 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter pResult */

/* 2766 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2768 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2770 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2772 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2774 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIResource */

/* 2778 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2784 */	NdrFcShort( 0xb ),	/* 11 */
/* 2786 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2790 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2792 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2794 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2800 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 2802 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2804 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2806 */	NdrFcShort( 0x9c ),	/* Type Offset=156 */

	/* Parameter pResult */

/* 2808 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2810 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2812 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2814 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2816 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToName */

/* 2820 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2826 */	NdrFcShort( 0xc ),	/* 12 */
/* 2828 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2832 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2834 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2836 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2844 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2846 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2848 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 2850 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2852 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2854 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2856 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2858 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToUserName */

/* 2862 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2864 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2868 */	NdrFcShort( 0xd ),	/* 13 */
/* 2870 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2874 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2876 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2878 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2884 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter userName */

/* 2886 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2888 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2890 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 2892 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2894 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2896 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2898 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2900 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToPath */

/* 2904 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2906 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2910 */	NdrFcShort( 0xe ),	/* 14 */
/* 2912 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2916 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2918 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2920 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 2928 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2930 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2932 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 2934 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2936 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2938 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2940 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2942 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToSerial */

/* 2946 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2952 */	NdrFcShort( 0xf ),	/* 15 */
/* 2954 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2956 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2958 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2960 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2962 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2968 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serial */

/* 2970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2972 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 2976 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2978 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2980 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2984 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToStickyName */

/* 2988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2994 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2996 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3000 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3002 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3004 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3010 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3012 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3014 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3016 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 3018 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3020 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3022 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3024 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3026 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EndSession */

/* 3030 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3036 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3038 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3044 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3046 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3052 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 3054 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3056 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3058 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Return value */

/* 3060 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3062 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EndValidate */

/* 3066 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3068 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3072 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3074 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3076 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3080 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3082 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3088 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter state */

/* 3090 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3092 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3094 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3096 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3098 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumDefaultRules */

/* 3102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3108 */	NdrFcShort( 0x14 ),	/* 20 */
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

	/* Parameter ppEnum */

/* 3126 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3130 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 3132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3134 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirst */

/* 3138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3144 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3146 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3152 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3154 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 3162 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3166 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pSession */

/* 3168 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3170 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3172 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter ppScanItem */

/* 3174 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3176 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3178 */	NdrFcShort( 0xec ),	/* Type Offset=236 */

	/* Return value */

/* 3180 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3182 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirstInRPIndex */

/* 3186 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3188 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3192 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3194 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3200 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3202 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3208 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 3210 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3212 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3214 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter ppScanItem */

/* 3216 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3218 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3220 */	NdrFcShort( 0xec ),	/* Type Offset=236 */

	/* Return value */

/* 3222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3224 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirstInDbIndex */

/* 3228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3234 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3236 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3242 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3244 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 3252 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3256 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter ppScanItem */

/* 3258 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3262 */	NdrFcShort( 0xec ),	/* Type Offset=236 */

	/* Return value */

/* 3264 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3266 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNext */

/* 3270 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3272 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3276 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3278 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3284 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3286 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3292 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 3294 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3296 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3298 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Return value */

/* 3300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3302 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNextInRPIndex */

/* 3306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x19 ),	/* 25 */
/* 3314 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3318 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3320 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3322 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 3330 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3334 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Return value */

/* 3336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNextInDbIndex */

/* 3342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3348 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3350 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3356 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3358 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 3366 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3368 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3370 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Return value */

/* 3372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3374 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFileId */

/* 3378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3384 */	NdrFcShort( 0x1b ),	/* 27 */
/* 3386 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3388 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3392 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3394 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileId */

/* 3402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3406 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSession */

/* 3408 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3410 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3412 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter ppScanItem */

/* 3414 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3416 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3418 */	NdrFcShort( 0xec ),	/* Type Offset=236 */

	/* Return value */

/* 3420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3422 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindObjectId */

/* 3426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3432 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3434 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3436 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3440 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3442 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3448 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter objIdHi */

/* 3450 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3452 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3454 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter objIdLo */

/* 3456 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3458 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3460 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSession */

/* 3462 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3464 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3466 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter ppScanItem */

/* 3468 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3470 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3472 */	NdrFcShort( 0xec ),	/* Type Offset=236 */

	/* Return value */

/* 3474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3476 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAlternatePath */

/* 3480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3486 */	NdrFcShort( 0x1d ),	/* 29 */
/* 3488 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3494 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3504 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3508 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 3510 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3516 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3518 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDefaultRules */

/* 3522 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3528 */	NdrFcShort( 0x1e ),	/* 30 */
/* 3530 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3536 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3538 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 3546 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3548 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3550 */	NdrFcShort( 0xf0 ),	/* Type Offset=240 */

	/* Return value */

/* 3552 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3554 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDbPath */

/* 3558 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3564 */	NdrFcShort( 0x1f ),	/* 31 */
/* 3566 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3568 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3572 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3574 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3580 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3582 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3584 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3586 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 3588 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3590 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3594 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3596 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUnmanageDbPath */

/* 3600 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3606 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3608 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3612 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3614 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3616 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3622 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3624 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3626 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3628 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 3630 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3632 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3638 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFreeLevel */

/* 3642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3648 */	NdrFcShort( 0x21 ),	/* 33 */
/* 3650 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3654 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3656 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3658 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLevel */

/* 3666 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3674 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFsName */

/* 3678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3684 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3686 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3692 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3694 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 3702 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3704 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3706 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 3708 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3710 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3716 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmEngine */

/* 3720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3726 */	NdrFcShort( 0x23 ),	/* 35 */
/* 3728 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3734 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3736 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEngine */

/* 3744 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3746 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3748 */	NdrFcShort( 0x106 ),	/* Type Offset=262 */

	/* Return value */

/* 3750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3752 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmLevel */

/* 3756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3762 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3764 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3768 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3770 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3772 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLevel */

/* 3780 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 3792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3798 */	NdrFcShort( 0x25 ),	/* 37 */
/* 3800 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3804 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3806 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3808 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 3816 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3820 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 3822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3824 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogicalName */

/* 3828 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3834 */	NdrFcShort( 0x26 ),	/* 38 */
/* 3836 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3842 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3844 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 3852 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3854 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3856 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 3858 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3864 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3866 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManageableItemLogicalSize */

/* 3870 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3876 */	NdrFcShort( 0x27 ),	/* 39 */
/* 3878 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3882 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3884 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3886 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3892 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 3894 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3896 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3898 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3902 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManageableItemAccessTime */

/* 3906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3912 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3914 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3918 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3920 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3922 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isRelative */

/* 3930 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3932 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pTime */

/* 3936 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 3938 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3940 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 3942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3944 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManagingHsm */

/* 3948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3954 */	NdrFcShort( 0x29 ),	/* 41 */
/* 3956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3960 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3962 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3964 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 3972 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3974 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3976 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 3978 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 3984 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3986 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3990 */	NdrFcShort( 0x2a ),	/* 42 */
/* 3992 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3998 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4000 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 4008 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4010 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4012 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4016 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4022 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOldPath */

/* 4026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4032 */	NdrFcShort( 0x2b ),	/* 43 */
/* 4034 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4040 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4042 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 4050 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4052 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4054 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4056 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4058 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4064 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 4068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4074 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4076 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4080 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4082 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4084 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 4092 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4094 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4096 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4098 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4100 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4106 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSerial */

/* 4110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4116 */	NdrFcShort( 0x2d ),	/* 45 */
/* 4118 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4122 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4124 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4126 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serial */

/* 4134 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSizes */

/* 4146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4152 */	NdrFcShort( 0x2e ),	/* 46 */
/* 4154 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4158 */	NdrFcShort( 0x98 ),	/* 152 */
/* 4160 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 4162 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTotal */

/* 4170 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4172 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4174 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pFree */

/* 4176 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4180 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPremigrated */

/* 4182 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4184 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4186 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pTruncated */

/* 4188 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4190 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4192 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4194 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4196 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTruncator */

/* 4200 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4206 */	NdrFcShort( 0x2f ),	/* 47 */
/* 4208 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4214 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4216 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4222 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppTruncator */

/* 4224 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4226 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4228 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 4230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4232 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUncPath */

/* 4236 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4242 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4244 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4248 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4250 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4252 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 4260 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4262 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4264 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4268 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4274 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUserFriendlyName */

/* 4278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4284 */	NdrFcShort( 0x31 ),	/* 49 */
/* 4286 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4292 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4294 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 4302 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4306 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4308 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4316 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStickyName */

/* 4320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4326 */	NdrFcShort( 0x32 ),	/* 50 */
/* 4328 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4334 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4336 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 4344 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4348 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4358 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsActive */

/* 4362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4368 */	NdrFcShort( 0x33 ),	/* 51 */
/* 4370 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4374 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4376 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4378 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4388 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsAvailable */

/* 4392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4398 */	NdrFcShort( 0x34 ),	/* 52 */
/* 4400 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4406 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4408 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4418 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsDeletePending */

/* 4422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4428 */	NdrFcShort( 0x35 ),	/* 53 */
/* 4430 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4436 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4438 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4444 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4448 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsManaged */

/* 4452 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4458 */	NdrFcShort( 0x36 ),	/* 54 */
/* 4460 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4466 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4468 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4474 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4476 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4478 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Manage */

/* 4482 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4488 */	NdrFcShort( 0x37 ),	/* 55 */
/* 4490 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 4492 */	NdrFcShort( 0x58 ),	/* 88 */
/* 4494 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4496 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 4498 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4506 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4508 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4510 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 4512 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4514 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4516 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 4518 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4520 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4522 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter storagePoolId */

/* 4524 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4526 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4528 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter truncate */

/* 4530 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4532 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4536 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4538 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 4540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ManagedBy */

/* 4542 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4544 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4548 */	NdrFcShort( 0x38 ),	/* 56 */
/* 4550 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4552 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4554 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4556 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 4558 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4564 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hsmId */

/* 4566 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4568 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4570 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter hsmLevel */

/* 4572 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4574 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter release */

/* 4578 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4580 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4586 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NeedsRepair */

/* 4590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4596 */	NdrFcShort( 0x39 ),	/* 57 */
/* 4598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4604 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4606 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4616 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessResult */

/* 4620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4626 */	NdrFcShort( 0x3a ),	/* 58 */
/* 4628 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4634 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4636 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4642 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResult */

/* 4644 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4646 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4648 */	NdrFcShort( 0x132 ),	/* Type Offset=306 */

	/* Return value */

/* 4650 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4652 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Recall */

/* 4656 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4658 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4662 */	NdrFcShort( 0x3b ),	/* 59 */
/* 4664 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4666 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4668 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4670 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4672 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4678 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4680 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4682 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4684 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 4686 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4688 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4690 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 4692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4694 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4696 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter deletePlaceholder */

/* 4698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4700 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4704 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4706 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemovePremigrated */

/* 4710 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4712 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4716 */	NdrFcShort( 0x3c ),	/* 60 */
/* 4718 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4720 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4724 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4726 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4732 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4734 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4736 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4738 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 4740 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4742 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4744 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 4746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4748 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4750 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4754 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveTruncated */

/* 4758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4764 */	NdrFcShort( 0x3d ),	/* 61 */
/* 4766 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4768 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4772 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4774 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4780 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4782 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4784 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4786 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 4788 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4790 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4792 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 4794 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4796 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4798 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4802 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHsmLevel */

/* 4806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4812 */	NdrFcShort( 0x3e ),	/* 62 */
/* 4814 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4816 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4820 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4822 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4828 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter level */

/* 4830 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4832 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4836 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4838 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsActive */

/* 4842 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4844 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4848 */	NdrFcShort( 0x3f ),	/* 63 */
/* 4850 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4856 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4858 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4864 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isActive */

/* 4866 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4868 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4872 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4874 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsAvailable */

/* 4878 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4884 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4886 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4892 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4894 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4900 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isActive */

/* 4902 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4904 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4908 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4910 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsDeletePending */

/* 4914 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4916 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4920 */	NdrFcShort( 0x41 ),	/* 65 */
/* 4922 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4926 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4928 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4930 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4936 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isDeletePending */

/* 4938 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4940 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4946 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetManageableItemLogicalSize */

/* 4950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4956 */	NdrFcShort( 0x42 ),	/* 66 */
/* 4958 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4960 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4964 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4966 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 4974 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4976 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4978 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4980 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4982 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetManageableItemAccessTime */

/* 4986 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4988 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4992 */	NdrFcShort( 0x43 ),	/* 67 */
/* 4994 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4996 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4998 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5000 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5002 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5008 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isRelative */

/* 5010 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5012 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5014 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pTime */

/* 5016 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5018 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5020 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 5022 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5024 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSerial */

/* 5028 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5030 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5034 */	NdrFcShort( 0x44 ),	/* 68 */
/* 5036 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5040 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5042 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5044 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5050 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serial */

/* 5052 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5054 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5058 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5060 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StartJob */

/* 5064 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5070 */	NdrFcShort( 0x45 ),	/* 69 */
/* 5072 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5076 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5078 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5080 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5086 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter startingPath */

/* 5088 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5090 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5092 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pSession */

/* 5094 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5096 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5098 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Return value */

/* 5100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5102 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StartJobSession */

/* 5106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5112 */	NdrFcShort( 0x46 ),	/* 70 */
/* 5114 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5120 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5122 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5128 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pJob */

/* 5130 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5132 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5134 */	NdrFcShort( 0x144 ),	/* Type Offset=324 */

	/* Parameter subRunId */

/* 5136 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5138 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppSession */

/* 5142 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5144 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5146 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 5148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5150 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Validate */

/* 5154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5160 */	NdrFcShort( 0x47 ),	/* 71 */
/* 5162 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 5164 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5168 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5170 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 5178 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5180 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5182 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 5184 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5186 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5188 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5190 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5192 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5194 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter usn */

/* 5196 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5198 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5200 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5204 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetupValidateJob */

/* 5208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5214 */	NdrFcShort( 0x48 ),	/* 72 */
/* 5216 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5218 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5222 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5224 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5230 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter runtime */

/* 5232 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5236 */	NdrFcShort( 0x156 ),	/* Type Offset=342 */

	/* Return value */

/* 5238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5240 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUsnId */

/* 5244 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5250 */	NdrFcShort( 0x49 ),	/* 73 */
/* 5252 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5256 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5258 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5260 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5266 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter usnId */

/* 5268 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5270 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5272 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5276 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ValidateForTruncate */

/* 5280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5286 */	NdrFcShort( 0x4a ),	/* 74 */
/* 5288 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 5290 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5294 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5296 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 5304 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5306 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5308 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 5310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5312 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5314 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5316 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5318 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5320 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter usn */

/* 5322 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5324 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5326 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5328 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5330 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckIfSparse */

/* 5334 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5336 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5340 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5342 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5344 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5348 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5350 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5356 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 5358 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5360 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5362 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5364 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5366 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5368 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5370 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5372 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIScanItem */

/* 5376 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5378 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5382 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5384 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5388 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5390 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5392 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5398 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 5400 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5402 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5404 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter pResult */

/* 5406 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5408 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5410 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5414 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToPathAndName */

/* 5418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5424 */	NdrFcShort( 0x5 ),	/* 5 */
/* 5426 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5430 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5432 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5434 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 5442 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5444 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5446 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter name */

/* 5448 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5450 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5452 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 5454 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5456 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5458 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5462 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Copy */

/* 5466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5472 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5474 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5476 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5480 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5482 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5488 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dest */

/* 5490 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5492 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5494 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter retainHierarcy */

/* 5496 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5498 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter expandPlaceholders */

/* 5502 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5504 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter overwriteExisting */

/* 5508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5510 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5514 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5516 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateLocalStream */

/* 5520 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5526 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5528 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5532 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5534 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5536 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5542 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppStream */

/* 5544 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5546 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5548 */	NdrFcShort( 0xc4 ),	/* Type Offset=196 */

	/* Return value */

/* 5550 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5552 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreatePlaceholder */

/* 5556 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5564 */	NdrFcShort( 0xc0 ),	/* x86 Stack size/offset = 192 */
/* 5566 */	NdrFcShort( 0x140 ),	/* 320 */
/* 5568 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5570 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 5572 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5578 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 5580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5582 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5584 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5588 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5590 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 5592 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5594 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5596 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Parameter checkUsn */

/* 5598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5600 */	NdrFcShort( 0xac ),	/* x86 Stack size/offset = 172 */
/* 5602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter usn */

/* 5604 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5606 */	NdrFcShort( 0xb0 ),	/* x86 Stack size/offset = 176 */
/* 5608 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pUsn */

/* 5610 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5612 */	NdrFcShort( 0xb8 ),	/* x86 Stack size/offset = 184 */
/* 5614 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5616 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5618 */	NdrFcShort( 0xbc ),	/* x86 Stack size/offset = 188 */
/* 5620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Delete */

/* 5622 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5628 */	NdrFcShort( 0x9 ),	/* 9 */
/* 5630 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5634 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5636 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5638 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5644 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5646 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5648 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeletePlaceholder */

/* 5652 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5654 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5658 */	NdrFcShort( 0xa ),	/* 10 */
/* 5660 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5662 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5664 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5666 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5668 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5674 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 5676 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5678 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5680 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5682 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5684 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5686 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5688 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5690 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirstPlaceholder */

/* 5694 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5700 */	NdrFcShort( 0xb ),	/* 11 */
/* 5702 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5706 */	NdrFcShort( 0x16c ),	/* 364 */
/* 5708 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 5710 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5716 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 5718 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5720 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5722 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSize */

/* 5724 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5726 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5728 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 5730 */	NdrFcShort( 0x112 ),	/* Flags:  must free, out, simple ref, */
/* 5732 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5734 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 5736 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5738 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNextPlaceholder */

/* 5742 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5744 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5748 */	NdrFcShort( 0xc ),	/* 12 */
/* 5750 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5752 */	NdrFcShort( 0x164 ),	/* 356 */
/* 5754 */	NdrFcShort( 0x16c ),	/* 364 */
/* 5756 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 5758 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5764 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 5766 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5768 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5770 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSize */

/* 5772 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5774 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5776 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 5778 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 5780 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5782 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 5784 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5786 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5788 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAccessTime */

/* 5790 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5792 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5796 */	NdrFcShort( 0xd ),	/* 13 */
/* 5798 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5802 */	NdrFcShort( 0x34 ),	/* 52 */
/* 5804 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5806 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5812 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 5814 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 5816 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5818 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 5820 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5822 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileId */

/* 5826 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5828 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5832 */	NdrFcShort( 0xe ),	/* 14 */
/* 5834 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5838 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5840 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5842 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5848 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */

/* 5850 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5852 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5854 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5856 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5858 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFullPathAndName */

/* 5862 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5864 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5868 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5870 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5876 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5878 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5884 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prependix */

/* 5886 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5888 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5890 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter appendix */

/* 5892 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5894 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5896 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pPath */

/* 5898 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 5900 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5902 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 5904 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5906 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5910 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5912 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5914 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogicalSize */

/* 5916 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5918 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5922 */	NdrFcShort( 0x12 ),	/* 18 */
/* 5924 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5928 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5930 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5932 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5938 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 5940 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5942 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5944 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5946 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5948 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetModifyTime */

/* 5952 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5954 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5958 */	NdrFcShort( 0x13 ),	/* 19 */
/* 5960 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5964 */	NdrFcShort( 0x34 ),	/* 52 */
/* 5966 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5968 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5974 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 5976 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 5978 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5980 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 5982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5984 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogicalName */


	/* Procedure GetName */

/* 5988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5994 */	NdrFcShort( 0x14 ),	/* 20 */
/* 5996 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5998 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6002 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6004 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6010 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 6012 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6014 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6016 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 6018 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6020 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 6024 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6026 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetOwner */

/* 6030 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6036 */	NdrFcShort( 0x15 ),	/* 21 */
/* 6038 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6040 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6044 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6046 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6052 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pOwner */

/* 6054 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6056 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6058 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 6060 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6062 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 6066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6068 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPathForFind */

/* 6072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6078 */	NdrFcShort( 0x16 ),	/* 22 */
/* 6080 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6086 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 6088 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6094 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter searchName */

/* 6096 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6098 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6100 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pPath */

/* 6102 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6106 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 6108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 6120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6126 */	NdrFcShort( 0x17 ),	/* 23 */
/* 6128 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6134 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6136 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 6144 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6146 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6148 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 6150 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6152 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6158 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPathAndName */

/* 6162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6168 */	NdrFcShort( 0x18 ),	/* 24 */
/* 6170 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6172 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6176 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 6178 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter appendix */

/* 6186 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6190 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pPath */

/* 6192 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6194 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6196 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 6198 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6206 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPhysicalSize */

/* 6210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6216 */	NdrFcShort( 0x19 ),	/* 25 */
/* 6218 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6222 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6224 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6226 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 6234 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6236 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6238 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6242 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPlaceholder */

/* 6246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6252 */	NdrFcShort( 0x1a ),	/* 26 */
/* 6254 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 6256 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6258 */	NdrFcShort( 0x124 ),	/* 292 */
/* 6260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 6262 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6268 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 6270 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6272 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6274 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 6276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6278 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6280 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 6282 */	NdrFcShort( 0x112 ),	/* Flags:  must free, out, simple ref, */
/* 6284 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6286 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 6288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6290 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 6294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6300 */	NdrFcShort( 0x1b ),	/* 27 */
/* 6302 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6308 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6310 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 6318 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6322 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 6324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6326 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUncPathAndName */

/* 6330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6336 */	NdrFcShort( 0x1c ),	/* 28 */
/* 6338 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6344 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 6346 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prependix */

/* 6354 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6356 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6358 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter appendix */

/* 6360 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6364 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pPath */

/* 6366 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6368 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6370 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 6372 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6374 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6380 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVersionId */

/* 6384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6390 */	NdrFcShort( 0x1d ),	/* 29 */
/* 6392 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6396 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6398 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6400 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6406 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 6408 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6410 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6412 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6414 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6416 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HasExtendedAttributes */

/* 6420 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6426 */	NdrFcShort( 0x1e ),	/* 30 */
/* 6428 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6434 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6436 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6442 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6446 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsALink */

/* 6450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6456 */	NdrFcShort( 0x1f ),	/* 31 */
/* 6458 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6464 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6466 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6476 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsAParent */

/* 6480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6486 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6488 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6494 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsARelativeParent */

/* 6510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6516 */	NdrFcShort( 0x21 ),	/* 33 */
/* 6518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6522 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6524 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6526 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6536 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsCompressed */

/* 6540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6546 */	NdrFcShort( 0x22 ),	/* 34 */
/* 6548 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6554 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6556 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6564 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6566 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsDeleteOK */

/* 6570 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6572 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6576 */	NdrFcShort( 0x23 ),	/* 35 */
/* 6578 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6582 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6584 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6586 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6592 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPostIt */

/* 6594 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6596 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6598 */	NdrFcShort( 0x192 ),	/* Type Offset=402 */

	/* Return value */

/* 6600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6602 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsEncrypted */

/* 6606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6612 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6620 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6622 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6630 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6632 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsGroupMemberOf */

/* 6636 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6638 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6642 */	NdrFcShort( 0x25 ),	/* 37 */
/* 6644 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6650 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6652 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6658 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter group */

/* 6660 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6662 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6664 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 6666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6668 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsHidden */

/* 6672 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6678 */	NdrFcShort( 0x26 ),	/* 38 */
/* 6680 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6684 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6686 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6688 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6694 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6698 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsManageable */

/* 6702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6708 */	NdrFcShort( 0x27 ),	/* 39 */
/* 6710 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6712 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6716 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 6718 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6724 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 6726 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6728 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6730 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 6732 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6736 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6740 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsManaged */

/* 6744 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6750 */	NdrFcShort( 0x28 ),	/* 40 */
/* 6752 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6754 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6758 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 6760 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 6768 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6770 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6772 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 6774 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6776 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6778 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6782 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMbit */

/* 6786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6792 */	NdrFcShort( 0x29 ),	/* 41 */
/* 6794 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6798 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6800 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6802 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6808 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6812 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMigrateOK */

/* 6816 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6822 */	NdrFcShort( 0x2a ),	/* 42 */
/* 6824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6830 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6832 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6838 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPostIt */

/* 6840 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6842 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6844 */	NdrFcShort( 0x192 ),	/* Type Offset=402 */

	/* Return value */

/* 6846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6848 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsOffline */

/* 6852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6858 */	NdrFcShort( 0x2b ),	/* 43 */
/* 6860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6866 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6868 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6878 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsOwnerMemberOf */

/* 6882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6888 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6896 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6898 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6904 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter group */

/* 6906 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6908 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6910 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 6912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6914 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsPremigrated */

/* 6918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6924 */	NdrFcShort( 0x2d ),	/* 45 */
/* 6926 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6928 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6932 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 6934 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 6942 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6946 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 6948 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6950 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6952 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6956 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsReadOnly */

/* 6960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6966 */	NdrFcShort( 0x2e ),	/* 46 */
/* 6968 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6974 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6976 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsRecallOK */

/* 6990 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6996 */	NdrFcShort( 0x2f ),	/* 47 */
/* 6998 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7004 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7006 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPostIt */

/* 7014 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7016 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7018 */	NdrFcShort( 0x192 ),	/* Type Offset=402 */

	/* Return value */

/* 7020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7022 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsSparse */

/* 7026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7032 */	NdrFcShort( 0x30 ),	/* 48 */
/* 7034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7040 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7042 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7050 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7052 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsSystem */

/* 7056 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7058 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7062 */	NdrFcShort( 0x31 ),	/* 49 */
/* 7064 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7068 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7070 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7072 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7078 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7082 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsTotallySparse */

/* 7086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7092 */	NdrFcShort( 0x32 ),	/* 50 */
/* 7094 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7100 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7102 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7108 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7112 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsTruncated */

/* 7116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7122 */	NdrFcShort( 0x33 ),	/* 51 */
/* 7124 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7126 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7130 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7132 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7142 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7144 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7148 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7150 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7154 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Manage */

/* 7158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7164 */	NdrFcShort( 0x34 ),	/* 52 */
/* 7166 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 7168 */	NdrFcShort( 0x58 ),	/* 88 */
/* 7170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7172 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 7174 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7182 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7184 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7186 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7188 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7190 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7192 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter storagePoolId */

/* 7194 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 7196 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7198 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter truncate */

/* 7200 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7202 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 7204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7206 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7208 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 7210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Move */

/* 7212 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7214 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7218 */	NdrFcShort( 0x35 ),	/* 53 */
/* 7220 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7222 */	NdrFcShort( 0x18 ),	/* 24 */
/* 7224 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7226 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 7228 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7234 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dest */

/* 7236 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7238 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7240 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter retainHierarcy */

/* 7242 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7244 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter expandPlaceholders */

/* 7248 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7250 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter overwriteExisting */

/* 7254 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7256 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7262 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Recall */

/* 7266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7272 */	NdrFcShort( 0x36 ),	/* 54 */
/* 7274 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 7276 */	NdrFcShort( 0x28 ),	/* 40 */
/* 7278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7280 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 7282 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7290 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7292 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7294 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7296 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7298 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7300 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter deletePlaceholder */

/* 7302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7304 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7310 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Recycle */

/* 7314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7320 */	NdrFcShort( 0x37 ),	/* 55 */
/* 7322 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7328 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7330 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7336 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7340 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Truncate */

/* 7344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7350 */	NdrFcShort( 0x38 ),	/* 56 */
/* 7352 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7354 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7358 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7360 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7368 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7372 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7374 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7376 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7378 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7382 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Unmanage */

/* 7386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7392 */	NdrFcShort( 0x39 ),	/* 57 */
/* 7394 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7396 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7400 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7402 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7414 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7416 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7418 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7420 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7424 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Validate */

/* 7428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7434 */	NdrFcShort( 0x3a ),	/* 58 */
/* 7436 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7438 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7442 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7444 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7450 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7452 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7454 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7456 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7458 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7460 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7462 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7466 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PrepareForManage */

/* 7470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7476 */	NdrFcShort( 0x3b ),	/* 59 */
/* 7478 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7480 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7484 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7486 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7494 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7496 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7498 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7500 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7502 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7504 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7508 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Verify */

/* 7512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7518 */	NdrFcShort( 0x3c ),	/* 60 */
/* 7520 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7522 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7526 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7528 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7534 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7536 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7538 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7540 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7542 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7544 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7546 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7550 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TruncateValidated */

/* 7554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7560 */	NdrFcShort( 0x3d ),	/* 61 */
/* 7562 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7564 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7568 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7570 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7578 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7580 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7582 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7584 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7586 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7588 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7592 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumResources */

/* 7596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7602 */	NdrFcShort( 0x4 ),	/* 4 */
/* 7604 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7610 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7612 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 7620 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7622 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7624 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 7626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7628 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceByAlternatePath */

/* 7632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7638 */	NdrFcShort( 0x5 ),	/* 5 */
/* 7640 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7646 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 7648 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 7656 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7658 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7660 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter ppResource */

/* 7662 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7664 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7666 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 7668 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7670 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceById */

/* 7674 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7680 */	NdrFcShort( 0x6 ),	/* 6 */
/* 7682 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 7684 */	NdrFcShort( 0x30 ),	/* 48 */
/* 7686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7688 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 7690 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7696 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 7698 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 7700 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7702 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter ppResource */

/* 7704 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7706 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7708 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 7710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7712 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceByName */

/* 7716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7722 */	NdrFcShort( 0x7 ),	/* 7 */
/* 7724 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7730 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 7732 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7738 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7740 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7742 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7744 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter ppResource */

/* 7746 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7748 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7750 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 7752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7754 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceByPath */

/* 7758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7766 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7772 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 7774 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7780 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 7782 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7784 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7786 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter ppResource */

/* 7788 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7790 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7792 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 7794 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7796 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceBySerial */

/* 7800 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7802 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7806 */	NdrFcShort( 0x9 ),	/* 9 */
/* 7808 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7812 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7814 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 7816 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7822 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serial */

/* 7824 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7826 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppResource */

/* 7830 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7832 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7834 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 7836 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7838 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceByStickyName */

/* 7842 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7844 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7848 */	NdrFcShort( 0xa ),	/* 10 */
/* 7850 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7856 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 7858 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7864 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7866 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7868 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7870 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter ppResource */

/* 7872 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7874 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7876 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 7878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7880 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDbPathAndName */

/* 7884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7890 */	NdrFcShort( 0xd ),	/* 13 */
/* 7892 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7898 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 7900 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7906 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 7908 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 7910 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7912 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 7914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7922 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIDbSys */

/* 7926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7932 */	NdrFcShort( 0xe ),	/* 14 */
/* 7934 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7940 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7942 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppDbSys */

/* 7950 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7952 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7954 */	NdrFcShort( 0x1ba ),	/* Type Offset=442 */

	/* Return value */

/* 7956 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7958 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUnmanageIDbSys */

/* 7962 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7964 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7968 */	NdrFcShort( 0xf ),	/* 15 */
/* 7970 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7976 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7978 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7984 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppDbSys */

/* 7986 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7988 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7990 */	NdrFcShort( 0x1ba ),	/* Type Offset=442 */

	/* Return value */

/* 7992 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7994 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFilter */

/* 7998 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8000 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8004 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8006 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8010 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8012 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8014 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFilter */

/* 8022 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8024 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8026 */	NdrFcShort( 0x1d0 ),	/* Type Offset=464 */

	/* Return value */

/* 8028 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8030 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUnmanageIDbPath */

/* 8034 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8036 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8040 */	NdrFcShort( 0x12 ),	/* 18 */
/* 8042 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8046 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8048 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8050 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 8058 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 8060 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8062 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 8064 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8066 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8072 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 8076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8082 */	NdrFcShort( 0x13 ),	/* 19 */
/* 8084 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8088 */	NdrFcShort( 0x4c ),	/* 76 */
/* 8090 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8092 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 8100 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 8102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8104 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 8106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 8112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8118 */	NdrFcShort( 0x16 ),	/* 22 */
/* 8120 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8126 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 8128 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8134 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 8136 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8138 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAutosave */

/* 8142 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8148 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8150 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8154 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8156 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8158 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8164 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter milliseconds */

/* 8166 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8168 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8172 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8174 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 8178 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8180 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8184 */	NdrFcShort( 0x4 ),	/* 4 */
/* 8186 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8192 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8194 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8200 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 8202 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8204 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8206 */	NdrFcShort( 0x1e6 ),	/* Type Offset=486 */

	/* Return value */

/* 8208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8210 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetKeepRecallTime */

/* 8214 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8220 */	NdrFcShort( 0x5 ),	/* 5 */
/* 8222 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8226 */	NdrFcShort( 0x34 ),	/* 52 */
/* 8228 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8230 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8236 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 8238 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 8240 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8242 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 8244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8246 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxFilesPerRun */

/* 8250 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8256 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8258 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8262 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8264 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8266 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8272 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMaxFiles */

/* 8274 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8276 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8278 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8282 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPremigratedSortOrder */

/* 8286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8292 */	NdrFcShort( 0x7 ),	/* 7 */
/* 8294 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8298 */	NdrFcShort( 0x22 ),	/* 34 */
/* 8300 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8302 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSortOrder */

/* 8310 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 8312 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8314 */	NdrFcShort( 0x1fc ),	/* Type Offset=508 */

	/* Return value */

/* 8316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8318 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRunInterval */

/* 8322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8330 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8334 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8336 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8338 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8344 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMilliseconds */

/* 8346 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8348 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8352 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8354 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxFilesPerRun */

/* 8358 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8360 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8364 */	NdrFcShort( 0x9 ),	/* 9 */
/* 8366 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8368 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8370 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8372 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8374 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8380 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter maxFiles */

/* 8382 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8384 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8386 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8388 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8390 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPremigratedSortOrder */

/* 8394 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8396 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8400 */	NdrFcShort( 0xa ),	/* 10 */
/* 8402 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8404 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8406 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8408 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8410 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter SortOrder */

/* 8418 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8420 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8422 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 8424 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8426 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRunInterval */

/* 8430 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8436 */	NdrFcShort( 0xb ),	/* 11 */
/* 8438 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8442 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8444 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8446 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8452 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter milliseconds */

/* 8454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8456 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8462 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetKeepRecallTime */

/* 8466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8472 */	NdrFcShort( 0xc ),	/* 12 */
/* 8474 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8476 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8480 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8482 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8488 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter time */

/* 8490 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 8492 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8494 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 8496 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8498 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Start */

/* 8502 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8504 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8508 */	NdrFcShort( 0xd ),	/* 13 */
/* 8510 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8514 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8516 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 8518 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8524 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 8526 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 8528 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8530 */	NdrFcShort( 0x1a8 ),	/* Type Offset=424 */

	/* Return value */

/* 8532 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8534 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileVersionId */

/* 8538 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8540 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8544 */	NdrFcShort( 0x3 ),	/* 3 */
/* 8546 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8550 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8552 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8554 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8560 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileVersionId */

/* 8562 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8564 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8566 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8568 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8570 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFilterRecall */

/* 8574 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8576 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8580 */	NdrFcShort( 0x4 ),	/* 4 */
/* 8582 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8588 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8590 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8596 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppRecall */

/* 8598 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8600 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8602 */	NdrFcShort( 0x200 ),	/* Type Offset=512 */

	/* Return value */

/* 8604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8606 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMode */

/* 8610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8616 */	NdrFcShort( 0x5 ),	/* 5 */
/* 8618 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8622 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8624 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8626 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8632 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMode */

/* 8634 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8636 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8642 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 8646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8652 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8654 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8660 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8662 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 8670 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 8672 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8674 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 8676 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8678 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8684 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPlaceholder */

/* 8688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8694 */	NdrFcShort( 0x7 ),	/* 7 */
/* 8696 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8700 */	NdrFcShort( 0x124 ),	/* 292 */
/* 8702 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8704 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPlaceholder */

/* 8712 */	NdrFcShort( 0x112 ),	/* Flags:  must free, out, simple ref, */
/* 8714 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8716 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 8718 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8720 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRequestAction */

/* 8724 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8726 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8732 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8736 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8738 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8740 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8746 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRequestAction */

/* 8748 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8750 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8752 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 8754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8756 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRequestOffset */

/* 8760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8766 */	NdrFcShort( 0x9 ),	/* 9 */
/* 8768 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8772 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8774 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8776 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8782 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRequestOffset */

/* 8784 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8786 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8788 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8790 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8792 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResultAction */

/* 8796 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8798 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8802 */	NdrFcShort( 0xc ),	/* 12 */
/* 8804 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8808 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8810 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8812 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8818 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResultAction */

/* 8820 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8822 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8824 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 8826 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8828 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 8832 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8834 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8838 */	NdrFcShort( 0xd ),	/* 13 */
/* 8840 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8846 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8848 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8854 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 8856 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8858 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8860 */	NdrFcShort( 0x1e6 ),	/* Type Offset=486 */

	/* Return value */

/* 8862 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8864 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStoragePoolId */

/* 8868 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8870 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8874 */	NdrFcShort( 0xe ),	/* 14 */
/* 8876 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8880 */	NdrFcShort( 0x4c ),	/* 76 */
/* 8882 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8884 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8890 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStoragePoolId */

/* 8892 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 8894 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8896 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 8898 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8900 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetThreadId */

/* 8904 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8906 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8910 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8912 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8916 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8918 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8920 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pThreadId */

/* 8928 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8930 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8932 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8934 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8936 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileVersionId */

/* 8940 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8946 */	NdrFcShort( 0x11 ),	/* 17 */
/* 8948 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8950 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8954 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8956 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8962 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileVersionId */

/* 8964 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8966 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8968 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8970 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8972 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFilterRecall */

/* 8976 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8978 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8982 */	NdrFcShort( 0x12 ),	/* 18 */
/* 8984 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8988 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8990 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 8992 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8998 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 9000 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9002 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9004 */	NdrFcShort( 0x204 ),	/* Type Offset=516 */

	/* Return value */

/* 9006 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9008 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPlaceholder */

/* 9012 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9018 */	NdrFcShort( 0x15 ),	/* 21 */
/* 9020 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9022 */	NdrFcShort( 0x11c ),	/* 284 */
/* 9024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9026 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9028 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9034 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPlaceholder */

/* 9036 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9038 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9040 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 9042 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9044 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRequestAction */

/* 9048 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9050 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9054 */	NdrFcShort( 0x16 ),	/* 22 */
/* 9056 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9058 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9060 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9062 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9064 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9070 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter requestAction */

/* 9072 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9074 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9076 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 9078 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9080 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRequestOffset */

/* 9084 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9086 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9090 */	NdrFcShort( 0x17 ),	/* 23 */
/* 9092 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9094 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9096 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9098 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9100 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter requestOffset */

/* 9108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9112 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9116 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRequestSize */

/* 9120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9126 */	NdrFcShort( 0x18 ),	/* 24 */
/* 9128 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9130 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9134 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9136 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter requestSize */

/* 9144 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9146 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9148 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResult */

/* 9156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9162 */	NdrFcShort( 0x19 ),	/* 25 */
/* 9164 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9170 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9172 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hr */

/* 9180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResultAction */

/* 9192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9198 */	NdrFcShort( 0x1a ),	/* 26 */
/* 9200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9206 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9208 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResultAction */

/* 9216 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9220 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 9222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSession */

/* 9228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9234 */	NdrFcShort( 0x1b ),	/* 27 */
/* 9236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9242 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9244 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 9252 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9256 */	NdrFcShort( 0x1ea ),	/* Type Offset=490 */

	/* Return value */

/* 9258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStoragePoolId */

/* 9264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9270 */	NdrFcShort( 0x1c ),	/* 28 */
/* 9272 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 9274 */	NdrFcShort( 0x30 ),	/* 48 */
/* 9276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9278 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9280 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter storagePoolId */

/* 9288 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 9290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9292 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 9294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9296 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUSN */

/* 9300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9306 */	NdrFcShort( 0x1d ),	/* 29 */
/* 9308 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9310 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9316 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter usn */

/* 9324 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9328 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetThreadId */

/* 9336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9342 */	NdrFcShort( 0x1e ),	/* 30 */
/* 9344 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9350 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9352 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter threadId */

/* 9360 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IdentifyWithServer */

/* 9372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9378 */	NdrFcShort( 0x3 ),	/* 3 */
/* 9380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9386 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9388 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szServerName */

/* 9396 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 9398 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9400 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 9402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9404 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnRecallStarted */

/* 9408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9414 */	NdrFcShort( 0x4 ),	/* 4 */
/* 9416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9420 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9422 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9424 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 9432 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9434 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9436 */	NdrFcShort( 0x216 ),	/* Type Offset=534 */

	/* Return value */

/* 9438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9440 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnRecallFinished */

/* 9444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9450 */	NdrFcShort( 0x5 ),	/* 5 */
/* 9452 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9458 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 9460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 9468 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9472 */	NdrFcShort( 0x216 ),	/* Type Offset=534 */

	/* Parameter hr */

/* 9474 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9482 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 9486 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9492 */	NdrFcShort( 0x3 ),	/* 3 */
/* 9494 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9498 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9500 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9502 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9508 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 9510 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9514 */	NdrFcShort( 0x204 ),	/* Type Offset=516 */

	/* Return value */

/* 9516 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cancel */

/* 9522 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9528 */	NdrFcShort( 0x4 ),	/* 4 */
/* 9530 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9536 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 9538 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 9546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9548 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 9552 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9558 */	NdrFcShort( 0x5 ),	/* 5 */
/* 9560 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9564 */	NdrFcShort( 0x4c ),	/* 76 */
/* 9566 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9568 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 9576 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 9578 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9580 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 9582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9584 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMode */

/* 9588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9594 */	NdrFcShort( 0x6 ),	/* 6 */
/* 9596 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9600 */	NdrFcShort( 0x24 ),	/* 36 */
/* 9602 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9604 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMode */

/* 9612 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9614 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9620 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOffset */

/* 9624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9630 */	NdrFcShort( 0x7 ),	/* 7 */
/* 9632 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9636 */	NdrFcShort( 0x2c ),	/* 44 */
/* 9638 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9640 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 9648 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9650 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9652 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9656 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 9660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9666 */	NdrFcShort( 0xb ),	/* 11 */
/* 9668 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9672 */	NdrFcShort( 0x24 ),	/* 36 */
/* 9674 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9676 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 9684 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9686 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9688 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 9690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9692 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendNotification */

/* 9696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9702 */	NdrFcShort( 0x3 ),	/* 3 */
/* 9704 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9706 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9710 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 9712 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9718 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter machineName */

/* 9720 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9722 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9724 */	NdrFcShort( 0x228 ),	/* Type Offset=552 */

	/* Parameter started */

/* 9726 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9728 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rHr */

/* 9732 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9740 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9742 */	0x8,		/* FC_LONG */
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
/*  4 */	NdrFcLong( 0x5e176f27 ),	/* 1578594087 */
/*  8 */	NdrFcShort( 0x6f53 ),	/* 28499 */
/* 10 */	NdrFcShort( 0x4c84 ),	/* 19588 */
/* 12 */	0xb9,		/* 185 */
			0x35,		/* 53 */
/* 14 */	0x92,		/* 146 */
			0x59,		/* 89 */
/* 16 */	0x29,		/* 41 */
			0x76,		/* 118 */
/* 18 */	0x69,		/* 105 */
			0xb0,		/* 176 */
/* 20 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 22 */	NdrFcShort( 0x8 ),	/* 8 */
/* 24 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 26 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 28 */	NdrFcShort( 0x10 ),	/* 16 */
/* 30 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 32 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 34 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (20) */
			0x5b,		/* FC_END */
/* 38 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 40 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 42 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 44 */	NdrFcLong( 0x5fff1640 ),	/* 1610552896 */
/* 48 */	NdrFcShort( 0xd487 ),	/* -11129 */
/* 50 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 52 */	0xa9,		/* 169 */
			0xf5,		/* 245 */
/* 54 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 56 */	0x24,		/* 36 */
			0x89,		/* 137 */
/* 58 */	0x3,		/* 3 */
			0xea,		/* 234 */
/* 60 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 62 */	NdrFcShort( 0x2 ),	/* Offset= 2 (64) */
/* 64 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 66 */	NdrFcLong( 0x9c7d6f14 ),	/* -1669501164 */
/* 70 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 72 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 74 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 76 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 78 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 80 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 82 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 84 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (26) */
/* 86 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 88 */	NdrFcShort( 0x2 ),	/* Offset= 2 (90) */
/* 90 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 92 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 94 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 96 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 98 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 100 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 102 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 104 */	NdrFcShort( 0xff9a ),	/* Offset= -102 (2) */
/* 106 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 108 */	NdrFcLong( 0x560e5a02 ),	/* 1443781122 */
/* 112 */	NdrFcShort( 0xdede ),	/* -8482 */
/* 114 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 116 */	0xa9,		/* 169 */
			0xf5,		/* 245 */
/* 118 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 120 */	0x24,		/* 36 */
			0x89,		/* 137 */
/* 122 */	0x3,		/* 3 */
			0xea,		/* 234 */
/* 124 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 126 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 128 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 130 */	NdrFcShort( 0x2 ),	/* Offset= 2 (132) */
/* 132 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 136 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 138 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 140 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 142 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 144 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 146 */	0x3,		/* FC_SMALL */
			0x5c,		/* FC_PAD */
/* 148 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 150 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 152 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 154 */	NdrFcShort( 0x2 ),	/* Offset= 2 (156) */
/* 156 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 158 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 162 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 164 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 166 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 168 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 170 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 172 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 174 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 176 */	NdrFcShort( 0x2 ),	/* Offset= 2 (178) */
/* 178 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 180 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 184 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 186 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 188 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 190 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 192 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 194 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 196 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 198 */	NdrFcShort( 0x2 ),	/* Offset= 2 (200) */
/* 200 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 202 */	NdrFcLong( 0xc ),	/* 12 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 210 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 212 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 214 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 216 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 218 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 220 */	NdrFcLong( 0x87e7ed0 ),	/* 142507728 */
/* 224 */	NdrFcShort( 0x727a ),	/* 29306 */
/* 226 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 228 */	0x9c,		/* 156 */
			0xd3,		/* 211 */
/* 230 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 232 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 234 */	0x81,		/* 129 */
			0x2,		/* 2 */
/* 236 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 238 */	NdrFcShort( 0xffec ),	/* Offset= -20 (218) */
/* 240 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 242 */	NdrFcShort( 0x2 ),	/* Offset= 2 (244) */
/* 244 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 246 */	NdrFcLong( 0x9c7d6f0f ),	/* -1669501169 */
/* 250 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 252 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 254 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 256 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 258 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 260 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 262 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 264 */	NdrFcShort( 0x2 ),	/* Offset= 2 (266) */
/* 266 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 268 */	NdrFcLong( 0x14f73fcb ),	/* 351748043 */
/* 272 */	NdrFcShort( 0x517d ),	/* 20861 */
/* 274 */	NdrFcShort( 0x4503 ),	/* 17667 */
/* 276 */	0xb1,		/* 177 */
			0x5d,		/* 93 */
/* 278 */	0x2d,		/* 45 */
			0x40,		/* 64 */
/* 280 */	0xb3,		/* 179 */
			0xe9,		/* 233 */
/* 282 */	0xcd,		/* 205 */
			0x21,		/* 33 */
/* 284 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 286 */	NdrFcShort( 0x2 ),	/* Offset= 2 (288) */
/* 288 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 290 */	NdrFcLong( 0x9cabc042 ),	/* -1666465726 */
/* 294 */	NdrFcShort( 0x8aa4 ),	/* -30044 */
/* 296 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 298 */	0x81,		/* 129 */
			0xe6,		/* 230 */
/* 300 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 302 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 304 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 306 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 308 */	NdrFcLong( 0xb5a1ed6a ),	/* -1247679126 */
/* 312 */	NdrFcShort( 0xced4 ),	/* -12588 */
/* 314 */	NdrFcShort( 0x4d16 ),	/* 19734 */
/* 316 */	0x9a,		/* 154 */
			0x76,		/* 118 */
/* 318 */	0x8c,		/* 140 */
			0xd4,		/* 212 */
/* 320 */	0x47,		/* 71 */
			0x3a,		/* 58 */
/* 322 */	0x2c,		/* 44 */
			0xe9,		/* 233 */
/* 324 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 326 */	NdrFcLong( 0x2a87c7e2 ),	/* 713541602 */
/* 330 */	NdrFcShort( 0xdb24 ),	/* -9436 */
/* 332 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 334 */	0xaf,		/* 175 */
			0xa2,		/* 162 */
/* 336 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 338 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 340 */	0x37,		/* 55 */
			0x58,		/* 88 */
/* 342 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 344 */	NdrFcShort( 0x10 ),	/* 16 */
/* 346 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 348 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 350 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 352 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 354 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 356 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 358 */	NdrFcShort( 0x98 ),	/* 152 */
/* 360 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 362 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 364 */	0x0,		/* 0 */
			NdrFcShort( 0xff17 ),	/* Offset= -233 (132) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 368 */	0x0,		/* 0 */
			NdrFcShort( 0xfea9 ),	/* Offset= -343 (26) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 372 */	0x0,		/* 0 */
			NdrFcShort( 0xfea5 ),	/* Offset= -347 (26) */
			0x40,		/* FC_STRUCTPAD4 */
/* 376 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 378 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 380 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 382 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 384 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 386 */	NdrFcShort( 0xff02 ),	/* Offset= -254 (132) */
/* 388 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 390 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 392 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 394 */	
			0x11, 0x0,	/* FC_RP */
/* 396 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (356) */
/* 398 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 400 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 402 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 404 */	NdrFcLong( 0xb5a1ed6a ),	/* -1247679126 */
/* 408 */	NdrFcShort( 0xced4 ),	/* -12588 */
/* 410 */	NdrFcShort( 0x4d16 ),	/* 19734 */
/* 412 */	0x9a,		/* 154 */
			0x76,		/* 118 */
/* 414 */	0x8c,		/* 140 */
			0xd4,		/* 212 */
/* 416 */	0x47,		/* 71 */
			0x3a,		/* 58 */
/* 418 */	0x2c,		/* 44 */
			0xe9,		/* 233 */
/* 420 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 422 */	NdrFcShort( 0x2 ),	/* Offset= 2 (424) */
/* 424 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 426 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 430 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 432 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 434 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 436 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 438 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 440 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 442 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 444 */	NdrFcShort( 0x2 ),	/* Offset= 2 (446) */
/* 446 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 448 */	NdrFcLong( 0xf2608980 ),	/* -228554368 */
/* 452 */	NdrFcShort( 0xa45 ),	/* 2629 */
/* 454 */	NdrFcShort( 0x47b4 ),	/* 18356 */
/* 456 */	0xb1,		/* 177 */
			0x10,		/* 16 */
/* 458 */	0x37,		/* 55 */
			0xea,		/* 234 */
/* 460 */	0x59,		/* 89 */
			0xf6,		/* 246 */
/* 462 */	0x7c,		/* 124 */
			0x47,		/* 71 */
/* 464 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 466 */	NdrFcShort( 0x2 ),	/* Offset= 2 (468) */
/* 468 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 470 */	NdrFcLong( 0x5fff1640 ),	/* 1610552896 */
/* 474 */	NdrFcShort( 0xd487 ),	/* -11129 */
/* 476 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 478 */	0xa9,		/* 169 */
			0xf5,		/* 245 */
/* 480 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 482 */	0x24,		/* 36 */
			0x89,		/* 137 */
/* 484 */	0x3,		/* 3 */
			0xea,		/* 234 */
/* 486 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 488 */	NdrFcShort( 0x2 ),	/* Offset= 2 (490) */
/* 490 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 492 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 496 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 498 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 500 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 502 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 504 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 506 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 508 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 510 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 512 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 514 */	NdrFcShort( 0x2 ),	/* Offset= 2 (516) */
/* 516 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 518 */	NdrFcLong( 0x5e176f27 ),	/* 1578594087 */
/* 522 */	NdrFcShort( 0x6f53 ),	/* 28499 */
/* 524 */	NdrFcShort( 0x4c84 ),	/* 19588 */
/* 526 */	0xb9,		/* 185 */
			0x35,		/* 53 */
/* 528 */	0x92,		/* 146 */
			0x59,		/* 89 */
/* 530 */	0x29,		/* 41 */
			0x76,		/* 118 */
/* 532 */	0x69,		/* 105 */
			0xb0,		/* 176 */
/* 534 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 536 */	NdrFcLong( 0xd68bd5b2 ),	/* -695478862 */
/* 540 */	NdrFcShort( 0xd6aa ),	/* -10582 */
/* 542 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 544 */	0x9e,		/* 158 */
			0xda,		/* 218 */
/* 546 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 548 */	0x24,		/* 36 */
			0x88,		/* 136 */
/* 550 */	0xfc,		/* 252 */
			0xde,		/* 222 */
/* 552 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 554 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_fsaint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IFsaFilter, ver. 0.0,
   GUID={0x5FFF1640,0xD487,0x11d1,{0xA9,0xF5,0x00,0xA0,0x24,0x89,0x03,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaFilter_FormatStringOffsetTable[] =
    {
    0,
    30,
    66,
    108,
    150,
    186,
    222,
    258,
    300,
    336,
    372,
    408,
    444,
    474,
    504,
    534,
    570,
    606,
    642,
    678,
    714,
    744,
    774,
    816
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaFilter_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaFilter_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaFilter_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaFilter_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IFsaFilterProxyVtbl = 
{
    &IFsaFilter_ProxyInfo,
    &IID_IFsaFilter,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaFilter::Cancel */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::CancelRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::CompareToIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::CompareToIFilter */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::DeleteRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::EnumRecalls */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetLogicalName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetMaxRecallBuffers */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetMaxRecalls */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetMinRecallInterval */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetState */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::IsEnabled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::Pause */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::Resume */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetAdminExemption */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::SetIsEnabled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::SetMaxRecalls */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::SetMinRecallInterval */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::SetMaxRecallBuffers */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::Start */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::StopIoctlThread */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::FindRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::SetAdminExemption */
};

const CInterfaceStubVtbl _IFsaFilterStubVtbl =
{
    &IID_IFsaFilter,
    &IFsaFilter_ServerInfo,
    27,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaFilterClient, ver. 0.0,
   GUID={0x560E5A02,0xDEDE,0x11d1,{0xA9,0xF5,0x00,0xA0,0x24,0x89,0x03,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaFilterClient_FormatStringOffsetTable[] =
    {
    852,
    888,
    936,
    978,
    1020,
    1062,
    1104,
    258,
    300,
    1140,
    1182,
    1212,
    1242,
    1284,
    1320,
    1356,
    1392,
    1428,
    642,
    1464,
    714,
    1500,
    1536,
    1584,
    1614,
    1650,
    1686
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaFilterClient_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterClient_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaFilterClient_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterClient_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(30) _IFsaFilterClientProxyVtbl = 
{
    &IFsaFilterClient_ProxyInfo,
    &IID_IFsaFilterClient,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::CompareBy */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::CompareToAuthenticationId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::CompareToIClient */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::CompareToMachineName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetAuthenticationId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetDomainName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetLastRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetMachineName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetRecallCount */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::HasRecallDisabled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::HitRecallLimit */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetAuthenticationId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetDomainName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetHasRecallDisabled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetHitRecallLimit */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetLastRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetMachineName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetRecallCount */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::StartIdentify */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetTokenSource */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SendRecallInfo */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::IdentifyThread */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetIsAdmin */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetIsAdmin */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::CheckRecallLimit */
};

const CInterfaceStubVtbl _IFsaFilterClientStubVtbl =
{
    &IID_IFsaFilterClient,
    &IFsaFilterClient_ServerInfo,
    30,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaFilterRecall, ver. 0.0,
   GUID={0x5E176F27,0x6F53,0x4C84,{0xB9,0x35,0x92,0x59,0x29,0x76,0x69,0xB0}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaFilterRecall_FormatStringOffsetTable[] =
    {
    1734,
    1776,
    1818,
    1860,
    1902,
    1938,
    1974,
    2010,
    2046,
    2088,
    372,
    2124,
    2160,
    2196,
    2232,
    1356,
    2274,
    2304,
    2340,
    2388
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaFilterRecall_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterRecall_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaFilterRecall_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterRecall_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(23) _IFsaFilterRecallProxyVtbl = 
{
    &IFsaFilterRecall_ProxyInfo,
    &IID_IFsaFilterRecall,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CompareToIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CompareToIRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CompareToDriversRecallId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CompareToDriversContextId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CompareBy */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetMode */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetResource */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetRecallFlags */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetState */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::HasCompleted */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::WasCancelled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CreateLocalStream */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CheckRecallLimit */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::AddClient */
};

const CInterfaceStubVtbl _IFsaFilterRecallStubVtbl =
{
    &IID_IFsaFilterRecall,
    &IFsaFilterRecall_ServerInfo,
    23,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaResource, ver. 0.0,
   GUID={0x172F71CD,0xA452,0x4005,{0x8E,0x3E,0x7B,0xCE,0xAE,0x12,0x4D,0x53}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaResource_FormatStringOffsetTable[] =
    {
    2424,
    2484,
    2532,
    2592,
    2622,
    2658,
    2694,
    2736,
    2778,
    2820,
    2862,
    2904,
    2946,
    2988,
    504,
    3030,
    3066,
    3102,
    3138,
    3186,
    3228,
    3270,
    3306,
    3342,
    3378,
    3426,
    3480,
    3522,
    3558,
    3600,
    3642,
    3678,
    3720,
    3756,
    3792,
    3828,
    3870,
    3906,
    3948,
    3984,
    4026,
    4068,
    4110,
    4146,
    4200,
    4236,
    4278,
    4320,
    4362,
    4392,
    4422,
    4452,
    4482,
    4542,
    4590,
    4620,
    4656,
    4710,
    4758,
    4806,
    4842,
    4878,
    4914,
    4950,
    4986,
    5028,
    5064,
    5106,
    5154,
    5208,
    5244,
    5280
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaResource_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaResource_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaResource_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaResource_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(75) _IFsaResourceProxyVtbl = 
{
    &IFsaResource_ProxyInfo,
    &IID_IFsaResource,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaResource::AddPremigrated */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::AddTruncated */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::BeginSession */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::BeginValidate */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CheckForValidate */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareBy */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToAlternatePath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToIResource */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToSerial */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToStickyName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CreateDefaultRules */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::EndSession */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::EndValidate */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::EnumDefaultRules */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindFirst */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindFirstInRPIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindFirstInDbIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindNext */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindNextInRPIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindNextInDbIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindObjectId */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetAlternatePath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetDefaultRules */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetDbPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetUnmanageDbPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetFreeLevel */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetFsName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetHsmEngine */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetHsmLevel */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetLogicalName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetManageableItemLogicalSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetManageableItemAccessTime */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetManagingHsm */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetOldPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetSerial */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetSizes */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetTruncator */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetUncPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetUserFriendlyName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetStickyName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::IsActive */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::IsAvailable */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::IsDeletePending */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::IsManaged */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::Manage */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::ManagedBy */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::NeedsRepair */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::ProcessResult */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::Recall */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::RemovePremigrated */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::RemoveTruncated */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetHsmLevel */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetIsActive */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetIsAvailable */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetIsDeletePending */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetManageableItemLogicalSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetManageableItemAccessTime */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetSerial */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::StartJob */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::StartJobSession */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::Validate */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetupValidateJob */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetUsnId */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::ValidateForTruncate */
};

const CInterfaceStubVtbl _IFsaResourceStubVtbl =
{
    &IID_IFsaResource,
    &IFsaResource_ServerInfo,
    75,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaScanItem, ver. 0.0,
   GUID={0x087e7ed0,0x727a,0x11d2,{0x9c,0xd3,0x00,0xa0,0xc9,0x11,0x81,0x02}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaScanItem_FormatStringOffsetTable[] =
    {
    5334,
    5376,
    5418,
    5466,
    5520,
    5556,
    5622,
    5652,
    5694,
    5742,
    5790,
    5826,
    2160,
    5862,
    2232,
    5916,
    5952,
    5988,
    6030,
    6072,
    6120,
    6162,
    6210,
    6246,
    6294,
    6330,
    6384,
    6420,
    6450,
    6480,
    6510,
    6540,
    6570,
    6606,
    6636,
    6672,
    6702,
    6744,
    6786,
    6816,
    6852,
    6882,
    6918,
    6960,
    6990,
    7026,
    7056,
    7086,
    7116,
    7158,
    7212,
    7266,
    7314,
    7344,
    7386,
    7428,
    7470,
    7512,
    7554
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaScanItem_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaScanItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaScanItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaScanItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(62) _IFsaScanItemProxyVtbl = 
{
    &IFsaScanItem_ProxyInfo,
    &IID_IFsaScanItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::CheckIfSparse */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::CompareToIScanItem */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::CompareToPathAndName */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Copy */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::CreateLocalStream */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::CreatePlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Delete */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::DeletePlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::FindFirstPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::FindNextPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetAccessTime */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetFileUsn */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetFullPathAndName */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetGroup */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetLogicalSize */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetModifyTime */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetName */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetOwner */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetPathForFind */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetPathAndName */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetPhysicalSize */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetUncPathAndName */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetVersionId */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::HasExtendedAttributes */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsALink */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsAParent */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsARelativeParent */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsCompressed */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsDeleteOK */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsEncrypted */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsGroupMemberOf */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsHidden */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsManageable */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsManaged */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsMbit */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsMigrateOK */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsOffline */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsOwnerMemberOf */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsPremigrated */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsReadOnly */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsRecallOK */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsSparse */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsSystem */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsTotallySparse */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsTruncated */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Manage */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Move */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Recall */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Recycle */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Truncate */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Unmanage */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Validate */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::PrepareForManage */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Verify */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::TruncateValidated */
};

const CInterfaceStubVtbl _IFsaScanItemStubVtbl =
{
    &IID_IFsaScanItem,
    &IFsaScanItem_ServerInfo,
    62,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSystemState, ver. 0.0,
   GUID={0x3F0DA041,0x69F1,0x11d2,{0xAF,0x82,0x00,0x10,0x4B,0x9A,0x37,0x58}} */


/* Object interface: IFsaServer, ver. 0.0,
   GUID={0xC49D553D,0xCA2B,0x4482,{0xA4,0x04,0xCD,0x4B,0x6B,0x44,0xEA,0xE4}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaServer_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    7596,
    7632,
    7674,
    7716,
    7758,
    7800,
    7842,
    300,
    1140,
    7884,
    7926,
    7962,
    7998,
    2232,
    8034,
    8076,
    5988,
    6030,
    8112,
    714,
    8142
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(25) _IFsaServerProxyVtbl = 
{
    &IFsaServer_ProxyInfo,
    &IID_IFsaServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::EnumResources */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceByAlternatePath */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceById */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceByName */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceByPath */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceBySerial */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceByStickyName */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetAutosave */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetDbPath */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetDbPathAndName */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetIDbSys */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetUnmanageIDbSys */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetFilter */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetIDbPath */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetUnmanageIDbPath */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetLogicalName */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetName */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::Init */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::ScanForResources */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::SetAutosave */
};


static const PRPC_STUB_FUNCTION IFsaServer_table[] =
{
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaServerStubVtbl =
{
    &IID_IFsaServer,
    &IFsaServer_ServerInfo,
    25,
    &IFsaServer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaTruncator, ver. 0.0,
   GUID={0x9CABC042,0x8AA4,0x11d0,{0x81,0xE6,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaTruncator_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    8178,
    8214,
    8250,
    8286,
    8322,
    8358,
    8394,
    8430,
    8466,
    8502,
    1212
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaTruncator_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaTruncator_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaTruncator_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaTruncator_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IFsaTruncatorProxyVtbl = 
{
    &IFsaTruncator_ProxyInfo,
    &IID_IFsaTruncator,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::GetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::GetKeepRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::GetMaxFilesPerRun */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::GetPremigratedSortOrder */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::GetRunInterval */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::SetMaxFilesPerRun */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::SetPremigratedSortOrder */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::SetRunInterval */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::SetKeepRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::Start */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::KickStart */
};


static const PRPC_STUB_FUNCTION IFsaTruncator_table[] =
{
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaTruncatorStubVtbl =
{
    &IID_IFsaTruncator,
    &IFsaTruncator_ServerInfo,
    15,
    &IFsaTruncator_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaPostIt, ver. 0.0,
   GUID={0xB5A1ED6A,0xCED4,0x4D16,{0x9A,0x76,0x8C,0xD4,0x47,0x3A,0x2C,0xE9}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaPostIt_FormatStringOffsetTable[] =
    {
    8538,
    8574,
    8610,
    8646,
    8688,
    8724,
    8760,
    2010,
    300,
    8796,
    8832,
    8868,
    2160,
    8904,
    8940,
    8976,
    570,
    1428,
    9012,
    9048,
    9084,
    9120,
    9156,
    9192,
    9228,
    9264,
    9300,
    9336
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaPostIt_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaPostIt_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaPostIt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaPostIt_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(31) _IFsaPostItProxyVtbl = 
{
    &IFsaPostIt_ProxyInfo,
    &IID_IFsaPostIt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetFileVersionId */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetFilterRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetMode */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetRequestAction */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetRequestOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetRequestSize */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetResult */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetResultAction */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetStoragePoolId */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetUSN */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetThreadId */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetFileVersionId */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetFilterRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetMode */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetRequestAction */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetRequestOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetRequestSize */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetResult */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetResultAction */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetStoragePoolId */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetUSN */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetThreadId */
};

const CInterfaceStubVtbl _IFsaPostItStubVtbl =
{
    &IID_IFsaPostIt,
    &IFsaPostIt_ServerInfo,
    31,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaRecallNotifyClient, ver. 0.0,
   GUID={0xD68BD5B1,0xD6AA,0x11d0,{0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaRecallNotifyClient_FormatStringOffsetTable[] =
    {
    9372,
    9408,
    9444
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifyClient_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifyClient_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaRecallNotifyClient_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifyClient_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IFsaRecallNotifyClientProxyVtbl = 
{
    &IFsaRecallNotifyClient_ProxyInfo,
    &IID_IFsaRecallNotifyClient,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyClient::IdentifyWithServer */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyClient::OnRecallStarted */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyClient::OnRecallFinished */
};

const CInterfaceStubVtbl _IFsaRecallNotifyClientStubVtbl =
{
    &IID_IFsaRecallNotifyClient,
    &IFsaRecallNotifyClient_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaRecallNotifyServer, ver. 0.0,
   GUID={0xD68BD5B2,0xD6AA,0x11d0,{0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaRecallNotifyServer_FormatStringOffsetTable[] =
    {
    9486,
    9522,
    9552,
    9588,
    9624,
    1062,
    1974,
    2010,
    9660,
    1140,
    1182
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifyServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifyServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaRecallNotifyServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifyServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IFsaRecallNotifyServerProxyVtbl = 
{
    &IFsaRecallNotifyServer_ProxyInfo,
    &IID_IFsaRecallNotifyServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::Init */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::Cancel */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetMode */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetRecallFlags */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetState */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::WasCancelled */
};

const CInterfaceStubVtbl _IFsaRecallNotifyServerStubVtbl =
{
    &IID_IFsaRecallNotifyServer,
    &IFsaRecallNotifyServer_ServerInfo,
    14,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaRecallNotifySend, ver. 0.0,
   GUID={0x931AC085,0xF98C,0x4595,{0x92,0xC0,0x70,0x6E,0xD3,0xDF,0xA6,0xD7}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaRecallNotifySend_FormatStringOffsetTable[] =
    {
    9696
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifySend_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifySend_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaRecallNotifySend_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifySend_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IFsaRecallNotifySendProxyVtbl = 
{
    &IFsaRecallNotifySend_ProxyInfo,
    &IID_IFsaRecallNotifySend,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifySend::SendNotification */
};

const CInterfaceStubVtbl _IFsaRecallNotifySendStubVtbl =
{
    &IID_IFsaRecallNotifySend,
    &IFsaRecallNotifySend_ServerInfo,
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

const CInterfaceProxyVtbl * _fsaint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IFsaFilterClientProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaFilterRecallProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaServerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaFilterProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaTruncatorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaPostItProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaRecallNotifySendProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaRecallNotifyClientProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaRecallNotifyServerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaResourceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaScanItemProxyVtbl,
    0
};

const CInterfaceStubVtbl * _fsaint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IFsaFilterClientStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaFilterRecallStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaServerStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaFilterStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaTruncatorStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaPostItStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaRecallNotifySendStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaRecallNotifyClientStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaRecallNotifyServerStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaResourceStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaScanItemStubVtbl,
    0
};

PCInterfaceName const _fsaint_InterfaceNamesList[] = 
{
    "IFsaFilterClient",
    "IFsaFilterRecall",
    "IFsaServer",
    "IFsaFilter",
    "IFsaTruncator",
    "IFsaPostIt",
    "IFsaRecallNotifySend",
    "IFsaRecallNotifyClient",
    "IFsaRecallNotifyServer",
    "IFsaResource",
    "IFsaScanItem",
    0
};

const IID *  _fsaint_BaseIIDList[] = 
{
    0,
    0,
    &IID_IHsmSystemState,
    0,
    &IID_IHsmSystemState,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};


#define _fsaint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _fsaint, pIID, n)

int __stdcall _fsaint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _fsaint, 11, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaint, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _fsaint, 11, *pIndex )
    
}

const ExtendedProxyFileInfo fsaint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _fsaint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _fsaint_StubVtblList,
    (const PCInterfaceName * ) & _fsaint_InterfaceNamesList,
    (const IID ** ) & _fsaint_BaseIIDList,
    & _fsaint_IID_Lookup, 
    11,
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
/* Compiler settings for fsaint.idl:
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


#include "fsaint.h"

#define TYPE_FORMAT_STRING_SIZE   557                               
#define PROC_FORMAT_STRING_SIZE   10247                             
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


extern const MIDL_SERVER_INFO IFsaFilter_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaFilter_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaFilterClient_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaFilterClient_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaFilterRecall_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaFilterRecall_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaResource_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaResource_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaScanItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaScanItem_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaTruncator_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaTruncator_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaPostIt_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaPostIt_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaRecallNotifyClient_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifyClient_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaRecallNotifyServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifyServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaRecallNotifySend_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifySend_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Cancel */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 26 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 28 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 30 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelRecall */

/* 32 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 34 */	NdrFcLong( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0x4 ),	/* 4 */
/* 40 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 48 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 58 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 60 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 62 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 64 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 66 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 68 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIdentifier */

/* 70 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 72 */	NdrFcLong( 0x0 ),	/* 0 */
/* 76 */	NdrFcShort( 0x5 ),	/* 5 */
/* 78 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 80 */	NdrFcShort( 0x30 ),	/* 48 */
/* 82 */	NdrFcShort( 0x22 ),	/* 34 */
/* 84 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 86 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 96 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 98 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 100 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter pResult */

/* 102 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 104 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 106 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIFilter */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x6 ),	/* 6 */
/* 122 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x22 ),	/* 34 */
/* 128 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 130 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFilter */

/* 140 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 142 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 144 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Parameter pResult */

/* 146 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 148 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 150 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 154 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteRecall */

/* 158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x7 ),	/* 7 */
/* 166 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 172 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 174 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 184 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 186 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 188 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 192 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumRecalls */

/* 196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 204 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 210 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 212 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 222 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 224 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 226 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 230 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x9 ),	/* 9 */
/* 242 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x4c ),	/* 76 */
/* 248 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 250 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 260 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 262 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 264 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 268 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMachineName */


	/* Procedure GetLogicalName */

/* 272 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0xa ),	/* 10 */
/* 280 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 286 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 288 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 298 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 300 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 302 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 304 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 306 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 312 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResult */


	/* Procedure GetAutosave */


	/* Procedure GetRecallCount */


	/* Procedure GetMaxRecallBuffers */

/* 316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0xb ),	/* 11 */
/* 324 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x24 ),	/* 36 */
/* 330 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 332 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pHr */


	/* Parameter pMilliseconds */


	/* Parameter pCount */


	/* Parameter pMaxBuffers */

/* 342 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 344 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxRecalls */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0xc ),	/* 12 */
/* 362 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x24 ),	/* 36 */
/* 368 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 370 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMaxRecalls */

/* 380 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 382 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 388 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecallFlags */


	/* Procedure GetMinRecallInterval */

/* 392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0xd ),	/* 13 */
/* 400 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x24 ),	/* 36 */
/* 406 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 408 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recallFlags */


	/* Parameter pMinIterval */

/* 418 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 420 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 424 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 426 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 430 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0xe ),	/* 14 */
/* 438 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 442 */	NdrFcShort( 0x24 ),	/* 36 */
/* 444 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 446 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 456 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 458 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 460 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 464 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsEnabled */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0xf ),	/* 15 */
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

/* 494 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 496 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Pause */

/* 500 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 502 */	NdrFcLong( 0x0 ),	/* 0 */
/* 506 */	NdrFcShort( 0x10 ),	/* 16 */
/* 508 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 514 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 516 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 528 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateDefaultRules */


	/* Procedure Resume */

/* 532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x11 ),	/* 17 */
/* 540 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 546 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 548 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 560 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAdminExemption */

/* 564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x12 ),	/* 18 */
/* 572 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x24 ),	/* 36 */
/* 578 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 580 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isExempt */

/* 590 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 592 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 598 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMode */


	/* Procedure SetIsEnabled */

/* 602 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 608 */	NdrFcShort( 0x13 ),	/* 19 */
/* 610 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 612 */	NdrFcShort( 0x8 ),	/* 8 */
/* 614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 616 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 618 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mode */


	/* Parameter isEnabled */

/* 628 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 630 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 634 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 636 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxRecalls */

/* 640 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0x14 ),	/* 20 */
/* 648 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 652 */	NdrFcShort( 0x8 ),	/* 8 */
/* 654 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 656 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter maxRecalls */

/* 666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 668 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 674 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRecallCount */


	/* Procedure SetMinRecallInterval */

/* 678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x15 ),	/* 21 */
/* 686 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 692 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 694 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter count */


	/* Parameter minIterval */

/* 704 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 706 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 712 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxRecallBuffers */

/* 716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x16 ),	/* 22 */
/* 724 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 730 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 732 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter maxBuffers */

/* 742 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 744 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 748 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 750 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ScanForResources */


	/* Procedure StartIdentify */


	/* Procedure Start */

/* 754 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 756 */	NdrFcLong( 0x0 ),	/* 0 */
/* 760 */	NdrFcShort( 0x17 ),	/* 23 */
/* 762 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 768 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 770 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 782 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StopIoctlThread */

/* 786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x18 ),	/* 24 */
/* 794 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x8 ),	/* 8 */
/* 800 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 802 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 814 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindRecall */

/* 818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x19 ),	/* 25 */
/* 826 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 828 */	NdrFcShort( 0x30 ),	/* 48 */
/* 830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 832 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 834 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recallId */

/* 844 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 846 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 848 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter pRecall */

/* 850 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 852 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 854 */	NdrFcShort( 0x66 ),	/* Type Offset=102 */

	/* Return value */

/* 856 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 858 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAdminExemption */

/* 862 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 864 */	NdrFcLong( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x1a ),	/* 26 */
/* 870 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 876 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 878 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isExempt */

/* 888 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 890 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 896 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareBy */

/* 900 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x3 ),	/* 3 */
/* 908 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 910 */	NdrFcShort( 0x6 ),	/* 6 */
/* 912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 914 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 916 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter by */

/* 926 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 928 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 930 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 934 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToAuthenticationId */

/* 938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 944 */	NdrFcShort( 0x4 ),	/* 4 */
/* 946 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 948 */	NdrFcShort( 0x10 ),	/* 16 */
/* 950 */	NdrFcShort( 0x22 ),	/* 34 */
/* 952 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 954 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter luidHigh */

/* 964 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 966 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 968 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter luidLow */

/* 970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 972 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 976 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 978 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 980 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 984 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIClient */

/* 988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0x5 ),	/* 5 */
/* 996 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1002 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1004 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClient */

/* 1014 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1016 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1018 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter pResult */

/* 1020 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1022 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1024 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1028 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToMachineName */

/* 1032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1040 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1046 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1048 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1058 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1060 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1062 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 1064 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1066 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1068 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1072 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAuthenticationId */

/* 1076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1084 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1090 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1092 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLuidHigh */

/* 1102 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1104 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pluidLow */

/* 1108 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1110 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1116 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */


	/* Procedure GetDomainName */

/* 1120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1128 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1134 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1136 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 1146 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1148 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1150 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 1152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1154 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1160 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLastRecallTime */

/* 1164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1170 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1172 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1178 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1180 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 1190 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1192 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1194 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 1196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1198 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUserName */


	/* Procedure GetDbPath */


	/* Procedure GetUserName */

/* 1202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1208 */	NdrFcShort( 0xc ),	/* 12 */
/* 1210 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1216 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1218 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pPath */


	/* Parameter pName */

/* 1228 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1230 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1232 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 1234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1236 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1242 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WasCancelled */


	/* Procedure HasRecallDisabled */

/* 1246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1252 */	NdrFcShort( 0xd ),	/* 13 */
/* 1254 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1262 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1274 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure KickStart */


	/* Procedure HitRecallLimit */

/* 1278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0xe ),	/* 14 */
/* 1286 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1292 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1294 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1306 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAuthenticationId */

/* 1310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1316 */	NdrFcShort( 0xf ),	/* 15 */
/* 1318 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1320 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1324 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1326 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter luidHigh */

/* 1336 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1338 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter luidLow */

/* 1342 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1344 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1350 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDomainName */

/* 1354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1360 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1362 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1368 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1370 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1380 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1382 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1384 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 1386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1388 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHasRecallDisabled */

/* 1392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1400 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1406 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1408 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isDisabled */

/* 1418 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1420 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1424 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1426 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HasCompleted */


	/* Procedure SetHitRecallLimit */

/* 1430 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1436 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1438 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1442 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1444 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1446 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter resultHr */


	/* Parameter hitLimit */

/* 1456 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1458 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1464 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLastRecallTime */

/* 1468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1474 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1476 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1478 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1480 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1482 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1484 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter time */

/* 1494 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1496 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1498 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 1500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1502 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPath */


	/* Procedure SetMachineName */

/* 1506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1514 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1520 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1522 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */


	/* Parameter pName */

/* 1532 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1534 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1536 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */


	/* Return value */

/* 1538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1540 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUserName */

/* 1544 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1550 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1552 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1556 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1558 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1560 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1570 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1572 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1574 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 1576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1578 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTokenSource */

/* 1582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1590 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1592 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1596 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1598 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1606 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter source */

/* 1608 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1610 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1612 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1616 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendRecallInfo */

/* 1620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1628 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1630 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1634 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1636 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1644 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 1646 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1648 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1650 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter starting */

/* 1652 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1654 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rHr */

/* 1658 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1660 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1664 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1666 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IdentifyThread */

/* 1670 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1672 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1676 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1678 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1684 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1686 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1694 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1698 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsAdmin */

/* 1702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1708 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1710 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1712 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1716 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1718 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isAdmin */

/* 1728 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1730 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1732 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIsAdmin */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1748 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1754 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1756 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1764 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isAdmin */

/* 1766 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1768 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1770 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 1772 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1774 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckRecallLimit */

/* 1778 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1784 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1786 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1788 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1792 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1794 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter minRecallInterval */

/* 1804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1806 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter maxRecalls */

/* 1810 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1812 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter exemptAdmin */

/* 1816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1818 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1820 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 1822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1824 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIdentifier */

/* 1828 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1834 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1836 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1838 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1840 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1842 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1844 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1852 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 1854 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1856 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1858 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter pResult */

/* 1860 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1862 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1864 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1866 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1868 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIRecall */

/* 1872 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1874 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1878 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1880 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1884 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1886 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1888 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 1898 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1900 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1902 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pResult */

/* 1904 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1906 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1908 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1910 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1912 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1914 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToDriversRecallId */

/* 1916 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1918 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1922 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1924 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1926 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1928 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1930 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1932 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 1942 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1944 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1946 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 1948 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1950 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1952 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1956 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToDriversContextId */

/* 1960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1966 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1968 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1970 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1972 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1974 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1976 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1984 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 1986 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1988 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1990 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 1992 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1994 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1996 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1998 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2000 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareBy */

/* 2004 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2010 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2012 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2014 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2016 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2018 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2020 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2028 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter by */

/* 2030 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2032 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2034 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 2036 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2038 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 2042 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2044 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2050 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2054 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2056 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2058 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2066 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 2068 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2070 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2072 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 2074 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2076 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2078 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecallFlags */


	/* Procedure GetMode */

/* 2080 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2082 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2086 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2088 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2092 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2094 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2096 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2104 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recallFlags */


	/* Parameter pMode */

/* 2106 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2108 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2114 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSize */


	/* Procedure GetRequestSize */


	/* Procedure GetOffset */

/* 2118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0xa ),	/* 10 */
/* 2126 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2130 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2132 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2134 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */


	/* Parameter pRequestSize */


	/* Parameter pOffset */

/* 2144 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2146 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2148 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2152 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 2156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2162 */	NdrFcShort( 0xb ),	/* 11 */
/* 2164 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2170 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2172 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 2182 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2184 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2186 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 2188 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2190 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2194 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2196 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResource */

/* 2200 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2206 */	NdrFcShort( 0xc ),	/* 12 */
/* 2208 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2214 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2216 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2224 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppResource */

/* 2226 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2228 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2230 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 2232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2234 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 2238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2244 */	NdrFcShort( 0xe ),	/* 14 */
/* 2246 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2252 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2254 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 2264 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2266 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2268 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 2270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2272 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUSN */


	/* Procedure GetFileUsn */


	/* Procedure GetSize */

/* 2276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0xf ),	/* 15 */
/* 2284 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2288 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2290 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2292 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pUsn */


	/* Parameter pFileUsn */


	/* Parameter pSize */

/* 2302 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2304 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2306 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2310 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 2314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2322 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2326 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2328 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2330 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2338 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 2340 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2342 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2344 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 2346 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2348 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIDbPath */


	/* Procedure GetGroup */


	/* Procedure GetUserName */

/* 2352 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2354 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2358 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2360 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2362 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2366 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2368 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */


	/* Parameter pOwner */


	/* Parameter pName */

/* 2378 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2380 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2382 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 2384 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2386 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2392 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WasCancelled */

/* 2396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2402 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2404 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2410 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2412 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2424 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateLocalStream */

/* 2428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2434 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2436 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2442 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2444 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2452 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppStream */

/* 2454 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2456 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2458 */	NdrFcShort( 0xc4 ),	/* Type Offset=196 */

	/* Return value */

/* 2460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2462 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckRecallLimit */

/* 2466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2472 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2474 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2476 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2480 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 2482 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter minRecallInterval */

/* 2492 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2494 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter maxRecalls */

/* 2498 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2500 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter exemptAdmin */

/* 2504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2506 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2508 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 2510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2512 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddClient */

/* 2516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2522 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2524 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2530 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2532 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWaitingClient */

/* 2542 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2544 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2546 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 2548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2550 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddPremigrated */

/* 2554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2560 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2562 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2564 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2568 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2570 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2578 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 2580 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2582 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2584 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 2586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2588 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2590 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 2592 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2594 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2596 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter isWaitingForClose */

/* 2598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2600 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter usn */

/* 2604 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2606 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2608 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2610 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2612 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddTruncated */

/* 2616 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2622 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2624 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2626 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2630 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2632 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 2642 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2644 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2646 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 2648 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2650 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2652 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 2654 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2656 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2658 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2660 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2662 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BeginSession */

/* 2666 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2668 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2672 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2674 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2676 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2678 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2680 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2682 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2690 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2692 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2694 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2696 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter logControl */

/* 2698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2700 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter runId */

/* 2704 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2706 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter subRunId */

/* 2710 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2712 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppSession */

/* 2716 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2718 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2720 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 2722 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2724 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2726 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BeginValidate */

/* 2728 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2730 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2734 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2736 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2740 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2742 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2744 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2752 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2756 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckForValidate */

/* 2760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2766 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2768 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2774 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2776 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bForceValidate */

/* 2786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2788 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2794 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareBy */

/* 2798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2804 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2806 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2808 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2812 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2814 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2822 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter by */

/* 2824 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2826 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2828 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 2830 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2832 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToAlternatePath */

/* 2836 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2838 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2842 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2844 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2848 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2850 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2852 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2860 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 2862 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2864 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2866 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 2868 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2870 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2872 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2874 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2876 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIdentifier */

/* 2880 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2882 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2886 */	NdrFcShort( 0xa ),	/* 10 */
/* 2888 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2890 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2892 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2894 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2896 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2904 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 2906 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2908 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2910 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter pResult */

/* 2912 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2914 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2916 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2920 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIResource */

/* 2924 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2930 */	NdrFcShort( 0xb ),	/* 11 */
/* 2932 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2936 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2938 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2940 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 2950 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2952 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2954 */	NdrFcShort( 0x9c ),	/* Type Offset=156 */

	/* Parameter pResult */

/* 2956 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2958 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2960 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2964 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToName */

/* 2968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2974 */	NdrFcShort( 0xc ),	/* 12 */
/* 2976 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2980 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2982 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2984 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2992 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2994 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2996 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2998 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 3000 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3002 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3004 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3006 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3008 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToUserName */

/* 3012 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3018 */	NdrFcShort( 0xd ),	/* 13 */
/* 3020 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3024 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3026 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3028 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3036 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter userName */

/* 3038 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3040 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3042 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 3044 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3046 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3048 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3050 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3052 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToPath */

/* 3056 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3058 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3062 */	NdrFcShort( 0xe ),	/* 14 */
/* 3064 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3068 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3070 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3072 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3080 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 3082 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3084 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3086 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 3088 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3090 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3092 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3094 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3096 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToSerial */

/* 3100 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3102 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3106 */	NdrFcShort( 0xf ),	/* 15 */
/* 3108 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3112 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3114 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3116 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serial */

/* 3126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3128 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 3132 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3134 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3136 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3140 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToStickyName */

/* 3144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3150 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3152 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3156 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3158 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3160 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3170 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3172 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3174 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 3176 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3178 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3180 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3182 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3184 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EndSession */

/* 3188 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3190 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3194 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3196 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3202 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3204 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3212 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 3214 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3216 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3218 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Return value */

/* 3220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3222 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EndValidate */

/* 3226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3232 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3234 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3240 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3242 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter state */

/* 3252 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3254 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3256 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3260 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumDefaultRules */

/* 3264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3270 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3272 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3278 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3280 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 3290 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3292 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3294 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 3296 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3298 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirst */

/* 3302 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3308 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3310 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3314 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3316 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3318 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3326 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 3328 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3330 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3332 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pSession */

/* 3334 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3336 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3338 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter ppScanItem */

/* 3340 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3342 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3344 */	NdrFcShort( 0xec ),	/* Type Offset=236 */

	/* Return value */

/* 3346 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3348 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirstInRPIndex */

/* 3352 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3354 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3358 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3360 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3366 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3368 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 3378 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3380 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3382 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter ppScanItem */

/* 3384 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3386 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3388 */	NdrFcShort( 0xec ),	/* Type Offset=236 */

	/* Return value */

/* 3390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3392 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirstInDbIndex */

/* 3396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3402 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3404 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3410 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3412 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3420 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 3422 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3424 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3426 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter ppScanItem */

/* 3428 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3430 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3432 */	NdrFcShort( 0xec ),	/* Type Offset=236 */

	/* Return value */

/* 3434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3436 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNext */

/* 3440 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3446 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3448 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3452 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3454 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3456 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3464 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 3466 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3468 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3470 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Return value */

/* 3472 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3474 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNextInRPIndex */

/* 3478 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3484 */	NdrFcShort( 0x19 ),	/* 25 */
/* 3486 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3492 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3494 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 3504 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3506 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3508 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Return value */

/* 3510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3512 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNextInDbIndex */

/* 3516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3522 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3524 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3530 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3532 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 3542 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3544 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3546 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Return value */

/* 3548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3550 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFileId */

/* 3554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3560 */	NdrFcShort( 0x1b ),	/* 27 */
/* 3562 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3564 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3568 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3570 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3578 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileId */

/* 3580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3582 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3584 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSession */

/* 3586 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3588 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3590 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter ppScanItem */

/* 3592 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3594 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3596 */	NdrFcShort( 0xec ),	/* Type Offset=236 */

	/* Return value */

/* 3598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3600 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindObjectId */

/* 3604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3610 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3612 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3614 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3618 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3620 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter objIdHi */

/* 3630 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3632 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3634 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter objIdLo */

/* 3636 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3638 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3640 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSession */

/* 3642 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3644 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3646 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Parameter ppScanItem */

/* 3648 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3650 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3652 */	NdrFcShort( 0xec ),	/* Type Offset=236 */

	/* Return value */

/* 3654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3656 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAlternatePath */

/* 3660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3666 */	NdrFcShort( 0x1d ),	/* 29 */
/* 3668 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3674 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3676 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3686 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3688 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3690 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 3692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3694 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3700 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDefaultRules */

/* 3704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3710 */	NdrFcShort( 0x1e ),	/* 30 */
/* 3712 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3716 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3718 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3720 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3728 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 3730 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3732 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3734 */	NdrFcShort( 0xf0 ),	/* Type Offset=240 */

	/* Return value */

/* 3736 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3738 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDbPath */

/* 3742 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3744 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3748 */	NdrFcShort( 0x1f ),	/* 31 */
/* 3750 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3754 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3756 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3758 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3768 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3770 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3772 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 3774 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3776 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3782 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUnmanageDbPath */

/* 3786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3792 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3794 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3796 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3798 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3800 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3802 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3810 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3812 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3814 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3816 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 3818 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3820 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3822 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3824 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3826 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFreeLevel */

/* 3830 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3832 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3836 */	NdrFcShort( 0x21 ),	/* 33 */
/* 3838 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3842 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3844 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3846 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3854 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLevel */

/* 3856 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3858 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3862 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3864 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFsName */

/* 3868 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3870 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3874 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3876 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3878 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3882 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3884 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3892 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 3894 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3896 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3898 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 3900 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3902 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3908 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmEngine */

/* 3912 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3918 */	NdrFcShort( 0x23 ),	/* 35 */
/* 3920 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3926 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3928 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3936 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEngine */

/* 3938 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3940 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3942 */	NdrFcShort( 0x106 ),	/* Type Offset=262 */

	/* Return value */

/* 3944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3946 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmLevel */

/* 3950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3956 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3958 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3962 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3964 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3966 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3974 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLevel */

/* 3976 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3978 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3984 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 3988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3994 */	NdrFcShort( 0x25 ),	/* 37 */
/* 3996 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4000 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4002 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4004 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 4014 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4016 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4018 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 4020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4022 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogicalName */

/* 4026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4032 */	NdrFcShort( 0x26 ),	/* 38 */
/* 4034 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4040 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4042 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4050 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 4052 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4054 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4056 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4060 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4064 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4066 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManageableItemLogicalSize */

/* 4070 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4072 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4076 */	NdrFcShort( 0x27 ),	/* 39 */
/* 4078 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4082 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4084 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4086 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4094 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 4096 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4098 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4100 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4104 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManageableItemAccessTime */

/* 4108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4114 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4116 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4120 */	NdrFcShort( 0x50 ),	/* 80 */
/* 4122 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4124 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isRelative */

/* 4134 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4136 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pTime */

/* 4140 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 4142 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4144 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 4146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4148 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManagingHsm */

/* 4152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4158 */	NdrFcShort( 0x29 ),	/* 41 */
/* 4160 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4164 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4166 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4168 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 4178 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4180 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4182 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 4184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4186 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 4190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4196 */	NdrFcShort( 0x2a ),	/* 42 */
/* 4198 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4204 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4206 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 4216 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4218 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4220 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4222 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4224 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4230 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOldPath */

/* 4234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4240 */	NdrFcShort( 0x2b ),	/* 43 */
/* 4242 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4244 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4248 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4250 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 4260 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4262 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4264 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4268 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4274 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 4278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4284 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4286 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4292 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4294 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 4304 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4306 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4308 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4312 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4318 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSerial */

/* 4322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4328 */	NdrFcShort( 0x2d ),	/* 45 */
/* 4330 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4334 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4336 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4338 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serial */

/* 4348 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4350 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4356 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSizes */

/* 4360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4366 */	NdrFcShort( 0x2e ),	/* 46 */
/* 4368 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4372 */	NdrFcShort( 0x98 ),	/* 152 */
/* 4374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 4376 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTotal */

/* 4386 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4388 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4390 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pFree */

/* 4392 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4394 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4396 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPremigrated */

/* 4398 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4400 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4402 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pTruncated */

/* 4404 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4406 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4408 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4412 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTruncator */

/* 4416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4422 */	NdrFcShort( 0x2f ),	/* 47 */
/* 4424 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4430 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4432 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppTruncator */

/* 4442 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4444 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4446 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 4448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4450 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUncPath */

/* 4454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4460 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4462 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4466 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4468 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4470 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 4480 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4482 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4484 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4486 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4488 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4492 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4494 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUserFriendlyName */

/* 4498 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4500 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4504 */	NdrFcShort( 0x31 ),	/* 49 */
/* 4506 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4508 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4510 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4512 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4514 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4522 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 4524 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4526 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4528 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4530 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4532 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4536 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4538 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStickyName */

/* 4542 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4544 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4548 */	NdrFcShort( 0x32 ),	/* 50 */
/* 4550 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4554 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4556 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4558 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4566 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 4568 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4570 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4572 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 4574 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4576 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4582 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsActive */

/* 4586 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4592 */	NdrFcShort( 0x33 ),	/* 51 */
/* 4594 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4598 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4600 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4602 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4614 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsAvailable */

/* 4618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4624 */	NdrFcShort( 0x34 ),	/* 52 */
/* 4626 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4632 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4634 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4642 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4646 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsDeletePending */

/* 4650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4656 */	NdrFcShort( 0x35 ),	/* 53 */
/* 4658 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4662 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4664 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4666 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4674 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4676 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4678 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsManaged */

/* 4682 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4684 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4688 */	NdrFcShort( 0x36 ),	/* 54 */
/* 4690 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4694 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4696 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4698 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4706 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4710 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Manage */

/* 4714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4720 */	NdrFcShort( 0x37 ),	/* 55 */
/* 4722 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 4724 */	NdrFcShort( 0x58 ),	/* 88 */
/* 4726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4728 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 4730 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4738 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4740 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4742 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4744 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 4746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4748 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4750 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 4752 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4754 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4756 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter storagePoolId */

/* 4758 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4760 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4762 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter truncate */

/* 4764 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4766 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4772 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 4774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ManagedBy */

/* 4776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4782 */	NdrFcShort( 0x38 ),	/* 56 */
/* 4784 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4786 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4790 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 4792 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4800 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hsmId */

/* 4802 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4804 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4806 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter hsmLevel */

/* 4808 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4810 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter release */

/* 4814 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4816 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4820 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4822 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NeedsRepair */

/* 4826 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4828 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4832 */	NdrFcShort( 0x39 ),	/* 57 */
/* 4834 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4840 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4842 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4852 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4854 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessResult */

/* 4858 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4860 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4864 */	NdrFcShort( 0x3a ),	/* 58 */
/* 4866 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4870 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4872 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4874 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4882 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResult */

/* 4884 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4886 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4888 */	NdrFcShort( 0x132 ),	/* Type Offset=306 */

	/* Return value */

/* 4890 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4892 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Recall */

/* 4896 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4898 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4902 */	NdrFcShort( 0x3b ),	/* 59 */
/* 4904 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4906 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4910 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4912 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4920 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4922 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4924 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4926 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 4928 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4930 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4932 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 4934 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4936 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4938 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter deletePlaceholder */

/* 4940 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4942 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4946 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4948 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemovePremigrated */

/* 4952 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4954 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4958 */	NdrFcShort( 0x3c ),	/* 60 */
/* 4960 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4962 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4966 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4968 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4976 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4978 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4980 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4982 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 4984 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4986 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4988 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 4990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4992 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4994 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4998 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveTruncated */

/* 5002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5008 */	NdrFcShort( 0x3d ),	/* 61 */
/* 5010 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5012 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5016 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5018 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5026 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 5028 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5030 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5032 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 5034 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5036 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5038 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5040 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5042 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5044 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5046 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5048 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHsmLevel */

/* 5052 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5054 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5058 */	NdrFcShort( 0x3e ),	/* 62 */
/* 5060 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5064 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5066 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5068 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5076 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter level */

/* 5078 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5080 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5084 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5086 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5088 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsActive */

/* 5090 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5092 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5096 */	NdrFcShort( 0x3f ),	/* 63 */
/* 5098 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5100 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5102 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5104 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5106 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5114 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isActive */

/* 5116 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5118 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5122 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5124 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsAvailable */

/* 5128 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5130 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5134 */	NdrFcShort( 0x40 ),	/* 64 */
/* 5136 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5142 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5144 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5152 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isActive */

/* 5154 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5156 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5160 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5162 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsDeletePending */

/* 5166 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5168 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5172 */	NdrFcShort( 0x41 ),	/* 65 */
/* 5174 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5176 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5178 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5180 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5182 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5190 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isDeletePending */

/* 5192 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5194 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5200 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetManageableItemLogicalSize */

/* 5204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5210 */	NdrFcShort( 0x42 ),	/* 66 */
/* 5212 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5214 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5218 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5220 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5228 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 5230 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5232 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5234 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5238 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetManageableItemAccessTime */

/* 5242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5248 */	NdrFcShort( 0x43 ),	/* 67 */
/* 5250 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5252 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5254 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5256 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5258 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5266 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isRelative */

/* 5268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5270 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pTime */

/* 5274 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5276 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5278 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 5280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5282 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSerial */

/* 5286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5292 */	NdrFcShort( 0x44 ),	/* 68 */
/* 5294 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5300 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5302 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serial */

/* 5312 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5314 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5320 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StartJob */

/* 5324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5330 */	NdrFcShort( 0x45 ),	/* 69 */
/* 5332 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5338 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5340 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5348 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter startingPath */

/* 5350 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5352 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5354 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pSession */

/* 5356 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5358 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5360 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Return value */

/* 5362 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5364 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StartJobSession */

/* 5368 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5374 */	NdrFcShort( 0x46 ),	/* 70 */
/* 5376 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5380 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5382 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5384 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5392 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pJob */

/* 5394 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5396 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5398 */	NdrFcShort( 0x144 ),	/* Type Offset=324 */

	/* Parameter subRunId */

/* 5400 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5402 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppSession */

/* 5406 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5408 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5410 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 5412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5414 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Validate */

/* 5418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5424 */	NdrFcShort( 0x47 ),	/* 71 */
/* 5426 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5428 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5432 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5434 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5442 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 5444 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5446 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5448 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 5450 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5452 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5454 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5456 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5458 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5460 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter usn */

/* 5462 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5464 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5466 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5470 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetupValidateJob */

/* 5474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5480 */	NdrFcShort( 0x48 ),	/* 72 */
/* 5482 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5484 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5488 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5490 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter runtime */

/* 5500 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5502 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5504 */	NdrFcShort( 0x156 ),	/* Type Offset=342 */

	/* Return value */

/* 5506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5508 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUsnId */

/* 5512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5518 */	NdrFcShort( 0x49 ),	/* 73 */
/* 5520 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5524 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5526 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5528 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5536 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter usnId */

/* 5538 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5540 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5542 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5546 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ValidateForTruncate */

/* 5550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5556 */	NdrFcShort( 0x4a ),	/* 74 */
/* 5558 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5560 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5564 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5566 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 5576 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5578 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5580 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter offset */

/* 5582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5584 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5586 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5588 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5590 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5592 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter usn */

/* 5594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5596 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5598 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5602 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckIfSparse */

/* 5606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5612 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5614 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5616 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5620 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5622 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5630 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 5632 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5634 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5636 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5638 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5640 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5642 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5646 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIScanItem */

/* 5650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5656 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5658 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5662 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5664 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5666 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5674 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 5676 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5678 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5680 */	NdrFcShort( 0xda ),	/* Type Offset=218 */

	/* Parameter pResult */

/* 5682 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5684 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5686 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5688 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5690 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToPathAndName */

/* 5694 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5700 */	NdrFcShort( 0x5 ),	/* 5 */
/* 5702 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5706 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5708 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5710 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5718 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 5720 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5722 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5724 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter name */

/* 5726 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5728 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5730 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pResult */

/* 5732 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5734 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5736 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5740 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Copy */

/* 5744 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5750 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5752 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5754 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5758 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5760 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dest */

/* 5770 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5772 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5774 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter retainHierarcy */

/* 5776 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5778 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter expandPlaceholders */

/* 5782 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5784 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter overwriteExisting */

/* 5788 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5790 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5794 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5796 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateLocalStream */

/* 5800 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5802 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5806 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5808 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5812 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5814 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5816 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5824 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppStream */

/* 5826 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5828 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5830 */	NdrFcShort( 0xc4 ),	/* Type Offset=196 */

	/* Return value */

/* 5832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5834 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreatePlaceholder */

/* 5838 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5846 */	NdrFcShort( 0xd0 ),	/* ia64 Stack size/offset = 208 */
/* 5848 */	NdrFcShort( 0x140 ),	/* 320 */
/* 5850 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5852 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 5854 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 5864 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5866 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5868 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5870 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5872 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5874 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 5876 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5878 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5880 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Parameter checkUsn */

/* 5882 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5884 */	NdrFcShort( 0xb0 ),	/* ia64 Stack size/offset = 176 */
/* 5886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter usn */

/* 5888 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5890 */	NdrFcShort( 0xb8 ),	/* ia64 Stack size/offset = 184 */
/* 5892 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pUsn */

/* 5894 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5896 */	NdrFcShort( 0xc0 ),	/* ia64 Stack size/offset = 192 */
/* 5898 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5902 */	NdrFcShort( 0xc8 ),	/* ia64 Stack size/offset = 200 */
/* 5904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Delete */

/* 5906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5912 */	NdrFcShort( 0x9 ),	/* 9 */
/* 5914 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5920 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5922 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5934 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeletePlaceholder */

/* 5938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5944 */	NdrFcShort( 0xa ),	/* 10 */
/* 5946 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5948 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5952 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5954 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5962 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 5964 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5966 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5968 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5972 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5974 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5978 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirstPlaceholder */

/* 5982 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5988 */	NdrFcShort( 0xb ),	/* 11 */
/* 5990 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5994 */	NdrFcShort( 0x16c ),	/* 364 */
/* 5996 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 5998 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 6008 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6010 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6012 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSize */

/* 6014 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6016 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6018 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 6020 */	NdrFcShort( 0x112 ),	/* Flags:  must free, out, simple ref, */
/* 6022 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6024 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 6026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6028 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNextPlaceholder */

/* 6032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6038 */	NdrFcShort( 0xc ),	/* 12 */
/* 6040 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6042 */	NdrFcShort( 0x164 ),	/* 356 */
/* 6044 */	NdrFcShort( 0x16c ),	/* 364 */
/* 6046 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 6048 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 6058 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 6060 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6062 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSize */

/* 6064 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 6066 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6068 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 6070 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 6072 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6074 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 6076 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6078 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAccessTime */

/* 6082 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6084 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6088 */	NdrFcShort( 0xd ),	/* 13 */
/* 6090 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6094 */	NdrFcShort( 0x34 ),	/* 52 */
/* 6096 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6098 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 6108 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 6110 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6112 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 6114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6116 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileId */

/* 6120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6126 */	NdrFcShort( 0xe ),	/* 14 */
/* 6128 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6132 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6134 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6136 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */

/* 6146 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6148 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6150 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6154 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFullPathAndName */

/* 6158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6164 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6166 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 6168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6172 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 6174 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prependix */

/* 6184 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6186 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6188 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter appendix */

/* 6190 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6192 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6194 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pPath */

/* 6196 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6198 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6200 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 6202 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6204 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6210 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogicalSize */

/* 6214 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6220 */	NdrFcShort( 0x12 ),	/* 18 */
/* 6222 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6226 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6228 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6230 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 6240 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6242 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6244 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6248 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetModifyTime */

/* 6252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6258 */	NdrFcShort( 0x13 ),	/* 19 */
/* 6260 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6264 */	NdrFcShort( 0x34 ),	/* 52 */
/* 6266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6268 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 6278 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 6280 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6282 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 6284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6286 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogicalName */


	/* Procedure GetName */

/* 6290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6296 */	NdrFcShort( 0x14 ),	/* 20 */
/* 6298 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6304 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6306 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6314 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 6316 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6318 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6320 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 6322 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6324 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 6328 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6330 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetOwner */

/* 6334 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6336 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6340 */	NdrFcShort( 0x15 ),	/* 21 */
/* 6342 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6348 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6350 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pOwner */

/* 6360 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6362 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6364 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 6366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6368 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 6372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6374 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPathForFind */

/* 6378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6384 */	NdrFcShort( 0x16 ),	/* 22 */
/* 6386 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6392 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 6394 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6402 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter searchName */

/* 6404 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6406 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6408 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pPath */

/* 6410 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6412 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6414 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 6416 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6418 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6424 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 6428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6434 */	NdrFcShort( 0x17 ),	/* 23 */
/* 6436 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6442 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6444 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6452 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 6454 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6456 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6458 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 6460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6462 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6466 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6468 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPathAndName */

/* 6472 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6474 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6478 */	NdrFcShort( 0x18 ),	/* 24 */
/* 6480 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6484 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6486 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 6488 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6496 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter appendix */

/* 6498 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6500 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6502 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pPath */

/* 6504 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6506 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6508 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 6510 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6512 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6516 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6518 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPhysicalSize */

/* 6522 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6528 */	NdrFcShort( 0x19 ),	/* 25 */
/* 6530 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6534 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6536 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6538 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 6548 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6550 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6552 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6556 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPlaceholder */

/* 6560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6566 */	NdrFcShort( 0x1a ),	/* 26 */
/* 6568 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6570 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6572 */	NdrFcShort( 0x124 ),	/* 292 */
/* 6574 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 6576 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6584 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 6586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6588 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6590 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 6592 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6594 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6596 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 6598 */	NdrFcShort( 0x112 ),	/* Flags:  must free, out, simple ref, */
/* 6600 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6602 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 6604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6606 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 6610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6616 */	NdrFcShort( 0x1b ),	/* 27 */
/* 6618 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6624 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6626 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 6636 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6638 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6640 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 6642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6644 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUncPathAndName */

/* 6648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6654 */	NdrFcShort( 0x1c ),	/* 28 */
/* 6656 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 6658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6660 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6662 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 6664 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prependix */

/* 6674 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6676 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6678 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter appendix */

/* 6680 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6682 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6684 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter pPath */

/* 6686 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 6688 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6690 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 6692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6694 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6700 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVersionId */

/* 6704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6710 */	NdrFcShort( 0x1d ),	/* 29 */
/* 6712 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6716 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6718 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6720 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6728 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 6730 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6732 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6734 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6736 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6738 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HasExtendedAttributes */

/* 6742 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6744 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6748 */	NdrFcShort( 0x1e ),	/* 30 */
/* 6750 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6754 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6756 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6758 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6770 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsALink */

/* 6774 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6780 */	NdrFcShort( 0x1f ),	/* 31 */
/* 6782 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6786 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6788 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6790 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6802 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsAParent */

/* 6806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6812 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6814 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6820 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6822 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6834 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsARelativeParent */

/* 6838 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6844 */	NdrFcShort( 0x21 ),	/* 33 */
/* 6846 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6852 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6854 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6864 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6866 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsCompressed */

/* 6870 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6876 */	NdrFcShort( 0x22 ),	/* 34 */
/* 6878 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6884 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6886 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6894 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6898 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsDeleteOK */

/* 6902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6908 */	NdrFcShort( 0x23 ),	/* 35 */
/* 6910 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6914 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6916 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6918 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPostIt */

/* 6928 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6930 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6932 */	NdrFcShort( 0x192 ),	/* Type Offset=402 */

	/* Return value */

/* 6934 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6936 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsEncrypted */

/* 6940 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6946 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6948 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6954 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6956 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6966 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6968 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsGroupMemberOf */

/* 6972 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6974 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6978 */	NdrFcShort( 0x25 ),	/* 37 */
/* 6980 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6984 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6986 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6988 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6996 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter group */

/* 6998 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7000 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7002 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 7004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7006 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsHidden */

/* 7010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7016 */	NdrFcShort( 0x26 ),	/* 38 */
/* 7018 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7024 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7026 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7034 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7036 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7038 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsManageable */

/* 7042 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7044 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7048 */	NdrFcShort( 0x27 ),	/* 39 */
/* 7050 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7052 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7054 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7056 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7058 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7066 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7068 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7070 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7072 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7074 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7076 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7078 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7082 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsManaged */

/* 7086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7092 */	NdrFcShort( 0x28 ),	/* 40 */
/* 7094 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7096 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7100 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7102 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7114 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7116 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7118 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7120 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7122 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7124 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7126 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMbit */

/* 7130 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7136 */	NdrFcShort( 0x29 ),	/* 41 */
/* 7138 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7144 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7146 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7158 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMigrateOK */

/* 7162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7168 */	NdrFcShort( 0x2a ),	/* 42 */
/* 7170 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7176 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7178 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7186 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPostIt */

/* 7188 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7190 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7192 */	NdrFcShort( 0x192 ),	/* Type Offset=402 */

	/* Return value */

/* 7194 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7196 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsOffline */

/* 7200 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7206 */	NdrFcShort( 0x2b ),	/* 43 */
/* 7208 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7214 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7216 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7224 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7226 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7228 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsOwnerMemberOf */

/* 7232 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7238 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7240 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7244 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7246 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7248 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter group */

/* 7258 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7260 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7262 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 7264 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7266 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsPremigrated */

/* 7270 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7272 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7276 */	NdrFcShort( 0x2d ),	/* 45 */
/* 7278 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7280 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7284 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7286 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7294 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7296 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7298 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7300 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7304 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7306 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7310 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsReadOnly */

/* 7314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7320 */	NdrFcShort( 0x2e ),	/* 46 */
/* 7322 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7328 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7330 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7338 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7340 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7342 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsRecallOK */

/* 7346 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7348 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7352 */	NdrFcShort( 0x2f ),	/* 47 */
/* 7354 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7358 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7360 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7362 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPostIt */

/* 7372 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7374 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7376 */	NdrFcShort( 0x192 ),	/* Type Offset=402 */

	/* Return value */

/* 7378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7380 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsSparse */

/* 7384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7390 */	NdrFcShort( 0x30 ),	/* 48 */
/* 7392 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7396 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7398 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7400 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7412 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsSystem */

/* 7416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7422 */	NdrFcShort( 0x31 ),	/* 49 */
/* 7424 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7430 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7432 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7444 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsTotallySparse */

/* 7448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7454 */	NdrFcShort( 0x32 ),	/* 50 */
/* 7456 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7460 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7462 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7464 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7476 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsTruncated */

/* 7480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7486 */	NdrFcShort( 0x33 ),	/* 51 */
/* 7488 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7490 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7494 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7496 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7506 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7508 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7510 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7512 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7514 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7516 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7520 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Manage */

/* 7524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7530 */	NdrFcShort( 0x34 ),	/* 52 */
/* 7532 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 7534 */	NdrFcShort( 0x58 ),	/* 88 */
/* 7536 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7538 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 7540 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7548 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7550 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7552 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7554 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7556 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7558 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7560 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter storagePoolId */

/* 7562 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 7564 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7566 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter truncate */

/* 7568 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7570 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 7572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7574 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7576 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 7578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Move */

/* 7580 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7582 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7586 */	NdrFcShort( 0x35 ),	/* 53 */
/* 7588 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 7590 */	NdrFcShort( 0x18 ),	/* 24 */
/* 7592 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7594 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 7596 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dest */

/* 7606 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7608 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7610 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter retainHierarcy */

/* 7612 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7614 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter expandPlaceholders */

/* 7618 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7620 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter overwriteExisting */

/* 7624 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7626 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7630 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7632 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 7634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Recall */

/* 7636 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7638 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7642 */	NdrFcShort( 0x36 ),	/* 54 */
/* 7644 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 7646 */	NdrFcShort( 0x28 ),	/* 40 */
/* 7648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7650 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 7652 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7660 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7662 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7664 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7666 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7668 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7670 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7672 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter deletePlaceholder */

/* 7674 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7676 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7682 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Recycle */

/* 7686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7692 */	NdrFcShort( 0x37 ),	/* 55 */
/* 7694 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7700 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7702 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7712 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7714 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Truncate */

/* 7718 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7720 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7724 */	NdrFcShort( 0x38 ),	/* 56 */
/* 7726 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7728 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7732 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7734 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7744 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7746 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7748 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7750 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7752 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7754 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7758 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Unmanage */

/* 7762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7768 */	NdrFcShort( 0x39 ),	/* 57 */
/* 7770 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7772 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7776 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7778 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7786 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7788 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7790 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7792 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7794 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7796 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7798 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7802 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Validate */

/* 7806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7812 */	NdrFcShort( 0x3a ),	/* 58 */
/* 7814 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7816 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7820 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7822 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7832 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7834 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7836 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7838 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7840 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7842 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7844 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7846 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7848 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PrepareForManage */

/* 7850 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7852 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7856 */	NdrFcShort( 0x3b ),	/* 59 */
/* 7858 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7860 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7864 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7866 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7878 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7880 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7882 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7884 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7886 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7888 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7890 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Verify */

/* 7894 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7896 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7900 */	NdrFcShort( 0x3c ),	/* 60 */
/* 7902 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7904 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7908 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7910 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7918 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7922 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7924 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7926 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7928 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7930 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7934 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TruncateValidated */

/* 7938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7944 */	NdrFcShort( 0x3d ),	/* 61 */
/* 7946 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7948 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7952 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7954 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7962 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 7964 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7966 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7968 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 7970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7972 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7974 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7978 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumResources */

/* 7982 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7988 */	NdrFcShort( 0x4 ),	/* 4 */
/* 7990 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7996 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7998 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 8008 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8010 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8012 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 8014 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8016 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceByAlternatePath */

/* 8020 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8026 */	NdrFcShort( 0x5 ),	/* 5 */
/* 8028 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8032 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8034 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8036 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8044 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 8046 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 8048 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8050 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter ppResource */

/* 8052 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8054 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8056 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 8058 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8060 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceById */

/* 8064 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8070 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8072 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 8074 */	NdrFcShort( 0x30 ),	/* 48 */
/* 8076 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8078 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 8080 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8088 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 8090 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 8092 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8094 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter ppResource */

/* 8096 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8098 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8100 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 8102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8104 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceByName */

/* 8108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8114 */	NdrFcShort( 0x7 ),	/* 7 */
/* 8116 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8122 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8124 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 8134 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 8136 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8138 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter ppResource */

/* 8140 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8142 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8144 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 8146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8148 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceByPath */

/* 8152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8160 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8166 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8168 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 8178 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 8180 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8182 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter ppResource */

/* 8184 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8186 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8188 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 8190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8192 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceBySerial */

/* 8196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8202 */	NdrFcShort( 0x9 ),	/* 9 */
/* 8204 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8210 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 8212 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serial */

/* 8222 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8224 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppResource */

/* 8228 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8230 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8232 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 8234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8236 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindResourceByStickyName */

/* 8240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8246 */	NdrFcShort( 0xa ),	/* 10 */
/* 8248 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8254 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8256 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 8266 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 8268 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8270 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Parameter ppResource */

/* 8272 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8274 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8276 */	NdrFcShort( 0x1a4 ),	/* Type Offset=420 */

	/* Return value */

/* 8278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8280 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDbPathAndName */

/* 8284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8290 */	NdrFcShort( 0xd ),	/* 13 */
/* 8292 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8298 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8300 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 8310 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 8312 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8314 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 8316 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8318 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8324 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIDbSys */

/* 8328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8334 */	NdrFcShort( 0xe ),	/* 14 */
/* 8336 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8342 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8344 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppDbSys */

/* 8354 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8356 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8358 */	NdrFcShort( 0x1ba ),	/* Type Offset=442 */

	/* Return value */

/* 8360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8362 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUnmanageIDbSys */

/* 8366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8372 */	NdrFcShort( 0xf ),	/* 15 */
/* 8374 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8380 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8382 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8390 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppDbSys */

/* 8392 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8394 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8396 */	NdrFcShort( 0x1ba ),	/* Type Offset=442 */

	/* Return value */

/* 8398 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8400 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFilter */

/* 8404 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8410 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8412 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8418 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8420 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8428 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFilter */

/* 8430 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8432 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8434 */	NdrFcShort( 0x1d0 ),	/* Type Offset=464 */

	/* Return value */

/* 8436 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8438 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUnmanageIDbPath */

/* 8442 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8444 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8448 */	NdrFcShort( 0x12 ),	/* 18 */
/* 8450 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8452 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8456 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8458 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 8468 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 8470 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8472 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 8474 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8476 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8482 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 8486 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8492 */	NdrFcShort( 0x13 ),	/* 19 */
/* 8494 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8498 */	NdrFcShort( 0x4c ),	/* 76 */
/* 8500 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8502 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8510 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 8512 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 8514 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8516 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 8518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8520 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 8524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8530 */	NdrFcShort( 0x16 ),	/* 22 */
/* 8532 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8536 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8538 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 8540 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8548 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 8550 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8552 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAutosave */

/* 8556 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8562 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8564 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8568 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8570 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8572 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8580 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter milliseconds */

/* 8582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8584 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8590 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 8594 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8600 */	NdrFcShort( 0x4 ),	/* 4 */
/* 8602 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8608 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8610 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 8620 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8622 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8624 */	NdrFcShort( 0x1e6 ),	/* Type Offset=486 */

	/* Return value */

/* 8626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8628 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetKeepRecallTime */

/* 8632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8638 */	NdrFcShort( 0x5 ),	/* 5 */
/* 8640 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8644 */	NdrFcShort( 0x34 ),	/* 52 */
/* 8646 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8648 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8656 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 8658 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 8660 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8662 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 8664 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8666 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxFilesPerRun */

/* 8670 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8672 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8676 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8678 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8682 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8684 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8686 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8694 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMaxFiles */

/* 8696 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8698 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8700 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8702 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8704 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPremigratedSortOrder */

/* 8708 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8710 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8714 */	NdrFcShort( 0x7 ),	/* 7 */
/* 8716 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8720 */	NdrFcShort( 0x22 ),	/* 34 */
/* 8722 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8724 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8732 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSortOrder */

/* 8734 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 8736 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8738 */	NdrFcShort( 0x1fc ),	/* Type Offset=508 */

	/* Return value */

/* 8740 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8742 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRunInterval */

/* 8746 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8754 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8758 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8760 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8762 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8770 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMilliseconds */

/* 8772 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8774 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8778 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8780 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxFilesPerRun */

/* 8784 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8786 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8790 */	NdrFcShort( 0x9 ),	/* 9 */
/* 8792 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8794 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8796 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8798 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8800 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8808 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter maxFiles */

/* 8810 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8812 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8814 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8816 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8818 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPremigratedSortOrder */

/* 8822 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8828 */	NdrFcShort( 0xa ),	/* 10 */
/* 8830 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8832 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8834 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8836 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8838 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8846 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter SortOrder */

/* 8848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8850 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8852 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 8854 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8856 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRunInterval */

/* 8860 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8866 */	NdrFcShort( 0xb ),	/* 11 */
/* 8868 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8870 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8874 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8876 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8884 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter milliseconds */

/* 8886 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8888 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8892 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8894 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8896 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetKeepRecallTime */

/* 8898 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8900 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8904 */	NdrFcShort( 0xc ),	/* 12 */
/* 8906 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8908 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8910 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8912 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8914 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter time */

/* 8924 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 8926 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8928 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 8930 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8932 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Start */

/* 8936 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8938 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8942 */	NdrFcShort( 0xd ),	/* 13 */
/* 8944 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8948 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8950 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 8952 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 8962 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 8964 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8966 */	NdrFcShort( 0x1a8 ),	/* Type Offset=424 */

	/* Return value */

/* 8968 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8970 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileVersionId */

/* 8974 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8976 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8980 */	NdrFcShort( 0x3 ),	/* 3 */
/* 8982 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8986 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8988 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8990 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8998 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileVersionId */

/* 9000 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9002 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9004 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9006 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9008 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFilterRecall */

/* 9012 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9018 */	NdrFcShort( 0x4 ),	/* 4 */
/* 9020 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9026 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 9028 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9036 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppRecall */

/* 9038 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9040 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9042 */	NdrFcShort( 0x200 ),	/* Type Offset=512 */

	/* Return value */

/* 9044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9046 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMode */

/* 9050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9056 */	NdrFcShort( 0x5 ),	/* 5 */
/* 9058 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9062 */	NdrFcShort( 0x24 ),	/* 36 */
/* 9064 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9066 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9074 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMode */

/* 9076 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9078 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9082 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9084 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 9088 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9090 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9094 */	NdrFcShort( 0x6 ),	/* 6 */
/* 9096 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9100 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9102 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 9104 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 9114 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 9116 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9118 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bufferSize */

/* 9120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9122 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9128 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPlaceholder */

/* 9132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9138 */	NdrFcShort( 0x7 ),	/* 7 */
/* 9140 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9144 */	NdrFcShort( 0x124 ),	/* 292 */
/* 9146 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9148 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPlaceholder */

/* 9158 */	NdrFcShort( 0x112 ),	/* Flags:  must free, out, simple ref, */
/* 9160 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9162 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 9164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9166 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRequestAction */

/* 9170 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9176 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9178 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9182 */	NdrFcShort( 0x24 ),	/* 36 */
/* 9184 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9186 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRequestAction */

/* 9196 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9198 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9200 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 9202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9204 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRequestOffset */

/* 9208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9214 */	NdrFcShort( 0x9 ),	/* 9 */
/* 9216 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9220 */	NdrFcShort( 0x2c ),	/* 44 */
/* 9222 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9224 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRequestOffset */

/* 9234 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9236 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9238 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9242 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResultAction */

/* 9246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9252 */	NdrFcShort( 0xc ),	/* 12 */
/* 9254 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9258 */	NdrFcShort( 0x24 ),	/* 36 */
/* 9260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9262 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResultAction */

/* 9272 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9274 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9276 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 9278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9280 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 9284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9290 */	NdrFcShort( 0xd ),	/* 13 */
/* 9292 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9298 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 9300 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 9310 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9312 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9314 */	NdrFcShort( 0x1e6 ),	/* Type Offset=486 */

	/* Return value */

/* 9316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9318 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStoragePoolId */

/* 9322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9328 */	NdrFcShort( 0xe ),	/* 14 */
/* 9330 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9334 */	NdrFcShort( 0x4c ),	/* 76 */
/* 9336 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9338 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStoragePoolId */

/* 9348 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 9350 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9352 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 9354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9356 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetThreadId */

/* 9360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9366 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9368 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9372 */	NdrFcShort( 0x24 ),	/* 36 */
/* 9374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9376 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pThreadId */

/* 9386 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9388 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9394 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileVersionId */

/* 9398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9404 */	NdrFcShort( 0x11 ),	/* 17 */
/* 9406 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9408 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9412 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9414 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileVersionId */

/* 9424 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9426 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9428 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9432 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFilterRecall */

/* 9436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9442 */	NdrFcShort( 0x12 ),	/* 18 */
/* 9444 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9448 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9450 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9452 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 9462 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9464 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9466 */	NdrFcShort( 0x204 ),	/* Type Offset=516 */

	/* Return value */

/* 9468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9470 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPlaceholder */

/* 9474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9480 */	NdrFcShort( 0x15 ),	/* 21 */
/* 9482 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9484 */	NdrFcShort( 0x11c ),	/* 284 */
/* 9486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9488 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9490 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPlaceholder */

/* 9500 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9502 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9504 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 9506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9508 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRequestAction */

/* 9512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9518 */	NdrFcShort( 0x16 ),	/* 22 */
/* 9520 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9522 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9526 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9528 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9536 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter requestAction */

/* 9538 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9540 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9542 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 9544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9546 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRequestOffset */

/* 9550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9556 */	NdrFcShort( 0x17 ),	/* 23 */
/* 9558 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9560 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9564 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9566 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter requestOffset */

/* 9576 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9578 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9580 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9584 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRequestSize */

/* 9588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9594 */	NdrFcShort( 0x18 ),	/* 24 */
/* 9596 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9598 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9602 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9604 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter requestSize */

/* 9614 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9616 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9618 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9620 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9622 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResult */

/* 9626 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9632 */	NdrFcShort( 0x19 ),	/* 25 */
/* 9634 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9640 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9642 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hr */

/* 9652 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9654 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9660 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResultAction */

/* 9664 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9670 */	NdrFcShort( 0x1a ),	/* 26 */
/* 9672 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9676 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9678 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9680 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9688 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResultAction */

/* 9690 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9692 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9694 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 9696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9698 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSession */

/* 9702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9708 */	NdrFcShort( 0x1b ),	/* 27 */
/* 9710 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9716 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9718 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 9728 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9730 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9732 */	NdrFcShort( 0x1ea ),	/* Type Offset=490 */

	/* Return value */

/* 9734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9736 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStoragePoolId */

/* 9740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9746 */	NdrFcShort( 0x1c ),	/* 28 */
/* 9748 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9750 */	NdrFcShort( 0x30 ),	/* 48 */
/* 9752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9754 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9756 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9764 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter storagePoolId */

/* 9766 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 9768 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9770 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 9772 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9774 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUSN */

/* 9778 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9784 */	NdrFcShort( 0x1d ),	/* 29 */
/* 9786 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9788 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9792 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9794 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter usn */

/* 9804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9806 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9808 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9812 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetThreadId */

/* 9816 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9822 */	NdrFcShort( 0x1e ),	/* 30 */
/* 9824 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9830 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9832 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter threadId */

/* 9842 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9844 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9850 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IdentifyWithServer */

/* 9854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9860 */	NdrFcShort( 0x3 ),	/* 3 */
/* 9862 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9868 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9870 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9878 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szServerName */

/* 9880 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 9882 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9884 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 9886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9888 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnRecallStarted */

/* 9892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9898 */	NdrFcShort( 0x4 ),	/* 4 */
/* 9900 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9904 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9906 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9908 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9916 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 9918 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9920 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9922 */	NdrFcShort( 0x216 ),	/* Type Offset=534 */

	/* Return value */

/* 9924 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9926 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnRecallFinished */

/* 9930 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9936 */	NdrFcShort( 0x5 ),	/* 5 */
/* 9938 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9942 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9944 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 9946 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 9956 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9958 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9960 */	NdrFcShort( 0x216 ),	/* Type Offset=534 */

	/* Parameter hr */

/* 9962 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9964 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9968 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9970 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 9974 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9976 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9980 */	NdrFcShort( 0x3 ),	/* 3 */
/* 9982 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9986 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9988 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9990 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9998 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 10000 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 10002 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 10004 */	NdrFcShort( 0x204 ),	/* Type Offset=516 */

	/* Return value */

/* 10006 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10008 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 10010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cancel */

/* 10012 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10018 */	NdrFcShort( 0x4 ),	/* 4 */
/* 10020 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 10022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10026 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 10028 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10036 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 10038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10040 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 10042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 10044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10050 */	NdrFcShort( 0x5 ),	/* 5 */
/* 10052 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 10054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10056 */	NdrFcShort( 0x4c ),	/* 76 */
/* 10058 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10060 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 10070 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 10072 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 10074 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 10076 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10078 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 10080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMode */

/* 10082 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10084 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10088 */	NdrFcShort( 0x6 ),	/* 6 */
/* 10090 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 10092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10094 */	NdrFcShort( 0x24 ),	/* 36 */
/* 10096 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10098 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMode */

/* 10108 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10110 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 10112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 10114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10116 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 10118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOffset */

/* 10120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10126 */	NdrFcShort( 0x7 ),	/* 7 */
/* 10128 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 10130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10132 */	NdrFcShort( 0x2c ),	/* 44 */
/* 10134 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10136 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 10146 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10148 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 10150 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 10152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10154 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 10156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 10158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10164 */	NdrFcShort( 0xb ),	/* 11 */
/* 10166 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 10168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10170 */	NdrFcShort( 0x24 ),	/* 36 */
/* 10172 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 10174 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 10184 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 10186 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 10188 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 10190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10192 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 10194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendNotification */

/* 10196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 10198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 10202 */	NdrFcShort( 0x3 ),	/* 3 */
/* 10204 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 10206 */	NdrFcShort( 0x10 ),	/* 16 */
/* 10208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10210 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 10212 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 10214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter machineName */

/* 10222 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 10224 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 10226 */	NdrFcShort( 0x228 ),	/* Type Offset=552 */

	/* Parameter started */

/* 10228 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 10230 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 10232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rHr */

/* 10234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 10236 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 10238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 10240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 10242 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 10244 */	0x8,		/* FC_LONG */
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
/*  4 */	NdrFcLong( 0x5e176f27 ),	/* 1578594087 */
/*  8 */	NdrFcShort( 0x6f53 ),	/* 28499 */
/* 10 */	NdrFcShort( 0x4c84 ),	/* 19588 */
/* 12 */	0xb9,		/* 185 */
			0x35,		/* 53 */
/* 14 */	0x92,		/* 146 */
			0x59,		/* 89 */
/* 16 */	0x29,		/* 41 */
			0x76,		/* 118 */
/* 18 */	0x69,		/* 105 */
			0xb0,		/* 176 */
/* 20 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 22 */	NdrFcShort( 0x8 ),	/* 8 */
/* 24 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 26 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 28 */	NdrFcShort( 0x10 ),	/* 16 */
/* 30 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 32 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 34 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (20) */
			0x5b,		/* FC_END */
/* 38 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 40 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 42 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 44 */	NdrFcLong( 0x5fff1640 ),	/* 1610552896 */
/* 48 */	NdrFcShort( 0xd487 ),	/* -11129 */
/* 50 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 52 */	0xa9,		/* 169 */
			0xf5,		/* 245 */
/* 54 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 56 */	0x24,		/* 36 */
			0x89,		/* 137 */
/* 58 */	0x3,		/* 3 */
			0xea,		/* 234 */
/* 60 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 62 */	NdrFcShort( 0x2 ),	/* Offset= 2 (64) */
/* 64 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 66 */	NdrFcLong( 0x9c7d6f14 ),	/* -1669501164 */
/* 70 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 72 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 74 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 76 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 78 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 80 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 82 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 84 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (26) */
/* 86 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 88 */	NdrFcShort( 0x2 ),	/* Offset= 2 (90) */
/* 90 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 92 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 94 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 96 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 98 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 100 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 102 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 104 */	NdrFcShort( 0xff9a ),	/* Offset= -102 (2) */
/* 106 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 108 */	NdrFcLong( 0x560e5a02 ),	/* 1443781122 */
/* 112 */	NdrFcShort( 0xdede ),	/* -8482 */
/* 114 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 116 */	0xa9,		/* 169 */
			0xf5,		/* 245 */
/* 118 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 120 */	0x24,		/* 36 */
			0x89,		/* 137 */
/* 122 */	0x3,		/* 3 */
			0xea,		/* 234 */
/* 124 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 126 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 128 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 130 */	NdrFcShort( 0x2 ),	/* Offset= 2 (132) */
/* 132 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 136 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 138 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 140 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 142 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 144 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 146 */	0x3,		/* FC_SMALL */
			0x5c,		/* FC_PAD */
/* 148 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 150 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 152 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 154 */	NdrFcShort( 0x2 ),	/* Offset= 2 (156) */
/* 156 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 158 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 162 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 164 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 166 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 168 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 170 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 172 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 174 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 176 */	NdrFcShort( 0x2 ),	/* Offset= 2 (178) */
/* 178 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 180 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 184 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 186 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 188 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 190 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 192 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 194 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 196 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 198 */	NdrFcShort( 0x2 ),	/* Offset= 2 (200) */
/* 200 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 202 */	NdrFcLong( 0xc ),	/* 12 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 210 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 212 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 214 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 216 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 218 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 220 */	NdrFcLong( 0x87e7ed0 ),	/* 142507728 */
/* 224 */	NdrFcShort( 0x727a ),	/* 29306 */
/* 226 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 228 */	0x9c,		/* 156 */
			0xd3,		/* 211 */
/* 230 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 232 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 234 */	0x81,		/* 129 */
			0x2,		/* 2 */
/* 236 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 238 */	NdrFcShort( 0xffec ),	/* Offset= -20 (218) */
/* 240 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 242 */	NdrFcShort( 0x2 ),	/* Offset= 2 (244) */
/* 244 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 246 */	NdrFcLong( 0x9c7d6f0f ),	/* -1669501169 */
/* 250 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 252 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 254 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 256 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 258 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 260 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 262 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 264 */	NdrFcShort( 0x2 ),	/* Offset= 2 (266) */
/* 266 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 268 */	NdrFcLong( 0x14f73fcb ),	/* 351748043 */
/* 272 */	NdrFcShort( 0x517d ),	/* 20861 */
/* 274 */	NdrFcShort( 0x4503 ),	/* 17667 */
/* 276 */	0xb1,		/* 177 */
			0x5d,		/* 93 */
/* 278 */	0x2d,		/* 45 */
			0x40,		/* 64 */
/* 280 */	0xb3,		/* 179 */
			0xe9,		/* 233 */
/* 282 */	0xcd,		/* 205 */
			0x21,		/* 33 */
/* 284 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 286 */	NdrFcShort( 0x2 ),	/* Offset= 2 (288) */
/* 288 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 290 */	NdrFcLong( 0x9cabc042 ),	/* -1666465726 */
/* 294 */	NdrFcShort( 0x8aa4 ),	/* -30044 */
/* 296 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 298 */	0x81,		/* 129 */
			0xe6,		/* 230 */
/* 300 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 302 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 304 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 306 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 308 */	NdrFcLong( 0xb5a1ed6a ),	/* -1247679126 */
/* 312 */	NdrFcShort( 0xced4 ),	/* -12588 */
/* 314 */	NdrFcShort( 0x4d16 ),	/* 19734 */
/* 316 */	0x9a,		/* 154 */
			0x76,		/* 118 */
/* 318 */	0x8c,		/* 140 */
			0xd4,		/* 212 */
/* 320 */	0x47,		/* 71 */
			0x3a,		/* 58 */
/* 322 */	0x2c,		/* 44 */
			0xe9,		/* 233 */
/* 324 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 326 */	NdrFcLong( 0x2a87c7e2 ),	/* 713541602 */
/* 330 */	NdrFcShort( 0xdb24 ),	/* -9436 */
/* 332 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 334 */	0xaf,		/* 175 */
			0xa2,		/* 162 */
/* 336 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 338 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 340 */	0x37,		/* 55 */
			0x58,		/* 88 */
/* 342 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 344 */	NdrFcShort( 0x10 ),	/* 16 */
/* 346 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 348 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 350 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 352 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 354 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 356 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 358 */	NdrFcShort( 0x98 ),	/* 152 */
/* 360 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 362 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 364 */	0x0,		/* 0 */
			NdrFcShort( 0xff17 ),	/* Offset= -233 (132) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 368 */	0x0,		/* 0 */
			NdrFcShort( 0xfea9 ),	/* Offset= -343 (26) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 372 */	0x0,		/* 0 */
			NdrFcShort( 0xfea5 ),	/* Offset= -347 (26) */
			0x40,		/* FC_STRUCTPAD4 */
/* 376 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 378 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 380 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 382 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 384 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 386 */	NdrFcShort( 0xff02 ),	/* Offset= -254 (132) */
/* 388 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 390 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 392 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 394 */	
			0x11, 0x0,	/* FC_RP */
/* 396 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (356) */
/* 398 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 400 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 402 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 404 */	NdrFcLong( 0xb5a1ed6a ),	/* -1247679126 */
/* 408 */	NdrFcShort( 0xced4 ),	/* -12588 */
/* 410 */	NdrFcShort( 0x4d16 ),	/* 19734 */
/* 412 */	0x9a,		/* 154 */
			0x76,		/* 118 */
/* 414 */	0x8c,		/* 140 */
			0xd4,		/* 212 */
/* 416 */	0x47,		/* 71 */
			0x3a,		/* 58 */
/* 418 */	0x2c,		/* 44 */
			0xe9,		/* 233 */
/* 420 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 422 */	NdrFcShort( 0x2 ),	/* Offset= 2 (424) */
/* 424 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 426 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 430 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 432 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 434 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 436 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 438 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 440 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 442 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 444 */	NdrFcShort( 0x2 ),	/* Offset= 2 (446) */
/* 446 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 448 */	NdrFcLong( 0xf2608980 ),	/* -228554368 */
/* 452 */	NdrFcShort( 0xa45 ),	/* 2629 */
/* 454 */	NdrFcShort( 0x47b4 ),	/* 18356 */
/* 456 */	0xb1,		/* 177 */
			0x10,		/* 16 */
/* 458 */	0x37,		/* 55 */
			0xea,		/* 234 */
/* 460 */	0x59,		/* 89 */
			0xf6,		/* 246 */
/* 462 */	0x7c,		/* 124 */
			0x47,		/* 71 */
/* 464 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 466 */	NdrFcShort( 0x2 ),	/* Offset= 2 (468) */
/* 468 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 470 */	NdrFcLong( 0x5fff1640 ),	/* 1610552896 */
/* 474 */	NdrFcShort( 0xd487 ),	/* -11129 */
/* 476 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 478 */	0xa9,		/* 169 */
			0xf5,		/* 245 */
/* 480 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 482 */	0x24,		/* 36 */
			0x89,		/* 137 */
/* 484 */	0x3,		/* 3 */
			0xea,		/* 234 */
/* 486 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 488 */	NdrFcShort( 0x2 ),	/* Offset= 2 (490) */
/* 490 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 492 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 496 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 498 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 500 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 502 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 504 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 506 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 508 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 510 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 512 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 514 */	NdrFcShort( 0x2 ),	/* Offset= 2 (516) */
/* 516 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 518 */	NdrFcLong( 0x5e176f27 ),	/* 1578594087 */
/* 522 */	NdrFcShort( 0x6f53 ),	/* 28499 */
/* 524 */	NdrFcShort( 0x4c84 ),	/* 19588 */
/* 526 */	0xb9,		/* 185 */
			0x35,		/* 53 */
/* 528 */	0x92,		/* 146 */
			0x59,		/* 89 */
/* 530 */	0x29,		/* 41 */
			0x76,		/* 118 */
/* 532 */	0x69,		/* 105 */
			0xb0,		/* 176 */
/* 534 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 536 */	NdrFcLong( 0xd68bd5b2 ),	/* -695478862 */
/* 540 */	NdrFcShort( 0xd6aa ),	/* -10582 */
/* 542 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 544 */	0x9e,		/* 158 */
			0xda,		/* 218 */
/* 546 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 548 */	0x24,		/* 36 */
			0x88,		/* 136 */
/* 550 */	0xfc,		/* 252 */
			0xde,		/* 222 */
/* 552 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 554 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_fsaint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IFsaFilter, ver. 0.0,
   GUID={0x5FFF1640,0xD487,0x11d1,{0xA9,0xF5,0x00,0xA0,0x24,0x89,0x03,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaFilter_FormatStringOffsetTable[] =
    {
    0,
    32,
    70,
    114,
    158,
    196,
    234,
    272,
    316,
    354,
    392,
    430,
    468,
    500,
    532,
    564,
    602,
    640,
    678,
    716,
    754,
    786,
    818,
    862
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaFilter_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaFilter_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaFilter_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaFilter_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IFsaFilterProxyVtbl = 
{
    &IFsaFilter_ProxyInfo,
    &IID_IFsaFilter,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaFilter::Cancel */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::CancelRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::CompareToIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::CompareToIFilter */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::DeleteRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::EnumRecalls */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetLogicalName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetMaxRecallBuffers */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetMaxRecalls */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetMinRecallInterval */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetState */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::IsEnabled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::Pause */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::Resume */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::GetAdminExemption */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::SetIsEnabled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::SetMaxRecalls */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::SetMinRecallInterval */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::SetMaxRecallBuffers */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::Start */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::StopIoctlThread */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::FindRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilter::SetAdminExemption */
};

const CInterfaceStubVtbl _IFsaFilterStubVtbl =
{
    &IID_IFsaFilter,
    &IFsaFilter_ServerInfo,
    27,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaFilterClient, ver. 0.0,
   GUID={0x560E5A02,0xDEDE,0x11d1,{0xA9,0xF5,0x00,0xA0,0x24,0x89,0x03,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaFilterClient_FormatStringOffsetTable[] =
    {
    900,
    938,
    988,
    1032,
    1076,
    1120,
    1164,
    272,
    316,
    1202,
    1246,
    1278,
    1310,
    1354,
    1392,
    1430,
    1468,
    1506,
    678,
    1544,
    754,
    1582,
    1620,
    1670,
    1702,
    1740,
    1778
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaFilterClient_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterClient_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaFilterClient_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterClient_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(30) _IFsaFilterClientProxyVtbl = 
{
    &IFsaFilterClient_ProxyInfo,
    &IID_IFsaFilterClient,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::CompareBy */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::CompareToAuthenticationId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::CompareToIClient */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::CompareToMachineName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetAuthenticationId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetDomainName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetLastRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetMachineName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetRecallCount */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::HasRecallDisabled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::HitRecallLimit */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetAuthenticationId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetDomainName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetHasRecallDisabled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetHitRecallLimit */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetLastRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetMachineName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetRecallCount */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::StartIdentify */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetTokenSource */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SendRecallInfo */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::IdentifyThread */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::SetIsAdmin */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::GetIsAdmin */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterClient::CheckRecallLimit */
};

const CInterfaceStubVtbl _IFsaFilterClientStubVtbl =
{
    &IID_IFsaFilterClient,
    &IFsaFilterClient_ServerInfo,
    30,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaFilterRecall, ver. 0.0,
   GUID={0x5E176F27,0x6F53,0x4C84,{0xB9,0x35,0x92,0x59,0x29,0x76,0x69,0xB0}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaFilterRecall_FormatStringOffsetTable[] =
    {
    1828,
    1872,
    1916,
    1960,
    2004,
    2042,
    2080,
    2118,
    2156,
    2200,
    392,
    2238,
    2276,
    2314,
    2352,
    1430,
    2396,
    2428,
    2466,
    2516
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaFilterRecall_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterRecall_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaFilterRecall_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterRecall_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(23) _IFsaFilterRecallProxyVtbl = 
{
    &IFsaFilterRecall_ProxyInfo,
    &IID_IFsaFilterRecall,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CompareToIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CompareToIRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CompareToDriversRecallId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CompareToDriversContextId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CompareBy */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetMode */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetResource */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetRecallFlags */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetState */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::GetUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::HasCompleted */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::WasCancelled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CreateLocalStream */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::CheckRecallLimit */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecall::AddClient */
};

const CInterfaceStubVtbl _IFsaFilterRecallStubVtbl =
{
    &IID_IFsaFilterRecall,
    &IFsaFilterRecall_ServerInfo,
    23,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaResource, ver. 0.0,
   GUID={0x172F71CD,0xA452,0x4005,{0x8E,0x3E,0x7B,0xCE,0xAE,0x12,0x4D,0x53}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaResource_FormatStringOffsetTable[] =
    {
    2554,
    2616,
    2666,
    2728,
    2760,
    2798,
    2836,
    2880,
    2924,
    2968,
    3012,
    3056,
    3100,
    3144,
    532,
    3188,
    3226,
    3264,
    3302,
    3352,
    3396,
    3440,
    3478,
    3516,
    3554,
    3604,
    3660,
    3704,
    3742,
    3786,
    3830,
    3868,
    3912,
    3950,
    3988,
    4026,
    4070,
    4108,
    4152,
    4190,
    4234,
    4278,
    4322,
    4360,
    4416,
    4454,
    4498,
    4542,
    4586,
    4618,
    4650,
    4682,
    4714,
    4776,
    4826,
    4858,
    4896,
    4952,
    5002,
    5052,
    5090,
    5128,
    5166,
    5204,
    5242,
    5286,
    5324,
    5368,
    5418,
    5474,
    5512,
    5550
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaResource_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaResource_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaResource_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaResource_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(75) _IFsaResourceProxyVtbl = 
{
    &IFsaResource_ProxyInfo,
    &IID_IFsaResource,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaResource::AddPremigrated */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::AddTruncated */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::BeginSession */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::BeginValidate */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CheckForValidate */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareBy */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToAlternatePath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToIResource */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToSerial */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CompareToStickyName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::CreateDefaultRules */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::EndSession */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::EndValidate */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::EnumDefaultRules */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindFirst */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindFirstInRPIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindFirstInDbIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindNext */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindNextInRPIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindNextInDbIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::FindObjectId */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetAlternatePath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetDefaultRules */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetDbPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetUnmanageDbPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetFreeLevel */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetFsName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetHsmEngine */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetHsmLevel */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetLogicalName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetManageableItemLogicalSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetManageableItemAccessTime */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetManagingHsm */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetOldPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetSerial */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetSizes */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetTruncator */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetUncPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetUserFriendlyName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetStickyName */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::IsActive */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::IsAvailable */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::IsDeletePending */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::IsManaged */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::Manage */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::ManagedBy */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::NeedsRepair */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::ProcessResult */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::Recall */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::RemovePremigrated */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::RemoveTruncated */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetHsmLevel */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetIsActive */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetIsAvailable */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetIsDeletePending */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetManageableItemLogicalSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetManageableItemAccessTime */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetSerial */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::StartJob */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::StartJobSession */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::Validate */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::SetupValidateJob */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::GetUsnId */ ,
    (void *) (INT_PTR) -1 /* IFsaResource::ValidateForTruncate */
};

const CInterfaceStubVtbl _IFsaResourceStubVtbl =
{
    &IID_IFsaResource,
    &IFsaResource_ServerInfo,
    75,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaScanItem, ver. 0.0,
   GUID={0x087e7ed0,0x727a,0x11d2,{0x9c,0xd3,0x00,0xa0,0xc9,0x11,0x81,0x02}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaScanItem_FormatStringOffsetTable[] =
    {
    5606,
    5650,
    5694,
    5744,
    5800,
    5838,
    5906,
    5938,
    5982,
    6032,
    6082,
    6120,
    2276,
    6158,
    2352,
    6214,
    6252,
    6290,
    6334,
    6378,
    6428,
    6472,
    6522,
    6560,
    6610,
    6648,
    6704,
    6742,
    6774,
    6806,
    6838,
    6870,
    6902,
    6940,
    6972,
    7010,
    7042,
    7086,
    7130,
    7162,
    7200,
    7232,
    7270,
    7314,
    7346,
    7384,
    7416,
    7448,
    7480,
    7524,
    7580,
    7636,
    7686,
    7718,
    7762,
    7806,
    7850,
    7894,
    7938
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaScanItem_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaScanItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaScanItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaScanItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(62) _IFsaScanItemProxyVtbl = 
{
    &IFsaScanItem_ProxyInfo,
    &IID_IFsaScanItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::CheckIfSparse */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::CompareToIScanItem */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::CompareToPathAndName */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Copy */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::CreateLocalStream */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::CreatePlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Delete */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::DeletePlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::FindFirstPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::FindNextPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetAccessTime */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetFileUsn */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetFullPathAndName */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetGroup */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetLogicalSize */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetModifyTime */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetName */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetOwner */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetPathForFind */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetPathAndName */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetPhysicalSize */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetUncPathAndName */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::GetVersionId */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::HasExtendedAttributes */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsALink */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsAParent */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsARelativeParent */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsCompressed */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsDeleteOK */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsEncrypted */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsGroupMemberOf */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsHidden */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsManageable */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsManaged */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsMbit */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsMigrateOK */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsOffline */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsOwnerMemberOf */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsPremigrated */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsReadOnly */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsRecallOK */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsSparse */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsSystem */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsTotallySparse */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::IsTruncated */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Manage */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Move */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Recall */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Recycle */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Truncate */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Unmanage */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Validate */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::PrepareForManage */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::Verify */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItem::TruncateValidated */
};

const CInterfaceStubVtbl _IFsaScanItemStubVtbl =
{
    &IID_IFsaScanItem,
    &IFsaScanItem_ServerInfo,
    62,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSystemState, ver. 0.0,
   GUID={0x3F0DA041,0x69F1,0x11d2,{0xAF,0x82,0x00,0x10,0x4B,0x9A,0x37,0x58}} */


/* Object interface: IFsaServer, ver. 0.0,
   GUID={0xC49D553D,0xCA2B,0x4482,{0xA4,0x04,0xCD,0x4B,0x6B,0x44,0xEA,0xE4}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaServer_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    7982,
    8020,
    8064,
    8108,
    8152,
    8196,
    8240,
    316,
    1202,
    8284,
    8328,
    8366,
    8404,
    2352,
    8442,
    8486,
    6290,
    6334,
    8524,
    754,
    8556
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(25) _IFsaServerProxyVtbl = 
{
    &IFsaServer_ProxyInfo,
    &IID_IFsaServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::EnumResources */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceByAlternatePath */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceById */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceByName */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceByPath */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceBySerial */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::FindResourceByStickyName */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetAutosave */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetDbPath */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetDbPathAndName */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetIDbSys */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetUnmanageIDbSys */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetFilter */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetIDbPath */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetUnmanageIDbPath */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetLogicalName */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::GetName */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::Init */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::ScanForResources */ ,
    (void *) (INT_PTR) -1 /* IFsaServer::SetAutosave */
};


static const PRPC_STUB_FUNCTION IFsaServer_table[] =
{
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaServerStubVtbl =
{
    &IID_IFsaServer,
    &IFsaServer_ServerInfo,
    25,
    &IFsaServer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaTruncator, ver. 0.0,
   GUID={0x9CABC042,0x8AA4,0x11d0,{0x81,0xE6,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaTruncator_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    8594,
    8632,
    8670,
    8708,
    8746,
    8784,
    8822,
    8860,
    8898,
    8936,
    1278
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaTruncator_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaTruncator_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaTruncator_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaTruncator_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IFsaTruncatorProxyVtbl = 
{
    &IFsaTruncator_ProxyInfo,
    &IID_IFsaTruncator,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::GetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::GetKeepRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::GetMaxFilesPerRun */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::GetPremigratedSortOrder */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::GetRunInterval */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::SetMaxFilesPerRun */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::SetPremigratedSortOrder */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::SetRunInterval */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::SetKeepRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::Start */ ,
    (void *) (INT_PTR) -1 /* IFsaTruncator::KickStart */
};


static const PRPC_STUB_FUNCTION IFsaTruncator_table[] =
{
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaTruncatorStubVtbl =
{
    &IID_IFsaTruncator,
    &IFsaTruncator_ServerInfo,
    15,
    &IFsaTruncator_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaPostIt, ver. 0.0,
   GUID={0xB5A1ED6A,0xCED4,0x4D16,{0x9A,0x76,0x8C,0xD4,0x47,0x3A,0x2C,0xE9}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaPostIt_FormatStringOffsetTable[] =
    {
    8974,
    9012,
    9050,
    9088,
    9132,
    9170,
    9208,
    2118,
    316,
    9246,
    9284,
    9322,
    2276,
    9360,
    9398,
    9436,
    602,
    1506,
    9474,
    9512,
    9550,
    9588,
    9626,
    9664,
    9702,
    9740,
    9778,
    9816
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaPostIt_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaPostIt_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaPostIt_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaPostIt_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(31) _IFsaPostItProxyVtbl = 
{
    &IFsaPostIt_ProxyInfo,
    &IID_IFsaPostIt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetFileVersionId */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetFilterRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetMode */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetRequestAction */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetRequestOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetRequestSize */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetResult */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetResultAction */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetStoragePoolId */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetUSN */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::GetThreadId */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetFileVersionId */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetFilterRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetMode */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetRequestAction */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetRequestOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetRequestSize */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetResult */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetResultAction */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetStoragePoolId */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetUSN */ ,
    (void *) (INT_PTR) -1 /* IFsaPostIt::SetThreadId */
};

const CInterfaceStubVtbl _IFsaPostItStubVtbl =
{
    &IID_IFsaPostIt,
    &IFsaPostIt_ServerInfo,
    31,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaRecallNotifyClient, ver. 0.0,
   GUID={0xD68BD5B1,0xD6AA,0x11d0,{0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaRecallNotifyClient_FormatStringOffsetTable[] =
    {
    9854,
    9892,
    9930
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifyClient_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifyClient_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaRecallNotifyClient_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifyClient_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IFsaRecallNotifyClientProxyVtbl = 
{
    &IFsaRecallNotifyClient_ProxyInfo,
    &IID_IFsaRecallNotifyClient,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyClient::IdentifyWithServer */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyClient::OnRecallStarted */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyClient::OnRecallFinished */
};

const CInterfaceStubVtbl _IFsaRecallNotifyClientStubVtbl =
{
    &IID_IFsaRecallNotifyClient,
    &IFsaRecallNotifyClient_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaRecallNotifyServer, ver. 0.0,
   GUID={0xD68BD5B2,0xD6AA,0x11d0,{0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaRecallNotifyServer_FormatStringOffsetTable[] =
    {
    9974,
    10012,
    10044,
    10082,
    10120,
    1120,
    2080,
    2118,
    10158,
    1202,
    1246
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifyServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifyServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaRecallNotifyServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifyServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IFsaRecallNotifyServerProxyVtbl = 
{
    &IFsaRecallNotifyServer_ProxyInfo,
    &IID_IFsaRecallNotifyServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::Init */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::Cancel */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetMode */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetRecallFlags */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetState */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::GetUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifyServer::WasCancelled */
};

const CInterfaceStubVtbl _IFsaRecallNotifyServerStubVtbl =
{
    &IID_IFsaRecallNotifyServer,
    &IFsaRecallNotifyServer_ServerInfo,
    14,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaRecallNotifySend, ver. 0.0,
   GUID={0x931AC085,0xF98C,0x4595,{0x92,0xC0,0x70,0x6E,0xD3,0xDF,0xA6,0xD7}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaRecallNotifySend_FormatStringOffsetTable[] =
    {
    10196
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaRecallNotifySend_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifySend_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaRecallNotifySend_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaRecallNotifySend_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IFsaRecallNotifySendProxyVtbl = 
{
    &IFsaRecallNotifySend_ProxyInfo,
    &IID_IFsaRecallNotifySend,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaRecallNotifySend::SendNotification */
};

const CInterfaceStubVtbl _IFsaRecallNotifySendStubVtbl =
{
    &IID_IFsaRecallNotifySend,
    &IFsaRecallNotifySend_ServerInfo,
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

const CInterfaceProxyVtbl * _fsaint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IFsaFilterClientProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaFilterRecallProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaServerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaFilterProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaTruncatorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaPostItProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaRecallNotifySendProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaRecallNotifyClientProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaRecallNotifyServerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaResourceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaScanItemProxyVtbl,
    0
};

const CInterfaceStubVtbl * _fsaint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IFsaFilterClientStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaFilterRecallStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaServerStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaFilterStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaTruncatorStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaPostItStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaRecallNotifySendStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaRecallNotifyClientStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaRecallNotifyServerStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaResourceStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaScanItemStubVtbl,
    0
};

PCInterfaceName const _fsaint_InterfaceNamesList[] = 
{
    "IFsaFilterClient",
    "IFsaFilterRecall",
    "IFsaServer",
    "IFsaFilter",
    "IFsaTruncator",
    "IFsaPostIt",
    "IFsaRecallNotifySend",
    "IFsaRecallNotifyClient",
    "IFsaRecallNotifyServer",
    "IFsaResource",
    "IFsaScanItem",
    0
};

const IID *  _fsaint_BaseIIDList[] = 
{
    0,
    0,
    &IID_IHsmSystemState,
    0,
    &IID_IHsmSystemState,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};


#define _fsaint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _fsaint, pIID, n)

int __stdcall _fsaint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _fsaint, 11, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaint, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _fsaint, 11, *pIndex )
    
}

const ExtendedProxyFileInfo fsaint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _fsaint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _fsaint_StubVtblList,
    (const PCInterfaceName * ) & _fsaint_InterfaceNamesList,
    (const IID ** ) & _fsaint_BaseIIDList,
    & _fsaint_IID_Lookup, 
    11,
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

