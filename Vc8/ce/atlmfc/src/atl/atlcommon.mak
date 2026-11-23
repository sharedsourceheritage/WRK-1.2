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

# Default PLATFORM depending on host environment
!if "$(PLATFORM)" == ""
!if "$(PROCESSOR_ARCHITECTURE)" == ""
!error PLATFORM must be set to intended target
!endif
!if "$(PROCESSOR_ARCHITECTURE)" == "x86"
PLATFORM=INTEL
!endif
!endif

!ifndef TARGETNAME
!error TARGETNAME must be defined
!endif
!ifndef TARGETTYPE
!error TARGETTYPE must be set to LIB, DLL, EXE, or TLB
!endif

# Default to DEBUG mode
!ifndef DEBUG
DEBUG=1
!endif

# Default Codeview Info
!ifndef CODEVIEW
CODEVIEW=1
!endif

# Default to _MBCS build
!ifndef MBCS
MBCS=1
!endif

!ifndef CE_TARGET

!if "$(USE_CRTDLL)" == "1"

!if "$(DEBUG)" == "1"
TARGOPTS=$(TARGOPTS) /MDd
CRTLIB=msvcrtd.lib
!else
TARGOPTS=$(TARGOPTS) /MD
CRTLIB=msvcrt.lib
!endif
!else # if "$(USE_CRTDLL)" == "1"

!if "$(DEBUG)" == "1"
TARGOPTS=$(TARGOPTS) /MTd
CRTLIB=libcmtd.lib
!else
TARGOPTS=$(TARGOPTS) /MT
!if "$(MIN_CRT)" == "1"
DEFS=$(DEFS) /D_ATL_MIN_CRT
CRTLIB=atlmincrt.lib libcmt.lib
!else
CRTLIB=libcmt.lib
!endif
!endif

!endif # if "$(USE_CRTDLL)" == "1"

!else # ifndef CE_TARGET

!if ("$(CE_TARGET)"=="armv4") || ("$(CE_TARGET)"=="emulator") || ("$(CE_TARGET)"=="x86")
CRTLIB= $(_NTDRIVE)$(_NTROOT)\public\ozonesdk\lib\$(CE_TARGET)\corelibc.lib
!else
CRTLIB= corelibc.lib
!endif

CRTLIB=$(CRTLIB) ccrtrtti.lib

!if "$(DEBUG)" == "1"
CRTLIB=$(CRTLIB) msvcrtd.lib
!else
CRTLIB=$(CRTLIB) msvcrt.lib
!endif

!endif # ifndef CE_TARGET

#############################################################################
# normalize cases of parameters, or error check

#############################################################################
# Parse options

DEFS=$(DEFS) /D_ATL_NO_DEFAULT_LIBS

#
# DEBUG OPTIONS
#
!if "$(DEBUG)" != "0"

DEBUGSUF=D
DEBDEFS=/D_DEBUG
DEBOPTS=/Od

!endif

#
# NON-DEBUG OPTIONS
#
!if "$(DEBUG)" == "0"

DEBUGSUF=
DEBDEFS=
DEBOPTS=/Gy

!if "$(PLATFORM)" == "INTEL"
DEBOPTS=/O1 /Gy
!endif

!if "$(PLATFORM)" == "IA64"
DEBOPTS=/O1 /Gy
!endif

!if "$(PLATFORM)" == "AMD64"
DEBOPTS=/O1 /Gy
!endif

!if "$(PLATFORM)" == "emulator" || "$(PLATFORM)" == "x86"
# REVIEW - JoshHe 1/16/2003 - Favoring space causes undefined symbols related to SEH when targeting CE x86 targets
DEBOPTS=$(DEBOPTS) /O2
!elseif defined(CE_TARGET)
DEBOPTS=$(DEBOPTS) /O1
!endif

!endif #DEBUG

#
# PLATFORM options
#
CPP=cl
LIB32=lib
LINK32=link
MIDL=midl
RC=rc

!if "$(PLATFORM)" == "INTEL"
CL_MODEL=/D_X86_
!endif

!if "$(PLATFORM)" == "AMD64"
CL_MODEL=/D_AMD64_
!endif

