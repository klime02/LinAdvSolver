#include <math.h>
#include <vector>
#include <iostream>
#include "Scheme.h"
#include "ExplicitScheme.h"
#include "ImplicitScheme.h"
using namespace std;

int main() {
	double deltaX = 5.0;
	double deltaT002 = 0.02;
	double tMax = 0.5;
	Scheme test = Scheme(deltaT002, deltaX, tMax);
	test.analitycalSolver();
	vector<double> testVec = test.get_analitycalSolution();

	test.baseVecCalculator();
	//testVec = test.get_baseVector();
	ExplicitScheme testEx = ExplicitScheme(test);
	testEx.solveUpwind();
	vector<double> testVec2 = testEx.get_finalVector();

	vector<double> xVec;
	for (int i(0); i < testVec.size(); i++) {
		xVec.push_back(i*deltaX);
	}



	//DISPLAY
	cout << "START :\nAnalitycal solution :\n";

	test.write2Vec("test.txt", xVec,testVec);
	for (int i(0); i < testVec.size(); i++) {
		cout << "i = " << i << " | We got : " << testVec[i] << " | And : " << testVec2[i] << " |\n";
	}
	
	system("PAUSE");
	return 0;
}