SHELL := /bin/bash
ARCH := -m$(shell getconf LONG_BIT)
IDIR := ../grafalgo/include
LDIR := ../grafalgo/lib
WARN := -Wall -Wno-c++11-extensions
CXXFLAGS := ${WARN} ${ARCH} -O2

LIBS := ${LDIR}/lib-ga.a ${LDIR}/lib-ds.a ${LDIR}/lib-util.a

XFILES = checkSpath checkFspath evalRand evalHard
OFILES = checkSpath.o checkFspath.o evalRand.o evalHard.o

.cpp.o:
	${CXX} ${CXXFLAGS} -I ${IDIR} -c $<

all:	${XFILES}

checkSpath: checkSpath.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

checkFspath: checkFspath.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

evalRand: evalRand.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

evalHard: evalHard.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

clean:
	rm -f *.o ${XFILES}
