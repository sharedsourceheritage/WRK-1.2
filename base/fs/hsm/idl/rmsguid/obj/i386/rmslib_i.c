

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for rmslib.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_RMSLib,0xFE37FF40,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsServer,0xFE37FA01,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsLibrary,0xFE37FA02,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsDriveClass,0xFE37FA03,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsCartridge,0xFE37FA04,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsDrive,0xFE37FA05,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsStorageSlot,0xFE37FA06,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsMediumChanger,0xFE37FA07,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsIEPort,0xFE37FA08,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsMediaSet,0xFE37FA09,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsRequest,0xFE37FA10,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsPartition,0xFE37FA11,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsClient,0xFE37FA12,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsNTMS,0xFE37FA13,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for rmslib.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_RMSLib,0xFE37FF40,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsServer,0xFE37FA01,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsLibrary,0xFE37FA02,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsDriveClass,0xFE37FA03,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsCartridge,0xFE37FA04,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsDrive,0xFE37FA05,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsStorageSlot,0xFE37FA06,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsMediumChanger,0xFE37FA07,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsIEPort,0xFE37FA08,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsMediaSet,0xFE37FA09,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsRequest,0xFE37FA10,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsPartition,0xFE37FA11,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsClient,0xFE37FA12,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CRmsNTMS,0xFE37FA13,0x3729,0x11D0,0x8C,0xF4,0x00,0xA0,0xC9,0x19,0x04,0x59);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

