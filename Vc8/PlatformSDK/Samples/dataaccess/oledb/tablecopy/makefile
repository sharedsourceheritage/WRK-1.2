#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

PROJ = TableCopy
all:    $(OUTDIR) $(OUTDIR)\$(PROJ).exe

$(OUTDIR):
     if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

EXTRA_LIBS = comctl32.lib msvcrt.lib odbccp32.lib odbc32.lib shell32.lib advapi32.lib oledb.lib

LINK32_OBJS = $(OUTDIR)\wizard.obj \
              $(OUTDIR)\winmain.obj \
              $(OUTDIR)\tablecopy.obj \
              $(OUTDIR)\table.obj \
              $(OUTDIR)\step4.obj \
              $(OUTDIR)\step3.obj \
              $(OUTDIR)\step2.obj \
              $(OUTDIR)\step1.obj \
              $(OUTDIR)\spy.obj \
              $(OUTDIR)\property.obj \
              $(OUTDIR)\progress.obj \
              $(OUTDIR)\error.obj \
              $(OUTDIR)\datasource.obj \
              $(OUTDIR)\common.obj \
              $(OUTDIR)\tablecopy.res

.cpp{$(OUTDIR)}.obj:
     $(cc) $(cflags) $(cdebug) $(cvarsdll) /Gi /Gm /WX /GX /DFINDLEAKS /I"..\..\INCLUDE" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

$(OUTDIR)\tablecopy.res:
     $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\tablecopy.res tablecopy.rc

$(OUTDIR)\$(PROJ).exe:   $(LINK32_OBJS)
     $(link) $(ldebug) $(guilflags) /MACHINE:$(CPU) /PDB:$(OUTDIR)\$(PROJ).pdb -out:$(OUTDIR)\$(PROJ).exe $(LINK32_OBJS) $(EXTRA_LIBS) $(baselibs) $(olelibs) 

clean:
     $(CLEANUP)
