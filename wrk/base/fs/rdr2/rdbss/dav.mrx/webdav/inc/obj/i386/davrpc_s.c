

/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for davrpc.idl, davrpc.acf:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, oldnames, robust
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
#include <string.h>
#include "davrpc.h"

#define TYPE_FORMAT_STRING_SIZE   69                                
#define PROC_FORMAT_STRING_SIZE   733                               
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

/* Standard interface: davclntrpc, ver. 1.0,
   GUID={0xc8cb7687,0xe6d3,0x11d2,{0xa9,0x58,0x00,0xc0,0x4f,0x68,0x2e,0x16}} */


extern const MIDL_SERVER_INFO davclntrpc_ServerInfo;

extern RPC_DISPATCH_TABLE davclntrpc_DispatchTable;

static const RPC_SERVER_INTERFACE davclntrpc___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0xc8cb7687,0xe6d3,0x11d2,{0xa9,0x58,0x00,0xc0,0x4f,0x68,0x2e,0x16}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    &davclntrpc_DispatchTable,
    0,
    0,
    0,
    &davclntrpc_ServerInfo,
    0x04000000
    };
RPC_IF_HANDLE davclntrpc_ServerIfHandle = (RPC_IF_HANDLE)& davclntrpc___RpcServerInterface;

extern const MIDL_STUB_DESC davclntrpc_StubDesc;


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

	/* Procedure DavrCreateConnection */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x8 ),	/* 8 */
/* 16 */	NdrFcShort( 0x8 ),	/* 8 */
/* 18 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 20 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 28 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 30 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 32 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter LocalName */

/* 34 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 36 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 38 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter RemoteName */

/* 40 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 42 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 44 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Type */

/* 46 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 48 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 50 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter Password */

/* 52 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 54 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 56 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter UserName */

/* 58 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 60 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 62 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrDoesServerDoDav */


	/* Return value */

/* 64 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 66 */	NdrFcLong( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x1 ),	/* 1 */
/* 72 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 74 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 76 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 78 */	NdrFcShort( 0x19 ),	/* 25 */
/* 80 */	NdrFcShort( 0x21 ),	/* 33 */
/* 82 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 84 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 92 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 94 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 96 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ServerName */

/* 98 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 100 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 102 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter DoesDav */

/* 104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 106 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrIsValidShare */


	/* Return value */

/* 110 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 116 */	NdrFcShort( 0x2 ),	/* 2 */
/* 118 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 120 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 122 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 124 */	NdrFcShort( 0x19 ),	/* 25 */
/* 126 */	NdrFcShort( 0x21 ),	/* 33 */
/* 128 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 130 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 138 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 142 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ServerName */

/* 144 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 146 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 148 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ShareName */

/* 150 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 154 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter ValidShare */

/* 156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 158 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrEnumNetUses */


	/* Return value */

/* 162 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x3 ),	/* 3 */
/* 170 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 172 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 174 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 176 */	NdrFcShort( 0x35 ),	/* 53 */
/* 178 */	NdrFcShort( 0x3d ),	/* 61 */
/* 180 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 182 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 190 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 192 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Index */

/* 196 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 198 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 200 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter LocalName */

/* 202 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 204 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 206 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter RemoteName */

/* 208 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 210 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 212 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter Done */

/* 214 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 216 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrEnumShares */


	/* Return value */

/* 220 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x4 ),	/* 4 */
/* 228 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 230 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 232 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 234 */	NdrFcShort( 0x35 ),	/* 53 */
/* 236 */	NdrFcShort( 0x3d ),	/* 61 */
/* 238 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 240 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 248 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 250 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Index */

/* 254 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 256 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 258 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ServerName */

/* 260 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 262 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 264 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter RemoteName */

/* 266 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 268 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 270 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter Done */

/* 272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 274 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrEnumServers */


	/* Return value */

/* 278 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x5 ),	/* 5 */
/* 286 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 288 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 290 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 292 */	NdrFcShort( 0x35 ),	/* 53 */
/* 294 */	NdrFcShort( 0x3d ),	/* 61 */
/* 296 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 298 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 306 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 308 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Index */

/* 312 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 314 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 316 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter RemoteName */

