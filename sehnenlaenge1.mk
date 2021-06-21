##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=sehnenlaenge1
ConfigurationName      :=Release
WorkspacePath          :=/home/josef/Programmieren/Codeblocks/METALL/SEHNENLAENGE-VERSIONEN/Sehnenlaenge1
ProjectPath            :=/home/josef/Programmieren/Codeblocks/METALL/SEHNENLAENGE-VERSIONEN/Sehnenlaenge1/sehnenlaenge1
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Josef Wismeth 
Date                   :=09/05/21
CodeLitePath           :=/home/josef/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="sehnenlaenge1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/sehne.cpp$(ObjectSuffix) $(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/SEHNENLAENGE-VERSIONEN/Sehnenlaenge1/sehnenlaenge1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/sehne.cpp$(ObjectSuffix): sehne.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sehne.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sehne.cpp$(DependSuffix) -MM sehne.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/SEHNENLAENGE-VERSIONEN/Sehnenlaenge1/sehnenlaenge1/sehne.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sehne.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sehne.cpp$(PreprocessSuffix): sehne.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sehne.cpp$(PreprocessSuffix) sehne.cpp

$(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix): menuefrage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/menuefrage.cpp$(DependSuffix) -MM menuefrage.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/SEHNENLAENGE-VERSIONEN/Sehnenlaenge1/sehnenlaenge1/menuefrage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/menuefrage.cpp$(PreprocessSuffix): menuefrage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/menuefrage.cpp$(PreprocessSuffix) menuefrage.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


