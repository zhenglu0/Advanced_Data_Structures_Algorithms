// usage: checkPrim <weighted_graph
//

#include "Wgraph.h"
#include <list>

using namespace grafalgo;

#include "common.cpp"

int main(int argc, char *argv[]) {
	Wgraph wg; cin >> wg;
	list<edge> mstree;
	PrimStats stats;
	prim(wg,mstree,2,stats);

	int verbose = 0;
	if (argc > 1 && string("verbose") == argv[1]) verbose = 1;

	if (verbose) cout << wg << endl;
	string s;
	if (verbose) cout << wg.elist2string(mstree,s) << endl;

	cout << "stats " << stats.ckCount << " " << stats.suCount << " "
	     << stats.sdCount << " " << stats.runtime << endl;
}
