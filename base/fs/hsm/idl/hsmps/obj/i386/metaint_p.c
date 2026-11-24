

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for metaint.idl:
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


#include "metaint.h"

#define TYPE_FORMAT_STRING_SIZE   171                               
#define PROC_FORMAT_STRING_SIZE   3595                              
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


extern const MIDL_SERVER_INFO ISegRec_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISegRec_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBagHole_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBagHole_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBagInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBagInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMediaInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMediaInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IVolAssign_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IVolAssign_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISegDb_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISegDb_ProxyInfo;



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

	/* Procedure GetSegmentRecord */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x16 ),	/* 22 */
/*  8 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x116 ),	/* 278 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBagId */

/* 24 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pSegStartLoc */

/* 30 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSegLen */

/* 36 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSegFlags */

/* 42 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 44 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 46 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pPrimPos */

/* 48 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 50 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 52 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pSecPos */

/* 54 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 56 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 58 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSegmentRecord */

/* 66 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x17 ),	/* 23 */
/* 74 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 76 */	NdrFcShort( 0x96 ),	/* 150 */
/* 78 */	NdrFcShort( 0x8 ),	/* 8 */
/* 80 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 82 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bagId */

/* 90 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 92 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 94 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 96 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 98 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 100 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 102 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 104 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 106 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segFlags */

/* 108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 110 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 112 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter primPos */

/* 114 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 116 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 118 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter secPos */

/* 120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 122 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 124 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 128 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSegmentFlags */

/* 132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x18 ),	/* 24 */
/* 140 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x22 ),	/* 34 */
/* 146 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 148 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSegFlags */

/* 156 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 160 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 164 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSegmentFlags */

/* 168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x19 ),	/* 25 */
/* 176 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 178 */	NdrFcShort( 0x6 ),	/* 6 */
/* 180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 182 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 184 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter segFlags */

/* 192 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 194 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 196 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPrimPos */

/* 204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x1a ),	/* 26 */
/* 212 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x4c ),	/* 76 */
/* 218 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 220 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPrimPos */

/* 228 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 230 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 232 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPrimPos */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x1b ),	/* 27 */
/* 248 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 250 */	NdrFcShort( 0x30 ),	/* 48 */
/* 252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 256 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter PrimPos */

/* 264 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 268 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 272 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSecPos */

/* 276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 282 */	NdrFcShort( 0x1c ),	/* 28 */
/* 284 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x2c ),	/* 44 */
/* 290 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 292 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSecPos */

/* 300 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 304 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 306 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSecPos */

/* 312 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 314 */	NdrFcLong( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x1d ),	/* 29 */
/* 320 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 322 */	NdrFcShort( 0x10 ),	/* 16 */
/* 324 */	NdrFcShort( 0x8 ),	/* 8 */
/* 326 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 328 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter secPos */

/* 336 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 338 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 340 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 344 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBagHole */

/* 348 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x16 ),	/* 22 */
/* 356 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x94 ),	/* 148 */
/* 362 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 364 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBagId */

/* 372 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 374 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 376 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pSegStartLoc */

/* 378 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 380 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 382 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSegLen */

/* 384 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 386 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 388 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 392 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagHole */

/* 396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x17 ),	/* 23 */
/* 404 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 406 */	NdrFcShort( 0x50 ),	/* 80 */
/* 408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 410 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 412 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter BagId */

/* 420 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 422 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 424 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 428 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 430 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 432 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 434 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 436 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBagInfo */

/* 444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x16 ),	/* 22 */
/* 452 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x154 ),	/* 340 */
/* 458 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStatus */

/* 468 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 472 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pBagId */

/* 474 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 478 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pBirthDate */

/* 480 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 482 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 484 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pLen */

/* 486 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 488 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 490 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pType */

/* 492 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 494 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 496 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVolId */

/* 498 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 500 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 502 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pDeletedBagAmount */

/* 504 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 506 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 508 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pRemoteDataSet */

/* 510 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 512 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 514 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 516 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 518 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagInfo */

/* 522 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x17 ),	/* 23 */
/* 530 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 532 */	NdrFcShort( 0xac ),	/* 172 */
/* 534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 536 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 538 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter status */

/* 546 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 548 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 550 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter bagId */

/* 552 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 554 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 556 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter birthDate */

/* 558 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 560 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 562 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter len */

/* 564 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 566 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 568 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter type */

/* 570 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 572 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 574 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter volId */

/* 576 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 578 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 580 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter deletedBagAmount */

/* 582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 584 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 586 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter remoteDataSet */

/* 588 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 590 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 592 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 594 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 596 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCapacity */

/* 600 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x16 ),	/* 22 */
/* 608 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 612 */	NdrFcShort( 0x2c ),	/* 44 */
/* 614 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 616 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCapacity */

/* 624 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 626 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 628 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 630 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 632 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyDescription */

/* 636 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 638 */	NdrFcLong( 0x0 ),	/* 0 */
/* 642 */	NdrFcShort( 0x17 ),	/* 23 */
/* 644 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 646 */	NdrFcShort( 0xe ),	/* 14 */
/* 648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 650 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 652 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 660 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 662 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 664 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pDescription */

/* 666 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 668 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 670 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter bufferSize */

/* 672 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 674 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 678 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 680 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyInfo */

/* 684 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 686 */	NdrFcLong( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x18 ),	/* 24 */
/* 692 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 694 */	NdrFcShort( 0x16 ),	/* 22 */
/* 696 */	NdrFcShort( 0xae ),	/* 174 */
/* 698 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0xa,		/* 10 */
/* 700 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 708 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 710 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 712 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pMediaSubsystemId */

/* 714 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 716 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 718 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pDescription */

/* 720 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 722 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 724 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter descriptionBufferSize */

/* 726 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 728 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pName */

/* 732 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 734 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 736 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter nameBufferSize */

/* 738 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 740 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUpdate */

/* 744 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 746 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 748 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pLastError */

/* 750 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 752 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pNextRemoteDataSet */

/* 756 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 758 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 760 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 762 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 764 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyLastError */

/* 768 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 770 */	NdrFcLong( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x19 ),	/* 25 */
/* 776 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 778 */	NdrFcShort( 0x6 ),	/* 6 */
/* 780 */	NdrFcShort( 0x24 ),	/* 36 */
/* 782 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 784 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 792 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 794 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 796 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pLastError */

/* 798 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 800 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 806 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyMediaSubsystemId */

/* 810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x1a ),	/* 26 */
/* 818 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 820 */	NdrFcShort( 0x6 ),	/* 6 */
/* 822 */	NdrFcShort( 0x4c ),	/* 76 */
/* 824 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 826 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 832 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 836 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 838 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pMediaSubsystemId */

/* 840 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 842 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 844 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 848 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyName */

/* 852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x1b ),	/* 27 */
/* 860 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 862 */	NdrFcShort( 0xe ),	/* 14 */
/* 864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 866 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 868 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 878 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 880 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pName */

/* 882 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 884 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 886 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter bufferSize */

/* 888 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 896 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyNextRemoteDataSet */

/* 900 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x1c ),	/* 28 */
/* 908 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 910 */	NdrFcShort( 0x6 ),	/* 6 */
/* 912 */	NdrFcShort( 0x22 ),	/* 34 */
/* 914 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 916 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 924 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 926 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 928 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pNextRemoteDataSet */

/* 930 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 932 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 934 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 938 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyUpdate */

/* 942 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 948 */	NdrFcShort( 0x1d ),	/* 29 */
/* 950 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 952 */	NdrFcShort( 0x6 ),	/* 6 */
/* 954 */	NdrFcShort( 0x34 ),	/* 52 */
/* 956 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 958 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 966 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 968 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 970 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pUpdate */

/* 972 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 974 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 976 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 978 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 980 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDescription */

/* 984 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 986 */	NdrFcLong( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x1e ),	/* 30 */
/* 992 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 998 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1000 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDescription */

/* 1008 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1010 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1012 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter bufferSize */

/* 1014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1016 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1022 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFreeBytes */

/* 1026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1034 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1040 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1042 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFreeBytes */

/* 1050 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1052 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1054 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1058 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetId */

/* 1062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1070 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1076 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1078 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 1086 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1088 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1090 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 1092 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1094 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLastError */

/* 1098 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x21 ),	/* 33 */
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

	/* Parameter pLastError */

/* 1122 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1124 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLastKnownGoodMasterInfo */

/* 1134 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1140 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1142 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 1144 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1146 */	NdrFcShort( 0x1b6 ),	/* 438 */
/* 1148 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0xf,		/* 15 */
/* 1150 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaId */

/* 1158 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1160 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1162 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pMediaSubsystemId */

/* 1164 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1166 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1168 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pStoragePoolId */

/* 1170 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1172 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1174 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pFreeBytes */

/* 1176 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1178 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1180 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pCapacity */

/* 1182 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1184 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1186 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pLastError */

/* 1188 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1190 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pDescription */

/* 1194 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1196 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1198 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter descriptionBufferSize */

/* 1200 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1202 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pType */

/* 1206 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1208 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1210 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pName */

/* 1212 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1214 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1216 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter nameBufferSize */

/* 1218 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1220 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pReadOnly */

/* 1224 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1226 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUpdate */

/* 1230 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1232 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 1234 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pNextRemoteDataSet */

/* 1236 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1238 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 1240 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1242 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1244 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 1246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLKGMasterNextRemoteDataSet */

/* 1248 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1250 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1256 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1262 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1264 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNextRemoteDataSet */

/* 1272 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1274 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1276 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogicalValidBytes */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1298 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1300 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLogicalValidBytes */

/* 1308 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1310 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1312 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1316 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaInfo */

