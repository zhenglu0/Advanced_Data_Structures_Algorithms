// usage: fcheckMaxdMatch
//
// checkMaxdMatch reads a bipartite graph from stdin, and computes a 
// matching that includes an edge incident to every vertex of maximum
// degree. 

#include "fmaxdMatch.h"

using namespace grafalgo;

extern void fedgeColor(Graph& , ClistSet&);

int main(int argc, char *argv[]) {
	Graph graf; cin >> graf;
	Dlist match(graf.m());
	maxdMatch::Stats stats;
	
	fmaxdMatch(graf, match, stats);

	string s;
	cout << stats.toString(s) << endl;
	cout << graf.elist2string(match,s) << endl;
}	
