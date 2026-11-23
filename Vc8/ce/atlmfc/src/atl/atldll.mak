# This is a part of the Active Template Library.
# Copyright (C) Microsoft Corporation
# All rights reserved.
#
# This source code is only intended as a supplement to the
# Active Template Library Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Active Template Library product.

!ifndef DEBUG
DEBUG=1
!endif

TARGETNAME=atl$(MFC_VER)
IMPLIB=atl.lib
TARGETTYPE=DLL
DEFFILE=$(ATL_DEFFILE)
RCFILE=atl.rc
RCINCLUDES=$(PLATFORM)\TLB
PDBNAME=$(TARGETNAME)$(ATL_PDB_VERSION_NAME).pdb

# base address for atl$(MFC_VER).dll. Should change if the name of the DLL changes

!ifndef CE_TARGET
LFLAGS=/base:0x7c120000
!else
# REVIEW - JoshHe 1/13/2003 - what should the base address be?
LFLAGS=/base:0x00100000
!endif

!if "$(UNICODE)" == "1"
LFLAGS=$(LFLAGS) /opt:nowin98
!endif

MIN_CRT=1

!include atlcommon.mak

OBJS=$(D)\RegObj.obj $(D)\atl.obj $(D)\stdafx.obj
 
!ifndef CE_TARGET
LIBS=$(LIBS) atldload.lib ole32.lib oleaut32.lib advapi32.lib user32.lib gdi32.lib kernel32.lib shlwapi.lib
MANIFESTOBJ=$(D)\atlmanifest.obj
!else
!if ("$(CE_TARGET)"=="armv4")
LIBS=$(LIBS) secchk.lib $(_NTDRIVE)$(_NTROOT)\public\ozonesdk\lib\$(CE_TARGET)\coredll.lib $(_NTDRIVE)$(_NTROOT)\public\ozonesdk\lib\$(CE_TARGET)\corelibc.lib
!else
LIBS=$(LIBS) secchk.lib coredll.lib corelibc.lib
!endif
LIBS=$(LIBS) ole32.lib oleaut32.lib uuid.lib $(_NTTREE)\bin\i386\vc7\ce\atlmfc\lib\$(CE_TARGET)\atlosapis.lib
!if ("$(CE_TARGET)"=="x86") || ("$(CE_TARGET)"=="emulator")
!if "$(DEBUG)" == "1"
LIBS=$(LIBS) libcmtx86d.lib
!else
LIBS=$(LIBS) libcmtx86.lib
!endif
!endif # ("$(CE_TARGET)"=="x86") || ("$(CE_TARGET)"=="emulator")
!endif # CE_TARGET
!if "$(DEBUG)" == "1"
LIBS=$(LIBS) atlsd.lib libcmtd.lib
!else
LIBS=$(LIBS) atls.lib
!endif

# No delay load on CE
!ifndef CE_TARGET
DELAYLOAD=ole32.dll;oleaut32.dll;advapi32.dll;user32.dll;gdi32.dll
!endif

$(D)\atlmanifest.obj : atlmanifest.cpp
	$(CPP) $(CPPFLAGS:/Zi=/Z7) /c atlmanifest.cpp

!include atltarg.mak
