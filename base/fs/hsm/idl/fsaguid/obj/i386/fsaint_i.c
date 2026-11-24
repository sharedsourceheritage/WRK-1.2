

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IFsaFilter,0x5FFF1640,0xD487,0x11d1,0xA9,0xF5,0x00,0xA0,0x24,0x89,0x03,0xEA);


MIDL_DEFINE_GUID(IID, IID_IFsaFilterClient,0x560E5A02,0xDEDE,0x11d1,0xA9,0xF5,0x00,0xA0,0x24,0x89,0x03,0xEA);


MIDL_DEFINE_GUID(IID, IID_IFsaFilterRecall,0x5E176F27,0x6F53,0x4C84,0xB9,0x35,0x92,0x59,0x29,0x76,0x69,0xB0);


MIDL_DEFINE_GUID(IID, IID_IFsaResource,0x172F71CD,0xA452,0x4005,0x8E,0x3E,0x7B,0xCE,0xAE,0x12,0x4D,0x53);


MIDL_DEFINE_GUID(IID, IID_IFsaScanItem,0x087e7ed0,0x727a,0x11d2,0x9c,0xd3,0x00,0xa0,0xc9,0x11,0x81,0x02);


MIDL_DEFINE_GUID(IID, IID_IFsaServer,0xC49D553D,0xCA2B,0x4482,0xA4,0x04,0xCD,0x4B,0x6B,0x44,0xEA,0xE4);


MIDL_DEFINE_GUID(IID, IID_IFsaTruncator,0x9CABC042,0x8AA4,0x11d0,0x81,0xE6,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(IID, IID_IFsaPostIt,0xB5A1ED6A,0xCED4,0x4D16,0x9A,0x76,0x8C,0xD4,0x47,0x3A,0x2C,0xE9);


MIDL_DEFINE_GUID(IID, IID_IFsaRecallNotifyClient,0xD68BD5B1,0xD6AA,0x11d0,0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE);


MIDL_DEFINE_GUID(IID, IID_IFsaRecallNotifyServer,0xD68BD5B2,0xD6AA,0x11d0,0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE);


MIDL_DEFINE_GUID(IID, IID_IFsaRecallNotifySend,0x931AC085,0xF98C,0x4595,0x92,0xC0,0x70,0x6E,0xD3,0xDF,0xA6,0xD7);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IFsaFilter,0x5FFF1640,0xD487,0x11d1,0xA9,0xF5,0x00,0xA0,0x24,0x89,0x03,0xEA);


MIDL_DEFINE_GUID(IID, IID_IFsaFilterClient,0x560E5A02,0xDEDE,0x11d1,0xA9,0xF5,0x00,0xA0,0x24,0x89,0x03,0xEA);


MIDL_DEFINE_GUID(IID, IID_IFsaFilterRecall,0x5E176F27,0x6F53,0x4C84,0xB9,0x35,0x92,0x59,0x29,0x76,0x69,0xB0);


MIDL_DEFINE_GUID(IID, IID_IFsaResource,0x172F71CD,0xA452,0x4005,0x8E,0x3E,0x7B,0xCE,0xAE,0x12,0x4D,0x53);


MIDL_DEFINE_GUID(IID, IID_IFsaScanItem,0x087e7ed0,0x727a,0x11d2,0x9c,0xd3,0x00,0xa0,0xc9,0x11,0x81,0x02);


MIDL_DEFINE_GUID(IID, IID_IFsaServer,0xC49D553D,0xCA2B,0x4482,0xA4,0x04,0xCD,0x4B,0x6B,0x44,0xEA,0xE4);


MIDL_DEFINE_GUID(IID, IID_IFsaTruncator,0x9CABC042,0x8AA4,0x11d0,0x81,0xE6,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(IID, IID_IFsaPostIt,0xB5A1ED6A,0xCED4,0x4D16,0x9A,0x76,0x8C,0xD4,0x47,0x3A,0x2C,0xE9);


MIDL_DEFINE_GUID(IID, IID_IFsaRecallNotifyClient,0xD68BD5B1,0xD6AA,0x11d0,0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE);


MIDL_DEFINE_GUID(IID, IID_IFsaRecallNotifyServer,0xD68BD5B2,0xD6AA,0x11d0,0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE);


MIDL_DEFINE_GUID(IID, IID_IFsaRecallNotifySend,0x931AC085,0xF98C,0x4595,0x92,0xC0,0x70,0x6E,0xD3,0xDF,0xA6,0xD7);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

