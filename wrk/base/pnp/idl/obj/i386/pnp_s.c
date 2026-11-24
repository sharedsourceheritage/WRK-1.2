

/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for pnp.idl:
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
#include "pnp.h"

#define TYPE_FORMAT_STRING_SIZE   449                               
#define PROC_FORMAT_STRING_SIZE   3823                              
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

/* Standard interface: pnp, ver. 1.0,
   GUID={0x8D9F4E40,0xA03D,0x11CE,{0x8F,0x69,0x08,0x00,0x3E,0x30,0x05,0x1B}} */


extern const MIDL_SERVER_INFO pnp_ServerInfo;

extern RPC_DISPATCH_TABLE pnp_DispatchTable;

static const RPC_SERVER_INTERFACE pnp___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x8D9F4E40,0xA03D,0x11CE,{0x8F,0x69,0x08,0x00,0x3E,0x30,0x05,0x1B}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    &pnp_DispatchTable,
    0,
    0,
    0,
    &pnp_ServerInfo,
    0x04000000
    };
RPC_IF_HANDLE pnp_ServerIfHandle = (RPC_IF_HANDLE)& pnp___RpcServerInterface;

extern const MIDL_STUB_DESC pnp_StubDesc;

extern const NDR_RUNDOWN RundownRoutines[];

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

	/* Procedure PNP_Connect */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10 */	0x31,		/* FC_BIND_GENERIC */
			0x4,		/* 4 */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	0x0,		/* 0 */
			0x5c,		/* FC_PAD */
/* 16 */	NdrFcShort( 0x0 ),	/* 0 */
/* 18 */	NdrFcShort( 0x8 ),	/* 8 */
/* 20 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 22 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter UNCServerName */

/* 30 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 32 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 34 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 38 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_Disconnect */

/* 42 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 44 */	NdrFcLong( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x1 ),	/* 1 */
/* 50 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 52 */	0x31,		/* FC_BIND_GENERIC */
			0x4,		/* 4 */
/* 54 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 56 */	0x0,		/* 0 */
			0x5c,		/* FC_PAD */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x8 ),	/* 8 */
/* 62 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 64 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter UNCServerName */

/* 72 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 74 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 76 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 80 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetVersion */

/* 84 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x2 ),	/* 2 */
/* 92 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 94 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 96 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x22 ),	/* 34 */
/* 102 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 104 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 112 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 114 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 116 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVersion */

/* 118 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 120 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetGlobalState */


	/* Return value */

/* 124 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 126 */	NdrFcLong( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x3 ),	/* 3 */
/* 132 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 134 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 140 */	NdrFcShort( 0x24 ),	/* 36 */
/* 142 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 144 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 152 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 154 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulState */

/* 158 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 160 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 166 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_InitDetection */


	/* Return value */

/* 170 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x4 ),	/* 4 */
/* 178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 180 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 190 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 200 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_ReportLogOn */


	/* Return value */

/* 204 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x5 ),	/* 5 */
/* 212 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 214 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 216 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 218 */	NdrFcShort( 0x10 ),	/* 16 */
/* 220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 222 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 224 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 230 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bAdmin */

/* 238 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 240 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ProcessID */

/* 244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 246 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_ValidateDeviceInstance */


	/* Return value */

/* 250 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x6 ),	/* 6 */
/* 258 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 260 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 262 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 268 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 270 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 278 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 280 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 282 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 284 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 286 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 290 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 294 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetRootDeviceInstance */


	/* Return value */

/* 296 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 298 */	NdrFcLong( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x7 ),	/* 7 */
/* 304 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 306 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 310 */	NdrFcShort( 0x8 ),	/* 8 */
/* 312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 314 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 316 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 318 */	NdrFcShort( 0x1 ),	/* 1 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 324 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 328 */	NdrFcShort( 0x16 ),	/* Type Offset=22 */

	/* Parameter pDeviceID */

/* 330 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 338 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetRelatedDeviceInstance */


	/* Return value */

/* 342 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 350 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 352 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 354 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 356 */	NdrFcShort( 0x2c ),	/* 44 */
/* 358 */	NdrFcShort( 0x24 ),	/* 36 */
/* 360 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 362 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 364 */	NdrFcShort( 0x1 ),	/* 1 */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 370 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 372 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulRelationship */

/* 376 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 378 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 380 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 382 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 384 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 386 */	NdrFcShort( 0x22 ),	/* Type Offset=34 */

	/* Parameter pRelatedDeviceID */

/* 388 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 390 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 394 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 396 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 400 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 402 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_EnumerateSubKeys */


	/* Return value */

/* 406 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 408 */	NdrFcLong( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x9 ),	/* 9 */
/* 414 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 416 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 418 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 420 */	NdrFcShort( 0x20 ),	/* 32 */
/* 422 */	NdrFcShort( 0x24 ),	/* 36 */
/* 424 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x7,		/* 7 */
/* 426 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 428 */	NdrFcShort( 0x1 ),	/* 1 */
/* 430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 436 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulBranch */

/* 440 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 442 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulIndex */

/* 446 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 448 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 450 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter Buffer */

/* 452 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 454 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 458 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 460 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulRequiredLen */

/* 464 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 466 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 472 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetDeviceList */


	/* Return value */

/* 476 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0xa ),	/* 10 */
/* 484 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 486 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 490 */	NdrFcShort( 0x24 ),	/* 36 */
/* 492 */	NdrFcShort( 0x24 ),	/* 36 */
/* 494 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 496 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 498 */	NdrFcShort( 0x1 ),	/* 1 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 504 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 508 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszFilter */

/* 510 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 514 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Parameter Buffer */

/* 516 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 518 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 522 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 524 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 530 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetDeviceListSize */


	/* Return value */

/* 534 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0xb ),	/* 11 */
/* 542 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 544 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 546 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 548 */	NdrFcShort( 0x8 ),	/* 8 */
/* 550 */	NdrFcShort( 0x24 ),	/* 36 */
/* 552 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 554 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 562 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 564 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 566 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszFilter */

/* 568 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 570 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLen */

/* 574 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 576 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 582 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetDepth */


	/* Return value */

/* 586 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0xc ),	/* 12 */
/* 594 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 596 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 602 */	NdrFcShort( 0x24 ),	/* 36 */
/* 604 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 606 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 614 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 616 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 618 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 620 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 622 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulDepth */

/* 626 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 628 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 632 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 634 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetDeviceRegProp */


	/* Return value */

/* 638 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 640 */	NdrFcLong( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0xd ),	/* 13 */
/* 646 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 648 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 650 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 652 */	NdrFcShort( 0x64 ),	/* 100 */
/* 654 */	NdrFcShort( 0x5c ),	/* 92 */
/* 656 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 658 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 660 */	NdrFcShort( 0x1 ),	/* 1 */
/* 662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 666 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 670 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 672 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 674 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProperty */

/* 678 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 680 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulRegDataType */

/* 684 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 686 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 688 */	NdrFcShort( 0x54 ),	/* Type Offset=84 */

	/* Parameter Buffer */

/* 690 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 692 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 696 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 698 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 702 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 704 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 710 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_SetDeviceRegProp */


	/* Return value */

/* 714 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0xe ),	/* 14 */
/* 722 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 724 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 726 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 728 */	NdrFcShort( 0x20 ),	/* 32 */
/* 730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 732 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 734 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x1 ),	/* 1 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 742 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 744 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 746 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 748 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 750 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProperty */

/* 754 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 756 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulDataType */

/* 760 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 762 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 764 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter Buffer */

/* 766 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 768 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 772 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 774 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 778 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 780 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetClassInstance */


	/* Return value */

/* 784 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 786 */	NdrFcLong( 0x0 ),	/* 0 */
/* 790 */	NdrFcShort( 0xf ),	/* 15 */
/* 792 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 794 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 796 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 798 */	NdrFcShort( 0x8 ),	/* 8 */
/* 800 */	NdrFcShort( 0x8 ),	/* 8 */
/* 802 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 804 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 806 */	NdrFcShort( 0x1 ),	/* 1 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 812 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 814 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 816 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 818 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 820 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 822 */	NdrFcShort( 0x7a ),	/* Type Offset=122 */

	/* Parameter pszClassInstance */

/* 824 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 826 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 830 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 832 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_CreateKey */


	/* Return value */

/* 836 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 838 */	NdrFcLong( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x10 ),	/* 16 */
/* 844 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 846 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 848 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 850 */	NdrFcShort( 0x10 ),	/* 16 */
/* 852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 854 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 856 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 864 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 866 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 868 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszSubKey */

/* 870 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 872 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter samDesired */

/* 876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 878 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 882 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 884 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_DeleteRegistryKey */


	/* Return value */

/* 888 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 890 */	NdrFcLong( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x11 ),	/* 17 */
/* 896 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 898 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 900 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 904 */	NdrFcShort( 0x8 ),	/* 8 */
/* 906 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 908 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 914 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 916 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 918 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 920 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 922 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 924 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 926 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszParentKey */

/* 928 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 930 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 932 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszChildKey */

/* 934 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 936 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 940 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 942 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetClassCount */


	/* Return value */

/* 946 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x12 ),	/* 18 */
/* 954 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 956 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 958 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 962 */	NdrFcShort( 0x24 ),	/* 36 */
/* 964 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 966 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 974 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 976 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulClassCount */

/* 980 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 982 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 986 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 988 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetClassName */


	/* Return value */

/* 992 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1000 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1002 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1004 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1006 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1008 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1010 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1012 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1014 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1020 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1022 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1024 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszClassGuid */

/* 1026 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1028 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1030 */	NdrFcShort( 0x86 ),	/* Type Offset=134 */

	/* Parameter Buffer */

/* 1032 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1034 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 1038 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1040 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1046 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_DeleteClassKey */


	/* Return value */

/* 1050 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1058 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1060 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1062 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1064 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1066 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1068 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1070 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1078 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1080 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1082 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszClassGuid */

/* 1084 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1086 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1088 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1090 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1092 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1094 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetInterfaceDeviceAlias */


	/* Return value */

/* 1096 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1098 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1102 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1104 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1106 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1108 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1110 */	NdrFcShort( 0x84 ),	/* 132 */
/* 1112 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1114 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 1116 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1118 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1124 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1126 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1128 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszInterfaceDevice */

/* 1130 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1132 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1134 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter AliasInterfaceGuid */

/* 1136 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1138 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1140 */	NdrFcShort( 0xa8 ),	/* Type Offset=168 */

	/* Parameter pszAliasInterfaceDevice */

/* 1142 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1144 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 1148 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1150 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 1154 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1156 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1160 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1162 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetInterfaceDeviceList */


	/* Return value */