!if "$(PLATFORM)" == "IA64"
CL_MODEL=/D_IA64_
!endif

!if "$(PLATFORM)" == "emulator" || "$(PLATFORM)" == "x86"
CPP=cl
CL_MODEL=/Dx86 /D_X86_
LFLAGS=$(LFLAGS) /machine:X86
!endif

!if "$(PLATFORM)" == "armv4" || "$(PLATFORM)" == "armv4i"

CPP=cl
CL_MODEL=-DARM -D_ARM_

!if "$(PLATFORM)" == "armv4" 
CL_MODEL=$(CL_MODEL) /QRarch4
LFLAGS=$(LFLAGS) /machine:ARM
!endif

!if  "$(PLATFORM)" == "armv4i"
CL_MODEL=$(CL_MODEL)  /QRarch4t /QRinterwork
LFLAGS=$(LFLAGS) /machine:THUMB
!endif

!endif

!if "$(PLATFORM)" == "mipsii" || "$(PLATFORM)" == "mipsii_fp" || "$(PLATFORM)" == "mipsiv" || "$(PLATFORM)" == "mipsiv_fp"

CPP=cl
CL_MODEL=-DMIPS -D_MIPS_

!if "$(PLATFORM)" == "mipsii" || "$(PLATFORM)" == "mipsii_fp"
CL_MODEL=$(CL_MODEL) /QMmips2
LFLAGS=$(LFLAGS) /machine:MIPS
!endif

!if "$(PLATFORM)" == "mipsiv" || "$(PLATFORM)" == "mipsiv_fp"
CL_MODEL=$(CL_MODEL) /QMmips4
# MIPSFPU actually means 64-bit not Floating Point Unit (it was hijacked)
LFLAGS=$(LFLAGS) /machine:MIPSFPU
!endif

!if  "$(PLATFORM)" == "mipsii" || "$(PLATFORM)" == "mipsiv"
# Turn on floating point emulation
CL_MODEL=$(CL_MODEL)  /QMFPE
!endif

!if  "$(PLATFORM)" == "mipsii_fp" || "$(PLATFORM)" == "mipsiv_fp"
# Turn off floating point emulation
CL_MODEL=$(CL_MODEL)  /QMFPE-
!endif

!endif

!if "$(PLATFORM)" == "sh3" || "$(PLATFORM)" == "sh4"

CPP=cl
CL_MODEL=-DSHx -D_SHX_

!if "$(PLATFORM)" == "sh3" 
CL_MODEL=$(CL_MODEL) /Qsh3
LFLAGS=$(LFLAGS) /machine:SH3
!endif

!if  "$(PLATFORM)" == "sh4"
CL_MODEL=$(CL_MODEL)  /Qsh4
LFLAGS=$(LFLAGS) /machine:SH4
!endif

!endif

!ifdef CE_TARGET
# REVIEW - JoshHe 1/16/2003 - is this the correct stack settings for all CE targets?
LFLAGS=$(LFLAGS) /STACK:0x10000,0x1000
LFLAGS=$(LFLAGS) /subsystem:windowsce
# The default libs are desktop libs
LFLAGS=$(LFLAGS) /NODEFAULTLIB
!endif

!if "$(CPP)" == ""
!error PLATFORM must be one of INTEL, IA64, AMD64
!endif

!if "$(UNICODE)" == "1"
TARGDEFS=$(TARGDEFS) /D_UNICODE /DUNICODE
!else
!if "$(MBCS)" != "0"
TARGDEFS=$(TARGDEFS) /D_MBCS
!endif
!endif

!ifndef CE_TARGET
TARGDEFS=$(TARGDEFS) /DWIN32 /D_WINDOWS
!else
TARGDEFS=$(TARGDEFS) /D_WIN32_WCE /DUNDER_CE
!endif

!if "$(TARGETTYPE)" == "DLL"
TARGDEFS=$(TARGDEFS) /D_WINDLL
!endif

#
# Object File Directory
#
!ifndef D
!if "$(DEBUG)" == "0"
D=$(PLATFORM)\Release
!else
D=$(PLATFORM)\Debug
!endif
!if "$(UNICODE)" == "1"
D=$(D)U
!endif
D=$(D)$(_OD_EXT)
!endif

