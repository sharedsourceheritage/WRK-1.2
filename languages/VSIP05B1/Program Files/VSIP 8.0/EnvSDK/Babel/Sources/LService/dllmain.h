/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef dllmain_h
#define dllmain_h

//open Visual Studio root key: HKLM\software\microsoft\visualstudio\7.1
HRESULT RegOpenKeyVS( REGSAM samDesired, out HKEY* key );

extern HINSTANCE    g_instance;
extern const CLSID  clsidBabelPackage;

extern ITypeInfo*   g_typeInfoColorSink;
extern ITypeInfo*   g_typeInfoParseSink;
extern ITypeInfo*   g_typeInfoScope;
extern ITypeInfo*   g_typeInfoDeclarations;
extern ITypeInfo*   g_typeInfoNames;
extern ITypeInfo*   g_typeInfoMethods;
extern ITypeInfo*   g_typeInfoBabelPackage;

extern HIMAGELIST   g_imageList;
const  long         g_imageListCount = 180;


#endif