/* 1320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1328 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 1330 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1332 */	NdrFcShort( 0x1f6 ),	/* 502 */
/* 1334 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x11,		/* 17 */
/* 1336 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaId */

/* 1344 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1348 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pMediaSubsystemId */

/* 1350 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1354 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pStoragePoolId */

/* 1356 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1358 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1360 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pFreeBytes */

/* 1362 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1364 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1366 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pCapacity */

/* 1368 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1370 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1372 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pLastError */

/* 1374 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1376 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pNextRemoteDataSet */

/* 1380 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1382 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1384 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pDescription */

/* 1386 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1388 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1390 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter descriptionBufferSize */

/* 1392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1394 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pType */

/* 1398 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1400 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1402 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pName */

/* 1404 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1406 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1408 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter nameBufferSize */

/* 1410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1412 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pReadOnly */

/* 1416 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1418 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 1420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUpdate */

/* 1422 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1424 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 1426 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pLogicalValidBytes */

/* 1428 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1430 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 1432 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pRecreate */

/* 1434 */	NdrFcShort( 0x12 ),	/* Flags:  must free, out, */
/* 1436 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 1438 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1442 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 1444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSubsystemId */

/* 1446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1454 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1458 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1460 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1462 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRmsMediaId */

/* 1470 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1472 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1474 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 1476 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1478 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 1482 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1490 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1494 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1496 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1498 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1506 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1508 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1510 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter bufferSize */

/* 1512 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1514 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1520 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNextRemoteDataSet */

/* 1524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1530 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1532 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1536 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1538 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1540 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNextRemoteDataSet */

/* 1548 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1550 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1552 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecallOnlyStatus */

/* 1560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1568 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1572 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1574 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1576 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecallOnlyStatus */

/* 1584 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1586 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1592 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecreate */

/* 1596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1604 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1608 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1610 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1612 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecreate */

/* 1620 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1622 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1628 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStoragePoolId */

/* 1632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1638 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1640 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1644 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1646 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1648 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStoragePoolId */

/* 1656 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1658 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1660 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 1662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1664 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetType */

/* 1668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1676 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1680 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1682 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1684 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1690 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 1692 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1694 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1696 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1700 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUpdate */

/* 1704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1712 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1716 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1718 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1720 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pUpdate */

/* 1728 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1730 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1732 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1748 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1754 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1756 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1764 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1766 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1768 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1772 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCapacity */

/* 1776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1784 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1786 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1790 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1792 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter capacity */

/* 1800 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1802 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1804 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1808 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyName */

/* 1812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1820 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1822 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1826 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1828 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 1836 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1838 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1840 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter name */

/* 1842 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1844 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1846 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1850 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyNextRemoteDataSet */

/* 1854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1862 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1864 */	NdrFcShort( 0xc ),	/* 12 */
/* 1866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1868 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1870 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 1878 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1880 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1882 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter nextRemoteDataSet */

/* 1884 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1888 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1890 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1892 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyDescription */

/* 1896 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1898 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1902 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1904 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1906 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1910 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1912 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1918 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 1920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1922 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1924 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter description */

/* 1926 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1928 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1930 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1934 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyInfo */

/* 1938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0x33 ),	/* 51 */
/* 1946 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 1948 */	NdrFcShort( 0x5c ),	/* 92 */
/* 1950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1952 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1954 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 1962 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1964 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1966 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter mediaSybsystemMediaId */

/* 1968 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1970 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1972 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter description */

/* 1974 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1976 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1978 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter name */

/* 1980 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1982 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1984 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter update */

/* 1986 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1988 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1990 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter lastError */

/* 1992 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1994 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nextRemoteDataSet */

/* 1998 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2000 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 2002 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2006 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyLastError */

/* 2010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2018 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2020 */	NdrFcShort( 0xe ),	/* 14 */
/* 2022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2024 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2026 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2032 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 2034 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2036 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2038 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter lastError */

/* 2040 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2042 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2044 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2046 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2048 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyMediaSubsystemId */

/* 2052 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2054 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2058 */	NdrFcShort( 0x35 ),	/* 53 */
/* 2060 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2062 */	NdrFcShort( 0x36 ),	/* 54 */
/* 2064 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2066 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2068 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2074 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 2076 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2078 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2080 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter mediaSybsystemMediaId */

/* 2082 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2084 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2086 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2090 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyUpdate */

/* 2094 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2100 */	NdrFcShort( 0x36 ),	/* 54 */
/* 2102 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2104 */	NdrFcShort( 0x1e ),	/* 30 */
/* 2106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2108 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2110 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 2118 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2120 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2122 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter update */

/* 2124 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2126 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2128 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 2130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2132 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDescription */

/* 2136 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2142 */	NdrFcShort( 0x37 ),	/* 55 */
/* 2144 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2150 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2152 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2158 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter description */

/* 2160 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2162 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2164 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 2166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2168 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetId */

/* 2172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2178 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2180 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2182 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2186 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2188 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 2196 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2198 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2200 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2204 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFreeBytes */

/* 2208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2214 */	NdrFcShort( 0x39 ),	/* 57 */
/* 2216 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2218 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2222 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2224 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2230 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter FreeBytes */

/* 2232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2236 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2240 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLastError */

/* 2244 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x3a ),	/* 58 */
/* 2252 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2254 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2256 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2258 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2260 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2266 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lastError */

/* 2268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2270 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2276 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLastKnownGoodMasterInfo */

/* 2280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2286 */	NdrFcShort( 0x3b ),	/* 59 */
/* 2288 */	NdrFcShort( 0x68 ),	/* x86 Stack size/offset = 104 */
/* 2290 */	NdrFcShort( 0xe6 ),	/* 230 */
/* 2292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2294 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xd,		/* 13 */
/* 2296 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 2304 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2306 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2308 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter mediaSubsystemMediaId */

/* 2310 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2312 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2314 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter storagePoolId */

/* 2316 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2318 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2320 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter FreeBytes */

/* 2322 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2324 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 2326 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter Capacity */

/* 2328 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2330 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 2332 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter lastError */

/* 2334 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2336 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter description */

/* 2340 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2342 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 2344 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter type */

/* 2346 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2348 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 2350 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter name */

/* 2352 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2354 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 2356 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter readOnly */

/* 2358 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2360 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 2362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter update */

/* 2364 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2366 */	NdrFcShort( 0x58 ),	/* x86 Stack size/offset = 88 */
/* 2368 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter nextRemoteDataSet */

/* 2370 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2372 */	NdrFcShort( 0x60 ),	/* x86 Stack size/offset = 96 */
/* 2374 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2378 */	NdrFcShort( 0x64 ),	/* x86 Stack size/offset = 100 */
/* 2380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLogicalValidBytes */

/* 2382 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2388 */	NdrFcShort( 0x3c ),	/* 60 */
/* 2390 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2392 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2394 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2396 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2398 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2404 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter logicalValidBytes */

/* 2406 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2408 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2410 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2414 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaInfo */

/* 2418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2424 */	NdrFcShort( 0x3d ),	/* 61 */
/* 2426 */	NdrFcShort( 0x74 ),	/* x86 Stack size/offset = 116 */
/* 2428 */	NdrFcShort( 0xfe ),	/* 254 */
/* 2430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2432 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xf,		/* 15 */
/* 2434 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 2442 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2444 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2446 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter mediaSubsystemMediaId */

/* 2448 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2450 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2452 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter storagePoolId */

/* 2454 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2456 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2458 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter FreeBytes */

/* 2460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2462 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 2464 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter Capacity */

/* 2466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2468 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 2470 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter lastError */

/* 2472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2474 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 2476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nextRemoteDataSet */

/* 2478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2480 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 2482 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter description */

/* 2484 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2486 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 2488 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter type */

/* 2490 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2492 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 2494 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter name */

/* 2496 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2498 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 2500 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter readOnly */

/* 2502 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2504 */	NdrFcShort( 0x58 ),	/* x86 Stack size/offset = 88 */
/* 2506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter update */

/* 2508 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2510 */	NdrFcShort( 0x5c ),	/* x86 Stack size/offset = 92 */
/* 2512 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter logicalValidBytes */

/* 2514 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2516 */	NdrFcShort( 0x64 ),	/* x86 Stack size/offset = 100 */
/* 2518 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter recreate */

/* 2520 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2522 */	NdrFcShort( 0x6c ),	/* x86 Stack size/offset = 108 */
/* 2524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2528 */	NdrFcShort( 0x70 ),	/* x86 Stack size/offset = 112 */
/* 2530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaSubsystemId */

/* 2532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2538 */	NdrFcShort( 0x3e ),	/* 62 */
/* 2540 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2542 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2546 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2548 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rmsMediaId */

/* 2556 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2558 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2560 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2564 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNextRemoteDataSet */

/* 2568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0x3f ),	/* 63 */
/* 2576 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2578 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2582 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2584 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nextRemoteDataSet */

/* 2592 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2594 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2596 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2600 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRecallOnlyStatus */

/* 2604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2610 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2612 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2618 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2620 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter readOnlyStatus */

/* 2628 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2630 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2634 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2636 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRecreate */

/* 2640 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2646 */	NdrFcShort( 0x41 ),	/* 65 */
/* 2648 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2652 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2654 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2656 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2662 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recreate */

/* 2664 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2666 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2670 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2672 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStoragePoolId */

/* 2676 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2678 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2682 */	NdrFcShort( 0x42 ),	/* 66 */
/* 2684 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2686 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2690 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2692 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2698 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter storagePoolId */

/* 2700 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2702 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2704 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2706 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2708 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetType */

/* 2712 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2714 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2718 */	NdrFcShort( 0x43 ),	/* 67 */
/* 2720 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2724 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2726 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2728 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2734 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 2736 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2738 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2740 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 2742 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2744 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUpdate */

/* 2748 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2750 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2754 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2756 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2758 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2760 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2762 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2764 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2770 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter update */

/* 2772 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2774 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2776 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 2778 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2780 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteCopy */

/* 2784 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2786 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2790 */	NdrFcShort( 0x45 ),	/* 69 */
/* 2792 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2794 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2796 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2798 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2800 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2806 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 2808 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2810 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2812 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2814 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2816 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RecreateMaster */

/* 2820 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2826 */	NdrFcShort( 0x46 ),	/* 70 */
/* 2828 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2834 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2836 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2844 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2846 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2848 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateLastKnownGoodMaster */

/* 2850 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2852 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2856 */	NdrFcShort( 0x47 ),	/* 71 */
/* 2858 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2864 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2866 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2874 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2876 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVolAssign */

/* 2880 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2882 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2886 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2888 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2892 */	NdrFcShort( 0xd8 ),	/* 216 */
/* 2894 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2896 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2902 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBagId */

/* 2904 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2906 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2908 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pSegStartLoc */

/* 2910 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2912 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2914 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSegLen */

/* 2916 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2918 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2920 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pVolId */

/* 2922 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2924 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2926 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2928 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2930 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2932 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetVolAssign */

/* 2934 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2936 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2940 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2942 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 2944 */	NdrFcShort( 0x80 ),	/* 128 */
/* 2946 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2948 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2950 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2956 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter BagId */

/* 2958 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2960 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2962 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 2964 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2966 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2968 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 2970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2972 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2974 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter VolId */

/* 2976 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2978 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2980 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2984 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 2986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Erase */

/* 2988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2994 */	NdrFcShort( 0xd ),	/* 13 */
/* 2996 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3002 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3004 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3010 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3012 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3014 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 3018 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3020 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3024 */	NdrFcShort( 0xe ),	/* 14 */
/* 3026 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3028 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3030 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3032 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3034 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3040 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter root */

/* 3042 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3044 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3046 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter pDbSys */

/* 3048 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3050 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3052 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter pCreateFlag */

/* 3054 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3056 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3058 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3060 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3062 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BagHoleAdd */

/* 3066 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3068 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3072 */	NdrFcShort( 0xf ),	/* 15 */
/* 3074 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3076 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3080 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3082 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3088 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3090 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3092 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3094 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3096 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3098 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3100 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3102 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3104 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3106 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3110 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3112 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3116 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BagHoleFind */

/* 3120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3126 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3128 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 3130 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3134 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3136 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3144 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3146 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3148 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3150 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3152 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3154 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3156 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3158 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3160 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3162 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3164 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3166 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter ppIBagHole */

/* 3168 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3170 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3172 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Return value */

/* 3174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3176 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BagHoleSubtract */

/* 3180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3186 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3188 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3190 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3194 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3196 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3204 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3206 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3208 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3210 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3214 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3216 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3218 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3220 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3222 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3224 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3226 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3230 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SegAdd */

/* 3234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3240 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3242 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 3244 */	NdrFcShort( 0x98 ),	/* 152 */
/* 3246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3248 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3250 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3258 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3260 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3262 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3264 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3266 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3268 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3270 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3272 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3274 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3278 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3280 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter MediaId */

/* 3282 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3284 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3286 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter mediaStart */

/* 3288 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3290 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3292 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter indirectRecord */

/* 3294 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3296 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 3298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3302 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 3304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SegFind */

/* 3306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3314 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 3316 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3318 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3320 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3322 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3330 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3334 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3336 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3340 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3342 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3344 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3346 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3348 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3350 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3352 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter ppISegRec */

/* 3354 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3356 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3358 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 3360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3362 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SegSubtract */

/* 3366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3372 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3374 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3376 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3380 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3382 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3390 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3392 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3394 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3396 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3398 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3400 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3404 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3406 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3408 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3410 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3412 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3414 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3416 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VolAssignAdd */

/* 3420 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3426 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3428 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 3430 */	NdrFcShort( 0x80 ),	/* 128 */
/* 3432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3434 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3436 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3442 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3444 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3446 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3448 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3450 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3452 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3454 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3456 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3458 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3460 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3462 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3464 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3466 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter VolId */

/* 3468 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3470 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3472 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 3474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3476 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VolAssignFind */

/* 3480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3486 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3488 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 3490 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3494 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3504 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3508 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3510 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3514 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3518 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3520 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3522 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3524 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3526 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter ppIVolAssign */

/* 3528 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3530 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3532 */	NdrFcShort( 0x94 ),	/* Type Offset=148 */

	/* Return value */

/* 3534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3536 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VolAssignSubtract */

/* 3540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3546 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3548 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3550 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3554 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3556 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3564 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3566 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3568 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3570 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3572 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3574 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3576 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3578 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3580 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3584 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3586 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3590 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3592 */	0x8,		/* FC_LONG */
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
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 26 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 28 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 30 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 32 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 34 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 36 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 38 */	NdrFcShort( 0x2 ),	/* Offset= 2 (40) */
/* 40 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 46 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 48 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 50 */	NdrFcShort( 0x2 ),	/* Offset= 2 (52) */
/* 52 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 54 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 56 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 58 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 60 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 62 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 64 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 66 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 68 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 70 */	NdrFcLong( 0xf2608980 ),	/* -228554368 */
/* 74 */	NdrFcShort( 0xa45 ),	/* 2629 */
/* 76 */	NdrFcShort( 0x47b4 ),	/* 18356 */
/* 78 */	0xb1,		/* 177 */
			0x10,		/* 16 */
/* 80 */	0x37,		/* 55 */
			0xea,		/* 234 */
/* 82 */	0x59,		/* 89 */
			0xf6,		/* 246 */
/* 84 */	0x7c,		/* 124 */
			0x47,		/* 71 */
/* 86 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 88 */	NdrFcLong( 0x1973831 ),	/* 26687537 */
/* 92 */	NdrFcShort( 0xe996 ),	/* -5738 */
/* 94 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 96 */	0x99,		/* 153 */
			0x28,		/* 40 */
/* 98 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 100 */	0xc9,		/* 201 */
			0x5,		/* 5 */
/* 102 */	0x8b,		/* 139 */
			0xf6,		/* 246 */
/* 104 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 106 */	NdrFcShort( 0x2 ),	/* Offset= 2 (108) */
/* 108 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 110 */	NdrFcLong( 0x450024a0 ),	/* 1157637280 */
/* 114 */	NdrFcShort( 0x47d0 ),	/* 18384 */
/* 116 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 118 */	0x9e,		/* 158 */
			0x1e,		/* 30 */
/* 120 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 122 */	0xc9,		/* 201 */
			0x16,		/* 22 */
/* 124 */	0xf1,		/* 241 */
			0x20,		/* 32 */
/* 126 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 128 */	NdrFcShort( 0x2 ),	/* Offset= 2 (130) */
/* 130 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 132 */	NdrFcLong( 0x952b2bc7 ),	/* -1792332857 */
/* 136 */	NdrFcShort( 0xfaf6 ),	/* -1290 */
/* 138 */	NdrFcShort( 0x4b14 ),	/* 19220 */
/* 140 */	0x84,		/* 132 */
			0xcd,		/* 205 */
/* 142 */	0x2f,		/* 47 */
			0xa4,		/* 164 */
/* 144 */	0xf0,		/* 240 */
			0x15,		/* 21 */
/* 146 */	0x6b,		/* 107 */
			0xc7,		/* 199 */
/* 148 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 150 */	NdrFcShort( 0x2 ),	/* Offset= 2 (152) */
/* 152 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 154 */	NdrFcLong( 0x4a009e82 ),	/* 1241554562 */
/* 158 */	NdrFcShort( 0xdc42 ),	/* -9150 */
/* 160 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 162 */	0x99,		/* 153 */
			0x25,		/* 37 */
/* 164 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 166 */	0xc9,		/* 201 */
			0x5,		/* 5 */
/* 168 */	0x8b,		/* 139 */
			0xf6,		/* 246 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IWsbDbEntity, ver. 0.0,
   GUID={0xFC7FB18F,0xF497,0x47A6,{0xA2,0x8F,0x7C,0xC4,0xBF,0xEC,0xAA,0x5E}} */


/* Object interface: ISegRec, ver. 0.0,
   GUID={0x952B2BC7,0xFAF6,0x4B14,{0x84,0xCD,0x2F,0xA4,0xF0,0x15,0x6B,0xC7}} */

#pragma code_seg(".orpc")
static const unsigned short ISegRec_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    66,
    132,
    168,
    204,
    240,
    276,
    312
    };

static const MIDL_STUBLESS_PROXY_INFO ISegRec_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISegRec_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISegRec_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISegRec_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(30) _ISegRecProxyVtbl = 
{
    &ISegRec_ProxyInfo,
    &IID_ISegRec,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* ISegRec::GetSegmentRecord */ ,
    (void *) (INT_PTR) -1 /* ISegRec::SetSegmentRecord */ ,
    (void *) (INT_PTR) -1 /* ISegRec::GetSegmentFlags */ ,
    (void *) (INT_PTR) -1 /* ISegRec::SetSegmentFlags */ ,
    (void *) (INT_PTR) -1 /* ISegRec::GetPrimPos */ ,
    (void *) (INT_PTR) -1 /* ISegRec::SetPrimPos */ ,
    (void *) (INT_PTR) -1 /* ISegRec::GetSecPos */ ,
    (void *) (INT_PTR) -1 /* ISegRec::SetSecPos */
};


static const PRPC_STUB_FUNCTION ISegRec_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
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

