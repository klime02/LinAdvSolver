#include <math.h>
#include <vector>
#include <iostream>
#include "Scheme.h"
#include "ExplicitScheme.h"
#include "ImplicitScheme.h"
using namespace std;

int main() {
	double deltaX = 5.0;
	double deltaT = 0.005;
	double tMax = 0.5;
	double analytical_t = 0.52;

	//INITIALIZE SCHEME OBJECT
	Scheme SchemeObj = Scheme(deltaT, deltaX, tMax, analytical_t); //Create the Scheme object
	SchemeObj.analyticalSolver();
	vector<double> AnalyticSol = SchemeObj.get_analyticalSolution(); //Analytical Solution vector
	SchemeObj.baseVecCalculator();

	// EXPLICIT CALLS
	ExplicitScheme ExpTest = ExplicitScheme(SchemeObj);
	ExpTest.solveUpwindExplicit();
	vector<double> UpwindSol = ExpTest.get_finalVector();
	ExpTest.solveLaxWendroff();
	vector<double> LaxSol = ExpTest.get_finalVector();

	//ERROR + NORMS

	//Upwind
	vector<double> ErrorUpwind = ExpTest.errorVectorCalc(UpwindSol, AnalyticSol);
	double UpwindNorm1 = ExpTest.normOne(ErrorUpwind);
	double UpwindNorm2 = ExpTest.normTwo(ErrorUpwind);
	double UpwindNormUni = ExpTest.uniformNorm(ErrorUpwind);

	//Lax-Wendroff
	vector<double> ErrorLax = ExpTest.errorVectorCalc(LaxSol, AnalyticSol);
	double LaxNorm1 = ExpTest.normOne(ErrorLax);
	double LaxNorm2 = ExpTest.normTwo(ErrorLax);
	double LaxNormUni = ExpTest.uniformNorm(ErrorLax);

	cout << "UPWIND ERROR NORMS: " << UpwindNorm1 << " " << UpwindNorm2 << " " << UpwindNormUni << "\n";
	cout << "LAX ERROR NORMS: " << LaxNorm1 << " " << LaxNorm2 << " " << LaxNormUni << "\n";


	vector<double> xVec;
	for (int i(0); i < AnalyticSol.size(); i++) {
		xVec.push_back(i*deltaX);
	}

	SchemeObj.write2Vec("Upwind.txt", xVec, UpwindSol);
	SchemeObj.write2Vec("LaxWendroff.txt", xVec, LaxSol);
	SchemeObj.write2Vec("Analytical.txt", xVec, AnalyticSol);

	return 0;
}