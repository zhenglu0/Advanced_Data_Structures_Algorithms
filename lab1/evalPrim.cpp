// usage: evalPrim n m d
//

#include "stdinc.h"
#include "Wgraph.h"
#include <list>

using namespace grafalgo;

#include "common.cpp"

int main(int argc, char *argv[]) {
	int n, m, d;
	if (argc < 4 ||
	    sscanf(argv[1],"%d",&n) != 1 ||
	    sscanf(argv[2],"%d",&m) != 1 ||
	    sscanf(argv[3],"%d",&d) != 1)
		Util::fatal("usage: evalPrim n m d"); 

	int reps = 10;
	PrimStats stats, tots, mins, maxs;
	tots.set(0); mins.set(Util::BIGINT32); maxs.set(0);
	Wgraph wg(n,m);
	list<edge> mstree;
	for (int i = 0; i < reps; i++) {
		wg.rcgraph(n,m); wg.randWeight(0,10*m);
		prim(wg,mstree,d,stats);

		tots.ckCount += stats.ckCount;
		tots.suCount += stats.suCount;
		tots.sdCount += stats.sdCount;
		tots.runtime += stats.runtime;

		mins.ckCount = min(mins.ckCount,stats.ckCount);
		mins.suCount = min(mins.suCount,stats.suCount);
		mins.sdCount = min(mins.sdCount,stats.sdCount);
		mins.runtime = min(mins.runtime,stats.runtime);

		maxs.ckCount = max(maxs.ckCount,stats.ckCount);
		maxs.suCount = max(maxs.suCount,stats.suCount);
		maxs.sdCount = max(maxs.sdCount,stats.sdCount);
		maxs.runtime = max(maxs.runtime,stats.runtime);
	
		wg.clear(); mstree.clear();
	}
	cout << "   random " << n << " " << m << " " << d << " "
	     << ((double) tots.ckCount)/reps << " ("
	     << mins.ckCount << "," << maxs.ckCount << ") "
	     << ((double) tots.suCount)/reps << " ("
	     << mins.suCount << "," << maxs.suCount << ") "
	     << ((double) tots.sdCount)/reps << " ("
	     << mins.sdCount << "," << maxs.sdCount << ") "
	     << ((double) tots.runtime)/reps << " ("
	     << mins.runtime << "," << maxs.runtime << ")" << endl;

	tots.set(0); mins.set(Util::BIGINT32); maxs.set(0);
	for (int i = 0; i < reps; i++) {
		badcase(n,m,wg);
		prim(wg,mstree,d,stats);

		tots.ckCount += stats.ckCount;
		tots.suCount += stats.suCount;
		tots.sdCount += stats.sdCount;
		tots.runtime += stats.runtime;

		mins.ckCount = min(mins.ckCount,stats.ckCount);
		mins.suCount = min(mins.suCount,stats.suCount);
		mins.sdCount = min(mins.sdCount,stats.sdCount);
		mins.runtime = min(mins.runtime,stats.runtime);

		maxs.ckCount = max(maxs.ckCount,stats.ckCount);
		maxs.suCount = max(maxs.suCount,stats.suCount);
		maxs.sdCount = max(maxs.sdCount,stats.sdCount);
		maxs.runtime = max(maxs.runtime,stats.runtime);

		wg.clear(); mstree.clear();
	}
	cout << "  badcase " << n << " " << m << " " << d << " "
	     << ((double) tots.ckCount)/reps << " ("
	     << mins.ckCount << "," << maxs.ckCount << ") "
	     << ((double) tots.suCount)/reps << " ("
	     << mins.suCount << "," << maxs.suCount << ") "
	     << ((double) tots.sdCount)/reps << " ("
	     << mins.sdCount << "," << maxs.sdCount << ") "
	     << ((double) tots.runtime)/reps << " ("
	     << mins.runtime << "," << maxs.runtime << ")" << endl;
		
	tots.set(0); mins.set(Util::BIGINT32); maxs.set(0);
	for (int i = 0; i < reps; i++) {
		worsecase(n,m,wg);
		prim(wg,mstree,d,stats);

		tots.ckCount += stats.ckCount;
		tots.suCount += stats.suCount;
		tots.sdCount += stats.sdCount;
		tots.runtime += stats.runtime;

		mins.ckCount = min(mins.ckCount,stats.ckCount);
		mins.suCount = min(mins.suCount,stats.suCount);
		mins.sdCount = min(mins.sdCount,stats.sdCount);
		mins.runtime = min(mins.runtime,stats.runtime);

		maxs.ckCount = max(maxs.ckCount,stats.ckCount);
		maxs.suCount = max(maxs.suCount,stats.suCount);
		maxs.sdCount = max(maxs.sdCount,stats.sdCount);
		maxs.runtime = max(maxs.runtime,stats.runtime);
	
		wg.clear(); mstree.clear();
	}
	cout << "worsecase " << n << " " << m << " " << d << " "
	     << ((double) tots.ckCount)/reps << " ("
	     << mins.ckCount << "," << maxs.ckCount << ") "
	     << ((double) tots.suCount)/reps << " ("
	     << mins.suCount << "," << maxs.suCount << ") "
	     << ((double) tots.sdCount)/reps << " ("
	     << mins.sdCount << "," << maxs.sdCount << ") "
	     << ((double) tots.runtime)/reps << " ("
	     << mins.runtime << "," << maxs.runtime << ")" << endl;
}