CInterfaceStubVtbl _ISegRecStubVtbl =
{
    &IID_ISegRec,
    &ISegRec_ServerInfo,
    30,
    &ISegRec_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IBagHole, ver. 0.0,
   GUID={0x450024A0,0x47D0,0x11D0,{0x9E,0x1E,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IBagHole_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    348,
    396
    };

static const MIDL_STUBLESS_PROXY_INFO IBagHole_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IBagHole_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IBagHole_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IBagHole_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IBagHoleProxyVtbl = 
{
    &IBagHole_ProxyInfo,
    &IID_IBagHole,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* IBagHole::GetBagHole */ ,
    (void *) (INT_PTR) -1 /* IBagHole::SetBagHole */
};


static const PRPC_STUB_FUNCTION IBagHole_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IBagHoleStubVtbl =
{
    &IID_IBagHole,
    &IBagHole_ServerInfo,
    24,
    &IBagHole_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IBagInfo, ver. 0.0,
   GUID={0xB13FA471,0x4E1B,0x11D0,{0x9E,0x22,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IBagInfo_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    444,
    522
    };

static const MIDL_STUBLESS_PROXY_INFO IBagInfo_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IBagInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IBagInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IBagInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IBagInfoProxyVtbl = 
{
    &IBagInfo_ProxyInfo,
    &IID_IBagInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* IBagInfo::GetBagInfo */ ,
    (void *) (INT_PTR) -1 /* IBagInfo::SetBagInfo */
};


static const PRPC_STUB_FUNCTION IBagInfo_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IBagInfoStubVtbl =
{
    &IID_IBagInfo,
    &IBagInfo_ServerInfo,
    24,
    &IBagInfo_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMediaInfo, ver. 0.0,
   GUID={0x072E876C,0xB1CD,0x4344,{0xA0,0x38,0x46,0x68,0xE9,0x31,0xDD,0xAD}} */

#pragma code_seg(".orpc")
static const unsigned short IMediaInfo_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    600,
    636,
    684,
    768,
    810,
    852,
    900,
    942,
    984,
    1026,
    1062,
    1098,
    1134,
    1248,
    1284,
    1320,
    1446,
    1482,
    1524,
    1560,
    1596,
    1632,
    1668,
    1704,
    1740,
    1776,
    1812,
    1854,
    1896,
    1938,
    2010,
    2052,
    2094,
    2136,
    2172,
    2208,
    2244,
    2280,
    2382,
    2418,
    2532,
    2568,
    2604,
    2640,
    2676,
    2712,
    2748,
    2784,
    2820,
    2850
    };

static const MIDL_STUBLESS_PROXY_INFO IMediaInfo_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IMediaInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMediaInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IMediaInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(72) _IMediaInfoProxyVtbl = 
{
    &IMediaInfo_ProxyInfo,
    &IID_IMediaInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCapacity */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyDescription */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyLastError */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyMediaSubsystemId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyName */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyNextRemoteDataSet */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyUpdate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetDescription */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetFreeBytes */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetLastError */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetLastKnownGoodMasterInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetLKGMasterNextRemoteDataSet */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetLogicalValidBytes */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetMediaSubsystemId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetName */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetNextRemoteDataSet */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetRecallOnlyStatus */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetRecreate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetStoragePoolId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetType */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetUpdate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetName */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCapacity */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyName */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyNextRemoteDataSet */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyDescription */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyLastError */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyMediaSubsystemId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyUpdate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetDescription */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetFreeBytes */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetLastError */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetLastKnownGoodMasterInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetLogicalValidBytes */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetMediaSubsystemId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetNextRemoteDataSet */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetRecallOnlyStatus */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetRecreate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetStoragePoolId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetType */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetUpdate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::DeleteCopy */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::RecreateMaster */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::UpdateLastKnownGoodMaster */
};


static const PRPC_STUB_FUNCTION IMediaInfo_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
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

CInterfaceStubVtbl _IMediaInfoStubVtbl =
{
    &IID_IMediaInfo,
    &IMediaInfo_ServerInfo,
    72,
    &IMediaInfo_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IVolAssign, ver. 0.0,
   GUID={0x4A009E82,0xDC42,0x11d0,{0x99,0x25,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */

#pragma code_seg(".orpc")
static const unsigned short IVolAssign_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    2880,
    2934
    };

static const MIDL_STUBLESS_PROXY_INFO IVolAssign_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IVolAssign_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IVolAssign_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IVolAssign_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IVolAssignProxyVtbl = 
{
    &IVolAssign_ProxyInfo,
    &IID_IVolAssign,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* IVolAssign::GetVolAssign */ ,
    (void *) (INT_PTR) -1 /* IVolAssign::SetVolAssign */
};


static const PRPC_STUB_FUNCTION IVolAssign_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IVolAssignStubVtbl =
{
    &IID_IVolAssign,
    &IVolAssign_ServerInfo,
    24,
    &IVolAssign_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IWsbDb, ver. 0.0,
   GUID={0xD7A42F4A,0x117C,0x47A3,{0x9C,0x30,0x92,0xD6,0x3A,0x49,0x19,0xE4}} */


/* Object interface: ISegDb, ver. 0.0,
   GUID={0x36A90590,0x3921,0x4C67,{0xBA,0xD2,0xCA,0xD1,0x66,0xE0,0x8B,0x6D}} */

#pragma code_seg(".orpc")
static const unsigned short ISegDb_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    2988,
    3018,
    3066,
    3120,
    3180,
    3234,
    3306,
    3366,
    3420,
    3480,
    3540
    };

static const MIDL_STUBLESS_PROXY_INFO ISegDb_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISegDb_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISegDb_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISegDb_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _ISegDbProxyVtbl = 
{
    &ISegDb_ProxyInfo,
    &IID_ISegDb,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Close */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Create */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Delete */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Dump */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::GetEntity */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::GetName */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::GetPath */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::GetVersion */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Locate */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Open */ ,
    (void *) (INT_PTR) -1 /* ISegDb::Erase */ ,
    (void *) (INT_PTR) -1 /* ISegDb::Initialize */ ,
    (void *) (INT_PTR) -1 /* ISegDb::BagHoleAdd */ ,
    (void *) (INT_PTR) -1 /* ISegDb::BagHoleFind */ ,
    (void *) (INT_PTR) -1 /* ISegDb::BagHoleSubtract */ ,
    (void *) (INT_PTR) -1 /* ISegDb::SegAdd */ ,
    (void *) (INT_PTR) -1 /* ISegDb::SegFind */ ,
    (void *) (INT_PTR) -1 /* ISegDb::SegSubtract */ ,
    (void *) (INT_PTR) -1 /* ISegDb::VolAssignAdd */ ,
    (void *) (INT_PTR) -1 /* ISegDb::VolAssignFind */ ,
    (void *) (INT_PTR) -1 /* ISegDb::VolAssignSubtract */
};


static const PRPC_STUB_FUNCTION ISegDb_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
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
    NdrStubCall2
};

CInterfaceStubVtbl _ISegDbStubVtbl =
{
    &IID_ISegDb,
    &ISegDb_ServerInfo,
    24,
    &ISegDb_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
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

const CInterfaceProxyVtbl * _metaint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IMediaInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IBagInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IVolAssignProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISegDbProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IBagHoleProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISegRecProxyVtbl,
    0
};

const CInterfaceStubVtbl * _metaint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IMediaInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IBagInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IVolAssignStubVtbl,
    ( CInterfaceStubVtbl *) &_ISegDbStubVtbl,
    ( CInterfaceStubVtbl *) &_IBagHoleStubVtbl,
    ( CInterfaceStubVtbl *) &_ISegRecStubVtbl,
    0
};

PCInterfaceName const _metaint_InterfaceNamesList[] = 
{
    "IMediaInfo",
    "IBagInfo",
    "IVolAssign",
    "ISegDb",
    "IBagHole",
    "ISegRec",
    0
};

const IID *  _metaint_BaseIIDList[] = 
{
    &IID_IWsbDbEntity,
    &IID_IWsbDbEntity,
    &IID_IWsbDbEntity,
    &IID_IWsbDb,
    &IID_IWsbDbEntity,
    &IID_IWsbDbEntity,
    0
};


#define _metaint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _metaint, pIID, n)

int __stdcall _metaint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _metaint, 6, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _metaint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _metaint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _metaint, 6, *pIndex )
    
}

const ExtendedProxyFileInfo metaint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _metaint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _metaint_StubVtblList,
    (const PCInterfaceName * ) & _metaint_InterfaceNamesList,
    (const IID ** ) & _metaint_BaseIIDList,
    & _metaint_IID_Lookup, 
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
/* Compiler settings for metaint.idl:
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


#include "metaint.h"

#define TYPE_FORMAT_STRING_SIZE   171                               
#define PROC_FORMAT_STRING_SIZE   3745                              
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


extern const MIDL_SERVER_INFO ISegRec_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISegRec_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBagHole_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBagHole_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBagInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBagInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMediaInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMediaInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IVolAssign_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IVolAssign_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISegDb_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISegDb_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure GetSegmentRecord */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x16 ),	/* 22 */
/*  8 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x116 ),	/* 278 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBagId */

/* 26 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 28 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pSegStartLoc */

/* 32 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 34 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 36 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSegLen */

/* 38 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 40 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 42 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSegFlags */

/* 44 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 46 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 48 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pPrimPos */

/* 50 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 52 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 54 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pSecPos */

/* 56 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 58 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 60 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 62 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 64 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 66 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSegmentRecord */

/* 68 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 70 */	NdrFcLong( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0x17 ),	/* 23 */
/* 76 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 78 */	NdrFcShort( 0x96 ),	/* 150 */
/* 80 */	NdrFcShort( 0x8 ),	/* 8 */
/* 82 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 84 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bagId */

/* 94 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 96 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 98 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 102 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 104 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 108 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 110 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segFlags */

/* 112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 114 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 116 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter primPos */

/* 118 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 120 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 122 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter secPos */

/* 124 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 126 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 128 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 132 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSegmentFlags */

/* 136 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x18 ),	/* 24 */
/* 144 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 148 */	NdrFcShort( 0x22 ),	/* 34 */
/* 150 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 152 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSegFlags */

/* 162 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 164 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 166 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 170 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSegmentFlags */

/* 174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x19 ),	/* 25 */
/* 182 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 184 */	NdrFcShort( 0x6 ),	/* 6 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 190 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter segFlags */

/* 200 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 202 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 204 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 206 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 208 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPrimPos */

/* 212 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 214 */	NdrFcLong( 0x0 ),	/* 0 */
/* 218 */	NdrFcShort( 0x1a ),	/* 26 */
/* 220 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x4c ),	/* 76 */
/* 226 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 228 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPrimPos */

/* 238 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 240 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 242 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 246 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPrimPos */

/* 250 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x1b ),	/* 27 */
/* 258 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 260 */	NdrFcShort( 0x30 ),	/* 48 */
/* 262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 264 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 266 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter PrimPos */

/* 276 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 278 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 280 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSecPos */

/* 288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x1c ),	/* 28 */
/* 296 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x2c ),	/* 44 */
/* 302 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 304 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSecPos */

/* 314 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 316 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 318 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 320 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 322 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSecPos */

/* 326 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x1d ),	/* 29 */
/* 334 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 336 */	NdrFcShort( 0x10 ),	/* 16 */
/* 338 */	NdrFcShort( 0x8 ),	/* 8 */
/* 340 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 342 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter secPos */

/* 352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 354 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 356 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 360 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBagHole */

/* 364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x16 ),	/* 22 */
/* 372 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x94 ),	/* 148 */
/* 378 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 380 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBagId */

/* 390 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 392 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 394 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pSegStartLoc */

/* 396 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 398 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 400 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSegLen */

/* 402 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 404 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 406 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 410 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagHole */

/* 414 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x17 ),	/* 23 */
/* 422 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 424 */	NdrFcShort( 0x50 ),	/* 80 */
/* 426 */	NdrFcShort( 0x8 ),	/* 8 */
/* 428 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 430 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter BagId */

/* 440 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 442 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 444 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 446 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 448 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 450 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 452 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 454 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 456 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 458 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 460 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBagInfo */

/* 464 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 470 */	NdrFcShort( 0x16 ),	/* 22 */
/* 472 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 476 */	NdrFcShort( 0x154 ),	/* 340 */
/* 478 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 480 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStatus */

/* 490 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 492 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 494 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pBagId */

/* 496 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 498 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 500 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pBirthDate */

/* 502 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 504 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 506 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pLen */

/* 508 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 510 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 512 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pType */

/* 514 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 516 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 518 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVolId */

/* 520 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 522 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 524 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pDeletedBagAmount */

/* 526 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 528 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 530 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pRemoteDataSet */

/* 532 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 534 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 536 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 540 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagInfo */

/* 544 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x17 ),	/* 23 */
/* 552 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 554 */	NdrFcShort( 0xac ),	/* 172 */
/* 556 */	NdrFcShort( 0x8 ),	/* 8 */
/* 558 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 560 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter status */

/* 570 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 572 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 574 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter bagId */

/* 576 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 578 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 580 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter birthDate */

/* 582 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 584 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 586 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter len */

/* 588 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 590 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 592 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter type */

/* 594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 596 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 598 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter volId */

/* 600 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 602 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 604 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter deletedBagAmount */

/* 606 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 608 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 610 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter remoteDataSet */

/* 612 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 614 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 616 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 620 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCapacity */

/* 624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x16 ),	/* 22 */
/* 632 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x2c ),	/* 44 */
/* 638 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 640 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCapacity */

/* 650 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 652 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 654 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 658 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyDescription */

/* 662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x17 ),	/* 23 */
/* 670 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 672 */	NdrFcShort( 0xe ),	/* 14 */
/* 674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 676 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 678 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 688 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 690 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 692 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pDescription */

/* 694 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 696 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 698 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter bufferSize */

/* 700 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 702 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 706 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 708 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyInfo */

/* 712 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 714 */	NdrFcLong( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x18 ),	/* 24 */
/* 720 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 722 */	NdrFcShort( 0x16 ),	/* 22 */
/* 724 */	NdrFcShort( 0xae ),	/* 174 */
/* 726 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0xa,		/* 10 */
/* 728 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 738 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 740 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 742 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pMediaSubsystemId */

/* 744 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 746 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 748 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pDescription */

/* 750 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 752 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 754 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter descriptionBufferSize */

/* 756 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 758 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pName */

/* 762 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 764 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 766 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter nameBufferSize */

/* 768 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 770 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUpdate */

/* 774 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 776 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 778 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pLastError */

/* 780 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 782 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pNextRemoteDataSet */

/* 786 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 788 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 790 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 794 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyLastError */

/* 798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x19 ),	/* 25 */
/* 806 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 808 */	NdrFcShort( 0x6 ),	/* 6 */
/* 810 */	NdrFcShort( 0x24 ),	/* 36 */
/* 812 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 814 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 824 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 826 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 828 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pLastError */

/* 830 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 832 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 836 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 838 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyMediaSubsystemId */

/* 842 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 844 */	NdrFcLong( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x1a ),	/* 26 */
/* 850 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 852 */	NdrFcShort( 0x6 ),	/* 6 */
/* 854 */	NdrFcShort( 0x4c ),	/* 76 */
/* 856 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 858 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 868 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 870 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 872 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pMediaSubsystemId */

/* 874 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 876 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 878 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 882 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyName */

/* 886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x1b ),	/* 27 */
/* 894 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 896 */	NdrFcShort( 0xe ),	/* 14 */
/* 898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 900 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 902 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 912 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 914 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 916 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pName */

/* 918 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 920 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 922 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter bufferSize */

/* 924 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 926 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 930 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 932 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyNextRemoteDataSet */

/* 936 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 938 */	NdrFcLong( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x1c ),	/* 28 */
/* 944 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 946 */	NdrFcShort( 0x6 ),	/* 6 */
/* 948 */	NdrFcShort( 0x22 ),	/* 34 */
/* 950 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 952 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 962 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 964 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 966 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pNextRemoteDataSet */

/* 968 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 970 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 972 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 974 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 976 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCopyUpdate */

/* 980 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 982 */	NdrFcLong( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0x1d ),	/* 29 */
/* 988 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 990 */	NdrFcShort( 0x6 ),	/* 6 */
/* 992 */	NdrFcShort( 0x34 ),	/* 52 */
/* 994 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 996 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 1006 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1008 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1010 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pUpdate */

/* 1012 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1014 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1016 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1018 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1020 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDescription */

/* 1024 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1026 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1032 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1038 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1040 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDescription */

/* 1050 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1052 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1054 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter bufferSize */

/* 1056 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1058 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1064 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFreeBytes */

/* 1068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1076 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1082 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1084 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFreeBytes */

/* 1094 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1096 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1098 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1102 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetId */

/* 1106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1112 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1114 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1120 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1122 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 1132 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1134 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1136 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 1138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1140 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLastError */

/* 1144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1150 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1152 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1158 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1160 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLastError */

/* 1170 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1172 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1178 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLastKnownGoodMasterInfo */

/* 1182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1190 */	NdrFcShort( 0x80 ),	/* ia64 Stack size/offset = 128 */
/* 1192 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1194 */	NdrFcShort( 0x1b6 ),	/* 438 */
/* 1196 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0xf,		/* 15 */
/* 1198 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaId */

/* 1208 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1210 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1212 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pMediaSubsystemId */

/* 1214 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1216 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1218 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pStoragePoolId */

/* 1220 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1222 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1224 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pFreeBytes */

/* 1226 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1228 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1230 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pCapacity */

/* 1232 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1234 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1236 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pLastError */

/* 1238 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1240 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pDescription */

/* 1244 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1246 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1248 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter descriptionBufferSize */

/* 1250 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1252 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pType */

/* 1256 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1258 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 1260 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pName */

/* 1262 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1264 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 1266 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter nameBufferSize */

/* 1268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1270 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 1272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pReadOnly */

/* 1274 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1276 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 1278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUpdate */

/* 1280 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1282 */	NdrFcShort( 0x68 ),	/* ia64 Stack size/offset = 104 */
/* 1284 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pNextRemoteDataSet */

/* 1286 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1288 */	NdrFcShort( 0x70 ),	/* ia64 Stack size/offset = 112 */
/* 1290 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1292 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1294 */	NdrFcShort( 0x78 ),	/* ia64 Stack size/offset = 120 */
/* 1296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLKGMasterNextRemoteDataSet */

/* 1298 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1306 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1312 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1314 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNextRemoteDataSet */

/* 1324 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1326 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1328 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1332 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogicalValidBytes */

/* 1336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1344 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1348 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1350 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1352 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1360 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLogicalValidBytes */

/* 1362 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1364 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1366 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1368 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1370 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaInfo */

/* 1374 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1376 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1380 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1382 */	NdrFcShort( 0x90 ),	/* ia64 Stack size/offset = 144 */
/* 1384 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1386 */	NdrFcShort( 0x1f6 ),	/* 502 */
/* 1388 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x11,		/* 17 */
/* 1390 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMediaId */

/* 1400 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1402 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1404 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pMediaSubsystemId */

/* 1406 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1408 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1410 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pStoragePoolId */

/* 1412 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1414 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1416 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pFreeBytes */

/* 1418 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1420 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1422 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pCapacity */

/* 1424 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1426 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1428 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pLastError */

/* 1430 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1432 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pNextRemoteDataSet */

/* 1436 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1438 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1440 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pDescription */

/* 1442 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1444 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1446 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter descriptionBufferSize */

/* 1448 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1450 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 1452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pType */

/* 1454 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1456 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 1458 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pName */

/* 1460 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1462 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 1464 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter nameBufferSize */

/* 1466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1468 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 1470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pReadOnly */

/* 1472 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1474 */	NdrFcShort( 0x68 ),	/* ia64 Stack size/offset = 104 */
/* 1476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUpdate */

/* 1478 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1480 */	NdrFcShort( 0x70 ),	/* ia64 Stack size/offset = 112 */
/* 1482 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter pLogicalValidBytes */

/* 1484 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1486 */	NdrFcShort( 0x78 ),	/* ia64 Stack size/offset = 120 */
/* 1488 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pRecreate */

/* 1490 */	NdrFcShort( 0x12 ),	/* Flags:  must free, out, */
/* 1492 */	NdrFcShort( 0x80 ),	/* ia64 Stack size/offset = 128 */
/* 1494 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1496 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1498 */	NdrFcShort( 0x88 ),	/* ia64 Stack size/offset = 136 */
/* 1500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSubsystemId */

/* 1502 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1504 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1508 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1510 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1514 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1516 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1518 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1526 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRmsMediaId */

/* 1528 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1530 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1532 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 1534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1536 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 1540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1548 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1554 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1556 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1566 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1568 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1570 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter bufferSize */

/* 1572 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1574 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1578 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1580 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNextRemoteDataSet */

/* 1584 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1586 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1592 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1598 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1600 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1608 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNextRemoteDataSet */

/* 1610 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1612 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1614 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1616 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1618 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecallOnlyStatus */

/* 1622 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1628 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1630 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1634 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1636 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1638 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecallOnlyStatus */

/* 1648 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1650 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1656 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecreate */

/* 1660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1666 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1668 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1672 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1674 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1676 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecreate */

/* 1686 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1688 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1692 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1694 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStoragePoolId */

/* 1698 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1706 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1712 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1714 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStoragePoolId */

/* 1724 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1726 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1728 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 1730 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1732 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetType */

/* 1736 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1742 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1744 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1748 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1750 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1752 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 1762 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1764 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1766 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1770 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUpdate */

/* 1774 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1780 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1782 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1786 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1788 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1790 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pUpdate */

/* 1800 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1802 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1804 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1808 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 1812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1820 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1826 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1828 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1838 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1840 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1842 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1844 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1846 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1848 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCapacity */

/* 1850 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1852 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1856 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1858 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1860 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1864 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1866 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter capacity */

/* 1876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1878 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1880 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1882 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1884 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyName */

/* 1888 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1890 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1894 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1896 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1898 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1900 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1902 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1904 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 1914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1916 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1918 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter name */

/* 1920 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1922 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1924 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 1926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1928 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyNextRemoteDataSet */

/* 1932 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1940 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1942 */	NdrFcShort( 0xc ),	/* 12 */
/* 1944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1946 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1948 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1956 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 1958 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1960 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1962 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter nextRemoteDataSet */

/* 1964 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1966 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1968 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1970 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1972 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyDescription */

/* 1976 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1978 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1982 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1984 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1986 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1988 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1990 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1992 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2000 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 2002 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2004 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2006 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter description */

/* 2008 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2010 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2012 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 2014 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2016 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyInfo */

/* 2020 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2026 */	NdrFcShort( 0x33 ),	/* 51 */
/* 2028 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 2030 */	NdrFcShort( 0x5c ),	/* 92 */
/* 2032 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2034 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 2036 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2044 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 2046 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2048 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2050 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter mediaSybsystemMediaId */

/* 2052 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2054 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2056 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter description */

/* 2058 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2060 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2062 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter name */

/* 2064 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2066 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2068 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter update */

/* 2070 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2072 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2074 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter lastError */

/* 2076 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2078 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nextRemoteDataSet */

/* 2082 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2084 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 2086 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2090 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 2092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyLastError */

/* 2094 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2100 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2102 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2104 */	NdrFcShort( 0xe ),	/* 14 */
/* 2106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2108 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2110 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 2120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2122 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2124 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter lastError */

/* 2126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2128 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2134 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyMediaSubsystemId */

/* 2138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2144 */	NdrFcShort( 0x35 ),	/* 53 */
/* 2146 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2148 */	NdrFcShort( 0x36 ),	/* 54 */
/* 2150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2152 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2154 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 2164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2166 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2168 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter mediaSybsystemMediaId */

/* 2170 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2172 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2174 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2178 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCopyUpdate */

/* 2182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2188 */	NdrFcShort( 0x36 ),	/* 54 */
/* 2190 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2192 */	NdrFcShort( 0x1e ),	/* 30 */
/* 2194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2196 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2198 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 2208 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2210 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2212 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter update */

/* 2214 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2216 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2218 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 2220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2222 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDescription */

/* 2226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0x37 ),	/* 55 */
/* 2234 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2240 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2242 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter description */

/* 2252 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2254 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2256 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Return value */

/* 2258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2260 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetId */

/* 2264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2270 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2272 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2274 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2278 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2280 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 2290 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2292 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2294 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2296 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2298 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFreeBytes */

/* 2302 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2308 */	NdrFcShort( 0x39 ),	/* 57 */
/* 2310 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2312 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2314 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2316 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2318 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2326 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter FreeBytes */

/* 2328 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2330 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2332 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2336 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLastError */

/* 2340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x3a ),	/* 58 */
/* 2348 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2354 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2356 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lastError */

/* 2366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2368 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2374 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLastKnownGoodMasterInfo */

/* 2378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2384 */	NdrFcShort( 0x3b ),	/* 59 */
/* 2386 */	NdrFcShort( 0x88 ),	/* ia64 Stack size/offset = 136 */
/* 2388 */	NdrFcShort( 0xe6 ),	/* 230 */
/* 2390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2392 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xd,		/* 13 */
/* 2394 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2402 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 2404 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2406 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2408 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter mediaSubsystemMediaId */

/* 2410 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2412 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2414 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter storagePoolId */

/* 2416 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2418 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2420 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter FreeBytes */

/* 2422 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2424 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2426 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter Capacity */

/* 2428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2430 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 2432 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter lastError */

/* 2434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2436 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 2438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter description */

/* 2440 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2442 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 2444 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter type */

/* 2446 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2448 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 2450 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter name */

/* 2452 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2454 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 2456 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter readOnly */

/* 2458 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2460 */	NdrFcShort( 0x68 ),	/* ia64 Stack size/offset = 104 */
/* 2462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter update */

/* 2464 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2466 */	NdrFcShort( 0x70 ),	/* ia64 Stack size/offset = 112 */
/* 2468 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter nextRemoteDataSet */

/* 2470 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2472 */	NdrFcShort( 0x78 ),	/* ia64 Stack size/offset = 120 */
/* 2474 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2476 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2478 */	NdrFcShort( 0x80 ),	/* ia64 Stack size/offset = 128 */
/* 2480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLogicalValidBytes */

/* 2482 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2488 */	NdrFcShort( 0x3c ),	/* 60 */
/* 2490 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2492 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2494 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2496 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2498 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter logicalValidBytes */

/* 2508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2510 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2512 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2514 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2516 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaInfo */

/* 2520 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2526 */	NdrFcShort( 0x3d ),	/* 61 */
/* 2528 */	NdrFcShort( 0x98 ),	/* ia64 Stack size/offset = 152 */
/* 2530 */	NdrFcShort( 0xfe ),	/* 254 */
/* 2532 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2534 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xf,		/* 15 */
/* 2536 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaId */

/* 2546 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2548 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2550 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter mediaSubsystemMediaId */

/* 2552 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2554 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2556 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter storagePoolId */

/* 2558 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2560 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2562 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter FreeBytes */

/* 2564 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2566 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2568 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter Capacity */

/* 2570 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2572 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 2574 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter lastError */

/* 2576 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2578 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 2580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nextRemoteDataSet */

/* 2582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2584 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 2586 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter description */

/* 2588 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2590 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 2592 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter type */

/* 2594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2596 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 2598 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter name */

/* 2600 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2602 */	NdrFcShort( 0x68 ),	/* ia64 Stack size/offset = 104 */
/* 2604 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter readOnly */

/* 2606 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2608 */	NdrFcShort( 0x70 ),	/* ia64 Stack size/offset = 112 */
/* 2610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter update */

/* 2612 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2614 */	NdrFcShort( 0x78 ),	/* ia64 Stack size/offset = 120 */
/* 2616 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter logicalValidBytes */

/* 2618 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2620 */	NdrFcShort( 0x80 ),	/* ia64 Stack size/offset = 128 */
/* 2622 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter recreate */

/* 2624 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2626 */	NdrFcShort( 0x88 ),	/* ia64 Stack size/offset = 136 */
/* 2628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2630 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2632 */	NdrFcShort( 0x90 ),	/* ia64 Stack size/offset = 144 */
/* 2634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaSubsystemId */

/* 2636 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2638 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2642 */	NdrFcShort( 0x3e ),	/* 62 */
/* 2644 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2646 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2650 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2652 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2660 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rmsMediaId */

/* 2662 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2664 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2666 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2668 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2670 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNextRemoteDataSet */

/* 2674 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2680 */	NdrFcShort( 0x3f ),	/* 63 */
/* 2682 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2684 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2688 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2690 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2698 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nextRemoteDataSet */

/* 2700 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2702 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2704 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2706 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2708 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRecallOnlyStatus */

/* 2712 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2714 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2718 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2720 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2724 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2726 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2728 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2736 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter readOnlyStatus */

/* 2738 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2740 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2744 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2746 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRecreate */

/* 2750 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2752 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2756 */	NdrFcShort( 0x41 ),	/* 65 */
/* 2758 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2760 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2764 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2766 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2774 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recreate */

/* 2776 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2778 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2782 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2784 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStoragePoolId */

/* 2788 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2794 */	NdrFcShort( 0x42 ),	/* 66 */
/* 2796 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2798 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2800 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2802 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2804 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2812 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter storagePoolId */

/* 2814 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2816 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2818 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 2820 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2822 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetType */

/* 2826 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2828 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2832 */	NdrFcShort( 0x43 ),	/* 67 */
/* 2834 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2840 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2842 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 2852 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2854 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2856 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 2858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2860 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUpdate */

/* 2864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2870 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2872 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2874 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2876 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2878 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2880 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2888 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter update */

/* 2890 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2892 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2894 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 2896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2898 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteCopy */

/* 2902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2908 */	NdrFcShort( 0x45 ),	/* 69 */
/* 2910 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2912 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2914 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2916 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2918 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter copyNumber */

/* 2928 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2930 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2932 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2934 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2936 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RecreateMaster */

/* 2940 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2946 */	NdrFcShort( 0x46 ),	/* 70 */
/* 2948 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2954 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2956 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2966 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2968 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateLastKnownGoodMaster */

/* 2972 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2974 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2978 */	NdrFcShort( 0x47 ),	/* 71 */
/* 2980 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2984 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2986 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2988 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2996 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2998 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3000 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVolAssign */

/* 3004 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3010 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3012 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3016 */	NdrFcShort( 0xd8 ),	/* 216 */
/* 3018 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 3020 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3028 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBagId */

/* 3030 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3032 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3034 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter pSegStartLoc */

/* 3036 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3038 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3040 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSegLen */

/* 3042 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3044 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3046 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pVolId */

/* 3048 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3050 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3052 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 3054 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3056 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3058 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetVolAssign */

/* 3060 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3062 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3066 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3068 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3070 */	NdrFcShort( 0x80 ),	/* 128 */
/* 3072 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3074 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 3076 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3084 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter BagId */

/* 3086 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3088 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3090 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3092 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3094 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3096 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3098 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3100 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3102 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter VolId */

/* 3104 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3106 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3108 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 3110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3112 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Erase */

/* 3116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3122 */	NdrFcShort( 0xd ),	/* 13 */
/* 3124 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3130 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3132 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3142 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3144 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 3148 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3154 */	NdrFcShort( 0xe ),	/* 14 */
/* 3156 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3158 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3160 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3162 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3164 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter root */

/* 3174 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3176 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3178 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter pDbSys */

/* 3180 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3182 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3184 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter pCreateFlag */

/* 3186 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3188 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3194 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BagHoleAdd */

/* 3198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3204 */	NdrFcShort( 0xf ),	/* 15 */
/* 3206 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3208 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3212 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3214 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3222 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3224 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3226 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3228 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3230 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3232 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3234 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3236 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3238 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3240 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3242 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3244 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3246 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3250 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BagHoleFind */

/* 3254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3260 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3262 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3264 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3268 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3270 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3278 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3280 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3282 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3284 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3286 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3288 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3290 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3292 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3294 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3296 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3298 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3300 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3302 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter ppIBagHole */

/* 3304 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3306 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3308 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Return value */

/* 3310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3312 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BagHoleSubtract */

/* 3316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3322 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3324 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3326 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3330 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3332 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3342 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3344 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3346 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3348 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3350 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3352 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3354 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3356 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3358 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3360 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3362 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3364 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3368 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SegAdd */

/* 3372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3378 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3380 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 3382 */	NdrFcShort( 0x98 ),	/* 152 */
/* 3384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3386 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3388 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3396 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3398 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3400 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3402 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3404 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3406 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3408 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3412 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3414 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3416 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3418 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3420 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter MediaId */

/* 3422 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3424 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3426 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter mediaStart */

/* 3428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3430 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3432 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter indirectRecord */

/* 3434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3436 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 3438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3442 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 3444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SegFind */

/* 3446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3452 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3454 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3456 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3460 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3462 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3470 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3472 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3474 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3476 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3478 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3480 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3482 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3484 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3486 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3488 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3490 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3492 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3494 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter ppISegRec */

/* 3496 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3498 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3500 */	NdrFcShort( 0x7e ),	/* Type Offset=126 */

	/* Return value */

/* 3502 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3504 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SegSubtract */

/* 3508 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3510 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3514 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3516 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3518 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3520 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3522 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3524 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3534 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3536 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3538 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3540 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3542 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3544 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3546 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3548 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3550 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3552 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3554 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3556 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3560 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VolAssignAdd */

/* 3564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3570 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3572 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 3574 */	NdrFcShort( 0x80 ),	/* 128 */
/* 3576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3578 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3580 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3590 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3592 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3594 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3596 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3598 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3600 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3602 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3604 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3606 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3608 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3610 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3612 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter VolId */

/* 3614 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3616 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3618 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 3620 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3622 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VolAssignFind */

/* 3626 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3632 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3634 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3636 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3640 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3642 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3652 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3654 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3656 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3658 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3660 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3662 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3664 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3666 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3668 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3670 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3672 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3674 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter ppIVolAssign */

/* 3676 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3678 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3680 */	NdrFcShort( 0x94 ),	/* Type Offset=148 */

	/* Return value */

/* 3682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3684 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VolAssignSubtract */

/* 3688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3694 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3696 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3698 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3700 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3702 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3704 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbSession */

/* 3714 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3716 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3718 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter bagId */

/* 3720 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3722 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3724 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter segStartLoc */

/* 3726 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3728 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3730 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter segLen */

/* 3732 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3734 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3736 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3740 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3742 */	0x8,		/* FC_LONG */
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
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 26 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 28 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 30 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 32 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 34 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 36 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 38 */	NdrFcShort( 0x2 ),	/* Offset= 2 (40) */
/* 40 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 46 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 48 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 50 */	NdrFcShort( 0x2 ),	/* Offset= 2 (52) */
/* 52 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 54 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 56 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 58 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 60 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 62 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 64 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 66 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 68 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 70 */	NdrFcLong( 0xf2608980 ),	/* -228554368 */
/* 74 */	NdrFcShort( 0xa45 ),	/* 2629 */
/* 76 */	NdrFcShort( 0x47b4 ),	/* 18356 */
/* 78 */	0xb1,		/* 177 */
			0x10,		/* 16 */
/* 80 */	0x37,		/* 55 */
			0xea,		/* 234 */
/* 82 */	0x59,		/* 89 */
			0xf6,		/* 246 */
/* 84 */	0x7c,		/* 124 */
			0x47,		/* 71 */
/* 86 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 88 */	NdrFcLong( 0x1973831 ),	/* 26687537 */
/* 92 */	NdrFcShort( 0xe996 ),	/* -5738 */
/* 94 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 96 */	0x99,		/* 153 */
			0x28,		/* 40 */
/* 98 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 100 */	0xc9,		/* 201 */
			0x5,		/* 5 */
/* 102 */	0x8b,		/* 139 */
			0xf6,		/* 246 */
/* 104 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 106 */	NdrFcShort( 0x2 ),	/* Offset= 2 (108) */
/* 108 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 110 */	NdrFcLong( 0x450024a0 ),	/* 1157637280 */
/* 114 */	NdrFcShort( 0x47d0 ),	/* 18384 */
/* 116 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 118 */	0x9e,		/* 158 */
			0x1e,		/* 30 */
/* 120 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 122 */	0xc9,		/* 201 */
			0x16,		/* 22 */
/* 124 */	0xf1,		/* 241 */
			0x20,		/* 32 */
/* 126 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 128 */	NdrFcShort( 0x2 ),	/* Offset= 2 (130) */
/* 130 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 132 */	NdrFcLong( 0x952b2bc7 ),	/* -1792332857 */
/* 136 */	NdrFcShort( 0xfaf6 ),	/* -1290 */
/* 138 */	NdrFcShort( 0x4b14 ),	/* 19220 */
/* 140 */	0x84,		/* 132 */
			0xcd,		/* 205 */
/* 142 */	0x2f,		/* 47 */
			0xa4,		/* 164 */
/* 144 */	0xf0,		/* 240 */
			0x15,		/* 21 */
/* 146 */	0x6b,		/* 107 */
			0xc7,		/* 199 */
/* 148 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 150 */	NdrFcShort( 0x2 ),	/* Offset= 2 (152) */
/* 152 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 154 */	NdrFcLong( 0x4a009e82 ),	/* 1241554562 */
/* 158 */	NdrFcShort( 0xdc42 ),	/* -9150 */
/* 160 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 162 */	0x99,		/* 153 */
			0x25,		/* 37 */
/* 164 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 166 */	0xc9,		/* 201 */
			0x5,		/* 5 */
/* 168 */	0x8b,		/* 139 */
			0xf6,		/* 246 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IWsbDbEntity, ver. 0.0,
   GUID={0xFC7FB18F,0xF497,0x47A6,{0xA2,0x8F,0x7C,0xC4,0xBF,0xEC,0xAA,0x5E}} */


/* Object interface: ISegRec, ver. 0.0,
   GUID={0x952B2BC7,0xFAF6,0x4B14,{0x84,0xCD,0x2F,0xA4,0xF0,0x15,0x6B,0xC7}} */

#pragma code_seg(".orpc")
static const unsigned short ISegRec_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    68,
    136,
    174,
    212,
    250,
    288,
    326
    };

