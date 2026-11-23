#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

PROJ = TheProvider
all:    $(OUTDIR) $(OUTDIR)\$(PROJ).dll

$(OUTDIR):
     if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

EXTRA_LIBS = odbccp32.lib odbc32.lib shell32.lib advapi32.lib

LINK32_OBJS = $(OUTDIR)\stdafx.obj \
              $(OUTDIR)\theprovider.obj \
              $(OUTDIR)\msomniprovrs.obj \
              $(OUTDIR)\crow.obj \
              $(OUTDIR)\cdbfile.obj \
              $(OUTDIR)\theprovider.res

$(OUTDIR)\theprovider.h : theprovider.idl
     $(midl) /h $(OUTDIR)\theprovider.h /tlb $(OUTDIR)\theprovider.tlb /iid $(OUTDIR)\theprovider_i.c theprovider.idl

$(OUTDIR)\stdafx.obj:     stdafx.cpp
     $(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /D_ATL_MIN_CRT /D_ATL_STATIC_REGISTRY /D_USRDLL /D_MBCS /Yc"stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I$(OUTDIR) stdafx.cpp

.cpp{$(OUTDIR)}.obj:
     $(cc) $(cflags) $(cdebug) $(cvarsdll) /Gm /D_ATL_MIN_CRT /D_ATL_STATIC_REGISTRY /D_USRDLL /D_MBCS /Yu"stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I$(OUTDIR) $**

$(OUTDIR)\theprovider.res:
     $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\theprovider.res /I$(OUTDIR) theprovider.rc

$(OUTDIR)\$(PROJ).dll:   $(OUTDIR)\theprovider.h $(LINK32_OBJS)
     $(link) $(ldebug) $(dlllflags) /MACHINE:$(CPU) /PDB:$(OUTDIR)\$(PROJ).pdb -out:$(OUTDIR)\$(PROJ).dll /DEF:theprovider.def  $(LINK32_OBJS) $(EXTRA_LIBS) $(baselibs) $(olelibs) 

clean:
     $(CLEANUP)