/* 1166 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1168 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1172 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1174 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1176 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1180 */	NdrFcShort( 0x68 ),	/* 104 */
/* 1182 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1184 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1186 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1188 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1194 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1196 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1198 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter InterfaceGuid */

/* 1200 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1202 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1204 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceID */

/* 1206 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1208 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1210 */	NdrFcShort( 0xb4 ),	/* Type Offset=180 */

	/* Parameter Buffer */

/* 1212 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1214 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 1218 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1220 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1226 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetInterfaceDeviceListSize */


	/* Return value */

/* 1230 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1238 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1240 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1242 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1244 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1246 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1248 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1250 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1258 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1260 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLen */

/* 1264 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1266 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1268 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter InterfaceGuid */

/* 1270 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1274 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceID */

/* 1276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1278 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1284 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RegisterDeviceClassAssociation */


	/* Return value */

/* 1288 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1294 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1296 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1298 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1300 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1302 */	NdrFcShort( 0x84 ),	/* 132 */
/* 1304 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1306 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1308 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1310 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1314 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1316 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1318 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1320 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceID */

/* 1322 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1324 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1326 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter InterfaceGuid */

/* 1328 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1330 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1332 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszReference */

/* 1334 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1336 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1338 */	NdrFcShort( 0xca ),	/* Type Offset=202 */

	/* Parameter pszSymLink */

/* 1340 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1342 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 1346 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1348 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 1352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1354 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1360 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_UnregisterDeviceClassAssociation */


	/* Return value */

/* 1364 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1370 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1372 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1374 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1376 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1380 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1382 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1384 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1390 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1392 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1394 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1396 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszInterfaceDevice */

/* 1398 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1400 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1406 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetClassRegProp */


	/* Return value */

/* 1410 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1416 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1418 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1420 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1422 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1424 */	NdrFcShort( 0x64 ),	/* 100 */
/* 1426 */	NdrFcShort( 0x5c ),	/* 92 */
/* 1428 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1430 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1432 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1438 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1440 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1442 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszClassGuid */

/* 1444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1446 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProperty */

/* 1450 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulRegDataType */

/* 1456 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1458 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1460 */	NdrFcShort( 0x54 ),	/* Type Offset=84 */

	/* Parameter Buffer */

/* 1462 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1464 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 1468 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1470 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 1474 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1476 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1482 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_SetClassRegProp */


	/* Return value */

/* 1486 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1492 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1494 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1496 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1498 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1500 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1502 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1504 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 1506 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1510 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1514 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1518 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszClassGuid */

/* 1520 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProperty */

/* 1526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1528 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulDataType */

/* 1532 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1534 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1536 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter Buffer */

/* 1538 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1540 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 1544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1546 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1550 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1552 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_CreateDevInst */


	/* Return value */

/* 1556 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1562 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1564 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1566 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1568 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1570 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1574 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1576 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1578 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1580 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1584 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1586 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1588 */	NdrFcShort( 0xd6 ),	/* Type Offset=214 */

	/* Parameter pszDeviceID */

/* 1590 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1592 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1594 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszParentDeviceID */

/* 1596 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1598 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 1602 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1604 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1608 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1610 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1612 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_DeviceInstanceAction */


	/* Return value */

/* 1614 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1616 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1620 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1622 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1624 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1626 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1628 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1632 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1634 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1642 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulMajorAction */

/* 1648 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulMinorAction */

/* 1654 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1656 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1658 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceInstance1 */

/* 1660 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1662 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1664 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceInstance2 */

/* 1666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1668 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetDeviceStatus */


	/* Return value */

/* 1672 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1678 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1680 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1682 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1684 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1688 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1690 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1692 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1698 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1700 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1702 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1704 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pDeviceID */

/* 1706 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1708 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulStatus */

/* 1712 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1714 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulProblem */

/* 1718 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1720 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1726 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_SetDeviceProblem */


	/* Return value */

/* 1730 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1736 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1738 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1740 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1742 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1744 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1748 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1750 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1756 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1758 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1760 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1762 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pDeviceID */

/* 1764 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1766 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProblem */

/* 1770 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1772 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1778 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_DisableDevInst */


	/* Return value */

/* 1782 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1790 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1792 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1794 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1796 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1798 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1800 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1802 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1804 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1806 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1808 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1810 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1812 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1814 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pDeviceID */

/* 1816 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 1818 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1820 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter pVetoType */

/* 1822 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 1824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1826 */	NdrFcShort( 0xe2 ),	/* Type Offset=226 */

	/* Parameter pszVetoName */

/* 1828 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1830 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulNameLength */

/* 1834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1836 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1842 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_UninstallDevInst */


	/* Return value */

/* 1846 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1852 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1854 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1856 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1858 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1864 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1866 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1874 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1876 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1878 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pDeviceID */

/* 1880 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1882 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1888 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_AddID */


	/* Return value */

/* 1892 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1898 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1900 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1902 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1904 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1910 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1912 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1918 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1920 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1922 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1924 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceID */

/* 1926 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1928 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1930 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszID */

/* 1932 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1934 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1938 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1940 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RegisterDriver */


	/* Return value */

/* 1944 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1946 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1950 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1952 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1954 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1956 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1958 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1962 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1964 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1972 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1974 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1976 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 1978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1986 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_QueryRemove */


	/* Return value */

/* 1990 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1996 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1998 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2000 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2002 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2004 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2006 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2008 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2010 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2012 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2014 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2016 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2018 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2020 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2022 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 2024 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 2026 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2028 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter pVetoType */

/* 2030 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 2032 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2034 */	NdrFcShort( 0xee ),	/* Type Offset=238 */

	/* Parameter pszVetoName */

/* 2036 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2038 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulNameLength */

/* 2042 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2044 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2048 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2050 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2052 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RequestDeviceEject */


	/* Return value */

/* 2054 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2056 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2060 */	NdrFcShort( 0x25 ),	/* 37 */
/* 2062 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2064 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2066 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2068 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2070 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2072 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2074 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2076 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2078 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2082 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2084 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2086 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 2088 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 2090 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2092 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter pVetoType */

/* 2094 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 2096 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2098 */	NdrFcShort( 0xfa ),	/* Type Offset=250 */

	/* Parameter pszVetoName */

/* 2100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2102 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulNameLength */

/* 2106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2108 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2114 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_IsDockStationPresent */


	/* Return value */

/* 2118 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x26 ),	/* 38 */
/* 2126 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2128 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2130 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2132 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2134 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2136 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2138 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2146 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 2148 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2150 */	NdrFcShort( 0x106 ),	/* Type Offset=262 */

	/* Parameter Present */

/* 2152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2154 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RequestEjectPC */


	/* Return value */

/* 2158 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2164 */	NdrFcShort( 0x27 ),	/* 39 */
/* 2166 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2168 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2170 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2176 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2178 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_HwProfFlags */


	/* Return value */

/* 2192 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2198 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2200 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2202 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2204 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2206 */	NdrFcShort( 0x56 ),	/* 86 */
/* 2208 */	NdrFcShort( 0x3e ),	/* 62 */
/* 2210 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2212 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2214 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2216 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2220 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2222 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulAction */

/* 2226 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2230 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulConfig */

/* 2238 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2240 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulValue */

/* 2244 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 2246 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2248 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter pVetoType */

/* 2250 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 2252 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2254 */	NdrFcShort( 0x10a ),	/* Type Offset=266 */

	/* Parameter pszVetoName */

/* 2256 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2258 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulNameLength */

/* 2262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2264 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2270 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetHwProfInfo */


	/* Return value */

/* 2274 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2280 */	NdrFcShort( 0x29 ),	/* 41 */
/* 2282 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2284 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2286 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2288 */	NdrFcShort( 0xf4 ),	/* 244 */
/* 2290 */	NdrFcShort( 0xe4 ),	/* 228 */
/* 2292 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2294 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulIndex */

/* 2308 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 2310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2312 */	NdrFcShort( 0x120 ),	/* Type Offset=288 */

	/* Parameter pHWProfileInfo */

/* 2314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2316 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProfileInfoSize */

/* 2320 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2322 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2328 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_AddEmptyLogConf */


	/* Return value */

/* 2332 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2338 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2340 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2342 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2344 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2346 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2348 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2350 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2352 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2360 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2364 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulPriority */

/* 2372 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLogConfTag */

/* 2378 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2380 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2386 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_FreeLogConf */


	/* Return value */

/* 2390 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2396 */	NdrFcShort( 0x2b ),	/* 43 */
/* 2398 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2400 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2402 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2404 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2406 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2408 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2410 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2418 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2420 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2422 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2424 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2426 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2430 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2432 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 2436 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2438 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2444 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetFirstLogConf */


	/* Return value */

/* 2448 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2454 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2456 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2458 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2460 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2462 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2464 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2466 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2468 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2474 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2476 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2478 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2480 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2482 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2488 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2490 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLogConfTag */

/* 2494 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2496 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2502 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetNextLogConf */


	/* Return value */

/* 2506 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2512 */	NdrFcShort( 0x2d ),	/* 45 */
/* 2514 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2516 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2518 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2520 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2522 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2524 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2526 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2534 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2536 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2538 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2540 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2542 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2546 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2548 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulCurrentTag */

/* 2552 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2554 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulNextTag */

/* 2558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2560 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2564 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2566 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetLogConfPriority */


	/* Return value */

/* 2570 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2572 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2576 */	NdrFcShort( 0x2e ),	/* 46 */
/* 2578 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2580 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2582 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2584 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2586 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2588 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2590 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2596 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2598 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2600 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2602 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2604 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2606 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulType */

/* 2610 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2612 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulTag */

/* 2616 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2618 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPriority */

/* 2622 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2624 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2628 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2630 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_AddResDes */


	/* Return value */

/* 2634 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2636 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2640 */	NdrFcShort( 0x2f ),	/* 47 */
/* 2642 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2644 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2646 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2648 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2650 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2652 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2654 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2658 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2660 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2662 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2664 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2666 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2668 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2670 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 2674 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2676 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2680 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2682 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 2686 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2688 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulResourceTag */

/* 2692 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2694 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2696 */	NdrFcShort( 0x130 ),	/* Type Offset=304 */

	/* Parameter ResourceData */

/* 2698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2700 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceLen */

/* 2704 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2706 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2712 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_FreeResDes */


	/* Return value */

/* 2716 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2722 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2724 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2726 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2728 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2730 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2732 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2734 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2736 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2744 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2746 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2748 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2750 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2752 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 2756 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2758 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2762 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2764 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 2768 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2770 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulResourceTag */

/* 2774 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2776 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulPreviousResType */

/* 2780 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2782 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulPreviousResTag */

/* 2786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2788 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2794 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetNextResDes */


	/* Return value */