/* 318 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 320 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 322 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter Done */

/* 324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 326 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrGetConnection */


	/* Return value */

/* 330 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x6 ),	/* 6 */
/* 338 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 340 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 342 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 344 */	NdrFcShort( 0x19 ),	/* 25 */
/* 346 */	NdrFcShort( 0x21 ),	/* 33 */
/* 348 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 350 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 358 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 360 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 362 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter LocalName */

/* 364 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 366 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 368 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter RemoteName */

/* 370 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 372 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 374 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter Connected */

/* 376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 378 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrDeleteConnection */


	/* Return value */

/* 382 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 388 */	NdrFcShort( 0x7 ),	/* 7 */
/* 390 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 392 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 394 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 396 */	NdrFcShort( 0x8 ),	/* 8 */
/* 398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 400 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 402 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 410 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 414 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ConnectionName */

/* 416 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter UseForce */

/* 422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 424 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrGetUser */


	/* Return value */

/* 428 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 436 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 438 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 440 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 446 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 448 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 456 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 458 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 460 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ConnectionName */

/* 462 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 464 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 466 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter UserName */

/* 468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 470 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrConnectionExist */


	/* Return value */

/* 474 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x9 ),	/* 9 */
/* 482 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 484 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 486 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 492 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 494 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 502 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 504 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 506 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ConnectionName */

/* 508 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 510 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrWinlogonLogonEvent */


	/* Return value */

/* 514 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 516 */	NdrFcLong( 0x0 ),	/* 0 */
/* 520 */	NdrFcShort( 0xa ),	/* 10 */
/* 522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 524 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 532 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 534 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 542 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 544 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrWinlogonLogoffEvent */


	/* Return value */

/* 548 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0xb ),	/* 11 */
/* 556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 558 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 560 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 566 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 568 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 578 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrGetDiskSpaceUsage */


	/* Return value */

/* 582 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0xc ),	/* 12 */
/* 590 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 592 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 594 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 596 */	NdrFcShort( 0x60 ),	/* 96 */
/* 598 */	NdrFcShort( 0x7c ),	/* 124 */
/* 600 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x6,		/* 6 */
/* 602 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 604 */	NdrFcShort( 0x1 ),	/* 1 */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 610 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 612 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 614 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter lptzLocation */

/* 616 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 618 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 620 */	NdrFcShort( 0x2c ),	/* 44 */

	/* Parameter Size */

/* 622 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 624 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pLength */

/* 628 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 630 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 632 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Parameter lpMaxSpace */

/* 634 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 636 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 638 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Parameter lpUsedSpace */

/* 640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 642 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrFreeUsedDiskSpace */


	/* Return value */

/* 646 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0xd ),	/* 13 */
/* 654 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 656 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 658 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 660 */	NdrFcShort( 0x8 ),	/* 8 */
/* 662 */	NdrFcShort( 0x8 ),	/* 8 */
/* 664 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 666 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 674 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 676 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwPercent */

/* 680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 682 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrGetTheLockOwnerOfTheFile */


	/* Return value */

/* 686 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 692 */	NdrFcShort( 0xe ),	/* 14 */
/* 694 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 696 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 704 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 706 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 714 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 716 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 718 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter FileName */

/* 720 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 722 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 724 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter LockOwnerName */

/* 726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 728 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 730 */	0x8,		/* FC_LONG */
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
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/*  4 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  8 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 12 */	0x3,		/* FC_SMALL */
			0x5c,		/* FC_PAD */
/* 14 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 16 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 18 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 20 */	NdrFcShort( 0xffee ),	/* Offset= -18 (2) */
/* 22 */	
			0x11, 0x0,	/* FC_RP */
/* 24 */	NdrFcShort( 0x2 ),	/* Offset= 2 (26) */
/* 26 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 28 */	NdrFcShort( 0x2 ),	/* 2 */
/* 30 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 36 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x54,		/* FC_DEREFERENCE */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 42 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 44 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 46 */	NdrFcLong( 0x0 ),	/* 0 */
/* 50 */	NdrFcLong( 0x104 ),	/* 260 */
/* 54 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 56 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 58 */	
			0x11, 0x0,	/* FC_RP */
