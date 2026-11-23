#----------------#
# Initialization #
#----------------#

!include ..\..\..\..\..\makefile.inc
!include ..\..\..\..\makefile.inc

###############################################################################
###############################################################################
#                              Build targets

#------------------------------------------------------------------------------
#
# all.  Everything to build. It depends on the pass or passes that need to be
#       run, so it contains Pass0, Pass1, and/or Pass2.
#
#------------------------------------------------------------------------------
all: $(TARGET)

###############################################################################
###############################################################################
#                              Pass targets
#
# Pass targets.  This section contains our definitions for the different
#                build passes.

#------------------------------------------------------------------------------
#
# Pass 0.
#
#------------------------------------------------------------------------------
Pass0:
    @echo ***  Pass 0 complete. ***

#------------------------------------------------------------------------------
#
# Pass 1.
#
#------------------------------------------------------------------------------
Pass1: $(CLEAN_WRAPPED) MFC_TARG COPYMFC
    @echo ***  Pass 1 complete. ***

#------------------------------------------------------------------------------
#
# Pass 2.
#
#------------------------------------------------------------------------------
Pass2:
    @echo ***  Pass 2 complete. ***

###############################################################################
###############################################################################
#                              Worker targets
#
# These targets actually perform the build work.
#


#------------------------------------------------------------------------------
# clean:  Cleans all of our intermediate directories.
#------------------------------------------------------------------------------
clean:
!if "$(PASS0ONLY)"!="1" && "$(LINKONLY)"!="1"
    setlocal
    call $(VCTOOLS)\vcbldenv && $(MAKE) do_clean
    endlocal
!endif

do_clean: MFCBLDENV
    cd $(_LIBSROOT)
    -call buildmfc clean
    -del /s /q $(_LIBSROOT)\ship\atlmfc\mfc.opt\$(PLATFORM)
    cd $(_LIBSROOT)\ship\samples
    -del /s /q *.obj *.pch *.idb *.pdb *.dll *.lib *.exe *.ilk *.map
#   set PATH=$(_MFC_PATH_SAVE)
#   set INCLUDE=$(_MFC_INCLUDE_SAVE)
#   set LIB=$(_MFC_LIB_SAVE)

#------------------------------------------------------------------------------
# build:  Performs the actual compile.
#------------------------------------------------------------------------------
MFC_TARG:
    setlocal
    call $(VCTOOLS)\vcbldenv && $(MAKE) do_build
    endlocal

do_build: MFCBLDENV
    -md $(BINPATH)\nonbbt
    -md $(_LIBSROOT)\ship\atlmfc\src\mfc.bbt\$(PLATFORM)
    -md $(_LIBSROOT)\ship\atlmfc\src\mfc.bbt\$(PLATFORM)\lib
    -md $(_LIBSROOT)\ship\atlmfc\src\mfc.bbt\$(PLATFORM)\$$dll.w
    -md $(_LIBSROOT)\ship\atlmfc\src\mfc.bbt\$(PLATFORM)\$$udll.w
    -md $(_LIBSROOT)\ship\atlmfc\mfc.opt\$(PLATFORM)
    set _OD_EXT=$(_OD_EXT)
!if "$(BUILD_64BIT)" == "1"
    set NOMFCSAMPS=1
    set NOMFCTOOLS=1
!endif
    set DISABLE_MP_BUILD=$(DISABLE_MP_BUILD)
    call buildmfc
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\mfc$(MFC_VER).dll $(BINPATH)\nonbbt
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\mfc$(MFC_VER).pdb $(BINPATH)\nonbbt
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\mfc$(MFC_VER)u.dll $(BINPATH)\nonbbt
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\mfc$(MFC_VER)u.pdb $(BINPATH)\nonbbt
    copy $(_LIBSROOT)\ship\atlmfc\lib\$(PLATFORM)\mfc$(MFC_VER).lib $(BINPATH)\nonbbt
    copy $(_LIBSROOT)\ship\atlmfc\lib\$(PLATFORM)\mfc$(MFC_VER)u.lib $(BINPATH)\nonbbt
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\$$DLL.W\mfc$(MFC_VER).map $(BINPATH)\nonbbt
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\$$UDLL.W\mfc$(MFC_VER)u.map $(BINPATH)\nonbbt
!if "$(BBTBUILD)" == "1"
    set CPU=$(P_ARCH)
    call bbbldmfc NT BuildDLLs clean
