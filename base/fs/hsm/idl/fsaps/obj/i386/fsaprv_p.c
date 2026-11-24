

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for fsaprv.idl:
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


#include "fsaprv.h"

#define TYPE_FORMAT_STRING_SIZE   367                               
#define PROC_FORMAT_STRING_SIZE   3739                              
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


extern const MIDL_SERVER_INFO IFsaFilterPriv_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaFilterPriv_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaFilterRecallPriv_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaFilterRecallPriv_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaResourcePriv_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaResourcePriv_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaScanItemPriv_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaScanItemPriv_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaPremigratedDb_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaPremigratedDb_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaPremigratedRec_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaPremigratedRec_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaRecoveryRec_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaRecoveryRec_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaUnmanageDb_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaUnmanageDb_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaUnmanageRec_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaUnmanageRec_ProxyInfo;



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
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 24 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIdentifier */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x4 ),	/* 4 */
/* 44 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 46 */	NdrFcShort( 0x30 ),	/* 48 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 60 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Delete */


	/* Procedure IoctlThread */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x5 ),	/* 5 */
/* 80 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 88 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNext */


	/* Procedure DoRecovery */


	/* Procedure PipeThread */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x6 ),	/* 6 */
/* 110 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 118 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendCancel */

/* 132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x7 ),	/* 7 */
/* 140 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 146 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 148 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecallPriv */

/* 156 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 160 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 164 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendComplete */

/* 168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 176 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 178 */	NdrFcShort( 0x8 ),	/* 8 */
/* 180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 182 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 184 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recall */

/* 192 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 194 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 196 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter result */

/* 198 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 206 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cancel */

/* 210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x3 ),	/* 3 */
/* 218 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x8 ),	/* 8 */
/* 224 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 226 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelByDriver */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x4 ),	/* 4 */
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

/* 264 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetClient */

/* 270 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 272 */	NdrFcLong( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x6 ),	/* 6 */
/* 278 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 284 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 286 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppClient */

/* 294 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 296 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 298 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */

/* 300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 302 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDriversRecallId */

/* 306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x7 ),	/* 7 */
/* 314 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x2c ),	/* 44 */
/* 320 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 322 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 330 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 334 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDriversRecallId */

/* 342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 350 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 352 */	NdrFcShort( 0x10 ),	/* 16 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 358 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 368 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 370 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetThreadId */

/* 378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x9 ),	/* 9 */
/* 386 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 392 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 394 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 410 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPlaceholder */

/* 414 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0xa ),	/* 10 */
/* 422 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0x124 ),	/* 292 */
/* 428 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 430 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPlaceholder */

/* 438 */	NdrFcShort( 0x112 ),	/* Flags:  must free, out, simple ref, */
/* 440 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 442 */	NdrFcShort( 0x5e ),	/* Type Offset=94 */

	/* Return value */

/* 444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 446 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0xb ),	/* 11 */
/* 458 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 460 */	NdrFcShort( 0x164 ),	/* 356 */
/* 462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 464 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 466 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClient */

/* 474 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 476 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 478 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pDriversRecallId */

/* 480 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 482 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 484 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pResource */

/* 486 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 488 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 490 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Parameter path */

/* 492 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 494 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 496 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter fileId */

/* 498 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 500 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 502 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter offset */

/* 504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 506 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 508 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 510 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 512 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 514 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter mode */

/* 516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 518 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 522 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 524 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 526 */	NdrFcShort( 0x5e ),	/* Type Offset=94 */

	/* Parameter pFilterPriv */

/* 528 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 530 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 532 */	NdrFcShort( 0x9a ),	/* Type Offset=154 */

	/* Return value */

/* 534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 536 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIdentifier */

/* 540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0xc ),	/* 12 */
/* 548 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 550 */	NdrFcShort( 0x30 ),	/* 48 */
/* 552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 554 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 556 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 564 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 566 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 568 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 572 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StartRecall */

/* 576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0xd ),	/* 13 */
/* 584 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 586 */	NdrFcShort( 0x20 ),	/* 32 */
/* 588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 590 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 592 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 600 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 602 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 604 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 606 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 608 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 610 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 614 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStream */

/* 618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0xe ),	/* 14 */
/* 626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 632 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 634 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppStream */

/* 642 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 646 */	NdrFcShort( 0xac ),	/* Type Offset=172 */

	/* Return value */

/* 648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIdentifier */

/* 654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0xf ),	/* 15 */
/* 662 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 664 */	NdrFcShort( 0x30 ),	/* 48 */
/* 666 */	NdrFcShort( 0x22 ),	/* 34 */
/* 668 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 670 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 678 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 682 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter pResult */

/* 684 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 686 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 688 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 692 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIRecall */

/* 696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x10 ),	/* 16 */
/* 704 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x22 ),	/* 34 */
/* 710 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 712 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 720 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 722 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 724 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Parameter pResult */

/* 726 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 728 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 730 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 732 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToDriversRecallId */

/* 738 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 740 */	NdrFcLong( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x11 ),	/* 17 */
/* 746 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 748 */	NdrFcShort( 0x10 ),	/* 16 */
/* 750 */	NdrFcShort( 0x22 ),	/* 34 */
/* 752 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 754 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 762 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 764 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 766 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 768 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 770 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 772 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 776 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToDriversContextId */

/* 780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x12 ),	/* 18 */
/* 788 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 790 */	NdrFcShort( 0x10 ),	/* 16 */
/* 792 */	NdrFcShort( 0x22 ),	/* 34 */
/* 794 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 796 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 806 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 808 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 810 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 812 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 814 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 816 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 818 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareBy */

/* 822 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 828 */	NdrFcShort( 0x13 ),	/* 19 */
/* 830 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 832 */	NdrFcShort( 0x6 ),	/* 6 */
/* 834 */	NdrFcShort( 0x8 ),	/* 8 */
/* 836 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 838 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter by */

/* 846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 848 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 850 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 852 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 854 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 858 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 860 */	NdrFcLong( 0x0 ),	/* 0 */
/* 864 */	NdrFcShort( 0x14 ),	/* 20 */
/* 866 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x4c ),	/* 76 */
/* 872 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 874 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 880 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 882 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 884 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 886 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 888 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 890 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMode */

/* 894 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 896 */	NdrFcLong( 0x0 ),	/* 0 */
/* 900 */	NdrFcShort( 0x15 ),	/* 21 */
/* 902 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x24 ),	/* 36 */
/* 908 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 910 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 916 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMode */

/* 918 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 920 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 924 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 926 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOffset */

/* 930 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0x16 ),	/* 22 */
/* 938 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x2c ),	/* 44 */
/* 944 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 946 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 954 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 956 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 958 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 960 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 962 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 964 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 966 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 968 */	NdrFcLong( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x17 ),	/* 23 */
/* 974 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 978 */	NdrFcShort( 0x8 ),	/* 8 */
/* 980 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 982 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 990 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 992 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 994 */	NdrFcShort( 0xe0 ),	/* Type Offset=224 */

	/* Parameter bufferSize */

/* 996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 998 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1002 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1004 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResource */

/* 1008 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1010 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1016 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1020 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1022 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1024 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppResource */

/* 1032 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1034 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1036 */	NdrFcShort( 0xe8 ),	/* Type Offset=232 */

	/* Return value */

/* 1038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1040 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 1044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1052 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1058 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1060 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 1068 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1070 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1072 */	NdrFcShort( 0xfe ),	/* Type Offset=254 */

	/* Return value */

/* 1074 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1078 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileUSN */


	/* Procedure GetSize */

/* 1080 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1082 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1086 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1088 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1094 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1096 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1102 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileUSN */


	/* Parameter pSize */

/* 1104 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1106 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1108 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1112 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 1116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1124 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1130 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1132 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 1140 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1142 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1144 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUserName */

/* 1152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1160 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1166 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1168 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1174 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1176 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1178 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1180 */	NdrFcShort( 0xe0 ),	/* Type Offset=224 */

	/* Parameter bufferSize */

/* 1182 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1184 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1190 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WasCancelled */

/* 1194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1202 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1208 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1210 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1220 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LogComplete */

/* 1224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1230 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1232 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1238 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1240 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1246 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hr */

/* 1248 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1250 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1254 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1256 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddPremigratedSize */

/* 1260 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1268 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1270 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1274 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1276 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1282 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter size */

/* 1284 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1286 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1288 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1290 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1294 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddTruncatedSize */

/* 1296 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1298 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1302 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1304 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1306 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1308 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1310 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1312 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1318 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter size */

/* 1320 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1322 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1324 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1328 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FilterSawOpen */

/* 1332 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1338 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1340 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 1342 */	NdrFcShort( 0x164 ),	/* 356 */
/* 1344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1346 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 1348 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 1356 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1358 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1360 */	NdrFcShort( 0x102 ),	/* Type Offset=258 */

	/* Parameter pRecall */

/* 1362 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1364 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1366 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Parameter path */

/* 1368 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1370 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1372 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter fileId */

/* 1374 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1376 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1378 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter requestOffset */

/* 1380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1382 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1384 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter requestSize */

/* 1386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1388 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1390 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 1392 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1394 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1396 */	NdrFcShort( 0x5e ),	/* Type Offset=94 */

	/* Parameter mode */

/* 1398 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1400 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter resultAction */

/* 1404 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1406 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1408 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 1410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1412 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 1414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1418 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 1420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FilterSawDelete */

/* 1422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1430 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1432 */	NdrFcShort( 0x15c ),	/* 348 */
/* 1434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1436 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1438 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1444 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filterId */

/* 1446 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1448 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1450 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter path */

/* 1452 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1454 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1456 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter size */

/* 1458 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1460 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1462 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 1464 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1466 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1468 */	NdrFcShort( 0x5e ),	/* Type Offset=94 */

	/* Return value */

/* 1470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1472 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPremigrated */

/* 1476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1484 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1486 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1490 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1492 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1494 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 1500 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1502 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1504 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter ppDb */

/* 1506 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1510 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 1512 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1514 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUnmanageDb */

/* 1518 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0xa ),	/* 10 */
/* 1526 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1528 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1532 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1534 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1536 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 1542 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1544 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1546 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter ppDb */

/* 1548 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1550 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1552 */	NdrFcShort( 0x128 ),	/* Type Offset=296 */

	/* Return value */

/* 1554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1556 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeUnmanageDb */

