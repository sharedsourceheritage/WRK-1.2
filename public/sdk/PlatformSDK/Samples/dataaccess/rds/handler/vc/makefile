#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

PROJ = msdfmap
all:    $(OUTDIR) $(OUTDIR)\$(PROJ).dll

$(OUTDIR):
     if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

EXTRA_LIBS = msvcrtd.lib odbccp32.lib odbc32.lib shell32.lib advapi32.lib

LINK32_OBJS = $(OUTDIR)\util.obj \
              $(OUTDIR)\stdafx.obj \
              $(OUTDIR)\msdfmap.obj \
              $(OUTDIR)\handler.obj \
              $(OUTDIR)\const.obj \
              $(OUTDIR)\msdfmap.res

$(OUTDIR)\msdfhdl.h : msdfhdl.idl
     $(midl) /h $(OUTDIR)\msdfhdl.h /tlb $(OUTDIR)\msdfhdl.tlb /iid $(OUTDIR)\msdfhdl_i.c msdfhdl.idl

.cpp{$(OUTDIR)}.obj:
     $(cc) $(cflags) $(cdebug) $(cvarsdll) /Gy /Gf /Gm /WX /GX /Gt0 /D_UNICODE" /DMICROSOFT_INTERNAL_BUILD /DUTILTEST /D_UNICODE /DMDACBETAVER /DBETAVER /D_USRDLL /DMDACVER /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I$(OUTDIR) $**

$(OUTDIR)\msdfmap.res:
     $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\msdfmap.res /I$(OUTDIR) msdfmap.rc

$(OUTDIR)\$(PROJ).dll:   $(OUTDIR)\msdfhdl.h $(LINK32_OBJS)
     $(link) $(ldebug) $(dlllflags) /MACHINE:$(CPU) /PDB:$(OUTDIR)\$(PROJ).pdb -out:$(OUTDIR)\$(PROJ).dll /DEF:msdfmap.def  $(LINK32_OBJS) $(EXTRA_LIBS) $(baselibs) $(olelibs) 

clean:
     $(CLEANUP)
