##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Chapter_6_Ex_64
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=E:/Dokumenty_ZbynA/Cpp_Pokusy/CodeLite/Projekty
ProjectPath            :=E:/Dokumenty_ZbynA/Cpp_Pokusy/CodeLite/Projekty/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64
IntermediateDirectory  :=../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64
OutDir                 :=../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=decak
Date                   :=02/02/2020
CodeLitePath           :="E:/Program Files/CodeLite"
LinkerName             :=E:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=E:/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\..\..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=E:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := E:/msys64/mingw64/bin/ar.exe rcu
CXX      := E:/msys64/mingw64/bin/g++.exe
CC       := E:/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall -pedantic-errors -g -O0 -std=c++14 -Wall -Weffc++ -Werror -Wsign-conversion -Wextra -g  -fexceptions $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\Program Files\CodeLite
Objects0=../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/.d $(Objects) 
	@if not exist "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_6_Compiletime_Polymorphism\Chapter_6_Ex_64" mkdir "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_6_Compiletime_Polymorphism\Chapter_6_Ex_64"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_6_Compiletime_Polymorphism\Chapter_6_Ex_64" mkdir "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_6_Compiletime_Polymorphism\Chapter_6_Ex_64"
	@if not exist ""..\..\..\build-$(ConfigurationName)\bin"" mkdir ""..\..\..\build-$(ConfigurationName)\bin""

../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/.d:
	@if not exist "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_6_Compiletime_Polymorphism\Chapter_6_Ex_64" mkdir "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_6_Compiletime_Polymorphism\Chapter_6_Ex_64"

PreBuild:


##
## Objects
##
../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/main.cpp$(ObjectSuffix): main.cpp ../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Dokumenty_ZbynA/Cpp_Pokusy/CodeLite/Projekty/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/main.cpp$(ObjectSuffix) -MF../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/main.cpp$(DependSuffix) -MM main.cpp

../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64/main.cpp$(PreprocessSuffix) main.cpp


-include ../../../build-$(ConfigurationName)/Crash_Course/Chapter_6_Compiletime_Polymorphism/Chapter_6_Ex_64//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