!endif
#   set PATH=$(_MFC_PATH_SAVE)
#   set INCLUDE=$(_MFC_INCLUDE_SAVE)
#   set LIB=$(_MFC_LIB_SAVE)


COPYMFC: MFCBLDENV
    setlocal
    -md $(BINPATH)
    -md $(MFCPATH)\src\mfc
    -md $(MFCPATH)\include
    -md $(MFCPATH)\lib\$(ARCH)
    -md $(_LIBSROOT)\ship\atlmfc\src\mfc\mfc.bsc
    -md $(_LIBSROOT)\ship\atlmfc\src\mfc.bbt\$(PLATFORM)
    cd /d $(_LIBSROOT)
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\nafxewd.bsc $(_LIBSROOT)\ship\atlmfc\src\mfc\mfc.bsc
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\*.dll $(BINPATH)
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\*.pdb $(BINPATH)
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\$$DLL.W\mfc$(MFC_VER).map $(BINPATH)
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\$$DLLD.W\mfc$(MFC_VER)d.map $(BINPATH)
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\$$UDLL.W\mfc$(MFC_VER)u.map $(BINPATH)
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\$$UDLLD.W\mfc$(MFC_VER)ud.map $(BINPATH)
!if "$(BUILD_64BIT)" != "1"
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\$(PLATFORM)\mfc$(MFC_VER)*.def $(MFCPATH)\src\mfc
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\pchmark.bin $(MFCPATH)\src\mfc
    copy $(_LIBSROOT)\nonship\src\ErrLook\release\ErrLook.exe $(BINPATH)
    -copy $(_LIBSROOT)\nonship\src\ErrLook\release\ErrLook.pdb $(BINPATH)
    copy $(_LIBSROOT)\nonship\src\ErrLook\release\ErrLook.hlp $(BINPATH)
    copy $(_LIBSROOT)\nonship\src\sproxy\$(PLATFORM)\release\sproxy.exe $(BINPATH)
    copy $(_LIBSROOT)\nonship\src\sproxy\$(PLATFORM)\release\sproxy.pdb $(BINPATH)
    copy $(_LIBSROOT)\nonship\src\vcdeploy\intel\release\VCDeploy.exe $(BINPATH)
    copy $(_LIBSROOT)\nonship\src\vcdeploy\intel\release\VCDeploy.pdb $(BINPATH)
#Copy Sample binaries
    copy $(_LIBSROOT)\Nonship\Src\disco\discohandler\INTEL\Release\discohandler.dll $(BINPATH)
    copy $(_LIBSROOT)\Nonship\Src\disco\discohandler\INTEL\Release\discohandler.pdb $(BINPATH)
    copy $(_LIBSROOT)\Nonship\Src\disco\discomgr\INTEL\Release\discomgr.exe $(BINPATH)
    copy $(_LIBSROOT)\Nonship\Src\disco\discomgr\INTEL\Release\discomgr.pdb $(BINPATH)
    copy "$(_LIBSROOT)\Ship\Samples\C++\ATLMFC\ATL\Advanced\AtlTraceTool\Release\AtlTraceTool.exe" $(BINPATH)
    copy "$(_LIBSROOT)\Ship\Samples\C++\ATLMFC\ATL\Advanced\AtlTraceTool\Release\AtlTraceTool.pdb" $(BINPATH)
    copy "$(_LIBSROOT)\Ship\Samples\C++\ATLMFC\ATL\Advanced\AtlTraceTool\Release\AtlTraceTool.chm" $(BINPATH)
    copy "$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc\ole\TstCon\TCProps\Release\tcprops.dll" $(BINPATH)
    copy "$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc\ole\TstCon\TCProps\Release\tcprops.pdb" $(BINPATH)
    copy "$(_LIBSROOT)\Ship\Samples\C++\ATLMFC\ATL Server\CLStencil\release\CLStencil.exe" $(BINPATH)
    copy "$(_LIBSROOT)\Ship\Samples\C++\ATLMFC\ATL Server\CLStencil\release\CLStencil.pdb" $(BINPATH)
    copy "$(_LIBSROOT)\Ship\Samples\C++\ATLMFC\ATL Server\WebDbg\release\WebDbg.exe" $(BINPATH)
    copy "$(_LIBSROOT)\Ship\Samples\C++\ATLMFC\ATL Server\WebDbg\release\WebDbg.pdb" $(BINPATH)
    copy "$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc\utility\makehm\makehm.exe" $(BINPATH)
    copy "$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc\utility\makehm\makehm.pdb" $(BINPATH)
    copy "$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc\utility\guidgen\guidgen.exe" $(BINPATH)
    copy "$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc\utility\guidgen\guidgen.pdb" $(BINPATH)
    copy "$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc\ole\TstCon\Release\TstCon32.exe" $(BINPATH)
    copy "$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc\ole\TstCon\Release\TstCon32.pdb" $(BINPATH)
    copy "$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc\ole\TstCon\Release\TstCon32.hlp" $(BINPATH)
    copy "$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc\ole\TstCon\Release\TstCon32.cnt" $(BINPATH)
