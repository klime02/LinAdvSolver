/*!
 * \file Display.h
 * \brief Header File of the Display Class
 * \author GARIKIPATI Bhargav and AMARIR Julien
 * \version Final Version
 */


#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Display
{
public:
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
	string typeScheme(int type);
	/*!
	*   \brief Create a path from the caracteristics given in imput and white a vector inside a path.txt
	*   \param deltaT : Time step of the Scheme.
	*   \param print_t : Current time to print.
	*   \param deltaT : Time step of the Scheme.
	*   \param schemeType : Int type of the scheme which will be converted by the typeScheme method.
	*   \param vec : The vector which will be printed into the text file.
	*/
	void writeVec1V2(double deltaT, double print_t, int schemeType, vector<double> vec);
	/*!
	*  \brief Basic Constructor
	*	Create an instance of the Display class.
	*/
	Display();



	~Display();
};
