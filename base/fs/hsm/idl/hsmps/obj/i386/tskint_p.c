

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for tskint.idl:
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


#include "tskint.h"

#define TYPE_FORMAT_STRING_SIZE   191                               
#define PROC_FORMAT_STRING_SIZE   1777                              
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


extern const MIDL_SERVER_INFO IHsmFsaTskMgr_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmFsaTskMgr_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmWorkQueue_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmWorkQueue_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmWorkItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmWorkItem_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRecallQueue_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRecallQueue_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRecallItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRecallItem_ProxyInfo;



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

	/* Procedure ContactOk */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x4 ),	/* 4 */
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

	/* Procedure DoFsaWork */

/* 30 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 32 */	NdrFcLong( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x5 ),	/* 5 */
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

	/* Parameter fsaWorkItem */

/* 54 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 56 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 58 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 66 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x6 ),	/* 6 */
/* 74 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x8 ),	/* 8 */
/* 80 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 82 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 90 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 92 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 94 */	NdrFcShort( 0x14 ),	/* Type Offset=20 */

	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WorkQueueDone */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x7 ),	/* 7 */
/* 110 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 112 */	NdrFcShort( 0x4c ),	/* 76 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 118 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 126 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 130 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter type */

/* 132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 134 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 136 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter mediaId */

/* 138 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 140 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 142 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 146 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x4 ),	/* 4 */
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

	/* Parameter pFsaWorkItem */

/* 174 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 176 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 178 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 180 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 182 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 186 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 188 */	NdrFcLong( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x5 ),	/* 5 */
/* 194 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 196 */	NdrFcShort( 0x8 ),	/* 8 */
/* 198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 200 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 202 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 210 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 212 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 214 */	NdrFcShort( 0x14 ),	/* Type Offset=20 */

	/* Parameter pSession */

/* 216 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 218 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 220 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter pTskMgr */

/* 222 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 224 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 226 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter type */

/* 228 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 230 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 232 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Start */


	/* Procedure Start */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x6 ),	/* 6 */
/* 248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 256 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 264 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stop */


	/* Procedure Stop */

/* 270 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 272 */	NdrFcLong( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x7 ),	/* 7 */
/* 278 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 284 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 286 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 296 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ContactOk */


	/* Procedure ContactOk */

/* 300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 316 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaId */


	/* Procedure GetCurrentSessionId */

/* 330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x9 ),	/* 9 */
/* 338 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0x4c ),	/* 76 */
/* 344 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 346 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */


	/* Parameter pSessionId */

/* 354 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 356 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 358 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */


	/* Return value */

/* 360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEventCookie */


	/* Procedure GetNumWorkItems */

/* 366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0xa ),	/* 10 */
/* 374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x24 ),	/* 36 */
/* 380 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 382 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEventCookie */


	/* Parameter pNumWorkItems */

/* 390 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 392 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 398 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIHsmWorkItem */

/* 402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x3 ),	/* 3 */
/* 410 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x22 ),	/* 34 */
/* 416 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 418 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkItem */

/* 426 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 428 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 430 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Parameter pResult */

/* 432 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 434 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 436 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFsaPostIt */


	/* Procedure GetFsaPostIt */

/* 444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x4 ),	/* 4 */
/* 452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 458 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFsaPostIt */


	/* Parameter ppFsaPostIt */

/* 468 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 472 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */


	/* Return value */

/* 474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFsaResource */


	/* Procedure GetFsaResource */

/* 480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x5 ),	/* 5 */
/* 488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 494 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFsaResource */


	/* Parameter ppFsaResource */

/* 504 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 508 */	NdrFcShort( 0x82 ),	/* Type Offset=130 */

	/* Return value */


	/* Return value */

/* 510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetId */


	/* Procedure GetId */

/* 516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x6 ),	/* 6 */
/* 524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x4c ),	/* 76 */
/* 530 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 532 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */


	/* Parameter pId */

/* 540 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 542 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 544 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */


	/* Return value */

/* 546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 548 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaInfo */


	/* Procedure GetMediaInfo */

/* 552 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x7 ),	/* 7 */
/* 560 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0xee ),	/* 238 */
/* 566 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 568 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaId */


	/* Parameter pMediaId */

/* 576 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 578 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 580 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter pMediaLastUpdate */


	/* Parameter pMediaLastUpdate */

/* 582 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 584 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 586 */	NdrFcShort( 0x9c ),	/* Type Offset=156 */

	/* Parameter pMediaLastError */


	/* Parameter pMediaLastError */

/* 588 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 590 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMediaRecallOnly */


	/* Parameter pMediaRecallOnly */

/* 594 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 596 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMediaFreeBytes */


	/* Parameter pMediaFreeBytes */

/* 600 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 602 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 604 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pMediaRemoteDataSet */


	/* Parameter pMediaRemoteDataSet */

/* 606 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 608 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 610 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 614 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResult */


	/* Procedure GetResult */

/* 618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x24 ),	/* 36 */
/* 632 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 634 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pHr */


	/* Parameter pHr */

/* 642 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetWorkType */


	/* Procedure GetWorkType */

/* 654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x9 ),	/* 9 */
/* 662 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x24 ),	/* 36 */
/* 668 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 670 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkType */


	/* Parameter pWorkType */

/* 678 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 682 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFsaPostIt */

/* 690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0xa ),	/* 10 */
/* 698 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 704 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 706 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsaPostIt */

/* 714 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 716 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 718 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 722 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFsaResource */

/* 726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0xb ),	/* 11 */
/* 734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 740 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 742 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsaResource */

/* 750 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 752 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 754 */	NdrFcShort( 0x86 ),	/* Type Offset=134 */

	/* Return value */

/* 756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 758 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaInfo */

/* 762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0xc ),	/* 12 */
/* 770 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 772 */	NdrFcShort( 0x6e ),	/* 110 */
/* 774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 776 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 778 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 786 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 788 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 790 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter mediaLastUpdate */

/* 792 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 794 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 796 */	NdrFcShort( 0x9c ),	/* Type Offset=156 */

	/* Parameter mediaLastError */

/* 798 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 800 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mediaRecallOnly */

/* 804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 806 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mediaFreeBytes */

/* 810 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 812 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 814 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter mediaRemoteDataSet */

/* 816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 818 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 820 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 824 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResult */

/* 828 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0xd ),	/* 13 */
/* 836 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 842 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 844 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hr */

/* 852 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 854 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWorkType */

/* 864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0xe ),	/* 14 */
/* 872 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 876 */	NdrFcShort( 0x8 ),	/* 8 */
/* 878 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 880 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter workType */

/* 888 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 890 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 892 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 896 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 900 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x4 ),	/* 4 */
/* 908 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 910 */	NdrFcShort( 0x54 ),	/* 84 */
/* 912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 914 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 916 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsaWorkItem */

/* 924 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 926 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 928 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pBagId */

/* 930 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 932 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 934 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter dataSetStart */

/* 936 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 938 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 940 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 944 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x5 ),	/* 5 */
/* 956 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 962 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 964 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 972 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 974 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 976 */	NdrFcShort( 0x14 ),	/* Type Offset=20 */

	/* Parameter pTskMgr */

/* 978 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 982 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Return value */

/* 984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 986 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaId */

/* 990 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0xa ),	/* 10 */
/* 998 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1000 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1004 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1006 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 1014 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1016 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1018 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1022 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsEmpty */

/* 1026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0xb ),	/* 11 */
/* 1034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1040 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1042 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1050 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1052 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIHsmRecallItem */

/* 1056 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1058 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1064 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1070 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1072 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkItem */

/* 1080 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1082 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1084 */	NdrFcShort( 0xac ),	/* Type Offset=172 */

	/* Parameter pResult */

/* 1086 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1088 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1090 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1092 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1094 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStateCookie */

/* 1098 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0xb ),	/* 11 */
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

	/* Parameter pStateCookie */

/* 1122 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1124 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJobState */

/* 1134 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1140 */	NdrFcShort( 0xc ),	/* 12 */
/* 1142 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1148 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1150 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pJobState */

/* 1158 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1160 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1162 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1166 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJobPhase */

/* 1170 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0xd ),	/* 13 */
/* 1178 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1184 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1186 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pJobPhase */

/* 1194 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1196 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1198 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1202 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSeekOffset */

/* 1206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1212 */	NdrFcShort( 0xe ),	/* 14 */
/* 1214 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1220 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1222 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pJobPhase */

/* 1230 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1232 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1234 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1238 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBagId */

/* 1242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0xf ),	/* 15 */
/* 1250 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1256 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1258 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBagId */

/* 1266 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1268 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1270 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1274 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDataSetStart */

/* 1278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1286 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1292 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1294 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataSetStart */

/* 1302 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1306 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFsaPostIt */

/* 1314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1320 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1322 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1328 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1330 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1336 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsaPostIt */

/* 1338 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1340 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1342 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 1344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1346 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFsaResource */

/* 1350 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1358 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1364 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1366 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsaResource */

/* 1374 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1376 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1378 */	NdrFcShort( 0x86 ),	/* Type Offset=134 */

	/* Return value */

/* 1380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1382 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaInfo */

/* 1386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1394 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 1396 */	NdrFcShort( 0x6e ),	/* 110 */
/* 1398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1400 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 1402 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 1410 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1414 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter mediaLastUpdate */

/* 1416 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1418 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1420 */	NdrFcShort( 0x9c ),	/* Type Offset=156 */

	/* Parameter mediaLastError */

/* 1422 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1424 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mediaRecallOnly */

/* 1428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1430 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mediaFreeBytes */

/* 1434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1436 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1438 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter mediaRemoteDataSet */

/* 1440 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1442 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1444 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1448 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResult */

/* 1452 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1458 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1460 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1466 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1468 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1474 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hr */

/* 1476 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1478 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1482 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWorkType */

/* 1488 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1490 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1494 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1496 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1498 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1500 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1502 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1504 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1510 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter workType */

/* 1512 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1514 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1516 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1520 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetEventCookie */

/* 1524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1530 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1532 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1536 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1538 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1540 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter eventCookie */

/* 1548 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1550 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStateCookie */

/* 1560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1568 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1574 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1576 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter stateCookie */

/* 1584 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1586 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1592 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetJobState */

/* 1596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1604 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1610 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1612 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter jobState */

/* 1620 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1622 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1624 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1628 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetJobPhase */

/* 1632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1638 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1640 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1646 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1648 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter jobPhase */

/* 1656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1658 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1660 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1664 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSeekOffset */

/* 1668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1676 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1678 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1680 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1682 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1684 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1690 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter seekOffset */

/* 1692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1694 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1696 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1700 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagId */

/* 1704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1712 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1714 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1716 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1718 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1720 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bagId */

/* 1728 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1730 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1732 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDataSetStart */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1748 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1750 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1754 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1756 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dataSetStart */

