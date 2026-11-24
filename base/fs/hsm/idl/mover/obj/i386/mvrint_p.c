

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for mvrint.idl:
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


#include "mvrint.h"

#define TYPE_FORMAT_STRING_SIZE   199                               
#define PROC_FORMAT_STRING_SIZE   1987                              
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


extern const MIDL_SERVER_INFO IDataMover_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDataMover_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRemoteStorageHint_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRemoteStorageHint_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRemoteStorage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRemoteStorage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILocalStorage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ILocalStorage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRemoteStream_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRemoteStream_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILocalStream_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ILocalStream_ProxyInfo;


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

	/* Procedure GetObjectId */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x4c ),	/* 76 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pObjectId */

/* 24 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BeginSession */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 46 */	NdrFcShort( 0xe ),	/* 14 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 52 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x2 ),	/* 2 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter remoteSessionName */

/* 60 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter remoteSessionDescription */

/* 66 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter remoteDataSet */

/* 72 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 74 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 76 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter options */

/* 78 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 80 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 84 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 86 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 88 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EndSession */

/* 90 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 92 */	NdrFcLong( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x9 ),	/* 9 */
/* 98 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0x8 ),	/* 8 */
/* 104 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 106 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 116 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StoreData */

/* 120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0xa ),	/* 10 */
/* 128 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 130 */	NdrFcShort( 0x38 ),	/* 56 */
/* 132 */	NdrFcShort( 0x1a0 ),	/* 416 */
/* 134 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xf,		/* 15 */
/* 136 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x1 ),	/* 1 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter localName */

/* 144 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 146 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 148 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter localDataStart */

/* 150 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 152 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 154 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter localDataSize */

/* 156 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 158 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 160 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter flags */

/* 162 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 164 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRemoteDataSetStart */

/* 168 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 170 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 172 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pRemoteFileStart */

/* 174 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 176 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 178 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pRemoteFileSize */

/* 180 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 182 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 184 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pRemoteDataStart */

/* 186 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 188 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 190 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pRemoteDataSize */

/* 192 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 194 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 196 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pRemoteVerificationType */

/* 198 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 200 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRemoteVerificationData */

/* 204 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 206 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 208 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pDatastreamCRCType */

/* 210 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 212 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pDatastreamCRC */

/* 216 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 218 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 220 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pUsn */

/* 222 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 224 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 226 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 230 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RecallData */

/* 234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0xb ),	/* 11 */
/* 242 */	NdrFcShort( 0x58 ),	/* x86 Stack size/offset = 88 */
/* 244 */	NdrFcShort( 0xd0 ),	/* 208 */
/* 246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 248 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xd,		/* 13 */
/* 250 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 254 */	NdrFcShort( 0x2 ),	/* 2 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter localName */

/* 258 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 260 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 262 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter localDataStart */

/* 264 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 266 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 268 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter localDataSize */

/* 270 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 272 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 274 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter flags */

/* 276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 278 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter migratedSessionName */

/* 282 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 284 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 286 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter remoteDataSetStart */

/* 288 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 290 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 292 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteFileStart */

/* 294 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 296 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 298 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteFileSize */

/* 300 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 302 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 304 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteDataStart */

/* 306 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 308 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 310 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteDataSize */

/* 312 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 314 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 316 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteVerificationType */

/* 318 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 320 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter remoteVerificationData */

/* 324 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 326 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 328 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 332 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FormatLabel */

/* 336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0xc ),	/* 12 */
/* 344 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 350 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 352 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 354 */	NdrFcShort( 0x1 ),	/* 1 */
/* 356 */	NdrFcShort( 0x2 ),	/* 2 */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter displayName */

/* 360 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 364 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter pLabel */

/* 366 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 370 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteLabel */

/* 378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0xd ),	/* 13 */
/* 386 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 392 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 394 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x1 ),	/* 1 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter label */

/* 402 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 406 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 410 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadLabel */

/* 414 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0xe ),	/* 14 */
/* 422 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0x8 ),	/* 8 */
/* 428 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 430 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 432 */	NdrFcShort( 0x1 ),	/* 1 */
/* 434 */	NdrFcShort( 0x1 ),	/* 1 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLabel */

/* 438 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 440 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 442 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 446 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VerifyLabel */

/* 450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0xf ),	/* 15 */
/* 458 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 464 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 466 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 470 */	NdrFcShort( 0x1 ),	/* 1 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter label */

/* 474 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 476 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 478 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 482 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceName */

/* 486 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x10 ),	/* 16 */
/* 494 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0x8 ),	/* 8 */
/* 500 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 502 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 504 */	NdrFcShort( 0x1 ),	/* 1 */
/* 506 */	NdrFcShort( 0x1 ),	/* 1 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 510 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 514 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 516 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceName */

/* 522 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x11 ),	/* 17 */
/* 530 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 536 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 538 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x2 ),	/* 2 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 546 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 548 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 550 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter volName */

/* 552 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 554 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 556 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 560 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLargestFreeSpace */

/* 564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x12 ),	/* 18 */
/* 572 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 574 */	NdrFcShort( 0x10 ),	/* 16 */
/* 576 */	NdrFcShort( 0x50 ),	/* 80 */
/* 578 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 580 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter freeSpace */

/* 588 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 590 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 592 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter capacity */

/* 594 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 596 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 598 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter defaultFreeSpaceLow */

/* 600 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 602 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter defaultFreeSpaceHigh */

/* 606 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 608 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 614 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetInitialOffset */

/* 618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x13 ),	/* 19 */
/* 626 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 628 */	NdrFcShort( 0x18 ),	/* 24 */
/* 630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 632 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 634 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter initialOffset */

/* 642 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 646 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 650 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCartridge */

/* 654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x14 ),	/* 20 */
/* 662 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x8 ),	/* 8 */
/* 668 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 670 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 678 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 682 */	NdrFcShort( 0x60 ),	/* Type Offset=96 */

	/* Return value */

/* 684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCartridge */

/* 690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0x15 ),	/* 21 */
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

	/* Parameter ptr */

/* 714 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 716 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 718 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */

/* 720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 722 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cancel */

/* 726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x16 ),	/* 22 */
/* 734 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 740 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 742 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 752 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateLocalStream */

/* 756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x17 ),	/* 23 */
/* 764 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 772 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x1 ),	/* 1 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 780 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 784 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter mode */

/* 786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppStream */

/* 792 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 794 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 796 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 798 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 800 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateRemoteStream */

/* 804 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 806 */	NdrFcLong( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x18 ),	/* 24 */
/* 812 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 814 */	NdrFcShort( 0xa0 ),	/* 160 */
/* 816 */	NdrFcShort( 0x8 ),	/* 8 */
/* 818 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xd,		/* 13 */
/* 820 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x3 ),	/* 3 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 828 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 830 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 832 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter mode */

