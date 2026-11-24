

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for tskint.idl:
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

MIDL_DEFINE_GUID(IID, IID_IHsmFsaTskMgr,0x14F73FCB,0x517D,0x4503,0xB1,0x5D,0x2D,0x40,0xB3,0xE9,0xCD,0x21);


MIDL_DEFINE_GUID(IID, IID_IHsmWorkQueue,0x39A35CB0,0xC56B,0x11d0,0xB1,0x6F,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(IID, IID_IHsmWorkItem,0xBF8BBCD0,0xC596,0x11d0,0xB1,0x6F,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(IID, IID_IHsmRecallQueue,0xE3A35E06,0x4263,0x4505,0xB7,0x7B,0x19,0x6B,0x22,0xAC,0xC9,0x4b);


MIDL_DEFINE_GUID(IID, IID_IHsmRecallItem,0xB287C709,0xf4AD,0x467C,0x81,0x1D,0x1D,0x56,0x02,0x1D,0x68,0xAD);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for tskint.idl:
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

MIDL_DEFINE_GUID(IID, IID_IHsmFsaTskMgr,0x14F73FCB,0x517D,0x4503,0xB1,0x5D,0x2D,0x40,0xB3,0xE9,0xCD,0x21);


MIDL_DEFINE_GUID(IID, IID_IHsmWorkQueue,0x39A35CB0,0xC56B,0x11d0,0xB1,0x6F,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(IID, IID_IHsmWorkItem,0xBF8BBCD0,0xC596,0x11d0,0xB1,0x6F,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(IID, IID_IHsmRecallQueue,0xE3A35E06,0x4263,0x4505,0xB7,0x7B,0x19,0x6B,0x22,0xAC,0xC9,0x4b);


MIDL_DEFINE_GUID(IID, IID_IHsmRecallItem,0xB287C709,0xf4AD,0x467C,0x81,0x1D,0x1D,0x56,0x02,0x1D,0x68,0xAD);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

