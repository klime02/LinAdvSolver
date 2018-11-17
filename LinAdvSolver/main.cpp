#include <math.h>
#include <vector>
#include <iostream>
#include "Scheme.h"
#include "ExplicitScheme.h"
#include "ImplicitScheme.h"
using namespace std;

int main() {
	double deltaX = 5.0;
	double deltaT002 = 0.01;
	double tMax = 0.5;
	double current_t = 0.5;
	Scheme test = Scheme(deltaT002, deltaX, tMax, current_t);
	test.analitycalSolver();
	vector<double> testVecAnalytical = test.get_analitycalSolution();

	test.baseVecCalculator();
	ExplicitScheme testEx = ExplicitScheme(test);
	testEx.solveUpwindExplicit();
	vector<double> testVecUpwind = testEx.get_finalVector();
	testEx.solveLaxWendroff();
	vector<double> testVecLax = testEx.get_finalVector();
	vector<double> xVec;
	for (int i(0); i < testVecAnalytical.size(); i++) {
		xVec.push_back(i*deltaX);
	}



	//DISPLAY
	cout << "START :\nAnalitycal solution :\n";

	test.write2Vec("test.txt", xVec,testVecAnalytical);
	test.write2Vec("test2.txt", xVec, testVecUpwind);
	test.write2Vec("test3.txt", xVec, testVecLax);
	system("PAUSE");
	return 0;
}