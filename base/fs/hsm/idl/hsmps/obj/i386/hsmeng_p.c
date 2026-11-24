

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for hsmeng.idl:
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


#include "hsmeng.h"

#define TYPE_FORMAT_STRING_SIZE   311                               
#define PROC_FORMAT_STRING_SIZE   2959                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

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


extern const MIDL_SERVER_INFO IHsmServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmUpgradeRmsDb_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmUpgradeRmsDb_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmManagedResource_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmManagedResource_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmManagedResourceCollection_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmManagedResourceCollection_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmStoragePool_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmStoragePool_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMountingMedia_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMountingMedia_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

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

	/* Procedure Init */

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

	/* Procedure GetId */


	/* Procedure GetResourceId */


	/* Procedure GetID */

/* 30 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 32 */	NdrFcLong( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x5 ),	/* 5 */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	NdrFcShort( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x4c ),	/* 76 */
/* 44 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 46 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */


	/* Parameter pResourceId */


	/* Parameter phid */

/* 54 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 56 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 58 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDbPath */

/* 66 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x6 ),	/* 6 */
/* 74 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 76 */	NdrFcShort( 0x8 ),	/* 8 */
/* 78 */	NdrFcShort( 0x8 ),	/* 8 */
/* 80 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 82 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 90 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 92 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 94 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Parameter bufferSize */

/* 96 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 98 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIDbPath */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x7 ),	/* 7 */
/* 116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 122 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 124 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 132 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 136 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Parameter bufferSize */

/* 138 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 146 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDbPathAndName */

/* 150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 164 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 166 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 174 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 176 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 178 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Parameter bufferSize */

/* 180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 182 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x9 ),	/* 9 */
/* 200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 206 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 208 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppName */

/* 216 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 220 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmExtVerHi */

/* 228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0xa ),	/* 10 */
/* 236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x22 ),	/* 34 */
/* 242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 244 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pExtVerHi */

/* 252 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 256 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNumMediaCopies */


	/* Procedure GetHsmExtVerLo */

/* 264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0xb ),	/* 11 */
/* 272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x22 ),	/* 34 */
/* 278 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 280 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNumMediaCopies */


	/* Parameter pExtVerLo */

/* 288 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 292 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmExtRev */

/* 300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0xc ),	/* 12 */
/* 308 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x22 ),	/* 34 */
/* 314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 316 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pExtRev */

/* 324 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 328 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAutosave */

/* 336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0xd ),	/* 13 */
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

	/* Parameter pMilliseconds */

/* 360 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAutosave */

/* 372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0xe ),	/* 14 */
/* 380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 386 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 388 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter milliseconds */

/* 396 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 398 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 404 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyFilesLimit */

/* 408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0xf ),	/* 15 */
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

	/* Parameter pLimit */

/* 432 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 434 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyFilesUserLimit */

/* 444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x10 ),	/* 16 */
/* 452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x24 ),	/* 36 */
/* 458 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLimit */

/* 468 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyFilesUserLimit */

/* 480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x11 ),	/* 17 */
/* 488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 494 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter limit */

/* 504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManagedResources */

/* 516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x12 ),	/* 18 */
/* 524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 530 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 532 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 540 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 542 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 544 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 548 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindHsmStoragePoolById */

/* 552 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x13 ),	/* 19 */
/* 560 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 562 */	NdrFcShort( 0x30 ),	/* 48 */
/* 564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 566 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 568 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter StoragePoolId */

/* 576 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 578 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 580 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter ppStoragePool */

/* 582 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 584 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 586 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 590 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindHsmStoragePoolByMediaSetId */

/* 594 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x14 ),	/* 20 */
/* 602 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 604 */	NdrFcShort( 0x30 ),	/* 48 */
/* 606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 608 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 610 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter RmsMediaSetId */

/* 618 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 620 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 622 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter ppStoragePool */

/* 624 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 626 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 628 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 630 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 632 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindMediaIdByDescription */

/* 636 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 638 */	NdrFcLong( 0x0 ),	/* 0 */
/* 642 */	NdrFcShort( 0x15 ),	/* 21 */
/* 644 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x4c ),	/* 76 */
/* 650 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 652 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter description */

/* 660 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 662 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 664 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter pMediaId */

/* 666 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 668 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 670 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 674 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindStoragePoolByName */

/* 678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x16 ),	/* 22 */
/* 686 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 692 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 694 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 702 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 704 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 706 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter ppStoragePool */

/* 708 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 710 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 712 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 716 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStoragePools */

/* 720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x17 ),	/* 23 */
/* 728 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 734 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 736 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 744 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 746 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 748 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 752 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOnlineInformation */

/* 756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x18 ),	/* 24 */
/* 764 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 772 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 780 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 784 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMessages */

/* 792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x19 ),	/* 25 */
/* 800 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x8 ),	/* 8 */
/* 806 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 808 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 816 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 820 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 824 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUsrToNotify */

/* 828 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0x1a ),	/* 26 */
/* 836 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 842 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 844 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 852 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 854 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 856 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindJobByName */

/* 864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x1b ),	/* 27 */
/* 872 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x8 ),	/* 8 */
/* 878 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 880 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 888 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 890 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 892 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter ppJob */

/* 894 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 896 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 898 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */

/* 900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 902 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJobs */

/* 906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x1c ),	/* 28 */
/* 914 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 920 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 922 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 930 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 932 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 934 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 938 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJobDefs */

/* 942 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 948 */	NdrFcShort( 0x1d ),	/* 29 */
/* 950 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x8 ),	/* 8 */
/* 956 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 958 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 966 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 968 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 970 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 974 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPolicies */

/* 978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0x1e ),	/* 30 */
/* 986 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 992 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 994 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1002 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1004 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1006 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1008 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1010 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActions */

/* 1014 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1016 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1020 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1022 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1026 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1028 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1030 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1038 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1040 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1042 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1046 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCriteria */

/* 1050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1058 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1064 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1066 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1074 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1076 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1078 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1082 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaRecs */

/* 1086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1094 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1100 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1102 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1110 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1112 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1114 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1116 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1118 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMountingMedias */

/* 1122 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1130 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1136 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1138 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1146 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1148 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1150 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1154 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LockMountingMedias */

/* 1158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1166 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1172 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1174 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1182 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1184 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnlockMountingMedias */

/* 1188 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1190 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1196 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1202 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1204 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1210 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1212 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1214 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNextMedia */

/* 1218 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1220 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1224 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1226 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1230 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1232 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1234 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1240 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNextMedia */

/* 1242 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1244 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1250 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSegmentDb */

/* 1254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1262 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1268 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1270 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppDb */

/* 1278 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1280 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1282 */	NdrFcShort( 0x6e ),	/* Type Offset=110 */

	/* Return value */

/* 1284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1286 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BackupSegmentDb */

/* 1290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1298 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1304 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1306 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1316 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmFsaTskMgr */

/* 1320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1328 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1334 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1336 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppHsmTskMgr */

/* 1344 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1348 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 1350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveMetaData */

/* 1356 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1364 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1370 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1372 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1382 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SavePersistData */

/* 1386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1394 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1400 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1402 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CloseOutDb */

/* 1416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1422 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1424 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1430 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1432 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1438 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1442 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelAllJobs */

/* 1446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1454 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1460 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1462 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1472 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AreJobsEnabled */

/* 1476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1490 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1492 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1502 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnableAllJobs */

/* 1506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1514 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1520 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1522 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1528 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1532 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisableAllJobs */

/* 1536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1542 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1544 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1548 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1550 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1552 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1558 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1562 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RestartSuspendedJobs */

/* 1566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1572 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1574 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1580 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1582 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateTask */

/* 1596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1604 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1606 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1610 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1612 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter jobName */

/* 1620 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1622 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1624 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobParameters */

/* 1626 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1628 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1630 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobComments */

/* 1632 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1634 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1636 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobTriggerType */

/* 1638 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1640 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1642 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter jobStartHour */

/* 1644 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1646 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1648 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter jobStartMinute */

/* 1650 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1652 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1654 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter scheduledJob */

/* 1656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1658 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1664 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateTaskEx */

/* 1668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1676 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1678 */	NdrFcShort( 0x36 ),	/* 54 */
/* 1680 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1682 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1684 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1690 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter jobName */

/* 1692 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1694 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1696 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobParameters */

/* 1698 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1700 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1702 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobComments */

/* 1704 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1706 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1708 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobTriggerType */

/* 1710 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1712 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1714 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter runTime */

/* 1716 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1718 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1720 */	NdrFcShort( 0x9a ),	/* Type Offset=154 */

	/* Parameter runOccurrence */

/* 1722 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1724 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1726 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter scheduledJob */

/* 1728 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1730 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelCopyMedia */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x33 ),	/* 51 */
/* 1748 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1754 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1756 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1764 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1766 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarkMediaForRecreation */

/* 1770 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1776 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1778 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1780 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1782 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1784 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1786 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter masterMediaId */

/* 1794 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1796 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1798 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 1800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1802 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RecreateMaster */

/* 1806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1812 */	NdrFcShort( 0x35 ),	/* 53 */
/* 1814 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1816 */	NdrFcShort( 0x4a ),	/* 74 */
/* 1818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1820 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1822 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter masterMediaId */

/* 1830 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1832 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1834 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter copySet */

/* 1836 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1838 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1840 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1844 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SynchronizeMedia */

/* 1848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x36 ),	/* 54 */
/* 1856 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1858 */	NdrFcShort( 0x36 ),	/* 54 */
/* 1860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1862 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1864 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter poolId */

/* 1872 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1874 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1876 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter copySet */

/* 1878 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1880 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1882 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1884 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1886 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmMediaMgr */

/* 1890 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x37 ),	/* 55 */
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

	/* Parameter ppHsmMediaMgr */

/* 1914 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1918 */	NdrFcShort( 0xac ),	/* Type Offset=172 */

	/* Return value */

/* 1920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetSegmentValidMark */

/* 1926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x38 ),	/* 56 */
/* 1934 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1940 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1942 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1950 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1952 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1954 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetMediaValidBytes */

/* 1956 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1958 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1962 */	NdrFcShort( 0x39 ),	/* 57 */
/* 1964 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1968 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1970 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1972 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1978 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1980 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1982 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSegmentPosition */

/* 1986 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1988 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0x3a ),	/* 58 */
/* 1994 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1996 */	NdrFcShort( 0x64 ),	/* 100 */
/* 1998 */	NdrFcShort( 0x70 ),	/* 112 */
/* 2000 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 2002 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2008 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bagId */

/* 2010 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2012 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2014 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter fileStart */

/* 2016 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2018 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2020 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter fileSize */

/* 2022 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2024 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2026 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPosMedia */

/* 2028 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2030 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2032 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pPosOfffset */

/* 2034 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2036 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2038 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2040 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2042 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2044 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateMediaSizeLimit */

/* 2046 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2048 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0x3b ),	/* 59 */
/* 2054 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2058 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2060 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2062 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNewLimit */

/* 2070 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2072 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2076 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2078 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 2082 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2084 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2088 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2090 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2094 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2096 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2098 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2104 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppHsmMediaMgr */

/* 2106 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2108 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2110 */	NdrFcShort( 0xb0 ),	/* Type Offset=176 */

	/* Return value */

/* 2112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2114 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetId */


	/* Procedure SetResourceId */

/* 2118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2126 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2128 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2132 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2134 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Id */


	/* Parameter resourceId */

/* 2142 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2144 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2146 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */


	/* Return value */

/* 2148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2150 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitFromFsaResource */

/* 2154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2162 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2168 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2170 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsa */

/* 2178 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2180 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2182 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Return value */

/* 2184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2186 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFsaResource */

/* 2190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2196 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2198 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2204 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2206 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2212 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFsa */

/* 2214 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2216 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2218 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Return value */

/* 2220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2222 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIHsmManagedResource */

/* 2226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2234 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2240 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2242 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pHsmManagedResource */

/* 2250 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2252 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2254 */	NdrFcShort( 0xdc ),	/* Type Offset=220 */

	/* Parameter psResult */

/* 2256 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2258 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2260 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2262 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2264 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteAllAndRelease */

/* 2268 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2270 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2274 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2276 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2280 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2282 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2284 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2290 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2292 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2294 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSet */

/* 2298 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2304 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2306 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2310 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2312 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2314 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2316 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaSetId */

/* 2322 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2324 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2326 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pMediaSetName */

/* 2328 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2330 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2332 */	NdrFcShort( 0x10c ),	/* Type Offset=268 */

	/* Return value */

/* 2334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2336 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaSet */

/* 2340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2348 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2350 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2354 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2356 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaSetId */

/* 2364 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2366 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2368 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter mediaSetName */

/* 2370 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2372 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2374 */	NdrFcShort( 0x11a ),	/* Type Offset=282 */

	/* Return value */

/* 2376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2378 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNumOnlineMedia */

/* 2382 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2388 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2390 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2394 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2396 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2398 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2404 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNumOnlineMedia */

/* 2406 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2408 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2414 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNumOnlineMedia */

/* 2418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2424 */	NdrFcShort( 0xa ),	/* 10 */
/* 2426 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2432 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2434 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter numOnlineMedia */

/* 2442 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2444 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2450 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNumMediaCopies */

/* 2454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2460 */	NdrFcShort( 0xc ),	/* 12 */
/* 2462 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2464 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2466 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2468 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2470 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2476 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter numMediaCopies */

/* 2478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2480 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2482 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2486 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManagementPolicy */

/* 2490 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0xd ),	/* 13 */
/* 2498 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2502 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2504 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2506 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2512 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pManagementPolicyId */

/* 2514 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2518 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetManagementPolicy */

/* 2526 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2532 */	NdrFcShort( 0xe ),	/* 14 */
/* 2534 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2536 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2540 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2542 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2548 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter managementPolicyId */

/* 2550 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2552 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2554 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2556 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2558 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitFromRmsMediaSet */

/* 2562 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2564 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2568 */	NdrFcShort( 0xf ),	/* 15 */
/* 2570 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2576 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2578 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2584 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRmsMediaSet */

/* 2586 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2588 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2590 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Return value */

/* 2592 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2594 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRmsMediaSet */

/* 2598 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2604 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2606 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2612 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2614 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2620 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppRmsMediaSet */

/* 2622 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2624 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2626 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Return value */

/* 2628 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2630 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIHsmStoragePool */

/* 2634 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2636 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2640 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2642 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2646 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2648 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2650 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2656 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pHsmStoragePool */

/* 2658 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2660 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2662 */	NdrFcShort( 0x124 ),	/* Type Offset=292 */

	/* Parameter psResult */

/* 2664 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2666 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2668 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2670 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2672 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSetType */

/* 2676 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2678 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2682 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2684 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2690 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2692 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2698 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaType */

/* 2700 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2702 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2704 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2706 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2708 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 2712 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2714 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2718 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2720 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2722 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2724 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2726 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2728 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2734 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 2736 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2738 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2740 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter readOnly */

/* 2742 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2744 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2748 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2750 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaId */

/* 2754 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2756 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2760 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2762 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2766 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2768 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2770 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2776 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaId */

/* 2778 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2780 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2782 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2784 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2786 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2788 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaId */

/* 2790 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2792 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2796 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2798 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2800 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2802 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2804 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2806 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2812 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 2814 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2816 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2818 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2820 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2822 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WaitForMount */

/* 2826 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2828 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2832 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2834 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2840 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2842 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2848 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter timeout */

/* 2850 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2852 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2856 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2858 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MountDone */

/* 2862 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2864 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2868 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2870 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2876 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2878 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2884 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2888 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsReadOnly */

/* 2892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2900 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2904 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2906 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2908 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter readOnly */

/* 2916 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2918 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2922 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2924 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2926 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsReadOnly */

/* 2928 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2930 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2934 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2936 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2942 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2944 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2950 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2952 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2954 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2956 */	0x8,		/* FC_LONG */
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
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x8 ),	/* Offset= 8 (12) */
/*  6 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 12 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 14 */	NdrFcShort( 0x10 ),	/* 16 */
/* 16 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 18 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 20 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (6) */
			0x5b,		/* FC_END */