/* 1560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0xb ),	/* 11 */
/* 1568 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1574 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1576 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1586 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TerminateUnmanageDb */

/* 1590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0xc ),	/* 12 */
/* 1598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1604 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1606 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1616 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 1620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0xd ),	/* 13 */
/* 1628 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1634 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1636 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1642 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 1644 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1646 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1648 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter path */

/* 1650 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1652 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1654 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter dosname */

/* 1656 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1658 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1660 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1664 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemovePremigratedSize */

/* 1668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0xe ),	/* 14 */
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

	/* Parameter size */

/* 1692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1694 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1696 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1700 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveTruncatedSize */

/* 1704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0xf ),	/* 15 */
/* 1712 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1714 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1716 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1718 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1720 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter size */

/* 1728 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1730 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1732 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAlternatePath */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x10 ),	/* 16 */
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

	/* Parameter path */

/* 1764 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1766 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1768 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1772 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIdentifier */

/* 1776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1784 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1786 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1790 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1792 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 1800 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1802 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1804 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 1806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1808 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 1812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1820 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1826 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1828 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1836 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1838 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1840 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1844 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOldPath */

/* 1848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1856 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1862 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1864 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter oldPath */

/* 1872 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1874 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1876 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1880 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPath */

/* 1884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1892 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1898 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1900 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1906 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 1908 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1910 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1912 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1914 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUserFriendlyName */

/* 1920 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1922 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1926 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1928 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1934 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1936 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1942 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 1944 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1946 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1948 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1950 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1952 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1954 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStickyName */

/* 1956 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1958 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1962 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1964 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1968 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1970 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1972 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1978 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 1980 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1982 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1984 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1986 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1988 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSerial */

/* 1992 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1998 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2000 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2006 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2008 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2014 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serial */

/* 2016 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2018 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2022 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2024 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateFrom */

/* 2028 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2030 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2034 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2036 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2040 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2042 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2044 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2050 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 2052 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2054 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2056 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pResource */

/* 2058 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2060 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2062 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 2064 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2066 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileId */


	/* Procedure GetMaxFileLogicalSize */

/* 2070 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2072 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2076 */	NdrFcShort( 0x19 ),	/* 25 */
/* 2078 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2084 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2086 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2092 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */


	/* Parameter pSize */

/* 2094 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2096 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2098 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2102 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirst */

/* 2106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2112 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2114 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2120 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2122 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 2130 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2132 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2134 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Parameter path */

/* 2136 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2138 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2140 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter pSession */

/* 2142 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2144 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2146 */	NdrFcShort( 0x134 ),	/* Type Offset=308 */

	/* Return value */

/* 2148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2150 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirstInRPIndex */

/* 2154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2162 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2168 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2170 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 2178 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2180 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2182 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Parameter pSession */

/* 2184 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2186 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2188 */	NdrFcShort( 0x134 ),	/* Type Offset=308 */

	/* Return value */

/* 2190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2192 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirstInDbIndex */

/* 2196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2202 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2204 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2210 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2212 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 2220 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2222 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2224 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Parameter pSession */

/* 2226 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2230 */	NdrFcShort( 0x134 ),	/* Type Offset=308 */

	/* Return value */

/* 2232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNextInRPIndex */

/* 2238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2244 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2246 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2252 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2254 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2260 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2262 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2264 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNextInDbIndex */

/* 2268 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2270 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2274 */	NdrFcShort( 0x8 ),	/* 8 */
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

	/* Procedure TruncateInternal */

/* 2298 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2304 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2306 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2308 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2310 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2312 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2314 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 2322 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2324 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2326 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 2328 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2330 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2332 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2336 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VerifyInternal */

/* 2340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0xa ),	/* 10 */
/* 2348 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2350 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2354 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2356 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 2364 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2366 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2368 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 2370 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2372 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2374 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter usn1 */

/* 2376 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2378 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2380 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter usn2 */

/* 2382 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2384 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2386 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2388 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2390 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */


	/* Procedure Init */

/* 2394 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2396 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2400 */	NdrFcShort( 0xd ),	/* 13 */
/* 2402 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2406 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2408 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2410 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter name */

/* 2418 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2420 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2422 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter pDbSys */


	/* Parameter pDbSys */

/* 2424 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2426 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2428 */	NdrFcShort( 0x146 ),	/* Type Offset=326 */

	/* Parameter pCreated */


	/* Parameter pCreated */

/* 2430 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2432 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2436 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2438 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAccessTime */

/* 2442 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2444 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2448 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2450 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2454 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2456 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2458 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2464 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAccessTime */

/* 2466 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2468 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2470 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 2472 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2474 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBagId */

/* 2478 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2484 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2486 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2490 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2492 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2494 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2500 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 2502 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2504 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2506 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 2508 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2510 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileId */


	/* Procedure GetFileId */


	/* Procedure GetBagOffset */

/* 2514 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2516 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2520 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2522 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2526 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2528 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2530 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2536 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */


	/* Parameter pFileId */


	/* Parameter pOffset */

/* 2538 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2540 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2542 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2546 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOffset */

/* 2550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2556 */	NdrFcShort( 0x1b ),	/* 27 */
/* 2558 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2562 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2564 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2566 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 2574 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2576 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2578 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2582 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 2586 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2592 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2594 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2596 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2598 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2600 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2602 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2608 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppPath */

/* 2610 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2612 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2614 */	NdrFcShort( 0xe0 ),	/* Type Offset=224 */

	/* Parameter bufferSize */

/* 2616 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2618 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2622 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2624 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecallTime */

/* 2628 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2634 */	NdrFcShort( 0x1d ),	/* 29 */
/* 2636 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2640 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2642 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2644 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 2652 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2654 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2656 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 2658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2660 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSize */

/* 2664 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2670 */	NdrFcShort( 0x1e ),	/* 30 */
/* 2672 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2676 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2678 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2680 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 2688 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2690 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2692 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2696 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsWaitingForClose */

/* 2700 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2706 */	NdrFcShort( 0x1f ),	/* 31 */
/* 2708 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2714 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2716 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2722 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2726 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAccessTime */

/* 2730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2736 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2738 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2740 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2742 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2744 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2746 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2752 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAccessTime */

/* 2754 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2756 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2758 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 2760 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2762 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2764 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFromScanItem */

/* 2766 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2768 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2772 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2774 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2776 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2778 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2780 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2782 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2788 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 2790 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2792 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2794 */	NdrFcShort( 0x15c ),	/* Type Offset=348 */

	/* Parameter offset */

/* 2796 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2798 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2800 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 2802 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2804 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2806 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter isWaitingForClose */

/* 2808 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2810 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2814 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2816 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagId */

/* 2820 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2826 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2828 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2830 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2834 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2836 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 2844 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2846 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2848 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 2850 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2852 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagOffset */

/* 2856 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2858 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2862 */	NdrFcShort( 0x23 ),	/* 35 */
/* 2864 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2866 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2868 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2870 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2872 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2878 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 2880 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2882 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2884 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2888 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileId */

/* 2892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2900 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2902 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2904 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2906 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2908 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */

/* 2916 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2918 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2920 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2922 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2924 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2926 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileUSN */

/* 2928 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2930 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2934 */	NdrFcShort( 0x25 ),	/* 37 */
/* 2936 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2938 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2942 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2944 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2950 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileUSN */

/* 2952 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2954 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2956 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2958 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2960 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2962 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsWaitingForClose */

/* 2964 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2966 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2970 */	NdrFcShort( 0x26 ),	/* 38 */
/* 2972 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2978 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2980 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2986 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isWaiting */

/* 2988 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2990 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2994 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2996 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOffset */

/* 3000 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3006 */	NdrFcShort( 0x27 ),	/* 39 */
/* 3008 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3010 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3014 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3016 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 3024 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3026 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3028 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3030 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3032 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPath */

/* 3036 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3038 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3044 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3050 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3052 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3060 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3062 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3064 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 3066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3068 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRecallTime */

/* 3072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3078 */	NdrFcShort( 0x29 ),	/* 41 */
/* 3080 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3082 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3086 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3088 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3094 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter time */

/* 3096 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3098 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3100 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 3102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3104 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSize */

/* 3108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3114 */	NdrFcShort( 0x2a ),	/* 42 */
/* 3116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3118 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3122 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3124 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 3132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3136 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3140 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaId */


	/* Procedure GetBagId */

/* 3144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3150 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3156 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3158 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3160 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */


	/* Parameter pId */

/* 3168 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3172 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */


	/* Return value */

/* 3174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileOffset */


	/* Procedure GetBagOffset */

/* 3180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3186 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3192 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3194 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3196 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */


	/* Parameter pOffset */

/* 3204 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3206 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3208 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOffsetSize */

/* 3216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3222 */	NdrFcShort( 0x19 ),	/* 25 */
/* 3224 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3228 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3230 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3232 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 3240 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3244 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSize */

/* 3246 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3250 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3254 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 3258 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3264 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3266 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3272 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3274 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppPath */

/* 3282 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3284 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3286 */	NdrFcShort( 0xe0 ),	/* Type Offset=224 */

	/* Parameter bufferSize */

/* 3288 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3290 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecoveryCount */

/* 3300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3306 */	NdrFcShort( 0x1b ),	/* 27 */
/* 3308 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3316 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCount */

/* 3324 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStatus */

/* 3336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3342 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3344 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3348 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3350 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3352 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStatus */

/* 3360 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagId */

/* 3372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3378 */	NdrFcShort( 0x1d ),	/* 29 */
/* 3380 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3382 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3386 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3388 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 3396 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3398 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3400 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 3402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3404 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagOffset */

/* 3408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3414 */	NdrFcShort( 0x1e ),	/* 30 */
/* 3416 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3418 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3420 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3422 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3424 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 3432 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3434 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3436 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3440 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileId */

/* 3444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3450 */	NdrFcShort( 0x1f ),	/* 31 */
/* 3452 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3454 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3458 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */

/* 3468 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3472 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3476 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOffsetSize */

/* 3480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3486 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3488 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3490 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3494 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Offset */

/* 3504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3508 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter Size */

/* 3510 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3512 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3514 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3516 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3518 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPath */

/* 3522 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3528 */	NdrFcShort( 0x21 ),	/* 33 */
/* 3530 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3536 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3538 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3546 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3548 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3550 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 3552 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3554 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRecoveryCount */

/* 3558 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3564 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3566 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3568 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3572 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3574 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3580 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Count */

/* 3582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3584 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3590 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStatus */

/* 3594 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3600 */	NdrFcShort( 0x23 ),	/* 35 */
/* 3602 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3604 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3608 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3610 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3616 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Status */

/* 3618 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3620 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3626 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaId */

/* 3630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3636 */	NdrFcShort( 0x19 ),	/* 25 */
/* 3638 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3640 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3644 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3646 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3652 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 3654 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3656 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3658 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 3660 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3662 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileOffset */

/* 3666 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3668 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3672 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3674 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3676 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3678 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3680 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3682 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3688 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 3690 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3692 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3694 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3698 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileId */

/* 3702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3708 */	NdrFcShort( 0x1b ),	/* 27 */
/* 3710 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3712 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3716 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3718 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3724 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */

/* 3726 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3728 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3730 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3732 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3736 */	0x8,		/* FC_LONG */
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
/*  4 */	NdrFcLong( 0xc49d553d ),	/* -996321987 */
/*  8 */	NdrFcShort( 0xca2b ),	/* -13781 */
/* 10 */	NdrFcShort( 0x4482 ),	/* 17538 */
/* 12 */	0xa4,		/* 164 */
			0x4,		/* 4 */
/* 14 */	0xcd,		/* 205 */
			0x4b,		/* 75 */
/* 16 */	0x6b,		/* 107 */
			0x44,		/* 68 */
/* 18 */	0xea,		/* 234 */
			0xe4,		/* 228 */
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
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 40 */	NdrFcLong( 0x23a05997 ),	/* 597711255 */
/* 44 */	NdrFcShort( 0xda21 ),	/* -9695 */
/* 46 */	NdrFcShort( 0x4998 ),	/* 18840 */
/* 48 */	0xa3,		/* 163 */
			0x54,		/* 84 */
/* 50 */	0x87,		/* 135 */
			0x97,		/* 151 */
/* 52 */	0x30,		/* 48 */
			0x3f,		/* 63 */
/* 54 */	0xb9,		/* 185 */
			0x1e,		/* 30 */
/* 56 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 58 */	NdrFcShort( 0x2 ),	/* Offset= 2 (60) */
/* 60 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 62 */	NdrFcLong( 0x560e5a02 ),	/* 1443781122 */
/* 66 */	NdrFcShort( 0xdede ),	/* -8482 */
/* 68 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 70 */	0xa9,		/* 169 */
			0xf5,		/* 245 */
/* 72 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 74 */	0x24,		/* 36 */
			0x89,		/* 137 */
/* 76 */	0x3,		/* 3 */
			0xea,		/* 234 */
/* 78 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 80 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 82 */	
			0x11, 0x0,	/* FC_RP */
/* 84 */	NdrFcShort( 0xa ),	/* Offset= 10 (94) */
/* 86 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 88 */	NdrFcShort( 0x8 ),	/* 8 */
/* 90 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 92 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 94 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 96 */	NdrFcShort( 0x98 ),	/* 152 */
/* 98 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 100 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 102 */	0x0,		/* 0 */
			NdrFcShort( 0xffef ),	/* Offset= -17 (86) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 106 */	0x0,		/* 0 */
			NdrFcShort( 0xffaf ),	/* Offset= -81 (26) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 110 */	0x0,		/* 0 */
			NdrFcShort( 0xffab ),	/* Offset= -85 (26) */
			0x40,		/* FC_STRUCTPAD4 */
/* 114 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 116 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 118 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 120 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 122 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 124 */	NdrFcShort( 0xffda ),	/* Offset= -38 (86) */
/* 126 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 128 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 130 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 132 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 134 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 138 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 140 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 142 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 144 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 146 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 148 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 150 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 152 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 154 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 156 */	NdrFcLong( 0x3defb163 ),	/* 1039118691 */
/* 160 */	NdrFcShort( 0xbaec ),	/* -17684 */
/* 162 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 164 */	0x9e,		/* 158 */
			0xe9,		/* 233 */
/* 166 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 168 */	0x4b,		/* 75 */
			0x22,		/* 34 */
/* 170 */	0x6b,		/* 107 */
			0x3e,		/* 62 */
/* 172 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 174 */	NdrFcShort( 0x2 ),	/* Offset= 2 (176) */
/* 176 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 178 */	NdrFcLong( 0xc ),	/* 12 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 188 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 190 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 192 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 194 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 196 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 198 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 200 */	NdrFcLong( 0x5e176f27 ),	/* 1578594087 */
/* 204 */	NdrFcShort( 0x6f53 ),	/* 28499 */
/* 206 */	NdrFcShort( 0x4c84 ),	/* 19588 */
/* 208 */	0xb9,		/* 185 */
			0x35,		/* 53 */
/* 210 */	0x92,		/* 146 */
			0x59,		/* 89 */
/* 212 */	0x29,		/* 41 */
			0x76,		/* 118 */
/* 214 */	0x69,		/* 105 */
			0xb0,		/* 176 */
/* 216 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 218 */	NdrFcShort( 0xff40 ),	/* Offset= -192 (26) */
/* 220 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 222 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 224 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 226 */	NdrFcShort( 0x2 ),	/* Offset= 2 (228) */
/* 228 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 230 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 232 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 234 */	NdrFcShort( 0x2 ),	/* Offset= 2 (236) */
/* 236 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 238 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 242 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 244 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 246 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 248 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 250 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 252 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 254 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 256 */	NdrFcShort( 0x2 ),	/* Offset= 2 (258) */
/* 258 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 260 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 264 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 266 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 268 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 270 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 272 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 274 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 276 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 278 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 280 */	
			0x11, 0x0,	/* FC_RP */
/* 282 */	NdrFcShort( 0xff00 ),	/* Offset= -256 (26) */
/* 284 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 286 */	NdrFcShort( 0x2 ),	/* Offset= 2 (288) */
/* 288 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 290 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 292 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 294 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 296 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 298 */	NdrFcShort( 0x2 ),	/* Offset= 2 (300) */
/* 300 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 302 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 306 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 308 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 310 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 314 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 316 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 318 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 320 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 322 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 324 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 326 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 328 */	NdrFcLong( 0xf2608980 ),	/* -228554368 */
/* 332 */	NdrFcShort( 0xa45 ),	/* 2629 */
/* 334 */	NdrFcShort( 0x47b4 ),	/* 18356 */
/* 336 */	0xb1,		/* 177 */
			0x10,		/* 16 */
/* 338 */	0x37,		/* 55 */
			0xea,		/* 234 */
/* 340 */	0x59,		/* 89 */
			0xf6,		/* 246 */
/* 342 */	0x7c,		/* 124 */
			0x47,		/* 71 */
/* 344 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 346 */	NdrFcShort( 0xfefc ),	/* Offset= -260 (86) */
/* 348 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 350 */	NdrFcLong( 0x87e7ed0 ),	/* 142507728 */
/* 354 */	NdrFcShort( 0x727a ),	/* 29306 */
/* 356 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 358 */	0x9c,		/* 156 */
			0xd3,		/* 211 */
