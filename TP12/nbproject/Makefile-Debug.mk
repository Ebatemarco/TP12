#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/5d8126cf/termlib.o \
	${OBJECTDIR}/Main\ TP12.o \
	${OBJECTDIR}/emuladordepuertos.o \
	${OBJECTDIR}/hardware.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs glib-2.0`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tp12

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tp12: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tp12 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/5d8126cf/termlib.o: ../../../../termlib.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5d8126cf
	${RM} "$@.d"
	$(COMPILE.c) -g `pkg-config --cflags glib-2.0`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5d8126cf/termlib.o ../../../../termlib.c

.NO_PARALLEL:${OBJECTDIR}/Main\ TP12.o
${OBJECTDIR}/Main\ TP12.o: Main\ TP12.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g `pkg-config --cflags glib-2.0`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Main\ TP12.o Main\ TP12.c

${OBJECTDIR}/emuladordepuertos.o: emuladordepuertos.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g `pkg-config --cflags glib-2.0`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/emuladordepuertos.o emuladordepuertos.c

${OBJECTDIR}/hardware.o: hardware.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g `pkg-config --cflags glib-2.0`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hardware.o hardware.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