/* 60 */	NdrFcShort( 0x2 ),	/* Offset= 2 (62) */
/* 62 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 64 */	NdrFcShort( 0x8 ),	/* 8 */
/* 66 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const unsigned short davclntrpc_FormatStringOffsetTable[] =
    {
    0,
    64,
    110,
    162,
    220,
    278,
    330,
    382,
    428,
    474,
    514,
    548,
    582,
    646,
    686
    };


static const MIDL_STUB_DESC davclntrpc_StubDesc = 
    {
    (void *)& davclntrpc___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
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

static RPC_DISPATCH_FUNCTION davclntrpc_table[] =
    {
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    0
    };
RPC_DISPATCH_TABLE davclntrpc_DispatchTable = 
    {
    15,
    davclntrpc_table
    };

static const SERVER_ROUTINE davclntrpc_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)DavrCreateConnection,
    (SERVER_ROUTINE)DavrDoesServerDoDav,
    (SERVER_ROUTINE)DavrIsValidShare,
    (SERVER_ROUTINE)DavrEnumNetUses,
    (SERVER_ROUTINE)DavrEnumShares,
    (SERVER_ROUTINE)DavrEnumServers,
    (SERVER_ROUTINE)DavrGetConnection,
    (SERVER_ROUTINE)DavrDeleteConnection,
    (SERVER_ROUTINE)DavrGetUser,
    (SERVER_ROUTINE)DavrConnectionExist,
    (SERVER_ROUTINE)DavrWinlogonLogonEvent,
    (SERVER_ROUTINE)DavrWinlogonLogoffEvent,
    (SERVER_ROUTINE)DavrGetDiskSpaceUsage,
    (SERVER_ROUTINE)DavrFreeUsedDiskSpace,
    (SERVER_ROUTINE)DavrGetTheLockOwnerOfTheFile
    };

static const MIDL_SERVER_INFO davclntrpc_ServerInfo = 
    {
    &davclntrpc_StubDesc,
    davclntrpc_ServerRoutineTable,
    __MIDL_ProcFormatString.Format,
    davclntrpc_FormatStringOffsetTable,
    0,
    0,
    0,
    0};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for davrpc.idl, davrpc.acf:
    Oicf, W1, Zp8, env=Win64 (32b run,appending)
    protocol : dce , ms_ext, c_ext, oldnames, robust
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
#include <string.h>
#include "davrpc.h"

#define TYPE_FORMAT_STRING_SIZE   69                                
#define PROC_FORMAT_STRING_SIZE   763                               
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

/* Standard interface: davclntrpc, ver. 1.0,
   GUID={0xc8cb7687,0xe6d3,0x11d2,{0xa9,0x58,0x00,0xc0,0x4f,0x68,0x2e,0x16}} */


extern const MIDL_SERVER_INFO davclntrpc_ServerInfo;

extern RPC_DISPATCH_TABLE davclntrpc_DispatchTable;

static const RPC_SERVER_INTERFACE davclntrpc___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0xc8cb7687,0xe6d3,0x11d2,{0xa9,0x58,0x00,0xc0,0x4f,0x68,0x2e,0x16}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    &davclntrpc_DispatchTable,
    0,
    0,
    0,
    &davclntrpc_ServerInfo,
    0x04000000
    };
RPC_IF_HANDLE davclntrpc_ServerIfHandle = (RPC_IF_HANDLE)& davclntrpc___RpcServerInterface;

extern const MIDL_STUB_DESC davclntrpc_StubDesc;


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure DavrCreateConnection */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x8 ),	/* 8 */
/* 16 */	NdrFcShort( 0x8 ),	/* 8 */
/* 18 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 20 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 30 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 32 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 34 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter LocalName */

/* 36 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 38 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 40 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter RemoteName */

/* 42 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 44 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 46 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Type */

/* 48 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 50 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 52 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter Password */

/* 54 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 56 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 58 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter UserName */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrDoesServerDoDav */


	/* Return value */

/* 66 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x1 ),	/* 1 */
/* 74 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 76 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 78 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 80 */	NdrFcShort( 0x19 ),	/* 25 */
/* 82 */	NdrFcShort( 0x21 ),	/* 33 */
/* 84 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 86 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 96 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 98 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 100 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ServerName */

