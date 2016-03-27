// usage: checkEdgeColor
//
// EdgeColor reads a bipartite graph from stdin, and computes a 
// minimal edge coloring. If the optional argument "fast" is specified
// it uses a faster version of the algorithm.
//

#include "fmaxdMatch.h"

using namespace grafalgo;

extern void fedgeColor(Graph& , ClistSet&, maxdMatch::Stats&);

int main(int argc, char *argv[]) {
	Graph graf; cin >> graf;
	ClistSet colorSets(graf.m());

	maxdMatch::Stats stats;
	fedgeColor(graf, colorSets, stats);

	// print stats
	string s;
	cout << stats.toString(s) << endl;

	// print color sets
	edge e; int maxe = 0;
	for (e = graf.first(); e != 0; e = graf.next(e)) 
		maxe = max(e,maxe);
	bool done[maxe+1];
	for (e = graf.first(); e != 0; e = graf.next(e)) 
		done[e] = false;
	e = graf.first();
	while (e != 0) {
		cout << "{" << graf.edge2string(e,s);
		done[e] = true;
		edge ee;
		for (ee = colorSets.suc(e); ee != e; ee = colorSets.suc(ee)) {
			cout << ", " << graf.edge2string(ee,s);
			done[ee] = true;
		}
		cout << "}\n";
		while (e != 0 && done[e]) e = graf.next(e);
	}
}	
