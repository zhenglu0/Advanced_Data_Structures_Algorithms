// usage: checkFspath <flograph
//

#include "Flograph.h"
#include "fshortPath.h"
#include <list>

using namespace grafalgo;

#include "common.cpp"

int main(int argc, char *argv[]) {
	Flograph fg; cin >> fg;
	int floVal;

	int verbose = 0;
	if (argc > 1 && string("verbose") == argv[1]) verbose = 1;

	fshortPath sp(fg,floVal);

	if (verbose) cout << fg << endl;

	cout << "stats " << floVal << " "
	     << sp.fpCount << " " << sp.fpSteps << " "
	     << sp.augCount << " " << sp.augSteps << " "
	     << sp.runtime << endl;
}
