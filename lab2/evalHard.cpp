// usage: evalHard n m
//

#include "stdinc.h"
#include "Flograph.h"
#include "shortPath.h"
#include "fshortPath.h"
#include <list>

using namespace grafalgo;

#include "common.cpp"
#include "hardFlograph.cpp"

extern void hardFlograph(int,int,Flograph&);

int main(int argc, char *argv[]) {
	int k1, k2;
	if (argc < 3 ||
	    sscanf(argv[1],"%d",&k1) != 1 ||
	    sscanf(argv[2],"%d",&k2) != 1 )
		Util::fatal("usage: evalHard k1 k2"); 

	flow floVal;
	Flograph fg;
	Stats stats1, stats2;
	hardFlograph(k1,k2,fg);

	shortPath sp1(fg,floVal);
	stats1.set(floVal, sp1.fpCount, sp1.fpSteps,
		   sp1.augCount, sp1.augSteps, sp1.runtime);

	for (edge e = fg.first(); e != 0; e = fg.next(e))
		fg.setFlow(e,0);

	fshortPath sp2(fg,floVal);
	stats2.set(floVal, sp2.fpCount, sp2.fpSteps,
		   sp2.augCount, sp2.augSteps, sp2.runtime);

	cout << "   hard  spath " << k1 << " " << k2 << " "
	     << fg.n() << " " << fg.m() << " ";
	stats1.print();

	cout << "   hard fspath " << k1 << " " << k2 << " "
	     << fg.n() << " " << fg.m() << " ";
	stats2.print();
}
