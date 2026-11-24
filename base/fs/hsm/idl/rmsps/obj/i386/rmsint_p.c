

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for rmsint.idl:
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


#include "rmsint.h"

#define TYPE_FORMAT_STRING_SIZE   667                               
#define PROC_FORMAT_STRING_SIZE   9415                              
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


extern const MIDL_SERVER_INFO IRmsServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsLibrary_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsLibrary_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsDriveClass_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsDriveClass_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsCartridge_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsCartridge_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsDrive_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsDrive_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsStorageSlot_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsStorageSlot_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsMediumChanger_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsMediumChanger_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsMoveMedia_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsMoveMedia_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsIEPort_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsIEPort_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsMediaSet_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsMediaSet_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsRequest_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsRequest_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsPartition_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsPartition_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsComObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsComObject_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsChangerElement_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsChangerElement_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsDevice_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsDevice_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsStorageInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsStorageInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsClient_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsClient_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsNTMS_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsNTMS_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsSinkEveryEvent_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsSinkEveryEvent_ProxyInfo;


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

	/* Procedure IsInstalled */


	/* Procedure Status */


	/* Procedure Initialize */


	/* Procedure IsReady */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
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


	/* Return value */


	/* Return value */


	/* Return value */

/* 24 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeState */

/* 30 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 32 */	NdrFcLong( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x8 ),	/* 8 */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	NdrFcShort( 0x8 ),	/* 8 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 46 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newState */

/* 54 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 56 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 58 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReleaseDevice */


	/* Procedure AddMountReference */


	/* Procedure IsNTMSInstalled */

/* 66 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x9 ),	/* 9 */
/* 74 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x8 ),	/* 8 */
/* 80 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 82 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 90 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 92 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 94 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNTMS */

/* 96 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 98 */	NdrFcLong( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0xa ),	/* 10 */
/* 104 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x8 ),	/* 8 */
/* 110 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 112 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 120 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 122 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 124 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 128 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsEnabled */


	/* Procedure IsDone */


	/* Procedure SelectForMount */


	/* Procedure InitializeInAnotherThread */

/* 132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0xb ),	/* 11 */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 146 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 148 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Enable */


	/* Procedure VerifyIdentifier */


	/* Procedure IsExport */


	/* Procedure Initialize */

/* 162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0xc ),	/* 12 */
/* 170 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 176 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 178 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsStorage */


	/* Procedure IsAutomatic */


	/* Procedure SaveAll */

/* 192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0xd ),	/* 13 */
/* 200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 206 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 208 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 216 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetServerName */

/* 222 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 224 */	NdrFcLong( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0xe ),	/* 14 */
/* 230 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 236 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 238 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 240 */	NdrFcShort( 0x1 ),	/* 1 */
/* 242 */	NdrFcShort( 0x1 ),	/* 1 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 246 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 248 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 250 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 254 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCartridges */

/* 258 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0xf ),	/* 15 */
/* 266 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 272 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 274 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 282 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 284 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 286 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 290 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActiveCartridges */

/* 294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x10 ),	/* 16 */
/* 302 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 308 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 310 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 318 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 322 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 326 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDataMovers */

/* 330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x11 ),	/* 17 */
/* 338 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 344 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 346 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 354 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 356 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 358 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetActiveCartridge */

/* 366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x12 ),	/* 18 */
/* 374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 380 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 382 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 390 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 392 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 394 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 398 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLibraries */

/* 402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x13 ),	/* 19 */
/* 410 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 416 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 418 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 426 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 428 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 430 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 434 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSets */

/* 438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x14 ),	/* 20 */
/* 446 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 452 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 454 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 462 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 464 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 466 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 470 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRequests */

/* 474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x15 ),	/* 21 */
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

	/* Parameter ptr */

/* 498 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 500 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 502 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 506 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetClients */

/* 510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x16 ),	/* 22 */
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

	/* Parameter ptr */

/* 534 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 536 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 538 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 540 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 542 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUnconfiguredDevices */

/* 546 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x17 ),	/* 23 */
/* 554 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x8 ),	/* 8 */
/* 560 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 562 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 570 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 572 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 574 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 578 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ScanForDevices */

/* 582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x18 ),	/* 24 */
/* 590 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 596 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 598 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 608 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ScanForDrives */

/* 612 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0x19 ),	/* 25 */
/* 620 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 626 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 628 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 638 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MountScratchCartridge */

/* 642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x1a ),	/* 26 */
/* 650 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 652 */	NdrFcShort( 0xbc ),	/* 188 */
/* 654 */	NdrFcShort( 0x70 ),	/* 112 */
/* 656 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 658 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x1 ),	/* 1 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCartId */

/* 666 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 670 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter fromMediaSet */

/* 672 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 674 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 676 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter prevSideId */

/* 678 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 680 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 682 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pFreeSpace */

/* 684 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 686 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 688 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter blockingFactor */

/* 690 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 692 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter displayName */

/* 696 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 698 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 700 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter ppDrive */

/* 702 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 704 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 706 */	NdrFcShort( 0x94 ),	/* Type Offset=148 */

	/* Parameter ppCartridge */

/* 708 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 710 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 712 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Parameter ppDataMover */

/* 714 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 716 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 718 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Parameter options */

/* 720 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 722 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 728 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MountCartridge */

/* 732 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 734 */	NdrFcLong( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x1b ),	/* 27 */
/* 740 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 742 */	NdrFcShort( 0x54 ),	/* 84 */
/* 744 */	NdrFcShort( 0x8 ),	/* 8 */
/* 746 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 748 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 756 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 758 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 760 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter ppDrive */

/* 762 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 766 */	NdrFcShort( 0x94 ),	/* Type Offset=148 */

	/* Parameter ppCartridge */

/* 768 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 770 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 772 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Parameter ppDataMover */

/* 774 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 776 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 778 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Parameter options */

/* 780 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 782 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 788 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 794 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DismountCartridge */

/* 798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x1c ),	/* 28 */
/* 806 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 808 */	NdrFcShort( 0x4c ),	/* 76 */
/* 810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 812 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 814 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 822 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 824 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 826 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter options */

/* 828 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 830 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 834 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 836 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DuplicateCartridge */

/* 840 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x1d ),	/* 29 */
/* 848 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 850 */	NdrFcShort( 0x118 ),	/* 280 */
/* 852 */	NdrFcShort( 0x94 ),	/* 148 */
/* 854 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 856 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x1 ),	/* 1 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 864 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 866 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 868 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter firstSideId */

/* 870 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 872 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 874 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pCopyCartId */

/* 876 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 878 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 880 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter copySet */

/* 882 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 884 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 886 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter copyName */

/* 888 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 890 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 892 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter pFreeSpace */

/* 894 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 896 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 898 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pCapacity */

/* 900 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 902 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 904 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter options */

/* 906 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 908 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 914 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RecycleCartridge */

/* 918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x1e ),	/* 30 */
/* 926 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 928 */	NdrFcShort( 0x4c ),	/* 76 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 934 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 942 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 946 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter options */

/* 948 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindLibraryById */

/* 960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x1f ),	/* 31 */
/* 968 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 970 */	NdrFcShort( 0x44 ),	/* 68 */
/* 972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 974 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 976 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libId */

/* 984 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 988 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter ptr */

/* 990 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 994 */	NdrFcShort( 0xc8 ),	/* Type Offset=200 */

	/* Return value */

/* 996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 998 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCartridgeById */

/* 1002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1010 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1012 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1016 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1018 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 1026 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1028 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1030 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter ptr */

/* 1032 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1036 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 1038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1040 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateObject */

/* 1044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1052 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1054 */	NdrFcShort( 0xd4 ),	/* 212 */
/* 1056 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1058 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x6,		/* 6 */
/* 1060 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1062 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter objectId */

/* 1068 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1070 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1072 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter rclsid */

/* 1074 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1078 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter riid */

/* 1080 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1082 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1084 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter dwCreate */

/* 1086 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1088 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1090 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppvObj */

/* 1092 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1094 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1096 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Return value */

/* 1098 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1100 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNofAvailableDrives */

/* 1104 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1112 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1114 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1116 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1118 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1120 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromMediaSet */

/* 1128 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1130 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1132 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pdwNofDrives */

/* 1134 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1136 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1142 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCartridgeStatusById */

/* 1146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1154 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1156 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1158 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1160 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1162 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 1170 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1172 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1174 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pdwStatus */

/* 1176 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1182 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1184 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMultipleSidedMedia */

/* 1188 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1190 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1196 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1198 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1202 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1204 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1210 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaSetId */

/* 1212 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1214 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1216 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 1218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1220 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckSecondSide */

/* 1224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1230 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1232 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1234 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1236 */	NdrFcShort( 0x68 ),	/* 104 */
/* 1238 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1240 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1246 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter firstSideId */

/* 1248 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1250 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1252 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pbValid */

/* 1254 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1256 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSecondSideId */

/* 1260 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1262 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1264 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 1266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1268 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxMediaCapacity */

/* 1272 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1278 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1280 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1282 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1284 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1286 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1288 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromMediaSet */

/* 1296 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1298 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1300 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pMaxCapacity */

/* 1302 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1304 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1306 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1310 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOwnerClassId */


	/* Procedure GetObjectId */


	/* Procedure GetMediaSetId */


	/* Procedure GetMediaSetId */


	/* Procedure GetDriveClassId */


	/* Procedure GetLibraryId */

/* 1314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1320 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1322 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1328 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1330 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1336 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */


	/* Parameter pObjectId */


	/* Parameter pMediaSetId */


	/* Parameter pMediaSetId */


	/* Parameter pDriveClassId */


	/* Parameter pLibId */

/* 1338 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1340 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1342 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1346 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOwnerClassId */


	/* Procedure SetObjectId */


	/* Procedure SetMediaSetId */


	/* Procedure SetLibraryId */

/* 1350 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1358 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1360 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1362 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1364 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1366 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */


	/* Parameter objectId */


	/* Parameter mediaSetId */


	/* Parameter libId */

/* 1374 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1376 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1378 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1382 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetName */

/* 1386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1394 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1400 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1402 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1404 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1406 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 1410 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1414 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */


	/* Return value */

/* 1416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */


	/* Procedure SetName */

/* 1422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1428 */	NdrFcShort( 0xa ),	/* 10 */
/* 1430 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1436 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1438 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1442 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1444 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter name */

/* 1446 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1448 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1450 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */


	/* Return value */

/* 1452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1454 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSupported */

/* 1458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1464 */	NdrFcShort( 0xb ),	/* 11 */
/* 1466 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1470 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1472 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1474 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 1482 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1484 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1490 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IncrementBytesRead */


	/* Procedure SetIsStorage */


	/* Procedure SetAutomatic */


	/* Procedure SetMediaSupported */

/* 1494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0xc ),	/* 12 */
/* 1502 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1506 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1508 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1510 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter val */


	/* Parameter flag */


	/* Parameter flag */


	/* Parameter type */

/* 1518 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1520 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1524 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1526 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetWaitTime */


	/* Procedure GetMaxChangers */

/* 1530 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1532 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1536 */	NdrFcShort( 0xd ),	/* 13 */
/* 1538 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1542 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1544 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1546 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1552 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */


	/* Parameter pNum */

/* 1554 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1556 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1562 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsOccupied */


	/* Procedure SetWaitTime */


	/* Procedure SetCanRotate */


	/* Procedure SetMaxChangers */

/* 1566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1572 */	NdrFcShort( 0xe ),	/* 14 */
/* 1574 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1580 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1582 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */


	/* Parameter time */


	/* Parameter flag */


	/* Parameter num */

/* 1590 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxDrives */

/* 1602 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1608 */	NdrFcShort( 0xf ),	/* 15 */
/* 1610 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1616 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1618 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1624 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 1626 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1628 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1632 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1634 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxDrives */

/* 1638 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1640 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1644 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1646 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1652 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1654 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1660 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */

/* 1662 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1664 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1668 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1670 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxPorts */

/* 1674 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1680 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1682 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1686 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1688 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1690 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1696 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 1698 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1700 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1704 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1706 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxPorts */

/* 1710 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1712 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1716 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1718 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1720 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1724 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1726 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1732 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */

/* 1734 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1736 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1740 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1742 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxSlots */

/* 1746 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1754 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1758 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1760 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1762 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 1770 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1772 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1778 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxSlots */

/* 1782 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1790 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1796 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1798 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */

/* 1806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1808 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1814 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNumUsedSlots */

/* 1818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1826 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1832 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1834 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 1842 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1850 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFindBy */


	/* Procedure GetStatus */


	/* Procedure GetUnloadPauseTime */


	/* Procedure GetNumStagingSlots */

/* 1854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1868 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1870 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFindBy */


	/* Parameter pStatus */


	/* Parameter pTime */


	/* Parameter pNum */

/* 1878 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1880 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1884 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFindBy */


	/* Procedure SetIsMediaCopySupported */


	/* Procedure SetStatus */


	/* Procedure SetUnloadPauseTime */


	/* Procedure SetNumStagingSlots */

/* 1890 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1898 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1900 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1904 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1906 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter findby */


	/* Parameter flag */


	/* Parameter status */


	/* Parameter time */


	/* Parameter num */

/* 1914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNofAvailableDrives */


	/* Procedure GetType */


	/* Procedure GetDriveSelectionPolicy */


	/* Procedure GetNumScratchCarts */

/* 1926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1934 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1940 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1942 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pdwNofDrives */


	/* Parameter pType */


	/* Parameter pPolicy */


	/* Parameter pNum */

/* 1950 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1952 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1954 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1956 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1958 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetType */


	/* Procedure SetDriveSelectionPolicy */


	/* Procedure SetNumScratchCarts */

/* 1962 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1964 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1968 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1970 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1976 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1978 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1984 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */


	/* Parameter policy */


	/* Parameter num */

/* 1986 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1988 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1992 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1994 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBlockSize */


	/* Procedure GetNumUnknownCarts */

/* 1998 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2000 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2004 */	NdrFcShort( 0x1a ),	/* 26 */
/* 2006 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2010 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2012 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2014 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBlockSize */


	/* Parameter pNum */

/* 2022 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2024 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2028 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2030 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBlockSize */


	/* Procedure SetNumUnknownCarts */

/* 2034 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2036 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2040 */	NdrFcShort( 0x1b ),	/* 27 */
/* 2042 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2046 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2048 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2050 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter blockSize */


	/* Parameter num */

/* 2058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2060 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2064 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2066 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMagazineSupported */

/* 2070 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2072 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2076 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2078 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2084 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2086 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2092 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2094 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2096 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsMagazineSupported */

/* 2100 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2102 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2106 */	NdrFcShort( 0x1d ),	/* 29 */
/* 2108 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2112 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2114 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2116 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2122 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */

/* 2124 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2126 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2132 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxCleaningMounts */

/* 2136 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2142 */	NdrFcShort( 0x1e ),	/* 30 */
/* 2144 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2150 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2152 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2158 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 2160 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2162 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2168 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxCleaningMounts */

/* 2172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2178 */	NdrFcShort( 0x1f ),	/* 31 */
/* 2180 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2182 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2186 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2188 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */

/* 2196 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2198 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2204 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSlotSelectionPolicy */

/* 2208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2214 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2216 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2220 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2222 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2224 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2230 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 2232 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2240 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSlotSelectionPolicy */

/* 2244 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x21 ),	/* 33 */
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

	/* Parameter num */

/* 2268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2270 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2276 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetChangers */

/* 2280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2286 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2288 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2294 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2296 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2304 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2306 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2308 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2312 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDriveClasses */

/* 2316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2322 */	NdrFcShort( 0x23 ),	/* 35 */
/* 2324 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2330 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2332 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2338 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2340 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2342 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2344 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2346 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2348 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDrives */

/* 2352 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2354 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2358 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2360 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2366 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2368 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2374 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2376 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2378 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2380 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2382 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2384 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2386 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStorageSlots */

/* 2388 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2390 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2394 */	NdrFcShort( 0x25 ),	/* 37 */
/* 2396 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2400 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2402 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2404 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2410 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2412 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2414 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2416 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2420 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStagingSlots */

/* 2424 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2430 */	NdrFcShort( 0x26 ),	/* 38 */
/* 2432 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2438 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2440 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2446 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2448 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2450 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2452 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2454 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2456 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPorts */

/* 2460 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2462 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2466 */	NdrFcShort( 0x27 ),	/* 39 */
/* 2468 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2472 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2474 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2476 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2482 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2484 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2486 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2488 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2490 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2492 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCleaningCartridges */

/* 2496 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2498 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2502 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2504 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2508 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2510 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2512 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2518 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2520 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2522 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2524 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2528 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetScratchCartridges */

/* 2532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2538 */	NdrFcShort( 0x29 ),	/* 41 */
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

	/* Parameter ptr */

/* 2556 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2558 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2560 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2564 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSets */

/* 2568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0x2a ),	/* 42 */
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

	/* Parameter ptr */

/* 2592 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2594 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2596 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2600 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRequestDescription */


	/* Procedure GetName */


	/* Procedure GetName */

/* 2604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2612 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2618 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2620 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2622 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2624 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDesc */


	/* Parameter pName */


	/* Parameter pName */

/* 2628 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 2630 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2632 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2634 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2636 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRequestDescription */


	/* Procedure SetName */


	/* Procedure SetName */

/* 2640 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2646 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2648 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2652 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2654 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2656 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2660 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2662 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter desc */


	/* Parameter name */


	/* Parameter name */

/* 2664 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2666 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2668 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2670 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2672 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSupported */


	/* Procedure GetMediaSupported */


	/* Procedure GetType */

/* 2676 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2678 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2682 */	NdrFcShort( 0xa ),	/* 10 */
/* 2684 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2690 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2692 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2698 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */


	/* Parameter pType */


	/* Parameter pType */

/* 2700 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2702 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2706 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2708 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaSupported */


	/* Procedure SetMediaSupported */


	/* Procedure SetIsExport */


	/* Procedure SetType */

/* 2712 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2714 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2718 */	NdrFcShort( 0xb ),	/* 11 */
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


	/* Parameter type */


	/* Parameter flag */


	/* Parameter type */

/* 2736 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2738 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 2742 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2744 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCapability */

/* 2748 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2750 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2754 */	NdrFcShort( 0xc ),	/* 12 */
/* 2756 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2760 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2762 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2764 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2770 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCapablity */

/* 2772 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2774 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2778 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2780 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Disable */


	/* Procedure SetCapability */

/* 2784 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2786 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2790 */	NdrFcShort( 0xd ),	/* 13 */
/* 2792 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2796 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2798 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2800 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2806 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter reason */


	/* Parameter capability */

/* 2808 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2810 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2814 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2816 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */


	/* Procedure GetIdleTime */

/* 2820 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2826 */	NdrFcShort( 0xe ),	/* 14 */
/* 2828 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2832 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2834 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2836 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */


	/* Parameter pTime */

/* 2844 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2846 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2848 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2850 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2852 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetState */


	/* Procedure SetIdleTime */

/* 2856 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2858 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2862 */	NdrFcShort( 0xf ),	/* 15 */
/* 2864 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2868 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2870 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2872 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2878 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter state */


	/* Parameter time */

/* 2880 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2882 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2888 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStatusCode */


	/* Procedure GetMediaSetType */


	/* Procedure GetMountWaitTime */

/* 2892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2900 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2904 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2906 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2908 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResult */


	/* Parameter pType */


	/* Parameter pTime */

/* 2916 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2918 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2922 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2924 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2926 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IncrementBytesWritten */


	/* Procedure SetStatusCode */


	/* Procedure SetMediaSetType */


	/* Procedure SetMountWaitTime */

/* 2928 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2930 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2934 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2936 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2942 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2944 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2950 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter val */


	/* Parameter result */


	/* Parameter type */


	/* Parameter time */

/* 2952 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2954 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 2958 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2960 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2962 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxCartridges */


	/* Procedure GetMountLimit */

/* 2964 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2966 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2970 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2972 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2976 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2978 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2980 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2986 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */


	/* Parameter pLim */

/* 2988 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2990 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2994 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2996 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxCartridges */


	/* Procedure SetMountLimit */

/* 3000 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3006 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3008 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3010 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3014 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3016 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */


	/* Parameter lim */

/* 3024 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3026 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3030 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3032 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOccupancy */


	/* Procedure GetQueuedRequests */

/* 3036 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3038 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3044 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3048 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3050 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3052 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */


	/* Parameter pReqs */

/* 3060 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3062 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3068 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOccupancy */


	/* Procedure SetQueuedRequests */

/* 3072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3078 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3080 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3086 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3088 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3094 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */


	/* Parameter reqs */

/* 3096 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3098 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDrives */

/* 3108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3114 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3116 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3122 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3124 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 3132 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3136 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 3138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCartridgeId */

/* 3144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3150 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3152 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3154 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3158 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3160 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 3168 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3172 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 3174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3176 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCartridgeId */

/* 3180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3186 */	NdrFcShort( 0xa ),	/* 10 */
/* 3188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3192 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3194 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3196 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCartId */

/* 3204 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3206 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3208 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 3210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPassword */


	/* Procedure GetName */

/* 3216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3222 */	NdrFcShort( 0xb ),	/* 11 */
/* 3224 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3230 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3232 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3234 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3236 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 3240 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3244 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */


	/* Return value */

/* 3246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPassword */


	/* Procedure SetName */

/* 3252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3258 */	NdrFcShort( 0xc ),	/* 12 */
/* 3260 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3266 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3268 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3272 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter name */

/* 3276 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3280 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */


	/* Return value */

/* 3282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDescription */

/* 3288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3294 */	NdrFcShort( 0xd ),	/* 13 */
/* 3296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3302 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3304 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3306 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3308 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDescription */

/* 3312 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3316 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 3318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDescription */

/* 3324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3330 */	NdrFcShort( 0xe ),	/* 14 */
/* 3332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3338 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3340 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3344 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3348 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3352 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 3354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3356 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTagAndNumber */

/* 3360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3366 */	NdrFcShort( 0xf ),	/* 15 */
/* 3368 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3372 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3374 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3376 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3378 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3380 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTag */

/* 3384 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3388 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter pNumber */

/* 3390 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3392 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3398 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTagAndNumber */

/* 3402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3408 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3410 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3416 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3418 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3422 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter tag */

/* 3426 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3428 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3430 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter number */

/* 3432 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3434 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3440 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBarcode */

/* 3444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3450 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3458 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3460 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3462 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3464 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBarcode */

/* 3468 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3472 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 3474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOnMediaIdentifier */

/* 3480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3486 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3488 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3490 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3492 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3494 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3496 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3498 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3500 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIdentifier */

/* 3504 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3508 */	NdrFcShort( 0xf2 ),	/* Type Offset=242 */

	/* Parameter pSize */

/* 3510 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pType */

/* 3516 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3518 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3524 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOnMediaIdentifier */

/* 3528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3534 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3536 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3538 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3540 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3542 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3544 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3548 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIdentifier */

/* 3552 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3554 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3556 */	NdrFcShort( 0x106 ),	/* Type Offset=262 */

	/* Parameter size */

/* 3558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3560 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter type */

/* 3564 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3566 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3572 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDescription */


	/* Procedure GetOnMediaLabel */

/* 3576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3582 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3584 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3590 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3592 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3594 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3596 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDesc */


	/* Parameter pLabel */

/* 3600 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3602 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3604 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */


	/* Return value */

/* 3606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3608 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDescription */


	/* Procedure SetOnMediaLabel */

/* 3612 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3618 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3620 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3626 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3628 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3632 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter desc */


	/* Parameter label */

/* 3636 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3638 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3640 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */


	/* Return value */

/* 3642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3644 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsTwoSided */

/* 3648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3654 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3656 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3660 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3662 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3664 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3670 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */

/* 3672 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3674 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3678 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3680 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsTwoSided */

/* 3684 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3686 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3690 */	NdrFcShort( 0x1d ),	/* 29 */
/* 3692 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3696 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3698 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3700 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3706 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3710 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsMounted */

/* 3714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3720 */	NdrFcShort( 0x1e ),	/* 30 */
/* 3722 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3724 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3728 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3730 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3736 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */

/* 3738 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3740 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3744 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3746 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMounted */

/* 3750 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3752 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3756 */	NdrFcShort( 0x1f ),	/* 31 */
/* 3758 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3764 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3766 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3776 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsAvailable */

/* 3780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3786 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3788 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3794 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3796 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */

/* 3804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3806 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3812 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsAvailable */

/* 3816 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3822 */	NdrFcShort( 0x21 ),	/* 33 */
/* 3824 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3830 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3832 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3838 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3842 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHome */

/* 3846 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3852 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3854 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3858 */	NdrFcShort( 0x138 ),	/* 312 */
/* 3860 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 3862 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3868 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 3870 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3872 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pLibId */

/* 3876 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3878 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3880 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pMediaSetId */

/* 3882 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3884 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3886 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pPos */

/* 3888 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3890 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pAlt1 */

/* 3894 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3896 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pAlt2 */

/* 3900 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3902 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pAlt3 */

/* 3906 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3908 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInvert */

/* 3912 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3914 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3920 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHome */

/* 3924 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x23 ),	/* 35 */
/* 3932 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 3934 */	NdrFcShort( 0x90 ),	/* 144 */
/* 3936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3938 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 3940 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3946 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 3948 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3950 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter libId */

