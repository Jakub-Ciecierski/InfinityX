######################################################################
#--------------------------------------------------------------------#
#---------------------------- COMMENTS ------------------------------#
#--------------------------------------------------------------------#
######################################################################
#
# This Makefile is split into:
# 1) Variables Section
# 	1.1) Dynamic subsection
# 	1.2) Static subsection - DO NOT MODIFY
# 2) Rules Section
# 	2.1) Static subsection - DO NOT MODIFY
# 	2.2) Dynamic subsection
# 3) Dependency Graph - DO NOT MODIFY
#
#
# As a user of this makefile You should not be modifing
# any of the static subsections.
#
#---------------------------------------------------------------------
#
# Compilers supported:
#
# 1) g++
# 2) nvcc
#
#---------------------------------------------------------------------
#
# Supports a particular project structure:
# Refer to Project Structure section to define the following folders:
#
# 1) INC: Header files of this application
# 2) LIB: Your, local Libraries to be linked with application
# 3) BLD: Build where your compiled object files are stored
# 4) SRC: Source files of this application
#
#---------------------------------------------------------------------
#
# Tips:
#
# Use '\' to break new line
# Take special care of whitespaces, it might cause errors.
# $@ is the value of target
# $^ is the list of all prerequisites of the rule
# $< is just the first prerequisite
#
#---------------------------------------------------------------------
#
# TODO:
# (Lack of these features might cause bugs)
#
# Realese / Debug
# Support for gcc for .c files
# Currently only one extension per XX_EXT variable applies
# Support for unit tests
# Variable printouts
# Add usage
#
#---------------------------------------------------------------------
#
# For further information refer to:
# http://www.gnu.org/software/make/manual/make.html
#
######################################################################
#--------------------------------1-----------------------------------#
#------------------------ VARIABLES SECTION -------------------------#
#--------------------------------------------------------------------#
######################################################################

######################################################################
#------------------ DYNAMIC SUBSECTION - CAN MODIFY -----------------#
######################################################################


#----------------- PRINT OUTS -----------------#

# The separator will be printed between compiling objects
INFO_SEPARATOR = "--------------------------------------------------------------------------------"
INFO_FILLER = "\t\t\t\t"

#--------------- LIBRARY NAME -------------#

LIB_NAME = libstdifx
LIB_EXT = .a

#--------------- FILE EXTENSIONS --------------#

# c++ extension
CPP_EXT = .cpp
# cuda extension
CUDA_EXT = .cu

#-------------- PROJECT STRUCTURE -------------#

# Your header files
INC = include
# Your local libraries to be linked with the application
LIB = lib
# Build dumper. All your object files (*.o) will be located here
OBJ = build
# Source files and only source files, subdirectories are supported.
SRC = src

#------------- EXTERNAL MAKEFILES -------------#

# Paths to the Makefiles to be ran before this Makefile.
# Default target will be executed. (TODO verify this)
# Can be used to compile your static libraries before linking
MAKE_EXTERNAL =

#----------------- INCLUDES -------------------#

# Paths to all Includes
INCLUDES += -I /usr/local/cuda/include \
    		-I /opt/cuda/include \
				-I ${INC} -I ../stdifx/include

#------------------- FLAGS --------------------#

C_FLAGS += -g -Wall -std=c++11
NVCC_FLAGS += -arch=sm_20

######################################################################
#------------------ STATIC SUBSECTION - DO NOT MODIFY ---------------#
######################################################################

INCLUDES += -I ${INC}

LIB_CC = ar
CC = g++
NVCC = nvcc

LIB_FLAGS = -cvq
C_FLAGS += ${INCLUDES} -MMD
NVCC_FLAGS +=

# All source files
CPP_SOURCES = $(shell find ${SRC} -name *${CPP_EXT})
CUDA_SOURCES = $(shell find ${SRC} -name *${CUDA_EXT})

# List of all subdirectories in source directory
MODULES = $(shell find ${SRC} -type d)

# All objects to be compiled
OBJECTS += $(addprefix ${OBJ}/,$(notdir $(CPP_SOURCES:${CPP_EXT}=.o)))
OBJECTS += $(addprefix ${OBJ}/,$(notdir $(CUDA_SOURCES:${CUDA_EXT}=.o)))

# Add modules to vpath
VPATH = ${MODULES}

######################################################################
#---------------------------------2----------------------------------#
#------------------------------ RULES -------------------------------#
#--------------------------------------------------------------------#
######################################################################

######################################################################
#------------------ STATIC SUBSECTION - DO NOT MODIFY ---------------#
######################################################################

#------------------ DEFAULT -------------------#

# Release rule
release: $(MAKE_EXTERNAL) info_prefix init_project ${LIB_NAME} info_suffix

#------------------ LINKER --------------------#

${LIB_NAME}: ${OBJECTS} clean_lib
	@${LIB_CC} ${LIB_FLAGS} ${LIB}/${LIB_NAME}${LIB_EXT} ${OBJECTS}

#----------------- COMPILERS ------------------#

# cpp compiler
$(OBJ)/%.o: %${CPP_EXT}
	@echo ${INFO_SEPARATOR}
	@echo 'COMPILING: ' $<
	@echo
	@$(CC) $(C_FLAGS) -c -o $@ $<

# cuda compiler
${OBJ}/%.o: %${CUDA_EXT}
	@echo ${INFO_SEPARATOR}
	@echo 'COMPILING: ' $<
	@echo
	@$(NVCC) $(NVCC_FLAGS) -c -o $@ $<

#------------------ EXTERNALS -----------------#

# Make external makefiles
$(MAKE_EXTERNAL):
	@$(MAKE) -C $@

#---------------- UTILITY RULES ---------------#

# Creates all the directories of the project
init_project:
	@mkdir -p ${OBJ} ${SRC} ${LIB} ${INC}

clean: clean_lib
	@$(RM) *.o *~ ${OBJ}/*.o ${OBJ}/*.d ${OBJ}/*~

clean_lib:
	@${RM} ${LIB}/${LIB_NAME}${LIB_EXT}

.PHONY: $(SUBDIRS) clean

######################################################################
#------------------ DYNAMIC SUBSECTION - CAN MODIFY -----------------#
######################################################################

#----------------- PRINT RULES ----------------#

info_prefix:
	@echo
	@echo
	@echo ${INFO_SEPARATOR}
	@echo ${INFO_SEPARATOR}
	@echo
	@echo ${INFO_FILLER}"MAKING:" ${LIB_NAME}
	@echo
	@echo

info_suffix:
	@echo
	@echo ${INFO_SEPARATOR}
	@echo
	@echo ${INFO_FILLER}"LINKING SUCCESSFULL"
	@echo
	@echo ${INFO_SEPARATOR}
	@echo ${INFO_SEPARATOR}
	@echo

######################################################################
#---------------------------------3----------------------------------#
#---------------- DEPENDENCY GRAPH - DO NOT MODIFY ------------------#
#--------------------------------------------------------------------#
######################################################################

#--------------- DEPENDENCY GRAPH -------------#

# Automatic dependency graph generation
# Must be inserted at the end of the makefile (TODO verify)
-include $(OBJECTS:.o=.d)