/* 2798 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2804 */	NdrFcShort( 0x31 ),	/* 49 */
/* 2806 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2808 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2810 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2812 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2814 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2816 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2818 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2824 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2826 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2828 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2830 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2832 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2834 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 2838 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2840 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2842 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2844 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2846 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2848 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 2850 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2852 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulResourceTag */

/* 2856 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2858 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulNextResDesTag */

/* 2862 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2864 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulNextResDesType */

/* 2868 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2870 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2874 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2876 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetResDesData */


	/* Return value */

/* 2880 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2882 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2886 */	NdrFcShort( 0x32 ),	/* 50 */
/* 2888 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2890 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2892 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2894 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2898 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2900 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2902 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2906 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2908 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2910 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2912 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 2920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2922 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2926 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2928 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 2932 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2934 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulResourceTag */

/* 2938 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2940 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2942 */	NdrFcShort( 0x130 ),	/* Type Offset=304 */

	/* Parameter Buffer */

/* 2944 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2946 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter BufferLen */

/* 2950 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2952 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2954 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2956 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2958 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetResDesDataSize */


	/* Return value */

/* 2962 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2964 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2968 */	NdrFcShort( 0x33 ),	/* 51 */
/* 2970 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2972 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2974 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2976 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2978 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2980 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 2982 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2990 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2992 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2994 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2998 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 3002 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3004 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 3008 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3010 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3016 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulResourceTag */

/* 3020 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3022 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulSize */

/* 3026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3028 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3034 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_ModifyResDes */


	/* Return value */

/* 3038 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3044 */	NdrFcShort( 0x34 ),	/* 52 */
/* 3046 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3048 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3050 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3052 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3054 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3056 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xa,		/* 10 */
/* 3058 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3062 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3064 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3066 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3068 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3070 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 3072 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3074 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 3078 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3080 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 3084 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3086 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3088 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter CurrentResourceID */

/* 3090 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3092 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3094 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter NewResourceID */

/* 3096 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3098 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulResourceTag */

/* 3102 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3104 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3106 */	NdrFcShort( 0x140 ),	/* Type Offset=320 */

	/* Parameter ResourceData */

/* 3108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3110 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceLen */

/* 3114 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3116 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3122 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_DetectResourceConflict */


	/* Return value */

/* 3126 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3132 */	NdrFcShort( 0x35 ),	/* 53 */
/* 3134 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3136 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3138 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3140 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3142 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3144 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3146 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3150 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3152 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3154 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3156 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3158 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 3160 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3162 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3166 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3168 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3170 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Parameter ResourceData */

/* 3172 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3174 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceLen */

/* 3178 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3180 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbConflictDetected */

/* 3184 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3186 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3192 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_QueryResConfList */


	/* Return value */

/* 3196 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3202 */	NdrFcShort( 0x36 ),	/* 54 */
/* 3204 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3206 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3208 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3210 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3214 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3216 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3218 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3220 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3222 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3224 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3226 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3228 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 3230 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3232 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3236 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3238 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3240 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Parameter ResourceData */

/* 3242 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3244 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceLen */

/* 3248 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3250 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3252 */	NdrFcShort( 0x160 ),	/* Type Offset=352 */

	/* Parameter Buffer */

/* 3254 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3256 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter BufferLen */

/* 3260 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3262 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3268 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_SetHwProf */


	/* Return value */

/* 3272 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3278 */	NdrFcShort( 0x37 ),	/* 55 */
/* 3280 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3282 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3284 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3286 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3290 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3292 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3300 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulHardwareProfile */

/* 3306 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3314 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_QueryArbitratorFreeData */


	/* Return value */

/* 3318 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3324 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3326 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3328 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3330 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3332 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3336 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3338 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3340 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3344 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3346 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3348 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3350 */	NdrFcShort( 0x170 ),	/* Type Offset=368 */

	/* Parameter pData */

/* 3352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3354 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulDataLen */

/* 3358 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3360 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3362 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 3364 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3366 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3370 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3372 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3378 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_QueryArbitratorFreeSize */


	/* Return value */

/* 3382 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3388 */	NdrFcShort( 0x39 ),	/* 57 */
/* 3390 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3392 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3394 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3396 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3398 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3400 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3402 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3410 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulSize */

/* 3416 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3420 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 3422 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3424 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3430 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3436 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RunDetection */


	/* Return value */

/* 3440 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3446 */	NdrFcShort( 0x3a ),	/* 58 */
/* 3448 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3450 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3452 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3458 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3468 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RegisterNotification */


	/* Return value */

/* 3480 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3486 */	NdrFcShort( 0x3b ),	/* 59 */
/* 3488 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3490 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3492 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3494 */	NdrFcShort( 0x44 ),	/* 68 */
/* 3496 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3498 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 3500 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3504 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3510 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hRecipient */

/* 3514 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3516 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3518 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter ServiceName */

/* 3520 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3522 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3524 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Parameter NotificationFilter */

/* 3526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3528 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulSize */

/* 3532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3534 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Flags */

/* 3538 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 3540 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3542 */	NdrFcShort( 0x180 ),	/* Type Offset=384 */

	/* Parameter Context */

/* 3544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3546 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hProcess */

/* 3550 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3552 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3554 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter ClientContext */

/* 3556 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3558 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_UnregisterNotification */


	/* Return value */

/* 3562 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3564 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3568 */	NdrFcShort( 0x3c ),	/* 60 */
/* 3570 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3572 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3574 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3576 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3578 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3580 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3582 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3590 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 3592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3594 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Parameter Context */

/* 3596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetCustomDevProp */


	/* Return value */

/* 3602 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3608 */	NdrFcShort( 0x3d ),	/* 61 */
/* 3610 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3612 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3614 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3616 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3618 */	NdrFcShort( 0x5c ),	/* 92 */
/* 3620 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3622 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3624 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3630 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3632 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3634 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 3636 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3638 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3640 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter CustomPropName */

/* 3642 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3644 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulRegDataType */

/* 3648 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3650 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3652 */	NdrFcShort( 0x194 ),	/* Type Offset=404 */

	/* Parameter Buffer */

/* 3654 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3656 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 3660 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3662 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 3666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3668 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3674 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetVersionInternal */


	/* Return value */

/* 3678 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3684 */	NdrFcShort( 0x3e ),	/* 62 */
/* 3686 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3688 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3690 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3692 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3694 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3696 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3698 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3704 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3706 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3708 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3710 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pwVersion */

/* 3712 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3714 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetBlockedDriverInfo */


	/* Return value */

/* 3718 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3720 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3724 */	NdrFcShort( 0x3f ),	/* 63 */
/* 3726 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3728 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3730 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3732 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3734 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3736 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 3738 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3740 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3744 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3746 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3748 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3750 */	NdrFcShort( 0x1ae ),	/* Type Offset=430 */

	/* Parameter Buffer */

/* 3752 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3754 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 3758 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3760 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3762 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 3764 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3766 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3772 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetServerSideDeviceInstallFlags */


	/* Return value */

/* 3776 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3782 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3784 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3786 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3788 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3792 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3794 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3796 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3804 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3806 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulSSDIFlags */

/* 3810 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3812 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3816 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3818 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3820 */	0x8,		/* FC_LONG */
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
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  8 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 12 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 14 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 16 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 18 */	
			0x11, 0x0,	/* FC_RP */
/* 20 */	NdrFcShort( 0x2 ),	/* Offset= 2 (22) */
/* 22 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 24 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 26 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 28 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 30 */	
			0x11, 0x0,	/* FC_RP */
/* 32 */	NdrFcShort( 0x2 ),	/* Offset= 2 (34) */
/* 34 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 36 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 38 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 40 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 42 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 44 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 46 */	
			0x11, 0x0,	/* FC_RP */
/* 48 */	NdrFcShort( 0x2 ),	/* Offset= 2 (50) */
/* 50 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 52 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 54 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 56 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 58 */	
			0x11, 0x0,	/* FC_RP */
/* 60 */	NdrFcShort( 0x2 ),	/* Offset= 2 (62) */
/* 62 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 64 */	NdrFcShort( 0x2 ),	/* 2 */
/* 66 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 68 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 70 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 72 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 74 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 76 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 78 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 80 */	
			0x11, 0x0,	/* FC_RP */
/* 82 */	NdrFcShort( 0x2 ),	/* Offset= 2 (84) */
/* 84 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 86 */	NdrFcShort( 0x1 ),	/* 1 */
/* 88 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 90 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 92 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 94 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 96 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 98 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 100 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 102 */	
			0x11, 0x0,	/* FC_RP */
/* 104 */	NdrFcShort( 0x2 ),	/* Offset= 2 (106) */
/* 106 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 108 */	NdrFcShort( 0x1 ),	/* 1 */
/* 110 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 112 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 114 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 116 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 118 */	
			0x11, 0x0,	/* FC_RP */
/* 120 */	NdrFcShort( 0x2 ),	/* Offset= 2 (122) */
/* 122 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 124 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 126 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 128 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 130 */	
			0x11, 0x0,	/* FC_RP */
/* 132 */	NdrFcShort( 0x2 ),	/* Offset= 2 (134) */
/* 134 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 136 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 138 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 140 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 142 */	
			0x11, 0x0,	/* FC_RP */
/* 144 */	NdrFcShort( 0x8 ),	/* Offset= 8 (152) */
/* 146 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 148 */	NdrFcShort( 0x8 ),	/* 8 */
/* 150 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 152 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 154 */	NdrFcShort( 0x10 ),	/* 16 */
/* 156 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 158 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 160 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (146) */
			0x5b,		/* FC_END */
/* 164 */	
			0x11, 0x0,	/* FC_RP */
/* 166 */	NdrFcShort( 0x2 ),	/* Offset= 2 (168) */
/* 168 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 170 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 172 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 174 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 176 */	
			0x11, 0x0,	/* FC_RP */
/* 178 */	NdrFcShort( 0x2 ),	/* Offset= 2 (180) */
/* 180 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 182 */	NdrFcShort( 0x2 ),	/* 2 */
/* 184 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 186 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 188 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 190 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 192 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 194 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 196 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 198 */	
			0x11, 0x0,	/* FC_RP */
/* 200 */	NdrFcShort( 0x2 ),	/* Offset= 2 (202) */
/* 202 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 204 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 206 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 208 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 210 */	
			0x11, 0x0,	/* FC_RP */
/* 212 */	NdrFcShort( 0x2 ),	/* Offset= 2 (214) */
/* 214 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 216 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 218 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 220 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 222 */	
			0x12, 0xc,	/* FC_UP [alloced_on_stack] [simple_pointer] */
/* 224 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 226 */	
			0x12, 0x0,	/* FC_UP */
