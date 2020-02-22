##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Chapter_8_Statements_Ex_83
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=E:/Dokumenty_ZbynA/Cpp_Pokusy/CodeLite/Projekty
ProjectPath            :=E:/Dokumenty_ZbynA/Cpp_Pokusy/CodeLite/Projekty/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83
IntermediateDirectory  :=../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83
OutDir                 :=../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=decak
Date                   :=22/02/2020
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
CXXFLAGS :=  -pedantic-errors -g -O0 -fexceptions -std=c++2a -Wall -Weffc++ -Werror -Wsign-conversion -Wextra $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\Program Files\CodeLite
Objects0=../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/primenumbers.cpp$(ObjectSuffix) ../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/main.cpp$(ObjectSuffix) ../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/fibonaci.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/.d $(Objects) 
	@if not exist "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_8_Statements\Chapter_8_Statements_Ex_83" mkdir "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_8_Statements\Chapter_8_Statements_Ex_83"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_8_Statements\Chapter_8_Statements_Ex_83" mkdir "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_8_Statements\Chapter_8_Statements_Ex_83"
	@if not exist ""..\..\..\build-$(ConfigurationName)\bin"" mkdir ""..\..\..\build-$(ConfigurationName)\bin""

../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/.d:
	@if not exist "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_8_Statements\Chapter_8_Statements_Ex_83" mkdir "..\..\..\build-$(ConfigurationName)\Crash_Course\Chapter_8_Statements\Chapter_8_Statements_Ex_83"

PreBuild:


##
## Objects
##
../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/primenumbers.cpp$(ObjectSuffix): primenumbers.cpp ../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/primenumbers.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Dokumenty_ZbynA/Cpp_Pokusy/CodeLite/Projekty/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/primenumbers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/primenumbers.cpp$(ObjectSuffix) $(IncludePath)
../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/primenumbers.cpp$(DependSuffix): primenumbers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/primenumbers.cpp$(ObjectSuffix) -MF../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/primenumbers.cpp$(DependSuffix) -MM primenumbers.cpp

../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/primenumbers.cpp$(PreprocessSuffix): primenumbers.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/primenumbers.cpp$(PreprocessSuffix) primenumbers.cpp

../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/main.cpp$(ObjectSuffix): main.cpp ../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Dokumenty_ZbynA/Cpp_Pokusy/CodeLite/Projekty/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/main.cpp$(ObjectSuffix) -MF../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/main.cpp$(DependSuffix) -MM main.cpp

../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/main.cpp$(PreprocessSuffix) main.cpp

../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/fibonaci.cpp$(ObjectSuffix): fibonaci.cpp ../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/fibonaci.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Dokumenty_ZbynA/Cpp_Pokusy/CodeLite/Projekty/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/fibonaci.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fibonaci.cpp$(ObjectSuffix) $(IncludePath)
../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/fibonaci.cpp$(DependSuffix): fibonaci.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/fibonaci.cpp$(ObjectSuffix) -MF../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/fibonaci.cpp$(DependSuffix) -MM fibonaci.cpp

../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/fibonaci.cpp$(PreprocessSuffix): fibonaci.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83/fibonaci.cpp$(PreprocessSuffix) fibonaci.cpp


-include ../../../build-$(ConfigurationName)/Crash_Course/Chapter_8_Statements/Chapter_8_Statements_Ex_83//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