/* 24 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 26 */	NdrFcShort( 0x2 ),	/* Offset= 2 (28) */
/* 28 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 30 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 32 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 34 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 36 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 38 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 40 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 42 */	NdrFcShort( 0x2 ),	/* Offset= 2 (44) */
/* 44 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 46 */	NdrFcLong( 0xa5b69200 ),	/* -1514761728 */
/* 50 */	NdrFcShort( 0x214b ),	/* 8523 */
/* 52 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 54 */	0x81,		/* 129 */
			0xb7,		/* 183 */
/* 56 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 58 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 60 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 62 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 64 */	NdrFcShort( 0x2 ),	/* Offset= 2 (66) */
/* 66 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 68 */	NdrFcLong( 0xdd529292 ),	/* -581791086 */
/* 72 */	NdrFcShort( 0x3892 ),	/* 14482 */
/* 74 */	NdrFcShort( 0x47a4 ),	/* 18340 */
/* 76 */	0xb0,		/* 176 */
			0x16,		/* 22 */
/* 78 */	0xc7,		/* 199 */
			0x52,		/* 82 */
/* 80 */	0xa5,		/* 165 */
			0xc,		/* 12 */
/* 82 */	0xfc,		/* 252 */
			0x29,		/* 41 */
/* 84 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 86 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 88 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 90 */	NdrFcShort( 0x2 ),	/* Offset= 2 (92) */
/* 92 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 94 */	NdrFcLong( 0x2a87c7e2 ),	/* 713541602 */
/* 98 */	NdrFcShort( 0xdb24 ),	/* -9436 */
/* 100 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 102 */	0xaf,		/* 175 */
			0xa2,		/* 162 */
/* 104 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 106 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 108 */	0x37,		/* 55 */
			0x58,		/* 88 */
/* 110 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 112 */	NdrFcShort( 0x2 ),	/* Offset= 2 (114) */
/* 114 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 116 */	NdrFcLong( 0xd7a42f4a ),	/* -677105846 */
/* 120 */	NdrFcShort( 0x117c ),	/* 4476 */
/* 122 */	NdrFcShort( 0x47a3 ),	/* 18339 */
/* 124 */	0x9c,		/* 156 */
			0x30,		/* 48 */
/* 126 */	0x92,		/* 146 */
			0xd6,		/* 214 */
/* 128 */	0x3a,		/* 58 */
			0x49,		/* 73 */
/* 130 */	0x19,		/* 25 */
			0xe4,		/* 228 */
/* 132 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 134 */	NdrFcShort( 0x2 ),	/* Offset= 2 (136) */
/* 136 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 138 */	NdrFcLong( 0x14f73fcb ),	/* 351748043 */
/* 142 */	NdrFcShort( 0x517d ),	/* 20861 */
/* 144 */	NdrFcShort( 0x4503 ),	/* 17667 */
/* 146 */	0xb1,		/* 177 */
			0x5d,		/* 93 */
/* 148 */	0x2d,		/* 45 */
			0x40,		/* 64 */
/* 150 */	0xb3,		/* 179 */
			0xe9,		/* 233 */
/* 152 */	0xcd,		/* 205 */
			0x21,		/* 33 */
/* 154 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 156 */	NdrFcShort( 0x10 ),	/* 16 */
/* 158 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 160 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 162 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 164 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 166 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 168 */	
			0x11, 0x0,	/* FC_RP */
/* 170 */	NdrFcShort( 0xff62 ),	/* Offset= -158 (12) */
/* 172 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 174 */	NdrFcShort( 0x2 ),	/* Offset= 2 (176) */
/* 176 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 178 */	NdrFcLong( 0xdda2fbe0 ),	/* -576521248 */
/* 182 */	NdrFcShort( 0x33e4 ),	/* 13284 */
/* 184 */	NdrFcShort( 0x4221 ),	/* 16929 */
/* 186 */	0xa2,		/* 162 */
			0xc8,		/* 200 */
/* 188 */	0xd9,		/* 217 */
			0x7,		/* 7 */
/* 190 */	0x11,		/* 17 */
			0x3,		/* 3 */
/* 192 */	0x97,		/* 151 */
			0xea,		/* 234 */
/* 194 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 196 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 198 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 210 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 212 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 214 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 216 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 218 */	NdrFcShort( 0xffec ),	/* Offset= -20 (198) */
/* 220 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 222 */	NdrFcLong( 0xba365110 ),	/* -1170845424 */
/* 226 */	NdrFcShort( 0x6d66 ),	/* 28006 */
/* 228 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 230 */	0x9e,		/* 158 */
			0x2e,		/* 46 */
/* 232 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 234 */	0xc9,		/* 201 */
			0x16,		/* 22 */
/* 236 */	0xf1,		/* 241 */
			0x20,		/* 32 */
/* 238 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 240 */	NdrFcShort( 0x1c ),	/* Offset= 28 (268) */
/* 242 */	
			0x13, 0x0,	/* FC_OP */
/* 244 */	NdrFcShort( 0xe ),	/* Offset= 14 (258) */
/* 246 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 248 */	NdrFcShort( 0x2 ),	/* 2 */
/* 250 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 252 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 254 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 256 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 258 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 262 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (246) */
/* 264 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 266 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 268 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x4 ),	/* 4 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0xffde ),	/* Offset= -34 (242) */
/* 278 */	
			0x12, 0x0,	/* FC_UP */
/* 280 */	NdrFcShort( 0xffea ),	/* Offset= -22 (258) */
/* 282 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x4 ),	/* 4 */
/* 288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (278) */
/* 292 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 294 */	NdrFcLong( 0xdd529292 ),	/* -581791086 */
/* 298 */	NdrFcShort( 0x3892 ),	/* 14482 */
/* 300 */	NdrFcShort( 0x47a4 ),	/* 18340 */
/* 302 */	0xb0,		/* 176 */
			0x16,		/* 22 */
/* 304 */	0xc7,		/* 199 */
			0x52,		/* 82 */
/* 306 */	0xa5,		/* 165 */
			0xc,		/* 12 */
/* 308 */	0xfc,		/* 252 */
			0x29,		/* 41 */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Standard interface: __MIDL_itf_hsmeng_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IHsmSystemState, ver. 0.0,
   GUID={0x3F0DA041,0x69F1,0x11d2,{0xAF,0x82,0x00,0x10,0x4B,0x9A,0x37,0x58}} */


/* Object interface: IHsmServer, ver. 0.0,
   GUID={0xE372F85B,0xD72B,0x4A7D,{0xB0,0xF6,0x2B,0xCF,0x8F,0xED,0x88,0xB9}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmServer_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    0,
    30,
    66,
    108,
    150,
    192,
    228,
    264,
    300,
    336,
    372,
    408,
    444,
    480,
    516,
    552,
    594,
    636,
    678,
    720,
    756,
    792,
    828,
    864,
    906,
    942,
    978,
    1014,
    1050,
    1086,
    1122,
    1158,
    1188,
    1218,
    1254,
    1290,
    1320,
    1356,
    1386,
    1416,
    1446,
    1476,
    1506,
    1536,
    1566,
    1596,
    1668,
    1740,
    1770,
    1806,
    1848,
    1890,
    1926,
    1956,
    1986,
    2046
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(60) _IHsmServerProxyVtbl = 
{
    &IHsmServer_ProxyInfo,
    &IID_IHsmServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::Init */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetID */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetDbPath */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetIDbPath */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetDbPathAndName */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetHsmExtVerHi */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetHsmExtVerLo */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetHsmExtRev */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetAutosave */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::SetAutosave */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetCopyFilesLimit */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetCopyFilesUserLimit */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::SetCopyFilesUserLimit */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetManagedResources */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::FindHsmStoragePoolById */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::FindHsmStoragePoolByMediaSetId */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::FindMediaIdByDescription */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::FindStoragePoolByName */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetStoragePools */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetOnlineInformation */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetMessages */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetUsrToNotify */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::FindJobByName */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetJobs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetJobDefs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetPolicies */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetActions */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetCriteria */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetMediaRecs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetMountingMedias */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::LockMountingMedias */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::UnlockMountingMedias */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetNextMedia */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetSegmentDb */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::BackupSegmentDb */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetHsmFsaTskMgr */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::SaveMetaData */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::SavePersistData */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::CloseOutDb */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::CancelAllJobs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::AreJobsEnabled */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::EnableAllJobs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::DisableAllJobs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::RestartSuspendedJobs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::CreateTask */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::CreateTaskEx */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::CancelCopyMedia */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::MarkMediaForRecreation */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::RecreateMaster */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::SynchronizeMedia */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetHsmMediaMgr */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::ResetSegmentValidMark */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::ResetMediaValidBytes */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetSegmentPosition */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::UpdateMediaSizeLimit */
};