/* 3954 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3956 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3958 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter mediaSetId */

/* 3960 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3962 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3964 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pos */

/* 3966 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3968 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt1 */

/* 3972 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3974 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 3976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt2 */

/* 3978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3980 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 3982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt3 */

/* 3984 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3986 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 3988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter invert */

/* 3990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3992 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3998 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 4000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLocation */

/* 4002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4008 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4010 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4012 */	NdrFcShort( 0x130 ),	/* 304 */
/* 4014 */	NdrFcShort( 0x138 ),	/* 312 */
/* 4016 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 4018 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 4026 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4028 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4030 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pLibId */

/* 4032 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4036 */	NdrFcShort( 0x116 ),	/* Type Offset=278 */

	/* Parameter pMediaSetId */

/* 4038 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4040 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4042 */	NdrFcShort( 0x116 ),	/* Type Offset=278 */

	/* Parameter pPos */

/* 4044 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4046 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4048 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt1 */

/* 4050 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4052 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4054 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt2 */

/* 4056 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4058 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4060 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt3 */

/* 4062 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4064 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4066 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pInvert */

/* 4068 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4070 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4072 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Return value */

/* 4074 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4076 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 4078 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLocation */

/* 4080 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4082 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4086 */	NdrFcShort( 0x25 ),	/* 37 */
/* 4088 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 4090 */	NdrFcShort( 0x90 ),	/* 144 */
/* 4092 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4094 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 4096 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4102 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 4104 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4106 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter libId */

/* 4110 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4112 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4114 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter mediaSetId */

/* 4116 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4118 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4120 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pos */

/* 4122 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4124 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt1 */

/* 4128 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4130 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 4132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt2 */

/* 4134 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4136 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 4138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt3 */

/* 4140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4142 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 4144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter invert */

/* 4146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4148 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 4150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4154 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 4156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDrive */

/* 4158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4164 */	NdrFcShort( 0x26 ),	/* 38 */
/* 4166 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4172 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4174 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 4182 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4184 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4186 */	NdrFcShort( 0x11a ),	/* Type Offset=282 */

	/* Return value */

/* 4188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4190 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDrive */

/* 4194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4200 */	NdrFcShort( 0x27 ),	/* 39 */
/* 4202 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4208 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4210 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 4218 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4220 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4222 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 4224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4226 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMailStop */

/* 4230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4236 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4238 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4244 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4246 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4248 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4250 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMailStop */

/* 4254 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 4256 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4258 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 4260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4262 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMailStop */

/* 4266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4272 */	NdrFcShort( 0x29 ),	/* 41 */
/* 4274 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4280 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4282 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4286 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mailStop */

/* 4290 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4292 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4294 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 4296 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4298 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetInfo */

/* 4302 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4308 */	NdrFcShort( 0x2a ),	/* 42 */
/* 4310 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4314 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4316 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 4318 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4320 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4324 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 4326 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 4328 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4330 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 4332 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4334 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4336 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4340 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetInfo */

/* 4344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4350 */	NdrFcShort( 0x2b ),	/* 43 */
/* 4352 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4354 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4358 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4360 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4364 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 4368 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4372 */	NdrFcShort( 0x136 ),	/* Type Offset=310 */

	/* Parameter size */

/* 4374 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4376 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4378 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4382 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOwnerClassId */

/* 4386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4392 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4394 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4398 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4400 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4402 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 4410 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4414 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOwnerClassId */

/* 4422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4428 */	NdrFcShort( 0x2d ),	/* 45 */
/* 4430 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4432 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4436 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4438 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4444 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 4446 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4448 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4450 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4454 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPartitions */

/* 4458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4464 */	NdrFcShort( 0x2e ),	/* 46 */
/* 4466 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4470 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4472 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4474 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 4482 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4484 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4486 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 4488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4490 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVerifierClass */

/* 4494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4500 */	NdrFcShort( 0x2f ),	/* 47 */
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

	/* Parameter pClassId */

/* 4518 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4520 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4522 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4524 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4526 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetVerifierClass */

/* 4530 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4532 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4536 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4538 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4540 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4542 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4544 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4546 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4552 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 4554 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4556 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4558 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4562 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPortalClass */

/* 4566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4572 */	NdrFcShort( 0x31 ),	/* 49 */
/* 4574 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4578 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4580 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4582 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 4590 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4594 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPortalClass */

/* 4602 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4608 */	NdrFcShort( 0x32 ),	/* 50 */
/* 4610 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4612 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4616 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4618 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4624 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 4626 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4628 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4630 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4632 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4634 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Mount */

/* 4638 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4640 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4644 */	NdrFcShort( 0x33 ),	/* 51 */
/* 4646 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4648 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4652 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 4654 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4660 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppDrive */

/* 4662 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4664 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4666 */	NdrFcShort( 0x11a ),	/* Type Offset=282 */

	/* Parameter options */

/* 4668 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4670 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 4674 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4676 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4682 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Dismount */

/* 4686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4692 */	NdrFcShort( 0x34 ),	/* 52 */
/* 4694 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4696 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4700 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4702 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4708 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter options */

/* 4710 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4712 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4716 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4718 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Home */

/* 4722 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4728 */	NdrFcShort( 0x35 ),	/* 53 */
/* 4730 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4736 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4738 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4744 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter options */

/* 4746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4748 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4754 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateDataMover */

/* 4758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4764 */	NdrFcShort( 0x36 ),	/* 54 */
/* 4766 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4772 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4774 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4780 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 4782 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4784 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4786 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 4788 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4790 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReleaseDataMover */

/* 4794 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4796 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4800 */	NdrFcShort( 0x37 ),	/* 55 */
/* 4802 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4806 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4808 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4810 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4816 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 4818 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4820 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4822 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Return value */

/* 4824 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4826 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadDataCache */

/* 4830 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4832 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4836 */	NdrFcShort( 0x38 ),	/* 56 */
/* 4838 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4840 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4842 */	NdrFcShort( 0x6c ),	/* 108 */
/* 4844 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 4846 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4848 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4852 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCache */

/* 4854 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 4856 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4858 */	NdrFcShort( 0x146 ),	/* Type Offset=326 */

	/* Parameter pSize */

/* 4860 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 4862 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUsed */

/* 4866 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4868 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pStartPBA */

/* 4872 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 4874 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4876 */	NdrFcShort( 0x156 ),	/* Type Offset=342 */

	/* Return value */

/* 4878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4880 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveDataCache */

/* 4884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4890 */	NdrFcShort( 0x39 ),	/* 57 */
/* 4892 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4894 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4898 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4900 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4904 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4906 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCache */

/* 4908 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4910 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4912 */	NdrFcShort( 0x160 ),	/* Type Offset=352 */

	/* Parameter size */

/* 4914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter used */

/* 4920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4922 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter startPBA */

/* 4926 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4928 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4930 */	NdrFcShort( 0x156 ),	/* Type Offset=342 */

	/* Return value */

/* 4932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4934 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManagedBy */

/* 4938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4944 */	NdrFcShort( 0x3a ),	/* 58 */
/* 4946 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4950 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4952 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4954 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pManagedBy */

/* 4962 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4964 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4968 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4970 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetManagedBy */

/* 4974 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4976 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4980 */	NdrFcShort( 0x3b ),	/* 59 */
/* 4982 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4984 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4986 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4988 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4990 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4996 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter managedBy */

/* 4998 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5000 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5006 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsFixedBlockSize */

/* 5010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5016 */	NdrFcShort( 0x3c ),	/* 60 */
/* 5018 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5024 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5026 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5032 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5036 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetElementNo */


	/* Procedure GetPartNo */


	/* Procedure GetRequestNo */


	/* Procedure GetMountReference */

/* 5040 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5046 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5048 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5052 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5054 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5056 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5062 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pElementNo */


	/* Parameter pPartNo */


	/* Parameter pRequestNo */


	/* Parameter pRefs */

/* 5064 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5066 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5072 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */


	/* Procedure AcquireDevice */


	/* Procedure IsInMagazine */


	/* Procedure ResetMountReference */

/* 5076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5084 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5090 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5092 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceType */


	/* Procedure SetObjectType */


	/* Procedure SetIsDone */


	/* Procedure ReleaseMountReference */

/* 5106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5112 */	NdrFcShort( 0xa ),	/* 10 */
/* 5114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5120 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5122 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5128 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */


	/* Parameter type */


	/* Parameter flag */


	/* Parameter options */

/* 5130 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5132 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5136 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5138 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateDataMover */

/* 5142 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5148 */	NdrFcShort( 0xc ),	/* 12 */
/* 5150 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5154 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5156 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5158 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5164 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 5166 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5168 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5170 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 5172 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5174 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReleaseDataMover */

/* 5178 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5180 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5184 */	NdrFcShort( 0xd ),	/* 13 */
/* 5186 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5192 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5194 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5200 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 5202 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5204 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5206 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Return value */

/* 5208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5210 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Eject */

/* 5214 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5220 */	NdrFcShort( 0xe ),	/* 14 */
/* 5222 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5226 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5228 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5230 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5236 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5240 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLargestFreeSpace */

/* 5244 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5250 */	NdrFcShort( 0xf ),	/* 15 */
/* 5252 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5256 */	NdrFcShort( 0x50 ),	/* 80 */
/* 5258 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5260 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5266 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter freeSpace */

/* 5268 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5270 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5272 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter capacity */

/* 5274 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5276 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5278 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5282 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnloadNow */

/* 5286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5292 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5294 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5300 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5302 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5312 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsInMagazine */

/* 5316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5322 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5324 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5330 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5332 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5338 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */

/* 5340 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5342 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5346 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5348 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMagazineAndCell */

/* 5352 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5354 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5358 */	NdrFcShort( 0x9 ),	/* 9 */
/* 5360 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5364 */	NdrFcShort( 0x40 ),	/* 64 */
/* 5366 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5368 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5374 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMag */

/* 5376 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5378 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCell */

/* 5382 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5384 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5386 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5388 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5390 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBytesRead2 */


	/* Procedure SetMagazineAndCell */

/* 5394 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5396 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5400 */	NdrFcShort( 0xa ),	/* 10 */
/* 5402 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5404 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5406 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5408 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5410 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter readHi */


	/* Parameter mag */

/* 5418 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5420 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter readLo */


	/* Parameter cell */

/* 5424 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5426 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5432 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHome */

/* 5436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5442 */	NdrFcShort( 0xa ),	/* 10 */
/* 5444 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5448 */	NdrFcShort( 0x5c ),	/* 92 */
/* 5450 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 5452 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 5460 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5462 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPos */

/* 5466 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5468 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInvert */

/* 5472 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5474 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5480 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHome */

/* 5484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5490 */	NdrFcShort( 0xb ),	/* 11 */
/* 5492 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5494 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5498 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 5500 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 5508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5510 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pos */

/* 5514 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5516 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter invert */

/* 5520 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5522 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5528 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsOccupied */


	/* Procedure CanRotate */

/* 5532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5538 */	NdrFcShort( 0xf ),	/* 15 */
/* 5540 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5546 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5548 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 5556 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5558 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOperation */

/* 5562 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5564 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5568 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5570 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5574 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5576 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5578 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 5580 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5582 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5584 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOperation */

/* 5586 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 5588 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5590 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 5592 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5594 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOperation */

/* 5598 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5604 */	NdrFcShort( 0x11 ),	/* 17 */
/* 5606 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5612 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5614 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5618 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5620 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOperation */

/* 5622 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5624 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5626 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 5628 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5630 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPercentComplete */

/* 5634 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5636 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5640 */	NdrFcShort( 0x12 ),	/* 18 */
/* 5642 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5646 */	NdrFcShort( 0x21 ),	/* 33 */
/* 5648 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5650 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5656 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPercent */

/* 5658 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5660 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5662 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 5664 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5666 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPercentComplete */

/* 5670 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5672 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5676 */	NdrFcShort( 0x13 ),	/* 19 */
/* 5678 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5680 */	NdrFcShort( 0x5 ),	/* 5 */
/* 5682 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5684 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5686 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5692 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter percent */

/* 5694 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5696 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5698 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 5700 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5702 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Suspend */


	/* Procedure TestReady */

/* 5706 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5708 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5712 */	NdrFcShort( 0x14 ),	/* 20 */
/* 5714 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5718 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5720 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5722 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5728 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 5730 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5732 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ImportCartridge */

/* 5736 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5742 */	NdrFcShort( 0x15 ),	/* 21 */
/* 5744 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5750 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5752 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5758 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 5760 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 5762 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5764 */	NdrFcShort( 0x170 ),	/* Type Offset=368 */

	/* Return value */

/* 5766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5768 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportCartridge */

/* 5772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5778 */	NdrFcShort( 0x16 ),	/* 22 */
/* 5780 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5784 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5786 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5788 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5794 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 5796 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 5798 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5800 */	NdrFcShort( 0x170 ),	/* Type Offset=368 */

	/* Return value */

/* 5802 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5804 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MoveCartridge */

/* 5808 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5810 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5814 */	NdrFcShort( 0x17 ),	/* 23 */
/* 5816 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5822 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5824 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSrcCart */

/* 5832 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5834 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5836 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter pDestElmt */

/* 5838 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5840 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5842 */	NdrFcShort( 0x174 ),	/* Type Offset=372 */

	/* Return value */

/* 5844 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5846 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5848 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HomeCartridge */

/* 5850 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5852 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5856 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5858 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5864 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5866 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 5874 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5876 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5878 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 5880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5882 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetParameters */

/* 5886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5892 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5894 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5896 */	NdrFcShort( 0x1c ),	/* 28 */
/* 5898 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5900 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 5902 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 5904 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5908 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 5910 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5912 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5914 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pParms */

/* 5916 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 5918 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5920 */	NdrFcShort( 0x1be ),	/* Type Offset=446 */

	/* Return value */

/* 5922 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5924 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5926 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetProductData */

/* 5928 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5930 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5934 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5936 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5938 */	NdrFcShort( 0x1c ),	/* 28 */
/* 5940 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5942 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 5944 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 5946 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5950 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 5952 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5954 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pData */

/* 5958 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 5960 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5962 */	NdrFcShort( 0x1fa ),	/* Type Offset=506 */

	/* Return value */

/* 5964 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5966 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5968 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RezeroUnit */

/* 5970 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5972 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5976 */	NdrFcShort( 0x5 ),	/* 5 */
/* 5978 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5982 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5984 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5986 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5992 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5994 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5996 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeElementStatus */

/* 6000 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6006 */	NdrFcShort( 0x6 ),	/* 6 */
/* 6008 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6010 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6014 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6016 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter elementList */

/* 6024 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6026 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6028 */	NdrFcShort( 0x216 ),	/* Type Offset=534 */

	/* Parameter barCodeScan */

/* 6030 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6032 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6036 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6038 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAccess */

/* 6042 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6044 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6050 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6052 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6054 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6056 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6058 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6064 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 6066 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6068 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6070 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter control */

/* 6072 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6074 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6078 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6080 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetElementStatus */

/* 6084 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6086 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6090 */	NdrFcShort( 0x9 ),	/* 9 */
/* 6092 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6094 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6096 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6098 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 6100 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 6102 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter elementList */

/* 6108 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6112 */	NdrFcShort( 0x216 ),	/* Type Offset=534 */

	/* Parameter volumeTagInfo */

/* 6114 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSize */

/* 6120 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 6122 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pElementInformation */

/* 6126 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 6128 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6130 */	NdrFcShort( 0x270 ),	/* Type Offset=624 */

	/* Return value */

/* 6132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6134 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 6136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExchangeMedium */

/* 6138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6144 */	NdrFcShort( 0xa ),	/* 10 */
/* 6146 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6148 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6152 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 6154 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter source */

/* 6162 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6166 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter destination1 */

/* 6168 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6170 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6172 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter destination2 */

/* 6174 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6176 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6178 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter flip1 */

/* 6180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6182 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 6184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter flip2 */

/* 6186 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6188 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6194 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 6196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MoveMedium */

/* 6198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6204 */	NdrFcShort( 0xb ),	/* 11 */
/* 6206 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 6208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6212 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 6214 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter source */

/* 6222 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6224 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6226 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter destination */

/* 6228 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6230 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6232 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter flip */

/* 6234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6236 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6242 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Position */

/* 6246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6252 */	NdrFcShort( 0xc ),	/* 12 */
/* 6254 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6256 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6260 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6262 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6268 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter destination */

/* 6270 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6272 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6274 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter flip */

/* 6276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6278 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6284 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryVolumeTag */

/* 6288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6294 */	NdrFcShort( 0xd ),	/* 13 */
/* 6296 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6298 */	NdrFcShort( 0x3d ),	/* 61 */
/* 6300 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6302 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 6304 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 6306 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter startingElement */

/* 6312 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6316 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter actionCode */

/* 6318 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6320 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVolumeIDTemplate */

/* 6324 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6326 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6328 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pNumberOfElementsReturned */

/* 6330 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 6332 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pElementInformation */

/* 6336 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 6338 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6340 */	NdrFcShort( 0x270 ),	/* Type Offset=624 */

	/* Return value */

/* 6342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6344 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 6346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceName */


	/* Procedure GetDescription */

/* 6348 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6354 */	NdrFcShort( 0x7 ),	/* 7 */
/* 6356 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6360 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6362 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6364 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 6366 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6368 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pDesc */

/* 6372 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 6374 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6376 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */


	/* Return value */

/* 6378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6380 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceName */


	/* Procedure SetDescription */

/* 6384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6392 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6396 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6398 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6400 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6404 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6406 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter desc */

/* 6408 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6410 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6412 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */


	/* Return value */

/* 6414 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6416 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAttributes */


	/* Procedure SetIsImport */

/* 6420 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6426 */	NdrFcShort( 0x9 ),	/* 9 */
/* 6428 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6434 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6436 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6442 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter attr */


	/* Parameter flag */

/* 6444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6446 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 6450 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6452 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsImport */

/* 6456 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6462 */	NdrFcShort( 0xa ),	/* 10 */
/* 6464 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6468 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6470 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6472 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6482 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetInfo */

/* 6486 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6492 */	NdrFcShort( 0xc ),	/* 12 */
/* 6494 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6498 */	NdrFcShort( 0x22 ),	/* 34 */
/* 6500 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 6502 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 6504 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6508 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 6510 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 6512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6514 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 6516 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6520 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetInfo */

/* 6528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6534 */	NdrFcShort( 0xd ),	/* 13 */
/* 6536 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6538 */	NdrFcShort( 0x6 ),	/* 6 */
/* 6540 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6542 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6544 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6548 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 6552 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6554 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6556 */	NdrFcShort( 0x136 ),	/* Type Offset=310 */

	/* Parameter size */

/* 6558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6560 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6562 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6564 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6566 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOwnerClassId */

/* 6570 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6572 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6576 */	NdrFcShort( 0xe ),	/* 14 */
/* 6578 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6582 */	NdrFcShort( 0x4c ),	/* 76 */
/* 6584 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6586 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6592 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 6594 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 6596 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6598 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 6600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6602 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOwnerClassId */

/* 6606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6612 */	NdrFcShort( 0xf ),	/* 15 */
/* 6614 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6616 */	NdrFcShort( 0x30 ),	/* 48 */
/* 6618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6620 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6622 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 6630 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 6632 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6634 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 6636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6638 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMediaCopySupported */

/* 6642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6648 */	NdrFcShort( 0x16 ),	/* 22 */
/* 6650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6656 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6658 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Allocate */

/* 6672 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6678 */	NdrFcShort( 0x18 ),	/* 24 */
/* 6680 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 6682 */	NdrFcShort( 0x70 ),	/* 112 */
/* 6684 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6686 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 6688 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6692 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6694 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prevSideId */

/* 6696 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 6698 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6700 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pFreeSpace */

/* 6702 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 6704 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6706 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter displayName */

/* 6708 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6710 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6712 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter options */

/* 6714 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6716 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCart */

/* 6720 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6722 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6724 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 6726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6728 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Deallocate */

/* 6732 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6734 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6738 */	NdrFcShort( 0x19 ),	/* 25 */
/* 6740 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6744 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6746 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6748 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 6756 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6758 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6760 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 6762 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOperation */

/* 6768 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6770 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6774 */	NdrFcShort( 0xc ),	/* 12 */
/* 6776 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6782 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6784 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 6786 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6788 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6790 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOperation */

/* 6792 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 6794 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6796 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 6798 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6800 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOperation */

/* 6804 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6806 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6810 */	NdrFcShort( 0xd ),	/* 13 */
/* 6812 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6816 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6818 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6820 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6824 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter operation */

/* 6828 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6830 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6832 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 6834 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6836 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPercentComplete */

/* 6840 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6846 */	NdrFcShort( 0xe ),	/* 14 */
/* 6848 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6852 */	NdrFcShort( 0x21 ),	/* 33 */
/* 6854 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6856 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPercent */

/* 6864 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6866 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6868 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 6870 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6872 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPercentComplete */

/* 6876 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6878 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6882 */	NdrFcShort( 0xf ),	/* 15 */
/* 6884 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6886 */	NdrFcShort( 0x5 ),	/* 5 */
/* 6888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6890 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6892 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter percent */

/* 6900 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6902 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6904 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 6906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAttributes */

/* 6912 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6920 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6924 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6926 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6928 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAttr */

/* 6936 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6938 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6944 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 6948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6954 */	NdrFcShort( 0xa ),	/* 10 */
/* 6956 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6960 */	NdrFcShort( 0x22 ),	/* 34 */
/* 6962 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 6964 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 6966 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIdent */

/* 6972 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 6974 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6976 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 6978 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6982 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6986 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIdentifier */

/* 6990 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6996 */	NdrFcShort( 0xb ),	/* 11 */
/* 6998 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7000 */	NdrFcShort( 0x6 ),	/* 6 */
/* 7002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7004 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 7006 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7010 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIdent */

/* 7014 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7016 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7018 */	NdrFcShort( 0x136 ),	/* Type Offset=310 */

	/* Parameter size */

/* 7020 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7022 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7024 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 7026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7028 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadOnMediaId */

/* 7032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7038 */	NdrFcShort( 0xd ),	/* 13 */
/* 7040 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7044 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7046 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 7048 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 7050 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 7056 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 7058 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7060 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 7062 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7064 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7070 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceType */


	/* Procedure GetObjectType */

/* 7074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7080 */	NdrFcShort( 0x9 ),	/* 9 */
/* 7082 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7086 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7088 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7090 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */


	/* Parameter pType */

/* 7098 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7100 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 7104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7106 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 7110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7116 */	NdrFcShort( 0x12 ),	/* 18 */
/* 7118 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7124 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7126 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 7128 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7130 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 7134 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 7136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7138 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 7140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 7146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7152 */	NdrFcShort( 0x13 ),	/* 19 */
/* 7154 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7160 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7162 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7166 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7170 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7172 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7174 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 7176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLocation */

/* 7182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7190 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 7192 */	NdrFcShort( 0x130 ),	/* 304 */
/* 7194 */	NdrFcShort( 0x138 ),	/* 312 */
/* 7196 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 7198 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7204 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 7206 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7208 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7210 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pLibId */

/* 7212 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7214 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7216 */	NdrFcShort( 0x116 ),	/* Type Offset=278 */

	/* Parameter pMediaSetId */

/* 7218 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7220 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7222 */	NdrFcShort( 0x116 ),	/* Type Offset=278 */

	/* Parameter pPos */

/* 7224 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7226 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7228 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt1 */

/* 7230 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7232 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7234 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt2 */

/* 7236 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7238 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7240 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt3 */

/* 7242 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7244 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 7246 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pInvert */

/* 7248 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7250 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 7252 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Return value */

/* 7254 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7256 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 7258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLocation */

/* 7260 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7266 */	NdrFcShort( 0x9 ),	/* 9 */
/* 7268 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 7270 */	NdrFcShort( 0x90 ),	/* 144 */
/* 7272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7274 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 7276 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7282 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 7284 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7286 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter libId */

/* 7290 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 7292 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7294 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter mediaSetId */

/* 7296 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 7298 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7300 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pos */

/* 7302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7304 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 7306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt1 */

/* 7308 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7310 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 7312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt2 */

/* 7314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7316 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 7318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt3 */

/* 7320 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7322 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 7324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter invert */

/* 7326 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7328 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 7330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7332 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7334 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 7336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCartridge */

/* 7338 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7340 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7344 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7346 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7352 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7354 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7360 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 7362 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7364 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7366 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 7368 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7370 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCartridge */

/* 7374 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7376 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7380 */	NdrFcShort( 0x11 ),	/* 17 */
/* 7382 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7386 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7388 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7390 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7396 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 7398 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7400 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7402 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 7404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7406 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOwnerClassId */

/* 7410 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7416 */	NdrFcShort( 0x12 ),	/* 18 */
/* 7418 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7422 */	NdrFcShort( 0x4c ),	/* 76 */
/* 7424 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7426 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7432 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 7434 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 7436 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7438 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 7440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7442 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOwnerClassId */

/* 7446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7452 */	NdrFcShort( 0x13 ),	/* 19 */
/* 7454 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7456 */	NdrFcShort( 0x30 ),	/* 48 */
/* 7458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7460 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7462 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7468 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 7470 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 7472 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7474 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 7476 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7478 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUsedSpace2 */


	/* Procedure GetAccessCounters */

