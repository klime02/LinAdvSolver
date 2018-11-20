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

	ImplicitScheme testIm = ImplicitScheme(test);
	testIm.baseVecCalculator();
	vector<double> basevec = testIm.get_baseVector();
	testIm.thomasAlgo(1,2,3,basevec);
	vector<double> testVecImp = testIm.get_finalVector();
	vector<double> xVec;




	//DISPLAY
	//cout << "START :\nAnalitycal solution :\n";

	//test.write2Vec("test.txt", xVec,testVecAnalytical);
	//test.write2Vec("test2.txt", xVec, testVecUpwind);
	//test.write2Vec("test3.txt", xVec, testVecLax);
	//system("PAUSE");
	return 0;
}