/* 360 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 362 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 364 */	0x81,		/* 129 */
			0x2,		/* 2 */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_fsaprv_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IFsaFilterPriv, ver. 0.0,
   GUID={0x3DEFB163,0xBAEC,0x11d2,{0x9E,0xE9,0x00,0x10,0x4B,0x22,0x6B,0x3E}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaFilterPriv_FormatStringOffsetTable[] =
    {
    0,
    36,
    72,
    102,
    132,
    168
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaFilterPriv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaFilterPriv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IFsaFilterPrivProxyVtbl = 
{
    &IFsaFilterPriv_ProxyInfo,
    &IID_IFsaFilterPriv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::Init */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::SetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::IoctlThread */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::PipeThread */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::SendCancel */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::SendComplete */
};

const CInterfaceStubVtbl _IFsaFilterPrivStubVtbl =
{
    &IID_IFsaFilterPriv,
    &IFsaFilterPriv_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaFilterRecallPriv, ver. 0.0,
   GUID={0x23A05997,0xDA21,0x4998,{0xA3,0x54,0x87,0x97,0x30,0x3F,0xB9,0x1E}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaFilterRecallPriv_FormatStringOffsetTable[] =
    {
    210,
    240,
    72,
    270,
    306,
    342,
    378,
    414,
    450,
    540,
    576,
    618,
    654,
    696,
    738,
    780,
    822,
    858,
    894,
    930,
    966,
    1008,
    1044,
    1080,
    1116,
    1152,
    1194,
    1224
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaFilterRecallPriv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterRecallPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaFilterRecallPriv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterRecallPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(31) _IFsaFilterRecallPrivProxyVtbl = 
{
    &IFsaFilterRecallPriv_ProxyInfo,
    &IID_IFsaFilterRecallPriv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::Cancel */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CancelByDriver */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::Delete */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetClient */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetDriversRecallId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::SetDriversRecallId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::SetThreadId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::Init */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::SetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::StartRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetStream */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CompareToIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CompareToIRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CompareToDriversRecallId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CompareToDriversContextId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CompareBy */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetMode */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetResource */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetState */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::WasCancelled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::LogComplete */
};

const CInterfaceStubVtbl _IFsaFilterRecallPrivStubVtbl =
{
    &IID_IFsaFilterRecallPriv,
    &IFsaFilterRecallPriv_ServerInfo,
    31,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSystemState, ver. 0.0,
   GUID={0x3F0DA041,0x69F1,0x11d2,{0xAF,0x82,0x00,0x10,0x4B,0x9A,0x37,0x58}} */


/* Object interface: IFsaResourcePriv, ver. 0.0,
   GUID={0xBFAB9D53,0x4D27,0x4B22,{0xBC,0xEA,0xB8,0x3C,0x29,0xE7,0xD5,0x09}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaResourcePriv_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    1260,
    1296,
    102,
    1332,
    1422,
    1476,
    1518,
    1560,
    1590,
    1620,
    1668,
    1704,
    1740,
    1776,
    1812,
    1848,
    1884,
    1920,
    1956,
    1992,
    2028,
    2070
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaResourcePriv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaResourcePriv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaResourcePriv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaResourcePriv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IFsaResourcePrivProxyVtbl = 
{
    &IFsaResourcePriv_ProxyInfo,
    &IID_IFsaResourcePriv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::AddPremigratedSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::AddTruncatedSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::DoRecovery */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::FilterSawOpen */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::FilterSawDelete */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::GetPremigrated */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::GetUnmanageDb */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::InitializeUnmanageDb */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::TerminateUnmanageDb */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::Init */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::RemovePremigratedSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::RemoveTruncatedSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetAlternatePath */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetName */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetOldPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetUserFriendlyName */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetStickyName */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetSerial */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::UpdateFrom */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::GetMaxFileLogicalSize */
};


static const PRPC_STUB_FUNCTION IFsaResourcePriv_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaResourcePrivStubVtbl =
{
    &IID_IFsaResourcePriv,
    &IFsaResourcePriv_ServerInfo,
    26,
    &IFsaResourcePriv_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaScanItemPriv, ver. 0.0,
   GUID={0x03150C1E,0x9580,0x4A1F,{0x91,0xB3,0xBE,0x23,0x67,0xE4,0xF4,0x00}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaScanItemPriv_FormatStringOffsetTable[] =
    {
    2106,
    2154,
    2196,
    102,
    2238,
    2268,
    2298,
    2340
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaScanItemPriv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaScanItemPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaScanItemPriv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaScanItemPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IFsaScanItemPrivProxyVtbl = 
{
    &IFsaScanItemPriv_ProxyInfo,
    &IID_IFsaScanItemPriv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindFirst */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindFirstInRPIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindFirstInDbIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindNext */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindNextInRPIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindNextInDbIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::TruncateInternal */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::VerifyInternal */
};

const CInterfaceStubVtbl _IFsaScanItemPrivStubVtbl =
{
    &IID_IFsaScanItemPriv,
    &IFsaScanItemPriv_ServerInfo,
    11,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDb, ver. 0.0,
   GUID={0xD7A42F4A,0x117C,0x47A3,{0x9C,0x30,0x92,0xD6,0x3A,0x49,0x19,0xE4}} */


/* Object interface: IFsaPremigratedDb, ver. 0.0,
   GUID={0xE4D900C9,0xDFD0,0x4F8D,{0x8F,0x44,0x15,0x55,0xC2,0xE3,0xE1,0x5F}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaPremigratedDb_FormatStringOffsetTable[] =
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
    2394
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaPremigratedDb_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaPremigratedDb_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaPremigratedDb_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaPremigratedDb_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IFsaPremigratedDbProxyVtbl = 
{
    &IFsaPremigratedDb_ProxyInfo,
    &IID_IFsaPremigratedDb,
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
    (void *) (INT_PTR) -1 /* IFsaPremigratedDb::Init */
};


static const PRPC_STUB_FUNCTION IFsaPremigratedDb_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaPremigratedDbStubVtbl =
{
    &IID_IFsaPremigratedDb,
    &IFsaPremigratedDb_ServerInfo,
    14,
    &IFsaPremigratedDb_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IWsbDbEntity, ver. 0.0,
   GUID={0xFC7FB18F,0xF497,0x47A6,{0xA2,0x8F,0x7C,0xC4,0xBF,0xEC,0xAA,0x5E}} */


/* Object interface: IFsaPremigratedRec, ver. 0.0,
   GUID={0x5E2526D3,0x400D,0x11d1,{0xA3,0xD5,0x00,0x60,0x97,0x04,0xF7,0x87}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaPremigratedRec_FormatStringOffsetTable[] =
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
    2442,
    2478,
    2514,
    2070,
    1080,
    2550,
    2586,
    2628,
    2664,
    2700,
    2730,
    2766,
    2820,
    2856,
    2892,
    2928,
    2964,
    3000,
    3036,
    3072,
    3108
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaPremigratedRec_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaPremigratedRec_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaPremigratedRec_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaPremigratedRec_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(43) _IFsaPremigratedRecProxyVtbl = 
{
    &IFsaPremigratedRec_ProxyInfo,
    &IID_IFsaPremigratedRec,
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
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetAccessTime */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetBagId */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetBagOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetFileUSN */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::IsWaitingForClose */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetAccessTime */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetFromScanItem */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetBagId */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetBagOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetFileUSN */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetIsWaitingForClose */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetSize */
};


static const PRPC_STUB_FUNCTION IFsaPremigratedRec_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaPremigratedRecStubVtbl =
{
    &IID_IFsaPremigratedRec,
    &IFsaPremigratedRec_ServerInfo,
    43,
    &IFsaPremigratedRec_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaRecoveryRec, ver. 0.0,
   GUID={0x74D85681,0x44D8,0x11d1,{0xA3,0xD7,0x00,0x60,0x97,0x04,0xF7,0x87}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaRecoveryRec_FormatStringOffsetTable[] =
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
    3144,
    3180,
    2514,
    3216,
    3258,
    3300,
    3336,
    3372,
    3408,
    3444,
    3480,
    3522,
    3558,
    3594
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaRecoveryRec_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaRecoveryRec_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaRecoveryRec_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaRecoveryRec_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(36) _IFsaRecoveryRecProxyVtbl = 
{
    &IFsaRecoveryRec_ProxyInfo,
    &IID_IFsaRecoveryRec,
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
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetBagId */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetBagOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetOffsetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetRecoveryCount */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetStatus */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetBagId */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetBagOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetOffsetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetRecoveryCount */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetStatus */
};


static const PRPC_STUB_FUNCTION IFsaRecoveryRec_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaRecoveryRecStubVtbl =
{
    &IID_IFsaRecoveryRec,
    &IFsaRecoveryRec_ServerInfo,
    36,
    &IFsaRecoveryRec_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaUnmanageDb, ver. 0.0,
   GUID={0x3F676047,0x90B6,0x48D6,{0xB4,0x79,0x28,0xE5,0x7A,0xD4,0xB7,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaUnmanageDb_FormatStringOffsetTable[] =
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
    2394
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaUnmanageDb_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaUnmanageDb_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaUnmanageDb_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaUnmanageDb_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IFsaUnmanageDbProxyVtbl = 
{
    &IFsaUnmanageDb_ProxyInfo,
    &IID_IFsaUnmanageDb,
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
    (void *) (INT_PTR) -1 /* IFsaUnmanageDb::Init */
};


static const PRPC_STUB_FUNCTION IFsaUnmanageDb_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaUnmanageDbStubVtbl =
{
    &IID_IFsaUnmanageDb,
    &IFsaUnmanageDb_ServerInfo,
    14,
    &IFsaUnmanageDb_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaUnmanageRec, ver. 0.0,
   GUID={0x90D54B53,0xEDB6,0x401D,{0x81,0xC5,0x47,0xD7,0xB4,0x84,0x2E,0xC0}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaUnmanageRec_FormatStringOffsetTable[] =
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
    3144,
    3180,
    2514,
    3630,
    3666,
    3702
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaUnmanageRec_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaUnmanageRec_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaUnmanageRec_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaUnmanageRec_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(28) _IFsaUnmanageRecProxyVtbl = 
{
    &IFsaUnmanageRec_ProxyInfo,
    &IID_IFsaUnmanageRec,
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
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::GetMediaId */ ,
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::GetFileOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::GetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::SetMediaId */ ,
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::SetFileOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::SetFileId */
};


static const PRPC_STUB_FUNCTION IFsaUnmanageRec_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaUnmanageRecStubVtbl =
{
    &IID_IFsaUnmanageRec,
    &IFsaUnmanageRec_ServerInfo,
    28,
    &IFsaUnmanageRec_table[-3],
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

const CInterfaceProxyVtbl * _fsaprv_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IFsaScanItemPrivProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaUnmanageDbProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaUnmanageRecProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaResourcePrivProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaFilterPrivProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaRecoveryRecProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaFilterRecallPrivProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaPremigratedDbProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaPremigratedRecProxyVtbl,
    0
};

const CInterfaceStubVtbl * _fsaprv_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IFsaScanItemPrivStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaUnmanageDbStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaUnmanageRecStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaResourcePrivStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaFilterPrivStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaRecoveryRecStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaFilterRecallPrivStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaPremigratedDbStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaPremigratedRecStubVtbl,
    0
};

PCInterfaceName const _fsaprv_InterfaceNamesList[] = 
{
    "IFsaScanItemPriv",
    "IFsaUnmanageDb",
    "IFsaUnmanageRec",
    "IFsaResourcePriv",
    "IFsaFilterPriv",
    "IFsaRecoveryRec",
    "IFsaFilterRecallPriv",
    "IFsaPremigratedDb",
    "IFsaPremigratedRec",
    0
};

const IID *  _fsaprv_BaseIIDList[] = 
{
    0,
    &IID_IWsbDb,
    &IID_IWsbDbEntity,
    &IID_IHsmSystemState,
    0,
    &IID_IWsbDbEntity,
    0,
    &IID_IWsbDb,
    &IID_IWsbDbEntity,
    0
};


#define _fsaprv_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _fsaprv, pIID, n)

int __stdcall _fsaprv_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _fsaprv, 9, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaprv, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaprv, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaprv, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _fsaprv, 9, *pIndex )
    
}

const ExtendedProxyFileInfo fsaprv_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _fsaprv_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _fsaprv_StubVtblList,
    (const PCInterfaceName * ) & _fsaprv_InterfaceNamesList,
    (const IID ** ) & _fsaprv_BaseIIDList,
    & _fsaprv_IID_Lookup, 
    9,
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
/* Compiler settings for fsaprv.idl:
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


#include "fsaprv.h"

#define TYPE_FORMAT_STRING_SIZE   367                               
#define PROC_FORMAT_STRING_SIZE   3933                              
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


extern const MIDL_SERVER_INFO IFsaFilterPriv_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaFilterPriv_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaFilterRecallPriv_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaFilterRecallPriv_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaResourcePriv_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaResourcePriv_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaScanItemPriv_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaScanItemPriv_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaPremigratedDb_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaPremigratedDb_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaPremigratedRec_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaPremigratedRec_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaRecoveryRec_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaRecoveryRec_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaUnmanageDb_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaUnmanageDb_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFsaUnmanageRec_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFsaUnmanageRec_ProxyInfo;



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
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 26 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 28 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 32 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIdentifier */

/* 38 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x4 ),	/* 4 */
/* 46 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 48 */	NdrFcShort( 0x30 ),	/* 48 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 54 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 64 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 66 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 68 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 70 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 72 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Delete */


	/* Procedure IoctlThread */

/* 76 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 78 */	NdrFcLong( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x5 ),	/* 5 */
/* 84 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x8 ),	/* 8 */
/* 90 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 92 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNext */


	/* Procedure DoRecovery */


	/* Procedure PipeThread */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x6 ),	/* 6 */
/* 116 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 122 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 124 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 136 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendCancel */

/* 140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0x7 ),	/* 7 */
/* 148 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 154 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 156 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecallPriv */

/* 166 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 168 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 170 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 172 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 174 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendComplete */

/* 178 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 180 */	NdrFcLong( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 186 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 192 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 194 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recall */

/* 204 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 206 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 208 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter result */

/* 210 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 212 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 216 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 218 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cancel */

/* 222 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 224 */	NdrFcLong( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x3 ),	/* 3 */
/* 230 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 236 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 238 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 250 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelByDriver */

/* 254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x4 ),	/* 4 */
/* 262 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 268 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 270 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 282 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetClient */

/* 286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x6 ),	/* 6 */
/* 294 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 300 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 302 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppClient */

/* 312 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 314 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 316 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */

/* 318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 320 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDriversRecallId */

/* 324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x7 ),	/* 7 */
/* 332 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x2c ),	/* 44 */
/* 338 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 340 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 350 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 352 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 354 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 358 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDriversRecallId */

/* 362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 370 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 372 */	NdrFcShort( 0x10 ),	/* 16 */
/* 374 */	NdrFcShort( 0x8 ),	/* 8 */
/* 376 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 378 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 388 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 390 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 392 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 396 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetThreadId */

/* 400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0x9 ),	/* 9 */
/* 408 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 414 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 416 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 428 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 434 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPlaceholder */

/* 438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0xa ),	/* 10 */
/* 446 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x124 ),	/* 292 */
/* 452 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 454 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPlaceholder */

/* 464 */	NdrFcShort( 0x112 ),	/* Flags:  must free, out, simple ref, */
/* 466 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 468 */	NdrFcShort( 0x5e ),	/* Type Offset=94 */

	/* Return value */

/* 470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 472 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0xb ),	/* 11 */
/* 484 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 486 */	NdrFcShort( 0x164 ),	/* 356 */
/* 488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 490 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 492 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClient */

/* 502 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 504 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 506 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pDriversRecallId */

/* 508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 510 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 512 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pResource */

/* 514 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 516 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 518 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Parameter path */

/* 520 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 522 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 524 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter fileId */

/* 526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 528 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 530 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter offset */

/* 532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 534 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 536 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 538 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 540 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 542 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter mode */

/* 544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 546 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 550 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 552 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 554 */	NdrFcShort( 0x5e ),	/* Type Offset=94 */

	/* Parameter pFilterPriv */

/* 556 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 558 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 560 */	NdrFcShort( 0x9a ),	/* Type Offset=154 */

	/* Return value */

/* 562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 564 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIdentifier */

/* 568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0xc ),	/* 12 */
/* 576 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 578 */	NdrFcShort( 0x30 ),	/* 48 */
/* 580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 582 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 584 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 594 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 596 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 598 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 602 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StartRecall */

/* 606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 612 */	NdrFcShort( 0xd ),	/* 13 */
/* 614 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 616 */	NdrFcShort( 0x20 ),	/* 32 */
/* 618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 620 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 622 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 632 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 634 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 636 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 638 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 640 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 642 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 646 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStream */

/* 650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0xe ),	/* 14 */
/* 658 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x8 ),	/* 8 */
/* 664 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 666 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppStream */

/* 676 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 678 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 680 */	NdrFcShort( 0xac ),	/* Type Offset=172 */

	/* Return value */

/* 682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 684 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIdentifier */

/* 688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0xf ),	/* 15 */
/* 696 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 698 */	NdrFcShort( 0x30 ),	/* 48 */
/* 700 */	NdrFcShort( 0x22 ),	/* 34 */
/* 702 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 704 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 714 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 716 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 718 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter pResult */

/* 720 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 722 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 724 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 728 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIRecall */

/* 732 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 734 */	NdrFcLong( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x10 ),	/* 16 */
/* 740 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x22 ),	/* 34 */
/* 746 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 748 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRecall */

/* 758 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 760 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 762 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Parameter pResult */

/* 764 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 766 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 768 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 772 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToDriversRecallId */

/* 776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x11 ),	/* 17 */
/* 784 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 786 */	NdrFcShort( 0x10 ),	/* 16 */
/* 788 */	NdrFcShort( 0x22 ),	/* 34 */
/* 790 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 792 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 802 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 804 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 806 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 808 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 810 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 812 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 814 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 816 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToDriversContextId */

/* 820 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x12 ),	/* 18 */
/* 828 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 830 */	NdrFcShort( 0x10 ),	/* 16 */
/* 832 */	NdrFcShort( 0x22 ),	/* 34 */
/* 834 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 836 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 848 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 850 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 852 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 854 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 856 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 860 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareBy */

/* 864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x13 ),	/* 19 */
/* 872 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 874 */	NdrFcShort( 0x6 ),	/* 6 */
/* 876 */	NdrFcShort( 0x8 ),	/* 8 */
/* 878 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 880 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter by */

/* 890 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 892 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 894 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 898 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x14 ),	/* 20 */
/* 910 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 914 */	NdrFcShort( 0x4c ),	/* 76 */
/* 916 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 918 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 928 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 930 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 932 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 934 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 936 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMode */

/* 940 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 946 */	NdrFcShort( 0x15 ),	/* 21 */
/* 948 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x24 ),	/* 36 */
/* 954 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 956 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMode */

/* 966 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 968 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 974 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOffset */

/* 978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0x16 ),	/* 22 */
/* 986 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x2c ),	/* 44 */
/* 992 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 994 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 1004 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1006 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1008 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1010 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1012 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1014 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 1016 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1018 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1022 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1024 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1026 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1028 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1030 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1032 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1042 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1044 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1046 */	NdrFcShort( 0xe0 ),	/* Type Offset=224 */

	/* Parameter bufferSize */

/* 1048 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1050 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1052 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1054 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1056 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1058 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResource */

/* 1060 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1062 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1066 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1068 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1074 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1076 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppResource */

/* 1086 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1088 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1090 */	NdrFcShort( 0xe8 ),	/* Type Offset=232 */

	/* Return value */

/* 1092 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1094 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 1098 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1106 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1112 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1114 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 1124 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1126 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1128 */	NdrFcShort( 0xfe ),	/* Type Offset=254 */

	/* Return value */

/* 1130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1132 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileUSN */


	/* Procedure GetSize */

/* 1136 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1142 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1144 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1148 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1150 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1152 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileUSN */


	/* Parameter pSize */

/* 1162 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1164 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1166 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1170 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 1174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1182 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1186 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1188 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1190 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 1200 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1202 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1204 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1206 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1208 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUserName */

/* 1212 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1214 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1220 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1222 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1224 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1226 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1228 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1238 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1240 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1242 */	NdrFcShort( 0xe0 ),	/* Type Offset=224 */

	/* Parameter bufferSize */

/* 1244 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1246 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1252 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WasCancelled */

/* 1256 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1264 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1270 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1272 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1284 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LogComplete */

/* 1288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1294 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1296 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1302 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1304 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hr */

/* 1314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1316 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1320 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1322 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddPremigratedSize */

/* 1326 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1332 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1334 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1336 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1338 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1340 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1342 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter size */

/* 1352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1354 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1356 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1360 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddTruncatedSize */

/* 1364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1370 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1372 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1374 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1378 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1380 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter size */

/* 1390 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1392 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1394 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1398 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FilterSawOpen */

/* 1402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1408 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1410 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 1412 */	NdrFcShort( 0x164 ),	/* 356 */
/* 1414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1416 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 1418 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 1428 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1430 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1432 */	NdrFcShort( 0x102 ),	/* Type Offset=258 */

	/* Parameter pRecall */

/* 1434 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1436 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1438 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Parameter path */

/* 1440 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1442 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1444 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter fileId */

/* 1446 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1448 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1450 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter requestOffset */

/* 1452 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1454 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1456 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter requestSize */

/* 1458 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1460 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1462 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 1464 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1466 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1468 */	NdrFcShort( 0x5e ),	/* Type Offset=94 */

	/* Parameter mode */

/* 1470 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1472 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter resultAction */

/* 1476 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1478 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 1480 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 1482 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1484 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 1486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1490 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 1492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FilterSawDelete */

/* 1494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1502 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1504 */	NdrFcShort( 0x15c ),	/* 348 */
/* 1506 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1508 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1510 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filterId */

/* 1520 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1522 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1524 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter path */

/* 1526 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1528 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1530 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter size */

/* 1532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1534 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1536 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pPlaceholder */

/* 1538 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1540 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1542 */	NdrFcShort( 0x5e ),	/* Type Offset=94 */

	/* Return value */

/* 1544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1546 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPremigrated */

/* 1550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1556 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1558 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1560 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1564 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1566 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1568 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 1576 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1578 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1580 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter ppDb */

/* 1582 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1584 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1586 */	NdrFcShort( 0x11c ),	/* Type Offset=284 */

	/* Return value */

/* 1588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1590 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUnmanageDb */

/* 1594 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1600 */	NdrFcShort( 0xa ),	/* 10 */
/* 1602 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1604 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1608 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1610 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1612 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 1620 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1622 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1624 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter ppDb */

/* 1626 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1628 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1630 */	NdrFcShort( 0x128 ),	/* Type Offset=296 */

	/* Return value */

/* 1632 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1634 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeUnmanageDb */

/* 1638 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1640 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1644 */	NdrFcShort( 0xb ),	/* 11 */
/* 1646 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1652 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1654 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1662 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1664 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1666 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TerminateUnmanageDb */

/* 1670 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1672 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1676 */	NdrFcShort( 0xc ),	/* 12 */
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

	/* Procedure Init */

/* 1702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1708 */	NdrFcShort( 0xd ),	/* 13 */
/* 1710 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1716 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1718 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 1728 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1730 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1732 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter path */

/* 1734 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1736 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1738 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter dosname */

/* 1740 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1742 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1744 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1746 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1748 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemovePremigratedSize */

/* 1752 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1754 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1758 */	NdrFcShort( 0xe ),	/* 14 */
/* 1760 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1762 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1766 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1768 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1776 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter size */

/* 1778 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1780 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1782 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1784 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1786 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1788 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveTruncatedSize */

/* 1790 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1792 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0xf ),	/* 15 */
/* 1798 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1800 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1802 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1804 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1806 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter size */

/* 1816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1818 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1820 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1824 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAlternatePath */

/* 1828 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1834 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1836 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1842 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1844 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1852 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 1854 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1856 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1858 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1860 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1862 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIdentifier */

/* 1866 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1868 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1874 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1876 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1878 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1880 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1882 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 1892 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1894 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1896 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 1898 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1900 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 1904 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1906 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1910 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1912 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1916 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1918 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1920 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1930 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1932 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1934 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1938 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOldPath */

/* 1942 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1948 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1950 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1954 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1956 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1958 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1966 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter oldPath */

/* 1968 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1970 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1972 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 1974 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1976 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPath */

/* 1980 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1982 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1988 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1994 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1996 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2004 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 2006 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2008 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2010 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 2012 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2014 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUserFriendlyName */

/* 2018 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2020 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2024 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2026 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2032 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2034 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 2044 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2046 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2048 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 2050 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2052 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStickyName */

/* 2056 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2058 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2062 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2064 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2070 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2072 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 2082 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2084 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2086 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 2088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2090 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSerial */

/* 2094 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2100 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2102 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2104 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2108 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2110 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter serial */

/* 2120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2122 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2128 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateFrom */

/* 2132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2138 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2140 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2146 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2148 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pServer */

/* 2158 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2160 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2162 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pResource */

/* 2164 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2166 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2168 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Return value */

/* 2170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2172 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileId */


	/* Procedure GetMaxFileLogicalSize */

/* 2176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2182 */	NdrFcShort( 0x19 ),	/* 25 */
/* 2184 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2188 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2190 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2192 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2200 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */


	/* Parameter pSize */

/* 2202 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2204 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2206 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2210 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirst */

/* 2214 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2220 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2222 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2226 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2228 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2230 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 2240 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2242 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2244 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Parameter path */

/* 2246 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2248 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2250 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter pSession */

/* 2252 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2254 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2256 */	NdrFcShort( 0x134 ),	/* Type Offset=308 */

	/* Return value */

/* 2258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2260 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirstInRPIndex */

/* 2264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2270 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2272 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2278 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2280 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 2290 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2292 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2294 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Parameter pSession */

/* 2296 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2298 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2300 */	NdrFcShort( 0x134 ),	/* Type Offset=308 */

	/* Return value */

/* 2302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2304 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindFirstInDbIndex */

/* 2308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2314 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2316 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2322 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2324 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2332 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 2334 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2336 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2338 */	NdrFcShort( 0x84 ),	/* Type Offset=132 */

	/* Parameter pSession */

/* 2340 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2342 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2344 */	NdrFcShort( 0x134 ),	/* Type Offset=308 */

	/* Return value */

/* 2346 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2348 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNextInRPIndex */

/* 2352 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2354 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2358 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2360 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2366 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2368 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2380 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNextInDbIndex */

/* 2384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2392 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2396 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2398 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2400 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2412 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TruncateInternal */

/* 2416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2424 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2426 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2430 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2432 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 2442 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2444 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2446 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 2448 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2450 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2452 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2454 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2456 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VerifyInternal */

/* 2460 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2462 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2466 */	NdrFcShort( 0xa ),	/* 10 */
/* 2468 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2470 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2472 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2474 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2476 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2484 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter offset */

/* 2486 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2488 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2490 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 2492 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2494 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2496 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter usn1 */

/* 2498 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2500 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2502 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter usn2 */

/* 2504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2506 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2508 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2512 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */


	/* Procedure Init */

/* 2516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2522 */	NdrFcShort( 0xd ),	/* 13 */
/* 2524 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2528 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2530 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2532 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter name */

/* 2542 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2544 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2546 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter pDbSys */


	/* Parameter pDbSys */

/* 2548 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2550 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2552 */	NdrFcShort( 0x146 ),	/* Type Offset=326 */

	/* Parameter pCreated */


	/* Parameter pCreated */

/* 2554 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2556 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2562 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAccessTime */

/* 2566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2572 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2574 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2578 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2580 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2582 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAccessTime */

/* 2592 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2594 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2596 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 2598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2600 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBagId */

/* 2604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2610 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2612 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2616 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2618 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2620 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 2630 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2632 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2634 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 2636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2638 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileId */


	/* Procedure GetFileId */


	/* Procedure GetBagOffset */

/* 2642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2650 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2654 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2656 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2658 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2666 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */


	/* Parameter pFileId */


	/* Parameter pOffset */

/* 2668 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2670 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2672 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2674 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2676 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOffset */

/* 2680 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0x1b ),	/* 27 */
/* 2688 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2692 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2694 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2696 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2704 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 2706 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2708 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2710 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2712 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2714 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 2718 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2720 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2724 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2726 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2732 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2734 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppPath */

/* 2744 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2746 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2748 */	NdrFcShort( 0xe0 ),	/* Type Offset=224 */

	/* Parameter bufferSize */

/* 2750 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2752 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2758 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecallTime */

/* 2762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2768 */	NdrFcShort( 0x1d ),	/* 29 */
/* 2770 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2774 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2776 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2778 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2786 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 2788 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2790 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2792 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 2794 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2796 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSize */

/* 2800 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2802 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2806 */	NdrFcShort( 0x1e ),	/* 30 */
/* 2808 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2812 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2814 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2816 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2824 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 2826 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2828 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2830 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2834 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsWaitingForClose */

/* 2838 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2844 */	NdrFcShort( 0x1f ),	/* 31 */
/* 2846 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2852 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2854 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2864 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2866 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAccessTime */

/* 2870 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2876 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2878 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2880 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2884 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2886 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2894 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAccessTime */

/* 2896 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2898 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2900 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 2902 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2904 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFromScanItem */

/* 2908 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2910 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2914 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2916 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2918 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2922 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2924 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2932 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 2934 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2936 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2938 */	NdrFcShort( 0x15c ),	/* Type Offset=348 */

	/* Parameter offset */

/* 2940 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2942 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2944 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 2946 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2948 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2950 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter isWaitingForClose */

/* 2952 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2954 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2958 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2960 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2962 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagId */

/* 2964 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2966 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2970 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2972 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2974 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2978 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2980 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 2990 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2992 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2994 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 2996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2998 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagOffset */

/* 3002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3008 */	NdrFcShort( 0x23 ),	/* 35 */
/* 3010 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3012 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3016 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3018 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3026 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 3028 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3030 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3032 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3036 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileId */

/* 3040 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3046 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3048 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3050 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3052 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3054 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3056 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3064 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */

/* 3066 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3068 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3070 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3072 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3074 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileUSN */

/* 3078 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3080 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3084 */	NdrFcShort( 0x25 ),	/* 37 */
/* 3086 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3088 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3090 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3092 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3094 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3102 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileUSN */

/* 3104 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3106 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3108 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3112 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsWaitingForClose */

/* 3116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3122 */	NdrFcShort( 0x26 ),	/* 38 */
/* 3124 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3130 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3132 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isWaiting */

/* 3142 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3144 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3150 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOffset */

/* 3154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3160 */	NdrFcShort( 0x27 ),	/* 39 */
/* 3162 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3164 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3168 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3170 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 3180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3182 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3184 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3188 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPath */

/* 3192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3198 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3200 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3206 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3208 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3218 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3220 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3222 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 3224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3226 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRecallTime */

/* 3230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3236 */	NdrFcShort( 0x29 ),	/* 41 */
/* 3238 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3240 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3244 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3246 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3254 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter time */

/* 3256 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3258 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3260 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 3262 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3264 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSize */

/* 3268 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3270 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3274 */	NdrFcShort( 0x2a ),	/* 42 */
/* 3276 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3278 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3280 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3282 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3284 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3292 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 3294 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3296 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3298 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3302 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaId */


	/* Procedure GetBagId */

/* 3306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3314 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3318 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3320 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3322 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3330 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */


	/* Parameter pId */

/* 3332 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3334 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3336 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */


	/* Return value */

/* 3338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3340 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileOffset */


	/* Procedure GetBagOffset */

/* 3344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3350 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3352 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3356 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3358 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3360 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3368 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */


	/* Parameter pOffset */

/* 3370 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3372 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3374 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3378 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOffsetSize */

/* 3382 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3388 */	NdrFcShort( 0x19 ),	/* 25 */
/* 3390 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3394 */	NdrFcShort( 0x50 ),	/* 80 */
/* 3396 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3398 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3406 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 3408 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3410 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3412 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pSize */

/* 3414 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3416 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3418 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3422 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 3426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3432 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3434 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3440 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3442 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3450 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppPath */

/* 3452 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3454 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3456 */	NdrFcShort( 0xe0 ),	/* Type Offset=224 */

	/* Parameter bufferSize */

/* 3458 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3460 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3466 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRecoveryCount */

/* 3470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3476 */	NdrFcShort( 0x1b ),	/* 27 */
/* 3478 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3482 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3484 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3486 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3494 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCount */

/* 3496 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3498 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3502 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3504 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStatus */

/* 3508 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3510 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3514 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3516 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3520 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3522 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3524 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStatus */

/* 3534 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3536 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3540 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3542 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagId */

/* 3546 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3552 */	NdrFcShort( 0x1d ),	/* 29 */
/* 3554 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3556 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3558 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3560 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3562 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3570 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 3572 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3574 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3576 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 3578 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3580 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBagOffset */

/* 3584 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3586 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3590 */	NdrFcShort( 0x1e ),	/* 30 */
/* 3592 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3594 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3596 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3598 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3600 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3608 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 3610 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3612 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3614 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3616 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3618 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileId */

/* 3622 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3628 */	NdrFcShort( 0x1f ),	/* 31 */
/* 3630 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3632 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3634 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3636 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3638 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */

/* 3648 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3650 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3652 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3656 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOffsetSize */

/* 3660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3666 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3668 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3670 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3674 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3676 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Offset */

/* 3686 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3688 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3690 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter Size */

/* 3692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3694 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3696 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3700 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPath */

/* 3704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3710 */	NdrFcShort( 0x21 ),	/* 33 */
/* 3712 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3716 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3718 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3720 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3728 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3730 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3732 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3734 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 3736 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3738 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRecoveryCount */

/* 3742 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3744 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3748 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3750 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3754 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3756 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3758 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Count */

/* 3768 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3770 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3776 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStatus */

/* 3780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3786 */	NdrFcShort( 0x23 ),	/* 35 */
/* 3788 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3794 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3796 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Status */

/* 3806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3808 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3814 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaId */

/* 3818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3824 */	NdrFcShort( 0x19 ),	/* 25 */
/* 3826 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3828 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3832 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3834 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 3844 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3846 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3848 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 3850 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3852 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileOffset */

/* 3856 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3858 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3862 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3864 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3866 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3868 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3870 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3872 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3880 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOffset */

/* 3882 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3884 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3886 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3888 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3890 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileId */

/* 3894 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3896 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3900 */	NdrFcShort( 0x1b ),	/* 27 */
/* 3902 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3904 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3908 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3910 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3918 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFileId */

/* 3920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3922 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3924 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3928 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3930 */	0x8,		/* FC_LONG */
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
/*  4 */	NdrFcLong( 0xc49d553d ),	/* -996321987 */
/*  8 */	NdrFcShort( 0xca2b ),	/* -13781 */
/* 10 */	NdrFcShort( 0x4482 ),	/* 17538 */
/* 12 */	0xa4,		/* 164 */
			0x4,		/* 4 */
/* 14 */	0xcd,		/* 205 */
			0x4b,		/* 75 */
/* 16 */	0x6b,		/* 107 */
			0x44,		/* 68 */
/* 18 */	0xea,		/* 234 */
			0xe4,		/* 228 */
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
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 40 */	NdrFcLong( 0x23a05997 ),	/* 597711255 */
/* 44 */	NdrFcShort( 0xda21 ),	/* -9695 */
/* 46 */	NdrFcShort( 0x4998 ),	/* 18840 */
/* 48 */	0xa3,		/* 163 */
			0x54,		/* 84 */
/* 50 */	0x87,		/* 135 */
			0x97,		/* 151 */
/* 52 */	0x30,		/* 48 */
			0x3f,		/* 63 */
/* 54 */	0xb9,		/* 185 */
			0x1e,		/* 30 */
/* 56 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 58 */	NdrFcShort( 0x2 ),	/* Offset= 2 (60) */
/* 60 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 62 */	NdrFcLong( 0x560e5a02 ),	/* 1443781122 */
/* 66 */	NdrFcShort( 0xdede ),	/* -8482 */
/* 68 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 70 */	0xa9,		/* 169 */
			0xf5,		/* 245 */
/* 72 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 74 */	0x24,		/* 36 */
			0x89,		/* 137 */
/* 76 */	0x3,		/* 3 */
			0xea,		/* 234 */
/* 78 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 80 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 82 */	
			0x11, 0x0,	/* FC_RP */
/* 84 */	NdrFcShort( 0xa ),	/* Offset= 10 (94) */
/* 86 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 88 */	NdrFcShort( 0x8 ),	/* 8 */
/* 90 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 92 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 94 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 96 */	NdrFcShort( 0x98 ),	/* 152 */
/* 98 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 100 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 102 */	0x0,		/* 0 */
			NdrFcShort( 0xffef ),	/* Offset= -17 (86) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 106 */	0x0,		/* 0 */
			NdrFcShort( 0xffaf ),	/* Offset= -81 (26) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 110 */	0x0,		/* 0 */
			NdrFcShort( 0xffab ),	/* Offset= -85 (26) */
			0x40,		/* FC_STRUCTPAD4 */
/* 114 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 116 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 118 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 120 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 122 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 124 */	NdrFcShort( 0xffda ),	/* Offset= -38 (86) */
/* 126 */	0xb,		/* FC_HYPER */
			0xb,		/* FC_HYPER */
/* 128 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 130 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 132 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 134 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 138 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 140 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 142 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 144 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 146 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 148 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 150 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 152 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 154 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 156 */	NdrFcLong( 0x3defb163 ),	/* 1039118691 */
/* 160 */	NdrFcShort( 0xbaec ),	/* -17684 */
/* 162 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 164 */	0x9e,		/* 158 */
			0xe9,		/* 233 */
/* 166 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 168 */	0x4b,		/* 75 */
			0x22,		/* 34 */
/* 170 */	0x6b,		/* 107 */
			0x3e,		/* 62 */
/* 172 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 174 */	NdrFcShort( 0x2 ),	/* Offset= 2 (176) */
/* 176 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 178 */	NdrFcLong( 0xc ),	/* 12 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 188 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 190 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 192 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 194 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 196 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 198 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 200 */	NdrFcLong( 0x5e176f27 ),	/* 1578594087 */
/* 204 */	NdrFcShort( 0x6f53 ),	/* 28499 */
/* 206 */	NdrFcShort( 0x4c84 ),	/* 19588 */
/* 208 */	0xb9,		/* 185 */
			0x35,		/* 53 */
/* 210 */	0x92,		/* 146 */
			0x59,		/* 89 */
/* 212 */	0x29,		/* 41 */
			0x76,		/* 118 */
/* 214 */	0x69,		/* 105 */
			0xb0,		/* 176 */
/* 216 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 218 */	NdrFcShort( 0xff40 ),	/* Offset= -192 (26) */
/* 220 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 222 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 224 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 226 */	NdrFcShort( 0x2 ),	/* Offset= 2 (228) */
/* 228 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 230 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 232 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 234 */	NdrFcShort( 0x2 ),	/* Offset= 2 (236) */
/* 236 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 238 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 242 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 244 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 246 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 248 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 250 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 252 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 254 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 256 */	NdrFcShort( 0x2 ),	/* Offset= 2 (258) */
/* 258 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 260 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 264 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 266 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 268 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 270 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 272 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 274 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 276 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 278 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 280 */	
			0x11, 0x0,	/* FC_RP */
/* 282 */	NdrFcShort( 0xff00 ),	/* Offset= -256 (26) */
/* 284 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 286 */	NdrFcShort( 0x2 ),	/* Offset= 2 (288) */
/* 288 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 290 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 292 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 294 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 296 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 298 */	NdrFcShort( 0x2 ),	/* Offset= 2 (300) */
/* 300 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 302 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 304 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 306 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 308 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 310 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 314 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 316 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 318 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 320 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 322 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 324 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 326 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 328 */	NdrFcLong( 0xf2608980 ),	/* -228554368 */
/* 332 */	NdrFcShort( 0xa45 ),	/* 2629 */
/* 334 */	NdrFcShort( 0x47b4 ),	/* 18356 */
/* 336 */	0xb1,		/* 177 */
			0x10,		/* 16 */
/* 338 */	0x37,		/* 55 */
			0xea,		/* 234 */
/* 340 */	0x59,		/* 89 */
			0xf6,		/* 246 */
/* 342 */	0x7c,		/* 124 */
			0x47,		/* 71 */
/* 344 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 346 */	NdrFcShort( 0xfefc ),	/* Offset= -260 (86) */
/* 348 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 350 */	NdrFcLong( 0x87e7ed0 ),	/* 142507728 */
/* 354 */	NdrFcShort( 0x727a ),	/* 29306 */
/* 356 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 358 */	0x9c,		/* 156 */
			0xd3,		/* 211 */
/* 360 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 362 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 364 */	0x81,		/* 129 */
			0x2,		/* 2 */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_fsaprv_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IFsaFilterPriv, ver. 0.0,
   GUID={0x3DEFB163,0xBAEC,0x11d2,{0x9E,0xE9,0x00,0x10,0x4B,0x22,0x6B,0x3E}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaFilterPriv_FormatStringOffsetTable[] =
    {
    0,
    38,
    76,
    108,
    140,
    178
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaFilterPriv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaFilterPriv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IFsaFilterPrivProxyVtbl = 
{
    &IFsaFilterPriv_ProxyInfo,
    &IID_IFsaFilterPriv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::Init */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::SetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::IoctlThread */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::PipeThread */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::SendCancel */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterPriv::SendComplete */
};

const CInterfaceStubVtbl _IFsaFilterPrivStubVtbl =
{
    &IID_IFsaFilterPriv,
    &IFsaFilterPriv_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFsaFilterRecallPriv, ver. 0.0,
   GUID={0x23A05997,0xDA21,0x4998,{0xA3,0x54,0x87,0x97,0x30,0x3F,0xB9,0x1E}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaFilterRecallPriv_FormatStringOffsetTable[] =
    {
    222,
    254,
    76,
    286,
    324,
    362,
    400,
    438,
    476,
    568,
    606,
    650,
    688,
    732,
    776,
    820,
    864,
    902,
    940,
    978,
    1016,
    1060,
    1098,
    1136,
    1174,
    1212,
    1256,
    1288
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaFilterRecallPriv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterRecallPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaFilterRecallPriv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaFilterRecallPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(31) _IFsaFilterRecallPrivProxyVtbl = 
{
    &IFsaFilterRecallPriv_ProxyInfo,
    &IID_IFsaFilterRecallPriv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::Cancel */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CancelByDriver */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::Delete */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetClient */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetDriversRecallId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::SetDriversRecallId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::SetThreadId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetPlaceholder */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::Init */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::SetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::StartRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetStream */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CompareToIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CompareToIRecall */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CompareToDriversRecallId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CompareToDriversContextId */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::CompareBy */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetMode */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetResource */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetSession */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetState */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::GetUserName */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::WasCancelled */ ,
    (void *) (INT_PTR) -1 /* IFsaFilterRecallPriv::LogComplete */
};

const CInterfaceStubVtbl _IFsaFilterRecallPrivStubVtbl =
{
    &IID_IFsaFilterRecallPriv,
    &IFsaFilterRecallPriv_ServerInfo,
    31,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSystemState, ver. 0.0,
   GUID={0x3F0DA041,0x69F1,0x11d2,{0xAF,0x82,0x00,0x10,0x4B,0x9A,0x37,0x58}} */


/* Object interface: IFsaResourcePriv, ver. 0.0,
   GUID={0xBFAB9D53,0x4D27,0x4B22,{0xBC,0xEA,0xB8,0x3C,0x29,0xE7,0xD5,0x09}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaResourcePriv_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    1326,
    1364,
    108,
    1402,
    1494,
    1550,
    1594,
    1638,
    1670,
    1702,
    1752,
    1790,
    1828,
    1866,
    1904,
    1942,
    1980,
    2018,
    2056,
    2094,
    2132,
    2176
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaResourcePriv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaResourcePriv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaResourcePriv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaResourcePriv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IFsaResourcePrivProxyVtbl = 
{
    &IFsaResourcePriv_ProxyInfo,
    &IID_IFsaResourcePriv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::AddPremigratedSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::AddTruncatedSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::DoRecovery */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::FilterSawOpen */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::FilterSawDelete */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::GetPremigrated */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::GetUnmanageDb */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::InitializeUnmanageDb */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::TerminateUnmanageDb */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::Init */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::RemovePremigratedSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::RemoveTruncatedSize */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetAlternatePath */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetName */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetOldPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetUserFriendlyName */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetStickyName */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::SetSerial */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::UpdateFrom */ ,
    (void *) (INT_PTR) -1 /* IFsaResourcePriv::GetMaxFileLogicalSize */
};


static const PRPC_STUB_FUNCTION IFsaResourcePriv_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaResourcePrivStubVtbl =
{
    &IID_IFsaResourcePriv,
    &IFsaResourcePriv_ServerInfo,
    26,
    &IFsaResourcePriv_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaScanItemPriv, ver. 0.0,
   GUID={0x03150C1E,0x9580,0x4A1F,{0x91,0xB3,0xBE,0x23,0x67,0xE4,0xF4,0x00}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaScanItemPriv_FormatStringOffsetTable[] =
    {
    2214,
    2264,
    2308,
    108,
    2352,
    2384,
    2416,
    2460
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaScanItemPriv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaScanItemPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaScanItemPriv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaScanItemPriv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IFsaScanItemPrivProxyVtbl = 
{
    &IFsaScanItemPriv_ProxyInfo,
    &IID_IFsaScanItemPriv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindFirst */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindFirstInRPIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindFirstInDbIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindNext */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindNextInRPIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::FindNextInDbIndex */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::TruncateInternal */ ,
    (void *) (INT_PTR) -1 /* IFsaScanItemPriv::VerifyInternal */
};

const CInterfaceStubVtbl _IFsaScanItemPrivStubVtbl =
{
    &IID_IFsaScanItemPriv,
    &IFsaScanItemPriv_ServerInfo,
    11,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDb, ver. 0.0,
   GUID={0xD7A42F4A,0x117C,0x47A3,{0x9C,0x30,0x92,0xD6,0x3A,0x49,0x19,0xE4}} */


/* Object interface: IFsaPremigratedDb, ver. 0.0,
   GUID={0xE4D900C9,0xDFD0,0x4F8D,{0x8F,0x44,0x15,0x55,0xC2,0xE3,0xE1,0x5F}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaPremigratedDb_FormatStringOffsetTable[] =
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
    2516
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaPremigratedDb_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaPremigratedDb_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaPremigratedDb_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaPremigratedDb_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IFsaPremigratedDbProxyVtbl = 
{
    &IFsaPremigratedDb_ProxyInfo,
    &IID_IFsaPremigratedDb,
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
    (void *) (INT_PTR) -1 /* IFsaPremigratedDb::Init */
};


static const PRPC_STUB_FUNCTION IFsaPremigratedDb_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaPremigratedDbStubVtbl =
{
    &IID_IFsaPremigratedDb,
    &IFsaPremigratedDb_ServerInfo,
    14,
    &IFsaPremigratedDb_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IWsbDbEntity, ver. 0.0,
   GUID={0xFC7FB18F,0xF497,0x47A6,{0xA2,0x8F,0x7C,0xC4,0xBF,0xEC,0xAA,0x5E}} */


/* Object interface: IFsaPremigratedRec, ver. 0.0,
   GUID={0x5E2526D3,0x400D,0x11d1,{0xA3,0xD5,0x00,0x60,0x97,0x04,0xF7,0x87}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaPremigratedRec_FormatStringOffsetTable[] =
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
    2566,
    2604,
    2642,
    2176,
    1136,
    2680,
    2718,
    2762,
    2800,
    2838,
    2870,
    2908,
    2964,
    3002,
    3040,
    3078,
    3116,
    3154,
    3192,
    3230,
    3268
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaPremigratedRec_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaPremigratedRec_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaPremigratedRec_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaPremigratedRec_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(43) _IFsaPremigratedRecProxyVtbl = 
{
    &IFsaPremigratedRec_ProxyInfo,
    &IID_IFsaPremigratedRec,
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
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetAccessTime */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetBagId */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetBagOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetFileUSN */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::GetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::IsWaitingForClose */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetAccessTime */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetFromScanItem */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetBagId */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetBagOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetFileUSN */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetIsWaitingForClose */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetRecallTime */ ,
    (void *) (INT_PTR) -1 /* IFsaPremigratedRec::SetSize */
};


static const PRPC_STUB_FUNCTION IFsaPremigratedRec_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaPremigratedRecStubVtbl =
{
    &IID_IFsaPremigratedRec,
    &IFsaPremigratedRec_ServerInfo,
    43,
    &IFsaPremigratedRec_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaRecoveryRec, ver. 0.0,
   GUID={0x74D85681,0x44D8,0x11d1,{0xA3,0xD7,0x00,0x60,0x97,0x04,0xF7,0x87}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaRecoveryRec_FormatStringOffsetTable[] =
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
    3306,
    3344,
    2642,
    3382,
    3426,
    3470,
    3508,
    3546,
    3584,
    3622,
    3660,
    3704,
    3742,
    3780
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaRecoveryRec_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaRecoveryRec_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaRecoveryRec_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaRecoveryRec_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(36) _IFsaRecoveryRecProxyVtbl = 
{
    &IFsaRecoveryRec_ProxyInfo,
    &IID_IFsaRecoveryRec,
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
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetBagId */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetBagOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetOffsetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetRecoveryCount */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::GetStatus */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetBagId */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetBagOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetOffsetSize */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetPath */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetRecoveryCount */ ,
    (void *) (INT_PTR) -1 /* IFsaRecoveryRec::SetStatus */
};


static const PRPC_STUB_FUNCTION IFsaRecoveryRec_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaRecoveryRecStubVtbl =
{
    &IID_IFsaRecoveryRec,
    &IFsaRecoveryRec_ServerInfo,
    36,
    &IFsaRecoveryRec_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaUnmanageDb, ver. 0.0,
   GUID={0x3F676047,0x90B6,0x48D6,{0xB4,0x79,0x28,0xE5,0x7A,0xD4,0xB7,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaUnmanageDb_FormatStringOffsetTable[] =
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
    2516
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaUnmanageDb_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaUnmanageDb_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaUnmanageDb_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaUnmanageDb_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IFsaUnmanageDbProxyVtbl = 
{
    &IFsaUnmanageDb_ProxyInfo,
    &IID_IFsaUnmanageDb,
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
    (void *) (INT_PTR) -1 /* IFsaUnmanageDb::Init */
};


static const PRPC_STUB_FUNCTION IFsaUnmanageDb_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaUnmanageDbStubVtbl =
{
    &IID_IFsaUnmanageDb,
    &IFsaUnmanageDb_ServerInfo,
    14,
    &IFsaUnmanageDb_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFsaUnmanageRec, ver. 0.0,
   GUID={0x90D54B53,0xEDB6,0x401D,{0x81,0xC5,0x47,0xD7,0xB4,0x84,0x2E,0xC0}} */

#pragma code_seg(".orpc")
static const unsigned short IFsaUnmanageRec_FormatStringOffsetTable[] =
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
    3306,
    3344,
    2642,
    3818,
    3856,
    3894
    };

static const MIDL_STUBLESS_PROXY_INFO IFsaUnmanageRec_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IFsaUnmanageRec_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFsaUnmanageRec_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IFsaUnmanageRec_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(28) _IFsaUnmanageRecProxyVtbl = 
{
    &IFsaUnmanageRec_ProxyInfo,
    &IID_IFsaUnmanageRec,
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
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::GetMediaId */ ,
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::GetFileOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::GetFileId */ ,
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::SetMediaId */ ,
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::SetFileOffset */ ,
    (void *) (INT_PTR) -1 /* IFsaUnmanageRec::SetFileId */
};


static const PRPC_STUB_FUNCTION IFsaUnmanageRec_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IFsaUnmanageRecStubVtbl =
{
    &IID_IFsaUnmanageRec,
    &IFsaUnmanageRec_ServerInfo,
    28,
    &IFsaUnmanageRec_table[-3],
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

const CInterfaceProxyVtbl * _fsaprv_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IFsaScanItemPrivProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaUnmanageDbProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaUnmanageRecProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaResourcePrivProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaFilterPrivProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaRecoveryRecProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaFilterRecallPrivProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaPremigratedDbProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFsaPremigratedRecProxyVtbl,
    0
};

const CInterfaceStubVtbl * _fsaprv_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IFsaScanItemPrivStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaUnmanageDbStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaUnmanageRecStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaResourcePrivStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaFilterPrivStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaRecoveryRecStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaFilterRecallPrivStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaPremigratedDbStubVtbl,
    ( CInterfaceStubVtbl *) &_IFsaPremigratedRecStubVtbl,
    0
};

PCInterfaceName const _fsaprv_InterfaceNamesList[] = 
{
    "IFsaScanItemPriv",
    "IFsaUnmanageDb",
    "IFsaUnmanageRec",
    "IFsaResourcePriv",
    "IFsaFilterPriv",
    "IFsaRecoveryRec",
    "IFsaFilterRecallPriv",
    "IFsaPremigratedDb",
    "IFsaPremigratedRec",
    0
};

const IID *  _fsaprv_BaseIIDList[] = 
{
    0,
    &IID_IWsbDb,
    &IID_IWsbDbEntity,
    &IID_IHsmSystemState,
    0,
    &IID_IWsbDbEntity,
    0,
    &IID_IWsbDb,
    &IID_IWsbDbEntity,
    0
};


#define _fsaprv_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _fsaprv, pIID, n)

int __stdcall _fsaprv_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _fsaprv, 9, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaprv, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaprv, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _fsaprv, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _fsaprv, 9, *pIndex )
    
}

const ExtendedProxyFileInfo fsaprv_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _fsaprv_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _fsaprv_StubVtblList,
    (const PCInterfaceName * ) & _fsaprv_InterfaceNamesList,
    (const IID ** ) & _fsaprv_BaseIIDList,
    & _fsaprv_IID_Lookup, 
    9,
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