/* 7482 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7488 */	NdrFcShort( 0x14 ),	/* 20 */
/* 7490 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7494 */	NdrFcShort( 0x40 ),	/* 64 */
/* 7496 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7498 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pUsedHi */


	/* Parameter pGets */

/* 7506 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7508 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUsedLo */


	/* Parameter pPuts */

/* 7512 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7514 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 7518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7520 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Resume */


	/* Procedure ResetAccessCounters */

/* 7524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7530 */	NdrFcShort( 0x15 ),	/* 21 */
/* 7532 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7536 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7538 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7540 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 7548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7550 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCoordinates */

/* 7554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7560 */	NdrFcShort( 0x16 ),	/* 22 */
/* 7562 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7566 */	NdrFcShort( 0x5c ),	/* 92 */
/* 7568 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 7570 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pX1 */

/* 7578 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7580 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pX2 */

/* 7584 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7586 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pX3 */

/* 7590 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7592 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7598 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCoordinates */

/* 7602 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7608 */	NdrFcShort( 0x17 ),	/* 23 */
/* 7610 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7612 */	NdrFcShort( 0x18 ),	/* 24 */
/* 7614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7616 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 7618 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7624 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x1 */

/* 7626 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7628 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter x2 */

/* 7632 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7634 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter x3 */

/* 7638 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7640 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7642 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7646 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceInfo */

/* 7650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7656 */	NdrFcShort( 0xb ),	/* 11 */
/* 7658 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7662 */	NdrFcShort( 0x22 ),	/* 34 */
/* 7664 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 7666 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 7668 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 7674 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 7676 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7678 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 7680 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7682 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7684 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 7686 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7688 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceInfo */

/* 7692 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7698 */	NdrFcShort( 0xc ),	/* 12 */
/* 7700 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7702 */	NdrFcShort( 0x6 ),	/* 6 */
/* 7704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7706 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 7708 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7712 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7714 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 7716 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7718 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7720 */	NdrFcShort( 0x136 ),	/* Type Offset=310 */

	/* Parameter size */

/* 7722 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7724 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7726 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 7728 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7730 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceAddress */

/* 7734 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7740 */	NdrFcShort( 0xd ),	/* 13 */
/* 7742 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7746 */	NdrFcShort( 0x6c ),	/* 108 */
/* 7748 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 7750 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7756 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPort */

/* 7758 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7760 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7762 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pBus */

/* 7764 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7766 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7768 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pId */

/* 7770 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7772 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7774 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pLun */

/* 7776 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7778 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7780 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 7782 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7784 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceAddress */

/* 7788 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7794 */	NdrFcShort( 0xe ),	/* 14 */
/* 7796 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7798 */	NdrFcShort( 0x14 ),	/* 20 */
/* 7800 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7802 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 7804 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7810 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter port */

/* 7812 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7814 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7816 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter bus */

/* 7818 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7820 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7822 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter id */

/* 7824 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7826 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7828 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter lun */

/* 7830 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7832 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7834 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 7836 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7838 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMountCounters */

/* 7842 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7844 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7848 */	NdrFcShort( 0x7 ),	/* 7 */
/* 7850 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7854 */	NdrFcShort( 0x40 ),	/* 64 */
/* 7856 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7858 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7864 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pReads */

/* 7866 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7868 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pWrites */

/* 7872 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7874 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7880 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBytesRead2 */

/* 7884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7892 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7896 */	NdrFcShort( 0x40 ),	/* 64 */
/* 7898 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7900 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7906 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pReadHi */

/* 7908 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7910 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pReadLo */

/* 7914 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7922 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBytesRead */

/* 7926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7932 */	NdrFcShort( 0x9 ),	/* 9 */
/* 7934 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7938 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7940 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7942 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRead */

/* 7950 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7952 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7954 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7956 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7958 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBytesRead */

/* 7962 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7964 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7968 */	NdrFcShort( 0xb ),	/* 11 */
/* 7970 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7972 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7976 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7978 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7984 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter read */

/* 7986 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7988 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7990 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7992 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7994 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBytesWritten2 */

/* 7998 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8000 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8004 */	NdrFcShort( 0xd ),	/* 13 */
/* 8006 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8010 */	NdrFcShort( 0x40 ),	/* 64 */
/* 8012 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8014 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWriteHi */

/* 8022 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8024 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pWriteLo */

/* 8028 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8030 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8036 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBytesWritten */

/* 8040 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8046 */	NdrFcShort( 0xe ),	/* 14 */
/* 8048 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8052 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8054 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8056 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8062 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWritten */

/* 8064 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8066 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8068 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8072 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBytesWritten2 */

/* 8076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8082 */	NdrFcShort( 0xf ),	/* 15 */
/* 8084 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8086 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8090 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8092 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter writeHi */

/* 8100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter writeLo */

/* 8106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBytesWritten */

/* 8118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8124 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8126 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8128 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8132 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8134 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter written */

/* 8142 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8144 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8146 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8150 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCapacity2 */

/* 8154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8160 */	NdrFcShort( 0x12 ),	/* 18 */
/* 8162 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8166 */	NdrFcShort( 0x40 ),	/* 64 */
/* 8168 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8170 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCapHi */

/* 8178 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8180 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCapLo */

/* 8184 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8186 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8192 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCapacity */

/* 8196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8202 */	NdrFcShort( 0x13 ),	/* 19 */
/* 8204 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8208 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8210 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8212 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCap */

/* 8220 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8222 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8224 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8226 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUsedSpace */

/* 8232 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8238 */	NdrFcShort( 0x15 ),	/* 21 */
/* 8240 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8244 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8246 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8248 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8254 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pUsed */

/* 8256 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8258 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8260 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8262 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8264 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLargestFreeSpace2 */

/* 8268 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8270 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8274 */	NdrFcShort( 0x16 ),	/* 22 */
/* 8276 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8280 */	NdrFcShort( 0x40 ),	/* 64 */
/* 8282 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8284 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8290 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFreeHi */

/* 8292 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8294 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pFreeLo */

/* 8298 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8300 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8306 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLargestFreeSpace */

/* 8310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8316 */	NdrFcShort( 0x17 ),	/* 23 */
/* 8318 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8322 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8324 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8326 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8332 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFree */

/* 8334 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8336 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8338 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8340 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8342 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCapacity */

/* 8346 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8348 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8352 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8354 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8356 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8358 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8360 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8362 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8368 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cap */

/* 8370 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8372 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8374 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8378 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUsedSpace */

/* 8382 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8388 */	NdrFcShort( 0x19 ),	/* 25 */
/* 8390 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8392 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8394 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8396 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8398 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8404 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter used */

/* 8406 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8408 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8410 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8414 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFreeSpace */

/* 8418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8424 */	NdrFcShort( 0x1a ),	/* 26 */
/* 8426 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8428 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8432 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8434 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter free */

/* 8442 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8444 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8446 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8450 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetCounters */

/* 8454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8460 */	NdrFcShort( 0x1b ),	/* 27 */
/* 8462 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8466 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8468 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 8470 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8476 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 8478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8480 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetInfo */

/* 8484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8490 */	NdrFcShort( 0xd ),	/* 13 */
/* 8492 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8496 */	NdrFcShort( 0x22 ),	/* 34 */
/* 8498 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 8500 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 8502 */	NdrFcShort( 0x1 ),	/* 1 */
/* 8504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 8508 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 8510 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8512 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 8514 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8516 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8518 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 8520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8522 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetInfo */

/* 8526 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8532 */	NdrFcShort( 0xe ),	/* 14 */
/* 8534 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8536 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8540 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8542 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 8544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8546 */	NdrFcShort( 0x1 ),	/* 1 */
/* 8548 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 8550 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 8552 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8554 */	NdrFcShort( 0x136 ),	/* Type Offset=310 */

	/* Parameter size */

/* 8556 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8558 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8560 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 8562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8564 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVerifierClass */

/* 8568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8574 */	NdrFcShort( 0xf ),	/* 15 */
/* 8576 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8580 */	NdrFcShort( 0x4c ),	/* 76 */
/* 8582 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8584 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 8592 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 8594 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8596 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 8598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8600 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetVerifierClass */

/* 8604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8610 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8612 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 8614 */	NdrFcShort( 0x30 ),	/* 48 */
/* 8616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8618 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8620 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 8628 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 8630 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8632 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 8634 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8636 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPortalClass */

/* 8640 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8646 */	NdrFcShort( 0x11 ),	/* 17 */
/* 8648 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8652 */	NdrFcShort( 0x4c ),	/* 76 */
/* 8654 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8656 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8662 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 8664 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 8666 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8668 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 8670 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8672 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPortalClass */

/* 8676 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8678 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8682 */	NdrFcShort( 0x12 ),	/* 18 */
/* 8684 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 8686 */	NdrFcShort( 0x30 ),	/* 48 */
/* 8688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8690 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8692 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8698 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 8700 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 8702 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8704 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 8706 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8708 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Allocate */

/* 8712 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8714 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8718 */	NdrFcShort( 0x9 ),	/* 9 */
/* 8720 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 8722 */	NdrFcShort( 0xb4 ),	/* 180 */
/* 8724 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8726 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 8728 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 8730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8732 */	NdrFcShort( 0x1 ),	/* 1 */
/* 8734 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromMediaSet */

/* 8736 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 8738 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8740 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter prevSideId */

/* 8742 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 8744 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8746 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pFreeSpace */

/* 8748 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 8750 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8752 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter displayName */

/* 8754 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 8756 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8758 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter options */

/* 8760 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8762 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8764 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCart */

/* 8766 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8768 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 8770 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 8772 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8774 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 8776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Mount */

/* 8778 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8784 */	NdrFcShort( 0xa ),	/* 10 */
/* 8786 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 8788 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8792 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 8794 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8800 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 8802 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 8804 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8806 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter ppDrive */

/* 8808 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 8810 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8812 */	NdrFcShort( 0x94 ),	/* Type Offset=148 */

	/* Parameter options */

/* 8814 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8816 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 8820 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8822 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8826 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8828 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Dismount */

/* 8832 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8834 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8838 */	NdrFcShort( 0xb ),	/* 11 */
/* 8840 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8842 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8846 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8848 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8854 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 8856 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 8858 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8860 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter options */

/* 8862 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8864 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8868 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8870 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Deallocate */

/* 8874 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8876 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8880 */	NdrFcShort( 0xc ),	/* 12 */
/* 8882 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8886 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8888 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 8890 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8896 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 8898 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 8900 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8902 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 8904 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8906 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DismountAll */

/* 8910 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8912 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8916 */	NdrFcShort( 0xd ),	/* 13 */
/* 8918 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8920 */	NdrFcShort( 0x4c ),	/* 76 */
/* 8922 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8924 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8926 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8932 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromMediaSet */

/* 8934 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 8936 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8938 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter options */

/* 8940 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8942 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8946 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8948 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisableAndEject */

/* 8952 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8954 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8958 */	NdrFcShort( 0xe ),	/* 14 */
/* 8960 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8966 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8968 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8974 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 8976 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 8978 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8980 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter options */

/* 8982 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8984 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8988 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8990 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateOmidInfo */

/* 8994 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8996 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9000 */	NdrFcShort( 0xf ),	/* 15 */
/* 9002 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 9004 */	NdrFcShort( 0x54 ),	/* 84 */
/* 9006 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9008 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 9010 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 9012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9014 */	NdrFcShort( 0x1 ),	/* 1 */
/* 9016 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 9018 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9020 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9022 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pBuffer */

/* 9024 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 9026 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9028 */	NdrFcShort( 0x28e ),	/* Type Offset=654 */

	/* Parameter size */

/* 9030 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9032 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter type */

/* 9036 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9038 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9042 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9044 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBlockSize */

/* 9048 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9050 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9054 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9056 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9058 */	NdrFcShort( 0x44 ),	/* 68 */
/* 9060 */	NdrFcShort( 0x24 ),	/* 36 */
/* 9062 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 9064 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9070 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 9072 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9074 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9076 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pBlockSize */

/* 9078 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9080 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9084 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9086 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9088 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBlockSize */

/* 9090 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9092 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9096 */	NdrFcShort( 0x11 ),	/* 17 */
/* 9098 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9100 */	NdrFcShort( 0x4c ),	/* 76 */
/* 9102 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9104 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 9106 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 9114 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9116 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9118 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter blockSize */

/* 9120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9122 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9128 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportDatabase */

/* 9132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9138 */	NdrFcShort( 0x12 ),	/* 18 */
/* 9140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9146 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 9148 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 9156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCartridge */

/* 9162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9168 */	NdrFcShort( 0x13 ),	/* 19 */
/* 9170 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9172 */	NdrFcShort( 0x44 ),	/* 68 */
/* 9174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9176 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 9178 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 9186 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9190 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter ppCartridge */

/* 9192 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9194 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9196 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 9198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMediaCopySupported */

/* 9204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9210 */	NdrFcShort( 0x16 ),	/* 22 */
/* 9212 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9214 */	NdrFcShort( 0x44 ),	/* 68 */
/* 9216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9218 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9220 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaPoolId */

/* 9228 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9230 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9232 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 9234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9236 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateDrive */

/* 9240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9246 */	NdrFcShort( 0x17 ),	/* 23 */
/* 9248 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9254 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9256 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDrive */

/* 9264 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9268 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 9270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9272 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckSecondSide */

/* 9276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9282 */	NdrFcShort( 0x19 ),	/* 25 */
/* 9284 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9286 */	NdrFcShort( 0x44 ),	/* 68 */
/* 9288 */	NdrFcShort( 0x68 ),	/* 104 */
/* 9290 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 9292 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter firstSideId */

/* 9300 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9304 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pbValid */

/* 9306 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSecondSideId */

/* 9312 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 9314 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9316 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 9318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9320 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxMediaCapacity */

/* 9324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9330 */	NdrFcShort( 0x1a ),	/* 26 */
/* 9332 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9334 */	NdrFcShort( 0x44 ),	/* 68 */
/* 9336 */	NdrFcShort( 0x2c ),	/* 44 */
/* 9338 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 9340 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromMediaSet */

/* 9348 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9352 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pMaxCapacity */

/* 9354 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9356 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9358 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9362 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessObjectStatusChange */

/* 9366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9372 */	NdrFcShort( 0x3 ),	/* 3 */
/* 9374 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9376 */	NdrFcShort( 0x18 ),	/* 24 */
/* 9378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9380 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 9382 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isEnabled */

/* 9390 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9392 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter state */

/* 9396 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9398 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter statusCode */

/* 9402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9404 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9410 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9412 */	0x8,		/* FC_LONG */
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
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  8 */	NdrFcLong( 0x70674820 ),	/* 1885816864 */
/* 12 */	NdrFcShort( 0x67df ),	/* 26591 */
/* 14 */	NdrFcShort( 0x4c2f ),	/* 19503 */
/* 16 */	0x9d,		/* 157 */
			0xf4,		/* 244 */
/* 18 */	0x1a,		/* 26 */
			0xf0,		/* 240 */
/* 20 */	0xad,		/* 173 */
			0x42,		/* 66 */
/* 22 */	0x27,		/* 39 */
			0xff,		/* 255 */
/* 24 */	
			0x11, 0x0,	/* FC_RP */
/* 26 */	NdrFcShort( 0x1c ),	/* Offset= 28 (54) */
/* 28 */	
			0x13, 0x0,	/* FC_OP */
/* 30 */	NdrFcShort( 0xe ),	/* Offset= 14 (44) */
/* 32 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 34 */	NdrFcShort( 0x2 ),	/* 2 */
/* 36 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 38 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 40 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 42 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 44 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 46 */	NdrFcShort( 0x8 ),	/* 8 */
/* 48 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (32) */
/* 50 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 52 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 54 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x4 ),	/* 4 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0xffde ),	/* Offset= -34 (28) */
/* 64 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 66 */	NdrFcShort( 0x2 ),	/* Offset= 2 (68) */
/* 68 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 70 */	NdrFcLong( 0xa5b69200 ),	/* -1514761728 */
/* 74 */	NdrFcShort( 0x214b ),	/* 8523 */
/* 76 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 78 */	0x81,		/* 129 */
			0xb7,		/* 183 */
/* 80 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 82 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 84 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 86 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 88 */	NdrFcLong( 0x534f26cb ),	/* 1397696203 */
/* 92 */	NdrFcShort( 0x4f8a ),	/* 20362 */
/* 94 */	NdrFcShort( 0x4fee ),	/* 20462 */
/* 96 */	0x8d,		/* 141 */
			0x7e,		/* 126 */
/* 98 */	0x5c,		/* 92 */
			0x35,		/* 53 */
/* 100 */	0xa0,		/* 160 */
			0xa0,		/* 160 */
/* 102 */	0xcc,		/* 204 */
			0x38,		/* 56 */
/* 104 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 106 */	NdrFcShort( 0x8 ),	/* Offset= 8 (114) */
/* 108 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 112 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 114 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 116 */	NdrFcShort( 0x10 ),	/* 16 */
/* 118 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 120 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 122 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (108) */
			0x5b,		/* FC_END */
/* 126 */	
			0x11, 0x0,	/* FC_RP */
/* 128 */	NdrFcShort( 0xfff2 ),	/* Offset= -14 (114) */
/* 130 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 132 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 134 */	
			0x12, 0x0,	/* FC_UP */
/* 136 */	NdrFcShort( 0xffa4 ),	/* Offset= -92 (44) */
/* 138 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x4 ),	/* 4 */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (134) */
/* 148 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 150 */	NdrFcShort( 0x2 ),	/* Offset= 2 (152) */
/* 152 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 154 */	NdrFcLong( 0xaa46e0ce ),	/* -1438195506 */
/* 158 */	NdrFcShort( 0xf1f8 ),	/* -3592 */
/* 160 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 162 */	0xa8,		/* 168 */
			0x1e,		/* 30 */
/* 164 */	0x0,		/* 0 */
			0xc0,		/* 192 */
/* 166 */	0x4f,		/* 79 */
			0xb9,		/* 185 */
/* 168 */	0x60,		/* 96 */
			0xed,		/* 237 */
/* 170 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 172 */	NdrFcShort( 0xffaa ),	/* Offset= -86 (86) */
/* 174 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 176 */	NdrFcShort( 0x2 ),	/* Offset= 2 (178) */
/* 178 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 180 */	NdrFcLong( 0x54b6c009 ),	/* 1421262857 */
/* 184 */	NdrFcShort( 0xc05a ),	/* -16294 */
/* 186 */	NdrFcShort( 0x4f16 ),	/* 20246 */
/* 188 */	0xab,		/* 171 */
			0x55,		/* 85 */
/* 190 */	0x71,		/* 113 */
			0x6a,		/* 106 */
/* 192 */	0x1a,		/* 26 */
			0x1b,		/* 27 */
/* 194 */	0xe4,		/* 228 */
			0x47,		/* 71 */
/* 196 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 198 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 200 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 202 */	NdrFcShort( 0x2 ),	/* Offset= 2 (204) */
/* 204 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 206 */	NdrFcLong( 0xfe37fb02 ),	/* -29885694 */
/* 210 */	NdrFcShort( 0x3729 ),	/* 14121 */
/* 212 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 214 */	0x8c,		/* 140 */
			0xf4,		/* 244 */
/* 216 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 218 */	0xc9,		/* 201 */
			0x19,		/* 25 */
/* 220 */	0x4,		/* 4 */
			0x59,		/* 89 */
/* 222 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 224 */	NdrFcShort( 0x2 ),	/* Offset= 2 (226) */
/* 226 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 228 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 230 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 232 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 234 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 236 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 238 */	
			0x11, 0x0,	/* FC_RP */
/* 240 */	NdrFcShort( 0x2 ),	/* Offset= 2 (242) */
/* 242 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 244 */	NdrFcShort( 0x1 ),	/* 1 */
/* 246 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x54,		/* FC_DEREFERENCE */
/* 248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 250 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 252 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 254 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 256 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 258 */	
			0x11, 0x0,	/* FC_RP */
/* 260 */	NdrFcShort( 0x2 ),	/* Offset= 2 (262) */
/* 262 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 264 */	NdrFcShort( 0x1 ),	/* 1 */
/* 266 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 268 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 270 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 272 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 274 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 276 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 278 */	
			0x12, 0x0,	/* FC_UP */
/* 280 */	NdrFcShort( 0xff5a ),	/* Offset= -166 (114) */
/* 282 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 284 */	NdrFcShort( 0xff7c ),	/* Offset= -132 (152) */
/* 286 */	
			0x11, 0x0,	/* FC_RP */
/* 288 */	NdrFcShort( 0x2 ),	/* Offset= 2 (290) */
/* 290 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 292 */	NdrFcShort( 0x1 ),	/* 1 */
/* 294 */	0x40,		/* Corr desc:  constant, val=128 */
			0x0,		/* 0 */
/* 296 */	NdrFcShort( 0x80 ),	/* 128 */
/* 298 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 300 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 302 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 304 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 306 */	
			0x11, 0x0,	/* FC_RP */
/* 308 */	NdrFcShort( 0x2 ),	/* Offset= 2 (310) */
/* 310 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 312 */	NdrFcShort( 0x1 ),	/* 1 */
/* 314 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 316 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 318 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 320 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 322 */	
			0x11, 0x0,	/* FC_RP */
/* 324 */	NdrFcShort( 0x2 ),	/* Offset= 2 (326) */
/* 326 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 328 */	NdrFcShort( 0x1 ),	/* 1 */
/* 330 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 336 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 338 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 340 */	NdrFcShort( 0x2 ),	/* Offset= 2 (342) */
/* 342 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 346 */	0xb,		/* FC_HYPER */
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
/* 358 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 360 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 362 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 364 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 366 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 368 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 370 */	NdrFcShort( 0xfee4 ),	/* Offset= -284 (86) */
/* 372 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 384 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 386 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 388 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 390 */	
			0x11, 0x0,	/* FC_RP */
/* 392 */	NdrFcShort( 0x36 ),	/* Offset= 54 (446) */
/* 394 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 396 */	NdrFcShort( 0x2 ),	/* 2 */
/* 398 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 400 */	
			0x1d,		/* FC_SMFARRAY */
			0x3,		/* 3 */
/* 402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 404 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 406 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 408 */	NdrFcShort( 0x3c ),	/* 60 */
/* 410 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 412 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 414 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 416 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 418 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 420 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 422 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 424 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 426 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 428 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 430 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 432 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 434 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 436 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 438 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (394) */
/* 440 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 442 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (400) */
/* 444 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 446 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 448 */	NdrFcShort( 0x3c ),	/* 60 */
/* 450 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 452 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 454 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 456 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 458 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (406) */
/* 460 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 462 */	
			0x11, 0x0,	/* FC_RP */
/* 464 */	NdrFcShort( 0x2a ),	/* Offset= 42 (506) */
/* 466 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 468 */	NdrFcShort( 0x10 ),	/* 16 */
/* 470 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 472 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 474 */	NdrFcShort( 0x4 ),	/* 4 */
/* 476 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 478 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 480 */	NdrFcShort( 0x20 ),	/* 32 */
/* 482 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 484 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 486 */	NdrFcShort( 0x3d ),	/* 61 */
/* 488 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 490 */	NdrFcShort( 0xfe82 ),	/* Offset= -382 (108) */
/* 492 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 494 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (466) */
/* 496 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 498 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (472) */
/* 500 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 502 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (478) */
/* 504 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 506 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 508 */	NdrFcShort( 0x3d ),	/* 61 */
/* 510 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 514 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 516 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 518 */	NdrFcShort( 0xffde ),	/* Offset= -34 (484) */
/* 520 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 522 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x0 ),	/* Offset= 0 (528) */
/* 530 */	0xd,		/* FC_ENUM16 */
			0x8,		/* FC_LONG */
/* 532 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 534 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 536 */	NdrFcShort( 0xc ),	/* 12 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x0 ),	/* Offset= 0 (540) */
/* 542 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 544 */	NdrFcShort( 0xffea ),	/* Offset= -22 (522) */
/* 546 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 548 */	
			0x11, 0x0,	/* FC_RP */
/* 550 */	NdrFcShort( 0x4a ),	/* Offset= 74 (624) */
/* 552 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 554 */	NdrFcShort( 0x24 ),	/* 36 */
/* 556 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 558 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 560 */	NdrFcShort( 0x64 ),	/* 100 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* Offset= 0 (564) */
/* 566 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 568 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (522) */
/* 570 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 572 */	NdrFcShort( 0xffce ),	/* Offset= -50 (522) */
/* 574 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 576 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 578 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 580 */	0x0,		/* 0 */
			NdrFcShort( 0xffe3 ),	/* Offset= -29 (552) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 584 */	0x0,		/* 0 */
			NdrFcShort( 0xffdf ),	/* Offset= -33 (552) */
			0x5b,		/* FC_END */
/* 588 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 590 */	NdrFcShort( 0x1 ),	/* 1 */
/* 592 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 596 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 598 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 602 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 604 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 606 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (558) */
/* 608 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 610 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 612 */	NdrFcShort( 0x68 ),	/* 104 */
/* 614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0x0 ),	/* Offset= 0 (616) */
/* 618 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 620 */	0x0,		/* 0 */
			NdrFcShort( 0xffdf ),	/* Offset= -33 (588) */
			0x5b,		/* FC_END */
