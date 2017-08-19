# Microsoft Developer Studio Generated NMAKE File, Based on Ly.dsp
!IF "$(CFG)" == ""
CFG=Ly - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Ly - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Ly - Win32 Release" && "$(CFG)" != "Ly - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Ly.mak" CFG="Ly - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Ly - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Ly - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Ly - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Ly.exe"


CLEAN :
	-@erase "$(INTDIR)\Ellip.obj"
	-@erase "$(INTDIR)\Layer.obj"
	-@erase "$(INTDIR)\Line.obj"
	-@erase "$(INTDIR)\Ly.obj"
	-@erase "$(INTDIR)\Ly.pch"
	-@erase "$(INTDIR)\Ly.res"
	-@erase "$(INTDIR)\LyDoc.obj"
	-@erase "$(INTDIR)\LyView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\Penc.obj"
	-@erase "$(INTDIR)\PolyGon.obj"
	-@erase "$(INTDIR)\PolyLine.obj"
	-@erase "$(INTDIR)\Rectangle.obj"
	-@erase "$(INTDIR)\RoundRect.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Ly.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Ly.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\Ly.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Ly.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Ly.pdb" /machine:I386 /out:"$(OUTDIR)\Ly.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Ellip.obj" \
	"$(INTDIR)\Layer.obj" \
	"$(INTDIR)\Line.obj" \
	"$(INTDIR)\Ly.obj" \
	"$(INTDIR)\LyDoc.obj" \
	"$(INTDIR)\LyView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Penc.obj" \
	"$(INTDIR)\PolyLine.obj" \
	"$(INTDIR)\Rectangle.obj" \
	"$(INTDIR)\RoundRect.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Ly.res" \
	"$(INTDIR)\PolyGon.obj"

"$(OUTDIR)\Ly.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Ly.exe" "$(OUTDIR)\Ly.bsc"


CLEAN :
	-@erase "$(INTDIR)\Ellip.obj"
	-@erase "$(INTDIR)\Ellip.sbr"
	-@erase "$(INTDIR)\Layer.obj"
	-@erase "$(INTDIR)\Layer.sbr"
	-@erase "$(INTDIR)\Line.obj"
	-@erase "$(INTDIR)\Line.sbr"
	-@erase "$(INTDIR)\Ly.obj"
	-@erase "$(INTDIR)\Ly.pch"
	-@erase "$(INTDIR)\Ly.res"
	-@erase "$(INTDIR)\Ly.sbr"
	-@erase "$(INTDIR)\LyDoc.obj"
	-@erase "$(INTDIR)\LyDoc.sbr"
	-@erase "$(INTDIR)\LyView.obj"
	-@erase "$(INTDIR)\LyView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\Penc.obj"
	-@erase "$(INTDIR)\Penc.sbr"
	-@erase "$(INTDIR)\PolyGon.obj"
	-@erase "$(INTDIR)\PolyGon.sbr"
	-@erase "$(INTDIR)\PolyLine.obj"
	-@erase "$(INTDIR)\PolyLine.sbr"
	-@erase "$(INTDIR)\Rectangle.obj"
	-@erase "$(INTDIR)\Rectangle.sbr"
	-@erase "$(INTDIR)\RoundRect.obj"
	-@erase "$(INTDIR)\RoundRect.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Ly.bsc"
	-@erase "$(OUTDIR)\Ly.exe"
	-@erase "$(OUTDIR)\Ly.ilk"
	-@erase "$(OUTDIR)\Ly.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Ly.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\Ly.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Ly.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Ellip.sbr" \
	"$(INTDIR)\Layer.sbr" \
	"$(INTDIR)\Line.sbr" \
	"$(INTDIR)\Ly.sbr" \
	"$(INTDIR)\LyDoc.sbr" \
	"$(INTDIR)\LyView.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\Penc.sbr" \
	"$(INTDIR)\PolyLine.sbr" \
	"$(INTDIR)\Rectangle.sbr" \
	"$(INTDIR)\RoundRect.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\PolyGon.sbr"

"$(OUTDIR)\Ly.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Ly.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Ly.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Ellip.obj" \
	"$(INTDIR)\Layer.obj" \
	"$(INTDIR)\Line.obj" \
	"$(INTDIR)\Ly.obj" \
	"$(INTDIR)\LyDoc.obj" \
	"$(INTDIR)\LyView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Penc.obj" \
	"$(INTDIR)\PolyLine.obj" \
	"$(INTDIR)\Rectangle.obj" \
	"$(INTDIR)\RoundRect.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Ly.res" \
	"$(INTDIR)\PolyGon.obj"

"$(OUTDIR)\Ly.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Ly.dep")
!INCLUDE "Ly.dep"
!ELSE 
!MESSAGE Warning: cannot find "Ly.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Ly - Win32 Release" || "$(CFG)" == "Ly - Win32 Debug"
SOURCE=.\Ellip.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\Ellip.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\Ellip.obj"	"$(INTDIR)\Ellip.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\Layer.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\Layer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\Layer.obj"	"$(INTDIR)\Layer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\Line.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\Line.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\Line.obj"	"$(INTDIR)\Line.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\Ly.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\Ly.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\Ly.obj"	"$(INTDIR)\Ly.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\Ly.rc

"$(INTDIR)\Ly.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\LyDoc.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\LyDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\LyDoc.obj"	"$(INTDIR)\LyDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\LyView.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\LyView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\LyView.obj"	"$(INTDIR)\LyView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\Penc.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\Penc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\Penc.obj"	"$(INTDIR)\Penc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\PolyGon.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\PolyGon.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\PolyGon.obj"	"$(INTDIR)\PolyGon.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\PolyLine.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\PolyLine.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\PolyLine.obj"	"$(INTDIR)\PolyLine.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\Rectangle.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\Rectangle.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\Rectangle.obj"	"$(INTDIR)\Rectangle.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\RoundRect.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"


"$(INTDIR)\RoundRect.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"


"$(INTDIR)\RoundRect.obj"	"$(INTDIR)\RoundRect.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ly.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Ly - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Ly.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Ly.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Ly - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Ly.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\Ly.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

