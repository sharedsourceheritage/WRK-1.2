# This is a part of the Active Template Library.
# Copyright (C) Microsoft Corporation
# All rights reserved.
#
# This source code is only intended as a supplement to the
# Active Template Library Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Active Template Library product.

!if "$(MFC_VER)" == ""
MFC_VER=80
!endif

!if "$(LIBNAME)" != ""
_LIBNAME = LIBNAME=$(LIBNAME)
!endif

!if "$(PLATFORM)" == ""
!message setting PLATFORM=INTEL
PLATFORM=INTEL
!endif

!if "$(CLEAN)" != ""
_CLEAN = CLEAN
!else
_CLEAN =
!endif

!if !exist(atlmfc.mak)
!error Run this makefile from the directory it is loacted in.
!endif


all : ATLSRC MFCSRC MFCMSRC

atl : ATLSRC

mfc : MFCSRC

createdir :
# create or clean destination directory
!if "$(CLEAN)" == ""
	-if not exist ..\lib\$(PLATFORM)$(_OD_EXT) md ..\lib\$(PLATFORM)$(_OD_EXT)
!endif

!ifndef CE_TARGET
ATLSRC : ATL_ASSMINFO ATL_IDL ATL_MINCRT ATL_STATIC_RELEASE ATL_STATIC_DEBUG ATL_UNICODE_RELEASE ATL_UNICODE_DEBUG ATL_ANSI_RELEASE ATL_ANSI_DEBUG
!else
ATLSRC : ATL_IDL ATL_MINCRT ATL_STATIC_RELEASE ATL_STATIC_DEBUG ATL_UNICODE_RELEASE ATL_UNICODE_DEBUG
!endif

# build atl80.dll
# Unicode release
ATL_UNICODE_RELEASE : createdir
	cd atl
	$(MAKE) /$(MAKEFLAGS) /f atldll.mak UNICODE=1 DEBUG=0 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM) _CL_ATL_CHECK_MANIFEST_=$(_CL_ATL_CHECK_MANIFEST_)
!if "$(CLEAN)" == ""
	copy $(PLATFORM)\releaseU$(_OD_EXT)\atl.lib ..\..\lib\$(PLATFORM)$(_OD_EXT)
	copy $(PLATFORM)\releaseU$(_OD_EXT)\atl$(MFC_VER)$(ATL_PDB_VERSION_NAME).pdb ..\..\lib\$(PLATFORM)$(_OD_EXT)
!endif
	cd ..

# Unicode Debug
ATL_UNICODE_DEBUG : createdir
	cd atl
	$(MAKE) /$(MAKEFLAGS) /f atldll.mak UNICODE=1 DEBUG=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM) _CL_ATL_CHECK_MANIFEST_=$(_CL_ATL_CHECK_MANIFEST_)
	cd ..

!ifndef CE_TARGET
# Ansi Release
ATL_ANSI_RELEASE : createdir
	cd atl
	$(MAKE) /$(MAKEFLAGS) /f atldll.mak UNICODE=0 DEBUG=0 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM) _CL_ATL_CHECK_MANIFEST_=$(_CL_ATL_CHECK_MANIFEST_)
	cd ..

# Ansi Debug
ATL_ANSI_DEBUG : createdir
	cd atl
	$(MAKE) /$(MAKEFLAGS) /f atldll.mak UNICODE=0 DEBUG=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM) _CL_ATL_CHECK_MANIFEST_=$(_CL_ATL_CHECK_MANIFEST_)
	cd ..
!endif

# build Atl static lib
# atls.lib
ATL_STATIC_RELEASE : createdir BUILD_STATIC_RELEASE COPY_STATIC_RELEASE

BUILD_STATIC_RELEASE :
	cd atl\atls
	$(MAKE) /$(MAKEFLAGS) /f atls.mak DEBUG=0 _OD_EXT=$(_OD_EXT) UNICODE= $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..\..

!if "$(CLEAN)" == ""
COPY_STATIC_RELEASE : ..\lib\$(PLATFORM)$(_OD_EXT)\atls.lib

..\lib\$(PLATFORM)$(_OD_EXT)\atls.lib: atl\atls\$(PLATFORM)\release$(_OD_EXT)\atls.lib
	copy atl\atls\$(PLATFORM)\release$(_OD_EXT)\atls.lib ..\lib\$(PLATFORM)$(_OD_EXT)
	copy atl\atls\$(PLATFORM)\release$(_OD_EXT)\atls.pdb ..\lib\$(PLATFORM)$(_OD_EXT)
	
!else
COPY_STATIC_RELEASE : 
!endif
	
# atlsd.lib
ATL_STATIC_DEBUG : createdir BUILD_STATIC_DEBUG COPY_STATIC_DEBUG

BUILD_STATIC_DEBUG :
	cd atl\atls
	$(MAKE) /$(MAKEFLAGS) /f atls.mak DEBUG=1 _OD_EXT=$(_OD_EXT) UNICODE= $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..\..

!if "$(CLEAN)" == ""
COPY_STATIC_DEBUG : ..\lib\$(PLATFORM)$(_OD_EXT)\atlsd.lib

..\lib\$(PLATFORM)$(_OD_EXT)\atlsd.lib: atl\atls\$(PLATFORM)\debug$(_OD_EXT)\atlsd.lib
	copy atl\atls\$(PLATFORM)\debug$(_OD_EXT)\atlsd.lib ..\lib\$(PLATFORM)$(_OD_EXT)
	copy atl\atls\$(PLATFORM)\debug$(_OD_EXT)\atlsd.pdb ..\lib\$(PLATFORM)$(_OD_EXT)
	
