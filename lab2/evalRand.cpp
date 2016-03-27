// usage: evalRand n m
//

#include "stdinc.h"
#include "Flograph.h"
#include "shortPath.h"
#include "fshortPath.h"
#include <list>

using namespace grafalgo;

#include "common.cpp"

int main(int argc, char *argv[]) {
	int n; int m;
	if (argc < 3 ||
	    sscanf(argv[1],"%d",&n) != 1 ||
	    sscanf(argv[2],"%d",&m) != 1 )
		Util::fatal("usage: evalRand n m"); 

	int reps = 10;
	int mss = min(m/n,n/4);
	Flograph fg(n,m);
	flow ecap2 = 2*m; flow ecap1 = ecap2*(n*n)/mss;
	flow floVal;
	Stats stats1, stats2; stats1.set(0); stats2.set(0);
	for (int i = 0; i < reps; i++) {
		fg.rgraph(n,m,mss); fg.randCapacity(ecap1,ecap2);

		shortPath sp1(fg,floVal);
		stats1.add(floVal, sp1.fpCount, sp1.fpSteps,
			  sp1.augCount, sp1.augSteps, sp1.runtime);

		for (edge e = fg.first(); e != 0; e = fg.next(e))
			fg.setFlow(e,0);
        
		fshortPath sp2(fg,floVal);
		stats2.add(floVal, sp2.fpCount, sp2.fpSteps,
			   sp2.augCount, sp2.augSteps, sp2.runtime);
		fg.clear();
	}
	stats1.scale(1.0/reps);
	cout << " random  spath " << n << " " << m << " ";
	stats1.print();

	stats2.scale(1.0/reps);
	cout << " random fspath " << n << " " << m << " ";
	stats2.print();
}
