SHELL := /bin/bash
ARCH := -m$(shell getconf LONG_BIT)
IDIR := ../grafalgo/include
LDIR := ../grafalgo/lib
WARN := -Wall -Wno-c++11-extensions
CXXFLAGS := ${WARN} ${ARCH} -O2

LIBS := ${LDIR}/lib-ga.a ${LDIR}/lib-ds.a ${LDIR}/lib-util.a

XFILES = checkPrim badcase worsecase evalPrim
OFILES = checkPrim.o badcase.o worsecase.o evalPrim.o

${OFILES} : common.cpp

.cpp.o:
	${CXX} ${CXXFLAGS} -I ${IDIR} -c $<

all:	${XFILES}

checkPrim: checkPrim.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

badcase: badcase.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

worsecase: worsecase.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

evalPrim: evalPrim.o ${LIBS}
	${CXX} ${CXXFLAGS} $< ${LIBS} -o $@

clean:
	rm -f *.o ${XFILES}