!else
COPY_STATIC_DEBUG :
!endif

	
# build mincrt static lib	
ATL_MINCRT : createdir
	cd atl\atlmincrt
	$(MAKE) /$(MAKEFLAGS) /f atlmincrt.mak DEBUG=0 _OD_EXT=$(_OD_EXT) UNICODE= $(_CLEAN) PLATFORM=$(PLATFORM)
!if "$(CLEAN)" == ""
	copy $(PLATFORM)\release$(_OD_EXT)\atlmincrt.lib ..\..\..\lib\$(PLATFORM)$(_OD_EXT)
	copy $(PLATFORM)\release$(_OD_EXT)\atlmincrt.pdb ..\..\..\lib\$(PLATFORM)$(_OD_EXT)
!endif
	cd ..\..
	
# buils atl.tlb from atl.idl	
ATL_IDL :
	cd atl
	$(MAKE) /$(MAKEFLAGS) /f atlidl.mak DEBUG=0 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..
	
MFCSRC : MFC_ASSMINFO MFC_STATIC MFC_DLL MFC_ISAPI MFC_LOC MFCM_DLL

# static libs	
!ifndef CE_TARGET
MFC_STATIC: MFC_ANSI_STATIC_RELEASE MFC_ANSI_STATIC_DEBUG MFC_UNICODE_STATIC_RELEASE MFC_UNICODE_STATIC_DEBUG
!else
MFC_STATIC: MFC_UNICODE_STATIC_RELEASE MFC_UNICODE_STATIC_DEBUG
!endif

!ifndef CE_TARGET
MFC_ANSI_STATIC_RELEASE: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) DEBUG=0 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..
	
MFC_ANSI_STATIC_DEBUG: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) DEBUG=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..
!endif
	
MFC_UNICODE_STATIC_RELEASE: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) DEBUG=0 UNICODE=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..

MFC_UNICODE_STATIC_DEBUG: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) DEBUG=1 UNICODE=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..
	
# isapi libs
MFC_ISAPI: MFC_ISAPI_RELEASE MFC_ISAPI_DEBUG

MFC_ISAPI_RELEASE: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) /f mfcisapi.mak DEBUG=0 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	$(MAKE) /$(MAKEFLAGS) /f mfcisapi.mak DEBUG=0 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM) DLL=2
	cd ..

MFC_ISAPI_DEBUG: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) /f mfcisapi.mak DEBUG=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	$(MAKE) /$(MAKEFLAGS) /f mfcisapi.mak DEBUG=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM) DLL=2
	cd ..
	
# dlls
!ifndef CE_TARGET
MFC_DLL: MFC_ANSI_RELEASE MFC_ANSI_DEBUG MFC_UNICODE_RELEASE MFC_UNICODE_DEBUG
!else
MFC_DLL: MFC_UNICODE_RELEASE MFC_UNICODE_DEBUG
!endif

!ifndef CE_TARGET
MFC_ANSI_RELEASE: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) /f mfcdll.mak $(_LIBNAME) debug=0 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..
	
MFC_ANSI_DEBUG: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) /f mfcdll.mak $(_LIBNAME) debug=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..
!endif
	
MFC_UNICODE_RELEASE: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) /f mfcdll.mak $(_LIBNAME) debug=0 UNICODE=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..
	
MFC_UNICODE_DEBUG: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) /f mfcdll.mak $(_LIBNAME) debug=1 UNICODE=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..

# managed dlls
MFCM_DLL: MFCM_ANSI_RELEASE MFCM_ANSI_DEBUG MFCM_UNICODE_RELEASE MFCM_UNICODE_DEBUG

MFCM_ANSI_RELEASE: createdir
	cd MFCM
	$(MAKE) /$(MAKEFLAGS) /f mfcmdll.mak $(_LIBNAME) debug=0 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..
	
MFCM_ANSI_DEBUG: createdir
	cd MFCM
	$(MAKE) /$(MAKEFLAGS) /f mfcmdll.mak $(_LIBNAME) debug=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..
	
MFCM_UNICODE_RELEASE: createdir
	cd MFCM
	$(MAKE) /$(MAKEFLAGS) /f mfcmdll.mak $(_LIBNAME) debug=0 UNICODE=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..
	
MFCM_UNICODE_DEBUG: createdir
	cd MFCM
	$(MAKE) /$(MAKEFLAGS) /f mfcmdll.mak $(_LIBNAME) debug=1 UNICODE=1 _OD_EXT=$(_OD_EXT) $(_CLEAN) PLATFORM=$(PLATFORM)
	cd ..

# localized dlls
MFC_LOC: createdir
	cd MFC
	$(MAKE) /$(MAKEFLAGS) /f mfcintl.mak fra
	$(MAKE) /$(MAKEFLAGS) /f mfcintl.mak deu
	$(MAKE) /$(MAKEFLAGS) /f mfcintl.mak jpn
	$(MAKE) /$(MAKEFLAGS) /f mfcintl.mak ita
	$(MAKE) /$(MAKEFLAGS) /f mfcintl.mak esp
	$(MAKE) /$(MAKEFLAGS) /f mfcintl.mak chs
	$(MAKE) /$(MAKEFLAGS) /f mfcintl.mak cht
	$(MAKE) /$(MAKEFLAGS) /f mfcintl.mak kor
	$(MAKE) /$(MAKEFLAGS) /f mfcintl.mak enu
	cd ..
