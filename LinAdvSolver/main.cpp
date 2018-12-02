/*!
 * \file main.cpp
 * \brief The main file will ask informations to the user and use the right scheme with the right characteristics and will write the results on text files.
 * \author GARIKIPATI Bhargav and AMARIR Julien
 * \version Final Version
 */

#include <math.h>
#include <vector>
#include <iostream>
#include "Scheme.h"
#include "ExplicitScheme.h"
#include "ImplicitScheme.h"
#include "Display.h"

 /*! \namespace player
  *
  * Declarative region which gather all C++ standard library types and functions.
  * 
  */
using namespace std;

int main() {
	//Variable Initialisation

	double deltaX = 5.0;/*!< Distance between two points of the space grid.*/
	double deltaT = 0.02;/*!< Time between two time steps.*/
	double current_t = 0.0;/*!< Current time which will be increased while using the solvers.*/
	double tMax = 0.5;/*!< Total time of the instance.*/
	double analytical_t = 0.5;/*!< Time used to calculate the analytical solution.*/
	bool stop = false;/*!< Boolean which will be used to restart or stop the programm.*/

	//Main loop of the programm while the user keep saying yes at the end of the loop the programm will restart.
	while (!stop)
	{
		//Variable Initialisation
		int methodSelect;/*!< Will indicate which method will be used.*/
		int dtselect;/*!< Will indicate which delta_t will be used.*/
		bool finalSelect = false;/*!< Boolean which will be used to restart the selection of methodSelect and dtSelect if it fails.*/

		//Loop used to select methodSelect and dtSelect.
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

		//Modify the dtSelect value with the value asked by the user
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
		//Creation of the Scheme Object.
		Scheme SchemeObj = Scheme(deltaT, deltaX, tMax, analytical_t, current_t); //Create the Scheme object
		//Calcul the baseVector which contain the initial values.
		SchemeObj.baseVecCalculator();
		//Calcul the analitical values at a certain time.
		SchemeObj.analyticalSolver();
		//Create the display object
		Display DataOut = Display();
		//Creation of the ExplicitScheme object from the Scheme Object.
		ExplicitScheme ExpSolutions = ExplicitScheme(SchemeObj);
		//Creation of the ImplicitScheme object from the Scheme Object.
		ImplicitScheme ImpSolutions = ImplicitScheme(SchemeObj);

		SchemeObj.baseVecCalculator();
		SchemeObj.analyticalSolver();

		//AnalyticSol contains the analytical values.
		vector<double> AnalyticSol = SchemeObj.get_analyticalSolution();

		//Initialisation of the vector of double vectors which will be used to store the values requested by the user.
		vector<vector<double>> UpwindSol;
		vector<vector<double>> LaxWendroffSol;
		vector<vector<double>> ImplicitUpwindSol;
		vector<vector<double>> ImplicitFTCSSol;
		//Calcul the values depending of the method chosen by the user.
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
		//The user has to choose if he wants to print the norms.
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
		// The user choose if he wants to retart the programm. 
		string restart;
		cout << "\nRestart program? (y/n):  ";
		cin >> restart;
		if (restart == "y" || restart == "Y" || restart == "yes" || restart == "YES")
		{
			stop = false;
		}
		else
		{
			stop = true;
			cout << "\nQuitting Linear Advection Solver\n";
		}
	}
	

	return 0;
}
