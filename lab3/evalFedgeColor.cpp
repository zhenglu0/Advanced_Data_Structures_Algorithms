// usage: evalEdgeColor n m
//
// EvalMaxdMatch reads a bipartite graph from stdin, and computes a 
// minimal edge coloring.
//

#include "fmaxdMatch.h"

using namespace grafalgo;

extern void fedgeColor(Graph&, ClistSet&, maxdMatch::Stats&);

string& statString(int val, int reps, string& s) {
	double avg = ((double) val)/reps;
	stringstream ss;
	
    if (avg >= 1000000)
		ss << setprecision(3) << (avg/1000000) << "sec";
	else if (avg >= 1000)
		ss << setprecision(3) << (avg/1000) << "ms";
	else 
		ss << setprecision(3) << avg << "us";
    
    //ss << avg;
    
	s = " " + ss.str();
	return s;
}

int main(int argc, char *argv[]) {
	int n, m;
	if (argc != 3 ||
	    sscanf(argv[1],"%d",&n) != 1 ||
	    sscanf(argv[2],"%d",&m) != 1)
		Util::fatal("usage: evalEdgeColor n m");
	
	int reps = 10;
	Graph graf;
	maxdMatch::Stats stats, tstats;
	ClistSet colorSets(m);
	int ecTotal = 0;
	for (int i = 1; i <= reps; i++) {
		graf.rbigraph(n,n,m);
		int t0 = Util::getTime();
		fedgeColor(graf, colorSets, stats);
		ecTotal += Util::getTime() - t0;
		tstats.add(stats);
	}
	string s;
	cout << n << " " << m << statString(tstats.maxdInit,reps,s);
	cout << statString(tstats.fpInit,reps,s);
	cout << statString(tstats.fpLoop,reps,s);
	cout << statString(tstats.extend,reps,s);
	cout << statString(tstats.total,reps,s);
	cout << statString(ecTotal,reps,s) << endl;
}	