static const PRPC_STUB_FUNCTION IHsmServer_table[] =
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

CInterfaceStubVtbl _IHsmServerStubVtbl =
{
    &IID_IHsmServer,
    &IHsmServer_ServerInfo,
    60,
    &IHsmServer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHsmUpgradeRmsDb, ver. 0.0,
   GUID={0xB04E802A,0x8D06,0x46BE,{0x89,0x30,0x2A,0xA2,0xDA,0x4C,0x0D,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmUpgradeRmsDb_FormatStringOffsetTable[] =
    {
    2082
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmUpgradeRmsDb_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmUpgradeRmsDb_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmUpgradeRmsDb_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmUpgradeRmsDb_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmUpgradeRmsDbProxyVtbl = 
{
    &IHsmUpgradeRmsDb_ProxyInfo,
    &IID_IHsmUpgradeRmsDb,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmUpgradeRmsDb::Init */
};

const CInterfaceStubVtbl _IHsmUpgradeRmsDbStubVtbl =
{
    &IID_IHsmUpgradeRmsDb,
    &IHsmUpgradeRmsDb_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbCollectable, ver. 0.0,
   GUID={0x9C7D6F0A,0x1562,0x11D0,{0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */


/* Object interface: IHsmManagedResource, ver. 0.0,
   GUID={0xBA365110,0x6D66,0x11d0,{0x9E,0x2E,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmManagedResource_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    30,
    2118,
    2154,
    2190,
    2226
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmManagedResource_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmManagedResource_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmManagedResource_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmManagedResource_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IHsmManagedResourceProxyVtbl = 
{
    &IHsmManagedResource_ProxyInfo,
    &IID_IHsmManagedResource,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbCollectable::CompareTo */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbCollectable::IsEqual */ ,
    (void *) (INT_PTR) -1 /* IHsmManagedResource::GetResourceId */ ,
    (void *) (INT_PTR) -1 /* IHsmManagedResource::SetResourceId */ ,
    (void *) (INT_PTR) -1 /* IHsmManagedResource::InitFromFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmManagedResource::GetFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmManagedResource::CompareToIHsmManagedResource */
};


static const PRPC_STUB_FUNCTION IHsmManagedResource_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IHsmManagedResourceStubVtbl =
{
    &IID_IHsmManagedResource,
    &IHsmManagedResource_ServerInfo,
    10,
    &IHsmManagedResource_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHsmManagedResourceCollection, ver. 0.0,
   GUID={0xAAA2ABF1,0xE5CF,0x11d1,{0x99,0x74,0x00,0x60,0x97,0x6A,0x54,0x6D}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmManagedResourceCollection_FormatStringOffsetTable[] =
    {
    2268
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmManagedResourceCollection_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmManagedResourceCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmManagedResourceCollection_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmManagedResourceCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmManagedResourceCollectionProxyVtbl = 
{
    &IHsmManagedResourceCollection_ProxyInfo,
    &IID_IHsmManagedResourceCollection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmManagedResourceCollection::DeleteAllAndRelease */
};

const CInterfaceStubVtbl _IHsmManagedResourceCollectionStubVtbl =
{
    &IID_IHsmManagedResourceCollection,
    &IHsmManagedResourceCollection_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmStoragePool, ver. 0.0,
   GUID={0xDD529292,0x3892,0x47A4,{0xB0,0x16,0xC7,0x52,0xA5,0x0C,0xFC,0x29}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmStoragePool_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    30,
    2118,
    2298,
    2340,
    2382,
    2418,
    264,
    2454,
    2490,
    2526,
    2562,
    2598,
    2634,
    2676
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmStoragePool_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmStoragePool_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmStoragePool_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmStoragePool_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IHsmStoragePoolProxyVtbl = 
{
    &IHsmStoragePool_ProxyInfo,
    &IID_IHsmStoragePool,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbCollectable::CompareTo */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbCollectable::IsEqual */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetId */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::SetId */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetMediaSet */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::SetMediaSet */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetNumOnlineMedia */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::SetNumOnlineMedia */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetNumMediaCopies */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::SetNumMediaCopies */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetManagementPolicy */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::SetManagementPolicy */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::InitFromRmsMediaSet */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetRmsMediaSet */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::CompareToIHsmStoragePool */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetMediaSetType */
};


static const PRPC_STUB_FUNCTION IHsmStoragePool_table[] =
{
    STUB_FORWARDING_FUNCTION,
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
    NdrStubCall2
};

CInterfaceStubVtbl _IHsmStoragePoolStubVtbl =
{
    &IID_IHsmStoragePool,
    &IHsmStoragePool_ServerInfo,
    19,
    &IHsmStoragePool_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMountingMedia, ver. 0.0,
   GUID={0x38E504D8,0xCBC5,0x4701,{0xBA,0xC5,0xD4,0xF8,0x5B,0x45,0xFC,0x79}} */

#pragma code_seg(".orpc")
static const unsigned short IMountingMedia_FormatStringOffsetTable[] =
    {
    2712,
    2754,
    2790,
    2826,
    2862,
    2892,
    2928
    };

static const MIDL_STUBLESS_PROXY_INFO IMountingMedia_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IMountingMedia_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMountingMedia_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IMountingMedia_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IMountingMediaProxyVtbl = 
{
    &IMountingMedia_ProxyInfo,
    &IID_IMountingMedia,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IMountingMedia::Init */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::GetMediaId */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::SetMediaId */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::WaitForMount */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::MountDone */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::SetIsReadOnly */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::IsReadOnly */
};

const CInterfaceStubVtbl _IMountingMediaStubVtbl =
{
    &IID_IMountingMedia,
    &IMountingMedia_ServerInfo,
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
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _hsmeng_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IHsmManagedResourceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmUpgradeRmsDbProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmServerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmStoragePoolProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMountingMediaProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmManagedResourceCollectionProxyVtbl,
    0
};

const CInterfaceStubVtbl * _hsmeng_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IHsmManagedResourceStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmUpgradeRmsDbStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmServerStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmStoragePoolStubVtbl,
    ( CInterfaceStubVtbl *) &_IMountingMediaStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmManagedResourceCollectionStubVtbl,
    0
};

PCInterfaceName const _hsmeng_InterfaceNamesList[] = 
{
    "IHsmManagedResource",
    "IHsmUpgradeRmsDb",
    "IHsmServer",
    "IHsmStoragePool",
    "IMountingMedia",
    "IHsmManagedResourceCollection",
    0
};

const IID *  _hsmeng_BaseIIDList[] = 
{
    &IID_IWsbCollectable,
    0,
    &IID_IHsmSystemState,
    &IID_IWsbCollectable,
    0,
    0,
    0
};


#define _hsmeng_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _hsmeng, pIID, n)

int __stdcall _hsmeng_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _hsmeng, 6, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _hsmeng, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _hsmeng, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _hsmeng, 6, *pIndex )
    
}

const ExtendedProxyFileInfo hsmeng_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _hsmeng_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _hsmeng_StubVtblList,
    (const PCInterfaceName * ) & _hsmeng_InterfaceNamesList,
    (const IID ** ) & _hsmeng_BaseIIDList,
    & _hsmeng_IID_Lookup, 
    6,
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
/* Compiler settings for hsmeng.idl:
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


#include "hsmeng.h"

#define TYPE_FORMAT_STRING_SIZE   311                               
#define PROC_FORMAT_STRING_SIZE   3119                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

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


extern const MIDL_SERVER_INFO IHsmServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmUpgradeRmsDb_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmUpgradeRmsDb_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmManagedResource_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmManagedResource_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmManagedResourceCollection_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmManagedResourceCollection_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmStoragePool_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmStoragePool_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMountingMedia_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMountingMedia_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Init */

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

	/* Procedure GetId */


	/* Procedure GetResourceId */


	/* Procedure GetID */

/* 32 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 34 */	NdrFcLong( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0x5 ),	/* 5 */
/* 40 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x4c ),	/* 76 */
/* 46 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 48 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */


	/* Parameter pResourceId */


	/* Parameter phid */

/* 58 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 60 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 62 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 64 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 66 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 68 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDbPath */

/* 70 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 72 */	NdrFcLong( 0x0 ),	/* 0 */
/* 76 */	NdrFcShort( 0x6 ),	/* 6 */
/* 78 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 80 */	NdrFcShort( 0x8 ),	/* 8 */
/* 82 */	NdrFcShort( 0x8 ),	/* 8 */
/* 84 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 86 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 96 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 98 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 100 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Parameter bufferSize */

/* 102 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 104 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIDbPath */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x7 ),	/* 7 */
/* 122 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 128 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 130 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 140 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 142 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 144 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Parameter bufferSize */

/* 146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 148 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 154 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDbPathAndName */

/* 158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 166 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 172 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 174 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 184 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 186 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 188 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Parameter bufferSize */

/* 190 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 192 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 198 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x9 ),	/* 9 */
/* 210 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 216 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 218 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppName */

/* 228 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 230 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 232 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmExtVerHi */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0xa ),	/* 10 */
/* 248 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x22 ),	/* 34 */
/* 254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 256 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pExtVerHi */

/* 266 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 268 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 270 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 274 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNumMediaCopies */


	/* Procedure GetHsmExtVerLo */

/* 278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0xb ),	/* 11 */
/* 286 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0x22 ),	/* 34 */
/* 292 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 294 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNumMediaCopies */


	/* Parameter pExtVerLo */

/* 304 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 306 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 308 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 312 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmExtRev */

/* 316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0xc ),	/* 12 */
/* 324 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x22 ),	/* 34 */
/* 330 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 332 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pExtRev */

/* 342 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 344 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 346 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAutosave */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0xd ),	/* 13 */
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

	/* Parameter pMilliseconds */

/* 380 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 382 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 388 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAutosave */

/* 392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0xe ),	/* 14 */
/* 400 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 406 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 408 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter milliseconds */

/* 418 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 420 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 424 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 426 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyFilesLimit */

/* 430 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0xf ),	/* 15 */
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

	/* Parameter pLimit */

/* 456 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 458 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 464 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyFilesUserLimit */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x10 ),	/* 16 */
/* 476 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x24 ),	/* 36 */
/* 482 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 484 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLimit */

/* 494 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 496 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 502 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyFilesUserLimit */

/* 506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x11 ),	/* 17 */
/* 514 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 520 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 522 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter limit */

/* 532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 534 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 540 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManagedResources */

/* 544 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x12 ),	/* 18 */
/* 552 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x8 ),	/* 8 */
/* 558 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 560 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 570 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 572 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 574 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 578 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindHsmStoragePoolById */

/* 582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x13 ),	/* 19 */
/* 590 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 592 */	NdrFcShort( 0x30 ),	/* 48 */
/* 594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 596 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 598 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter StoragePoolId */

/* 608 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 610 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 612 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter ppStoragePool */

/* 614 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 616 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 618 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 620 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 622 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindHsmStoragePoolByMediaSetId */

/* 626 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x14 ),	/* 20 */
/* 634 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 636 */	NdrFcShort( 0x30 ),	/* 48 */
/* 638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 640 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 642 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter RmsMediaSetId */

/* 652 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 654 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 656 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter ppStoragePool */

/* 658 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 660 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 662 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 664 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 666 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindMediaIdByDescription */

/* 670 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 672 */	NdrFcLong( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x15 ),	/* 21 */
/* 678 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x4c ),	/* 76 */
/* 684 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 686 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter description */

/* 696 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 698 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 700 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter pMediaId */

/* 702 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 704 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 706 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 710 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindStoragePoolByName */

/* 714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0x16 ),	/* 22 */
/* 722 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 728 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 730 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 740 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 742 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 744 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter ppStoragePool */

/* 746 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 748 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 750 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 754 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStoragePools */

/* 758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 764 */	NdrFcShort( 0x17 ),	/* 23 */
/* 766 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 772 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 774 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 784 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 786 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 788 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 790 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 792 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOnlineInformation */

/* 796 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 798 */	NdrFcLong( 0x0 ),	/* 0 */
/* 802 */	NdrFcShort( 0x18 ),	/* 24 */
/* 804 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 810 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 812 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 822 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 824 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 826 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 830 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMessages */

/* 834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x19 ),	/* 25 */
/* 842 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 848 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 850 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 860 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 862 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 864 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 866 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 868 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUsrToNotify */

/* 872 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 874 */	NdrFcLong( 0x0 ),	/* 0 */
/* 878 */	NdrFcShort( 0x1a ),	/* 26 */
/* 880 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 886 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 888 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 898 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 900 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 902 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 904 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 906 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindJobByName */

/* 910 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 912 */	NdrFcLong( 0x0 ),	/* 0 */
/* 916 */	NdrFcShort( 0x1b ),	/* 27 */
/* 918 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x8 ),	/* 8 */
/* 924 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 926 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 936 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 938 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 940 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter ppJob */

/* 942 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 944 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 946 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */

/* 948 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 950 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJobs */

/* 954 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x1c ),	/* 28 */
/* 962 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 968 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 970 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 980 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 982 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 984 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 986 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 988 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJobDefs */

/* 992 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1000 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1006 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1008 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1018 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1020 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1022 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1024 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1026 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPolicies */

/* 1030 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1038 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1044 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1046 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1056 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1058 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1060 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1064 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActions */

/* 1068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1076 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1082 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1084 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1094 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1096 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1098 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1102 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCriteria */

/* 1106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1112 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1114 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1120 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1122 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1132 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1134 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1136 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1140 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaRecs */

/* 1144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1150 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1152 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1158 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1160 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1170 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1172 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1174 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1178 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMountingMedias */

/* 1182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1190 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1196 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1198 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCollection */

/* 1208 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1210 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1212 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1214 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1216 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LockMountingMedias */

/* 1220 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1228 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1232 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1234 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1236 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1244 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1248 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnlockMountingMedias */

/* 1252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1258 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1260 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1268 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNextMedia */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1292 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1298 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1300 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNextMedia */

/* 1310 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1312 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1318 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSegmentDb */

/* 1322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1328 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1330 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1336 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1338 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppDb */

/* 1348 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1350 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1352 */	NdrFcShort( 0x6e ),	/* Type Offset=110 */

	/* Return value */

/* 1354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1356 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BackupSegmentDb */

/* 1360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1366 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1368 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1376 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1388 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmFsaTskMgr */

/* 1392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1400 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1406 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1408 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppHsmTskMgr */

/* 1418 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1420 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1422 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 1424 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1426 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveMetaData */

/* 1430 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1436 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1438 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1442 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1444 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1446 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1458 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SavePersistData */

/* 1462 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1468 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1470 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1474 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1476 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1478 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1490 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CloseOutDb */

/* 1494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1502 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1506 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1508 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1510 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1522 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelAllJobs */

/* 1526 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1532 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1534 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1540 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1542 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1552 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1554 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AreJobsEnabled */

/* 1558 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1564 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1566 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1572 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1574 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1586 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnableAllJobs */

/* 1590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1598 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1604 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1606 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1616 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1618 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisableAllJobs */

/* 1622 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1628 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1630 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1634 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1636 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1638 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1650 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RestartSuspendedJobs */

/* 1654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1660 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1662 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1666 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1668 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1670 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1678 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1682 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateTask */

/* 1686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1692 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1694 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 1696 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1700 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1702 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter jobName */

/* 1712 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1714 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1716 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobParameters */

/* 1718 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1720 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1722 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobComments */

/* 1724 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1726 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1728 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobTriggerType */

/* 1730 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1732 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1734 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter jobStartHour */

/* 1736 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1738 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1740 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter jobStartMinute */

/* 1742 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1744 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1746 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter scheduledJob */

/* 1748 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1750 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1756 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateTaskEx */

/* 1760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1766 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1768 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 1770 */	NdrFcShort( 0x36 ),	/* 54 */
/* 1772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1774 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1776 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter jobName */

/* 1786 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1788 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1790 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobParameters */

/* 1792 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1794 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1796 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobComments */

/* 1798 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1800 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1802 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter jobTriggerType */

/* 1804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1806 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1808 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter runTime */

/* 1810 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1812 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1814 */	NdrFcShort( 0x9a ),	/* Type Offset=154 */

	/* Parameter runOccurrence */

/* 1816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1818 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter scheduledJob */

/* 1822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1824 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1830 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 1832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelCopyMedia */

/* 1834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x33 ),	/* 51 */
/* 1842 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1848 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1850 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1858 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1860 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1862 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarkMediaForRecreation */

/* 1866 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1868 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1874 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1876 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1878 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1880 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1882 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter masterMediaId */

/* 1892 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1894 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1896 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 1898 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1900 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RecreateMaster */

/* 1904 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1906 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1910 */	NdrFcShort( 0x35 ),	/* 53 */
/* 1912 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1914 */	NdrFcShort( 0x4a ),	/* 74 */
/* 1916 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1918 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1920 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter masterMediaId */

/* 1930 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1932 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1934 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter copySet */

/* 1936 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1938 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1940 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1944 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SynchronizeMedia */

/* 1948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1954 */	NdrFcShort( 0x36 ),	/* 54 */
/* 1956 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1958 */	NdrFcShort( 0x36 ),	/* 54 */
/* 1960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1962 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1964 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter poolId */

/* 1974 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1976 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1978 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter copySet */

/* 1980 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1982 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1984 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1986 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1988 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmMediaMgr */

/* 1992 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1998 */	NdrFcShort( 0x37 ),	/* 55 */
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

	/* Parameter ppHsmMediaMgr */

/* 2018 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2020 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2022 */	NdrFcShort( 0xac ),	/* Type Offset=172 */

	/* Return value */

/* 2024 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2026 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetSegmentValidMark */

/* 2030 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2036 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2038 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2044 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2046 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2058 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetMediaValidBytes */

/* 2062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x39 ),	/* 57 */
/* 2070 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2076 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2078 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2086 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2090 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSegmentPosition */

/* 2094 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2100 */	NdrFcShort( 0x3a ),	/* 58 */
/* 2102 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2104 */	NdrFcShort( 0x64 ),	/* 100 */
/* 2106 */	NdrFcShort( 0x70 ),	/* 112 */
/* 2108 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 2110 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bagId */

/* 2120 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2122 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2124 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter fileStart */

/* 2126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2128 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2130 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter fileSize */

/* 2132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2134 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2136 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPosMedia */

/* 2138 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2140 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2142 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pPosOfffset */

/* 2144 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2146 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2148 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2152 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateMediaSizeLimit */

/* 2156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2162 */	NdrFcShort( 0x3b ),	/* 59 */
/* 2164 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2168 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2170 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2172 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNewLimit */

/* 2182 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2184 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2190 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 2194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2200 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2202 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2208 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2210 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppHsmMediaMgr */

/* 2220 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2222 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2224 */	NdrFcShort( 0xb0 ),	/* Type Offset=176 */

	/* Return value */

/* 2226 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2228 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetId */


	/* Procedure SetResourceId */

/* 2232 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2240 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2242 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2244 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2246 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2248 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Id */


	/* Parameter resourceId */

/* 2258 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2260 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2262 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */


	/* Return value */

/* 2264 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2266 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitFromFsaResource */

/* 2270 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2272 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2276 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2278 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2284 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2286 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2294 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFsa */

/* 2296 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2298 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2300 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Return value */

/* 2302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2304 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFsaResource */

/* 2308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2314 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2316 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2322 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2324 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2332 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFsa */

/* 2334 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2336 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2338 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Return value */

/* 2340 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2342 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIHsmManagedResource */

/* 2346 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2348 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2352 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2354 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2358 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2360 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2362 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pHsmManagedResource */

/* 2372 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2374 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2376 */	NdrFcShort( 0xdc ),	/* Type Offset=220 */

	/* Parameter psResult */

/* 2378 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2380 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2382 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2386 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteAllAndRelease */

/* 2390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2396 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2398 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2404 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2406 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2418 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSet */

/* 2422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2428 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2430 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2434 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2436 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2438 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2440 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2446 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaSetId */

/* 2448 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2450 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2452 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pMediaSetName */

/* 2454 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2456 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2458 */	NdrFcShort( 0x10c ),	/* Type Offset=268 */

	/* Return value */

/* 2460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2462 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaSet */

/* 2466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2472 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2474 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2476 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2480 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2482 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2486 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaSetId */

/* 2492 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2494 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2496 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter mediaSetName */

/* 2498 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2500 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2502 */	NdrFcShort( 0x11a ),	/* Type Offset=282 */

	/* Return value */

/* 2504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2506 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNumOnlineMedia */

/* 2510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2516 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2518 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2522 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2524 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2526 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2534 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNumOnlineMedia */

/* 2536 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2538 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2542 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2544 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNumOnlineMedia */

/* 2548 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2554 */	NdrFcShort( 0xa ),	/* 10 */
/* 2556 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2558 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2562 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2564 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter numOnlineMedia */

/* 2574 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2576 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2582 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNumMediaCopies */

/* 2586 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2592 */	NdrFcShort( 0xc ),	/* 12 */
/* 2594 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2596 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2598 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2600 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2602 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter numMediaCopies */

/* 2612 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2614 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2616 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2620 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManagementPolicy */

/* 2624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2630 */	NdrFcShort( 0xd ),	/* 13 */
/* 2632 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2636 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2638 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2640 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pManagementPolicyId */

/* 2650 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2652 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2654 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2658 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetManagementPolicy */

/* 2662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2668 */	NdrFcShort( 0xe ),	/* 14 */
/* 2670 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2672 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2676 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2678 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter managementPolicyId */

/* 2688 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2690 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2692 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2696 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitFromRmsMediaSet */

/* 2700 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2706 */	NdrFcShort( 0xf ),	/* 15 */
/* 2708 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2714 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2716 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2724 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRmsMediaSet */

/* 2726 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2728 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2730 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Return value */

/* 2732 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2734 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRmsMediaSet */

/* 2738 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2740 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2744 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2746 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2750 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2752 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2754 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2762 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppRmsMediaSet */

/* 2764 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2766 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2768 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Return value */

/* 2770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2772 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIHsmStoragePool */

/* 2776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2782 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2784 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2788 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2790 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2792 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2800 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pHsmStoragePool */

/* 2802 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2804 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2806 */	NdrFcShort( 0x124 ),	/* Type Offset=292 */

	/* Parameter psResult */

/* 2808 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2810 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2812 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2814 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2816 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSetType */

/* 2820 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2826 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2828 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2832 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2834 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2836 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaType */

/* 2846 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2848 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2850 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2852 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2854 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 2858 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2860 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2864 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2866 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2868 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2870 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2872 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2874 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2882 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 2884 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2886 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2888 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter readOnly */

/* 2890 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2892 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2898 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaId */

/* 2902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2908 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2910 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2914 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2916 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2918 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaId */

/* 2928 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2930 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2932 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2934 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2936 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaId */

/* 2940 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2946 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2948 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2950 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2954 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2956 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 2966 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2968 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2970 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2974 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WaitForMount */

/* 2978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2984 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2986 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2988 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2992 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2994 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3002 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter timeout */

/* 3004 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3006 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3010 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3012 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3014 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MountDone */

/* 3016 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3018 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3022 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3024 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3028 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3030 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3032 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3040 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3042 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3044 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsReadOnly */

/* 3048 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3050 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3054 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3056 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3058 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3060 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3062 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3064 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3072 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter readOnly */

/* 3074 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3076 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3078 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3082 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsReadOnly */

/* 3086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3092 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3094 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3100 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3102 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3114 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3116 */	0x8,		/* FC_LONG */
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
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x8 ),	/* Offset= 8 (12) */
/*  6 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 12 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 14 */	NdrFcShort( 0x10 ),	/* 16 */
/* 16 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 18 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 20 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (6) */
			0x5b,		/* FC_END */
/* 24 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 26 */	NdrFcShort( 0x2 ),	/* Offset= 2 (28) */
/* 28 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 30 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 32 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 34 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 36 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 38 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 40 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 42 */	NdrFcShort( 0x2 ),	/* Offset= 2 (44) */
/* 44 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 46 */	NdrFcLong( 0xa5b69200 ),	/* -1514761728 */
/* 50 */	NdrFcShort( 0x214b ),	/* 8523 */
/* 52 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 54 */	0x81,		/* 129 */
			0xb7,		/* 183 */
/* 56 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 58 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 60 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 62 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 64 */	NdrFcShort( 0x2 ),	/* Offset= 2 (66) */
/* 66 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 68 */	NdrFcLong( 0xdd529292 ),	/* -581791086 */
/* 72 */	NdrFcShort( 0x3892 ),	/* 14482 */
/* 74 */	NdrFcShort( 0x47a4 ),	/* 18340 */
/* 76 */	0xb0,		/* 176 */
			0x16,		/* 22 */
/* 78 */	0xc7,		/* 199 */
			0x52,		/* 82 */
/* 80 */	0xa5,		/* 165 */
			0xc,		/* 12 */
/* 82 */	0xfc,		/* 252 */
			0x29,		/* 41 */
/* 84 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 86 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 88 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 90 */	NdrFcShort( 0x2 ),	/* Offset= 2 (92) */
/* 92 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 94 */	NdrFcLong( 0x2a87c7e2 ),	/* 713541602 */
/* 98 */	NdrFcShort( 0xdb24 ),	/* -9436 */
/* 100 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 102 */	0xaf,		/* 175 */
			0xa2,		/* 162 */
/* 104 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 106 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 108 */	0x37,		/* 55 */
			0x58,		/* 88 */
/* 110 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 112 */	NdrFcShort( 0x2 ),	/* Offset= 2 (114) */
/* 114 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 116 */	NdrFcLong( 0xd7a42f4a ),	/* -677105846 */
/* 120 */	NdrFcShort( 0x117c ),	/* 4476 */
/* 122 */	NdrFcShort( 0x47a3 ),	/* 18339 */
/* 124 */	0x9c,		/* 156 */
			0x30,		/* 48 */
/* 126 */	0x92,		/* 146 */
			0xd6,		/* 214 */
/* 128 */	0x3a,		/* 58 */
			0x49,		/* 73 */
/* 130 */	0x19,		/* 25 */
			0xe4,		/* 228 */
/* 132 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 134 */	NdrFcShort( 0x2 ),	/* Offset= 2 (136) */
/* 136 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 138 */	NdrFcLong( 0x14f73fcb ),	/* 351748043 */
/* 142 */	NdrFcShort( 0x517d ),	/* 20861 */
/* 144 */	NdrFcShort( 0x4503 ),	/* 17667 */
/* 146 */	0xb1,		/* 177 */
			0x5d,		/* 93 */
/* 148 */	0x2d,		/* 45 */
			0x40,		/* 64 */
/* 150 */	0xb3,		/* 179 */
			0xe9,		/* 233 */
/* 152 */	0xcd,		/* 205 */
			0x21,		/* 33 */
/* 154 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 156 */	NdrFcShort( 0x10 ),	/* 16 */
/* 158 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 160 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 162 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 164 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 166 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 168 */	
			0x11, 0x0,	/* FC_RP */
/* 170 */	NdrFcShort( 0xff62 ),	/* Offset= -158 (12) */
/* 172 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 174 */	NdrFcShort( 0x2 ),	/* Offset= 2 (176) */
/* 176 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 178 */	NdrFcLong( 0xdda2fbe0 ),	/* -576521248 */
/* 182 */	NdrFcShort( 0x33e4 ),	/* 13284 */
/* 184 */	NdrFcShort( 0x4221 ),	/* 16929 */
/* 186 */	0xa2,		/* 162 */
			0xc8,		/* 200 */
/* 188 */	0xd9,		/* 217 */
			0x7,		/* 7 */
/* 190 */	0x11,		/* 17 */
			0x3,		/* 3 */
/* 192 */	0x97,		/* 151 */
			0xea,		/* 234 */
/* 194 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 196 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 198 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 210 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 212 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 214 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 216 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 218 */	NdrFcShort( 0xffec ),	/* Offset= -20 (198) */
/* 220 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 222 */	NdrFcLong( 0xba365110 ),	/* -1170845424 */
/* 226 */	NdrFcShort( 0x6d66 ),	/* 28006 */
/* 228 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 230 */	0x9e,		/* 158 */
			0x2e,		/* 46 */
/* 232 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 234 */	0xc9,		/* 201 */
			0x16,		/* 22 */
/* 236 */	0xf1,		/* 241 */
			0x20,		/* 32 */
/* 238 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 240 */	NdrFcShort( 0x1c ),	/* Offset= 28 (268) */
/* 242 */	
			0x13, 0x0,	/* FC_OP */
/* 244 */	NdrFcShort( 0xe ),	/* Offset= 14 (258) */
/* 246 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 248 */	NdrFcShort( 0x2 ),	/* 2 */
/* 250 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 252 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 254 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 256 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 258 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 262 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (246) */
/* 264 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 266 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 268 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0xffde ),	/* Offset= -34 (242) */
/* 278 */	
			0x12, 0x0,	/* FC_UP */
/* 280 */	NdrFcShort( 0xffea ),	/* Offset= -22 (258) */
/* 282 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (278) */
/* 292 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 294 */	NdrFcLong( 0xdd529292 ),	/* -581791086 */
/* 298 */	NdrFcShort( 0x3892 ),	/* 14482 */
/* 300 */	NdrFcShort( 0x47a4 ),	/* 18340 */
/* 302 */	0xb0,		/* 176 */
			0x16,		/* 22 */
/* 304 */	0xc7,		/* 199 */
			0x52,		/* 82 */
/* 306 */	0xa5,		/* 165 */
			0xc,		/* 12 */
/* 308 */	0xfc,		/* 252 */
			0x29,		/* 41 */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Standard interface: __MIDL_itf_hsmeng_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IHsmSystemState, ver. 0.0,
   GUID={0x3F0DA041,0x69F1,0x11d2,{0xAF,0x82,0x00,0x10,0x4B,0x9A,0x37,0x58}} */


/* Object interface: IHsmServer, ver. 0.0,
   GUID={0xE372F85B,0xD72B,0x4A7D,{0xB0,0xF6,0x2B,0xCF,0x8F,0xED,0x88,0xB9}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmServer_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    0,
    32,
    70,
    114,
    158,
    202,
    240,
    278,
    316,
    354,
    392,
    430,
    468,
    506,
    544,
    582,
    626,
    670,
    714,
    758,
    796,
    834,
    872,
    910,
    954,
    992,
    1030,
    1068,
    1106,
    1144,
    1182,
    1220,
    1252,
    1284,
    1322,
    1360,
    1392,
    1430,
    1462,
    1494,
    1526,
    1558,
    1590,
    1622,
    1654,
    1686,
    1760,
    1834,
    1866,
    1904,
    1948,
    1992,
    2030,
    2062,
    2094,
    2156
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(60) _IHsmServerProxyVtbl = 
{
    &IHsmServer_ProxyInfo,
    &IID_IHsmServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::Init */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetID */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetDbPath */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetIDbPath */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetDbPathAndName */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetHsmExtVerHi */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetHsmExtVerLo */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetHsmExtRev */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetAutosave */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::SetAutosave */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetCopyFilesLimit */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetCopyFilesUserLimit */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::SetCopyFilesUserLimit */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetManagedResources */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::FindHsmStoragePoolById */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::FindHsmStoragePoolByMediaSetId */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::FindMediaIdByDescription */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::FindStoragePoolByName */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetStoragePools */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetOnlineInformation */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetMessages */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetUsrToNotify */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::FindJobByName */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetJobs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetJobDefs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetPolicies */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetActions */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetCriteria */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetMediaRecs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetMountingMedias */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::LockMountingMedias */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::UnlockMountingMedias */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetNextMedia */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetSegmentDb */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::BackupSegmentDb */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetHsmFsaTskMgr */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::SaveMetaData */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::SavePersistData */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::CloseOutDb */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::CancelAllJobs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::AreJobsEnabled */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::EnableAllJobs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::DisableAllJobs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::RestartSuspendedJobs */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::CreateTask */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::CreateTaskEx */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::CancelCopyMedia */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::MarkMediaForRecreation */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::RecreateMaster */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::SynchronizeMedia */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetHsmMediaMgr */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::ResetSegmentValidMark */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::ResetMediaValidBytes */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::GetSegmentPosition */ ,
    (void *) (INT_PTR) -1 /* IHsmServer::UpdateMediaSizeLimit */
};


static const PRPC_STUB_FUNCTION IHsmServer_table[] =
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

CInterfaceStubVtbl _IHsmServerStubVtbl =
{
    &IID_IHsmServer,
    &IHsmServer_ServerInfo,
    60,
    &IHsmServer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHsmUpgradeRmsDb, ver. 0.0,
   GUID={0xB04E802A,0x8D06,0x46BE,{0x89,0x30,0x2A,0xA2,0xDA,0x4C,0x0D,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmUpgradeRmsDb_FormatStringOffsetTable[] =
    {
    2194
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmUpgradeRmsDb_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmUpgradeRmsDb_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmUpgradeRmsDb_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmUpgradeRmsDb_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmUpgradeRmsDbProxyVtbl = 
{
    &IHsmUpgradeRmsDb_ProxyInfo,
    &IID_IHsmUpgradeRmsDb,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmUpgradeRmsDb::Init */
};

const CInterfaceStubVtbl _IHsmUpgradeRmsDbStubVtbl =
{
    &IID_IHsmUpgradeRmsDb,
    &IHsmUpgradeRmsDb_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbCollectable, ver. 0.0,
   GUID={0x9C7D6F0A,0x1562,0x11D0,{0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */


/* Object interface: IHsmManagedResource, ver. 0.0,
   GUID={0xBA365110,0x6D66,0x11d0,{0x9E,0x2E,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmManagedResource_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    32,
    2232,
    2270,
    2308,
    2346
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmManagedResource_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmManagedResource_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmManagedResource_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmManagedResource_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IHsmManagedResourceProxyVtbl = 
{
    &IHsmManagedResource_ProxyInfo,
    &IID_IHsmManagedResource,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbCollectable::CompareTo */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbCollectable::IsEqual */ ,
    (void *) (INT_PTR) -1 /* IHsmManagedResource::GetResourceId */ ,
    (void *) (INT_PTR) -1 /* IHsmManagedResource::SetResourceId */ ,
    (void *) (INT_PTR) -1 /* IHsmManagedResource::InitFromFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmManagedResource::GetFsaResource */ ,
    (void *) (INT_PTR) -1 /* IHsmManagedResource::CompareToIHsmManagedResource */
};


static const PRPC_STUB_FUNCTION IHsmManagedResource_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IHsmManagedResourceStubVtbl =
{
    &IID_IHsmManagedResource,
    &IHsmManagedResource_ServerInfo,
    10,
    &IHsmManagedResource_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IHsmManagedResourceCollection, ver. 0.0,
   GUID={0xAAA2ABF1,0xE5CF,0x11d1,{0x99,0x74,0x00,0x60,0x97,0x6A,0x54,0x6D}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmManagedResourceCollection_FormatStringOffsetTable[] =
    {
    2390
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmManagedResourceCollection_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmManagedResourceCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmManagedResourceCollection_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmManagedResourceCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmManagedResourceCollectionProxyVtbl = 
{
    &IHsmManagedResourceCollection_ProxyInfo,
    &IID_IHsmManagedResourceCollection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmManagedResourceCollection::DeleteAllAndRelease */
};

const CInterfaceStubVtbl _IHsmManagedResourceCollectionStubVtbl =
{
    &IID_IHsmManagedResourceCollection,
    &IHsmManagedResourceCollection_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmStoragePool, ver. 0.0,
   GUID={0xDD529292,0x3892,0x47A4,{0xB0,0x16,0xC7,0x52,0xA5,0x0C,0xFC,0x29}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmStoragePool_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    32,
    2232,
    2422,
    2466,
    2510,
    2548,
    278,
    2586,
    2624,
    2662,
    2700,
    2738,
    2776,
    2820
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmStoragePool_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmStoragePool_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmStoragePool_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmStoragePool_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IHsmStoragePoolProxyVtbl = 
{
    &IHsmStoragePool_ProxyInfo,
    &IID_IHsmStoragePool,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbCollectable::CompareTo */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbCollectable::IsEqual */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetId */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::SetId */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetMediaSet */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::SetMediaSet */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetNumOnlineMedia */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::SetNumOnlineMedia */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetNumMediaCopies */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::SetNumMediaCopies */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetManagementPolicy */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::SetManagementPolicy */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::InitFromRmsMediaSet */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetRmsMediaSet */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::CompareToIHsmStoragePool */ ,
    (void *) (INT_PTR) -1 /* IHsmStoragePool::GetMediaSetType */
};


static const PRPC_STUB_FUNCTION IHsmStoragePool_table[] =
{
    STUB_FORWARDING_FUNCTION,
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
    NdrStubCall2
};

CInterfaceStubVtbl _IHsmStoragePoolStubVtbl =
{
    &IID_IHsmStoragePool,
    &IHsmStoragePool_ServerInfo,
    19,
    &IHsmStoragePool_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMountingMedia, ver. 0.0,
   GUID={0x38E504D8,0xCBC5,0x4701,{0xBA,0xC5,0xD4,0xF8,0x5B,0x45,0xFC,0x79}} */

#pragma code_seg(".orpc")
static const unsigned short IMountingMedia_FormatStringOffsetTable[] =
    {
    2858,
    2902,
    2940,
    2978,
    3016,
    3048,
    3086
    };

static const MIDL_STUBLESS_PROXY_INFO IMountingMedia_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IMountingMedia_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMountingMedia_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IMountingMedia_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IMountingMediaProxyVtbl = 
{
    &IMountingMedia_ProxyInfo,
    &IID_IMountingMedia,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IMountingMedia::Init */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::GetMediaId */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::SetMediaId */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::WaitForMount */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::MountDone */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::SetIsReadOnly */ ,
    (void *) (INT_PTR) -1 /* IMountingMedia::IsReadOnly */
};

const CInterfaceStubVtbl _IMountingMediaStubVtbl =
{
    &IID_IMountingMedia,
    &IMountingMedia_ServerInfo,
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
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _hsmeng_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IHsmManagedResourceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmUpgradeRmsDbProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmServerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmStoragePoolProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMountingMediaProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmManagedResourceCollectionProxyVtbl,
    0
};

const CInterfaceStubVtbl * _hsmeng_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IHsmManagedResourceStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmUpgradeRmsDbStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmServerStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmStoragePoolStubVtbl,
    ( CInterfaceStubVtbl *) &_IMountingMediaStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmManagedResourceCollectionStubVtbl,
    0
};

PCInterfaceName const _hsmeng_InterfaceNamesList[] = 
{
    "IHsmManagedResource",
    "IHsmUpgradeRmsDb",
    "IHsmServer",
    "IHsmStoragePool",
    "IMountingMedia",
    "IHsmManagedResourceCollection",
    0
};

const IID *  _hsmeng_BaseIIDList[] = 
{
    &IID_IWsbCollectable,
    0,
    &IID_IHsmSystemState,
    &IID_IWsbCollectable,
    0,
    0,
    0
};


#define _hsmeng_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _hsmeng, pIID, n)

int __stdcall _hsmeng_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _hsmeng, 6, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _hsmeng, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _hsmeng, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _hsmeng, 6, *pIndex )
    
}

const ExtendedProxyFileInfo hsmeng_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _hsmeng_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _hsmeng_StubVtblList,
    (const PCInterfaceName * ) & _hsmeng_InterfaceNamesList,
    (const IID ** ) & _hsmeng_BaseIIDList,
    & _hsmeng_IID_Lookup, 
    6,
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