#
# CODEVIEW options
#
!if !defined(PDBNAME)
PDBNAME=$(TARGETNAME).pdb
!endif

CVOPTS=/Zi /Fd$(D)\$(PDBNAME)

!if "$(VC6_DEBUGGING)" != ""
CVOPTS=$(CVOPTS) /Zvc6
!endif


#
# COMPILER OPTIONS
#
!ifndef CE_TARGET
CL_OPT=/W4 /Wp64 /WX /Zl $(DEBOPTS) $(CVOPTS) $(TARGOPTS)
!else
# No /Wp64 - CE platform headers are not compatible with this
CL_OPT=/Bd /W4 /WX /Zl $(DEBOPTS) $(CVOPTS) $(TARGOPTS)
!endif

!if "$(PREPROC)" == "1"
CL_OPT=$(CL_OPT) /P
!endif

!if "$(USE_EH)" == "1"
CL_OPT=$(CL_OPT) /EHsc
!else
CL_OPT=$(CL_OPT) /EHs-c-
!endif

CL_OPT=/Fo$D\ $(CL_OPT)

# REVIEW
CL_OPT=$(CL_OPT) /wd4601

# _SECURE_CRT deprecation mechanism
CL_OPT=$(SECURE_CRT_DEPRECATE) $(CL_OPT)

DEFS=$(DEFS) $(DEBDEFS) $(TARGDEFS)

#############################################################################
# Library Components

#############################################################################
# Standard tools

!if "$(VC6_DEBUGGING)" != ""
LFLAGS=$(LFLAGS) /debug /debugtype:vc6 /pdb:$(D)\$(PDBNAME) /incremental:no
!else
LFLAGS=$(LFLAGS) /debug /debugtype:cv /pdb:$(D)\$(PDBNAME) /incremental:no
!endif

!if "$(DEBUG)" == "0"
LFLAGS=$(LFLAGS) /opt:ref /opt:icf,32
!endif

!if "$(TARGETTYPE)" == "DLL"
LFLAGS=$(LFLAGS) /dll
!endif

!if "$(TARGETTYPE)" == "CONSOLE"
LFLAGS=$(LFLAGS) /subsystem:console
!endif

MIDL_FLAGS=$(MIDL_FLAGS) /out $(PLATFORM)\TLB

!if "$(PLATFORM)" == "INTEL"
MIDL_FLAGS=$(MIDL_FLAGS)
!endif

!if "$(PLATFORM)" == "IA64"
MIDL_FLAGS=$(MIDL_FLAGS)
!endif

!if "$(PLATFORM)" == "AMD64"
MIDL_FLAGS=$(MIDL_FLAGS)
!endif

!ifdef CE_TARGET
MIDL_FLAGS=$(MIDL_FLAGS) /D_WIN32_WCE /DUNDER_CE
!endif

RCFLAGS=$(RCFLAGS) /l 0x409 $(DEFS)
!ifdef RCINCLUDES
RCFLAGS=$(RCFLAGS) /i $(RCINCLUDES: =/i )
!endif

#############################################################################
# Goals to build

GOALS=create.dir

!if "$(TARGETTYPE)" == "CONSOLE"
GOALS=$(GOALS) $(D)\$(TARGETNAME).exe
!endif

!if "$(TARGETTYPE)" == "LIB"
GOALS=$(GOALS) $(D)\$(TARGETNAME).lib
!endif

!if "$(TARGETTYPE)" == "DLL"
!ifndef IMPLIB
IMPLIB=$(TARGETNAME).lib
!endif
GOALS=$(GOALS) $(D)\$(TARGETNAME).dll $(D)\$(IMPLIB)
!endif

!if "$(TARGETTYPE)" == "TLB"
MIDL_TARGETS=$(PLATFORM)\TLB\$(TARGETNAME).tlb $(PLATFORM)\TLB\$(TARGETNAME).H
GOALS=$(GOALS) $(MIDL_TARGETS)
!endif

goal: $(GOALS)

create.dir:
	@-if not exist $D\*.* mkdir $D

