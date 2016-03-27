// usage: worsecase n m

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
		Util::fatal("usage: worsecase n m"); 

	Wgraph wg(n,m);
	worsecase(n,m,wg);
	cout << wg;
}
