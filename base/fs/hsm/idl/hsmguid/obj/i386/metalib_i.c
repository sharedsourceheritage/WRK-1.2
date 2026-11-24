

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for metalib.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_MetaLib,0x37F704E0,0x3EF9,0x11D0,0x9E,0x17,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CSegRec,0x37F704E6,0x3EF9,0x11D0,0x9E,0x17,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CBagHole,0x450024A3,0x47D0,0x11D0,0x9E,0x1E,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CBagInfo,0xB13FA473,0x4E1B,0x11D0,0x9E,0x22,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CMediaInfo,0xF0D7AFE0,0x9026,0x11d0,0x9E,0x3B,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CVolAssign,0x4A009E81,0xDC42,0x11d0,0x99,0x25,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CSegDb,0x768AD5A4,0x40C8,0x11D0,0x9E,0x17,0x00,0xA0,0xC9,0x16,0xF1,0x20);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for metalib.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_MetaLib,0x37F704E0,0x3EF9,0x11D0,0x9E,0x17,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CSegRec,0x37F704E6,0x3EF9,0x11D0,0x9E,0x17,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CBagHole,0x450024A3,0x47D0,0x11D0,0x9E,0x1E,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CBagInfo,0xB13FA473,0x4E1B,0x11D0,0x9E,0x22,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CMediaInfo,0xF0D7AFE0,0x9026,0x11d0,0x9E,0x3B,0x00,0xA0,0xC9,0x16,0xF1,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_CVolAssign,0x4A009E81,0xDC42,0x11d0,0x99,0x25,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CSegDb,0x768AD5A4,0x40C8,0x11D0,0x9E,0x17,0x00,0xA0,0xC9,0x16,0xF1,0x20);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