!endif
    copy $(_LIBSROOT)\ship\atlmfc\lib\$(PLATFORM)\*.lib     $(MFCPATH)\lib\$(ARCH)
#Make sure we copy the non-bbt import libs
    copy $(BINPATH)\nonbbt\mfc$(MFC_VER).lib $(MFCPATH)\lib\$(ARCH)
    copy $(BINPATH)\nonbbt\mfc$(MFC_VER)u.lib $(MFCPATH)\lib\$(ARCH)

    copy $(_LIBSROOT)\ship\atlmfc\lib\$(PLATFORM)\*.pdb     $(MFCPATH)\lib\$(ARCH)
    -copy $(_LIBSROOT)\ship\atlmfc\src\mfc\makefile $(MFCPATH)\src\mfc
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\mfc.bsc  $(MFCPATH)\src\mfc
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\*.r*  $(MFCPATH)\src\mfc
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\*.c*  $(MFCPATH)\src\mfc
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\*.h*  $(MFCPATH)\src\mfc
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\*.t*  $(MFCPATH)\src\mfc
    copy $(_LIBSROOT)\ship\atlmfc\src\mfc\*.m*  $(MFCPATH)\src\mfc
    -copy $(_LIBSROOT)\ship\atlmfc\src\mfc\*.i*  $(MFCPATH)\src\mfc
    cd $(_MFCDIR)
    -for /d %%a in (l.*) do xcopy %%a\*.* $(MFCPATH)\src\mfc\%%a\ /seivr
    cd $(_LIBSROOT))
    xcopy $(_LIBSROOT)\ship\atlmfc\include\*.* $(MFCPATH)\include\ /sevr
#   set PATH=$(_MFC_PATH_SAVE)
#   set INCLUDE=$(_MFC_INCLUDE_SAVE)
#   set LIB=$(_MFC_LIB_SAVE)
    endlocal


MFCBLDENV:
    set NTMAKEENV=
!ifndef _LIBSROOT
    set _LIBSROOT=$(VCBASE)\VC7Libs
!endif
    set _LIBSROOT=$(_LIBSROOT)
!ifndef MFCPATH
    set MFCPATH=$(BINDIR)\VC7$(_OD_EXT)\atlmfc
!endif
    set MFCPATH=$(MFCPATH)
!ifndef MFC_VER
    set MFC_VER=80
!endif
    set MFC_VER=$(MFC_VER)
    set _MFCDIR=$(_LIBSROOT)\ship\atlmfc\src\mfc
    set _MFC_PATH_SAVE=$(PATH)
    set _MFC_INCLUDE_SAVE=$(INCLUDE)
    set _MFC_LIB_SAVE=$(LIB)
    set _MSVCDIR=$(_LIBSROOT)
    set _MACDIR=$(VCBASE)
    set _MACDISK=$(VCBASE)
    set _MACDISKDIR=$(VCBASE)
    set PLATFORM=$(PLATFORM)
!if "$(BBTBUILD)" == "1"
!if "$(BBT_REMOTE)" == "1"
    set _SAMPLEDIR=$(_LIBSROOT)\samples\mfc
!else
    set _SAMPLEDIR=$(_LIBSROOT)\ship\samples\C++\atlmfc\mfc
!endif
    set _LEGOBIN=$(PROD_BIN_PATH)
!endif
    set PATH=$(_LIBSROOT)\nonship\build\bin\$(HOSTPLATFORM);$(_LIBSROOT)\nonship\build\bin;$(PATH)
    set LIB=$(_LIBSROOT)\ship\atlmfc\lib\$(PLATFORM);$(LIB)
    set INCLUDE=$(_LIBSROOT)\ship\atlmfc\include;$(VCTOOLS)\nonship\bin\$(P_ARCH)\inc;$(INCLUDE)
!ifndef __ATLMFC_NO_FIXUP__
    set _LINK_=$(_LINK_) /debugtype:cv,fixup
!endif

