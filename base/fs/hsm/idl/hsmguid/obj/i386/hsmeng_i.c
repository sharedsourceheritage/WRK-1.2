

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, IID_IHsmServer,0xE372F85B,0xD72B,0x4A7D,0xB0,0xF6,0x2B,0xCF,0x8F,0xED,0x88,0xB9);


MIDL_DEFINE_GUID(IID, IID_IHsmUpgradeRmsDb,0xB04E802A,0x8D06,0x46BE,0x89,0x30,0x2A,0xA2,0xDA,0x4C,0x0D,0xF2);


MIDL_DEFINE_GUID(IID, IID_IHsmManagedResource,0xBA365110,0x6D66,0x11d0,0x9E,0x2E,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(IID, IID_IHsmManagedResourceCollection,0xAAA2ABF1,0xE5CF,0x11d1,0x99,0x74,0x00,0x60,0x97,0x6A,0x54,0x6D);


MIDL_DEFINE_GUID(IID, IID_IHsmStoragePool,0xDD529292,0x3892,0x47A4,0xB0,0x16,0xC7,0x52,0xA5,0x0C,0xFC,0x29);


MIDL_DEFINE_GUID(IID, IID_IMountingMedia,0x38E504D8,0xCBC5,0x4701,0xBA,0xC5,0xD4,0xF8,0x5B,0x45,0xFC,0x79);


MIDL_DEFINE_GUID(IID, LIBID_HsmEngLib,0x2D1E3150,0x25DE,0x11D0,0x80,0x73,0x00,0xA0,0xC9,0x05,0xF0,0x98);


MIDL_DEFINE_GUID(CLSID, CLSID_HsmServer,0x2D1E3156,0x25DE,0x11D0,0x80,0x73,0x00,0xA0,0xC9,0x05,0xF0,0x98);


MIDL_DEFINE_GUID(CLSID, CLSID_CHsmUpgradeRmsDb,0xFA94233C,0xF4E2,0x4B96,0xA4,0xFA,0xBC,0x63,0xAF,0xB6,0x9F,0x7D);


MIDL_DEFINE_GUID(CLSID, CLSID_CHsmManagedResource,0xAB939AD0,0x6D67,0x11d0,0x9E,0x2E,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CHsmManagedResourceCollection,0x8448DD80,0x7614,0x11d0,0x9E,0x33,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CHsmStoragePool,0x61F0B790,0x82D9,0x11d0,0x9E,0x35,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CMountingMedia,0x842B10E9,0xFAAD,0x4A8C,0x87,0xFE,0x4F,0xF9,0xEB,0xF4,0x5A,0xBC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, IID_IHsmServer,0xE372F85B,0xD72B,0x4A7D,0xB0,0xF6,0x2B,0xCF,0x8F,0xED,0x88,0xB9);


MIDL_DEFINE_GUID(IID, IID_IHsmUpgradeRmsDb,0xB04E802A,0x8D06,0x46BE,0x89,0x30,0x2A,0xA2,0xDA,0x4C,0x0D,0xF2);


MIDL_DEFINE_GUID(IID, IID_IHsmManagedResource,0xBA365110,0x6D66,0x11d0,0x9E,0x2E,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(IID, IID_IHsmManagedResourceCollection,0xAAA2ABF1,0xE5CF,0x11d1,0x99,0x74,0x00,0x60,0x97,0x6A,0x54,0x6D);


MIDL_DEFINE_GUID(IID, IID_IHsmStoragePool,0xDD529292,0x3892,0x47A4,0xB0,0x16,0xC7,0x52,0xA5,0x0C,0xFC,0x29);


MIDL_DEFINE_GUID(IID, IID_IMountingMedia,0x38E504D8,0xCBC5,0x4701,0xBA,0xC5,0xD4,0xF8,0x5B,0x45,0xFC,0x79);


MIDL_DEFINE_GUID(IID, LIBID_HsmEngLib,0x2D1E3150,0x25DE,0x11D0,0x80,0x73,0x00,0xA0,0xC9,0x05,0xF0,0x98);


MIDL_DEFINE_GUID(CLSID, CLSID_HsmServer,0x2D1E3156,0x25DE,0x11D0,0x80,0x73,0x00,0xA0,0xC9,0x05,0xF0,0x98);


MIDL_DEFINE_GUID(CLSID, CLSID_CHsmUpgradeRmsDb,0xFA94233C,0xF4E2,0x4B96,0xA4,0xFA,0xBC,0x63,0xAF,0xB6,0x9F,0x7D);


MIDL_DEFINE_GUID(CLSID, CLSID_CHsmManagedResource,0xAB939AD0,0x6D67,0x11d0,0x9E,0x2E,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CHsmManagedResourceCollection,0x8448DD80,0x7614,0x11d0,0x9E,0x33,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CHsmStoragePool,0x61F0B790,0x82D9,0x11d0,0x9E,0x35,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CMountingMedia,0x842B10E9,0xFAAD,0x4A8C,0x87,0xFE,0x4F,0xF9,0xEB,0xF4,0x5A,0xBC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

