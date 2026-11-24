

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, IID_IFsaFilterPriv,0x3DEFB163,0xBAEC,0x11d2,0x9E,0xE9,0x00,0x10,0x4B,0x22,0x6B,0x3E);


MIDL_DEFINE_GUID(IID, IID_IFsaFilterRecallPriv,0x23A05997,0xDA21,0x4998,0xA3,0x54,0x87,0x97,0x30,0x3F,0xB9,0x1E);


MIDL_DEFINE_GUID(IID, IID_IFsaResourcePriv,0xBFAB9D53,0x4D27,0x4B22,0xBC,0xEA,0xB8,0x3C,0x29,0xE7,0xD5,0x09);


MIDL_DEFINE_GUID(IID, IID_IFsaScanItemPriv,0x03150C1E,0x9580,0x4A1F,0x91,0xB3,0xBE,0x23,0x67,0xE4,0xF4,0x00);


MIDL_DEFINE_GUID(IID, IID_IFsaPremigratedDb,0xE4D900C9,0xDFD0,0x4F8D,0x8F,0x44,0x15,0x55,0xC2,0xE3,0xE1,0x5F);


MIDL_DEFINE_GUID(IID, IID_IFsaPremigratedRec,0x5E2526D3,0x400D,0x11d1,0xA3,0xD5,0x00,0x60,0x97,0x04,0xF7,0x87);


MIDL_DEFINE_GUID(IID, IID_IFsaRecoveryRec,0x74D85681,0x44D8,0x11d1,0xA3,0xD7,0x00,0x60,0x97,0x04,0xF7,0x87);


MIDL_DEFINE_GUID(IID, IID_IFsaUnmanageDb,0x3F676047,0x90B6,0x48D6,0xB4,0x79,0x28,0xE5,0x7A,0xD4,0xB7,0x46);


MIDL_DEFINE_GUID(IID, IID_IFsaUnmanageRec,0x90D54B53,0xEDB6,0x401D,0x81,0xC5,0x47,0xD7,0xB4,0x84,0x2E,0xC0);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, IID_IFsaFilterPriv,0x3DEFB163,0xBAEC,0x11d2,0x9E,0xE9,0x00,0x10,0x4B,0x22,0x6B,0x3E);


MIDL_DEFINE_GUID(IID, IID_IFsaFilterRecallPriv,0x23A05997,0xDA21,0x4998,0xA3,0x54,0x87,0x97,0x30,0x3F,0xB9,0x1E);


MIDL_DEFINE_GUID(IID, IID_IFsaResourcePriv,0xBFAB9D53,0x4D27,0x4B22,0xBC,0xEA,0xB8,0x3C,0x29,0xE7,0xD5,0x09);


MIDL_DEFINE_GUID(IID, IID_IFsaScanItemPriv,0x03150C1E,0x9580,0x4A1F,0x91,0xB3,0xBE,0x23,0x67,0xE4,0xF4,0x00);


MIDL_DEFINE_GUID(IID, IID_IFsaPremigratedDb,0xE4D900C9,0xDFD0,0x4F8D,0x8F,0x44,0x15,0x55,0xC2,0xE3,0xE1,0x5F);


MIDL_DEFINE_GUID(IID, IID_IFsaPremigratedRec,0x5E2526D3,0x400D,0x11d1,0xA3,0xD5,0x00,0x60,0x97,0x04,0xF7,0x87);


MIDL_DEFINE_GUID(IID, IID_IFsaRecoveryRec,0x74D85681,0x44D8,0x11d1,0xA3,0xD7,0x00,0x60,0x97,0x04,0xF7,0x87);


MIDL_DEFINE_GUID(IID, IID_IFsaUnmanageDb,0x3F676047,0x90B6,0x48D6,0xB4,0x79,0x28,0xE5,0x7A,0xD4,0xB7,0x46);


MIDL_DEFINE_GUID(IID, IID_IFsaUnmanageRec,0x90D54B53,0xEDB6,0x401D,0x81,0xC5,0x47,0xD7,0xB4,0x84,0x2E,0xC0);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