/* 228 */	NdrFcShort( 0x2 ),	/* Offset= 2 (230) */
/* 230 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 232 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 234 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 236 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 238 */	
			0x12, 0x0,	/* FC_UP */
/* 240 */	NdrFcShort( 0x2 ),	/* Offset= 2 (242) */
/* 242 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 244 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 246 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 248 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 250 */	
			0x12, 0x0,	/* FC_UP */
/* 252 */	NdrFcShort( 0x2 ),	/* Offset= 2 (254) */
/* 254 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 256 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 258 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 260 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 262 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 264 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 266 */	
			0x12, 0x0,	/* FC_UP */
/* 268 */	NdrFcShort( 0x2 ),	/* Offset= 2 (270) */
/* 270 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 272 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 274 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 276 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 278 */	
			0x11, 0x0,	/* FC_RP */
/* 280 */	NdrFcShort( 0x8 ),	/* Offset= 8 (288) */
/* 282 */	
			0x1d,		/* FC_SMFARRAY */
			0x1,		/* 1 */
/* 284 */	NdrFcShort( 0xa0 ),	/* 160 */
/* 286 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 288 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 290 */	NdrFcShort( 0xa8 ),	/* 168 */
/* 292 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 294 */	0x0,		/* 0 */
			NdrFcShort( 0xfff3 ),	/* Offset= -13 (282) */
			0x8,		/* FC_LONG */
/* 298 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 300 */	
			0x11, 0x0,	/* FC_RP */
/* 302 */	NdrFcShort( 0x2 ),	/* Offset= 2 (304) */
/* 304 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 306 */	NdrFcShort( 0x1 ),	/* 1 */
/* 308 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 310 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 312 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 314 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 316 */	
			0x11, 0x0,	/* FC_RP */
/* 318 */	NdrFcShort( 0x2 ),	/* Offset= 2 (320) */
/* 320 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 322 */	NdrFcShort( 0x1 ),	/* 1 */
/* 324 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 326 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 328 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 330 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 332 */	
			0x11, 0x0,	/* FC_RP */
/* 334 */	NdrFcShort( 0x2 ),	/* Offset= 2 (336) */
/* 336 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 338 */	NdrFcShort( 0x1 ),	/* 1 */
/* 340 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 342 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 344 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 346 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 348 */	
			0x11, 0x0,	/* FC_RP */
/* 350 */	NdrFcShort( 0x2 ),	/* Offset= 2 (352) */
/* 352 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 354 */	NdrFcShort( 0x1 ),	/* 1 */
/* 356 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 358 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 360 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 362 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 364 */	
			0x11, 0x0,	/* FC_RP */
/* 366 */	NdrFcShort( 0x2 ),	/* Offset= 2 (368) */
/* 368 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 370 */	NdrFcShort( 0x1 ),	/* 1 */
/* 372 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 374 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 376 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 378 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 380 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 382 */	NdrFcShort( 0x2 ),	/* Offset= 2 (384) */
/* 384 */	0x30,		/* FC_BIND_CONTEXT */
			0xa8,		/* Ctxt flags:  via ptr, out, strict, */
/* 386 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 388 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 390 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 392 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 394 */	NdrFcShort( 0x2 ),	/* Offset= 2 (396) */
/* 396 */	0x30,		/* FC_BIND_CONTEXT */
			0xe8,		/* Ctxt flags:  via ptr, in, out, strict, */
/* 398 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 400 */	
			0x11, 0x0,	/* FC_RP */
/* 402 */	NdrFcShort( 0x2 ),	/* Offset= 2 (404) */
/* 404 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 406 */	NdrFcShort( 0x1 ),	/* 1 */
/* 408 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 410 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 412 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 414 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 416 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 418 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 420 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 422 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 424 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 426 */	
			0x11, 0x0,	/* FC_RP */
/* 428 */	NdrFcShort( 0x2 ),	/* Offset= 2 (430) */
/* 430 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 432 */	NdrFcShort( 0x1 ),	/* 1 */
/* 434 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 436 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 438 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 440 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 442 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 444 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 446 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const NDR_RUNDOWN RundownRoutines[] = 
    {
    PNP_NOTIFICATION_CONTEXT_rundown
    };


static const unsigned short pnp_FormatStringOffsetTable[] =
    {
    0,
    42,
    84,
    124,
    170,
    204,
    250,
    296,
    342,
    406,
    476,
    534,
    586,
    638,
    714,
    784,
    836,
    888,
    946,
    992,
    1050,
    1096,
    1166,
    1230,
    1288,
    1364,
    1410,
    1486,
    1556,
    1614,
    1672,
    1730,
    1782,
    1846,
    1892,
    1944,
    1990,
    2054,
    2118,
    2158,
    2192,
    2274,
    2332,
    2390,
    2448,
    2506,
    2570,
    2634,
    2716,
    2798,
    2880,
    2962,
    3038,
    3126,
    3196,
    3272,
    3318,
    3382,
    3440,
    3480,
    3562,
    3602,
    3678,
    3718,
    3776
    };


static const MIDL_STUB_DESC pnp_StubDesc = 
    {
    (void *)& pnp___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    RundownRoutines,
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

static RPC_DISPATCH_FUNCTION pnp_table[] =
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
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    0
    };
RPC_DISPATCH_TABLE pnp_DispatchTable = 
    {
    65,
    pnp_table
    };

static const SERVER_ROUTINE pnp_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)PNP_Connect,
    (SERVER_ROUTINE)PNP_Disconnect,
    (SERVER_ROUTINE)PNP_GetVersion,
    (SERVER_ROUTINE)PNP_GetGlobalState,
    (SERVER_ROUTINE)PNP_InitDetection,
    (SERVER_ROUTINE)PNP_ReportLogOn,
    (SERVER_ROUTINE)PNP_ValidateDeviceInstance,
    (SERVER_ROUTINE)PNP_GetRootDeviceInstance,
    (SERVER_ROUTINE)PNP_GetRelatedDeviceInstance,
    (SERVER_ROUTINE)PNP_EnumerateSubKeys,
    (SERVER_ROUTINE)PNP_GetDeviceList,
    (SERVER_ROUTINE)PNP_GetDeviceListSize,
    (SERVER_ROUTINE)PNP_GetDepth,
    (SERVER_ROUTINE)PNP_GetDeviceRegProp,
    (SERVER_ROUTINE)PNP_SetDeviceRegProp,
    (SERVER_ROUTINE)PNP_GetClassInstance,
    (SERVER_ROUTINE)PNP_CreateKey,
    (SERVER_ROUTINE)PNP_DeleteRegistryKey,
    (SERVER_ROUTINE)PNP_GetClassCount,
    (SERVER_ROUTINE)PNP_GetClassName,
    (SERVER_ROUTINE)PNP_DeleteClassKey,
    (SERVER_ROUTINE)PNP_GetInterfaceDeviceAlias,
    (SERVER_ROUTINE)PNP_GetInterfaceDeviceList,
    (SERVER_ROUTINE)PNP_GetInterfaceDeviceListSize,
    (SERVER_ROUTINE)PNP_RegisterDeviceClassAssociation,
    (SERVER_ROUTINE)PNP_UnregisterDeviceClassAssociation,
    (SERVER_ROUTINE)PNP_GetClassRegProp,
    (SERVER_ROUTINE)PNP_SetClassRegProp,
    (SERVER_ROUTINE)PNP_CreateDevInst,
    (SERVER_ROUTINE)PNP_DeviceInstanceAction,
    (SERVER_ROUTINE)PNP_GetDeviceStatus,
    (SERVER_ROUTINE)PNP_SetDeviceProblem,
    (SERVER_ROUTINE)PNP_DisableDevInst,
    (SERVER_ROUTINE)PNP_UninstallDevInst,
    (SERVER_ROUTINE)PNP_AddID,
    (SERVER_ROUTINE)PNP_RegisterDriver,
    (SERVER_ROUTINE)PNP_QueryRemove,
    (SERVER_ROUTINE)PNP_RequestDeviceEject,
    (SERVER_ROUTINE)PNP_IsDockStationPresent,
    (SERVER_ROUTINE)PNP_RequestEjectPC,
    (SERVER_ROUTINE)PNP_HwProfFlags,
    (SERVER_ROUTINE)PNP_GetHwProfInfo,
    (SERVER_ROUTINE)PNP_AddEmptyLogConf,
    (SERVER_ROUTINE)PNP_FreeLogConf,
    (SERVER_ROUTINE)PNP_GetFirstLogConf,
    (SERVER_ROUTINE)PNP_GetNextLogConf,
    (SERVER_ROUTINE)PNP_GetLogConfPriority,
    (SERVER_ROUTINE)PNP_AddResDes,
    (SERVER_ROUTINE)PNP_FreeResDes,
    (SERVER_ROUTINE)PNP_GetNextResDes,
    (SERVER_ROUTINE)PNP_GetResDesData,
    (SERVER_ROUTINE)PNP_GetResDesDataSize,
    (SERVER_ROUTINE)PNP_ModifyResDes,
    (SERVER_ROUTINE)PNP_DetectResourceConflict,
    (SERVER_ROUTINE)PNP_QueryResConfList,
    (SERVER_ROUTINE)PNP_SetHwProf,
    (SERVER_ROUTINE)PNP_QueryArbitratorFreeData,
    (SERVER_ROUTINE)PNP_QueryArbitratorFreeSize,
    (SERVER_ROUTINE)PNP_RunDetection,
    (SERVER_ROUTINE)PNP_RegisterNotification,
    (SERVER_ROUTINE)PNP_UnregisterNotification,
    (SERVER_ROUTINE)PNP_GetCustomDevProp,
    (SERVER_ROUTINE)PNP_GetVersionInternal,
    (SERVER_ROUTINE)PNP_GetBlockedDriverInfo,
    (SERVER_ROUTINE)PNP_GetServerSideDeviceInstallFlags
    };

static const MIDL_SERVER_INFO pnp_ServerInfo = 
    {
    &pnp_StubDesc,
    pnp_ServerRoutineTable,
    __MIDL_ProcFormatString.Format,
    pnp_FormatStringOffsetTable,
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
/* Compiler settings for pnp.idl:
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
#include "pnp.h"

#define TYPE_FORMAT_STRING_SIZE   449                               
#define PROC_FORMAT_STRING_SIZE   3953                              
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

/* Standard interface: pnp, ver. 1.0,
   GUID={0x8D9F4E40,0xA03D,0x11CE,{0x8F,0x69,0x08,0x00,0x3E,0x30,0x05,0x1B}} */


extern const MIDL_SERVER_INFO pnp_ServerInfo;

extern RPC_DISPATCH_TABLE pnp_DispatchTable;