/* 1764 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1766 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1768 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1772 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1774 */	0x8,		/* FC_LONG */
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
/*  4 */	NdrFcLong( 0xb5a1ed6a ),	/* -1247679126 */
/*  8 */	NdrFcShort( 0xced4 ),	/* -12588 */
/* 10 */	NdrFcShort( 0x4d16 ),	/* 19734 */
/* 12 */	0x9a,		/* 154 */
			0x76,		/* 118 */
/* 14 */	0x8c,		/* 140 */
			0xd4,		/* 212 */
/* 16 */	0x47,		/* 71 */
			0x3a,		/* 58 */
/* 18 */	0x2c,		/* 44 */
			0xe9,		/* 233 */
/* 20 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 22 */	NdrFcLong( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */
/* 30 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 32 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 34 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 36 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 38 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 40 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 44 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 46 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 48 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 50 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 52 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 54 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 56 */	
			0x11, 0x0,	/* FC_RP */
/* 58 */	NdrFcShort( 0x8 ),	/* Offset= 8 (66) */
/* 60 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 62 */	NdrFcShort( 0x8 ),	/* 8 */
/* 64 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 66 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 68 */	NdrFcShort( 0x10 ),	/* 16 */
/* 70 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 72 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 74 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (60) */
			0x5b,		/* FC_END */
/* 78 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 80 */	NdrFcLong( 0x14f73fcb ),	/* 351748043 */
/* 84 */	NdrFcShort( 0x517d ),	/* 20861 */
/* 86 */	NdrFcShort( 0x4503 ),	/* 17667 */
/* 88 */	0xb1,		/* 177 */
			0x5d,		/* 93 */
/* 90 */	0x2d,		/* 45 */
			0x40,		/* 64 */
/* 92 */	0xb3,		/* 179 */
			0xe9,		/* 233 */
/* 94 */	0xcd,		/* 205 */
			0x21,		/* 33 */
/* 96 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 98 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (66) */
/* 100 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 102 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 104 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 106 */	NdrFcLong( 0xbf8bbcd0 ),	/* -1081361200 */
/* 110 */	NdrFcShort( 0xc596 ),	/* -14954 */
/* 112 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 114 */	0xb1,		/* 177 */
			0x6f,		/* 111 */
/* 116 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 118 */	0xc9,		/* 201 */
			0x16,		/* 22 */
/* 120 */	0xf1,		/* 241 */
			0x20,		/* 32 */
/* 122 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 124 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 126 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 128 */	NdrFcShort( 0xff82 ),	/* Offset= -126 (2) */
/* 130 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 132 */	NdrFcShort( 0x2 ),	/* Offset= 2 (134) */
/* 134 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 136 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 140 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 142 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 144 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 146 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 148 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 150 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 152 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 154 */	NdrFcShort( 0x2 ),	/* Offset= 2 (156) */
/* 156 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 160 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 162 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 164 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 166 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 168 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 170 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 172 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 174 */	NdrFcLong( 0xb287c709 ),	/* -1299724535 */
/* 178 */	NdrFcShort( 0xf4ad ),	/* -2899 */
/* 180 */	NdrFcShort( 0x467c ),	/* 18044 */
/* 182 */	0x81,		/* 129 */
			0x1d,		/* 29 */
/* 184 */	0x1d,		/* 29 */
			0x56,		/* 86 */
/* 186 */	0x2,		/* 2 */
			0x1d,		/* 29 */
/* 188 */	0x68,		/* 104 */
			0xad,		/* 173 */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_tskint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IHsmSystemState, ver. 0.0,
   GUID={0x3F0DA041,0x69F1,0x11d2,{0xAF,0x82,0x00,0x10,0x4B,0x9A,0x37,0x58}} */


/* Object interface: IHsmFsaTskMgr, ver. 0.0,
   GUID={0x14F73FCB,0x517D,0x4503,{0xB1,0x5D,0x2D,0x40,0xB3,0xE9,0xCD,0x21}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmFsaTskMgr_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    0,
    30,
    66,
    102
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmFsaTskMgr_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmFsaTskMgr_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmFsaTskMgr_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmFsaTskMgr_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IHsmFsaTskMgrProxyVtbl = 
{
    &IHsmFsaTskMgr_ProxyInfo,
    &IID_IHsmFsaTskMgr,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IHsmFsaTskMgr::ContactOk */ ,
    (void *) (INT_PTR) -1 /* IHsmFsaTskMgr::DoFsaWork */ ,
    (void *) (INT_PTR) -1 /* IHsmFsaTskMgr::Init */ ,
    (void *) (INT_PTR) -1 /* IHsmFsaTskMgr::WorkQueueDone */
};