/* 834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 836 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter remoteSessionName */

/* 840 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 842 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 844 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter remoteSessionDescription */

/* 846 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 848 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 850 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter remoteDataSetStart */

/* 852 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 854 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 856 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteFileStart */

/* 858 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 860 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 862 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteFileSize */

/* 864 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 866 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 868 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteDataStart */

/* 870 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 872 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 874 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteDataSize */

/* 876 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 878 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 880 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteVerificationType */

/* 882 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 884 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter remoteVerificationData */

/* 888 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 890 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 892 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter ppStream */

/* 894 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 896 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 898 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 902 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CloseStream */

/* 906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x19 ),	/* 25 */
/* 914 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 920 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 922 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 930 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 932 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Duplicate */

/* 936 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 938 */	NdrFcLong( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x1a ),	/* 26 */
/* 944 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 946 */	NdrFcShort( 0x8 ),	/* 8 */
/* 948 */	NdrFcShort( 0x60 ),	/* 96 */
/* 950 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 952 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDestination */

/* 960 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 962 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 964 */	NdrFcShort( 0x8c ),	/* Type Offset=140 */

	/* Parameter options */

/* 966 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 968 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBytesCopied */

/* 972 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 974 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 976 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pBytesReclaimed */

/* 978 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 980 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 982 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 986 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FlushBuffers */

/* 990 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x1b ),	/* 27 */
/* 998 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1004 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1006 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1014 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1016 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Recover */

/* 1020 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1026 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1028 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1034 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1036 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDeleteFile */

/* 1044 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1046 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1050 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1052 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 1056 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1058 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1064 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1070 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1072 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1082 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDataSetStart */

/* 1086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1094 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1096 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1100 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1102 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dataSetStart */

/* 1110 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1112 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1114 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1116 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1118 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileStart */

/* 1122 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1130 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1132 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1136 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1138 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileStart */

/* 1146 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1148 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1150 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1154 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileSize */

/* 1158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0xa ),	/* 10 */
/* 1166 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1168 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1172 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1174 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileSize */

/* 1182 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1184 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1186 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1190 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDataStart */

/* 1194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0xb ),	/* 11 */
/* 1202 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1204 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1208 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1210 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dataStart */

/* 1218 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1220 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1222 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1226 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDataSize */

/* 1230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0xc ),	/* 12 */
/* 1238 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1240 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1244 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1246 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dataSize */

/* 1254 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1256 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1258 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1262 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetVerificationData */

/* 1266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1272 */	NdrFcShort( 0xd ),	/* 13 */
/* 1274 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1276 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1280 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1282 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter verificationType */

/* 1290 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1292 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1294 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter verificationData */

/* 1296 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1298 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1300 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1304 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDatastreamCRC */

/* 1308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1314 */	NdrFcShort( 0xe ),	/* 14 */
/* 1316 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1318 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1322 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1324 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1330 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dataStreamCRCType */

/* 1332 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1334 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dataStreamCRC */

/* 1338 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1340 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1342 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1346 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileUSN */

/* 1350 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0xf ),	/* 15 */
/* 1358 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1360 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1362 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1364 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1366 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileUSN */

/* 1374 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1376 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1378 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1382 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetElementInformation */

/* 1386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1394 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x1a0 ),	/* 416 */
/* 1400 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0xb,		/* 11 */
/* 1402 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataSetStart */

/* 1410 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1414 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pFileStart */

/* 1416 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1420 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pFileSize */

/* 1422 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1424 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1426 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pDataStart */

/* 1428 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1430 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1432 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pDataSize */

/* 1434 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1436 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1438 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pVerificationType */

/* 1440 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1442 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVerificationData */

/* 1446 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1448 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1450 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pDataStreamCRCType */

/* 1452 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1454 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pDataStreamCRC */

/* 1458 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1460 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1462 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pFileUSN */

/* 1464 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1466 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1468 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1472 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FormatLabel */

/* 1476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1484 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1490 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1492 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1494 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1496 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter displayName */

/* 1500 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1502 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1504 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter pLabel */

/* 1506 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1510 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 1512 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1514 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteLabel */

/* 1518 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1526 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1532 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1534 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1538 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter label */

/* 1542 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1544 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1546 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 1548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1550 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadLabel */

/* 1554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1562 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1568 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1570 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1572 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1574 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLabel */

/* 1578 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1580 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1582 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 1584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1586 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VerifyLabel */

/* 1590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0xa ),	/* 10 */
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

	/* Procedure GetDeviceName */

/* 1620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0xb ),	/* 11 */
/* 1628 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1634 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1636 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1638 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1640 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1642 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1644 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1646 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1648 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 1650 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1652 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceName */

/* 1656 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1658 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1662 */	NdrFcShort( 0xc ),	/* 12 */
/* 1664 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1670 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1672 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1676 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1678 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1680 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1682 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1684 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter volName */

/* 1686 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1688 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1690 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 1692 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1694 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLargestFreeSpace */

/* 1698 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0xd ),	/* 13 */
/* 1706 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0x50 ),	/* 80 */
/* 1712 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1714 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1720 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter freeSpace */

/* 1722 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1724 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1726 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter capacity */

/* 1728 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1730 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1732 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCartridge */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0xe ),	/* 14 */
/* 1748 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1754 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1756 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 1764 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1766 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1768 */	NdrFcShort( 0x60 ),	/* Type Offset=96 */

	/* Return value */

/* 1770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1772 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCartridge */

/* 1776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0xf ),	/* 15 */
/* 1784 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1790 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1792 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 1800 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1802 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1804 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */

/* 1806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1808 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateRemoteStream */

/* 1812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1820 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1822 */	NdrFcShort( 0xe ),	/* 14 */
/* 1824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1826 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 1828 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1832 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1836 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1838 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1840 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter description */

/* 1842 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1844 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1846 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter index */

/* 1848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1850 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1852 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter options */

/* 1854 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1856 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pHint */

/* 1860 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1862 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1864 */	NdrFcShort( 0x9e ),	/* Type Offset=158 */

	/* Parameter ppStream */

/* 1866 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1868 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1870 */	NdrFcShort( 0xb0 ),	/* Type Offset=176 */

	/* Return value */

/* 1872 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1874 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CloseStream */

/* 1878 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1884 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1892 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1894 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1900 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1902 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1904 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateLocalStream */


	/* Procedure CreateRemoteStream */


	/* Procedure CreateLocalStream */

/* 1908 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1910 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1914 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1916 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1922 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1924 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1928 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter name */


	/* Parameter name */

/* 1932 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1934 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1936 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter mode */


	/* Parameter mode */


	/* Parameter mode */

