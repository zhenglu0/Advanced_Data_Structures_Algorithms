// usage: badcase n m

#include "stdinc.h"
#include "Wgraph.h"
#include <list>

using namespace grafalgo;

#include "common.cpp"

int main(int argc, char *argv[]) {
	int n, m;
	if (argc < 3 ||
	    sscanf(argv[1],"%d",&n) != 1 ||
	    sscanf(argv[2],"%d",&m) != 1)
		Util::fatal("usage: badcase n m"); 

	Wgraph wg(n,m);
	badcase(n,m,wg);
	cout << wg;
}