/* 624 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 630 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 632 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 634 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 638 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 640 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 642 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (610) */
/* 644 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 646 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 648 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 650 */	
			0x11, 0x0,	/* FC_RP */
/* 652 */	NdrFcShort( 0x2 ),	/* Offset= 2 (654) */
/* 654 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 656 */	NdrFcShort( 0x1 ),	/* 1 */
/* 658 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 660 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 662 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 664 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */

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



/* Standard interface: __MIDL_itf_rmsint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IRmsServer, ver. 0.0,
   GUID={0xDDA2FBE0,0x33E4,0x4221,{0xA2,0xC8,0xD9,0x07,0x11,0x03,0x97,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsServer_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    30,
    66,
    96,
    132,
    162,
    192,
    222,
    258,
    294,
    330,
    366,
    402,
    438,
    474,
    510,
    546,
    582,
    612,
    642,
    732,
    798,
    840,
    918,
    960,
    1002,
    1044,
    1104,
    1146,
    1188,
    1224,
    1272
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(39) _IRmsServerProxyVtbl = 
{
    &IRmsServer_ProxyInfo,
    &IID_IRmsServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::IsReady */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::ChangeState */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::IsNTMSInstalled */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetNTMS */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::InitializeInAnotherThread */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::Initialize */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::SaveAll */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetServerName */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetActiveCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetDataMovers */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::SetActiveCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetLibraries */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetMediaSets */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetRequests */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetClients */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetUnconfiguredDevices */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::ScanForDevices */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::ScanForDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::MountScratchCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::MountCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::DismountCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::DuplicateCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::RecycleCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::FindLibraryById */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::FindCartridgeById */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::CreateObject */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetNofAvailableDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::FindCartridgeStatusById */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::IsMultipleSidedMedia */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::CheckSecondSide */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetMaxMediaCapacity */
};


static const PRPC_STUB_FUNCTION IRmsServer_table[] =
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
    NdrStubCall2,
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