/* 102 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 104 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 106 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter DoesDav */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrIsValidShare */


	/* Return value */

/* 114 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x2 ),	/* 2 */
/* 122 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 124 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 126 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 128 */	NdrFcShort( 0x19 ),	/* 25 */
/* 130 */	NdrFcShort( 0x21 ),	/* 33 */
/* 132 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 134 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 144 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 146 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 148 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ServerName */

/* 150 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 152 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 154 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ShareName */

/* 156 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 158 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 160 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter ValidShare */

/* 162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 164 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrEnumNetUses */


	/* Return value */

/* 168 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x3 ),	/* 3 */
/* 176 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 178 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 180 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 182 */	NdrFcShort( 0x35 ),	/* 53 */
/* 184 */	NdrFcShort( 0x3d ),	/* 61 */
/* 186 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 188 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 198 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 200 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Index */

/* 204 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 206 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 208 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter LocalName */

/* 210 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 212 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 214 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter RemoteName */

/* 216 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 218 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 220 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter Done */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrEnumShares */


	/* Return value */

/* 228 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x4 ),	/* 4 */
/* 236 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 238 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 240 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 242 */	NdrFcShort( 0x35 ),	/* 53 */
/* 244 */	NdrFcShort( 0x3d ),	/* 61 */
/* 246 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 248 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 258 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 260 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Index */

/* 264 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 266 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 268 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ServerName */

/* 270 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 272 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 274 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter RemoteName */

/* 276 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 278 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 280 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter Done */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrEnumServers */


	/* Return value */

/* 288 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x5 ),	/* 5 */
/* 296 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 298 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 300 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 302 */	NdrFcShort( 0x35 ),	/* 53 */
/* 304 */	NdrFcShort( 0x3d ),	/* 61 */
/* 306 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 308 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 318 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 320 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Index */

/* 324 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 326 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 328 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter RemoteName */

/* 330 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 332 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 334 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter Done */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 338 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrGetConnection */


	/* Return value */

/* 342 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x6 ),	/* 6 */
/* 350 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 352 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 354 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 356 */	NdrFcShort( 0x19 ),	/* 25 */
/* 358 */	NdrFcShort( 0x21 ),	/* 33 */
/* 360 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 362 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 372 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 374 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 376 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter LocalName */

/* 378 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 380 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 382 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter RemoteName */

/* 384 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 386 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 388 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter Connected */

/* 390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 392 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrDeleteConnection */


	/* Return value */

/* 396 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x7 ),	/* 7 */
/* 404 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 406 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 408 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 414 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 416 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 426 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 428 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 430 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ConnectionName */

/* 432 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 434 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter UseForce */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrGetUser */


	/* Return value */

/* 444 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 452 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 454 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 456 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 460 */	NdrFcShort( 0x8 ),	/* 8 */
/* 462 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 464 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 474 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 476 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 478 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ConnectionName */

/* 480 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 482 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 484 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter UserName */

/* 486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 488 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrConnectionExist */


	/* Return value */

/* 492 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0x9 ),	/* 9 */
/* 500 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 502 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 504 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 508 */	NdrFcShort( 0x8 ),	/* 8 */
/* 510 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 512 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 522 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 524 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 526 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter ConnectionName */

/* 528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 530 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrWinlogonLogonEvent */


	/* Return value */

/* 534 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0xa ),	/* 10 */
/* 542 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 544 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 546 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 552 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 554 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 564 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 566 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrWinlogonLogoffEvent */


	/* Return value */

/* 570 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 572 */	NdrFcLong( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0xb ),	/* 11 */
/* 578 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 580 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 582 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 588 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 590 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 602 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrGetDiskSpaceUsage */


	/* Return value */

/* 606 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 612 */	NdrFcShort( 0xc ),	/* 12 */
/* 614 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 616 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 618 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 620 */	NdrFcShort( 0x60 ),	/* 96 */
/* 622 */	NdrFcShort( 0x7c ),	/* 124 */
/* 624 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x6,		/* 6 */
/* 626 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 628 */	NdrFcShort( 0x1 ),	/* 1 */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 636 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 638 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 640 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter lptzLocation */

