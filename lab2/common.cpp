class Stats {
public:
	flow floVal;
	int fpCount;
	int fpSteps;
	int augCount;
	int augSteps;
	int runtime;

	void set(int x) { 
		floVal = fpCount = fpSteps = augCount = augSteps = runtime = x;
	};

	void set(flow fv, int fpc, int fps, int augc, int augs, int rt) { 
		floVal = fv;
		fpCount = fpc; fpSteps = fps;
		augCount = augc; augSteps = augs;
		runtime = rt;
	};

	void add(flow fv, int fpc, int fps, int augc, int augs, int rt) { 
		floVal += fv; fpCount += fpc; fpSteps += fps;
		augCount += augc; augSteps += augs; runtime += rt;
	};

	void scale(double x) {
		floVal *= x; fpCount *= x; fpSteps *= x;
		augCount *= x; augSteps *= x; runtime *= x;
	};

	void print() {
		cout << floVal << " " << fpCount << " " << fpSteps << " "
		     << augCount << " " << augSteps << " " << runtime << endl;
	}
};