static const RPC_SERVER_INTERFACE pnp___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x8D9F4E40,0xA03D,0x11CE,{0x8F,0x69,0x08,0x00,0x3E,0x30,0x05,0x1B}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    &pnp_DispatchTable,
    0,
    0,
    0,
    &pnp_ServerInfo,
    0x04000000
    };
RPC_IF_HANDLE pnp_ServerIfHandle = (RPC_IF_HANDLE)& pnp___RpcServerInterface;

extern const MIDL_STUB_DESC pnp_StubDesc;

extern const NDR_RUNDOWN RundownRoutines[];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure PNP_Connect */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 10 */	0x31,		/* FC_BIND_GENERIC */
			0x8,		/* 8 */
/* 12 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 14 */	0x0,		/* 0 */
			0x5c,		/* FC_PAD */
/* 16 */	NdrFcShort( 0x0 ),	/* 0 */
/* 18 */	NdrFcShort( 0x8 ),	/* 8 */
/* 20 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 22 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter UNCServerName */

/* 32 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 34 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 36 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 38 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 40 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 42 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_Disconnect */

/* 44 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 46 */	NdrFcLong( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x1 ),	/* 1 */
/* 52 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 54 */	0x31,		/* FC_BIND_GENERIC */
			0x8,		/* 8 */
/* 56 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 58 */	0x0,		/* 0 */
			0x5c,		/* FC_PAD */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x8 ),	/* 8 */
/* 64 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 66 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter UNCServerName */

/* 76 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 78 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 80 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 82 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 84 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 86 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetVersion */

/* 88 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 90 */	NdrFcLong( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x2 ),	/* 2 */
/* 96 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 98 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 104 */	NdrFcShort( 0x22 ),	/* 34 */
/* 106 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 108 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 118 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 120 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 122 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVersion */

/* 124 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 126 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetGlobalState */


	/* Return value */

/* 130 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x3 ),	/* 3 */
/* 138 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 140 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 142 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 146 */	NdrFcShort( 0x24 ),	/* 36 */
/* 148 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 150 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 160 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 162 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulState */

/* 166 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 168 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 172 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 174 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_InitDetection */


	/* Return value */

/* 178 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 180 */	NdrFcLong( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x4 ),	/* 4 */
/* 186 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 188 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 190 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 196 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 198 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 210 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_ReportLogOn */


	/* Return value */

/* 214 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x5 ),	/* 5 */
/* 222 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 224 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 228 */	NdrFcShort( 0x10 ),	/* 16 */
/* 230 */	NdrFcShort( 0x8 ),	/* 8 */
/* 232 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 234 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 244 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 246 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bAdmin */

/* 250 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 252 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ProcessID */

/* 256 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 258 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_ValidateDeviceInstance */


	/* Return value */

/* 262 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 264 */	NdrFcLong( 0x0 ),	/* 0 */
/* 268 */	NdrFcShort( 0x6 ),	/* 6 */
/* 270 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 272 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 280 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 282 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 292 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 294 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 296 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 298 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 300 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 306 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetRootDeviceInstance */


	/* Return value */

/* 310 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x7 ),	/* 7 */
/* 318 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 320 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 324 */	NdrFcShort( 0x8 ),	/* 8 */
/* 326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 328 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 330 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 332 */	NdrFcShort( 0x1 ),	/* 1 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 340 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 342 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 344 */	NdrFcShort( 0x16 ),	/* Type Offset=22 */

	/* Parameter pDeviceID */

/* 346 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 348 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 352 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 354 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetRelatedDeviceInstance */


	/* Return value */

