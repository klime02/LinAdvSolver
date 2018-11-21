#include <math.h>
#include <vector>
#include <iostream>
#include "Scheme.h"
#include "ExplicitScheme.h"
#include "ImplicitScheme.h"
#include "Display.h"
using namespace std;

int main() {
	double deltaX = 5.0;
	double deltaT = 0.02;
	double current_t = 0.0;
	double tMax = 0.5;
	double analytical_t = 0.5;
	bool stop = false;

	while (!stop)
	{
		int methodSelect;
		int dtselect;
		bool finalSelect = false;

		while (!finalSelect)
		{
			cout << "\n----------Linear Advection Solver----------" << "\n";
			cout << "Solver options" << "\n";
			cout << "0 - Analytical Solution" << "\n";
			cout << "1 - Explicit Upwind Solution" << "\n";
			cout << "2 - Explicit Lax-Wendroff Solution" << "\n";
			cout << "3 - Implict Upwind Solution" << "\n";
			cout << "4 - Implicit FTCS Solution" << "\n";
			cout << "Select a solving method: ";
			while (!(cin >> methodSelect))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Sorry, that was not a valid selection. Please enter an method shown: ";
			}

			cout << "Timestep options" << "\n";
			cout << "0 - 0.02s" << "\n";
			cout << "1 - 0.01s" << "\n";
			cout << "2 - 0.005s" << "\n";
			cout << "Select a timestep: ";

			while (!(cin >> dtselect))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Sorry, that was not a valid selection. Please enter an timestep option shown: ";
			}

			if (methodSelect < 0 || dtselect < 0 || methodSelect > 4 || dtselect > 2)
			{
				cout << "\nInvalid selections. Please select an integer from the list" << "\n";
			}
			else
			{
				finalSelect = true;
			}
		}


		switch (dtselect)
		{
		case 0:
		{
			deltaT = 0.02;
			break;
		}
		case 1:
		{
			deltaT = 0.01;
			break;
		}
		case 2:
		{
			deltaT = 0.005;
			break;
		}
		default:
			break;
		}

		Scheme SchemeObj = Scheme(deltaT, deltaX, tMax, analytical_t, current_t); //Create the Scheme object
		SchemeObj.baseVecCalculator();
		SchemeObj.analyticalSolver();
		Display DataOut = Display();
		ExplicitScheme ExpSolutions = ExplicitScheme(SchemeObj);
		ImplicitScheme ImpSolutions = ImplicitScheme(SchemeObj);

		SchemeObj.baseVecCalculator();
		SchemeObj.analyticalSolver();
		vector<double> AnalyticSol = SchemeObj.get_analyticalSolution();
		vector<vector<double>> UpwindSol;
		vector<vector<double>> LaxWendroffSol;
		vector<vector<double>> ImplicitUpwindSol;
		vector<vector<double>> ImplicitFTCSSol;

		switch (methodSelect)
		{
		case 0:
		{
			DataOut.writeVec1V2(deltaT, analytical_t, methodSelect, AnalyticSol);
			break;
		}
		case 1:
		{
			UpwindSol = ExpSolutions.solveUpwindExplicit();
			double print_t = 0.0;
			for (int i = 0; i < 6; i++)
			{
				DataOut.writeVec1V2(deltaT, print_t, methodSelect, UpwindSol[i]);
				print_t += 0.1;
			}
			break;
		}
		case 2:
		{
			LaxWendroffSol = ExpSolutions.solveLaxWendroff();
			double print_t = 0.0;
			for (int i = 0; i < 6; i++)
			{
				DataOut.writeVec1V2(deltaT, print_t, methodSelect, LaxWendroffSol[i]);
				print_t += 0.1;
			}
			break;
		}
		case 3:
		{
			ImplicitUpwindSol = ImpSolutions.solveUpwindImplicit();
			double print_t = 0.0;
			for (int i = 0; i < 6; i++)
			{
				DataOut.writeVec1V2(deltaT, print_t, methodSelect, ImplicitUpwindSol[i]);
				print_t += 0.1;
			}
			break;
		}
		case 4:
		{
			ImplicitFTCSSol = ImpSolutions.solveFTCSImplicit();
			double print_t = 0.0;
			for (int i = 0; i < 6; i++)
			{
				DataOut.writeVec1V2(deltaT, print_t, methodSelect, ImplicitFTCSSol[i]);
				print_t += 0.1;
			}
			break;
		}
		default:
			break;
		}

		string normDisp;
		cout << "\nDisplay norms? (y/n): ";
		cin >> normDisp;
		if (normDisp == "y" || normDisp == "Y" || normDisp == "yes" || normDisp == "YES")
		{
			switch (methodSelect)
			{
			case 0:
			{
				cout << "Analytical solution has no error!";
				break;
			}
			case 1:
			{
				vector<double> Errors = SchemeObj.errorVectorCalc(AnalyticSol, UpwindSol[5]);
				double L1 = SchemeObj.normOne(Errors);
				double L2 = SchemeObj.normTwo(Errors);
				double LUni = SchemeObj.uniformNorm(Errors);
				cout << "Norms (L1, L2, Uniform): " << L1 << " " << L2 << " " << LUni << "\n";
				break;
			}
			case 2:
			{
				vector<double> Errors = SchemeObj.errorVectorCalc(AnalyticSol, LaxWendroffSol[5]);
				double L1 = SchemeObj.normOne(Errors);
				double L2 = SchemeObj.normTwo(Errors);
				double LUni = SchemeObj.uniformNorm(Errors);
				cout << "Norms (L1, L2, Uniform): " << L1 << " " << L2 << " " << LUni << "\n";
				break;
			}
			case 3:
			{
				vector<double> Errors = SchemeObj.errorVectorCalc(AnalyticSol, ImplicitUpwindSol[5]);
				double L1 = SchemeObj.normOne(Errors);
				double L2 = SchemeObj.normTwo(Errors);
				double LUni = SchemeObj.uniformNorm(Errors);
				cout << "Norms (L1, L2, Uniform): " << L1 << " " << L2 << " " << LUni << "\n";
				break;
			}
			case 4:
			{
				vector<double> Errors = SchemeObj.errorVectorCalc(AnalyticSol, ImplicitFTCSSol[5]);
				double L1 = SchemeObj.normOne(Errors);
				double L2 = SchemeObj.normTwo(Errors);
				double LUni = SchemeObj.uniformNorm(Errors);
				cout << "Norms (L1, L2, Uniform): " << L1 << " " << L2 << " " << LUni << "\n";
				break;
			}
			default:
				break;
			}
		}
		string restart;
		cout << "\nRestart program? (y/n):  ";
		cin >> restart;
		if (restart == "y" || restart == "Y" || restart == "yes" || restart == "YES")
		{
			stop = false;
			cout << "TRIIGERD";
		}
		else
		{
			stop = true;
			cout << "\nQuitting Linear Advection Solver\n";
		}
	}
	

	return 0;
}