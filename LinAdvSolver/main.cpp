#include <math.h>
#include <vector>
#include <iostream>
#include "Scheme.h"
#include "ExplicitScheme.h"
#include "ImplicitScheme.h"
using namespace std;

int main() {
	double deltaX = 5.0;
	double deltaT = 0.02;
	double current_t = 0.0;
	double tMax = 0.5;
	double analytical_t = 0.5;

	//INITIALIZE SCHEME OBJECT
	Scheme SchemeObj = Scheme(deltaT, deltaX, tMax, analytical_t, current_t); //Create the Scheme object
	SchemeObj.analyticalSolver();
	vector<double> AnalyticSol = SchemeObj.get_analyticalSolution(); //Analytical Solution vector
	SchemeObj.baseVecCalculator();
	vector<double> BaseVecSol = SchemeObj.get_baseVector();


	//EXPLICIT CALLS
	ExplicitScheme ExpTest = ExplicitScheme(SchemeObj);
	ExpTest.solveUpwindExplicit();
	vector<double> UpwindSol = ExpTest.get_finalVector();
	ExpTest.solveLaxWendroff();
	vector<double> LaxSol = ExpTest.get_finalVector();

	//IMPLICT CALLS
	ImplicitScheme ImpTest = ImplicitScheme(SchemeObj);
	ImpTest.solveUpwindImplicit();
	vector<double> ImpUpwindSol = ImpTest.get_finalVector();
	vector<vector<double>> FullSol = ImpTest.solveFTCSImplicit();
	vector<double> ImpFTCSSol = ImpTest.get_finalVector();

	
	//Explicit Upwind errors
	vector<double> ErrorUpwind = ExpTest.errorVectorCalc(UpwindSol, AnalyticSol);
	double UpwindNorm1 = ExpTest.normOne(ErrorUpwind);
	double UpwindNorm2 = ExpTest.normTwo(ErrorUpwind);
	double UpwindNormUni = ExpTest.uniformNorm(ErrorUpwind);

	//Explicit Lax-Wendroff errors
	vector<double> ErrorLax = ExpTest.errorVectorCalc(LaxSol, AnalyticSol);
	double LaxNorm1 = ExpTest.normOne(ErrorLax);
	double LaxNorm2 = ExpTest.normTwo(ErrorLax);
	double LaxNormUni = ExpTest.uniformNorm(ErrorLax);

	cout << "UPWIND ERROR NORMS: " << UpwindNorm1 << " " << UpwindNorm2 << " " << UpwindNormUni << "\n";
	cout << "LAX ERROR NORMS: " << LaxNorm1 << " " << LaxNorm2 << " " << LaxNormUni << "\n";

	vector<double> xVec;
	for (int i(0); i < 81; i++) {
		xVec.push_back(i*deltaX);
	}


	SchemeObj.write2Vec("OutUpwindNEW.txt", xVec, UpwindSol);
	SchemeObj.write2Vec("OutLaxWendroff.txt", xVec, LaxSol);
	SchemeObj.write2Vec("OutAnalytical.txt", xVec, AnalyticSol);
	SchemeObj.write2Vec("OutUpwindImplicit.txt", xVec, ImpUpwindSol);
	SchemeObj.write2Vec("OutFTCSImplicit.txt", xVec, ImpFTCSSol);

	return 0;
}