clean:
	-if exist $D\*.obj erase $D\*.obj
	-if exist $D\*.pch erase $D\*.pch
	-if exist $D\*.res erase $D\*.res
	-if exist $D\*.rsc erase $D\*.rsc
	-if exist $D\*.map erase $D\*.map
	-if exist $D\*.pdb erase $D\*.pdb
	-if exist $D\*.tlb erase $D\*.tlb
	-if exist $D\*.h erase $D\*.h
	-if not exist $D\*.* rmdir $D
!if "$(TARGETTYPE)" == "TLB"
    -rd $(PLATFORM)\TLB /s /q
!endif

#############################################################################
# Set CPPFLAGS for use with .cpp.obj and .c.obj rules
# Define rule for use with OBJ directory
# C++ uses a PCH file

!if "$(NO_PCH)" != "1"
PCH_FILE=stdafx
PCH_TARGETS=$(D)\$(PCH_FILE).pch $(D)\$(PCH_FILE).obj

PCH_USE_OPT=/Yu$(PCH_FILE).h /Fp$(D)\$(PCH_FILE).pch
!else
PCH_USE_OPT=
!endif

!ifndef CE_TARGET
CPPFLAGS=$(CPPFLAGS) $(CL_MODEL) $(CL_OPT) $(DEFS) $(OPT) $(_CL_ATL_CHECK_MANIFEST_)
!else
CPPFLAGS=$(CPPFLAGS) $(CL_MODEL) $(CL_OPT) $(DEFS) $(OPT)
!endif


# Disable the manifest directives when building ATL
CPPFLAGS=-D_ATL_NOFORCE_MANIFEST -D_CRT_NOFORCE_MANIFEST $(CPPFLAGS)

# Disable RTTI when building ATL
CPPFLAGS=$(CPPFLAGS) /GR-

.SUFFIXES: .cpp .c .s

!if "$(NO_PCH)" != "1"
$(PCH_TARGETS):: $(PCH_FILE).cpp $(PCH_FILE).h
	$(CPP) @<<
/Yc$(PCH_FILE).h /Fp$(D)\$(PCH_FILE).pch $(CPPFLAGS) /c $(PCH_FILE).cpp
<<
!endif

.cpp{$D}.obj::
	$(CPP) @<<
$(CPPFLAGS) $(PCH_USE_OPT) /c $<
<<

.cpp.i::
	$(CPP) @<<
$(CPPFLAGS) $(PCH_USE_OPT) /c /P $<
<<

.c{$D}.obj::
	$(CPP) @<<
$(CPPFLAGS)  /c $<
<<

.c.i::
	$(CPP) @<<
$(CPPFLAGS) /c /P $<
<<

!if "$(PLATFORM)" == "INTEL"

{$(PLATFORM)}.cpp{$D}.obj::
	$(CPP) @<<
$(CPPFLAGS) /c $<
<<
!endif


!if "$(PLATFORM)" == "IA64"

{$(PLATFORM)}.s{$D}.obj:
	ias -o $@ $<

!endif

!if "$(PLATFORM)" == "AMD64"

{$(PLATFORM)}.cpp{$D}.obj::
	$(CPP) @<<
$(CPPFLAGS) /c $<
<<

{$(PLATFORM)}.s{$D}.obj:
	ml64 -c -Fo$@ $<

!endif

!if "$(PLATFORM)" == "armv4"

{$(PLATFORM)}.s{$D}.obj:
	armasm -pd "Interworking SETL {FALSE}" -pd "Thumbing SETL {FALSE}" -o $@ $<

!endif

!if "$(PLATFORM)" == "armv4i"

{$(PLATFORM)}.s{$D}.obj:
	armasm -pd "Interworking SETL {TRUE}" -pd "Thumbing SETL {FALSE}" -o $@ $<

!endif

!ifdef RCFILE
RESFILE=$(D)\$(RCFILE:.rc=.res)

$(RESFILE): $(RCFILE)
	$(RC) $(RCFLAGS) /fo$(RESFILE) $(RCFILE)
!endif

!if "$(TARGETTYPE)" == "TLB"
$(MIDL_TARGETS):: $(TARGETNAME).idl
    -md $(PLATFORM)\TLB
	$(MIDL) @<<
$(MIDL_FLAGS) /h $(TARGETNAME).H $(TARGETNAME).idl
<<
!endif