/* 358 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 360 */	NdrFcLong( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 366 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 368 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 372 */	NdrFcShort( 0x2c ),	/* 44 */
/* 374 */	NdrFcShort( 0x24 ),	/* 36 */
/* 376 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 378 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 380 */	NdrFcShort( 0x1 ),	/* 1 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 388 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 390 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulRelationship */

/* 394 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 396 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 398 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 400 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 402 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 404 */	NdrFcShort( 0x22 ),	/* Type Offset=34 */

	/* Parameter pRelatedDeviceID */

/* 406 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 408 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 412 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 414 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 420 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_EnumerateSubKeys */


	/* Return value */

/* 424 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 430 */	NdrFcShort( 0x9 ),	/* 9 */
/* 432 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 434 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 436 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 438 */	NdrFcShort( 0x20 ),	/* 32 */
/* 440 */	NdrFcShort( 0x24 ),	/* 36 */
/* 442 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x7,		/* 7 */
/* 444 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 446 */	NdrFcShort( 0x1 ),	/* 1 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 456 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulBranch */

/* 460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 462 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulIndex */

/* 466 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 468 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 470 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Parameter Buffer */

/* 472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 474 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 478 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 480 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulRequiredLen */

/* 484 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 486 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 490 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 492 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetDeviceList */


	/* Return value */

/* 496 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 498 */	NdrFcLong( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0xa ),	/* 10 */
/* 504 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 506 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 508 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 510 */	NdrFcShort( 0x24 ),	/* 36 */
/* 512 */	NdrFcShort( 0x24 ),	/* 36 */
/* 514 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 516 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 518 */	NdrFcShort( 0x1 ),	/* 1 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 526 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 528 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 530 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszFilter */

/* 532 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 534 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 536 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Parameter Buffer */

/* 538 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 540 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 546 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 550 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 552 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetDeviceListSize */


	/* Return value */

/* 556 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0xb ),	/* 11 */
/* 564 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 566 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 568 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 572 */	NdrFcShort( 0x24 ),	/* 36 */
/* 574 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 576 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 586 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 588 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 590 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszFilter */

/* 592 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 594 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLen */

/* 598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 600 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 606 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetDepth */


	/* Return value */

/* 610 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0xc ),	/* 12 */
/* 618 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 620 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 622 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 626 */	NdrFcShort( 0x24 ),	/* 36 */
/* 628 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 630 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 640 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 642 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 644 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 646 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 648 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulDepth */

/* 652 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 654 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 660 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetDeviceRegProp */


	/* Return value */

/* 664 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0xd ),	/* 13 */
/* 672 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 674 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 676 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 678 */	NdrFcShort( 0x64 ),	/* 100 */
/* 680 */	NdrFcShort( 0x5c ),	/* 92 */
/* 682 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 684 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 686 */	NdrFcShort( 0x1 ),	/* 1 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 694 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 696 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 698 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 700 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 702 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProperty */

/* 706 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 708 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulRegDataType */

/* 712 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 714 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 716 */	NdrFcShort( 0x54 ),	/* Type Offset=84 */

	/* Parameter Buffer */

/* 718 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 720 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 724 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 726 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 730 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 732 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 736 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 738 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_SetDeviceRegProp */


	/* Return value */

/* 742 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 744 */	NdrFcLong( 0x0 ),	/* 0 */
/* 748 */	NdrFcShort( 0xe ),	/* 14 */
/* 750 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 752 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 754 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 756 */	NdrFcShort( 0x20 ),	/* 32 */
/* 758 */	NdrFcShort( 0x8 ),	/* 8 */
/* 760 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 762 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x1 ),	/* 1 */
/* 768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 770 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 772 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 774 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 776 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 778 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 780 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProperty */

/* 784 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 786 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 788 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulDataType */

/* 790 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 792 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 794 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter Buffer */

/* 796 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 798 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 802 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 804 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 808 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 810 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetClassInstance */


	/* Return value */

/* 814 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 816 */	NdrFcLong( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0xf ),	/* 15 */
/* 822 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 824 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 826 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 832 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 834 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 836 */	NdrFcShort( 0x1 ),	/* 1 */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 844 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 846 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 848 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 850 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 852 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 854 */	NdrFcShort( 0x7a ),	/* Type Offset=122 */

	/* Parameter pszClassInstance */

/* 856 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 858 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 862 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 864 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_CreateKey */


	/* Return value */

/* 868 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 870 */	NdrFcLong( 0x0 ),	/* 0 */
/* 874 */	NdrFcShort( 0x10 ),	/* 16 */
/* 876 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 878 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 880 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 882 */	NdrFcShort( 0x10 ),	/* 16 */
/* 884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 886 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 888 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 898 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 900 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 902 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszSubKey */

/* 904 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 906 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter samDesired */

/* 910 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 912 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 914 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 916 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 918 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_DeleteRegistryKey */


	/* Return value */

/* 922 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 928 */	NdrFcShort( 0x11 ),	/* 17 */
/* 930 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 932 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 934 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 940 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 942 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 950 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 952 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 954 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 956 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 958 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 960 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 962 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszParentKey */

/* 964 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 966 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 968 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszChildKey */

/* 970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 972 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 978 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetClassCount */


	/* Return value */

/* 982 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 988 */	NdrFcShort( 0x12 ),	/* 18 */
/* 990 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 992 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 994 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 998 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1000 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1002 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1012 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1014 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulClassCount */

/* 1018 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1020 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1024 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1026 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetClassName */


	/* Return value */

/* 1030 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1038 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1040 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1042 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1044 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1046 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1048 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1050 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1052 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1060 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1062 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1064 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszClassGuid */

/* 1066 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1068 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1070 */	NdrFcShort( 0x86 ),	/* Type Offset=134 */

	/* Parameter Buffer */

/* 1072 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1074 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 1078 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1080 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1084 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1086 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1088 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_DeleteClassKey */


	/* Return value */

/* 1090 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1092 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1098 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1100 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1102 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1104 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1108 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1110 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1120 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1122 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1124 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszClassGuid */

/* 1126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1128 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1134 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetInterfaceDeviceAlias */


	/* Return value */

/* 1138 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1146 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1148 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1150 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1152 */	NdrFcShort( 0x84 ),	/* 132 */
/* 1154 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1156 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 1158 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1160 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1168 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1170 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1172 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszInterfaceDevice */

/* 1174 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1176 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1178 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter AliasInterfaceGuid */

/* 1180 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1182 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1184 */	NdrFcShort( 0xa8 ),	/* Type Offset=168 */

	/* Parameter pszAliasInterfaceDevice */

/* 1186 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1188 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 1192 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1194 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 1198 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1200 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1206 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetInterfaceDeviceList */


	/* Return value */

/* 1210 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1216 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1218 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1220 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1222 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1224 */	NdrFcShort( 0x68 ),	/* 104 */
/* 1226 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1228 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1230 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1232 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1240 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1242 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1244 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter InterfaceGuid */

/* 1246 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1248 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1250 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceID */

/* 1252 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1254 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1256 */	NdrFcShort( 0xb4 ),	/* Type Offset=180 */

	/* Parameter Buffer */

/* 1258 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1260 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 1264 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1266 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1272 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetInterfaceDeviceListSize */


	/* Return value */

/* 1276 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1282 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1284 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1286 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1288 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1290 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1292 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1294 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1296 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1306 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1308 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLen */

/* 1312 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1314 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1316 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter InterfaceGuid */

/* 1318 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1320 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1322 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceID */

/* 1324 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1326 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1332 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RegisterDeviceClassAssociation */


	/* Return value */

/* 1336 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1344 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 1346 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1348 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1350 */	NdrFcShort( 0x84 ),	/* 132 */
/* 1352 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1354 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1356 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1358 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1366 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1368 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1370 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceID */

/* 1372 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1374 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1376 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter InterfaceGuid */

/* 1378 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1380 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1382 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszReference */

/* 1384 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1386 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1388 */	NdrFcShort( 0xca ),	/* Type Offset=202 */

	/* Parameter pszSymLink */

/* 1390 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1392 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 1396 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1398 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 1402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1404 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1410 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_UnregisterDeviceClassAssociation */


	/* Return value */

/* 1414 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1420 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1422 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1424 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1426 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1432 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1434 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1442 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1444 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1446 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1448 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszInterfaceDevice */

/* 1450 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1452 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1458 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetClassRegProp */


	/* Return value */

/* 1462 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1468 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1470 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 1472 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1474 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1476 */	NdrFcShort( 0x64 ),	/* 100 */
/* 1478 */	NdrFcShort( 0x5c ),	/* 92 */
/* 1480 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1482 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1484 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1492 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1494 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1496 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszClassGuid */

/* 1498 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1500 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProperty */

/* 1504 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1506 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulRegDataType */

/* 1510 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1512 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1514 */	NdrFcShort( 0x54 ),	/* Type Offset=84 */

	/* Parameter Buffer */

/* 1516 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1518 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 1522 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 1524 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 1528 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1530 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1536 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_SetClassRegProp */


	/* Return value */

/* 1540 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1548 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1550 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1552 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1554 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1556 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1558 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 1560 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1564 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1570 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1572 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1574 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszClassGuid */

/* 1576 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1578 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProperty */

/* 1582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1584 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulDataType */

/* 1588 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1590 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1592 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter Buffer */

/* 1594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1596 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 1600 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1602 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1608 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_CreateDevInst */


	/* Return value */

/* 1612 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1620 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1622 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1624 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1626 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1630 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1632 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1634 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1636 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1642 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1644 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1646 */	NdrFcShort( 0xd6 ),	/* Type Offset=214 */

	/* Parameter pszDeviceID */

/* 1648 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1650 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1652 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszParentDeviceID */

/* 1654 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1656 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLength */

/* 1660 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1662 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1668 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_DeviceInstanceAction */


	/* Return value */

/* 1672 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1678 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1680 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1682 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1684 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1686 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1690 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1692 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1702 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1704 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulMajorAction */

/* 1708 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1710 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulMinorAction */

/* 1714 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1716 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1718 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceInstance1 */

/* 1720 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1722 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1724 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceInstance2 */

/* 1726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1728 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetDeviceStatus */


	/* Return value */

/* 1732 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1734 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1738 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1740 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1742 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1744 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1748 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1750 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1752 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1762 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1764 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1766 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pDeviceID */

/* 1768 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1770 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulStatus */

/* 1774 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1776 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulProblem */

/* 1780 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1782 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1788 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_SetDeviceProblem */


	/* Return value */

/* 1792 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1800 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1802 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1804 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1806 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1810 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1812 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1822 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1824 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1826 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pDeviceID */

/* 1828 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1830 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProblem */

/* 1834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1836 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1842 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_DisableDevInst */


	/* Return value */

/* 1846 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1852 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1854 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1856 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1858 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1860 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1862 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1864 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1866 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1868 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1870 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1876 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1878 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1880 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pDeviceID */

/* 1882 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 1884 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1886 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter pVetoType */

/* 1888 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 1890 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1892 */	NdrFcShort( 0xe2 ),	/* Type Offset=226 */

	/* Parameter pszVetoName */

/* 1894 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1896 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulNameLength */

/* 1900 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1902 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1908 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_UninstallDevInst */


	/* Return value */

/* 1912 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1918 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1920 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1922 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1924 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1926 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1928 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1930 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1932 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1942 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1944 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1946 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pDeviceID */

/* 1948 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1950 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 1954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1956 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_AddID */


	/* Return value */

/* 1960 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1966 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1968 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1970 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1972 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 1974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1978 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1980 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 1990 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1992 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1994 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pszDeviceID */

/* 1996 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1998 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2000 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszID */

/* 2002 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2004 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2008 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2010 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RegisterDriver */


	/* Return value */

/* 2014 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2016 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2020 */	NdrFcShort( 0x23 ),	/* 35 */
/* 2022 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2024 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2026 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2028 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2030 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2032 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2034 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2044 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2046 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2048 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 2050 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2052 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2058 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_QueryRemove */


	/* Return value */

/* 2062 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2070 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2072 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2074 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2076 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2078 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2080 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2082 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2084 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2086 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2092 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2094 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2096 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 2098 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 2100 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2102 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter pVetoType */

/* 2104 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 2106 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2108 */	NdrFcShort( 0xee ),	/* Type Offset=238 */

	/* Parameter pszVetoName */

/* 2110 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2112 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulNameLength */

/* 2116 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2118 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2122 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2124 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RequestDeviceEject */


	/* Return value */

/* 2128 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2130 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2134 */	NdrFcShort( 0x25 ),	/* 37 */
/* 2136 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2138 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2140 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2142 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2144 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2146 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2148 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2150 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2152 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2158 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2160 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2162 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 2164 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 2166 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2168 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter pVetoType */

/* 2170 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 2172 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2174 */	NdrFcShort( 0xfa ),	/* Type Offset=250 */

	/* Parameter pszVetoName */

/* 2176 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2178 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulNameLength */

/* 2182 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2184 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2190 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_IsDockStationPresent */


	/* Return value */

/* 2194 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2200 */	NdrFcShort( 0x26 ),	/* 38 */
/* 2202 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2204 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2206 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2208 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2210 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2212 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2214 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2222 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2224 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 2226 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2228 */	NdrFcShort( 0x106 ),	/* Type Offset=262 */

	/* Parameter Present */

/* 2230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2232 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RequestEjectPC */


	/* Return value */

/* 2236 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2242 */	NdrFcShort( 0x27 ),	/* 39 */
/* 2244 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2246 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2248 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2256 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2268 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_HwProfFlags */


	/* Return value */

/* 2272 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2278 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2280 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 2282 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2284 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2286 */	NdrFcShort( 0x56 ),	/* 86 */
/* 2288 */	NdrFcShort( 0x3e ),	/* 62 */
/* 2290 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2292 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2294 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2296 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2304 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulAction */

/* 2308 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2310 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2312 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2316 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulConfig */

/* 2320 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2322 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulValue */

/* 2326 */	NdrFcShort( 0x201a ),	/* Flags:  must free, in, out, srv alloc size=8 */
/* 2328 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2330 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter pVetoType */

/* 2332 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 2334 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2336 */	NdrFcShort( 0x10a ),	/* Type Offset=266 */

	/* Parameter pszVetoName */

/* 2338 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2340 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulNameLength */

/* 2344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2346 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 2348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2352 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 2354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetHwProfInfo */


	/* Return value */

/* 2356 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2362 */	NdrFcShort( 0x29 ),	/* 41 */
/* 2364 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2366 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2368 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2370 */	NdrFcShort( 0xf4 ),	/* 244 */
/* 2372 */	NdrFcShort( 0xe4 ),	/* 228 */
/* 2374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2376 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2388 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulIndex */

/* 2392 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 2394 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2396 */	NdrFcShort( 0x120 ),	/* Type Offset=288 */

	/* Parameter pHWProfileInfo */

/* 2398 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2400 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulProfileInfoSize */

/* 2404 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2406 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2412 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_AddEmptyLogConf */


	/* Return value */

/* 2416 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2424 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2426 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2428 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2430 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2432 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2434 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2436 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2444 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2446 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2448 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2450 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2452 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2454 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulPriority */

/* 2458 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2460 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLogConfTag */

/* 2464 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2466 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2472 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_FreeLogConf */


	/* Return value */

/* 2476 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2482 */	NdrFcShort( 0x2b ),	/* 43 */
/* 2484 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2486 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2488 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2490 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2494 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2496 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2506 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2508 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2510 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2512 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2514 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2518 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2520 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 2524 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2526 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2532 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetFirstLogConf */


	/* Return value */

/* 2536 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2542 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2544 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2546 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2548 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2550 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2552 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2554 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2556 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2564 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2566 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2568 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2570 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2572 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2574 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2578 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2580 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLogConfTag */

/* 2584 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2586 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2592 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetNextLogConf */


	/* Return value */

/* 2596 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2602 */	NdrFcShort( 0x2d ),	/* 45 */
/* 2604 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2606 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2608 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2610 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2612 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2614 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2616 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2624 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2626 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2628 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2630 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2632 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2634 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2638 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2640 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2642 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulCurrentTag */

/* 2644 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2646 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulNextTag */

/* 2650 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2652 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2658 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetLogConfPriority */


	/* Return value */

/* 2662 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2668 */	NdrFcShort( 0x2e ),	/* 46 */
/* 2670 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2672 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2674 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2676 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2678 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2680 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2682 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2690 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2692 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2694 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2696 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2700 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulType */

/* 2704 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2706 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulTag */

/* 2710 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2712 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPriority */

/* 2716 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2718 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2722 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2724 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2726 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_AddResDes */


	/* Return value */

/* 2728 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2730 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2734 */	NdrFcShort( 0x2f ),	/* 47 */
/* 2736 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 2738 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2740 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2742 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2744 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2746 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2748 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2752 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2756 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2758 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2760 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2762 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2764 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2766 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 2770 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2772 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2776 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2778 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 2782 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2784 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulResourceTag */

/* 2788 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2790 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2792 */	NdrFcShort( 0x130 ),	/* Type Offset=304 */

	/* Parameter ResourceData */

/* 2794 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2796 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceLen */

/* 2800 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2802 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 2804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2808 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 2810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_FreeResDes */


	/* Return value */

/* 2812 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2818 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2820 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 2822 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2824 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2826 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2828 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2830 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2832 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2842 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2844 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2846 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2850 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 2854 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2856 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2860 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2862 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 2866 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2868 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulResourceTag */

/* 2872 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2874 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulPreviousResType */

/* 2878 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2880 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulPreviousResTag */

/* 2884 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2886 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 2888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2890 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2892 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 2894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetNextResDes */


	/* Return value */

/* 2896 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2898 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2902 */	NdrFcShort( 0x31 ),	/* 49 */
/* 2904 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 2906 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2908 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2910 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2912 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2914 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2916 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2924 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 2926 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2928 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2930 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 2932 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2934 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 2938 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2940 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 2944 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2946 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 2950 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2952 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2954 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulResourceTag */

/* 2956 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2958 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulNextResDesTag */

/* 2962 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2964 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulNextResDesType */

/* 2968 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2970 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 2972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 2974 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2976 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 2978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetResDesData */


	/* Return value */

/* 2980 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2982 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2986 */	NdrFcShort( 0x32 ),	/* 50 */
/* 2988 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 2990 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2992 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 2994 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2998 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 3000 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3002 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3008 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3010 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3012 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3014 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 3016 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3018 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 3022 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3024 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 3028 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3030 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3034 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3036 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulResourceTag */

/* 3040 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3042 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3044 */	NdrFcShort( 0x130 ),	/* Type Offset=304 */

	/* Parameter Buffer */

/* 3046 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3048 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter BufferLen */

/* 3052 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3054 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3058 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3060 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 3062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetResDesDataSize */


	/* Return value */

/* 3064 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3070 */	NdrFcShort( 0x33 ),	/* 51 */
/* 3072 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 3074 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3076 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3078 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3080 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3082 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3084 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3092 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3094 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3096 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3098 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 3100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3102 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 3106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3108 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 3112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3114 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3118 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3120 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulResourceTag */

/* 3124 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3126 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulSize */

/* 3130 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3132 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3136 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3138 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_ModifyResDes */


	/* Return value */

/* 3142 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3148 */	NdrFcShort( 0x34 ),	/* 52 */
/* 3150 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 3152 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3154 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3156 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3160 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xa,		/* 10 */
/* 3162 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3166 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3170 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3172 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3174 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3176 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 3178 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3180 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfTag */

/* 3184 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3186 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulLogConfType */

/* 3190 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3192 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter CurrentResourceID */

/* 3196 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3198 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter NewResourceID */

/* 3202 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3204 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulResourceTag */

/* 3208 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3210 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3212 */	NdrFcShort( 0x140 ),	/* Type Offset=320 */

	/* Parameter ResourceData */

/* 3214 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3216 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceLen */

/* 3220 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3222 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 3224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3226 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3228 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 3230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_DetectResourceConflict */


	/* Return value */

/* 3232 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3238 */	NdrFcShort( 0x35 ),	/* 53 */
/* 3240 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3242 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3244 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3246 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3248 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3250 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3252 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3256 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3260 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3262 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3264 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3266 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 3268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3270 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3274 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3276 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3278 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Parameter ResourceData */

/* 3280 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3282 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceLen */

/* 3286 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3288 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbConflictDetected */

/* 3292 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3294 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3298 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3300 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_QueryResConfList */


	/* Return value */

/* 3304 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3310 */	NdrFcShort( 0x36 ),	/* 54 */
/* 3312 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 3314 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3316 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3318 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3322 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3324 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3326 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3328 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3332 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3334 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3336 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3338 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 3340 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3342 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3346 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3348 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3350 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Parameter ResourceData */

/* 3352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3354 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceLen */

/* 3358 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3360 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3362 */	NdrFcShort( 0x160 ),	/* Type Offset=352 */

	/* Parameter Buffer */

/* 3364 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3366 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter BufferLen */

/* 3370 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3372 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3378 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_SetHwProf */


	/* Return value */

/* 3382 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3388 */	NdrFcShort( 0x37 ),	/* 55 */
/* 3390 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3392 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3394 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3396 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3400 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3402 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3410 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3412 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3414 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulHardwareProfile */

/* 3418 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3420 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3424 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3426 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_QueryArbitratorFreeData */


	/* Return value */

/* 3430 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3436 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3438 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3440 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3442 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3444 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3446 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3448 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3450 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3452 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3460 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3462 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3464 */	NdrFcShort( 0x170 ),	/* Type Offset=368 */

	/* Parameter pData */

/* 3466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3468 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulDataLen */

/* 3472 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3474 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3476 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 3478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3480 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3484 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3486 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3490 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3492 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_QueryArbitratorFreeSize */


	/* Return value */

/* 3496 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3498 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3502 */	NdrFcShort( 0x39 ),	/* 57 */
/* 3504 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3506 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3508 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3510 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3512 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3514 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3516 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3524 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3526 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3528 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulSize */

/* 3532 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3534 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3536 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pszDeviceID */

/* 3538 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3540 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ResourceID */

/* 3544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3546 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3550 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3552 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RunDetection */


	/* Return value */

/* 3556 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3562 */	NdrFcShort( 0x3a ),	/* 58 */
/* 3564 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3566 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3568 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3574 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3576 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3584 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3588 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3592 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3594 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_RegisterNotification */


	/* Return value */

/* 3598 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3604 */	NdrFcShort( 0x3b ),	/* 59 */
/* 3606 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 3608 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3610 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3612 */	NdrFcShort( 0x44 ),	/* 68 */
/* 3614 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3616 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 3618 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3622 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3628 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3630 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3632 */	0xb9,		/* FC_UINT3264 */
			0x0,		/* 0 */

	/* Parameter hRecipient */

/* 3634 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3636 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3638 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter ServiceName */

/* 3640 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3642 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3644 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Parameter NotificationFilter */

/* 3646 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3648 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulSize */

/* 3652 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3654 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Flags */

/* 3658 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 3660 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3662 */	NdrFcShort( 0x180 ),	/* Type Offset=384 */

	/* Parameter Context */

/* 3664 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3666 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hProcess */

/* 3670 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3672 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3674 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter ClientContext */

/* 3676 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3678 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 3680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_UnregisterNotification */


	/* Return value */

/* 3682 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3684 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3688 */	NdrFcShort( 0x3c ),	/* 60 */
/* 3690 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3692 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3694 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3696 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3698 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3700 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3702 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3712 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 3714 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3716 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Parameter Context */

/* 3718 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3720 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetCustomDevProp */


	/* Return value */

/* 3724 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3726 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3730 */	NdrFcShort( 0x3d ),	/* 61 */
/* 3732 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 3734 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3736 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3738 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3740 */	NdrFcShort( 0x5c ),	/* 92 */
/* 3742 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3744 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3746 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3752 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3754 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3756 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3758 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter pDeviceID */

/* 3760 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3762 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3764 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */

	/* Parameter CustomPropName */

/* 3766 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3768 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulRegDataType */

/* 3772 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3774 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3776 */	NdrFcShort( 0x194 ),	/* Type Offset=404 */

	/* Parameter Buffer */

/* 3778 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3780 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 3784 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3786 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3788 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 3790 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3792 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3796 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3798 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetVersionInternal */


	/* Return value */

/* 3802 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3804 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3808 */	NdrFcShort( 0x3e ),	/* 62 */
/* 3810 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3812 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3814 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3816 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3818 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3820 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3822 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3832 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3834 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3836 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pwVersion */

/* 3838 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3840 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3842 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetBlockedDriverInfo */


	/* Return value */

/* 3844 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3846 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3850 */	NdrFcShort( 0x3f ),	/* 63 */
/* 3852 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3854 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3856 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3858 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3860 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3862 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 3864 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3866 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3874 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3876 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3878 */	NdrFcShort( 0x1ae ),	/* Type Offset=430 */

	/* Parameter Buffer */

/* 3880 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3882 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulTransferLen */

/* 3886 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3888 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulLength */

/* 3892 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3894 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3896 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3898 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3900 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PNP_GetServerSideDeviceInstallFlags */


	/* Return value */

/* 3904 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3906 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3910 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3912 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3914 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3916 */	NdrFcShort( 0x0 ),	/* ia64 Stack size/offset = 0 */
/* 3918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3920 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3922 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3924 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3932 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBinding */

/* 3934 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3936 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulSSDIFlags */

/* 3940 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3942 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulFlags */

/* 3946 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3948 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3950 */	0x8,		/* FC_LONG */
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
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  8 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 12 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 14 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 16 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 18 */	
			0x11, 0x0,	/* FC_RP */
/* 20 */	NdrFcShort( 0x2 ),	/* Offset= 2 (22) */
/* 22 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 24 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 26 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 28 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 30 */	
			0x11, 0x0,	/* FC_RP */
/* 32 */	NdrFcShort( 0x2 ),	/* Offset= 2 (34) */
/* 34 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 36 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 38 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 40 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 42 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 44 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 46 */	
			0x11, 0x0,	/* FC_RP */
/* 48 */	NdrFcShort( 0x2 ),	/* Offset= 2 (50) */
/* 50 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 52 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 54 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 56 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 58 */	
			0x11, 0x0,	/* FC_RP */
/* 60 */	NdrFcShort( 0x2 ),	/* Offset= 2 (62) */
/* 62 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 64 */	NdrFcShort( 0x2 ),	/* 2 */
/* 66 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 68 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 70 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 72 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 74 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 76 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 78 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 80 */	
			0x11, 0x0,	/* FC_RP */
/* 82 */	NdrFcShort( 0x2 ),	/* Offset= 2 (84) */
/* 84 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 86 */	NdrFcShort( 0x1 ),	/* 1 */
/* 88 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 90 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 92 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 94 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 96 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 98 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 100 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 102 */	
			0x11, 0x0,	/* FC_RP */
/* 104 */	NdrFcShort( 0x2 ),	/* Offset= 2 (106) */
/* 106 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 108 */	NdrFcShort( 0x1 ),	/* 1 */
/* 110 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 112 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 114 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 116 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 118 */	
			0x11, 0x0,	/* FC_RP */
/* 120 */	NdrFcShort( 0x2 ),	/* Offset= 2 (122) */
/* 122 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 124 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 126 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 128 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 130 */	
			0x11, 0x0,	/* FC_RP */
/* 132 */	NdrFcShort( 0x2 ),	/* Offset= 2 (134) */
/* 134 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 136 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 138 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 140 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 142 */	
			0x11, 0x0,	/* FC_RP */
/* 144 */	NdrFcShort( 0x8 ),	/* Offset= 8 (152) */
/* 146 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 148 */	NdrFcShort( 0x8 ),	/* 8 */
/* 150 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 152 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 154 */	NdrFcShort( 0x10 ),	/* 16 */
/* 156 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 158 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 160 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (146) */
			0x5b,		/* FC_END */
/* 164 */	
			0x11, 0x0,	/* FC_RP */
/* 166 */	NdrFcShort( 0x2 ),	/* Offset= 2 (168) */
/* 168 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 170 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 172 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 174 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 176 */	
			0x11, 0x0,	/* FC_RP */
/* 178 */	NdrFcShort( 0x2 ),	/* Offset= 2 (180) */
/* 180 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 182 */	NdrFcShort( 0x2 ),	/* 2 */
/* 184 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 186 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 188 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 190 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 192 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 194 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 196 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 198 */	
			0x11, 0x0,	/* FC_RP */
/* 200 */	NdrFcShort( 0x2 ),	/* Offset= 2 (202) */
/* 202 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 204 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 206 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 208 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 210 */	
			0x11, 0x0,	/* FC_RP */
/* 212 */	NdrFcShort( 0x2 ),	/* Offset= 2 (214) */
/* 214 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 216 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 218 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 220 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 222 */	
			0x12, 0xc,	/* FC_UP [alloced_on_stack] [simple_pointer] */
/* 224 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 226 */	
			0x12, 0x0,	/* FC_UP */
/* 228 */	NdrFcShort( 0x2 ),	/* Offset= 2 (230) */
/* 230 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 232 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 234 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 236 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 238 */	
			0x12, 0x0,	/* FC_UP */
/* 240 */	NdrFcShort( 0x2 ),	/* Offset= 2 (242) */
/* 242 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 244 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 246 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 248 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 250 */	
			0x12, 0x0,	/* FC_UP */
/* 252 */	NdrFcShort( 0x2 ),	/* Offset= 2 (254) */
/* 254 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 256 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 258 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 260 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 262 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 264 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 266 */	
			0x12, 0x0,	/* FC_UP */
/* 268 */	NdrFcShort( 0x2 ),	/* Offset= 2 (270) */
/* 270 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 272 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 274 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 276 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 278 */	
			0x11, 0x0,	/* FC_RP */
/* 280 */	NdrFcShort( 0x8 ),	/* Offset= 8 (288) */
/* 282 */	
			0x1d,		/* FC_SMFARRAY */
			0x1,		/* 1 */
/* 284 */	NdrFcShort( 0xa0 ),	/* 160 */
/* 286 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 288 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 290 */	NdrFcShort( 0xa8 ),	/* 168 */
/* 292 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 294 */	0x0,		/* 0 */
			NdrFcShort( 0xfff3 ),	/* Offset= -13 (282) */
			0x8,		/* FC_LONG */
/* 298 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 300 */	
			0x11, 0x0,	/* FC_RP */
/* 302 */	NdrFcShort( 0x2 ),	/* Offset= 2 (304) */
/* 304 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 306 */	NdrFcShort( 0x1 ),	/* 1 */
/* 308 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 310 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 312 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 314 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 316 */	
			0x11, 0x0,	/* FC_RP */
/* 318 */	NdrFcShort( 0x2 ),	/* Offset= 2 (320) */
/* 320 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 322 */	NdrFcShort( 0x1 ),	/* 1 */
/* 324 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 326 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 328 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 330 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 332 */	
			0x11, 0x0,	/* FC_RP */
/* 334 */	NdrFcShort( 0x2 ),	/* Offset= 2 (336) */
/* 336 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 338 */	NdrFcShort( 0x1 ),	/* 1 */
/* 340 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 342 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 344 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 346 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 348 */	
			0x11, 0x0,	/* FC_RP */
/* 350 */	NdrFcShort( 0x2 ),	/* Offset= 2 (352) */
/* 352 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 354 */	NdrFcShort( 0x1 ),	/* 1 */
/* 356 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 358 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 360 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 362 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 364 */	
			0x11, 0x0,	/* FC_RP */
/* 366 */	NdrFcShort( 0x2 ),	/* Offset= 2 (368) */
/* 368 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 370 */	NdrFcShort( 0x1 ),	/* 1 */
/* 372 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 374 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 376 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 378 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 380 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 382 */	NdrFcShort( 0x2 ),	/* Offset= 2 (384) */
/* 384 */	0x30,		/* FC_BIND_CONTEXT */
			0xa8,		/* Ctxt flags:  via ptr, out, strict, */
/* 386 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 388 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 390 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 392 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 394 */	NdrFcShort( 0x2 ),	/* Offset= 2 (396) */
/* 396 */	0x30,		/* FC_BIND_CONTEXT */
			0xe8,		/* Ctxt flags:  via ptr, in, out, strict, */
/* 398 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 400 */	
			0x11, 0x0,	/* FC_RP */
/* 402 */	NdrFcShort( 0x2 ),	/* Offset= 2 (404) */
/* 404 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 406 */	NdrFcShort( 0x1 ),	/* 1 */
/* 408 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 410 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 412 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 414 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 416 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 418 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 420 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 422 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 424 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 426 */	
			0x11, 0x0,	/* FC_RP */
/* 428 */	NdrFcShort( 0x2 ),	/* Offset= 2 (430) */
/* 430 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 432 */	NdrFcShort( 0x1 ),	/* 1 */
/* 434 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 436 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 438 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 440 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 442 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 444 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 446 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const NDR_RUNDOWN RundownRoutines[] = 
    {
    PNP_NOTIFICATION_CONTEXT_rundown
    };


static const unsigned short pnp_FormatStringOffsetTable[] =
    {
    0,
    44,
    88,
    130,
    178,
    214,
    262,
    310,
    358,
    424,
    496,
    556,
    610,
    664,
    742,
    814,
    868,
    922,
    982,
    1030,
    1090,
    1138,
    1210,
    1276,
    1336,
    1414,
    1462,
    1540,
    1612,
    1672,
    1732,
    1792,
    1846,
    1912,
    1960,
    2014,
    2062,
    2128,
    2194,
    2236,
    2272,
    2356,
    2416,
    2476,
    2536,
    2596,
    2662,
    2728,
    2812,
    2896,
    2980,
    3064,
    3142,
    3232,
    3304,
    3382,
    3430,
    3496,
    3556,
    3598,
    3682,
    3724,
    3802,
    3844,
    3904
    };


static const MIDL_STUB_DESC pnp_StubDesc = 
    {
    (void *)& pnp___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    RundownRoutines,
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

static RPC_DISPATCH_FUNCTION pnp_table[] =
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
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    0
    };
RPC_DISPATCH_TABLE pnp_DispatchTable = 
    {
    65,
    pnp_table
    };

static const SERVER_ROUTINE pnp_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)PNP_Connect,
    (SERVER_ROUTINE)PNP_Disconnect,
    (SERVER_ROUTINE)PNP_GetVersion,
    (SERVER_ROUTINE)PNP_GetGlobalState,
    (SERVER_ROUTINE)PNP_InitDetection,
    (SERVER_ROUTINE)PNP_ReportLogOn,
    (SERVER_ROUTINE)PNP_ValidateDeviceInstance,
    (SERVER_ROUTINE)PNP_GetRootDeviceInstance,
    (SERVER_ROUTINE)PNP_GetRelatedDeviceInstance,
    (SERVER_ROUTINE)PNP_EnumerateSubKeys,
    (SERVER_ROUTINE)PNP_GetDeviceList,
    (SERVER_ROUTINE)PNP_GetDeviceListSize,
    (SERVER_ROUTINE)PNP_GetDepth,
    (SERVER_ROUTINE)PNP_GetDeviceRegProp,
    (SERVER_ROUTINE)PNP_SetDeviceRegProp,
    (SERVER_ROUTINE)PNP_GetClassInstance,
    (SERVER_ROUTINE)PNP_CreateKey,
    (SERVER_ROUTINE)PNP_DeleteRegistryKey,
    (SERVER_ROUTINE)PNP_GetClassCount,
    (SERVER_ROUTINE)PNP_GetClassName,
    (SERVER_ROUTINE)PNP_DeleteClassKey,
    (SERVER_ROUTINE)PNP_GetInterfaceDeviceAlias,
    (SERVER_ROUTINE)PNP_GetInterfaceDeviceList,
    (SERVER_ROUTINE)PNP_GetInterfaceDeviceListSize,
    (SERVER_ROUTINE)PNP_RegisterDeviceClassAssociation,
    (SERVER_ROUTINE)PNP_UnregisterDeviceClassAssociation,
    (SERVER_ROUTINE)PNP_GetClassRegProp,
    (SERVER_ROUTINE)PNP_SetClassRegProp,
    (SERVER_ROUTINE)PNP_CreateDevInst,
    (SERVER_ROUTINE)PNP_DeviceInstanceAction,
    (SERVER_ROUTINE)PNP_GetDeviceStatus,
    (SERVER_ROUTINE)PNP_SetDeviceProblem,
    (SERVER_ROUTINE)PNP_DisableDevInst,
    (SERVER_ROUTINE)PNP_UninstallDevInst,
    (SERVER_ROUTINE)PNP_AddID,
    (SERVER_ROUTINE)PNP_RegisterDriver,
    (SERVER_ROUTINE)PNP_QueryRemove,
    (SERVER_ROUTINE)PNP_RequestDeviceEject,
    (SERVER_ROUTINE)PNP_IsDockStationPresent,
    (SERVER_ROUTINE)PNP_RequestEjectPC,
    (SERVER_ROUTINE)PNP_HwProfFlags,
    (SERVER_ROUTINE)PNP_GetHwProfInfo,
    (SERVER_ROUTINE)PNP_AddEmptyLogConf,
    (SERVER_ROUTINE)PNP_FreeLogConf,
    (SERVER_ROUTINE)PNP_GetFirstLogConf,
    (SERVER_ROUTINE)PNP_GetNextLogConf,
    (SERVER_ROUTINE)PNP_GetLogConfPriority,
    (SERVER_ROUTINE)PNP_AddResDes,
    (SERVER_ROUTINE)PNP_FreeResDes,
    (SERVER_ROUTINE)PNP_GetNextResDes,
    (SERVER_ROUTINE)PNP_GetResDesData,
    (SERVER_ROUTINE)PNP_GetResDesDataSize,
    (SERVER_ROUTINE)PNP_ModifyResDes,
    (SERVER_ROUTINE)PNP_DetectResourceConflict,
    (SERVER_ROUTINE)PNP_QueryResConfList,
    (SERVER_ROUTINE)PNP_SetHwProf,
    (SERVER_ROUTINE)PNP_QueryArbitratorFreeData,
    (SERVER_ROUTINE)PNP_QueryArbitratorFreeSize,
    (SERVER_ROUTINE)PNP_RunDetection,
    (SERVER_ROUTINE)PNP_RegisterNotification,
    (SERVER_ROUTINE)PNP_UnregisterNotification,
    (SERVER_ROUTINE)PNP_GetCustomDevProp,
    (SERVER_ROUTINE)PNP_GetVersionInternal,
    (SERVER_ROUTINE)PNP_GetBlockedDriverInfo,
    (SERVER_ROUTINE)PNP_GetServerSideDeviceInstallFlags
    };

static const MIDL_SERVER_INFO pnp_ServerInfo = 
    {
    &pnp_StubDesc,
    pnp_ServerRoutineTable,
    __MIDL_ProcFormatString.Format,
    pnp_FormatStringOffsetTable,
    0,
    0,
    0,
    0};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

