SHELL := /bin/bash
ARCH := -m$(shell getconf LONG_BIT)
IDIR := ../grafalgo/include
LDIR := ../grafalgo/lib
WARN := -Wall -Wno-c++11-extensions
CXXFLAGS := ${WARN} ${ARCH} -O2

LIBS := ${LDIR}/lib-ga.a ${LDIR}/lib-ds.a ${LDIR}/lib-util.a

XFILES = checkMaxdMatch checkEdgeColor checkFedgeColor \
	evalEdgeColor evalFedgeColor checkFMaxdMatch
OFILES = checkMaxdMatch.o checkEdgeColor.o checkFedgeColor.o \
	evalEdgeColor.o evalFedgeColor.o checkFMaxdMatch.o

.cpp.o:
	${CXX} ${CXXFLAGS} -I ${IDIR} -c $<

all:	${XFILES}

checkMaxdMatch: checkMaxdMatch.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

checkFMaxdMatch: checkFMaxdMatch.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

checkEdgeColor: checkEdgeColor.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

checkFedgeColor: checkFedgeColor.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

evalEdgeColor: evalEdgeColor.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

evalFedgeColor: evalFedgeColor.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

clean:
	rm -f *.o ${XFILES}