/* 642 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 644 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 646 */	NdrFcShort( 0x2c ),	/* 44 */

	/* Parameter Size */

/* 648 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 650 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pLength */

/* 654 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 656 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 658 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Parameter lpMaxSpace */

/* 660 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 662 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 664 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Parameter lpUsedSpace */

/* 666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 668 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrFreeUsedDiskSpace */


	/* Return value */

/* 672 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0xd ),	/* 13 */
/* 680 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 682 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 684 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 690 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 692 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 702 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 704 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwPercent */

/* 708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 710 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DavrGetTheLockOwnerOfTheFile */


	/* Return value */

/* 714 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0xe ),	/* 14 */
/* 722 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 724 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 726 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 732 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 734 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter IDL_handle */

/* 744 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 746 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 748 */	NdrFcShort( 0x8 ),	/* Type Offset=8 */

	/* Parameter FileName */

/* 750 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 752 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 754 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter LockOwnerName */

/* 756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 758 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 760 */	0x8,		/* FC_LONG */
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
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/*  4 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  8 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 12 */	0x3,		/* FC_SMALL */
			0x5c,		/* FC_PAD */
/* 14 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 16 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 18 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 20 */	NdrFcShort( 0xffee ),	/* Offset= -18 (2) */
/* 22 */	
			0x11, 0x0,	/* FC_RP */
/* 24 */	NdrFcShort( 0x2 ),	/* Offset= 2 (26) */
/* 26 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 28 */	NdrFcShort( 0x2 ),	/* 2 */
/* 30 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 32 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 34 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 36 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x54,		/* FC_DEREFERENCE */
/* 38 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 40 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 42 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 44 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 46 */	NdrFcLong( 0x0 ),	/* 0 */
/* 50 */	NdrFcLong( 0x104 ),	/* 260 */
/* 54 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 56 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 58 */	
			0x11, 0x0,	/* FC_RP */
/* 60 */	NdrFcShort( 0x2 ),	/* Offset= 2 (62) */
/* 62 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 64 */	NdrFcShort( 0x8 ),	/* 8 */
/* 66 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const unsigned short davclntrpc_FormatStringOffsetTable[] =
    {
    0,
    66,
    114,
    168,
    228,
    288,
    342,
    396,
    444,
    492,
    534,
    570,
    606,
    672,
    714
    };


static const MIDL_STUB_DESC davclntrpc_StubDesc = 
    {
    (void *)& davclntrpc___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
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

static RPC_DISPATCH_FUNCTION davclntrpc_table[] =
    {
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    0
    };
RPC_DISPATCH_TABLE davclntrpc_DispatchTable = 
    {
    15,
    davclntrpc_table
    };

static const SERVER_ROUTINE davclntrpc_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)DavrCreateConnection,
    (SERVER_ROUTINE)DavrDoesServerDoDav,
    (SERVER_ROUTINE)DavrIsValidShare,
    (SERVER_ROUTINE)DavrEnumNetUses,
    (SERVER_ROUTINE)DavrEnumShares,
    (SERVER_ROUTINE)DavrEnumServers,
    (SERVER_ROUTINE)DavrGetConnection,
    (SERVER_ROUTINE)DavrDeleteConnection,
    (SERVER_ROUTINE)DavrGetUser,
    (SERVER_ROUTINE)DavrConnectionExist,
    (SERVER_ROUTINE)DavrWinlogonLogonEvent,
    (SERVER_ROUTINE)DavrWinlogonLogoffEvent,
    (SERVER_ROUTINE)DavrGetDiskSpaceUsage,
    (SERVER_ROUTINE)DavrFreeUsedDiskSpace,
    (SERVER_ROUTINE)DavrGetTheLockOwnerOfTheFile
    };

static const MIDL_SERVER_INFO davclntrpc_ServerInfo = 
    {
    &davclntrpc_StubDesc,
    davclntrpc_ServerRoutineTable,
    __MIDL_ProcFormatString.Format,
    davclntrpc_FormatStringOffsetTable,
    0,
    0,
    0,
    0};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