/* 1938 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1940 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppStream */


	/* Parameter ppStream */


	/* Parameter ppStream */

/* 1944 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1946 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1948 */	NdrFcShort( 0xb0 ),	/* Type Offset=176 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1950 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1952 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1954 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CloseStream */


	/* Procedure CloseStream */


	/* Procedure CloseStream */

/* 1956 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1958 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1962 */	NdrFcShort( 0x8 ),	/* 8 */
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


	/* Return value */


	/* Return value */

/* 1980 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1982 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1984 */	0x8,		/* FC_LONG */
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
			0x12, 0x0,	/* FC_UP */
/* 26 */	NdrFcShort( 0xe ),	/* Offset= 14 (40) */
/* 28 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 30 */	NdrFcShort( 0x2 ),	/* 2 */
/* 32 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 34 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 36 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 38 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 40 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (28) */
/* 46 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 48 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 50 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x4 ),	/* 4 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0xffde ),	/* Offset= -34 (24) */
/* 60 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 62 */	NdrFcShort( 0x8 ),	/* 8 */
/* 64 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 66 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 68 */	NdrFcShort( 0xfff8 ),	/* Offset= -8 (60) */
/* 70 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 72 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 74 */	
			0x11, 0x0,	/* FC_RP */
/* 76 */	NdrFcShort( 0x6 ),	/* Offset= 6 (82) */
/* 78 */	
			0x13, 0x0,	/* FC_OP */
/* 80 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (40) */
/* 82 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x4 ),	/* 4 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (78) */
/* 92 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 94 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 96 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 98 */	NdrFcShort( 0x2 ),	/* Offset= 2 (100) */
/* 100 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 102 */	NdrFcLong( 0x534f26cb ),	/* 1397696203 */
/* 106 */	NdrFcShort( 0x4f8a ),	/* 20362 */
/* 108 */	NdrFcShort( 0x4fee ),	/* 20462 */
/* 110 */	0x8d,		/* 141 */
			0x7e,		/* 126 */
/* 112 */	0x5c,		/* 92 */
			0x35,		/* 53 */
/* 114 */	0xa0,		/* 160 */
			0xa0,		/* 160 */
/* 116 */	0xcc,		/* 204 */
			0x38,		/* 56 */
/* 118 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 120 */	NdrFcShort( 0x2 ),	/* Offset= 2 (122) */
/* 122 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 124 */	NdrFcLong( 0xc ),	/* 12 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 134 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 136 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 138 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 140 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 142 */	NdrFcLong( 0x54b6c009 ),	/* 1421262857 */
/* 146 */	NdrFcShort( 0xc05a ),	/* -16294 */
/* 148 */	NdrFcShort( 0x4f16 ),	/* 20246 */
/* 150 */	0xab,		/* 171 */
			0x55,		/* 85 */
/* 152 */	0x71,		/* 113 */
			0x6a,		/* 106 */
/* 154 */	0x1a,		/* 26 */
			0x1b,		/* 27 */
/* 156 */	0xe4,		/* 228 */
			0x47,		/* 71 */
/* 158 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 160 */	NdrFcLong( 0xbd010a01 ),	/* -1124005375 */
/* 164 */	NdrFcShort( 0xb ),	/* 11 */
/* 166 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 168 */	0xd0,		/* 208 */
			0xdd,		/* 221 */
/* 170 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 172 */	0xc9,		/* 201 */
			0x19,		/* 25 */
/* 174 */	0x4,		/* 4 */
			0x59,		/* 89 */
/* 176 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 178 */	NdrFcShort( 0x2 ),	/* Offset= 2 (180) */
/* 180 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 182 */	NdrFcLong( 0xc ),	/* 12 */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 190 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 192 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 194 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 196 */	0x0,		/* 0 */
			0x46,		/* 70 */

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



/* Standard interface: __MIDL_itf_mvrint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDataMover, ver. 0.0,
   GUID={0x54B6C009,0xC05A,0x4F16,{0xAB,0x55,0x71,0x6A,0x1A,0x1B,0xE4,0x47}} */

#pragma code_seg(".orpc")
static const unsigned short IDataMover_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    90,
    120,
    234,
    336,
    378,
    414,
    450,
    486,
    522,
    564,
    618,
    654,
    690,
    726,
    756,
    804,
    906,
    936,
    990,
    1020
    };

static const MIDL_STUBLESS_PROXY_INFO IDataMover_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDataMover_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDataMover_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDataMover_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(29) _IDataMoverProxyVtbl = 
{
    &IDataMover_ProxyInfo,
    &IID_IDataMover,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDataMover::GetObjectId */ ,
    (void *) (INT_PTR) -1 /* IDataMover::BeginSession */ ,
    (void *) (INT_PTR) -1 /* IDataMover::EndSession */ ,
    (void *) (INT_PTR) -1 /* IDataMover::StoreData */ ,
    (void *) (INT_PTR) -1 /* IDataMover::RecallData */ ,
    (void *) (INT_PTR) -1 /* IDataMover::FormatLabel */ ,
    (void *) (INT_PTR) -1 /* IDataMover::WriteLabel */ ,
    (void *) (INT_PTR) -1 /* IDataMover::ReadLabel */ ,
    (void *) (INT_PTR) -1 /* IDataMover::VerifyLabel */ ,
    (void *) (INT_PTR) -1 /* IDataMover::GetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IDataMover::SetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IDataMover::GetLargestFreeSpace */ ,
    (void *) (INT_PTR) -1 /* IDataMover::SetInitialOffset */ ,
    (void *) (INT_PTR) -1 /* IDataMover::GetCartridge */ ,
    (void *) (INT_PTR) -1 /* IDataMover::SetCartridge */ ,
    (void *) (INT_PTR) -1 /* IDataMover::Cancel */ ,
    (void *) (INT_PTR) -1 /* IDataMover::CreateLocalStream */ ,
    (void *) (INT_PTR) -1 /* IDataMover::CreateRemoteStream */ ,
    (void *) (INT_PTR) -1 /* IDataMover::CloseStream */ ,
    (void *) (INT_PTR) -1 /* IDataMover::Duplicate */ ,
    (void *) (INT_PTR) -1 /* IDataMover::FlushBuffers */ ,
    (void *) (INT_PTR) -1 /* IDataMover::Recover */
};


static const PRPC_STUB_FUNCTION IDataMover_table[] =
{
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
    NdrStubCall2
};

