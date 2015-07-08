#######################################################
#File: Makefile
#Description: Compiles of files necessary for lab4
#Used TA robust make_file for reference
########################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall

#CXXFLAGS += -g

SRC1 = FinalProj.cpp character.cpp dice.cpp derived_classes.cpp
SRCS = ${SRC1} ${SRC2}

HEADERS = character.hpp dice.hpp derived_classes.hpp

PROG1 = FinalProj

DOCS = finalProj_writeup.pdf

TAR = cs162_finalProj_pfisterl.tar.bz2

ZIP = cs162_finalProj_pfisterl

FinalProj: ${SRC1} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRC1} -o ${PROG1}

tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOCS} makefile 

zip:
	zip ${ZIP} ${SRCS} ${HEADERS} ${DOCS} makefile