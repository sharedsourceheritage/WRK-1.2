!IF 0

Copyright (c) 1990-2003  Microsoft Corporation

Module Name:

    makefile.inc.

Abstract:

    This file specifies build commands for MFC component. makefile.inc in
    subdirectories determine the target being built.
    All MFC components are built in the default phase [ PROD_PHASE ]

!ENDIF

!ifndef MFC_VER
MFC_VER=80
!endif

_MFC_LIBNAME=MFC$(MFC_VER)

!ifndef CE_TARGET
#don't build in _PHASE0 and _PHASE1
BOOT_PHASE SELF_PHASE:

PROD_PHASE: $(_MFC_TARGETS)
!else # CE_TARGET
BOOT_PHASE: $(_MFC_TARGETS)
!endif # CE_TARGET

MFC_STAT_BLD:
	cd $(_LIBSROOT)\Ship\ATLMFC\Src
	$(MAKE) /$(MAKEFLAGS) /f atlmfc.mak $(_MFC_TYPE) _OD_EXT=$(_ATLMFC_OD_EXT) LIBNAME=$(_MFC_LIBNAME) CLEAN=$(_ATLMFC_CLEAN) "SECURE_CRT_DEPRECATE=$(SECURE_CRT_DEPRECATE)"
!ifndef CE_TARGET
!ifndef _ATLMFC_CLEAN
	cd $(_LIBSROOT)\Ship\ATLMFC\Src\MFC\$(_MFC_BUILD_DIR)
	if exist _alias*.obj del _alias*.obj
	dumpbin /symbols $(_LIBSROOT)\Ship\ATLMFC\Lib\$(_MFC_BIN_DIR)\$(_MFC_BUILD_TARG) | perl $(_LIBSROOT)\Nonship\Build\Bin\wcharthunk.pl -fileprefix _alias_s_ -platform $(PLATFORM)
	lib /IGNORE:4221 $(_LIBSROOT)\Ship\ATLMFC\Lib\$(_MFC_BIN_DIR)\$(_MFC_BUILD_TARG) _alias_s_*.obj
!endif # _ATLMFC_CLEAN 
!endif # CE_TARGET
	cd $(_LIBSROOT)\Ship\ATLMFC\Src\$(_MFC_HOME_DIR)

MFC_ISAPI_BLD:
	cd $(_LIBSROOT)\Ship\ATLMFC\Src
	$(MAKE) /$(MAKEFLAGS) /f atlmfc.mak $(_MFC_TYPE) _OD_EXT=$(_ATLMFC_OD_EXT) LIBNAME=$(_MFC_LIBNAME) CLEAN=$(_ATLMFC_CLEAN) "SECURE_CRT_DEPRECATE=$(SECURE_CRT_DEPRECATE)"
	cd $(_LIBSROOT)\Ship\ATLMFC\Src\$(_MFC_HOME_DIR)

MFC_DLL_BLD:
    setlocal
    set _OD_EXT=$(_ATLMFC_OD_EXT)
    set SECURE_CRT_DEPRECATE=$(SECURE_CRT_DEPRECATE)
    set RCDEFINES=$(RCDEFINES)
    bldmfcdll $(_MFC_DLL_TYPE) $(_ATLMFC_CLEAN)
    endlocal

