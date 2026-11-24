

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for wsblib.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_WSBLib,0x9C7D6F08,0x1562,0x11D0,0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbGuid,0xA0FF1F42,0x237A,0x11D0,0x81,0xBA,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbIndexedEnum,0xDB35D732,0x21E9,0x11D0,0x81,0xB8,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbOrderedCollection,0x9C7D6F13,0x1562,0x11D0,0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbString,0xDB35D733,0x21E9,0x11D0,0x81,0xB8,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbDbSys,0x5D1A1AD2,0xC658,0x11d0,0x99,0x1E,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbDb,0x46CE9ED4,0x447C,0x11D0,0x98,0xFC,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbDbKey,0x46CE9EDE,0x447C,0x11D0,0x98,0xFC,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbTrace,0x389E18D0,0x7EE3,0x11d0,0x9E,0x35,0x00,0xA0,0xC9,0x16,0xF1,0x20);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for wsblib.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_WSBLib,0x9C7D6F08,0x1562,0x11D0,0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbGuid,0xA0FF1F42,0x237A,0x11D0,0x81,0xBA,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbIndexedEnum,0xDB35D732,0x21E9,0x11D0,0x81,0xB8,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbOrderedCollection,0x9C7D6F13,0x1562,0x11D0,0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbString,0xDB35D733,0x21E9,0x11D0,0x81,0xB8,0x00,0xA0,0xC9,0x11,0x80,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbDbSys,0x5D1A1AD2,0xC658,0x11d0,0x99,0x1E,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbDb,0x46CE9ED4,0x447C,0x11D0,0x98,0xFC,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbDbKey,0x46CE9EDE,0x447C,0x11D0,0x98,0xFC,0x00,0xA0,0xC9,0x05,0x8B,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_CWsbTrace,0x389E18D0,0x7EE3,0x11d0,0x9E,0x35,0x00,0xA0,0xC9,0x16,0xF1,0x20);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