CInterfaceStubVtbl _IDataMoverStubVtbl =
{
    &IID_IDataMover,
    &IDataMover_ServerInfo,
    29,
    &IDataMover_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRemoteStorageHint, ver. 0.0,
   GUID={0xBD010A01,0x000B,0x11D0,{0xD0,0xDD,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRemoteStorageHint_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1056,
    1086,
    1122,
    1158,
    1194,
    1230,
    1266,
    1308,
    1350,
    1386
    };

static const MIDL_STUBLESS_PROXY_INFO IRemoteStorageHint_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRemoteStorageHint_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRemoteStorageHint_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRemoteStorageHint_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IRemoteStorageHintProxyVtbl = 
{
    &IRemoteStorageHint_ProxyInfo,
    &IID_IRemoteStorageHint,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::Reset */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetDataSetStart */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetFileStart */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetFileSize */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetDataStart */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetDataSize */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetVerificationData */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetDatastreamCRC */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetFileUSN */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::GetElementInformation */
};


static const PRPC_STUB_FUNCTION IRemoteStorageHint_table[] =
{
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRemoteStorageHintStubVtbl =
{
    &IID_IRemoteStorageHint,
    &IRemoteStorageHint_ServerInfo,
    17,
    &IRemoteStorageHint_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRemoteStorage, ver. 0.0,
   GUID={0xC48AD3C9,0x00D4,0x11D3,{0x8F,0xD1,0x00,0x40,0x33,0x9F,0xD9,0x7B}} */

#pragma code_seg(".orpc")
static const unsigned short IRemoteStorage_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1476,
    1518,
    1554,
    1590,
    1620,
    1656,
    1698,
    1740,
    1776,
    1812,
    1878
    };

static const MIDL_STUBLESS_PROXY_INFO IRemoteStorage_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRemoteStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRemoteStorage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRemoteStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IRemoteStorageProxyVtbl = 
{
    &IRemoteStorage_ProxyInfo,
    &IID_IRemoteStorage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::FormatLabel */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::WriteLabel */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::ReadLabel */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::VerifyLabel */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::GetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::SetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::GetLargestFreeSpace */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::GetCartridge */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::SetCartridge */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::CreateRemoteStream */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::CloseStream */
};


static const PRPC_STUB_FUNCTION IRemoteStorage_table[] =
{
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

CInterfaceStubVtbl _IRemoteStorageStubVtbl =
{
    &IID_IRemoteStorage,
    &IRemoteStorage_ServerInfo,
    18,
    &IRemoteStorage_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ILocalStorage, ver. 0.0,
   GUID={0xBD010A03,0x000B,0x11D0,{0xD0,0xDD,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short ILocalStorage_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1908,
    1956
    };

static const MIDL_STUBLESS_PROXY_INFO ILocalStorage_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILocalStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ILocalStorage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILocalStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _ILocalStorageProxyVtbl = 
{
    &ILocalStorage_ProxyInfo,
    &IID_ILocalStorage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ILocalStorage::CreateLocalStream */ ,
    (void *) (INT_PTR) -1 /* ILocalStorage::CloseStream */
};


static const PRPC_STUB_FUNCTION ILocalStorage_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ILocalStorageStubVtbl =
{
    &IID_ILocalStorage,
    &ILocalStorage_ServerInfo,
    9,
    &ILocalStorage_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRemoteStream, ver. 0.0,
   GUID={0xBD010A04,0x000B,0x11D0,{0xD0,0xDD,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRemoteStream_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1908,
    1956
    };

static const MIDL_STUBLESS_PROXY_INFO IRemoteStream_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRemoteStream_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRemoteStream_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRemoteStream_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IRemoteStreamProxyVtbl = 
{
    &IRemoteStream_ProxyInfo,
    &IID_IRemoteStream,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRemoteStream::CreateRemoteStream */ ,
    (void *) (INT_PTR) -1 /* IRemoteStream::CloseStream */
};


static const PRPC_STUB_FUNCTION IRemoteStream_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IRemoteStreamStubVtbl =
{
    &IID_IRemoteStream,
    &IRemoteStream_ServerInfo,
    9,
    &IRemoteStream_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ILocalStream, ver. 0.0,
   GUID={0xBD010A05,0x000B,0x11D0,{0xD0,0xDD,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short ILocalStream_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1908,
    1956
    };

static const MIDL_STUBLESS_PROXY_INFO ILocalStream_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILocalStream_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ILocalStream_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILocalStream_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _ILocalStreamProxyVtbl = 
{
    &ILocalStream_ProxyInfo,
    &IID_ILocalStream,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ILocalStream::CreateLocalStream */ ,
    (void *) (INT_PTR) -1 /* ILocalStream::CloseStream */
};


static const PRPC_STUB_FUNCTION ILocalStream_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ILocalStreamStubVtbl =
{
    &IID_ILocalStream,
    &ILocalStream_ServerInfo,
    9,
    &ILocalStream_table[-3],
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
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _mvrint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IRemoteStorageHintProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILocalStorageProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRemoteStreamProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILocalStreamProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDataMoverProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRemoteStorageProxyVtbl,
    0
};

const CInterfaceStubVtbl * _mvrint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IRemoteStorageHintStubVtbl,
    ( CInterfaceStubVtbl *) &_ILocalStorageStubVtbl,
    ( CInterfaceStubVtbl *) &_IRemoteStreamStubVtbl,
    ( CInterfaceStubVtbl *) &_ILocalStreamStubVtbl,
    ( CInterfaceStubVtbl *) &_IDataMoverStubVtbl,
    ( CInterfaceStubVtbl *) &_IRemoteStorageStubVtbl,
    0
};

PCInterfaceName const _mvrint_InterfaceNamesList[] = 
{
    "IRemoteStorageHint",
    "ILocalStorage",
    "IRemoteStream",
    "ILocalStream",
    "IDataMover",
    "IRemoteStorage",
    0
};

const IID *  _mvrint_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _mvrint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _mvrint, pIID, n)

int __stdcall _mvrint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _mvrint, 6, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _mvrint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _mvrint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _mvrint, 6, *pIndex )
    
}

const ExtendedProxyFileInfo mvrint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _mvrint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _mvrint_StubVtblList,
    (const PCInterfaceName * ) & _mvrint_InterfaceNamesList,
    (const IID ** ) & _mvrint_BaseIIDList,
    & _mvrint_IID_Lookup, 
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
/* Compiler settings for mvrint.idl:
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


#include "mvrint.h"

#define TYPE_FORMAT_STRING_SIZE   199                               
#define PROC_FORMAT_STRING_SIZE   2077                              
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


extern const MIDL_SERVER_INFO IDataMover_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDataMover_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRemoteStorageHint_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRemoteStorageHint_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRemoteStorage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRemoteStorage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILocalStorage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ILocalStorage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRemoteStream_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRemoteStream_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILocalStream_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ILocalStream_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure GetObjectId */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x4c ),	/* 76 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pObjectId */

/* 26 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 28 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Return value */

/* 32 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BeginSession */

/* 38 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 48 */	NdrFcShort( 0xe ),	/* 14 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 54 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x2 ),	/* 2 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter remoteSessionName */

/* 64 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 66 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 68 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter remoteSessionDescription */

/* 70 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 72 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 74 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter remoteDataSet */

/* 76 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 78 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 80 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter options */

/* 82 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 84 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 86 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 88 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 90 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 92 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EndSession */

/* 94 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 96 */	NdrFcLong( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x9 ),	/* 9 */
/* 102 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 108 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 110 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 122 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StoreData */

/* 126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0xa ),	/* 10 */
/* 134 */	NdrFcShort( 0x80 ),	/* ia64 Stack size/offset = 128 */
/* 136 */	NdrFcShort( 0x38 ),	/* 56 */
/* 138 */	NdrFcShort( 0x1a0 ),	/* 416 */
/* 140 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xf,		/* 15 */
/* 142 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0x1 ),	/* 1 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter localName */

/* 152 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 154 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 156 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter localDataStart */

/* 158 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 160 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 162 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter localDataSize */

/* 164 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 166 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 168 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter flags */

/* 170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 172 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRemoteDataSetStart */

/* 176 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 178 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 180 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pRemoteFileStart */

/* 182 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 184 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 186 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pRemoteFileSize */

/* 188 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 190 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 192 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pRemoteDataStart */

/* 194 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 196 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 198 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pRemoteDataSize */

/* 200 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 202 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 204 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pRemoteVerificationType */

/* 206 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 208 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRemoteVerificationData */

/* 212 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 214 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 216 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pDatastreamCRCType */

/* 218 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 220 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pDatastreamCRC */

/* 224 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 226 */	NdrFcShort( 0x68 ),	/* ia64 Stack size/offset = 104 */
/* 228 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pUsn */

/* 230 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 232 */	NdrFcShort( 0x70 ),	/* ia64 Stack size/offset = 112 */
/* 234 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 238 */	NdrFcShort( 0x78 ),	/* ia64 Stack size/offset = 120 */
/* 240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RecallData */

/* 242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 248 */	NdrFcShort( 0xb ),	/* 11 */
/* 250 */	NdrFcShort( 0x70 ),	/* ia64 Stack size/offset = 112 */
/* 252 */	NdrFcShort( 0xd0 ),	/* 208 */
/* 254 */	NdrFcShort( 0x8 ),	/* 8 */
/* 256 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xd,		/* 13 */
/* 258 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x2 ),	/* 2 */
/* 264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 266 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter localName */

/* 268 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 270 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 272 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter localDataStart */

/* 274 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 276 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 278 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter localDataSize */

/* 280 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 282 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 284 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter flags */

/* 286 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 288 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter migratedSessionName */

/* 292 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 294 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 296 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter remoteDataSetStart */

/* 298 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 300 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 302 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteFileStart */

/* 304 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 306 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 308 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteFileSize */

/* 310 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 312 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 314 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteDataStart */

/* 316 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 318 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 320 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteDataSize */

/* 322 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 324 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 326 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteVerificationType */

/* 328 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 330 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter remoteVerificationData */

/* 334 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 336 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 338 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 340 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 342 */	NdrFcShort( 0x68 ),	/* ia64 Stack size/offset = 104 */
/* 344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FormatLabel */

/* 346 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 348 */	NdrFcLong( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0xc ),	/* 12 */
/* 354 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 358 */	NdrFcShort( 0x8 ),	/* 8 */
/* 360 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 362 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 364 */	NdrFcShort( 0x1 ),	/* 1 */
/* 366 */	NdrFcShort( 0x2 ),	/* 2 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter displayName */

/* 372 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 374 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 376 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter pLabel */

/* 378 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 380 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 382 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 386 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteLabel */

/* 390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0xd ),	/* 13 */
/* 398 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 404 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 406 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x1 ),	/* 1 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter label */

/* 416 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 418 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 420 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 424 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadLabel */

/* 428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0xe ),	/* 14 */
/* 436 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 442 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 444 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 446 */	NdrFcShort( 0x1 ),	/* 1 */
/* 448 */	NdrFcShort( 0x1 ),	/* 1 */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLabel */

/* 454 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 456 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 458 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 462 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VerifyLabel */

/* 466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0xf ),	/* 15 */
/* 474 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 480 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 482 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x1 ),	/* 1 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter label */

/* 492 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 494 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 496 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 500 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceName */

/* 504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x10 ),	/* 16 */
/* 512 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 518 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 520 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 522 */	NdrFcShort( 0x1 ),	/* 1 */
/* 524 */	NdrFcShort( 0x1 ),	/* 1 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 530 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 532 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 534 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 536 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 538 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceName */

/* 542 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 544 */	NdrFcLong( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x11 ),	/* 17 */
/* 550 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x8 ),	/* 8 */
/* 556 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 558 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x2 ),	/* 2 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 568 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 570 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 572 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter volName */

/* 574 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 576 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 578 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 582 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLargestFreeSpace */

/* 586 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0x12 ),	/* 18 */
/* 594 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 596 */	NdrFcShort( 0x10 ),	/* 16 */
/* 598 */	NdrFcShort( 0x50 ),	/* 80 */
/* 600 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 602 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter freeSpace */

/* 612 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 614 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 616 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter capacity */

/* 618 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 620 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 622 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter defaultFreeSpaceLow */

/* 624 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 626 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter defaultFreeSpaceHigh */

/* 630 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 632 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 638 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetInitialOffset */

/* 642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x13 ),	/* 19 */
/* 650 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 652 */	NdrFcShort( 0x18 ),	/* 24 */
/* 654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 656 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 658 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter initialOffset */

/* 668 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 670 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 672 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 674 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 676 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCartridge */

/* 680 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x14 ),	/* 20 */
/* 688 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	NdrFcShort( 0x8 ),	/* 8 */
/* 694 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 696 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 706 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 708 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 710 */	NdrFcShort( 0x60 ),	/* Type Offset=96 */

	/* Return value */

/* 712 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 714 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCartridge */

/* 718 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 720 */	NdrFcLong( 0x0 ),	/* 0 */
/* 724 */	NdrFcShort( 0x15 ),	/* 21 */
/* 726 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 732 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 734 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 744 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 746 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 748 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */

/* 750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 752 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cancel */

/* 756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x16 ),	/* 22 */
/* 764 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 772 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 782 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 784 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateLocalStream */

/* 788 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x17 ),	/* 23 */
/* 796 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 798 */	NdrFcShort( 0x8 ),	/* 8 */
/* 800 */	NdrFcShort( 0x8 ),	/* 8 */
/* 802 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 804 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0x1 ),	/* 1 */
/* 810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 814 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 816 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 818 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter mode */

/* 820 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 822 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppStream */

/* 826 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 828 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 830 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 834 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateRemoteStream */

/* 838 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0x18 ),	/* 24 */
/* 846 */	NdrFcShort( 0x70 ),	/* ia64 Stack size/offset = 112 */
/* 848 */	NdrFcShort( 0xa0 ),	/* 160 */
/* 850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 852 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xd,		/* 13 */
/* 854 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x3 ),	/* 3 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 864 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 866 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 868 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter mode */

/* 870 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 872 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter remoteSessionName */

/* 876 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 878 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 880 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter remoteSessionDescription */

/* 882 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 884 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 886 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter remoteDataSetStart */

/* 888 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 890 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 892 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteFileStart */

/* 894 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 896 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 898 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteFileSize */

/* 900 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 902 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 904 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteDataStart */

/* 906 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 908 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 910 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteDataSize */

/* 912 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 914 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 916 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter remoteVerificationType */

/* 918 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 920 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter remoteVerificationData */

/* 924 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 926 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 928 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter ppStream */

/* 930 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 932 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 934 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 938 */	NdrFcShort( 0x68 ),	/* ia64 Stack size/offset = 104 */
/* 940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CloseStream */

/* 942 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 948 */	NdrFcShort( 0x19 ),	/* 25 */
/* 950 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x8 ),	/* 8 */
/* 956 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 958 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 968 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 970 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Duplicate */

/* 974 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 976 */	NdrFcLong( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x1a ),	/* 26 */
/* 982 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 984 */	NdrFcShort( 0x8 ),	/* 8 */
/* 986 */	NdrFcShort( 0x60 ),	/* 96 */
/* 988 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 990 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDestination */

/* 1000 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1002 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1004 */	NdrFcShort( 0x8c ),	/* Type Offset=140 */

	/* Parameter options */

/* 1006 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1008 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBytesCopied */

/* 1012 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1014 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1016 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pBytesReclaimed */

/* 1018 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1020 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1022 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1024 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1026 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FlushBuffers */

/* 1030 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1038 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1044 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1046 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1058 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Recover */

/* 1062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1070 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1076 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1078 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDeleteFile */

/* 1088 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1090 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1094 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1096 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 1100 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1102 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1106 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1108 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1112 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1114 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1116 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1128 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDataSetStart */

/* 1132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1140 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1142 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1146 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1148 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dataSetStart */

/* 1158 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1160 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1162 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1166 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileStart */

/* 1170 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1178 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1180 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1182 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1184 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1186 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileStart */

/* 1196 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1198 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1200 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1204 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileSize */

/* 1208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0xa ),	/* 10 */
/* 1216 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1218 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1222 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1224 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileSize */

/* 1234 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1236 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1238 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1242 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDataStart */

/* 1246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1252 */	NdrFcShort( 0xb ),	/* 11 */
/* 1254 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1256 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1262 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dataStart */

/* 1272 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1274 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1276 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDataSize */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0xc ),	/* 12 */
/* 1292 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1294 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1298 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1300 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dataSize */

/* 1310 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1312 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1314 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1318 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetVerificationData */

/* 1322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1328 */	NdrFcShort( 0xd ),	/* 13 */
/* 1330 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1332 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1336 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1338 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter verificationType */

/* 1348 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1350 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter verificationData */

/* 1354 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1356 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1358 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1362 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDatastreamCRC */

/* 1366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0xe ),	/* 14 */
/* 1374 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1376 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1380 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1382 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1390 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dataStreamCRCType */

/* 1392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1394 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dataStreamCRC */

/* 1398 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1400 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1402 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1406 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFileUSN */

/* 1410 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1416 */	NdrFcShort( 0xf ),	/* 15 */
/* 1418 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1420 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1422 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1424 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1426 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1434 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileUSN */

/* 1436 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1438 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1440 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1444 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetElementInformation */

/* 1448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1454 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1456 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 1458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1460 */	NdrFcShort( 0x1a0 ),	/* 416 */
/* 1462 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0xb,		/* 11 */
/* 1464 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataSetStart */

/* 1474 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1476 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1478 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pFileStart */

/* 1480 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1482 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1484 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pFileSize */

/* 1486 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1488 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1490 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pDataStart */

/* 1492 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1494 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1496 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pDataSize */

/* 1498 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1500 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1502 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pVerificationType */

/* 1504 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1506 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVerificationData */

/* 1510 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1512 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1514 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pDataStreamCRCType */

/* 1516 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1518 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pDataStreamCRC */

/* 1522 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1524 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 1526 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter pFileUSN */

/* 1528 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1530 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 1532 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1536 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 1538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FormatLabel */

/* 1540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1548 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1554 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1556 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1558 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1560 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter displayName */

/* 1566 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1568 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1570 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter pLabel */

/* 1572 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1574 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1576 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 1578 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1580 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteLabel */

/* 1584 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1586 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1592 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1598 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1600 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1604 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1608 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter label */

/* 1610 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1612 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1614 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 1616 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1618 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadLabel */

/* 1622 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1628 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1630 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1634 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1636 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1638 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1640 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1642 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLabel */

/* 1648 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1650 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1652 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 1654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1656 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VerifyLabel */

/* 1660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1666 */	NdrFcShort( 0xa ),	/* 10 */
/* 1668 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1674 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1676 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1686 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1688 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceName */

/* 1692 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1698 */	NdrFcShort( 0xb ),	/* 11 */
/* 1700 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1706 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1708 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1710 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1712 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1716 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 1718 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1720 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1722 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 1724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1726 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceName */

/* 1730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1736 */	NdrFcShort( 0xc ),	/* 12 */
/* 1738 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1742 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1744 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1746 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1750 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1756 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1758 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1760 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter volName */

/* 1762 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1764 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1766 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 1768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1770 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLargestFreeSpace */

/* 1774 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1780 */	NdrFcShort( 0xd ),	/* 13 */
/* 1782 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1786 */	NdrFcShort( 0x50 ),	/* 80 */
/* 1788 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1790 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter freeSpace */

/* 1800 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1802 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1804 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter capacity */

/* 1806 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1808 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1810 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1814 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCartridge */

/* 1818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0xe ),	/* 14 */
/* 1826 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1832 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1834 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 1844 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1846 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1848 */	NdrFcShort( 0x60 ),	/* Type Offset=96 */

	/* Return value */

/* 1850 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1852 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCartridge */

/* 1856 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1858 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1862 */	NdrFcShort( 0xf ),	/* 15 */
/* 1864 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1870 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1872 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1880 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 1882 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1884 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1886 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */

/* 1888 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1890 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateRemoteStream */

/* 1894 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1896 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1900 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1902 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1904 */	NdrFcShort( 0xe ),	/* 14 */
/* 1906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1908 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 1910 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1914 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1918 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1920 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1922 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1924 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter description */

/* 1926 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1928 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1930 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter index */

/* 1932 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1934 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1936 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter options */

/* 1938 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1940 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pHint */

/* 1944 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1946 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1948 */	NdrFcShort( 0x9e ),	/* Type Offset=158 */

	/* Parameter ppStream */

/* 1950 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1952 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1954 */	NdrFcShort( 0xb0 ),	/* Type Offset=176 */

	/* Return value */

/* 1956 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1958 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CloseStream */

/* 1962 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1964 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1968 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1970 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1976 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1978 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1988 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1990 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateLocalStream */


	/* Procedure CreateRemoteStream */


	/* Procedure CreateLocalStream */

/* 1994 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1996 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2000 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2002 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2006 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2008 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2010 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2014 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter name */


	/* Parameter name */

/* 2020 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2022 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2024 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter mode */


	/* Parameter mode */


	/* Parameter mode */

/* 2026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2028 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppStream */


	/* Parameter ppStream */


	/* Parameter ppStream */

/* 2032 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2034 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2036 */	NdrFcShort( 0xb0 ),	/* Type Offset=176 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2040 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CloseStream */


	/* Procedure CloseStream */


	/* Procedure CloseStream */

/* 2044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2052 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2056 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2058 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2060 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2072 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2074 */	0x8,		/* FC_LONG */
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
			0x12, 0x0,	/* FC_UP */
/* 26 */	NdrFcShort( 0xe ),	/* Offset= 14 (40) */
/* 28 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 30 */	NdrFcShort( 0x2 ),	/* 2 */
/* 32 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 34 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 36 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 38 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 40 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (28) */
/* 46 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 48 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 50 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x8 ),	/* 8 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0xffde ),	/* Offset= -34 (24) */
/* 60 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 62 */	NdrFcShort( 0x8 ),	/* 8 */
/* 64 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 66 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 68 */	NdrFcShort( 0xfff8 ),	/* Offset= -8 (60) */
/* 70 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 72 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 74 */	
			0x11, 0x0,	/* FC_RP */
/* 76 */	NdrFcShort( 0x6 ),	/* Offset= 6 (82) */
/* 78 */	
			0x13, 0x0,	/* FC_OP */
/* 80 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (40) */
/* 82 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x8 ),	/* 8 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (78) */
/* 92 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 94 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 96 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 98 */	NdrFcShort( 0x2 ),	/* Offset= 2 (100) */
/* 100 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 102 */	NdrFcLong( 0x534f26cb ),	/* 1397696203 */
/* 106 */	NdrFcShort( 0x4f8a ),	/* 20362 */
/* 108 */	NdrFcShort( 0x4fee ),	/* 20462 */
/* 110 */	0x8d,		/* 141 */
			0x7e,		/* 126 */
/* 112 */	0x5c,		/* 92 */
			0x35,		/* 53 */
/* 114 */	0xa0,		/* 160 */
			0xa0,		/* 160 */
/* 116 */	0xcc,		/* 204 */
			0x38,		/* 56 */
/* 118 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 120 */	NdrFcShort( 0x2 ),	/* Offset= 2 (122) */
/* 122 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 124 */	NdrFcLong( 0xc ),	/* 12 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 134 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 136 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 138 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 140 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 142 */	NdrFcLong( 0x54b6c009 ),	/* 1421262857 */
/* 146 */	NdrFcShort( 0xc05a ),	/* -16294 */
/* 148 */	NdrFcShort( 0x4f16 ),	/* 20246 */
/* 150 */	0xab,		/* 171 */
			0x55,		/* 85 */
/* 152 */	0x71,		/* 113 */
			0x6a,		/* 106 */
/* 154 */	0x1a,		/* 26 */
			0x1b,		/* 27 */
/* 156 */	0xe4,		/* 228 */
			0x47,		/* 71 */
/* 158 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 160 */	NdrFcLong( 0xbd010a01 ),	/* -1124005375 */
/* 164 */	NdrFcShort( 0xb ),	/* 11 */
/* 166 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 168 */	0xd0,		/* 208 */
			0xdd,		/* 221 */
/* 170 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 172 */	0xc9,		/* 201 */
			0x19,		/* 25 */
/* 174 */	0x4,		/* 4 */
			0x59,		/* 89 */
/* 176 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 178 */	NdrFcShort( 0x2 ),	/* Offset= 2 (180) */
/* 180 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 182 */	NdrFcLong( 0xc ),	/* 12 */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 190 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 192 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 194 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 196 */	0x0,		/* 0 */
			0x46,		/* 70 */

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



/* Standard interface: __MIDL_itf_mvrint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDataMover, ver. 0.0,
   GUID={0x54B6C009,0xC05A,0x4F16,{0xAB,0x55,0x71,0x6A,0x1A,0x1B,0xE4,0x47}} */

#pragma code_seg(".orpc")
static const unsigned short IDataMover_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    38,
    94,
    126,
    242,
    346,
    390,
    428,
    466,
    504,
    542,
    586,
    642,
    680,
    718,
    756,
    788,
    838,
    942,
    974,
    1030,
    1062
    };

static const MIDL_STUBLESS_PROXY_INFO IDataMover_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDataMover_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDataMover_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDataMover_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(29) _IDataMoverProxyVtbl = 
{
    &IDataMover_ProxyInfo,
    &IID_IDataMover,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDataMover::GetObjectId */ ,
    (void *) (INT_PTR) -1 /* IDataMover::BeginSession */ ,
    (void *) (INT_PTR) -1 /* IDataMover::EndSession */ ,
    (void *) (INT_PTR) -1 /* IDataMover::StoreData */ ,
    (void *) (INT_PTR) -1 /* IDataMover::RecallData */ ,
    (void *) (INT_PTR) -1 /* IDataMover::FormatLabel */ ,
    (void *) (INT_PTR) -1 /* IDataMover::WriteLabel */ ,
    (void *) (INT_PTR) -1 /* IDataMover::ReadLabel */ ,
    (void *) (INT_PTR) -1 /* IDataMover::VerifyLabel */ ,
    (void *) (INT_PTR) -1 /* IDataMover::GetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IDataMover::SetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IDataMover::GetLargestFreeSpace */ ,
    (void *) (INT_PTR) -1 /* IDataMover::SetInitialOffset */ ,
    (void *) (INT_PTR) -1 /* IDataMover::GetCartridge */ ,
    (void *) (INT_PTR) -1 /* IDataMover::SetCartridge */ ,
    (void *) (INT_PTR) -1 /* IDataMover::Cancel */ ,
    (void *) (INT_PTR) -1 /* IDataMover::CreateLocalStream */ ,
    (void *) (INT_PTR) -1 /* IDataMover::CreateRemoteStream */ ,
    (void *) (INT_PTR) -1 /* IDataMover::CloseStream */ ,
    (void *) (INT_PTR) -1 /* IDataMover::Duplicate */ ,
    (void *) (INT_PTR) -1 /* IDataMover::FlushBuffers */ ,
    (void *) (INT_PTR) -1 /* IDataMover::Recover */
};


static const PRPC_STUB_FUNCTION IDataMover_table[] =
{
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
    NdrStubCall2
};

CInterfaceStubVtbl _IDataMoverStubVtbl =
{
    &IID_IDataMover,
    &IDataMover_ServerInfo,
    29,
    &IDataMover_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRemoteStorageHint, ver. 0.0,
   GUID={0xBD010A01,0x000B,0x11D0,{0xD0,0xDD,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRemoteStorageHint_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1100,
    1132,
    1170,
    1208,
    1246,
    1284,
    1322,
    1366,
    1410,
    1448
    };

static const MIDL_STUBLESS_PROXY_INFO IRemoteStorageHint_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRemoteStorageHint_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRemoteStorageHint_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRemoteStorageHint_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IRemoteStorageHintProxyVtbl = 
{
    &IRemoteStorageHint_ProxyInfo,
    &IID_IRemoteStorageHint,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::Reset */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetDataSetStart */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetFileStart */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetFileSize */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetDataStart */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetDataSize */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetVerificationData */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetDatastreamCRC */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::SetFileUSN */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorageHint::GetElementInformation */
};


static const PRPC_STUB_FUNCTION IRemoteStorageHint_table[] =
{
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRemoteStorageHintStubVtbl =
{
    &IID_IRemoteStorageHint,
    &IRemoteStorageHint_ServerInfo,
    17,
    &IRemoteStorageHint_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRemoteStorage, ver. 0.0,
   GUID={0xC48AD3C9,0x00D4,0x11D3,{0x8F,0xD1,0x00,0x40,0x33,0x9F,0xD9,0x7B}} */

#pragma code_seg(".orpc")
static const unsigned short IRemoteStorage_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1540,
    1584,
    1622,
    1660,
    1692,
    1730,
    1774,
    1818,
    1856,
    1894,
    1962
    };

static const MIDL_STUBLESS_PROXY_INFO IRemoteStorage_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRemoteStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRemoteStorage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRemoteStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IRemoteStorageProxyVtbl = 
{
    &IRemoteStorage_ProxyInfo,
    &IID_IRemoteStorage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::FormatLabel */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::WriteLabel */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::ReadLabel */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::VerifyLabel */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::GetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::SetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::GetLargestFreeSpace */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::GetCartridge */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::SetCartridge */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::CreateRemoteStream */ ,
    (void *) (INT_PTR) -1 /* IRemoteStorage::CloseStream */
};


static const PRPC_STUB_FUNCTION IRemoteStorage_table[] =
{
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

CInterfaceStubVtbl _IRemoteStorageStubVtbl =
{
    &IID_IRemoteStorage,
    &IRemoteStorage_ServerInfo,
    18,
    &IRemoteStorage_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ILocalStorage, ver. 0.0,
   GUID={0xBD010A03,0x000B,0x11D0,{0xD0,0xDD,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short ILocalStorage_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1994,
    2044
    };

static const MIDL_STUBLESS_PROXY_INFO ILocalStorage_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILocalStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ILocalStorage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILocalStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _ILocalStorageProxyVtbl = 
{
    &ILocalStorage_ProxyInfo,
    &IID_ILocalStorage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ILocalStorage::CreateLocalStream */ ,
    (void *) (INT_PTR) -1 /* ILocalStorage::CloseStream */
};


static const PRPC_STUB_FUNCTION ILocalStorage_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ILocalStorageStubVtbl =
{
    &IID_ILocalStorage,
    &ILocalStorage_ServerInfo,
    9,
    &ILocalStorage_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRemoteStream, ver. 0.0,
   GUID={0xBD010A04,0x000B,0x11D0,{0xD0,0xDD,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRemoteStream_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1994,
    2044
    };

static const MIDL_STUBLESS_PROXY_INFO IRemoteStream_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRemoteStream_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRemoteStream_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRemoteStream_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IRemoteStreamProxyVtbl = 
{
    &IRemoteStream_ProxyInfo,
    &IID_IRemoteStream,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRemoteStream::CreateRemoteStream */ ,
    (void *) (INT_PTR) -1 /* IRemoteStream::CloseStream */
};


static const PRPC_STUB_FUNCTION IRemoteStream_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IRemoteStreamStubVtbl =
{
    &IID_IRemoteStream,
    &IRemoteStream_ServerInfo,
    9,
    &IRemoteStream_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ILocalStream, ver. 0.0,
   GUID={0xBD010A05,0x000B,0x11D0,{0xD0,0xDD,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short ILocalStream_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1994,
    2044
    };

static const MIDL_STUBLESS_PROXY_INFO ILocalStream_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILocalStream_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ILocalStream_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILocalStream_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _ILocalStreamProxyVtbl = 
{
    &ILocalStream_ProxyInfo,
    &IID_ILocalStream,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ILocalStream::CreateLocalStream */ ,
    (void *) (INT_PTR) -1 /* ILocalStream::CloseStream */
};


static const PRPC_STUB_FUNCTION ILocalStream_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ILocalStreamStubVtbl =
{
    &IID_ILocalStream,
    &ILocalStream_ServerInfo,
    9,
    &ILocalStream_table[-3],
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
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _mvrint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IRemoteStorageHintProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILocalStorageProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRemoteStreamProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILocalStreamProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDataMoverProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRemoteStorageProxyVtbl,
    0
};

const CInterfaceStubVtbl * _mvrint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IRemoteStorageHintStubVtbl,
    ( CInterfaceStubVtbl *) &_ILocalStorageStubVtbl,
    ( CInterfaceStubVtbl *) &_IRemoteStreamStubVtbl,
    ( CInterfaceStubVtbl *) &_ILocalStreamStubVtbl,
    ( CInterfaceStubVtbl *) &_IDataMoverStubVtbl,
    ( CInterfaceStubVtbl *) &_IRemoteStorageStubVtbl,
    0
};

PCInterfaceName const _mvrint_InterfaceNamesList[] = 
{
    "IRemoteStorageHint",
    "ILocalStorage",
    "IRemoteStream",
    "ILocalStream",
    "IDataMover",
    "IRemoteStorage",
    0
};

const IID *  _mvrint_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _mvrint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _mvrint, pIID, n)

int __stdcall _mvrint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _mvrint, 6, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _mvrint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _mvrint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _mvrint, 6, *pIndex )
    
}

const ExtendedProxyFileInfo mvrint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _mvrint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _mvrint_StubVtblList,
    (const PCInterfaceName * ) & _mvrint_InterfaceNamesList,
    (const IID ** ) & _mvrint_BaseIIDList,
    & _mvrint_IID_Lookup, 
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