static const PRPC_STUB_FUNCTION IHsmFsaTskMgr_table[] =
{
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IHsmFsaTskMgrStubVtbl =
{
    &IID_IHsmFsaTskMgr,
    &IHsmFsaTskMgr_ServerInfo,
    8,
    &IHsmFsaTskMgr_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHsmWorkQueue, ver. 0.0,
   GUID={0x39A35CB0,0xC56B,0x11d0,{0xB1,0x6F,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmWorkQueue_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    150,
    186,
    240,
    270,
    300,
    330,
    366
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmWorkQueue_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmWorkQueue_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmWorkQueue_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmWorkQueue_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IHsmWorkQueueProxyVtbl = 
{
    &IHsmWorkQueue_ProxyInfo,
    &IID_IHsmWorkQueue,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::Add */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::Init */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::Start */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::Stop */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::ContactOk */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::GetCurrentSessionId */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::GetNumWorkItems */
};


static const PRPC_STUB_FUNCTION IHsmWorkQueue_table[] =
{
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IHsmWorkQueueStubVtbl =
{
    &IID_IHsmWorkQueue,
    &IHsmWorkQueue_ServerInfo,
    11,
    &IHsmWorkQueue_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHsmWorkItem, ver. 0.0,
   GUID={0xBF8BBCD0,0xC596,0x11d0,{0xB1,0x6F,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmWorkItem_FormatStringOffsetTable[] =
    {
    402,
    444,
    480,
    516,
    552,
    618,
    654,
    690,
    726,
    762,
    828,
    864
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmWorkItem_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmWorkItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmWorkItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmWorkItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IHsmWorkItemProxyVtbl = 
{
    &IHsmWorkItem_ProxyInfo,
    &IID_IHsmWorkItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::CompareToIHsmWorkItem */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetFsaPostIt */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetId */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetResult */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetWorkType */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::SetFsaPostIt */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::SetFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::SetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::SetResult */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::SetWorkType */
};

const CInterfaceStubVtbl _IHsmWorkItemStubVtbl =
{
    &IID_IHsmWorkItem,
    &IHsmWorkItem_ServerInfo,
    15,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmRecallQueue, ver. 0.0,
   GUID={0xE3A35E06,0x4263,0x4505,{0xB7,0x7B,0x19,0x6B,0x22,0xAC,0xC9,0x4b}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRecallQueue_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    900,
    948,
    240,
    270,
    300,
    330,
    990,
    1026
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRecallQueue_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRecallQueue_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRecallQueue_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRecallQueue_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IHsmRecallQueueProxyVtbl = 
{
    &IHsmRecallQueue_ProxyInfo,
    &IID_IHsmRecallQueue,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::Add */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::Init */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::Start */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::Stop */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::ContactOk */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::GetMediaId */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::SetMediaId */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::IsEmpty */
};


static const PRPC_STUB_FUNCTION IHsmRecallQueue_table[] =
{
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IHsmRecallQueueStubVtbl =
{
    &IID_IHsmRecallQueue,
    &IHsmRecallQueue_ServerInfo,
    12,
    &IHsmRecallQueue_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHsmRecallItem, ver. 0.0,
   GUID={0xB287C709,0xf4AD,0x467C,{0x81,0x1D,0x1D,0x56,0x02,0x1D,0x68,0xAD}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRecallItem_FormatStringOffsetTable[] =
    {
    1056,
    444,
    480,
    516,
    552,
    618,
    654,
    366,
    1098,
    1134,
    1170,
    1206,
    1242,
    1278,
    1314,
    1350,
    1386,
    1452,
    1488,
    1524,
    1560,
    1596,
    1632,
    1668,
    1704,
    1740
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRecallItem_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRecallItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRecallItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRecallItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(29) _IHsmRecallItemProxyVtbl = 
{
    &IHsmRecallItem_ProxyInfo,
    &IID_IHsmRecallItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::CompareToIHsmRecallItem */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetFsaPostIt */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetId */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetResult */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetWorkType */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetEventCookie */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetStateCookie */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetJobState */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetJobPhase */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetSeekOffset */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetBagId */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetDataSetStart */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetFsaPostIt */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetResult */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetWorkType */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetEventCookie */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetStateCookie */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetJobState */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetJobPhase */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetSeekOffset */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetBagId */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetDataSetStart */
};

const CInterfaceStubVtbl _IHsmRecallItemStubVtbl =
{
    &IID_IHsmRecallItem,
    &IHsmRecallItem_ServerInfo,
    29,
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

const CInterfaceProxyVtbl * _tskint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IHsmRecallQueueProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmRecallItemProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmWorkQueueProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmFsaTskMgrProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmWorkItemProxyVtbl,
    0
};

const CInterfaceStubVtbl * _tskint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IHsmRecallQueueStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmRecallItemStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmWorkQueueStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmFsaTskMgrStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmWorkItemStubVtbl,
    0
};

PCInterfaceName const _tskint_InterfaceNamesList[] = 
{
    "IHsmRecallQueue",
    "IHsmRecallItem",
    "IHsmWorkQueue",
    "IHsmFsaTskMgr",
    "IHsmWorkItem",
    0
};

const IID *  _tskint_BaseIIDList[] = 
{
    &IID_IHsmSystemState,
    0,
    &IID_IHsmSystemState,
    &IID_IHsmSystemState,
    0,
    0
};


#define _tskint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _tskint, pIID, n)

int __stdcall _tskint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _tskint, 5, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _tskint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _tskint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _tskint, 5, *pIndex )
    
}

const ExtendedProxyFileInfo tskint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _tskint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _tskint_StubVtblList,
    (const PCInterfaceName * ) & _tskint_InterfaceNamesList,
    (const IID ** ) & _tskint_BaseIIDList,
    & _tskint_IID_Lookup, 
    5,
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
/* Compiler settings for tskint.idl:
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


#include "tskint.h"

#define TYPE_FORMAT_STRING_SIZE   191                               
#define PROC_FORMAT_STRING_SIZE   1869                              
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


extern const MIDL_SERVER_INFO IHsmFsaTskMgr_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmFsaTskMgr_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmWorkQueue_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmWorkQueue_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmWorkItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmWorkItem_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRecallQueue_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRecallQueue_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRecallItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRecallItem_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure ContactOk */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x4 ),	/* 4 */
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

	/* Procedure DoFsaWork */

/* 32 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 34 */	NdrFcLong( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0x5 ),	/* 5 */
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

	/* Parameter fsaWorkItem */

/* 58 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 60 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 62 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 64 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 66 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 68 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 70 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 72 */	NdrFcLong( 0x0 ),	/* 0 */
/* 76 */	NdrFcShort( 0x6 ),	/* 6 */
/* 78 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 80 */	NdrFcShort( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x8 ),	/* 8 */
/* 84 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 86 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 96 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 98 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 100 */	NdrFcShort( 0x14 ),	/* Type Offset=20 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WorkQueueDone */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x7 ),	/* 7 */
/* 116 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 118 */	NdrFcShort( 0x4c ),	/* 76 */
/* 120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 122 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 124 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 134 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 136 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 138 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter type */

/* 140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 142 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 144 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter mediaId */

/* 146 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 148 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 150 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 154 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x4 ),	/* 4 */
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

	/* Parameter pFsaWorkItem */

/* 184 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 186 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 188 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 192 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x5 ),	/* 5 */
/* 204 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 210 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 212 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 222 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 224 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 226 */	NdrFcShort( 0x14 ),	/* Type Offset=20 */

	/* Parameter pSession */

/* 228 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 230 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 232 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter pTskMgr */

/* 234 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 236 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 238 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Parameter type */

/* 240 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 242 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 244 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 248 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Start */


	/* Procedure Start */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x6 ),	/* 6 */
/* 260 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 268 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 280 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stop */


	/* Procedure Stop */

/* 284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0x7 ),	/* 7 */
/* 292 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 298 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 300 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 312 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ContactOk */


	/* Procedure ContactOk */

/* 316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 324 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 330 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 332 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 344 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaId */


	/* Procedure GetCurrentSessionId */

/* 348 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x9 ),	/* 9 */
/* 356 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x4c ),	/* 76 */
/* 362 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 364 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */


	/* Parameter pSessionId */

/* 374 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 376 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 378 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */


	/* Return value */

/* 380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 382 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEventCookie */


	/* Procedure GetNumWorkItems */

/* 386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 392 */	NdrFcShort( 0xa ),	/* 10 */
/* 394 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x24 ),	/* 36 */
/* 400 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 402 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEventCookie */


	/* Parameter pNumWorkItems */

/* 412 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 414 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 420 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIHsmWorkItem */

/* 424 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 430 */	NdrFcShort( 0x3 ),	/* 3 */
/* 432 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x22 ),	/* 34 */
/* 438 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 440 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkItem */

/* 450 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 452 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 454 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Parameter pResult */

/* 456 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 458 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 460 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 464 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFsaPostIt */


	/* Procedure GetFsaPostIt */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x4 ),	/* 4 */
/* 476 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x8 ),	/* 8 */
/* 482 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 484 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFsaPostIt */


	/* Parameter ppFsaPostIt */

/* 494 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 496 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 498 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */


	/* Return value */

/* 500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 502 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFsaResource */


	/* Procedure GetFsaResource */

/* 506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x5 ),	/* 5 */
/* 514 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 520 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 522 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFsaResource */


	/* Parameter ppFsaResource */

/* 532 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 534 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 536 */	NdrFcShort( 0x82 ),	/* Type Offset=130 */

	/* Return value */


	/* Return value */

/* 538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 540 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetId */


	/* Procedure GetId */

/* 544 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x6 ),	/* 6 */
/* 552 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x4c ),	/* 76 */
/* 558 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 560 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */


	/* Parameter pId */

/* 570 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 572 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 574 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */


	/* Return value */

/* 576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 578 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaInfo */


	/* Procedure GetMediaInfo */

/* 582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x7 ),	/* 7 */
/* 590 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0xee ),	/* 238 */
/* 596 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 598 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaId */


	/* Parameter pMediaId */

/* 608 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 610 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 612 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter pMediaLastUpdate */


	/* Parameter pMediaLastUpdate */

/* 614 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 616 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 618 */	NdrFcShort( 0x9c ),	/* Type Offset=156 */

	/* Parameter pMediaLastError */


	/* Parameter pMediaLastError */

/* 620 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 622 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMediaRecallOnly */


	/* Parameter pMediaRecallOnly */

/* 626 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 628 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMediaFreeBytes */


	/* Parameter pMediaFreeBytes */

/* 632 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 634 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 636 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pMediaRemoteDataSet */


	/* Parameter pMediaRemoteDataSet */

/* 638 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 640 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 642 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 646 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResult */


	/* Procedure GetResult */

/* 650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 658 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x24 ),	/* 36 */
/* 664 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 666 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pHr */


	/* Parameter pHr */

/* 676 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 678 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 684 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetWorkType */


	/* Procedure GetWorkType */

/* 688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x9 ),	/* 9 */
/* 696 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x24 ),	/* 36 */
/* 702 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 704 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkType */


	/* Parameter pWorkType */

/* 714 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 716 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 718 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 722 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFsaPostIt */

/* 726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0xa ),	/* 10 */
/* 734 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 740 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 742 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsaPostIt */

/* 752 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 754 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 756 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 758 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 760 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 762 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFsaResource */

/* 764 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 766 */	NdrFcLong( 0x0 ),	/* 0 */
/* 770 */	NdrFcShort( 0xb ),	/* 11 */
/* 772 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x8 ),	/* 8 */
/* 778 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 780 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsaResource */

/* 790 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 792 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 794 */	NdrFcShort( 0x86 ),	/* Type Offset=134 */

	/* Return value */

/* 796 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 798 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaInfo */

/* 802 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 804 */	NdrFcLong( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0xc ),	/* 12 */
/* 810 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 812 */	NdrFcShort( 0x6e ),	/* 110 */
/* 814 */	NdrFcShort( 0x8 ),	/* 8 */
/* 816 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 818 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 828 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 830 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 832 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter mediaLastUpdate */

/* 834 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 836 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 838 */	NdrFcShort( 0x9c ),	/* Type Offset=156 */

	/* Parameter mediaLastError */

/* 840 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 842 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mediaRecallOnly */

/* 846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 848 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mediaFreeBytes */

/* 852 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 854 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 856 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter mediaRemoteDataSet */

/* 858 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 860 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 862 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 864 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 866 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResult */

/* 870 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0xd ),	/* 13 */
/* 878 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 884 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 886 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hr */

/* 896 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 898 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 902 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 904 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWorkType */

/* 908 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 910 */	NdrFcLong( 0x0 ),	/* 0 */
/* 914 */	NdrFcShort( 0xe ),	/* 14 */
/* 916 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 922 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 924 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter workType */

/* 934 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 936 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 938 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 940 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 942 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 946 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x4 ),	/* 4 */
/* 954 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 956 */	NdrFcShort( 0x54 ),	/* 84 */
/* 958 */	NdrFcShort( 0x8 ),	/* 8 */
/* 960 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 962 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsaWorkItem */

/* 972 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 974 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 976 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pBagId */

/* 978 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 980 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 982 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter dataSetStart */

/* 984 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 986 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 988 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 992 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 996 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1004 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1010 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1012 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 1022 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1024 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1026 */	NdrFcShort( 0x14 ),	/* Type Offset=20 */

	/* Parameter pTskMgr */

/* 1028 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1030 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1032 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Return value */

/* 1034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1036 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaId */

/* 1040 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0xa ),	/* 10 */
/* 1048 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1050 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1052 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1054 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1056 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1064 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 1066 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1068 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1070 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1072 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1074 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsEmpty */

/* 1078 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1080 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0xb ),	/* 11 */
/* 1086 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1092 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1094 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1102 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1106 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIHsmRecallItem */

/* 1110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1118 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1124 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1126 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkItem */

/* 1136 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1138 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1140 */	NdrFcShort( 0xac ),	/* Type Offset=172 */

	/* Parameter pResult */

/* 1142 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1144 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1146 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1150 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStateCookie */

/* 1154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1160 */	NdrFcShort( 0xb ),	/* 11 */
/* 1162 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1168 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1170 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStateCookie */

/* 1180 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1182 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1188 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJobState */

/* 1192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1198 */	NdrFcShort( 0xc ),	/* 12 */
/* 1200 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1204 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1206 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1208 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pJobState */

/* 1218 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1220 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1222 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1226 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJobPhase */

/* 1230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0xd ),	/* 13 */
/* 1238 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1242 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1244 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1246 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pJobPhase */

/* 1256 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1258 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1260 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1262 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1264 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSeekOffset */

/* 1268 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1270 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1274 */	NdrFcShort( 0xe ),	/* 14 */
/* 1276 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1280 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1282 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1284 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1292 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pJobPhase */

/* 1294 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1296 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1298 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1302 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBagId */

/* 1306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0xf ),	/* 15 */
/* 1314 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1318 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1320 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1322 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1330 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBagId */

/* 1332 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1334 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1336 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1340 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDataSetStart */

/* 1344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1352 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1358 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1360 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataSetStart */

/* 1370 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1372 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1374 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1378 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFsaPostIt */

/* 1382 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1388 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1390 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1394 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1396 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1398 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1406 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsaPostIt */

/* 1408 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1410 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1412 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 1414 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1416 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFsaResource */

/* 1420 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1426 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1428 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1434 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1436 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1444 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsaResource */

/* 1446 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1448 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1450 */	NdrFcShort( 0x86 ),	/* Type Offset=134 */

	/* Return value */

/* 1452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1454 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaInfo */

/* 1458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1464 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1466 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 1468 */	NdrFcShort( 0x6e ),	/* 110 */
/* 1470 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1472 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 1474 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 1484 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1486 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1488 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter mediaLastUpdate */

/* 1490 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1492 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1494 */	NdrFcShort( 0x9c ),	/* Type Offset=156 */

	/* Parameter mediaLastError */

/* 1496 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1498 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mediaRecallOnly */

/* 1502 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1504 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mediaFreeBytes */

/* 1508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1510 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1512 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter mediaRemoteDataSet */

/* 1514 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1516 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1518 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1522 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResult */

/* 1526 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1532 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1534 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1536 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1540 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1542 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hr */

/* 1552 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1554 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1560 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWorkType */

/* 1564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1570 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1572 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1574 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1578 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1580 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter workType */

/* 1590 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1592 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1594 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1598 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetEventCookie */

/* 1602 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1608 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1610 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1612 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1616 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1618 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter eventCookie */

/* 1628 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1630 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1634 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1636 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStateCookie */

/* 1640 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1646 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1648 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1652 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1654 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1656 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter stateCookie */

/* 1666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1668 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1674 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetJobState */

/* 1678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1684 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1686 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1692 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1694 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1702 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter jobState */

/* 1704 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1706 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1708 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1712 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetJobPhase */

/* 1716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1724 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1730 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1732 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1740 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter jobPhase */

/* 1742 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1744 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1746 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1748 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1750 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSeekOffset */

/* 1754 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1756 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1762 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1764 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1768 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1770 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter seekOffset */

/* 1780 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1782 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1784 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1788 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagId */

/* 1792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1800 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1802 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1804 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1806 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1808 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1816 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bagId */

/* 1818 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1820 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1822 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1824 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1826 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDataSetStart */

/* 1830 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1832 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1836 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1838 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1840 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1842 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1844 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1846 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dataSetStart */

/* 1856 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1858 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1860 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1862 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1864 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1866 */	0x8,		/* FC_LONG */
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
/*  4 */	NdrFcLong( 0xb5a1ed6a ),	/* -1247679126 */
/*  8 */	NdrFcShort( 0xced4 ),	/* -12588 */
/* 10 */	NdrFcShort( 0x4d16 ),	/* 19734 */
/* 12 */	0x9a,		/* 154 */
			0x76,		/* 118 */
/* 14 */	0x8c,		/* 140 */
			0xd4,		/* 212 */
/* 16 */	0x47,		/* 71 */
			0x3a,		/* 58 */
/* 18 */	0x2c,		/* 44 */
			0xe9,		/* 233 */
/* 20 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 22 */	NdrFcLong( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */
/* 30 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 32 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 34 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 36 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 38 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 40 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 44 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 46 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 48 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 50 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 52 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 54 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 56 */	
			0x11, 0x0,	/* FC_RP */
/* 58 */	NdrFcShort( 0x8 ),	/* Offset= 8 (66) */
/* 60 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 62 */	NdrFcShort( 0x8 ),	/* 8 */
/* 64 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 66 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 68 */	NdrFcShort( 0x10 ),	/* 16 */
/* 70 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 72 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 74 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (60) */
			0x5b,		/* FC_END */
/* 78 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 80 */	NdrFcLong( 0x14f73fcb ),	/* 351748043 */
/* 84 */	NdrFcShort( 0x517d ),	/* 20861 */
/* 86 */	NdrFcShort( 0x4503 ),	/* 17667 */
/* 88 */	0xb1,		/* 177 */
			0x5d,		/* 93 */
/* 90 */	0x2d,		/* 45 */
			0x40,		/* 64 */
/* 92 */	0xb3,		/* 179 */
			0xe9,		/* 233 */
/* 94 */	0xcd,		/* 205 */
			0x21,		/* 33 */
/* 96 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 98 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (66) */
/* 100 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 102 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 104 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 106 */	NdrFcLong( 0xbf8bbcd0 ),	/* -1081361200 */
/* 110 */	NdrFcShort( 0xc596 ),	/* -14954 */
/* 112 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 114 */	0xb1,		/* 177 */
			0x6f,		/* 111 */
/* 116 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 118 */	0xc9,		/* 201 */
			0x16,		/* 22 */
/* 120 */	0xf1,		/* 241 */
			0x20,		/* 32 */
/* 122 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 124 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 126 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 128 */	NdrFcShort( 0xff82 ),	/* Offset= -126 (2) */
/* 130 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 132 */	NdrFcShort( 0x2 ),	/* Offset= 2 (134) */
/* 134 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 136 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 140 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 142 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 144 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 146 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 148 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 150 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 152 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 154 */	NdrFcShort( 0x2 ),	/* Offset= 2 (156) */
/* 156 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 160 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 162 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 164 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 166 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 168 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 170 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 172 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 174 */	NdrFcLong( 0xb287c709 ),	/* -1299724535 */
/* 178 */	NdrFcShort( 0xf4ad ),	/* -2899 */
/* 180 */	NdrFcShort( 0x467c ),	/* 18044 */
/* 182 */	0x81,		/* 129 */
			0x1d,		/* 29 */
/* 184 */	0x1d,		/* 29 */
			0x56,		/* 86 */
/* 186 */	0x2,		/* 2 */
			0x1d,		/* 29 */
/* 188 */	0x68,		/* 104 */
			0xad,		/* 173 */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_tskint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IHsmSystemState, ver. 0.0,
   GUID={0x3F0DA041,0x69F1,0x11d2,{0xAF,0x82,0x00,0x10,0x4B,0x9A,0x37,0x58}} */


/* Object interface: IHsmFsaTskMgr, ver. 0.0,
   GUID={0x14F73FCB,0x517D,0x4503,{0xB1,0x5D,0x2D,0x40,0xB3,0xE9,0xCD,0x21}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmFsaTskMgr_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    0,
    32,
    70,
    108
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmFsaTskMgr_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmFsaTskMgr_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmFsaTskMgr_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmFsaTskMgr_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IHsmFsaTskMgrProxyVtbl = 
{
    &IHsmFsaTskMgr_ProxyInfo,
    &IID_IHsmFsaTskMgr,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IHsmFsaTskMgr::ContactOk */ ,
    (void *) (INT_PTR) -1 /* IHsmFsaTskMgr::DoFsaWork */ ,
    (void *) (INT_PTR) -1 /* IHsmFsaTskMgr::Init */ ,
    (void *) (INT_PTR) -1 /* IHsmFsaTskMgr::WorkQueueDone */
};


static const PRPC_STUB_FUNCTION IHsmFsaTskMgr_table[] =
{
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IHsmFsaTskMgrStubVtbl =
{
    &IID_IHsmFsaTskMgr,
    &IHsmFsaTskMgr_ServerInfo,
    8,
    &IHsmFsaTskMgr_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHsmWorkQueue, ver. 0.0,
   GUID={0x39A35CB0,0xC56B,0x11d0,{0xB1,0x6F,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmWorkQueue_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    158,
    196,
    252,
    284,
    316,
    348,
    386
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmWorkQueue_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmWorkQueue_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmWorkQueue_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmWorkQueue_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IHsmWorkQueueProxyVtbl = 
{
    &IHsmWorkQueue_ProxyInfo,
    &IID_IHsmWorkQueue,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::Add */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::Init */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::Start */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::Stop */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::ContactOk */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::GetCurrentSessionId */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkQueue::GetNumWorkItems */
};


static const PRPC_STUB_FUNCTION IHsmWorkQueue_table[] =
{
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IHsmWorkQueueStubVtbl =
{
    &IID_IHsmWorkQueue,
    &IHsmWorkQueue_ServerInfo,
    11,
    &IHsmWorkQueue_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHsmWorkItem, ver. 0.0,
   GUID={0xBF8BBCD0,0xC596,0x11d0,{0xB1,0x6F,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmWorkItem_FormatStringOffsetTable[] =
    {
    424,
    468,
    506,
    544,
    582,
    650,
    688,
    726,
    764,
    802,
    870,
    908
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmWorkItem_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmWorkItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmWorkItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmWorkItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IHsmWorkItemProxyVtbl = 
{
    &IHsmWorkItem_ProxyInfo,
    &IID_IHsmWorkItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::CompareToIHsmWorkItem */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetFsaPostIt */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetId */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetResult */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::GetWorkType */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::SetFsaPostIt */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::SetFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::SetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::SetResult */ ,
    (void *) (INT_PTR) -1 /* IHsmWorkItem::SetWorkType */
};

const CInterfaceStubVtbl _IHsmWorkItemStubVtbl =
{
    &IID_IHsmWorkItem,
    &IHsmWorkItem_ServerInfo,
    15,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmRecallQueue, ver. 0.0,
   GUID={0xE3A35E06,0x4263,0x4505,{0xB7,0x7B,0x19,0x6B,0x22,0xAC,0xC9,0x4b}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRecallQueue_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    946,
    996,
    252,
    284,
    316,
    348,
    1040,
    1078
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRecallQueue_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRecallQueue_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRecallQueue_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRecallQueue_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IHsmRecallQueueProxyVtbl = 
{
    &IHsmRecallQueue_ProxyInfo,
    &IID_IHsmRecallQueue,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::Add */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::Init */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::Start */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::Stop */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::ContactOk */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::GetMediaId */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::SetMediaId */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallQueue::IsEmpty */
};


static const PRPC_STUB_FUNCTION IHsmRecallQueue_table[] =
{
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IHsmRecallQueueStubVtbl =
{
    &IID_IHsmRecallQueue,
    &IHsmRecallQueue_ServerInfo,
    12,
    &IHsmRecallQueue_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHsmRecallItem, ver. 0.0,
   GUID={0xB287C709,0xf4AD,0x467C,{0x81,0x1D,0x1D,0x56,0x02,0x1D,0x68,0xAD}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRecallItem_FormatStringOffsetTable[] =
    {
    1110,
    468,
    506,
    544,
    582,
    650,
    688,
    386,
    1154,
    1192,
    1230,
    1268,
    1306,
    1344,
    1382,
    1420,
    1458,
    1526,
    1564,
    1602,
    1640,
    1678,
    1716,
    1754,
    1792,
    1830
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRecallItem_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRecallItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRecallItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRecallItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(29) _IHsmRecallItemProxyVtbl = 
{
    &IHsmRecallItem_ProxyInfo,
    &IID_IHsmRecallItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::CompareToIHsmRecallItem */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetFsaPostIt */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetId */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetResult */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetWorkType */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetEventCookie */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetStateCookie */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetJobState */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetJobPhase */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetSeekOffset */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetBagId */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::GetDataSetStart */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetFsaPostIt */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetResult */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetWorkType */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetEventCookie */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetStateCookie */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetJobState */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetJobPhase */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetSeekOffset */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetBagId */ ,
    (void *) (INT_PTR) -1 /* IHsmRecallItem::SetDataSetStart */
};

const CInterfaceStubVtbl _IHsmRecallItemStubVtbl =
{
    &IID_IHsmRecallItem,
    &IHsmRecallItem_ServerInfo,
    29,
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

const CInterfaceProxyVtbl * _tskint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IHsmRecallQueueProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmRecallItemProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmWorkQueueProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmFsaTskMgrProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmWorkItemProxyVtbl,
    0
};

const CInterfaceStubVtbl * _tskint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IHsmRecallQueueStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmRecallItemStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmWorkQueueStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmFsaTskMgrStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmWorkItemStubVtbl,
    0
};

PCInterfaceName const _tskint_InterfaceNamesList[] = 
{
    "IHsmRecallQueue",
    "IHsmRecallItem",
    "IHsmWorkQueue",
    "IHsmFsaTskMgr",
    "IHsmWorkItem",
    0
};

const IID *  _tskint_BaseIIDList[] = 
{
    &IID_IHsmSystemState,
    0,
    &IID_IHsmSystemState,
    &IID_IHsmSystemState,
    0,
    0
};


#define _tskint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _tskint, pIID, n)

int __stdcall _tskint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _tskint, 5, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _tskint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _tskint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _tskint, 5, *pIndex )
    
}

const ExtendedProxyFileInfo tskint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _tskint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _tskint_StubVtblList,
    (const PCInterfaceName * ) & _tskint_InterfaceNamesList,
    (const IID ** ) & _tskint_BaseIIDList,
    & _tskint_IID_Lookup, 
    5,
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