CInterfaceStubVtbl _IRmsServerStubVtbl =
{
    &IID_IRmsServer,
    &IRmsServer_ServerInfo,
    39,
    &IRmsServer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsLibrary, ver. 0.0,
   GUID={0xFE37FB02,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsLibrary_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1314,
    1350,
    1386,
    1422,
    1458,
    1494,
    1530,
    1566,
    1602,
    1638,
    1674,
    1710,
    1746,
    1782,
    1818,
    1854,
    1890,
    1926,
    1962,
    1998,
    2034,
    2070,
    2100,
    2136,
    2172,
    2208,
    2244,
    2280,
    2316,
    2352,
    2388,
    2424,
    2460,
    2496,
    2532,
    2568
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsLibrary_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsLibrary_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsLibrary_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsLibrary_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(43) _IRmsLibraryProxyVtbl = 
{
    &IRmsLibrary_ProxyInfo,
    &IID_IRmsLibrary,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetLibraryId */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetLibraryId */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMaxChangers */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMaxChangers */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMaxDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMaxDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMaxPorts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMaxPorts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMaxSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMaxSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetNumUsedSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetNumStagingSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetNumStagingSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetNumScratchCarts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetNumScratchCarts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetNumUnknownCarts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetNumUnknownCarts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::IsMagazineSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetIsMagazineSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMaxCleaningMounts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMaxCleaningMounts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetSlotSelectionPolicy */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetSlotSelectionPolicy */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetChangers */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetDriveClasses */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetStorageSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetStagingSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetPorts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetCleaningCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetScratchCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMediaSets */
};


static const PRPC_STUB_FUNCTION IRmsLibrary_table[] =
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
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
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

CInterfaceStubVtbl _IRmsLibraryStubVtbl =
{
    &IID_IRmsLibrary,
    &IRmsLibrary_ServerInfo,
    43,
    &IRmsLibrary_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsDriveClass, ver. 0.0,
   GUID={0xFE37FB03,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsDriveClass_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1314,
    2604,
    2640,
    2676,
    2712,
    2748,
    2784,
    2820,
    2856,
    2892,
    2928,
    2964,
    3000,
    3036,
    3072,
    1854,
    1890,
    1926,
    1962,
    3108
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsDriveClass_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsDriveClass_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsDriveClass_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsDriveClass_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IRmsDriveClassProxyVtbl = 
{
    &IRmsDriveClass_ProxyInfo,
    &IID_IRmsDriveClass,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetDriveClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetType */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetType */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetCapability */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetCapability */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetIdleTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetIdleTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetMountWaitTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetMountWaitTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetMountLimit */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetMountLimit */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetQueuedRequests */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetQueuedRequests */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetUnloadPauseTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetUnloadPauseTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetDriveSelectionPolicy */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetDriveSelectionPolicy */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetDrives */
};


static const PRPC_STUB_FUNCTION IRmsDriveClass_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsDriveClassStubVtbl =
{
    &IID_IRmsDriveClass,
    &IRmsDriveClass_ServerInfo,
    27,
    &IRmsDriveClass_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsCartridge, ver. 0.0,
   GUID={0x534F26CB,0x4F8A,0x4FEE,{0x8D,0x7E,0x5C,0x35,0xA0,0xA0,0xCC,0x38}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsCartridge_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1314,
    1350,
    3144,
    3180,
    3216,
    3252,
    3288,
    3324,
    3360,
    3402,
    3444,
    3480,
    3528,
    3576,
    3612,
    1854,
    1890,
    1926,
    1962,
    1998,
    2034,
    3648,
    3684,
    3714,
    3750,
    3780,
    3816,
    3846,
    3924,
    4002,
    4080,
    4158,
    4194,
    4230,
    4266,
    4302,
    4344,
    4386,
    4422,
    4458,
    4494,
    4530,
    4566,
    4602,
    4638,
    4686,
    4722,
    4758,
    4794,
    4830,
    4884,
    4938,
    4974,
    5010
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsCartridge_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsCartridge_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsCartridge_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsCartridge_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(61) _IRmsCartridgeProxyVtbl = 
{
    &IRmsCartridge_ProxyInfo,
    &IID_IRmsCartridge,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetMediaSetId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetMediaSetId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetCartridgeId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetCartridgeId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetTagAndNumber */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetTagAndNumber */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetBarcode */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetOnMediaIdentifier */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetOnMediaIdentifier */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetOnMediaLabel */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetOnMediaLabel */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetStatus */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetStatus */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetType */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetType */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetBlockSize */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetBlockSize */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetIsTwoSided */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::IsTwoSided */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetIsMounted */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::IsMounted */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetIsAvailable */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::IsAvailable */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetHome */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetHome */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetLocation */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetLocation */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetDrive */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetDrive */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetMailStop */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetMailStop */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetPartitions */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetVerifierClass */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetVerifierClass */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetPortalClass */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetPortalClass */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::Mount */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::Dismount */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::Home */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::CreateDataMover */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::ReleaseDataMover */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::LoadDataCache */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SaveDataCache */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetManagedBy */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetManagedBy */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::IsFixedBlockSize */
};


static const PRPC_STUB_FUNCTION IRmsCartridge_table[] =
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
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
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

CInterfaceStubVtbl _IRmsCartridgeStubVtbl =
{
    &IID_IRmsCartridge,
    &IRmsCartridge_ServerInfo,
    61,
    &IRmsCartridge_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsDrive, ver. 0.0,
   GUID={0xAA46E0CE,0xF1F8,0x11D2,{0xA8,0x1E,0x00,0xC0,0x4F,0xB9,0x60,0xED}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsDrive_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5040,
    5076,
    66,
    5106,
    132,
    5142,
    5178,
    5214,
    5244,
    5286
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsDrive_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsDrive_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsDrive_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsDrive_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IRmsDriveProxyVtbl = 
{
    &IRmsDrive_ProxyInfo,
    &IID_IRmsDrive,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::GetMountReference */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::ResetMountReference */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::AddMountReference */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::ReleaseMountReference */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::SelectForMount */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::CreateDataMover */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::ReleaseDataMover */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::Eject */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::GetLargestFreeSpace */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::UnloadNow */
};


static const PRPC_STUB_FUNCTION IRmsDrive_table[] =
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

CInterfaceStubVtbl _IRmsDriveStubVtbl =
{
    &IID_IRmsDrive,
    &IRmsDrive_ServerInfo,
    17,
    &IRmsDrive_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsStorageSlot, ver. 0.0,
   GUID={0xFE37FB06,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsStorageSlot_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5316,
    5076,
    5352,
    5394
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsStorageSlot_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsStorageSlot_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsStorageSlot_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsStorageSlot_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IRmsStorageSlotProxyVtbl = 
{
    &IRmsStorageSlot_ProxyInfo,
    &IID_IRmsStorageSlot,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageSlot::SetIsInMagazine */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageSlot::IsInMagazine */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageSlot::GetMagazineAndCell */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageSlot::SetMagazineAndCell */
};


static const PRPC_STUB_FUNCTION IRmsStorageSlot_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsStorageSlotStubVtbl =
{
    &IID_IRmsStorageSlot,
    &IRmsStorageSlot_ServerInfo,
    11,
    &IRmsStorageSlot_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsMediumChanger, ver. 0.0,
   GUID={0xFE37FB07,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsMediumChanger_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    5076,
    66,
    5436,
    5484,
    1494,
    192,
    1566,
    5532,
    5562,
    5598,
    5634,
    5670,
    5706,
    5736,
    5772,
    5808,
    5850
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsMediumChanger_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsMediumChanger_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsMediumChanger_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsMediumChanger_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(25) _IRmsMediumChangerProxyVtbl = 
{
    &IRmsMediumChanger_ProxyInfo,
    &IID_IRmsMediumChanger,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::Initialize */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::AcquireDevice */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::ReleaseDevice */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::GetHome */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::SetHome */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::SetAutomatic */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::IsAutomatic */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::SetCanRotate */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::CanRotate */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::GetOperation */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::SetOperation */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::GetPercentComplete */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::SetPercentComplete */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::TestReady */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::ImportCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::ExportCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::MoveCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::HomeCartridge */
};


static const PRPC_STUB_FUNCTION IRmsMediumChanger_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsMediumChangerStubVtbl =
{
    &IID_IRmsMediumChanger,
    &IRmsMediumChanger_ServerInfo,
    25,
    &IRmsMediumChanger_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsMoveMedia, ver. 0.0,
   GUID={0xFE37FB18,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsMoveMedia_FormatStringOffsetTable[] =
    {
    5886,
    5928,
    5970,
    6000,
    0,
    6042,
    6084,
    6138,
    6198,
    6246,
    6288
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsMoveMedia_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsMoveMedia_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsMoveMedia_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsMoveMedia_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IRmsMoveMediaProxyVtbl = 
{
    &IRmsMoveMedia_ProxyInfo,
    &IID_IRmsMoveMedia,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::GetParameters */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::GetProductData */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::RezeroUnit */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::InitializeElementStatus */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::Status */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::SetAccess */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::GetElementStatus */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::ExchangeMedium */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::MoveMedium */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::Position */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::QueryVolumeTag */
};

const CInterfaceStubVtbl _IRmsMoveMediaStubVtbl =
{
    &IID_IRmsMoveMedia,
    &IRmsMoveMedia_ServerInfo,
    14,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRmsIEPort, ver. 0.0,
   GUID={0xFE37FB08,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsIEPort_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6348,
    6384,
    6420,
    6456,
    2712,
    162,
    1530,
    1566
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsIEPort_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsIEPort_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsIEPort_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsIEPort_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IRmsIEPortProxyVtbl = 
{
    &IRmsIEPort_ProxyInfo,
    &IID_IRmsIEPort,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::GetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::SetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::SetIsImport */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::IsImport */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::SetIsExport */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::IsExport */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::GetWaitTime */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::SetWaitTime */
};


static const PRPC_STUB_FUNCTION IRmsIEPort_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsIEPortStubVtbl =
{
    &IID_IRmsIEPort,
    &IRmsIEPort_ServerInfo,
    15,
    &IRmsIEPort_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsMediaSet, ver. 0.0,
   GUID={0xBC9E7125,0x0976,0x4773,{0x9E,0x43,0x72,0x04,0x7F,0xED,0x47,0x8C}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsMediaSet_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1314,
    2604,
    2640,
    2676,
    2712,
    6486,
    6528,
    6570,
    6606,
    2892,
    2928,
    2964,
    3000,
    3036,
    3072,
    6642,
    1890,
    6672,
    6732
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsMediaSet_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsMediaSet_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsMediaSet_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsMediaSet_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IRmsMediaSetProxyVtbl = 
{
    &IRmsMediaSet_ProxyInfo,
    &IID_IRmsMediaSet,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetMediaSetId */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetMediaSetType */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetMediaSetType */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetMaxCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetMaxCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetOccupancy */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetOccupancy */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::IsMediaCopySupported */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetIsMediaCopySupported */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::Allocate */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::Deallocate */
};


static const PRPC_STUB_FUNCTION IRmsMediaSet_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsMediaSetStubVtbl =
{
    &IID_IRmsMediaSet,
    &IRmsMediaSet_ServerInfo,
    26,
    &IRmsMediaSet_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsRequest, ver. 0.0,
   GUID={0xFE37FB10,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsRequest_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5040,
    2604,
    2640,
    5106,
    132,
    6768,
    6804,
    6840,
    6876
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsRequest_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsRequest_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsRequest_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsRequest_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IRmsRequestProxyVtbl = 
{
    &IRmsRequest_ProxyInfo,
    &IID_IRmsRequest,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::GetRequestNo */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::GetRequestDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::SetRequestDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::SetIsDone */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::IsDone */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::GetOperation */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::SetOperation */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::GetPercentComplete */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::SetPercentComplete */
};


static const PRPC_STUB_FUNCTION IRmsRequest_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsRequestStubVtbl =
{
    &IID_IRmsRequest,
    &IRmsRequest_ServerInfo,
    16,
    &IRmsRequest_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsPartition, ver. 0.0,
   GUID={0xFE37FB11,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsPartition_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5040,
    6912,
    6420,
    6948,
    6990,
    162,
    7032
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsPartition_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsPartition_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsPartition_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsPartition_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IRmsPartitionProxyVtbl = 
{
    &IRmsPartition_ProxyInfo,
    &IID_IRmsPartition,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::GetPartNo */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::GetAttributes */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::SetAttributes */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::SetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::VerifyIdentifier */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::ReadOnMediaId */
};


static const PRPC_STUB_FUNCTION IRmsPartition_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsPartitionStubVtbl =
{
    &IID_IRmsPartition,
    &IRmsPartition_ServerInfo,
    14,
    &IRmsPartition_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsComObject, ver. 0.0,
   GUID={0xFE37FB12,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsComObject_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1314,
    1350,
    7074,
    5106,
    132,
    162,
    2784,
    2820,
    2856,
    2892,
    2928,
    7110,
    7146,
    3576,
    3612,
    1854,
    1890
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsComObject_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsComObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsComObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsComObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IRmsComObjectProxyVtbl = 
{
    &IRmsComObject_ProxyInfo,
    &IID_IRmsComObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetObjectId */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetObjectId */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetObjectType */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetObjectType */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::IsEnabled */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::Enable */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::Disable */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetState */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetState */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetStatusCode */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetStatusCode */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetFindBy */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetFindBy */
};


static const PRPC_STUB_FUNCTION IRmsComObject_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsComObjectStubVtbl =
{
    &IID_IRmsComObject,
    &IRmsComObject_ServerInfo,
    24,
    &IRmsComObject_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsChangerElement, ver. 0.0,
   GUID={0xFE37FB13,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsChangerElement_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5040,
    7182,
    7260,
    2676,
    2712,
    1494,
    192,
    1566,
    5532,
    7338,
    7374,
    7410,
    7446,
    7482,
    7524,
    7554,
    7602
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsChangerElement_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsChangerElement_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsChangerElement_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsChangerElement_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IRmsChangerElementProxyVtbl = 
{
    &IRmsChangerElement_ProxyInfo,
    &IID_IRmsChangerElement,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetElementNo */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetLocation */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetLocation */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetIsStorage */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::IsStorage */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetIsOccupied */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::IsOccupied */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetAccessCounters */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::ResetAccessCounters */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetCoordinates */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetCoordinates */
};


static const PRPC_STUB_FUNCTION IRmsChangerElement_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsChangerElementStubVtbl =
{
    &IID_IRmsChangerElement,
    &IRmsChangerElement_ServerInfo,
    24,
    &IRmsChangerElement_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsDevice, ver. 0.0,
   GUID={0xFE37FB14,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsDevice_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6348,
    6384,
    7074,
    5106,
    7650,
    7692,
    7734,
    7788
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsDevice_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsDevice_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsDevice_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsDevice_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IRmsDeviceProxyVtbl = 
{
    &IRmsDevice_ProxyInfo,
    &IID_IRmsDevice,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::GetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::SetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::GetDeviceType */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::SetDeviceType */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::GetDeviceInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::SetDeviceInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::GetDeviceAddress */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::SetDeviceAddress */
};


static const PRPC_STUB_FUNCTION IRmsDevice_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsDeviceStubVtbl =
{
    &IID_IRmsDevice,
    &IRmsDevice_ServerInfo,
    15,
    &IRmsDevice_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsStorageInfo, ver. 0.0,
   GUID={0xFE37FB15,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsStorageInfo_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    7842,
    7884,
    7926,
    5394,
    7962,
    1494,
    7998,
    8040,
    8076,
    8118,
    2928,
    8154,
    8196,
    7482,
    8232,
    8268,
    8310,
    8346,
    8382,
    8418,
    8454
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsStorageInfo_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsStorageInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsStorageInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsStorageInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(28) _IRmsStorageInfoProxyVtbl = 
{
    &IRmsStorageInfo_ProxyInfo,
    &IID_IRmsStorageInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetMountCounters */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetBytesRead2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetBytesRead */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetBytesRead2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetBytesRead */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::IncrementBytesRead */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetBytesWritten2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetBytesWritten */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetBytesWritten2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetBytesWritten */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::IncrementBytesWritten */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetCapacity2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetCapacity */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetUsedSpace2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetUsedSpace */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetLargestFreeSpace2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetLargestFreeSpace */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetCapacity */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetUsedSpace */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetFreeSpace */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::ResetCounters */
};


static const PRPC_STUB_FUNCTION IRmsStorageInfo_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsStorageInfoStubVtbl =
{
    &IID_IRmsStorageInfo,
    &IRmsStorageInfo_ServerInfo,
    28,
    &IRmsStorageInfo_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsClient, ver. 0.0,
   GUID={0xFE37FB16,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsClient_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1314,
    1350,
    1386,
    1422,
    3216,
    3252,
    8484,
    8526,
    8568,
    8604,
    8640,
    8676
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsClient_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsClient_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsClient_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsClient_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IRmsClientProxyVtbl = 
{
    &IRmsClient_ProxyInfo,
    &IID_IRmsClient,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetPassword */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetPassword */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetVerifierClass */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetVerifierClass */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetPortalClass */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetPortalClass */
};


static const PRPC_STUB_FUNCTION IRmsClient_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsClientStubVtbl =
{
    &IID_IRmsClient,
    &IRmsClient_ServerInfo,
    19,
    &IRmsClient_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsNTMS, ver. 0.0,
   GUID={0x70674820,0x67DF,0x4C2F,{0x9D,0xF4,0x1A,0xF0,0xAD,0x42,0x27,0xFF}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsNTMS_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    5076,
    8712,
    8778,
    8832,
    8874,
    8910,
    8952,
    8994,
    9048,
    9090,
    9132,
    9162,
    5706,
    7524,
    9204,
    9240,
    1926,
    9276,
    9324
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsNTMS_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsNTMS_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsNTMS_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsNTMS_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IRmsNTMSProxyVtbl = 
{
    &IRmsNTMS_ProxyInfo,
    &IID_IRmsNTMS,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::IsInstalled */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Initialize */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Allocate */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Mount */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Dismount */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Deallocate */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::DismountAll */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::DisableAndEject */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::UpdateOmidInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::GetBlockSize */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::SetBlockSize */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::ExportDatabase */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::FindCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Suspend */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Resume */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::IsMediaCopySupported */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::UpdateDrive */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::GetNofAvailableDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::CheckSecondSide */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::GetMaxMediaCapacity */
};


static const PRPC_STUB_FUNCTION IRmsNTMS_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsNTMSStubVtbl =
{
    &IID_IRmsNTMS,
    &IRmsNTMS_ServerInfo,
    27,
    &IRmsNTMS_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsSinkEveryEvent, ver. 0.0,
   GUID={0xFE37FB20,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsSinkEveryEvent_FormatStringOffsetTable[] =
    {
    9366
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsSinkEveryEvent_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsSinkEveryEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsSinkEveryEvent_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsSinkEveryEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IRmsSinkEveryEventProxyVtbl = 
{
    &IRmsSinkEveryEvent_ProxyInfo,
    &IID_IRmsSinkEveryEvent,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRmsSinkEveryEvent::ProcessObjectStatusChange */
};

const CInterfaceStubVtbl _IRmsSinkEveryEventStubVtbl =
{
    &IID_IRmsSinkEveryEvent,
    &IRmsSinkEveryEvent_ServerInfo,
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
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _rmsint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IRmsLibraryProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsDriveClassProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsStorageSlotProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsMediumChangerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsIEPortProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsRequestProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsPartitionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsComObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsChangerElementProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsDeviceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsStorageInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsClientProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsMoveMediaProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsNTMSProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsSinkEveryEventProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsMediaSetProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsCartridgeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsDriveProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsServerProxyVtbl,
    0
};

const CInterfaceStubVtbl * _rmsint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IRmsLibraryStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsDriveClassStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsStorageSlotStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsMediumChangerStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsIEPortStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsRequestStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsPartitionStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsComObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsChangerElementStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsDeviceStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsStorageInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsClientStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsMoveMediaStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsNTMSStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsSinkEveryEventStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsMediaSetStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsCartridgeStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsDriveStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsServerStubVtbl,
    0
};

PCInterfaceName const _rmsint_InterfaceNamesList[] = 
{
    "IRmsLibrary",
    "IRmsDriveClass",
    "IRmsStorageSlot",
    "IRmsMediumChanger",
    "IRmsIEPort",
    "IRmsRequest",
    "IRmsPartition",
    "IRmsComObject",
    "IRmsChangerElement",
    "IRmsDevice",
    "IRmsStorageInfo",
    "IRmsClient",
    "IRmsMoveMedia",
    "IRmsNTMS",
    "IRmsSinkEveryEvent",
    "IRmsMediaSet",
    "IRmsCartridge",
    "IRmsDrive",
    "IRmsServer",
    0
};

const IID *  _rmsint_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0,
    &IID_IDispatch,
    0,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _rmsint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _rmsint, pIID, n)

int __stdcall _rmsint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _rmsint, 19, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _rmsint, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _rmsint, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _rmsint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _rmsint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _rmsint, 19, *pIndex )
    
}

const ExtendedProxyFileInfo rmsint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _rmsint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _rmsint_StubVtblList,
    (const PCInterfaceName * ) & _rmsint_InterfaceNamesList,
    (const IID ** ) & _rmsint_BaseIIDList,
    & _rmsint_IID_Lookup, 
    19,
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
/* Compiler settings for rmsint.idl:
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


#include "rmsint.h"

#define TYPE_FORMAT_STRING_SIZE   667                               
#define PROC_FORMAT_STRING_SIZE   9889                              
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


extern const MIDL_SERVER_INFO IRmsServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsLibrary_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsLibrary_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsDriveClass_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsDriveClass_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsCartridge_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsCartridge_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsDrive_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsDrive_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsStorageSlot_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsStorageSlot_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsMediumChanger_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsMediumChanger_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsMoveMedia_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsMoveMedia_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsIEPort_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsIEPort_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsMediaSet_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsMediaSet_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsRequest_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsRequest_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsPartition_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsPartition_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsComObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsComObject_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsChangerElement_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsChangerElement_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsDevice_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsDevice_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsStorageInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsStorageInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsClient_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsClient_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsNTMS_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsNTMS_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRmsSinkEveryEvent_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRmsSinkEveryEvent_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure IsInstalled */


	/* Procedure Status */


	/* Procedure Initialize */


	/* Procedure IsReady */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
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


	/* Return value */


	/* Return value */


	/* Return value */

/* 26 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 28 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 30 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeState */

/* 32 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 34 */	NdrFcLong( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0x8 ),	/* 8 */
/* 40 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 48 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newState */

/* 58 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 60 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 62 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 64 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 66 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 68 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReleaseDevice */


	/* Procedure AddMountReference */


	/* Procedure IsNTMSInstalled */

/* 70 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 72 */	NdrFcLong( 0x0 ),	/* 0 */
/* 76 */	NdrFcShort( 0x9 ),	/* 9 */
/* 78 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 80 */	NdrFcShort( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x8 ),	/* 8 */
/* 84 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 86 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNTMS */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0xa ),	/* 10 */
/* 110 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 118 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 128 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 130 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 132 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 136 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsEnabled */


	/* Procedure IsDone */


	/* Procedure SelectForMount */


	/* Procedure InitializeInAnotherThread */

/* 140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0xb ),	/* 11 */
/* 148 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 154 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 156 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 168 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Enable */


	/* Procedure VerifyIdentifier */


	/* Procedure IsExport */


	/* Procedure Initialize */

/* 172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0xc ),	/* 12 */
/* 180 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 186 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 188 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 200 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsStorage */


	/* Procedure IsAutomatic */


	/* Procedure SaveAll */

/* 204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0xd ),	/* 13 */
/* 212 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 218 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 220 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 232 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetServerName */

/* 236 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0xe ),	/* 14 */
/* 244 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	NdrFcShort( 0x8 ),	/* 8 */
/* 250 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 252 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 254 */	NdrFcShort( 0x1 ),	/* 1 */
/* 256 */	NdrFcShort( 0x1 ),	/* 1 */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 262 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 264 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 266 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 270 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCartridges */

/* 274 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 280 */	NdrFcShort( 0xf ),	/* 15 */
/* 282 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 288 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 290 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 300 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 302 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 304 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 306 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 308 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActiveCartridges */

/* 312 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 314 */	NdrFcLong( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x10 ),	/* 16 */
/* 320 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x8 ),	/* 8 */
/* 326 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 328 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 338 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 340 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 342 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 346 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDataMovers */

/* 350 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x11 ),	/* 17 */
/* 358 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 362 */	NdrFcShort( 0x8 ),	/* 8 */
/* 364 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 366 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 376 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 378 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 380 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 382 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 384 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 386 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetActiveCartridge */

/* 388 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 390 */	NdrFcLong( 0x0 ),	/* 0 */
/* 394 */	NdrFcShort( 0x12 ),	/* 18 */
/* 396 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0x8 ),	/* 8 */
/* 402 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 404 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 414 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 416 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 418 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 422 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLibraries */

/* 426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x13 ),	/* 19 */
/* 434 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 440 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 442 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 452 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 454 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 456 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 458 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 460 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSets */

/* 464 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 470 */	NdrFcShort( 0x14 ),	/* 20 */
/* 472 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 476 */	NdrFcShort( 0x8 ),	/* 8 */
/* 478 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 480 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 490 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 492 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 494 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 496 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 498 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRequests */

/* 502 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 504 */	NdrFcLong( 0x0 ),	/* 0 */
/* 508 */	NdrFcShort( 0x15 ),	/* 21 */
/* 510 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 514 */	NdrFcShort( 0x8 ),	/* 8 */
/* 516 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 518 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 528 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 530 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 532 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 536 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetClients */

/* 540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x16 ),	/* 22 */
/* 548 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 554 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 556 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 566 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 568 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 570 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 572 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 574 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUnconfiguredDevices */

/* 578 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 580 */	NdrFcLong( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x17 ),	/* 23 */
/* 586 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x8 ),	/* 8 */
/* 592 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 594 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 604 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 606 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 608 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 610 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 612 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ScanForDevices */

/* 616 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x18 ),	/* 24 */
/* 624 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 630 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 632 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 644 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ScanForDrives */

/* 648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x19 ),	/* 25 */
/* 656 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x8 ),	/* 8 */
/* 662 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 664 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 674 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 676 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MountScratchCartridge */

/* 680 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x1a ),	/* 26 */
/* 688 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 690 */	NdrFcShort( 0xbc ),	/* 188 */
/* 692 */	NdrFcShort( 0x70 ),	/* 112 */
/* 694 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 696 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x1 ),	/* 1 */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCartId */

/* 706 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 708 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 710 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter fromMediaSet */

/* 712 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 714 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 716 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter prevSideId */

/* 718 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 720 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 722 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pFreeSpace */

/* 724 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 726 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 728 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter blockingFactor */

/* 730 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 732 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter displayName */

/* 736 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 738 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 740 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter ppDrive */

/* 742 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 744 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 746 */	NdrFcShort( 0x94 ),	/* Type Offset=148 */

	/* Parameter ppCartridge */

/* 748 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 750 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 752 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Parameter ppDataMover */

/* 754 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 756 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 758 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Parameter options */

/* 760 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 762 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 764 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 768 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MountCartridge */

/* 772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x1b ),	/* 27 */
/* 780 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 782 */	NdrFcShort( 0x54 ),	/* 84 */
/* 784 */	NdrFcShort( 0x8 ),	/* 8 */
/* 786 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 788 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 798 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 800 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 802 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter ppDrive */

/* 804 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 806 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 808 */	NdrFcShort( 0x94 ),	/* Type Offset=148 */

	/* Parameter ppCartridge */

/* 810 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 812 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 814 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Parameter ppDataMover */

/* 816 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 818 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 820 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Parameter options */

/* 822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 824 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 828 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 830 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 834 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 836 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DismountCartridge */

/* 840 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x1c ),	/* 28 */
/* 848 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 850 */	NdrFcShort( 0x4c ),	/* 76 */
/* 852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 854 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 856 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 866 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 868 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 870 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter options */

/* 872 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 874 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 880 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DuplicateCartridge */

/* 884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 890 */	NdrFcShort( 0x1d ),	/* 29 */
/* 892 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 894 */	NdrFcShort( 0x118 ),	/* 280 */
/* 896 */	NdrFcShort( 0x94 ),	/* 148 */
/* 898 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 900 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0x1 ),	/* 1 */
/* 906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 910 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 912 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 914 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter firstSideId */

/* 916 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 918 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 920 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pCopyCartId */

/* 922 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 924 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 926 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter copySet */

/* 928 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 930 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 932 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter copyName */

/* 934 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 936 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 938 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter pFreeSpace */

/* 940 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 942 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 944 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pCapacity */

/* 946 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 948 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 950 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter options */

/* 952 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 954 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 958 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 960 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 962 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RecycleCartridge */

/* 964 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 966 */	NdrFcLong( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x1e ),	/* 30 */
/* 972 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 974 */	NdrFcShort( 0x4c ),	/* 76 */
/* 976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 978 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 980 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 990 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 992 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 994 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter options */

/* 996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 998 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1002 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1004 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindLibraryById */

/* 1008 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1010 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1016 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1018 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1020 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1022 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1024 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libId */

/* 1034 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1036 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1038 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter ptr */

/* 1040 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1042 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1044 */	NdrFcShort( 0xc8 ),	/* Type Offset=200 */

	/* Return value */

/* 1046 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1048 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCartridgeById */

/* 1052 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1054 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1060 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1062 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1064 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1066 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1068 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 1078 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1080 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1082 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter ptr */

/* 1084 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1086 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1088 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 1090 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1092 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1094 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateObject */

/* 1096 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1098 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1102 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1104 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1106 */	NdrFcShort( 0xd4 ),	/* 212 */
/* 1108 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1110 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x6,		/* 6 */
/* 1112 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1114 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter objectId */

/* 1122 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1124 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1126 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter rclsid */

/* 1128 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1130 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1132 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter riid */

/* 1134 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1136 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1138 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter dwCreate */

/* 1140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1142 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppvObj */

/* 1146 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1148 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1150 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Return value */

/* 1152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1154 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNofAvailableDrives */

/* 1158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1166 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1168 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1170 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1172 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1174 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromMediaSet */

/* 1184 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1186 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1188 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pdwNofDrives */

/* 1190 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1192 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1198 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCartridgeStatusById */

/* 1202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1208 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1210 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1212 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1214 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1216 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1218 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 1228 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1230 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1232 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pdwStatus */

/* 1234 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1236 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1242 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMultipleSidedMedia */

/* 1246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1252 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1254 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1256 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1262 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaSetId */

/* 1272 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1274 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1276 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckSecondSide */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1292 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1294 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1296 */	NdrFcShort( 0x68 ),	/* 104 */
/* 1298 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1300 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter firstSideId */

/* 1310 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1312 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1314 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pbValid */

/* 1316 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1318 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSecondSideId */

/* 1322 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1324 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1326 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 1328 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1330 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxMediaCapacity */

/* 1334 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1336 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1342 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1344 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1346 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1348 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1350 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromMediaSet */

/* 1360 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1362 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1364 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pMaxCapacity */

/* 1366 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1368 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1370 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 1372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1374 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOwnerClassId */


	/* Procedure GetObjectId */


	/* Procedure GetMediaSetId */


	/* Procedure GetMediaSetId */


	/* Procedure GetDriveClassId */


	/* Procedure GetLibraryId */

/* 1378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1386 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1390 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1392 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1394 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1402 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */


	/* Parameter pObjectId */


	/* Parameter pMediaSetId */


	/* Parameter pMediaSetId */


	/* Parameter pDriveClassId */


	/* Parameter pLibId */

/* 1404 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1406 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1408 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1412 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOwnerClassId */


	/* Procedure SetObjectId */


	/* Procedure SetMediaSetId */


	/* Procedure SetLibraryId */

/* 1416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1422 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1424 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1426 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1430 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1432 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */


	/* Parameter objectId */


	/* Parameter mediaSetId */


	/* Parameter libId */

/* 1442 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1444 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1446 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1450 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetName */

/* 1454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1460 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1462 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1466 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1468 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1470 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1472 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1474 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 1480 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1482 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1484 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */


	/* Return value */

/* 1486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1488 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */


	/* Procedure SetName */

/* 1492 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0xa ),	/* 10 */
/* 1500 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1506 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1508 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter name */

/* 1518 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1520 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1522 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */


	/* Return value */

/* 1524 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1526 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSupported */

/* 1530 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1532 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1536 */	NdrFcShort( 0xb ),	/* 11 */
/* 1538 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1542 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1544 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1546 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 1556 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1558 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1564 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IncrementBytesRead */


	/* Procedure SetIsStorage */


	/* Procedure SetAutomatic */


	/* Procedure SetMediaSupported */

/* 1568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1574 */	NdrFcShort( 0xc ),	/* 12 */
/* 1576 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1582 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1584 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1592 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter val */


	/* Parameter flag */


	/* Parameter flag */


	/* Parameter type */

/* 1594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1596 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1602 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetWaitTime */


	/* Procedure GetMaxChangers */

/* 1606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1612 */	NdrFcShort( 0xd ),	/* 13 */
/* 1614 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1620 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1622 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1630 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */


	/* Parameter pNum */

/* 1632 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1634 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1638 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1640 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1642 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsOccupied */


	/* Procedure SetWaitTime */


	/* Procedure SetCanRotate */


	/* Procedure SetMaxChangers */

/* 1644 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1646 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1650 */	NdrFcShort( 0xe ),	/* 14 */
/* 1652 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1658 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1660 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */


	/* Parameter time */


	/* Parameter flag */


	/* Parameter num */

/* 1670 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1672 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1676 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1678 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxDrives */

/* 1682 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1684 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1688 */	NdrFcShort( 0xf ),	/* 15 */
/* 1690 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1694 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1696 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1698 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1706 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 1708 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1710 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1716 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxDrives */

/* 1720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1728 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1734 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1736 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1744 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */

/* 1746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1748 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1754 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxPorts */

/* 1758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1764 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1766 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1770 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1772 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1774 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 1784 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1786 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1788 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1790 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1792 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxPorts */

/* 1796 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1798 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1804 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1806 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1810 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1812 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */

/* 1822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1824 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1830 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxSlots */

/* 1834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1842 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1846 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1848 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1850 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1858 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 1860 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1862 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1866 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1868 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxSlots */

/* 1872 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1874 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1878 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1880 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1886 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1888 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */

/* 1898 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1900 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1904 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1906 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNumUsedSlots */

/* 1910 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1912 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1916 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1918 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1922 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1924 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1926 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 1936 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1938 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1944 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFindBy */


	/* Procedure GetStatus */


	/* Procedure GetUnloadPauseTime */


	/* Procedure GetNumStagingSlots */

/* 1948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1954 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1956 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1962 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1964 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFindBy */


	/* Parameter pStatus */


	/* Parameter pTime */


	/* Parameter pNum */

/* 1974 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1976 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 1980 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1982 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFindBy */


	/* Procedure SetIsMediaCopySupported */


	/* Procedure SetStatus */


	/* Procedure SetUnloadPauseTime */


	/* Procedure SetNumStagingSlots */

/* 1986 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1988 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1994 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1998 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2000 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2002 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2010 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter findby */


	/* Parameter flag */


	/* Parameter status */


	/* Parameter time */


	/* Parameter num */

/* 2012 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2014 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 2018 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2020 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNofAvailableDrives */


	/* Procedure GetType */


	/* Procedure GetDriveSelectionPolicy */


	/* Procedure GetNumScratchCarts */

/* 2024 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2026 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2032 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2036 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2038 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2040 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pdwNofDrives */


	/* Parameter pType */


	/* Parameter pPolicy */


	/* Parameter pNum */

/* 2050 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2052 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 2056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2058 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetType */


	/* Procedure SetDriveSelectionPolicy */


	/* Procedure SetNumScratchCarts */

/* 2062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x19 ),	/* 25 */
/* 2070 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2072 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2076 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2078 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2086 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */


	/* Parameter policy */


	/* Parameter num */

/* 2088 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2090 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2094 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2096 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBlockSize */


	/* Procedure GetNumUnknownCarts */

/* 2100 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2102 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2106 */	NdrFcShort( 0x1a ),	/* 26 */
/* 2108 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2112 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2114 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2116 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBlockSize */


	/* Parameter pNum */

/* 2126 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2128 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2134 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBlockSize */


	/* Procedure SetNumUnknownCarts */

/* 2138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2144 */	NdrFcShort( 0x1b ),	/* 27 */
/* 2146 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2148 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2152 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2154 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter blockSize */


	/* Parameter num */

/* 2164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2166 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2172 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMagazineSupported */

/* 2176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2182 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2184 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2190 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2192 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2200 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2204 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsMagazineSupported */

/* 2208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2214 */	NdrFcShort( 0x1d ),	/* 29 */
/* 2216 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2222 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2224 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */

/* 2234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2236 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2242 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxCleaningMounts */

/* 2246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2252 */	NdrFcShort( 0x1e ),	/* 30 */
/* 2254 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2258 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2262 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 2272 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2274 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2280 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxCleaningMounts */

/* 2284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2290 */	NdrFcShort( 0x1f ),	/* 31 */
/* 2292 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2298 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2300 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */

/* 2310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2312 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2318 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSlotSelectionPolicy */

/* 2322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2328 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2330 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2334 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2336 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2338 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */

/* 2348 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2350 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2356 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSlotSelectionPolicy */

/* 2360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2366 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2368 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2370 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2376 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */

/* 2386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2388 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2394 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetChangers */

/* 2398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2404 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2406 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2412 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2414 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2424 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2426 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2428 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2432 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDriveClasses */

/* 2436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2442 */	NdrFcShort( 0x23 ),	/* 35 */
/* 2444 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2448 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2450 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2452 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2462 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2464 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2466 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2470 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDrives */

/* 2474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2480 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2482 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2488 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2490 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2500 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2502 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2504 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2508 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStorageSlots */

/* 2512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2518 */	NdrFcShort( 0x25 ),	/* 37 */
/* 2520 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2526 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2528 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2536 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2538 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2540 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2542 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2546 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStagingSlots */

/* 2550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2556 */	NdrFcShort( 0x26 ),	/* 38 */
/* 2558 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2564 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2566 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2576 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2578 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2580 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2584 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPorts */

/* 2588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2594 */	NdrFcShort( 0x27 ),	/* 39 */
/* 2596 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2602 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2604 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2614 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2616 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2618 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2620 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2622 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCleaningCartridges */

/* 2626 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2632 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2634 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2640 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2642 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2652 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2654 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2656 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2660 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetScratchCartridges */

/* 2664 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2670 */	NdrFcShort( 0x29 ),	/* 41 */
/* 2672 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2676 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2678 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2680 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2690 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2692 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2694 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2698 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSets */

/* 2702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2708 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2710 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2716 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2718 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 2728 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2730 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2732 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 2734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2736 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRequestDescription */


	/* Procedure GetName */


	/* Procedure GetName */

/* 2740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2748 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2754 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2756 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2758 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2760 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2764 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDesc */


	/* Parameter pName */


	/* Parameter pName */

/* 2766 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 2768 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2770 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2772 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2774 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRequestDescription */


	/* Procedure SetName */


	/* Procedure SetName */

/* 2778 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2784 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2786 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2792 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2794 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2798 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter desc */


	/* Parameter name */


	/* Parameter name */

/* 2804 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2806 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2808 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2812 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaSupported */


	/* Procedure GetMediaSupported */


	/* Procedure GetType */

/* 2816 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2822 */	NdrFcShort( 0xa ),	/* 10 */
/* 2824 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2828 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2830 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2832 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */


	/* Parameter pType */


	/* Parameter pType */

/* 2842 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2844 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 2848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2850 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMediaSupported */


	/* Procedure SetMediaSupported */


	/* Procedure SetIsExport */


	/* Procedure SetType */

/* 2854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2860 */	NdrFcShort( 0xb ),	/* 11 */
/* 2862 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2868 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2870 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2878 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */


	/* Parameter type */


	/* Parameter flag */


	/* Parameter type */

/* 2880 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2882 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 2886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2888 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCapability */

/* 2892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0xc ),	/* 12 */
/* 2900 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2904 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2906 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2908 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2916 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCapablity */

/* 2918 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2920 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2924 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2926 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Disable */


	/* Procedure SetCapability */

/* 2930 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2936 */	NdrFcShort( 0xd ),	/* 13 */
/* 2938 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2942 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2944 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2946 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter reason */


	/* Parameter capability */

/* 2956 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2958 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2964 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */


	/* Procedure GetIdleTime */

/* 2968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2974 */	NdrFcShort( 0xe ),	/* 14 */
/* 2976 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2980 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2982 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2984 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2992 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */


	/* Parameter pTime */

/* 2994 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2996 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3000 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3002 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3004 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetState */


	/* Procedure SetIdleTime */

/* 3006 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3008 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3012 */	NdrFcShort( 0xf ),	/* 15 */
/* 3014 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3016 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3018 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3020 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3022 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3030 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter state */


	/* Parameter time */

/* 3032 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3034 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3040 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStatusCode */


	/* Procedure GetMediaSetType */


	/* Procedure GetMountWaitTime */

/* 3044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3050 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3052 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3056 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3058 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3060 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResult */


	/* Parameter pType */


	/* Parameter pTime */

/* 3070 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3072 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 3076 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3078 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IncrementBytesWritten */


	/* Procedure SetStatusCode */


	/* Procedure SetMediaSetType */


	/* Procedure SetMountWaitTime */

/* 3082 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3084 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3088 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3090 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3092 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3094 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3096 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3098 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter val */


	/* Parameter result */


	/* Parameter type */


	/* Parameter time */

/* 3108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3110 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 3114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3116 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxCartridges */


	/* Procedure GetMountLimit */

/* 3120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3126 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3128 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3132 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3134 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3136 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */


	/* Parameter pLim */

/* 3146 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3148 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3154 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMaxCartridges */


	/* Procedure SetMountLimit */

/* 3158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3164 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3166 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3172 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3174 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */


	/* Parameter lim */

/* 3184 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3186 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3192 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOccupancy */


	/* Procedure GetQueuedRequests */

/* 3196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3202 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3204 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3208 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3210 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3212 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNum */


	/* Parameter pReqs */

/* 3222 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3224 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3230 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOccupancy */


	/* Procedure SetQueuedRequests */

/* 3234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3240 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3242 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3244 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3248 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3250 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter num */


	/* Parameter reqs */

/* 3260 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3262 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3268 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDrives */

/* 3272 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3278 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3280 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3286 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3288 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3296 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 3298 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3300 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3302 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 3304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3306 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCartridgeId */

/* 3310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3316 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3318 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3320 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3324 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3326 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 3336 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3338 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3340 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 3342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3344 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCartridgeId */

/* 3348 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3354 */	NdrFcShort( 0xa ),	/* 10 */
/* 3356 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3360 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3362 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3364 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCartId */

/* 3374 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3376 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3378 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 3380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3382 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPassword */


	/* Procedure GetName */

/* 3386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3392 */	NdrFcShort( 0xb ),	/* 11 */
/* 3394 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3400 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3402 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3404 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3406 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3410 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 3412 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3414 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3416 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */


	/* Return value */

/* 3418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3420 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPassword */


	/* Procedure SetName */

/* 3424 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3430 */	NdrFcShort( 0xc ),	/* 12 */
/* 3432 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3438 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3440 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3444 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3448 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter name */

/* 3450 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3452 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3454 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */


	/* Return value */

/* 3456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3458 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDescription */

/* 3462 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3468 */	NdrFcShort( 0xd ),	/* 13 */
/* 3470 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3474 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3476 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3478 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3480 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3482 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3486 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDescription */

/* 3488 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3490 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3492 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 3494 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3496 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDescription */

/* 3500 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3502 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3506 */	NdrFcShort( 0xe ),	/* 14 */
/* 3508 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3514 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3516 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3520 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3524 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3526 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3528 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3530 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 3532 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3534 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTagAndNumber */

/* 3538 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3540 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3544 */	NdrFcShort( 0xf ),	/* 15 */
/* 3546 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3550 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3552 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3554 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3556 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3558 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTag */

/* 3564 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3566 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3568 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter pNumber */

/* 3570 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3572 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3578 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTagAndNumber */

/* 3582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3588 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3590 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3592 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3596 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3598 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3602 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3606 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter tag */

/* 3608 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3610 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3612 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter number */

/* 3614 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3616 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3620 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3622 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBarcode */

/* 3626 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3632 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3634 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3640 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3642 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3644 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3646 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBarcode */

/* 3652 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3654 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3656 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 3658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3660 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOnMediaIdentifier */

/* 3664 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3670 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3672 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3674 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3676 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3678 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3680 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3682 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3684 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3688 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIdentifier */

/* 3690 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3692 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3694 */	NdrFcShort( 0xf2 ),	/* Type Offset=242 */

	/* Parameter pSize */

/* 3696 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3698 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pType */

/* 3702 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3704 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3710 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOnMediaIdentifier */

/* 3714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3720 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3722 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3724 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3728 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3730 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3734 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3738 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIdentifier */

/* 3740 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3742 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3744 */	NdrFcShort( 0x106 ),	/* Type Offset=262 */

	/* Parameter size */

/* 3746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3748 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter type */

/* 3752 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3754 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3758 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3760 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3762 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDescription */


	/* Procedure GetOnMediaLabel */

/* 3764 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3766 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3770 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3772 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3776 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3778 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3780 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3782 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3784 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3788 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDesc */


	/* Parameter pLabel */

/* 3790 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3792 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3794 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */


	/* Return value */

/* 3796 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3798 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDescription */


	/* Procedure SetOnMediaLabel */

/* 3802 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3804 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3808 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3810 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3814 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3816 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3818 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3822 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter desc */


	/* Parameter label */

/* 3828 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3830 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3832 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */


	/* Return value */

/* 3834 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3836 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsTwoSided */

/* 3840 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3846 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3848 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3854 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3856 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3864 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */

/* 3866 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3868 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3872 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3874 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsTwoSided */

/* 3878 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3884 */	NdrFcShort( 0x1d ),	/* 29 */
/* 3886 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3892 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3894 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3902 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3904 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3906 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsMounted */

/* 3910 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3912 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3916 */	NdrFcShort( 0x1e ),	/* 30 */
/* 3918 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3922 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3924 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3926 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */

/* 3936 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3938 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3944 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMounted */

/* 3948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3954 */	NdrFcShort( 0x1f ),	/* 31 */
/* 3956 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3962 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3964 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3974 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3976 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsAvailable */

/* 3980 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3982 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3986 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3988 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3992 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3994 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3996 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4004 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */

/* 4006 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4008 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4012 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4014 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsAvailable */

/* 4018 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4020 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4024 */	NdrFcShort( 0x21 ),	/* 33 */
/* 4026 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4030 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4032 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4034 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4046 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHome */

/* 4050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4056 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4058 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 4060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4062 */	NdrFcShort( 0x138 ),	/* 312 */
/* 4064 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 4066 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4074 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 4076 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4078 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pLibId */

/* 4082 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4084 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4086 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pMediaSetId */

/* 4088 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4090 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4092 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pPos */

/* 4094 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4096 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pAlt1 */

/* 4100 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4102 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pAlt2 */

/* 4106 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4108 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pAlt3 */

/* 4112 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4114 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 4116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInvert */

/* 4118 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4120 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 4122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4124 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4126 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 4128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHome */

/* 4130 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4136 */	NdrFcShort( 0x23 ),	/* 35 */
/* 4138 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 4140 */	NdrFcShort( 0x90 ),	/* 144 */
/* 4142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4144 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 4146 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 4156 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4158 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter libId */

/* 4162 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4164 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4166 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter mediaSetId */

/* 4168 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4170 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4172 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pos */

/* 4174 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4176 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt1 */

/* 4180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4182 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 4184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt2 */

/* 4186 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4188 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 4190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt3 */

/* 4192 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4194 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 4196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter invert */

/* 4198 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4200 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 4202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4206 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 4208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLocation */

/* 4210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4216 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4218 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 4220 */	NdrFcShort( 0x130 ),	/* 304 */
/* 4222 */	NdrFcShort( 0x138 ),	/* 312 */
/* 4224 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 4226 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4234 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 4236 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4238 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4240 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pLibId */

/* 4242 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4244 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4246 */	NdrFcShort( 0x116 ),	/* Type Offset=278 */

	/* Parameter pMediaSetId */

/* 4248 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4250 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4252 */	NdrFcShort( 0x116 ),	/* Type Offset=278 */

	/* Parameter pPos */

/* 4254 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4256 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4258 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt1 */

/* 4260 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4262 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4264 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt2 */

/* 4266 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4268 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4270 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt3 */

/* 4272 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4274 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 4276 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pInvert */

/* 4278 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 4280 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 4282 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Return value */

/* 4284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4286 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 4288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLocation */

/* 4290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4296 */	NdrFcShort( 0x25 ),	/* 37 */
/* 4298 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 4300 */	NdrFcShort( 0x90 ),	/* 144 */
/* 4302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4304 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 4306 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4314 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 4316 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4318 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter libId */

/* 4322 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4324 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4326 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter mediaSetId */

/* 4328 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4330 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4332 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pos */

/* 4334 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4336 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt1 */

/* 4340 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4342 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 4344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt2 */

/* 4346 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4348 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 4350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt3 */

/* 4352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4354 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 4356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter invert */

/* 4358 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4360 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 4362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4364 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4366 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 4368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDrive */

/* 4370 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4376 */	NdrFcShort( 0x26 ),	/* 38 */
/* 4378 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4384 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4386 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 4396 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4398 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4400 */	NdrFcShort( 0x11a ),	/* Type Offset=282 */

	/* Return value */

/* 4402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4404 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDrive */

/* 4408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4414 */	NdrFcShort( 0x27 ),	/* 39 */
/* 4416 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4420 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4422 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4424 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4432 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 4434 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4436 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4438 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 4440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4442 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMailStop */

/* 4446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4452 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4454 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4460 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4462 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4464 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4466 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4470 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMailStop */

/* 4472 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 4474 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4476 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 4478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4480 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMailStop */

/* 4484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4490 */	NdrFcShort( 0x29 ),	/* 41 */
/* 4492 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4498 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4500 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4504 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4508 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mailStop */

/* 4510 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4512 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4514 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 4516 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4518 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetInfo */

/* 4522 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4528 */	NdrFcShort( 0x2a ),	/* 42 */
/* 4530 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4534 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4536 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 4538 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4540 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 4548 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 4550 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4552 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 4554 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4556 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4558 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4562 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetInfo */

/* 4566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4572 */	NdrFcShort( 0x2b ),	/* 43 */
/* 4574 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4576 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4580 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4582 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4586 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 4592 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4594 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4596 */	NdrFcShort( 0x136 ),	/* Type Offset=310 */

	/* Parameter size */

/* 4598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4600 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4602 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4606 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOwnerClassId */

/* 4610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4616 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4618 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4622 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4624 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4626 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 4636 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4638 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4640 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4644 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOwnerClassId */

/* 4648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4654 */	NdrFcShort( 0x2d ),	/* 45 */
/* 4656 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4658 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4660 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4662 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4664 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 4674 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4676 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4678 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4682 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPartitions */

/* 4686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4692 */	NdrFcShort( 0x2e ),	/* 46 */
/* 4694 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4700 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4702 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 4712 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4714 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4716 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Return value */

/* 4718 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4720 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVerifierClass */

/* 4724 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4726 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4730 */	NdrFcShort( 0x2f ),	/* 47 */
/* 4732 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4736 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4738 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4740 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4748 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 4750 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4752 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4754 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4758 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetVerifierClass */

/* 4762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4768 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4770 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4772 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4776 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4778 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4786 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 4788 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4790 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4792 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4794 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4796 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPortalClass */

/* 4800 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4802 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4806 */	NdrFcShort( 0x31 ),	/* 49 */
/* 4808 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4812 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4814 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4816 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4824 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 4826 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4828 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4830 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4834 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPortalClass */

/* 4838 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4844 */	NdrFcShort( 0x32 ),	/* 50 */
/* 4846 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4848 */	NdrFcShort( 0x30 ),	/* 48 */
/* 4850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4852 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4854 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 4864 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 4866 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4868 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 4870 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4872 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Mount */

/* 4876 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4878 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4882 */	NdrFcShort( 0x33 ),	/* 51 */
/* 4884 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4886 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4890 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 4892 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4900 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppDrive */

/* 4902 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4904 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4906 */	NdrFcShort( 0x11a ),	/* Type Offset=282 */

	/* Parameter options */

/* 4908 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4910 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 4914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4916 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4922 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Dismount */

/* 4926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4932 */	NdrFcShort( 0x34 ),	/* 52 */
/* 4934 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4940 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4942 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4950 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter options */

/* 4952 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4954 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4958 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4960 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4962 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Home */

/* 4964 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4966 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4970 */	NdrFcShort( 0x35 ),	/* 53 */
/* 4972 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4978 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4980 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter options */

/* 4990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4992 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4998 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateDataMover */

/* 5002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5008 */	NdrFcShort( 0x36 ),	/* 54 */
/* 5010 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5016 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5018 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5026 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 5028 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5030 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5032 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 5034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5036 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReleaseDataMover */

/* 5040 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5046 */	NdrFcShort( 0x37 ),	/* 55 */
/* 5048 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5052 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5054 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5056 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5064 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 5066 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5068 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5070 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Return value */

/* 5072 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5074 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadDataCache */

/* 5078 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5080 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5084 */	NdrFcShort( 0x38 ),	/* 56 */
/* 5086 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5088 */	NdrFcShort( 0x1c ),	/* 28 */
/* 5090 */	NdrFcShort( 0x6c ),	/* 108 */
/* 5092 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 5094 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 5096 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5102 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCache */

/* 5104 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 5106 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5108 */	NdrFcShort( 0x146 ),	/* Type Offset=326 */

	/* Parameter pSize */

/* 5110 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 5112 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUsed */

/* 5116 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5118 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pStartPBA */

/* 5122 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 5124 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5126 */	NdrFcShort( 0x156 ),	/* Type Offset=342 */

	/* Return value */

/* 5128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5130 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveDataCache */

/* 5134 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5140 */	NdrFcShort( 0x39 ),	/* 57 */
/* 5142 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5144 */	NdrFcShort( 0x28 ),	/* 40 */
/* 5146 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5148 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5150 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5154 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5158 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCache */

/* 5160 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5162 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5164 */	NdrFcShort( 0x160 ),	/* Type Offset=352 */

	/* Parameter size */

/* 5166 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5168 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter used */

/* 5172 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5174 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter startPBA */

/* 5178 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5180 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5182 */	NdrFcShort( 0x156 ),	/* Type Offset=342 */

	/* Return value */

/* 5184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5186 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManagedBy */

/* 5190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5196 */	NdrFcShort( 0x3a ),	/* 58 */
/* 5198 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5202 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5204 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5206 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pManagedBy */

/* 5216 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5218 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5224 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetManagedBy */

/* 5228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5234 */	NdrFcShort( 0x3b ),	/* 59 */
/* 5236 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5244 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter managedBy */

/* 5254 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5256 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5262 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsFixedBlockSize */

/* 5266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5272 */	NdrFcShort( 0x3c ),	/* 60 */
/* 5274 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5280 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5282 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5290 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5292 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5294 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetElementNo */


	/* Procedure GetPartNo */


	/* Procedure GetRequestNo */


	/* Procedure GetMountReference */

/* 5298 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5304 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5306 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5310 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5312 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5314 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pElementNo */


	/* Parameter pPartNo */


	/* Parameter pRequestNo */


	/* Parameter pRefs */

/* 5324 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5326 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5332 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */


	/* Procedure AcquireDevice */


	/* Procedure IsInMagazine */


	/* Procedure ResetMountReference */

/* 5336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5344 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5350 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5352 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5360 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5362 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5364 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceType */


	/* Procedure SetObjectType */


	/* Procedure SetIsDone */


	/* Procedure ReleaseMountReference */

/* 5368 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5374 */	NdrFcShort( 0xa ),	/* 10 */
/* 5376 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5380 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5382 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5384 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5392 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */


	/* Parameter type */


	/* Parameter flag */


	/* Parameter options */

/* 5394 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5396 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 5400 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5402 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateDataMover */

/* 5406 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5408 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5412 */	NdrFcShort( 0xc ),	/* 12 */
/* 5414 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5418 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5420 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5422 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 5432 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5434 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5436 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 5438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5440 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReleaseDataMover */

/* 5444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5450 */	NdrFcShort( 0xd ),	/* 13 */
/* 5452 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5458 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5460 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5468 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 5470 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5472 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5474 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Return value */

/* 5476 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5478 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Eject */

/* 5482 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5488 */	NdrFcShort( 0xe ),	/* 14 */
/* 5490 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5494 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5496 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5498 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5508 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5510 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLargestFreeSpace */

/* 5514 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5516 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5520 */	NdrFcShort( 0xf ),	/* 15 */
/* 5522 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5526 */	NdrFcShort( 0x50 ),	/* 80 */
/* 5528 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5530 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5538 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter freeSpace */

/* 5540 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5542 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5544 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter capacity */

/* 5546 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5548 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5550 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5552 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5554 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnloadNow */

/* 5558 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5564 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5566 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5572 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5574 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 5584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5586 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsInMagazine */

/* 5590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5596 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5598 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5604 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5606 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5614 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter flag */

/* 5616 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5618 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5622 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5624 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMagazineAndCell */

/* 5628 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5634 */	NdrFcShort( 0x9 ),	/* 9 */
/* 5636 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5640 */	NdrFcShort( 0x40 ),	/* 64 */
/* 5642 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5644 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5652 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMag */

/* 5654 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5656 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCell */

/* 5660 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5662 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5668 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBytesRead2 */


	/* Procedure SetMagazineAndCell */

/* 5672 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5678 */	NdrFcShort( 0xa ),	/* 10 */
/* 5680 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5682 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5684 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5686 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5688 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5696 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter readHi */


	/* Parameter mag */

/* 5698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5700 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter readLo */


	/* Parameter cell */

/* 5704 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5706 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5712 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHome */

/* 5716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5722 */	NdrFcShort( 0xa ),	/* 10 */
/* 5724 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5728 */	NdrFcShort( 0x5c ),	/* 92 */
/* 5730 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 5732 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5740 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 5742 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5744 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPos */

/* 5748 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5750 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInvert */

/* 5754 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5756 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5760 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5762 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5764 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHome */

/* 5766 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5768 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5772 */	NdrFcShort( 0xb ),	/* 11 */
/* 5774 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5776 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5778 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5780 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 5782 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5790 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 5792 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5794 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pos */

/* 5798 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5800 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter invert */

/* 5804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5806 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5812 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsOccupied */


	/* Procedure CanRotate */

/* 5816 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5822 */	NdrFcShort( 0xf ),	/* 15 */
/* 5824 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5830 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 5832 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 5842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5844 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOperation */

/* 5848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5854 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5856 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5862 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5864 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 5866 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5868 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOperation */

/* 5874 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 5876 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5878 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 5880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5882 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOperation */

/* 5886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5892 */	NdrFcShort( 0x11 ),	/* 17 */
/* 5894 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5900 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5902 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 5904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5906 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOperation */

/* 5912 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5914 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5916 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 5918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5920 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPercentComplete */

/* 5924 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5930 */	NdrFcShort( 0x12 ),	/* 18 */
/* 5932 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5936 */	NdrFcShort( 0x21 ),	/* 33 */
/* 5938 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5940 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPercent */

/* 5950 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5952 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5954 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 5956 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5958 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPercentComplete */

/* 5962 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5964 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5968 */	NdrFcShort( 0x13 ),	/* 19 */
/* 5970 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5972 */	NdrFcShort( 0x5 ),	/* 5 */
/* 5974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5976 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5978 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5986 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter percent */

/* 5988 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5990 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5992 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 5994 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5996 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Suspend */


	/* Procedure TestReady */

/* 6000 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6006 */	NdrFcShort( 0x14 ),	/* 20 */
/* 6008 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6014 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6016 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 6026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6028 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ImportCartridge */

/* 6032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6038 */	NdrFcShort( 0x15 ),	/* 21 */
/* 6040 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6046 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6048 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 6058 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 6060 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6062 */	NdrFcShort( 0x170 ),	/* Type Offset=368 */

	/* Return value */

/* 6064 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6066 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportCartridge */

/* 6070 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6072 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6076 */	NdrFcShort( 0x16 ),	/* 22 */
/* 6078 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6084 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6086 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6094 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 6096 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 6098 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6100 */	NdrFcShort( 0x170 ),	/* Type Offset=368 */

	/* Return value */

/* 6102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6104 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MoveCartridge */

/* 6108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6114 */	NdrFcShort( 0x17 ),	/* 23 */
/* 6116 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6122 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6124 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSrcCart */

/* 6134 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6136 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6138 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter pDestElmt */

/* 6140 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6142 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6144 */	NdrFcShort( 0x174 ),	/* Type Offset=372 */

	/* Return value */

/* 6146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6148 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HomeCartridge */

/* 6152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6158 */	NdrFcShort( 0x18 ),	/* 24 */
/* 6160 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6166 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6168 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 6178 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6180 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6182 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 6184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6186 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetParameters */

/* 6190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6196 */	NdrFcShort( 0x3 ),	/* 3 */
/* 6198 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6200 */	NdrFcShort( 0x1c ),	/* 28 */
/* 6202 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6204 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 6206 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 6208 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 6216 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 6218 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pParms */

/* 6222 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 6224 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6226 */	NdrFcShort( 0x1be ),	/* Type Offset=446 */

	/* Return value */

/* 6228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6230 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetProductData */

/* 6234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6240 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6242 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6244 */	NdrFcShort( 0x1c ),	/* 28 */
/* 6246 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6248 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 6250 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 6252 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSize */

/* 6260 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 6262 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pData */

/* 6266 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 6268 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6270 */	NdrFcShort( 0x1fa ),	/* Type Offset=506 */

	/* Return value */

/* 6272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6274 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RezeroUnit */

/* 6278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6284 */	NdrFcShort( 0x5 ),	/* 5 */
/* 6286 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6292 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6294 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6306 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeElementStatus */

/* 6310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6316 */	NdrFcShort( 0x6 ),	/* 6 */
/* 6318 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6324 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6326 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter elementList */

/* 6336 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6338 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6340 */	NdrFcShort( 0x216 ),	/* Type Offset=534 */

	/* Parameter barCodeScan */

/* 6342 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6344 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6350 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAccess */

/* 6354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6360 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6362 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6368 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6370 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 6380 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6382 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6384 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter control */

/* 6386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6388 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6394 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetElementStatus */

/* 6398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6404 */	NdrFcShort( 0x9 ),	/* 9 */
/* 6406 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 6408 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6410 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6412 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 6414 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 6416 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter elementList */

/* 6424 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6426 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6428 */	NdrFcShort( 0x216 ),	/* Type Offset=534 */

	/* Parameter volumeTagInfo */

/* 6430 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6432 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSize */

/* 6436 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 6438 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pElementInformation */

/* 6442 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 6444 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6446 */	NdrFcShort( 0x270 ),	/* Type Offset=624 */

	/* Return value */

/* 6448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6450 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 6452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExchangeMedium */

/* 6454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6460 */	NdrFcShort( 0xa ),	/* 10 */
/* 6462 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 6464 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6466 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6468 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 6470 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter source */

/* 6480 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6482 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6484 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter destination1 */

/* 6486 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6488 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6490 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter destination2 */

/* 6492 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6494 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6496 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter flip1 */

/* 6498 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6500 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter flip2 */

/* 6504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6506 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6512 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 6514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MoveMedium */

/* 6516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6522 */	NdrFcShort( 0xb ),	/* 11 */
/* 6524 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6526 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6530 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 6532 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter source */

/* 6542 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6544 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6546 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter destination */

/* 6548 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6550 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6552 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter flip */

/* 6554 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6556 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6562 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Position */

/* 6566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6572 */	NdrFcShort( 0xc ),	/* 12 */
/* 6574 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6580 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6582 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter destination */

/* 6592 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6594 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6596 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter flip */

/* 6598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6600 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6606 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryVolumeTag */

/* 6610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6616 */	NdrFcShort( 0xd ),	/* 13 */
/* 6618 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 6620 */	NdrFcShort( 0x3d ),	/* 61 */
/* 6622 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6624 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 6626 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 6628 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter startingElement */

/* 6636 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6638 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6640 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter actionCode */

/* 6642 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6644 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVolumeIDTemplate */

/* 6648 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6650 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6652 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter pNumberOfElementsReturned */

/* 6654 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 6656 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pElementInformation */

/* 6660 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 6662 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6664 */	NdrFcShort( 0x270 ),	/* Type Offset=624 */

	/* Return value */

/* 6666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6668 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 6670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceName */


	/* Procedure GetDescription */

/* 6672 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6678 */	NdrFcShort( 0x7 ),	/* 7 */
/* 6680 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6684 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6686 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6688 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 6690 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6692 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6696 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pDesc */

/* 6698 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 6700 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6702 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */


	/* Return value */

/* 6704 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6706 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceName */


	/* Procedure SetDescription */

/* 6710 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6712 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6716 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6718 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6724 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6726 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6730 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6734 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */


	/* Parameter desc */

/* 6736 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6738 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6740 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */


	/* Return value */

/* 6742 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6744 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAttributes */


	/* Procedure SetIsImport */

/* 6748 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6750 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6754 */	NdrFcShort( 0x9 ),	/* 9 */
/* 6756 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6758 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6760 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6762 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6764 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter attr */


	/* Parameter flag */

/* 6774 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6776 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 6780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6782 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsImport */

/* 6786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6792 */	NdrFcShort( 0xa ),	/* 10 */
/* 6794 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6798 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6800 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6802 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6810 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 6812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6814 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetInfo */

/* 6818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6824 */	NdrFcShort( 0xc ),	/* 12 */
/* 6826 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6830 */	NdrFcShort( 0x22 ),	/* 34 */
/* 6832 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 6834 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 6836 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 6844 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 6846 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6848 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 6850 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6852 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6854 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6856 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6858 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetInfo */

/* 6862 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6864 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6868 */	NdrFcShort( 0xd ),	/* 13 */
/* 6870 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6872 */	NdrFcShort( 0x6 ),	/* 6 */
/* 6874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6876 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6878 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6882 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 6888 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6890 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6892 */	NdrFcShort( 0x136 ),	/* Type Offset=310 */

	/* Parameter size */

/* 6894 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6896 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6898 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6902 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOwnerClassId */

/* 6906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6912 */	NdrFcShort( 0xe ),	/* 14 */
/* 6914 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6918 */	NdrFcShort( 0x4c ),	/* 76 */
/* 6920 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6922 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 6932 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 6934 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6936 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 6938 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6940 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOwnerClassId */

/* 6944 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6946 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6950 */	NdrFcShort( 0xf ),	/* 15 */
/* 6952 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6954 */	NdrFcShort( 0x30 ),	/* 48 */
/* 6956 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6958 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6960 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6968 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 6970 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 6972 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6974 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 6976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6978 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMediaCopySupported */

/* 6982 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6988 */	NdrFcShort( 0x16 ),	/* 22 */
/* 6990 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6996 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 6998 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 7008 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7010 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Allocate */

/* 7014 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7016 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7020 */	NdrFcShort( 0x18 ),	/* 24 */
/* 7022 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 7024 */	NdrFcShort( 0x70 ),	/* 112 */
/* 7026 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7028 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 7030 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7034 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7038 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prevSideId */

/* 7040 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 7042 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7044 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pFreeSpace */

/* 7046 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 7048 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7050 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter displayName */

/* 7052 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7054 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7056 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter options */

/* 7058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7060 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCart */

/* 7064 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7066 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 7068 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 7070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7072 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 7074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Deallocate */

/* 7076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7082 */	NdrFcShort( 0x19 ),	/* 25 */
/* 7084 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7090 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7092 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 7102 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7104 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7106 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 7108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7110 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOperation */

/* 7114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7120 */	NdrFcShort( 0xc ),	/* 12 */
/* 7122 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7128 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7130 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 7132 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7134 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOperation */

/* 7140 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 7142 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7144 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 7146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7148 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOperation */

/* 7152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7158 */	NdrFcShort( 0xd ),	/* 13 */
/* 7160 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7166 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7168 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7172 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter operation */

/* 7178 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7180 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7182 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 7184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7186 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPercentComplete */

/* 7190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7196 */	NdrFcShort( 0xe ),	/* 14 */
/* 7198 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7202 */	NdrFcShort( 0x21 ),	/* 33 */
/* 7204 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7206 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPercent */

/* 7216 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7218 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7220 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 7222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7224 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPercentComplete */

/* 7228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7234 */	NdrFcShort( 0xf ),	/* 15 */
/* 7236 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7238 */	NdrFcShort( 0x5 ),	/* 5 */
/* 7240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7244 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter percent */

/* 7254 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7256 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7258 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 7260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7262 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAttributes */

/* 7266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7274 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7278 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7280 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7282 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7290 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAttr */

/* 7292 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7294 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7298 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7300 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 7304 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7310 */	NdrFcShort( 0xa ),	/* 10 */
/* 7312 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7316 */	NdrFcShort( 0x22 ),	/* 34 */
/* 7318 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 7320 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 7322 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIdent */

/* 7330 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 7332 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7334 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 7336 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7338 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7340 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 7342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7344 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIdentifier */

/* 7348 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7354 */	NdrFcShort( 0xb ),	/* 11 */
/* 7356 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7358 */	NdrFcShort( 0x6 ),	/* 6 */
/* 7360 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7362 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 7364 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7368 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIdent */

/* 7374 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7376 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7378 */	NdrFcShort( 0x136 ),	/* Type Offset=310 */

	/* Parameter size */

/* 7380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7382 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7384 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 7386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7388 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadOnMediaId */

/* 7392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7398 */	NdrFcShort( 0xd ),	/* 13 */
/* 7400 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7404 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7406 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 7408 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 7410 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 7418 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 7420 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7422 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 7424 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7426 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7432 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceType */


	/* Procedure GetObjectType */

/* 7436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7442 */	NdrFcShort( 0x9 ),	/* 9 */
/* 7444 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7448 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7450 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7452 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */


	/* Parameter pType */

/* 7462 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7464 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 7468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7470 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 7474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7480 */	NdrFcShort( 0x12 ),	/* 18 */
/* 7482 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7488 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7490 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 7492 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7494 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 7500 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 7502 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7504 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 7506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7508 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 7512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7518 */	NdrFcShort( 0x13 ),	/* 19 */
/* 7520 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7526 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7528 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7532 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7536 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 7538 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7540 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7542 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Return value */

/* 7544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7546 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLocation */

/* 7550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7556 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7558 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 7560 */	NdrFcShort( 0x130 ),	/* 304 */
/* 7562 */	NdrFcShort( 0x138 ),	/* 312 */
/* 7564 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 7566 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 7576 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7578 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7580 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pLibId */

/* 7582 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7584 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7586 */	NdrFcShort( 0x116 ),	/* Type Offset=278 */

	/* Parameter pMediaSetId */

/* 7588 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7590 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7592 */	NdrFcShort( 0x116 ),	/* Type Offset=278 */

	/* Parameter pPos */

/* 7594 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7596 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7598 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt1 */

/* 7600 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7602 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 7604 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt2 */

/* 7606 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7608 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 7610 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pAlt3 */

/* 7612 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7614 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 7616 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Parameter pInvert */

/* 7618 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 7620 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 7622 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Return value */

/* 7624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7626 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 7628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLocation */

/* 7630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7636 */	NdrFcShort( 0x9 ),	/* 9 */
/* 7638 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
/* 7640 */	NdrFcShort( 0x90 ),	/* 144 */
/* 7642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7644 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x9,		/* 9 */
/* 7646 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 7656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7658 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter libId */

/* 7662 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 7664 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7666 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter mediaSetId */

/* 7668 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 7670 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7672 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pos */

/* 7674 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7676 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 7678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt1 */

/* 7680 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7682 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 7684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt2 */

/* 7686 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7688 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 7690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter alt3 */

/* 7692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7694 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 7696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter invert */

/* 7698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7700 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 7702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7704 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7706 */	NdrFcShort( 0x58 ),	/* ia64 Stack size/offset = 88 */
/* 7708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCartridge */

/* 7710 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7712 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7716 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7718 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7724 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7726 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7734 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 7736 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7738 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7740 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 7742 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7744 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCartridge */

/* 7748 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7750 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7754 */	NdrFcShort( 0x11 ),	/* 17 */
/* 7756 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7760 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7762 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7764 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */

/* 7774 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7776 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7778 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 7780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7782 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOwnerClassId */

/* 7786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7792 */	NdrFcShort( 0x12 ),	/* 18 */
/* 7794 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7798 */	NdrFcShort( 0x4c ),	/* 76 */
/* 7800 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7802 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7810 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 7812 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 7814 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7816 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 7818 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7820 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7822 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOwnerClassId */

/* 7824 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7826 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7830 */	NdrFcShort( 0x13 ),	/* 19 */
/* 7832 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7834 */	NdrFcShort( 0x30 ),	/* 48 */
/* 7836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7838 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7840 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7848 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 7850 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 7852 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7854 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 7856 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7858 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUsedSpace2 */


	/* Procedure GetAccessCounters */

/* 7862 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7864 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7868 */	NdrFcShort( 0x14 ),	/* 20 */
/* 7870 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7874 */	NdrFcShort( 0x40 ),	/* 64 */
/* 7876 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 7878 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pUsedHi */


	/* Parameter pGets */

/* 7888 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7890 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUsedLo */


	/* Parameter pPuts */

/* 7894 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7896 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 7900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7902 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Resume */


	/* Procedure ResetAccessCounters */

/* 7906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7912 */	NdrFcShort( 0x15 ),	/* 21 */
/* 7914 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7920 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 7922 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 7932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7934 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCoordinates */

/* 7938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7944 */	NdrFcShort( 0x16 ),	/* 22 */
/* 7946 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 7948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7950 */	NdrFcShort( 0x5c ),	/* 92 */
/* 7952 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 7954 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7962 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pX1 */

/* 7964 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7966 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 7968 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pX2 */

/* 7970 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7972 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 7974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pX3 */

/* 7976 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7978 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 7980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7984 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 7986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCoordinates */

/* 7988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7994 */	NdrFcShort( 0x17 ),	/* 23 */
/* 7996 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 7998 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8002 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 8004 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x1 */

/* 8014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8016 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter x2 */

/* 8020 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8022 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter x3 */

/* 8026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8028 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8034 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceInfo */

/* 8038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8044 */	NdrFcShort( 0xb ),	/* 11 */
/* 8046 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8050 */	NdrFcShort( 0x22 ),	/* 34 */
/* 8052 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 8054 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 8056 */	NdrFcShort( 0x1 ),	/* 1 */
/* 8058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8062 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 8064 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 8066 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8068 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 8070 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8072 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8074 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 8076 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8078 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceInfo */

/* 8082 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8084 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8088 */	NdrFcShort( 0xc ),	/* 12 */
/* 8090 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8092 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8094 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8096 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8098 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 8100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8102 */	NdrFcShort( 0x1 ),	/* 1 */
/* 8104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 8108 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 8110 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8112 */	NdrFcShort( 0x136 ),	/* Type Offset=310 */

	/* Parameter size */

/* 8114 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8116 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8118 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 8120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8122 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceAddress */

/* 8126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8132 */	NdrFcShort( 0xd ),	/* 13 */
/* 8134 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 8136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8138 */	NdrFcShort( 0x6c ),	/* 108 */
/* 8140 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 8142 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPort */

/* 8152 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8154 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8156 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pBus */

/* 8158 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8160 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8162 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pId */

/* 8164 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8166 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8168 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pLun */

/* 8170 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8172 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8174 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 8176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8178 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 8180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDeviceAddress */

/* 8182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8188 */	NdrFcShort( 0xe ),	/* 14 */
/* 8190 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 8192 */	NdrFcShort( 0x14 ),	/* 20 */
/* 8194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8196 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 8198 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter port */

/* 8208 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8210 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8212 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter bus */

/* 8214 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8216 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8218 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter id */

/* 8220 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8222 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8224 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter lun */

/* 8226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8228 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8230 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 8232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8234 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 8236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMountCounters */

/* 8238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8244 */	NdrFcShort( 0x7 ),	/* 7 */
/* 8246 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8250 */	NdrFcShort( 0x40 ),	/* 64 */
/* 8252 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8254 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pReads */

/* 8264 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8266 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pWrites */

/* 8270 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8272 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8276 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8278 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBytesRead2 */

/* 8282 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8284 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8290 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8294 */	NdrFcShort( 0x40 ),	/* 64 */
/* 8296 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8298 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pReadHi */

/* 8308 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8310 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pReadLo */

/* 8314 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8316 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8320 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8322 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBytesRead */

/* 8326 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8332 */	NdrFcShort( 0x9 ),	/* 9 */
/* 8334 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8338 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8340 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8342 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRead */

/* 8352 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8354 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8356 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8360 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBytesRead */

/* 8364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8370 */	NdrFcShort( 0xb ),	/* 11 */
/* 8372 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8374 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8378 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8380 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter read */

/* 8390 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8392 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8394 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8398 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBytesWritten2 */

/* 8402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8408 */	NdrFcShort( 0xd ),	/* 13 */
/* 8410 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8414 */	NdrFcShort( 0x40 ),	/* 64 */
/* 8416 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8418 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWriteHi */

/* 8428 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8430 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pWriteLo */

/* 8434 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8436 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8442 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBytesWritten */

/* 8446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8452 */	NdrFcShort( 0xe ),	/* 14 */
/* 8454 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8458 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8460 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8462 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8470 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWritten */

/* 8472 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8474 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8476 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8480 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBytesWritten2 */

/* 8484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8490 */	NdrFcShort( 0xf ),	/* 15 */
/* 8492 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8494 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8498 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8500 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8508 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter writeHi */

/* 8510 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8512 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter writeLo */

/* 8516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8518 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8524 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBytesWritten */

/* 8528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8534 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8536 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8538 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8540 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8542 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8544 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8552 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter written */

/* 8554 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8556 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8558 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8562 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCapacity2 */

/* 8566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8572 */	NdrFcShort( 0x12 ),	/* 18 */
/* 8574 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8578 */	NdrFcShort( 0x40 ),	/* 64 */
/* 8580 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8582 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCapHi */

/* 8592 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8594 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCapLo */

/* 8598 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8600 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8606 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCapacity */

/* 8610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8616 */	NdrFcShort( 0x13 ),	/* 19 */
/* 8618 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8622 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8624 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8626 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCap */

/* 8636 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8638 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8640 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8644 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUsedSpace */

/* 8648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8654 */	NdrFcShort( 0x15 ),	/* 21 */
/* 8656 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8660 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8662 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8664 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pUsed */

/* 8674 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8676 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8678 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8682 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLargestFreeSpace2 */

/* 8686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8692 */	NdrFcShort( 0x16 ),	/* 22 */
/* 8694 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8698 */	NdrFcShort( 0x40 ),	/* 64 */
/* 8700 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 8702 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFreeHi */

/* 8712 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8714 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pFreeLo */

/* 8718 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8720 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8726 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLargestFreeSpace */

/* 8730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8736 */	NdrFcShort( 0x17 ),	/* 23 */
/* 8738 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8742 */	NdrFcShort( 0x2c ),	/* 44 */
/* 8744 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8746 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFree */

/* 8756 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8758 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8760 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8762 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8764 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCapacity */

/* 8768 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8770 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8774 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8776 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8778 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8782 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8784 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8792 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cap */

/* 8794 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8796 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8798 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8802 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUsedSpace */

/* 8806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8812 */	NdrFcShort( 0x19 ),	/* 25 */
/* 8814 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8816 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8820 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8822 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter used */

/* 8832 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8834 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8836 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8838 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8840 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8842 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFreeSpace */

/* 8844 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8846 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8850 */	NdrFcShort( 0x1a ),	/* 26 */
/* 8852 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8854 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8858 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 8860 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8868 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter free */

/* 8870 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8872 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8874 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8878 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetCounters */

/* 8882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8888 */	NdrFcShort( 0x1b ),	/* 27 */
/* 8890 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8896 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 8898 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8906 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 8908 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8910 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetInfo */

/* 8914 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8916 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8920 */	NdrFcShort( 0xd ),	/* 13 */
/* 8922 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8926 */	NdrFcShort( 0x22 ),	/* 34 */
/* 8928 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 8930 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 8932 */	NdrFcShort( 0x1 ),	/* 1 */
/* 8934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8938 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 8940 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 8942 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8944 */	NdrFcShort( 0x122 ),	/* Type Offset=290 */

	/* Parameter pSize */

/* 8946 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8948 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8950 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 8952 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8954 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 8956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetInfo */

/* 8958 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8960 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8964 */	NdrFcShort( 0xe ),	/* 14 */
/* 8966 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 8968 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8970 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8972 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 8974 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 8976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8978 */	NdrFcShort( 0x1 ),	/* 1 */
/* 8980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 8984 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 8986 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 8988 */	NdrFcShort( 0x136 ),	/* Type Offset=310 */

	/* Parameter size */

/* 8990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8992 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 8994 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 8996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8998 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVerifierClass */

/* 9002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9008 */	NdrFcShort( 0xf ),	/* 15 */
/* 9010 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9014 */	NdrFcShort( 0x4c ),	/* 76 */
/* 9016 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9018 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9026 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 9028 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 9030 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9032 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 9034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9036 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetVerifierClass */

/* 9040 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9046 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9048 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9050 */	NdrFcShort( 0x30 ),	/* 48 */
/* 9052 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9054 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9056 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9064 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 9066 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 9068 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9070 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 9072 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9074 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPortalClass */

/* 9078 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9080 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9084 */	NdrFcShort( 0x11 ),	/* 17 */
/* 9086 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9090 */	NdrFcShort( 0x4c ),	/* 76 */
/* 9092 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9094 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9102 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassId */

/* 9104 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 9106 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9108 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 9110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9112 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPortalClass */

/* 9116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9122 */	NdrFcShort( 0x12 ),	/* 18 */
/* 9124 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9126 */	NdrFcShort( 0x30 ),	/* 48 */
/* 9128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9130 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9132 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter classId */

/* 9142 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 9144 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9146 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 9148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9150 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Allocate */

/* 9154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9160 */	NdrFcShort( 0x9 ),	/* 9 */
/* 9162 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 9164 */	NdrFcShort( 0xb4 ),	/* 180 */
/* 9166 */	NdrFcShort( 0x2c ),	/* 44 */
/* 9168 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 9170 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 9172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9174 */	NdrFcShort( 0x1 ),	/* 1 */
/* 9176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromMediaSet */

/* 9180 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9182 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9184 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter prevSideId */

/* 9186 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9188 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9190 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pFreeSpace */

/* 9192 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 9194 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9196 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter displayName */

/* 9198 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9200 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9202 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter options */

/* 9204 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9206 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 9208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppCart */

/* 9210 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9212 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 9214 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 9216 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9218 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 9220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Mount */

/* 9222 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9224 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9228 */	NdrFcShort( 0xa ),	/* 10 */
/* 9230 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 9232 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9236 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 9238 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9246 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 9248 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9250 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9252 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter ppDrive */

/* 9254 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 9256 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9258 */	NdrFcShort( 0x94 ),	/* Type Offset=148 */

	/* Parameter options */

/* 9260 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9262 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter threadId */

/* 9266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9268 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9274 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 9276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Dismount */

/* 9278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9284 */	NdrFcShort( 0xb ),	/* 11 */
/* 9286 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9292 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 9294 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 9304 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9306 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9308 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter options */

/* 9310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9312 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9318 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Deallocate */

/* 9322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9328 */	NdrFcShort( 0xc ),	/* 12 */
/* 9330 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9336 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9338 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 9348 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9350 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9352 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */

/* 9354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9356 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DismountAll */

/* 9360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9366 */	NdrFcShort( 0xd ),	/* 13 */
/* 9368 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9370 */	NdrFcShort( 0x4c ),	/* 76 */
/* 9372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 9376 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromMediaSet */

/* 9386 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9388 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9390 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter options */

/* 9392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9394 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9398 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9400 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisableAndEject */

/* 9404 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9410 */	NdrFcShort( 0xe ),	/* 14 */
/* 9412 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9418 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 9420 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9428 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCart */

/* 9430 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9432 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9434 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Parameter options */

/* 9436 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9438 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9444 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateOmidInfo */

/* 9448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9454 */	NdrFcShort( 0xf ),	/* 15 */
/* 9456 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 9458 */	NdrFcShort( 0x54 ),	/* 84 */
/* 9460 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9462 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 9464 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 9466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9468 */	NdrFcShort( 0x1 ),	/* 1 */
/* 9470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 9474 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9476 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9478 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pBuffer */

/* 9480 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 9482 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9484 */	NdrFcShort( 0x28e ),	/* Type Offset=654 */

	/* Parameter size */

/* 9486 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9488 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter type */

/* 9492 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9494 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9500 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 9502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBlockSize */

/* 9504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9510 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9512 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9514 */	NdrFcShort( 0x44 ),	/* 68 */
/* 9516 */	NdrFcShort( 0x24 ),	/* 36 */
/* 9518 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 9520 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9528 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 9530 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9532 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9534 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pBlockSize */

/* 9536 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9538 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9542 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9544 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBlockSize */

/* 9548 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9554 */	NdrFcShort( 0x11 ),	/* 17 */
/* 9556 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9558 */	NdrFcShort( 0x4c ),	/* 76 */
/* 9560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9562 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 9564 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9572 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 9574 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9576 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9578 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter blockSize */

/* 9580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9582 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9586 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9588 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExportDatabase */

/* 9592 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9594 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9598 */	NdrFcShort( 0x12 ),	/* 18 */
/* 9600 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9604 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9606 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 9608 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9616 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 9618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9620 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCartridge */

/* 9624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9630 */	NdrFcShort( 0x13 ),	/* 19 */
/* 9632 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9634 */	NdrFcShort( 0x44 ),	/* 68 */
/* 9636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9638 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 9640 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9648 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cartId */

/* 9650 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9652 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9654 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter ppCartridge */

/* 9656 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 9658 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9660 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 9662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9664 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMediaCopySupported */

/* 9668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9674 */	NdrFcShort( 0x16 ),	/* 22 */
/* 9676 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9678 */	NdrFcShort( 0x44 ),	/* 68 */
/* 9680 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9682 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 9684 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9692 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mediaPoolId */

/* 9694 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9696 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9698 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 9700 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9702 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateDrive */

/* 9706 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9708 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9712 */	NdrFcShort( 0x17 ),	/* 23 */
/* 9714 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9718 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9720 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 9722 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9730 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDrive */

/* 9732 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 9734 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9736 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Return value */

/* 9738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9740 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckSecondSide */

/* 9744 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9750 */	NdrFcShort( 0x19 ),	/* 25 */
/* 9752 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 9754 */	NdrFcShort( 0x44 ),	/* 68 */
/* 9756 */	NdrFcShort( 0x68 ),	/* 104 */
/* 9758 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 9760 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter firstSideId */

/* 9770 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9772 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9774 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pbValid */

/* 9776 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9778 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSecondSideId */

/* 9782 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 9784 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9786 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Return value */

/* 9788 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9790 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMaxMediaCapacity */

/* 9794 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9796 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9800 */	NdrFcShort( 0x1a ),	/* 26 */
/* 9802 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9804 */	NdrFcShort( 0x44 ),	/* 68 */
/* 9806 */	NdrFcShort( 0x2c ),	/* 44 */
/* 9808 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 9810 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9818 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromMediaSet */

/* 9820 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9822 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9824 */	NdrFcShort( 0x72 ),	/* Type Offset=114 */

	/* Parameter pMaxCapacity */

/* 9826 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 9828 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9830 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 9832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9834 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessObjectStatusChange */

/* 9838 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9844 */	NdrFcShort( 0x3 ),	/* 3 */
/* 9846 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 9848 */	NdrFcShort( 0x18 ),	/* 24 */
/* 9850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9852 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 9854 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 9856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isEnabled */

/* 9864 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9866 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 9868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter state */

/* 9870 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9872 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 9874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter statusCode */

/* 9876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9878 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 9880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9882 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9884 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 9886 */	0x8,		/* FC_LONG */
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
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  8 */	NdrFcLong( 0x70674820 ),	/* 1885816864 */
/* 12 */	NdrFcShort( 0x67df ),	/* 26591 */
/* 14 */	NdrFcShort( 0x4c2f ),	/* 19503 */
/* 16 */	0x9d,		/* 157 */
			0xf4,		/* 244 */
/* 18 */	0x1a,		/* 26 */
			0xf0,		/* 240 */
/* 20 */	0xad,		/* 173 */
			0x42,		/* 66 */
/* 22 */	0x27,		/* 39 */
			0xff,		/* 255 */
/* 24 */	
			0x11, 0x0,	/* FC_RP */
/* 26 */	NdrFcShort( 0x1c ),	/* Offset= 28 (54) */
/* 28 */	
			0x13, 0x0,	/* FC_OP */
/* 30 */	NdrFcShort( 0xe ),	/* Offset= 14 (44) */
/* 32 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 34 */	NdrFcShort( 0x2 ),	/* 2 */
/* 36 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 38 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 40 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 42 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 44 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 46 */	NdrFcShort( 0x8 ),	/* 8 */
/* 48 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (32) */
/* 50 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 52 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 54 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x8 ),	/* 8 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0xffde ),	/* Offset= -34 (28) */
/* 64 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 66 */	NdrFcShort( 0x2 ),	/* Offset= 2 (68) */
/* 68 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 70 */	NdrFcLong( 0xa5b69200 ),	/* -1514761728 */
/* 74 */	NdrFcShort( 0x214b ),	/* 8523 */
/* 76 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 78 */	0x81,		/* 129 */
			0xb7,		/* 183 */
/* 80 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 82 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 84 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 86 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 88 */	NdrFcLong( 0x534f26cb ),	/* 1397696203 */
/* 92 */	NdrFcShort( 0x4f8a ),	/* 20362 */
/* 94 */	NdrFcShort( 0x4fee ),	/* 20462 */
/* 96 */	0x8d,		/* 141 */
			0x7e,		/* 126 */
/* 98 */	0x5c,		/* 92 */
			0x35,		/* 53 */
/* 100 */	0xa0,		/* 160 */
			0xa0,		/* 160 */
/* 102 */	0xcc,		/* 204 */
			0x38,		/* 56 */
/* 104 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 106 */	NdrFcShort( 0x8 ),	/* Offset= 8 (114) */
/* 108 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 112 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 114 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 116 */	NdrFcShort( 0x10 ),	/* 16 */
/* 118 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 120 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 122 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (108) */
			0x5b,		/* FC_END */
/* 126 */	
			0x11, 0x0,	/* FC_RP */
/* 128 */	NdrFcShort( 0xfff2 ),	/* Offset= -14 (114) */
/* 130 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 132 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 134 */	
			0x12, 0x0,	/* FC_UP */
/* 136 */	NdrFcShort( 0xffa4 ),	/* Offset= -92 (44) */
/* 138 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (134) */
/* 148 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 150 */	NdrFcShort( 0x2 ),	/* Offset= 2 (152) */
/* 152 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 154 */	NdrFcLong( 0xaa46e0ce ),	/* -1438195506 */
/* 158 */	NdrFcShort( 0xf1f8 ),	/* -3592 */
/* 160 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 162 */	0xa8,		/* 168 */
			0x1e,		/* 30 */
/* 164 */	0x0,		/* 0 */
			0xc0,		/* 192 */
/* 166 */	0x4f,		/* 79 */
			0xb9,		/* 185 */
/* 168 */	0x60,		/* 96 */
			0xed,		/* 237 */
/* 170 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 172 */	NdrFcShort( 0xffaa ),	/* Offset= -86 (86) */
/* 174 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 176 */	NdrFcShort( 0x2 ),	/* Offset= 2 (178) */
/* 178 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 180 */	NdrFcLong( 0x54b6c009 ),	/* 1421262857 */
/* 184 */	NdrFcShort( 0xc05a ),	/* -16294 */
/* 186 */	NdrFcShort( 0x4f16 ),	/* 20246 */
/* 188 */	0xab,		/* 171 */
			0x55,		/* 85 */
/* 190 */	0x71,		/* 113 */
			0x6a,		/* 106 */
/* 192 */	0x1a,		/* 26 */
			0x1b,		/* 27 */
/* 194 */	0xe4,		/* 228 */
			0x47,		/* 71 */
/* 196 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 198 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 200 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 202 */	NdrFcShort( 0x2 ),	/* Offset= 2 (204) */
/* 204 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 206 */	NdrFcLong( 0xfe37fb02 ),	/* -29885694 */
/* 210 */	NdrFcShort( 0x3729 ),	/* 14121 */
/* 212 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 214 */	0x8c,		/* 140 */
			0xf4,		/* 244 */
/* 216 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 218 */	0xc9,		/* 201 */
			0x19,		/* 25 */
/* 220 */	0x4,		/* 4 */
			0x59,		/* 89 */
/* 222 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 224 */	NdrFcShort( 0x2 ),	/* Offset= 2 (226) */
/* 226 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 228 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 230 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 232 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 234 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 236 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 238 */	
			0x11, 0x0,	/* FC_RP */
/* 240 */	NdrFcShort( 0x2 ),	/* Offset= 2 (242) */
/* 242 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 244 */	NdrFcShort( 0x1 ),	/* 1 */
/* 246 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x54,		/* FC_DEREFERENCE */
/* 248 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 250 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 252 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 254 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 256 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 258 */	
			0x11, 0x0,	/* FC_RP */
/* 260 */	NdrFcShort( 0x2 ),	/* Offset= 2 (262) */
/* 262 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 264 */	NdrFcShort( 0x1 ),	/* 1 */
/* 266 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 268 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 270 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 272 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 274 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 276 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 278 */	
			0x12, 0x0,	/* FC_UP */
/* 280 */	NdrFcShort( 0xff5a ),	/* Offset= -166 (114) */
/* 282 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 284 */	NdrFcShort( 0xff7c ),	/* Offset= -132 (152) */
/* 286 */	
			0x11, 0x0,	/* FC_RP */
/* 288 */	NdrFcShort( 0x2 ),	/* Offset= 2 (290) */
/* 290 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 292 */	NdrFcShort( 0x1 ),	/* 1 */
/* 294 */	0x40,		/* Corr desc:  constant, val=128 */
			0x0,		/* 0 */
/* 296 */	NdrFcShort( 0x80 ),	/* 128 */
/* 298 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 300 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 302 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 304 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 306 */	
			0x11, 0x0,	/* FC_RP */
/* 308 */	NdrFcShort( 0x2 ),	/* Offset= 2 (310) */
/* 310 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 312 */	NdrFcShort( 0x1 ),	/* 1 */
/* 314 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 316 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 318 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 320 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 322 */	
			0x11, 0x0,	/* FC_RP */
/* 324 */	NdrFcShort( 0x2 ),	/* Offset= 2 (326) */
/* 326 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 328 */	NdrFcShort( 0x1 ),	/* 1 */
/* 330 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 332 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 334 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 336 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 338 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 340 */	NdrFcShort( 0x2 ),	/* Offset= 2 (342) */
/* 342 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 346 */	0xb,		/* FC_HYPER */
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
/* 358 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 360 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 362 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 364 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 366 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 368 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 370 */	NdrFcShort( 0xfee4 ),	/* Offset= -284 (86) */
/* 372 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 384 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 386 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 388 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 390 */	
			0x11, 0x0,	/* FC_RP */
/* 392 */	NdrFcShort( 0x36 ),	/* Offset= 54 (446) */
/* 394 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 396 */	NdrFcShort( 0x2 ),	/* 2 */
/* 398 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 400 */	
			0x1d,		/* FC_SMFARRAY */
			0x3,		/* 3 */
/* 402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 404 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 406 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 408 */	NdrFcShort( 0x3c ),	/* 60 */
/* 410 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 412 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 414 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 416 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 418 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 420 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 422 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 424 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 426 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 428 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 430 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 432 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 434 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 436 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 438 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (394) */
/* 440 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 442 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (400) */
/* 444 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 446 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 448 */	NdrFcShort( 0x3c ),	/* 60 */
/* 450 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 452 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 454 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 456 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 458 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (406) */
/* 460 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 462 */	
			0x11, 0x0,	/* FC_RP */
/* 464 */	NdrFcShort( 0x2a ),	/* Offset= 42 (506) */
/* 466 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 468 */	NdrFcShort( 0x10 ),	/* 16 */
/* 470 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 472 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 474 */	NdrFcShort( 0x4 ),	/* 4 */
/* 476 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 478 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 480 */	NdrFcShort( 0x20 ),	/* 32 */
/* 482 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 484 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 486 */	NdrFcShort( 0x3d ),	/* 61 */
/* 488 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 490 */	NdrFcShort( 0xfe82 ),	/* Offset= -382 (108) */
/* 492 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 494 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (466) */
/* 496 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 498 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (472) */
/* 500 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 502 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (478) */
/* 504 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 506 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 508 */	NdrFcShort( 0x3d ),	/* 61 */
/* 510 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 512 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 514 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 516 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 518 */	NdrFcShort( 0xffde ),	/* Offset= -34 (484) */
/* 520 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 522 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x0 ),	/* Offset= 0 (528) */
/* 530 */	0xd,		/* FC_ENUM16 */
			0x8,		/* FC_LONG */
/* 532 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 534 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 536 */	NdrFcShort( 0xc ),	/* 12 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x0 ),	/* Offset= 0 (540) */
/* 542 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 544 */	NdrFcShort( 0xffea ),	/* Offset= -22 (522) */
/* 546 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 548 */	
			0x11, 0x0,	/* FC_RP */
/* 550 */	NdrFcShort( 0x4a ),	/* Offset= 74 (624) */
/* 552 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 554 */	NdrFcShort( 0x24 ),	/* 36 */
/* 556 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 558 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 560 */	NdrFcShort( 0x64 ),	/* 100 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* Offset= 0 (564) */
/* 566 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 568 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (522) */
/* 570 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 572 */	NdrFcShort( 0xffce ),	/* Offset= -50 (522) */
/* 574 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 576 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 578 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 580 */	0x0,		/* 0 */
			NdrFcShort( 0xffe3 ),	/* Offset= -29 (552) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 584 */	0x0,		/* 0 */
			NdrFcShort( 0xffdf ),	/* Offset= -33 (552) */
			0x5b,		/* FC_END */
/* 588 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 590 */	NdrFcShort( 0x1 ),	/* 1 */
/* 592 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 596 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 598 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 602 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 604 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 606 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (558) */
/* 608 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 610 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 612 */	NdrFcShort( 0x68 ),	/* 104 */
/* 614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0x0 ),	/* Offset= 0 (616) */
/* 618 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 620 */	0x0,		/* 0 */
			NdrFcShort( 0xffdf ),	/* Offset= -33 (588) */
			0x5b,		/* FC_END */
/* 624 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 630 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 632 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 634 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 638 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 640 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 642 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (610) */
/* 644 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 646 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 648 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 650 */	
			0x11, 0x0,	/* FC_RP */
/* 652 */	NdrFcShort( 0x2 ),	/* Offset= 2 (654) */
/* 654 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 656 */	NdrFcShort( 0x1 ),	/* 1 */
/* 658 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 660 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 662 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 664 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */

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



/* Standard interface: __MIDL_itf_rmsint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IRmsServer, ver. 0.0,
   GUID={0xDDA2FBE0,0x33E4,0x4221,{0xA2,0xC8,0xD9,0x07,0x11,0x03,0x97,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsServer_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    32,
    70,
    102,
    140,
    172,
    204,
    236,
    274,
    312,
    350,
    388,
    426,
    464,
    502,
    540,
    578,
    616,
    648,
    680,
    772,
    840,
    884,
    964,
    1008,
    1052,
    1096,
    1158,
    1202,
    1246,
    1284,
    1334
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(39) _IRmsServerProxyVtbl = 
{
    &IRmsServer_ProxyInfo,
    &IID_IRmsServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::IsReady */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::ChangeState */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::IsNTMSInstalled */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetNTMS */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::InitializeInAnotherThread */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::Initialize */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::SaveAll */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetServerName */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetActiveCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetDataMovers */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::SetActiveCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetLibraries */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetMediaSets */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetRequests */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetClients */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetUnconfiguredDevices */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::ScanForDevices */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::ScanForDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::MountScratchCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::MountCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::DismountCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::DuplicateCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::RecycleCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::FindLibraryById */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::FindCartridgeById */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::CreateObject */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetNofAvailableDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::FindCartridgeStatusById */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::IsMultipleSidedMedia */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::CheckSecondSide */ ,
    (void *) (INT_PTR) -1 /* IRmsServer::GetMaxMediaCapacity */
};


static const PRPC_STUB_FUNCTION IRmsServer_table[] =
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
    NdrStubCall2,
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

CInterfaceStubVtbl _IRmsServerStubVtbl =
{
    &IID_IRmsServer,
    &IRmsServer_ServerInfo,
    39,
    &IRmsServer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsLibrary, ver. 0.0,
   GUID={0xFE37FB02,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsLibrary_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1378,
    1416,
    1454,
    1492,
    1530,
    1568,
    1606,
    1644,
    1682,
    1720,
    1758,
    1796,
    1834,
    1872,
    1910,
    1948,
    1986,
    2024,
    2062,
    2100,
    2138,
    2176,
    2208,
    2246,
    2284,
    2322,
    2360,
    2398,
    2436,
    2474,
    2512,
    2550,
    2588,
    2626,
    2664,
    2702
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsLibrary_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsLibrary_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsLibrary_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsLibrary_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(43) _IRmsLibraryProxyVtbl = 
{
    &IRmsLibrary_ProxyInfo,
    &IID_IRmsLibrary,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetLibraryId */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetLibraryId */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMaxChangers */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMaxChangers */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMaxDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMaxDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMaxPorts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMaxPorts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMaxSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMaxSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetNumUsedSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetNumStagingSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetNumStagingSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetNumScratchCarts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetNumScratchCarts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetNumUnknownCarts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetNumUnknownCarts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::IsMagazineSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetIsMagazineSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMaxCleaningMounts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetMaxCleaningMounts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetSlotSelectionPolicy */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::SetSlotSelectionPolicy */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetChangers */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetDriveClasses */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetStorageSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetStagingSlots */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetPorts */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetCleaningCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetScratchCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsLibrary::GetMediaSets */
};


static const PRPC_STUB_FUNCTION IRmsLibrary_table[] =
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
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
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

CInterfaceStubVtbl _IRmsLibraryStubVtbl =
{
    &IID_IRmsLibrary,
    &IRmsLibrary_ServerInfo,
    43,
    &IRmsLibrary_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsDriveClass, ver. 0.0,
   GUID={0xFE37FB03,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsDriveClass_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1378,
    2740,
    2778,
    2816,
    2854,
    2892,
    2930,
    2968,
    3006,
    3044,
    3082,
    3120,
    3158,
    3196,
    3234,
    1948,
    1986,
    2024,
    2062,
    3272
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsDriveClass_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsDriveClass_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsDriveClass_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsDriveClass_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IRmsDriveClassProxyVtbl = 
{
    &IRmsDriveClass_ProxyInfo,
    &IID_IRmsDriveClass,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetDriveClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetType */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetType */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetCapability */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetCapability */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetIdleTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetIdleTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetMountWaitTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetMountWaitTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetMountLimit */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetMountLimit */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetQueuedRequests */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetQueuedRequests */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetUnloadPauseTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetUnloadPauseTime */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetDriveSelectionPolicy */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::SetDriveSelectionPolicy */ ,
    (void *) (INT_PTR) -1 /* IRmsDriveClass::GetDrives */
};


static const PRPC_STUB_FUNCTION IRmsDriveClass_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsDriveClassStubVtbl =
{
    &IID_IRmsDriveClass,
    &IRmsDriveClass_ServerInfo,
    27,
    &IRmsDriveClass_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsCartridge, ver. 0.0,
   GUID={0x534F26CB,0x4F8A,0x4FEE,{0x8D,0x7E,0x5C,0x35,0xA0,0xA0,0xCC,0x38}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsCartridge_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1378,
    1416,
    3310,
    3348,
    3386,
    3424,
    3462,
    3500,
    3538,
    3582,
    3626,
    3664,
    3714,
    3764,
    3802,
    1948,
    1986,
    2024,
    2062,
    2100,
    2138,
    3840,
    3878,
    3910,
    3948,
    3980,
    4018,
    4050,
    4130,
    4210,
    4290,
    4370,
    4408,
    4446,
    4484,
    4522,
    4566,
    4610,
    4648,
    4686,
    4724,
    4762,
    4800,
    4838,
    4876,
    4926,
    4964,
    5002,
    5040,
    5078,
    5134,
    5190,
    5228,
    5266
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsCartridge_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsCartridge_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsCartridge_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsCartridge_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(61) _IRmsCartridgeProxyVtbl = 
{
    &IRmsCartridge_ProxyInfo,
    &IID_IRmsCartridge,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetMediaSetId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetMediaSetId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetCartridgeId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetCartridgeId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetTagAndNumber */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetTagAndNumber */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetBarcode */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetOnMediaIdentifier */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetOnMediaIdentifier */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetOnMediaLabel */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetOnMediaLabel */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetStatus */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetStatus */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetType */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetType */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetBlockSize */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetBlockSize */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetIsTwoSided */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::IsTwoSided */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetIsMounted */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::IsMounted */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetIsAvailable */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::IsAvailable */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetHome */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetHome */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetLocation */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetLocation */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetDrive */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetDrive */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetMailStop */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetMailStop */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetPartitions */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetVerifierClass */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetVerifierClass */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetPortalClass */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetPortalClass */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::Mount */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::Dismount */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::Home */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::CreateDataMover */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::ReleaseDataMover */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::LoadDataCache */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SaveDataCache */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::GetManagedBy */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::SetManagedBy */ ,
    (void *) (INT_PTR) -1 /* IRmsCartridge::IsFixedBlockSize */
};


static const PRPC_STUB_FUNCTION IRmsCartridge_table[] =
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
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
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

CInterfaceStubVtbl _IRmsCartridgeStubVtbl =
{
    &IID_IRmsCartridge,
    &IRmsCartridge_ServerInfo,
    61,
    &IRmsCartridge_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsDrive, ver. 0.0,
   GUID={0xAA46E0CE,0xF1F8,0x11D2,{0xA8,0x1E,0x00,0xC0,0x4F,0xB9,0x60,0xED}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsDrive_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5298,
    5336,
    70,
    5368,
    140,
    5406,
    5444,
    5482,
    5514,
    5558
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsDrive_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsDrive_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsDrive_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsDrive_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IRmsDriveProxyVtbl = 
{
    &IRmsDrive_ProxyInfo,
    &IID_IRmsDrive,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::GetMountReference */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::ResetMountReference */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::AddMountReference */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::ReleaseMountReference */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::SelectForMount */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::CreateDataMover */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::ReleaseDataMover */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::Eject */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::GetLargestFreeSpace */ ,
    (void *) (INT_PTR) -1 /* IRmsDrive::UnloadNow */
};


static const PRPC_STUB_FUNCTION IRmsDrive_table[] =
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

CInterfaceStubVtbl _IRmsDriveStubVtbl =
{
    &IID_IRmsDrive,
    &IRmsDrive_ServerInfo,
    17,
    &IRmsDrive_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsStorageSlot, ver. 0.0,
   GUID={0xFE37FB06,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsStorageSlot_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5590,
    5336,
    5628,
    5672
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsStorageSlot_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsStorageSlot_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsStorageSlot_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsStorageSlot_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IRmsStorageSlotProxyVtbl = 
{
    &IRmsStorageSlot_ProxyInfo,
    &IID_IRmsStorageSlot,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageSlot::SetIsInMagazine */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageSlot::IsInMagazine */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageSlot::GetMagazineAndCell */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageSlot::SetMagazineAndCell */
};


static const PRPC_STUB_FUNCTION IRmsStorageSlot_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsStorageSlotStubVtbl =
{
    &IID_IRmsStorageSlot,
    &IRmsStorageSlot_ServerInfo,
    11,
    &IRmsStorageSlot_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsMediumChanger, ver. 0.0,
   GUID={0xFE37FB07,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsMediumChanger_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    5336,
    70,
    5716,
    5766,
    1568,
    204,
    1644,
    5816,
    5848,
    5886,
    5924,
    5962,
    6000,
    6032,
    6070,
    6108,
    6152
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsMediumChanger_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsMediumChanger_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsMediumChanger_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsMediumChanger_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(25) _IRmsMediumChangerProxyVtbl = 
{
    &IRmsMediumChanger_ProxyInfo,
    &IID_IRmsMediumChanger,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::Initialize */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::AcquireDevice */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::ReleaseDevice */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::GetHome */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::SetHome */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::SetAutomatic */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::IsAutomatic */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::SetCanRotate */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::CanRotate */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::GetOperation */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::SetOperation */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::GetPercentComplete */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::SetPercentComplete */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::TestReady */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::ImportCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::ExportCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::MoveCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsMediumChanger::HomeCartridge */
};


static const PRPC_STUB_FUNCTION IRmsMediumChanger_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsMediumChangerStubVtbl =
{
    &IID_IRmsMediumChanger,
    &IRmsMediumChanger_ServerInfo,
    25,
    &IRmsMediumChanger_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsMoveMedia, ver. 0.0,
   GUID={0xFE37FB18,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsMoveMedia_FormatStringOffsetTable[] =
    {
    6190,
    6234,
    6278,
    6310,
    0,
    6354,
    6398,
    6454,
    6516,
    6566,
    6610
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsMoveMedia_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsMoveMedia_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsMoveMedia_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsMoveMedia_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IRmsMoveMediaProxyVtbl = 
{
    &IRmsMoveMedia_ProxyInfo,
    &IID_IRmsMoveMedia,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::GetParameters */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::GetProductData */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::RezeroUnit */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::InitializeElementStatus */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::Status */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::SetAccess */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::GetElementStatus */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::ExchangeMedium */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::MoveMedium */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::Position */ ,
    (void *) (INT_PTR) -1 /* IRmsMoveMedia::QueryVolumeTag */
};

const CInterfaceStubVtbl _IRmsMoveMediaStubVtbl =
{
    &IID_IRmsMoveMedia,
    &IRmsMoveMedia_ServerInfo,
    14,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRmsIEPort, ver. 0.0,
   GUID={0xFE37FB08,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsIEPort_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6672,
    6710,
    6748,
    6786,
    2854,
    172,
    1606,
    1644
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsIEPort_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsIEPort_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsIEPort_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsIEPort_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IRmsIEPortProxyVtbl = 
{
    &IRmsIEPort_ProxyInfo,
    &IID_IRmsIEPort,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::GetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::SetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::SetIsImport */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::IsImport */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::SetIsExport */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::IsExport */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::GetWaitTime */ ,
    (void *) (INT_PTR) -1 /* IRmsIEPort::SetWaitTime */
};


static const PRPC_STUB_FUNCTION IRmsIEPort_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsIEPortStubVtbl =
{
    &IID_IRmsIEPort,
    &IRmsIEPort_ServerInfo,
    15,
    &IRmsIEPort_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsMediaSet, ver. 0.0,
   GUID={0xBC9E7125,0x0976,0x4773,{0x9E,0x43,0x72,0x04,0x7F,0xED,0x47,0x8C}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsMediaSet_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1378,
    2740,
    2778,
    2816,
    2854,
    6818,
    6862,
    6906,
    6944,
    3044,
    3082,
    3120,
    3158,
    3196,
    3234,
    6982,
    1986,
    7014,
    7076
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsMediaSet_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsMediaSet_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsMediaSet_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsMediaSet_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IRmsMediaSetProxyVtbl = 
{
    &IRmsMediaSet_ProxyInfo,
    &IID_IRmsMediaSet,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetMediaSetId */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetMediaSetType */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetMediaSetType */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetMaxCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetMaxCartridges */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::GetOccupancy */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetOccupancy */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::IsMediaCopySupported */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::SetIsMediaCopySupported */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::Allocate */ ,
    (void *) (INT_PTR) -1 /* IRmsMediaSet::Deallocate */
};


static const PRPC_STUB_FUNCTION IRmsMediaSet_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsMediaSetStubVtbl =
{
    &IID_IRmsMediaSet,
    &IRmsMediaSet_ServerInfo,
    26,
    &IRmsMediaSet_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsRequest, ver. 0.0,
   GUID={0xFE37FB10,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsRequest_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5298,
    2740,
    2778,
    5368,
    140,
    7114,
    7152,
    7190,
    7228
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsRequest_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsRequest_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsRequest_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsRequest_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IRmsRequestProxyVtbl = 
{
    &IRmsRequest_ProxyInfo,
    &IID_IRmsRequest,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::GetRequestNo */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::GetRequestDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::SetRequestDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::SetIsDone */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::IsDone */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::GetOperation */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::SetOperation */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::GetPercentComplete */ ,
    (void *) (INT_PTR) -1 /* IRmsRequest::SetPercentComplete */
};


static const PRPC_STUB_FUNCTION IRmsRequest_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsRequestStubVtbl =
{
    &IID_IRmsRequest,
    &IRmsRequest_ServerInfo,
    16,
    &IRmsRequest_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsPartition, ver. 0.0,
   GUID={0xFE37FB11,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsPartition_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5298,
    7266,
    6748,
    7304,
    7348,
    172,
    7392
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsPartition_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsPartition_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsPartition_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsPartition_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IRmsPartitionProxyVtbl = 
{
    &IRmsPartition_ProxyInfo,
    &IID_IRmsPartition,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::GetPartNo */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::GetAttributes */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::SetAttributes */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::SetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::VerifyIdentifier */ ,
    (void *) (INT_PTR) -1 /* IRmsPartition::ReadOnMediaId */
};


static const PRPC_STUB_FUNCTION IRmsPartition_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsPartitionStubVtbl =
{
    &IID_IRmsPartition,
    &IRmsPartition_ServerInfo,
    14,
    &IRmsPartition_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsComObject, ver. 0.0,
   GUID={0xFE37FB12,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsComObject_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1378,
    1416,
    7436,
    5368,
    140,
    172,
    2930,
    2968,
    3006,
    3044,
    3082,
    7474,
    7512,
    3764,
    3802,
    1948,
    1986
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsComObject_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsComObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsComObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsComObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IRmsComObjectProxyVtbl = 
{
    &IRmsComObject_ProxyInfo,
    &IID_IRmsComObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetObjectId */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetObjectId */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetObjectType */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetObjectType */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::IsEnabled */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::Enable */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::Disable */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetState */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetState */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetStatusCode */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetStatusCode */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetDescription */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::GetFindBy */ ,
    (void *) (INT_PTR) -1 /* IRmsComObject::SetFindBy */
};


static const PRPC_STUB_FUNCTION IRmsComObject_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsComObjectStubVtbl =
{
    &IID_IRmsComObject,
    &IRmsComObject_ServerInfo,
    24,
    &IRmsComObject_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsChangerElement, ver. 0.0,
   GUID={0xFE37FB13,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsChangerElement_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    5298,
    7550,
    7630,
    2816,
    2854,
    1568,
    204,
    1644,
    5816,
    7710,
    7748,
    7786,
    7824,
    7862,
    7906,
    7938,
    7988
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsChangerElement_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsChangerElement_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsChangerElement_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsChangerElement_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IRmsChangerElementProxyVtbl = 
{
    &IRmsChangerElement_ProxyInfo,
    &IID_IRmsChangerElement,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetElementNo */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetLocation */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetLocation */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetMediaSupported */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetIsStorage */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::IsStorage */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetIsOccupied */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::IsOccupied */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetAccessCounters */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::ResetAccessCounters */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::GetCoordinates */ ,
    (void *) (INT_PTR) -1 /* IRmsChangerElement::SetCoordinates */
};


static const PRPC_STUB_FUNCTION IRmsChangerElement_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsChangerElementStubVtbl =
{
    &IID_IRmsChangerElement,
    &IRmsChangerElement_ServerInfo,
    24,
    &IRmsChangerElement_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsDevice, ver. 0.0,
   GUID={0xFE37FB14,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsDevice_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    6672,
    6710,
    7436,
    5368,
    8038,
    8082,
    8126,
    8182
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsDevice_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsDevice_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsDevice_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsDevice_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IRmsDeviceProxyVtbl = 
{
    &IRmsDevice_ProxyInfo,
    &IID_IRmsDevice,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::GetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::SetDeviceName */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::GetDeviceType */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::SetDeviceType */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::GetDeviceInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::SetDeviceInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::GetDeviceAddress */ ,
    (void *) (INT_PTR) -1 /* IRmsDevice::SetDeviceAddress */
};


static const PRPC_STUB_FUNCTION IRmsDevice_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsDeviceStubVtbl =
{
    &IID_IRmsDevice,
    &IRmsDevice_ServerInfo,
    15,
    &IRmsDevice_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsStorageInfo, ver. 0.0,
   GUID={0xFE37FB15,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsStorageInfo_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    8238,
    8282,
    8326,
    5672,
    8364,
    1568,
    8402,
    8446,
    8484,
    8528,
    3082,
    8566,
    8610,
    7862,
    8648,
    8686,
    8730,
    8768,
    8806,
    8844,
    8882
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsStorageInfo_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsStorageInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsStorageInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsStorageInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(28) _IRmsStorageInfoProxyVtbl = 
{
    &IRmsStorageInfo_ProxyInfo,
    &IID_IRmsStorageInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetMountCounters */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetBytesRead2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetBytesRead */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetBytesRead2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetBytesRead */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::IncrementBytesRead */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetBytesWritten2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetBytesWritten */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetBytesWritten2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetBytesWritten */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::IncrementBytesWritten */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetCapacity2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetCapacity */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetUsedSpace2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetUsedSpace */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetLargestFreeSpace2 */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::GetLargestFreeSpace */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetCapacity */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetUsedSpace */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::SetFreeSpace */ ,
    (void *) (INT_PTR) -1 /* IRmsStorageInfo::ResetCounters */
};


static const PRPC_STUB_FUNCTION IRmsStorageInfo_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsStorageInfoStubVtbl =
{
    &IID_IRmsStorageInfo,
    &IRmsStorageInfo_ServerInfo,
    28,
    &IRmsStorageInfo_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsClient, ver. 0.0,
   GUID={0xFE37FB16,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsClient_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1378,
    1416,
    1454,
    1492,
    3386,
    3424,
    8914,
    8958,
    9002,
    9040,
    9078,
    9116
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsClient_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsClient_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsClient_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsClient_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IRmsClientProxyVtbl = 
{
    &IRmsClient_ProxyInfo,
    &IID_IRmsClient,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetOwnerClassId */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetName */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetName */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetPassword */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetPassword */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetVerifierClass */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetVerifierClass */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::GetPortalClass */ ,
    (void *) (INT_PTR) -1 /* IRmsClient::SetPortalClass */
};


static const PRPC_STUB_FUNCTION IRmsClient_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsClientStubVtbl =
{
    &IID_IRmsClient,
    &IRmsClient_ServerInfo,
    19,
    &IRmsClient_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsNTMS, ver. 0.0,
   GUID={0x70674820,0x67DF,0x4C2F,{0x9D,0xF4,0x1A,0xF0,0xAD,0x42,0x27,0xFF}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsNTMS_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    5336,
    9154,
    9222,
    9278,
    9322,
    9360,
    9404,
    9448,
    9504,
    9548,
    9592,
    9624,
    6000,
    7906,
    9668,
    9706,
    2024,
    9744,
    9794
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsNTMS_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsNTMS_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsNTMS_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsNTMS_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IRmsNTMSProxyVtbl = 
{
    &IRmsNTMS_ProxyInfo,
    &IID_IRmsNTMS,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::IsInstalled */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Initialize */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Allocate */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Mount */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Dismount */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Deallocate */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::DismountAll */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::DisableAndEject */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::UpdateOmidInfo */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::GetBlockSize */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::SetBlockSize */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::ExportDatabase */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::FindCartridge */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Suspend */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::Resume */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::IsMediaCopySupported */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::UpdateDrive */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::GetNofAvailableDrives */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::CheckSecondSide */ ,
    (void *) (INT_PTR) -1 /* IRmsNTMS::GetMaxMediaCapacity */
};


static const PRPC_STUB_FUNCTION IRmsNTMS_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IRmsNTMSStubVtbl =
{
    &IID_IRmsNTMS,
    &IRmsNTMS_ServerInfo,
    27,
    &IRmsNTMS_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IRmsSinkEveryEvent, ver. 0.0,
   GUID={0xFE37FB20,0x3729,0x11D0,{0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59}} */

#pragma code_seg(".orpc")
static const unsigned short IRmsSinkEveryEvent_FormatStringOffsetTable[] =
    {
    9838
    };

static const MIDL_STUBLESS_PROXY_INFO IRmsSinkEveryEvent_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IRmsSinkEveryEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRmsSinkEveryEvent_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IRmsSinkEveryEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IRmsSinkEveryEventProxyVtbl = 
{
    &IRmsSinkEveryEvent_ProxyInfo,
    &IID_IRmsSinkEveryEvent,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRmsSinkEveryEvent::ProcessObjectStatusChange */
};

const CInterfaceStubVtbl _IRmsSinkEveryEventStubVtbl =
{
    &IID_IRmsSinkEveryEvent,
    &IRmsSinkEveryEvent_ServerInfo,
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
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _rmsint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IRmsLibraryProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsDriveClassProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsStorageSlotProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsMediumChangerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsIEPortProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsRequestProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsPartitionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsComObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsChangerElementProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsDeviceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsStorageInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsClientProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsMoveMediaProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsNTMSProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsSinkEveryEventProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsMediaSetProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsCartridgeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsDriveProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRmsServerProxyVtbl,
    0
};

const CInterfaceStubVtbl * _rmsint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IRmsLibraryStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsDriveClassStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsStorageSlotStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsMediumChangerStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsIEPortStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsRequestStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsPartitionStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsComObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsChangerElementStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsDeviceStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsStorageInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsClientStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsMoveMediaStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsNTMSStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsSinkEveryEventStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsMediaSetStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsCartridgeStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsDriveStubVtbl,
    ( CInterfaceStubVtbl *) &_IRmsServerStubVtbl,
    0
};

PCInterfaceName const _rmsint_InterfaceNamesList[] = 
{
    "IRmsLibrary",
    "IRmsDriveClass",
    "IRmsStorageSlot",
    "IRmsMediumChanger",
    "IRmsIEPort",
    "IRmsRequest",
    "IRmsPartition",
    "IRmsComObject",
    "IRmsChangerElement",
    "IRmsDevice",
    "IRmsStorageInfo",
    "IRmsClient",
    "IRmsMoveMedia",
    "IRmsNTMS",
    "IRmsSinkEveryEvent",
    "IRmsMediaSet",
    "IRmsCartridge",
    "IRmsDrive",
    "IRmsServer",
    0
};

const IID *  _rmsint_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0,
    &IID_IDispatch,
    0,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _rmsint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _rmsint, pIID, n)

int __stdcall _rmsint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _rmsint, 19, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _rmsint, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _rmsint, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _rmsint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _rmsint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _rmsint, 19, *pIndex )
    
}

const ExtendedProxyFileInfo rmsint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _rmsint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _rmsint_StubVtblList,
    (const PCInterfaceName * ) & _rmsint_InterfaceNamesList,
    (const IID ** ) & _rmsint_BaseIIDList,
    & _rmsint_IID_Lookup, 
    19,
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

