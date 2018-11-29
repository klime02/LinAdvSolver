/*!
* \file Display.cpp
* \brief Source file of the Display Class
* \author GARIKIPATI Bhargav and AMARIR Julien
* \version Final Version
*/

#include "Display.h"
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
/*!
*   \brief Convert a int scheme type into the full name of the scheme in string type.
*	if the input is equal to 0 : return "analyticalSolution";
*	if the input is equal to 1 : return "upwindExplicit";
*	if the input is equal to 2 : return "laxExplicit";
*	if the input is equal to 2 : return "upwindImplicit";
*	if the input is equal to 2 : return "ftcsImplicit";
*   \param type : Type of the scheme in int type.
*	\return The type of the scheme in a string type.
*/
string Display::typeScheme(int type) {
	string stringTypeScheme = "NO TYPE";

	switch (type)
	{
	case 0:
		stringTypeScheme = "analyticalSolution";
		break;
	case 1:
		stringTypeScheme = "upwindExplicit";
		break;
	case 2:
		stringTypeScheme = "laxExplicit";
		break;
	case 3:
		stringTypeScheme = "upwindImplicit";
		break;
	case 4:
		stringTypeScheme = "ftcsImplicit";
		break;
	default:
		stringTypeScheme = "NO TYPE";
	}

	return stringTypeScheme;
}

/*!
*   \brief Create a path from the caracteristics given in imput and white a vector inside a path.txt
*   \param deltaT : Time step of the Scheme.
*   \param print_t : Current time to print.
*   \param deltaT : Time step of the Scheme.
*   \param schemeType : Int type of the scheme which will be converted by the typeScheme method.
*   \param vec : The vector which will be printed into the
*/
void Display::writeVec1V2(double deltaT, double print_t, int schemeType, vector<double> vec) {

	string path = to_string(deltaT) + typeScheme(schemeType) + to_string(print_t) + ".txt";
	cout << "Data wrote to: " << path << "\n";
	ofstream file(path, ios::out | ios::trunc);

	if (file)
	{
		for (int i(0); i < vec.size(); i++) {
			file << to_string(vec[i]) << "\n";
		}
		file << "\n";
		file.close();
	}
	else
	{
		cerr << "Error Opening File" << endl;
	}
		
}
/*!
*  \brief Basic Constructor
*	Create an instance of the Display class.
*/
Display::Display()
{
}

Display::~Display()
{
}
