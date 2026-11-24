

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for fsalib.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_FSALib,0x112981B1,0x1BA5,0x11D0,0x81,0xB2,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaFilterNTFS,0xFCDC8671,0x7329,0x11d0,0x81,0xDF,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaFilterClientNTFS,0xB2AD2931,0x84FD,0x11d0,0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaFilterRecallNTFS,0xB2AD2932,0x84FD,0x11d0,0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaResourceNTFS,0x112981B3,0x1BA5,0x11D0,0x81,0xB2,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaScanItemNTFS,0x112981B2,0x1BA5,0x11D0,0x81,0xB2,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaServerNTFS,0xE707D9B2,0x4F89,0x11D0,0x81,0xCC,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaTruncatorNTFS,0x14005FF1,0x8B4F,0x11d0,0x81,0xE6,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaPremigratedDb,0x0B8B6F12,0x8B3A,0x11D0,0x99,0x0C,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaPremigratedRec,0x7CA819F2,0x8AAB,0x11D0,0x99,0x0C,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaUnmanageDb,0x58DD2BB0,0x1A57,0x4CD3,0xB1,0x1E,0xD5,0x05,0xE4,0x33,0x2B,0xC0);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaUnmanageRec,0x85D81D44,0x31D5,0x43B0,0x94,0x66,0x1E,0x4F,0x66,0xEE,0xC0,0x3A);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaPostIt,0xF7860350,0xAA27,0x11d0,0xB1,0x6D,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaRecallNotifyClient,0xD68BD5B0,0xD6AA,0x11d0,0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaRecoveryRec,0xCECCB131,0x286D,0x11d1,0x99,0x3E,0x00,0x60,0x97,0x6A,0x54,0x6D);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaRecallNotifyServer,0xD68BD5B3,0xD6AA,0x11d0,0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for fsalib.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_FSALib,0x112981B1,0x1BA5,0x11D0,0x81,0xB2,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaFilterNTFS,0xFCDC8671,0x7329,0x11d0,0x81,0xDF,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaFilterClientNTFS,0xB2AD2931,0x84FD,0x11d0,0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaFilterRecallNTFS,0xB2AD2932,0x84FD,0x11d0,0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaResourceNTFS,0x112981B3,0x1BA5,0x11D0,0x81,0xB2,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaScanItemNTFS,0x112981B2,0x1BA5,0x11D0,0x81,0xB2,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaServerNTFS,0xE707D9B2,0x4F89,0x11D0,0x81,0xCC,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaTruncatorNTFS,0x14005FF1,0x8B4F,0x11d0,0x81,0xE6,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaPremigratedDb,0x0B8B6F12,0x8B3A,0x11D0,0x99,0x0C,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaPremigratedRec,0x7CA819F2,0x8AAB,0x11D0,0x99,0x0C,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaUnmanageDb,0x58DD2BB0,0x1A57,0x4CD3,0xB1,0x1E,0xD5,0x05,0xE4,0x33,0x2B,0xC0);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaUnmanageRec,0x85D81D44,0x31D5,0x43B0,0x94,0x66,0x1E,0x4F,0x66,0xEE,0xC0,0x3A);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaPostIt,0xF7860350,0xAA27,0x11d0,0xB1,0x6D,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaRecallNotifyClient,0xD68BD5B0,0xD6AA,0x11d0,0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaRecoveryRec,0xCECCB131,0x286D,0x11d1,0x99,0x3E,0x00,0x60,0x97,0x6A,0x54,0x6D);


MIDL_DEFINE_GUID(CLSID, CLSID_CFsaRecallNotifyServer,0xD68BD5B3,0xD6AA,0x11d0,0x9E,0xDA,0x00,0xA0,0x24,0x88,0xFC,0xDE);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