static const MIDL_STUBLESS_PROXY_INFO ISegRec_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISegRec_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISegRec_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISegRec_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(30) _ISegRecProxyVtbl = 
{
    &ISegRec_ProxyInfo,
    &IID_ISegRec,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* ISegRec::GetSegmentRecord */ ,
    (void *) (INT_PTR) -1 /* ISegRec::SetSegmentRecord */ ,
    (void *) (INT_PTR) -1 /* ISegRec::GetSegmentFlags */ ,
    (void *) (INT_PTR) -1 /* ISegRec::SetSegmentFlags */ ,
    (void *) (INT_PTR) -1 /* ISegRec::GetPrimPos */ ,
    (void *) (INT_PTR) -1 /* ISegRec::SetPrimPos */ ,
    (void *) (INT_PTR) -1 /* ISegRec::GetSecPos */ ,
    (void *) (INT_PTR) -1 /* ISegRec::SetSecPos */
};


static const PRPC_STUB_FUNCTION ISegRec_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
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

CInterfaceStubVtbl _ISegRecStubVtbl =
{
    &IID_ISegRec,
    &ISegRec_ServerInfo,
    30,
    &ISegRec_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IBagHole, ver. 0.0,
   GUID={0x450024A0,0x47D0,0x11D0,{0x9E,0x1E,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IBagHole_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    364,
    414
    };

static const MIDL_STUBLESS_PROXY_INFO IBagHole_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IBagHole_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IBagHole_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IBagHole_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IBagHoleProxyVtbl = 
{
    &IBagHole_ProxyInfo,
    &IID_IBagHole,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* IBagHole::GetBagHole */ ,
    (void *) (INT_PTR) -1 /* IBagHole::SetBagHole */
};


static const PRPC_STUB_FUNCTION IBagHole_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IBagHoleStubVtbl =
{
    &IID_IBagHole,
    &IBagHole_ServerInfo,
    24,
    &IBagHole_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IBagInfo, ver. 0.0,
   GUID={0xB13FA471,0x4E1B,0x11D0,{0x9E,0x22,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IBagInfo_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    464,
    544
    };

static const MIDL_STUBLESS_PROXY_INFO IBagInfo_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IBagInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IBagInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IBagInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IBagInfoProxyVtbl = 
{
    &IBagInfo_ProxyInfo,
    &IID_IBagInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* IBagInfo::GetBagInfo */ ,
    (void *) (INT_PTR) -1 /* IBagInfo::SetBagInfo */
};


static const PRPC_STUB_FUNCTION IBagInfo_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IBagInfoStubVtbl =
{
    &IID_IBagInfo,
    &IBagInfo_ServerInfo,
    24,
    &IBagInfo_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMediaInfo, ver. 0.0,
   GUID={0x072E876C,0xB1CD,0x4344,{0xA0,0x38,0x46,0x68,0xE9,0x31,0xDD,0xAD}} */

#pragma code_seg(".orpc")
static const unsigned short IMediaInfo_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    624,
    662,
    712,
    798,
    842,
    886,
    936,
    980,
    1024,
    1068,
    1106,
    1144,
    1182,
    1298,
    1336,
    1374,
    1502,
    1540,
    1584,
    1622,
    1660,
    1698,
    1736,
    1774,
    1812,
    1850,
    1888,
    1932,
    1976,
    2020,
    2094,
    2138,
    2182,
    2226,
    2264,
    2302,
    2340,
    2378,
    2482,
    2520,
    2636,
    2674,
    2712,
    2750,
    2788,
    2826,
    2864,
    2902,
    2940,
    2972
    };

static const MIDL_STUBLESS_PROXY_INFO IMediaInfo_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IMediaInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMediaInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IMediaInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(72) _IMediaInfoProxyVtbl = 
{
    &IMediaInfo_ProxyInfo,
    &IID_IMediaInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCapacity */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyDescription */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyLastError */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyMediaSubsystemId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyName */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyNextRemoteDataSet */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetCopyUpdate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetDescription */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetFreeBytes */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetLastError */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetLastKnownGoodMasterInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetLKGMasterNextRemoteDataSet */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetLogicalValidBytes */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetMediaSubsystemId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetName */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetNextRemoteDataSet */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetRecallOnlyStatus */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetRecreate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetStoragePoolId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetType */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::GetUpdate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetName */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCapacity */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyName */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyNextRemoteDataSet */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyDescription */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyLastError */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyMediaSubsystemId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetCopyUpdate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetDescription */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetFreeBytes */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetLastError */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetLastKnownGoodMasterInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetLogicalValidBytes */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetMediaInfo */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetMediaSubsystemId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetNextRemoteDataSet */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetRecallOnlyStatus */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetRecreate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetStoragePoolId */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetType */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::SetUpdate */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::DeleteCopy */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::RecreateMaster */ ,
    (void *) (INT_PTR) -1 /* IMediaInfo::UpdateLastKnownGoodMaster */
};


static const PRPC_STUB_FUNCTION IMediaInfo_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
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

CInterfaceStubVtbl _IMediaInfoStubVtbl =
{
    &IID_IMediaInfo,
    &IMediaInfo_ServerInfo,
    72,
    &IMediaInfo_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IVolAssign, ver. 0.0,
   GUID={0x4A009E82,0xDC42,0x11d0,{0x99,0x25,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */

#pragma code_seg(".orpc")
static const unsigned short IVolAssign_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    3004,
    3060
    };

static const MIDL_STUBLESS_PROXY_INFO IVolAssign_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IVolAssign_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IVolAssign_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IVolAssign_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IVolAssignProxyVtbl = 
{
    &IVolAssign_ProxyInfo,
    &IID_IVolAssign,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* IVolAssign::GetVolAssign */ ,
    (void *) (INT_PTR) -1 /* IVolAssign::SetVolAssign */
};


static const PRPC_STUB_FUNCTION IVolAssign_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IVolAssignStubVtbl =
{
    &IID_IVolAssign,
    &IVolAssign_ServerInfo,
    24,
    &IVolAssign_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IWsbDb, ver. 0.0,
   GUID={0xD7A42F4A,0x117C,0x47A3,{0x9C,0x30,0x92,0xD6,0x3A,0x49,0x19,0xE4}} */


/* Object interface: ISegDb, ver. 0.0,
   GUID={0x36A90590,0x3921,0x4C67,{0xBA,0xD2,0xCA,0xD1,0x66,0xE0,0x8B,0x6D}} */

#pragma code_seg(".orpc")
static const unsigned short ISegDb_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    3116,
    3148,
    3198,
    3254,
    3316,
    3372,
    3446,
    3508,
    3564,
    3626,
    3688
    };

static const MIDL_STUBLESS_PROXY_INFO ISegDb_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISegDb_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISegDb_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISegDb_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _ISegDbProxyVtbl = 
{
    &ISegDb_ProxyInfo,
    &IID_ISegDb,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Close */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Create */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Delete */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Dump */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::GetEntity */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::GetName */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::GetPath */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::GetVersion */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Locate */ ,
    0 /* (void *) (INT_PTR) -1 /* IWsbDb::Open */ ,
    (void *) (INT_PTR) -1 /* ISegDb::Erase */ ,
    (void *) (INT_PTR) -1 /* ISegDb::Initialize */ ,
    (void *) (INT_PTR) -1 /* ISegDb::BagHoleAdd */ ,
    (void *) (INT_PTR) -1 /* ISegDb::BagHoleFind */ ,
    (void *) (INT_PTR) -1 /* ISegDb::BagHoleSubtract */ ,
    (void *) (INT_PTR) -1 /* ISegDb::SegAdd */ ,
    (void *) (INT_PTR) -1 /* ISegDb::SegFind */ ,
    (void *) (INT_PTR) -1 /* ISegDb::SegSubtract */ ,
    (void *) (INT_PTR) -1 /* ISegDb::VolAssignAdd */ ,
    (void *) (INT_PTR) -1 /* ISegDb::VolAssignFind */ ,
    (void *) (INT_PTR) -1 /* ISegDb::VolAssignSubtract */
};


static const PRPC_STUB_FUNCTION ISegDb_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
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
    NdrStubCall2
};

CInterfaceStubVtbl _ISegDbStubVtbl =
{
    &IID_ISegDb,
    &ISegDb_ServerInfo,
    24,
    &ISegDb_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
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

const CInterfaceProxyVtbl * _metaint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IMediaInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IBagInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IVolAssignProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISegDbProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IBagHoleProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISegRecProxyVtbl,
    0
};

const CInterfaceStubVtbl * _metaint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IMediaInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IBagInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IVolAssignStubVtbl,
    ( CInterfaceStubVtbl *) &_ISegDbStubVtbl,
    ( CInterfaceStubVtbl *) &_IBagHoleStubVtbl,
    ( CInterfaceStubVtbl *) &_ISegRecStubVtbl,
    0
};

PCInterfaceName const _metaint_InterfaceNamesList[] = 
{
    "IMediaInfo",
    "IBagInfo",
    "IVolAssign",
    "ISegDb",
    "IBagHole",
    "ISegRec",
    0
};

const IID *  _metaint_BaseIIDList[] = 
{
    &IID_IWsbDbEntity,
    &IID_IWsbDbEntity,
    &IID_IWsbDbEntity,
    &IID_IWsbDb,
    &IID_IWsbDbEntity,
    &IID_IWsbDbEntity,
    0
};


#define _metaint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _metaint, pIID, n)

int __stdcall _metaint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _metaint, 6, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _metaint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _metaint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _metaint, 6, *pIndex )
    
}

const ExtendedProxyFileInfo metaint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _metaint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _metaint_StubVtblList,
    (const PCInterfaceName * ) & _metaint_InterfaceNamesList,
    (const IID ** ) & _metaint_BaseIIDList,
    & _metaint_IID_Lookup, 
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

