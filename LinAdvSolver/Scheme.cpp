/*!
 * \file Scheme.cpp
 * \brief Source file of the Scheme Class
 * \author GARIKIPATI Bhargav and AMARIR Julien
 * \version Final Version
 */

#include "Scheme.h"
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>

/*!
*  \brief Analytical solution values calculation
*
*  Using the initial conditions vector and the total time of the instance.
*  Store the values in the next vector : analyticalSolutionVector.
*/
void Scheme::analyticalSolver()
{
	double Pi = 3.141592;
	for (int i(0); i < nb_points + 1; i++) {

		if (i*delta_x <= (50.0 + (250.0 * analytical_t))) {
			analyticalSolutionVector[i] = 0.0;
		}
		else if ((50 + (250*analytical_t)) <= (i * delta_x) && (i*delta_x) < (110 + (250*analytical_t))) {
			analyticalSolutionVector[i] = 100.0 * sin(Pi*(((i*delta_x) - 50.0 - (250.0 * analytical_t)) / 60.0));

		}
		else {
			analyticalSolutionVector[i] = 0.0;
		}
	}
}
/*!
*  \brief Initial conditions values Calculation
*
*  Using the boundary conditions.
*  Store the values in the next vector : baseVector.
*/
void Scheme::baseVecCalculator()
{
	double Pi = 3.141592;
	//int xval = 0;
	for (int i(0); i < nb_points + 1; i++) {
		if (i*delta_x < 50.0) {
			baseVector[i] = 0.0;
		}
		else if (50.0 <= (i * delta_x) && (i*delta_x) < 110.0) {
			baseVector[i] = 100.0 * sin(Pi*(((i*delta_x) - 50.0 )/ 60.0));

		}
		else {
			baseVector[i] = 0.0;
		}
		//xval += 5;
	}
}
/*!
*  \brief Method to get the next vector : analyticalSolutionVector
*
*  \return the analyticalSolutionVector
*/
vector<double> Scheme::get_analyticalSolution()
{
	return analyticalSolutionVector;
}
/*!
*  \brief Method to get the next vector : baseVector
*
*  \return the baseVector
*/
vector<double> Scheme::get_baseVector()
{
	return baseVector;
}

/*!
*  \brief Calculate the errors between two vectors of doubles and return them (vector of doubles)
*
*  \param vec1 : First vector of doubles which will be used to calculate errors
*  \param vec2 : Second vector of doubles which will be used to calculate errors
*  \return a vector of error values (doubles)
*/
vector<double> Scheme::errorVectorCalc(vector<double> vec1, vector<double> vec2)
{
	//Creation of the returned error vector
	vector<double> errorVec(nb_points);

	for (int i = 0; i < nb_points; i++) {

		errorVec[i] = abs(vec1[i] - vec2[i]);

	}


	return errorVec;
}
/*!
*  \brief Calculate the One Norm of values from a vector and return it.
*
*  \param vec : vector of doubles
*  \return the value of the One Norm
*/
double Scheme::normOne(vector<double> vec)
{
	double result = 0.0;

	for (int i = 0; i < nb_points; i++) {
		result += abs(vec[i]);
	}

	return result;
}
/*!
*  \brief Calculate the Two Norm of values from a vector and return it.
*
*  \param vec : vector of doubles
*  \return the value of the Two Norm
*/
double Scheme::normTwo(vector<double> vec)
{
	double result = 0.0;

	for (int i = 0; i < nb_points; i++) {
		result += (vec[i] * vec[i]);
	}

	return sqrt(result) / nb_points;
}
/*!
*  \brief Calculate the Uniform Norm of values from a vector and return it.
*
*  \param vec : vector of doubles
*  \return the value of the Uniform Norm
*/
double Scheme::uniformNorm(vector<double> vec)
{
	double result = abs(vec[0]);

	for (int i = 1; i < nb_points; i++) {
		if (vec[i] > result)  result = vec[i];
	}

	return result;
}
/*!
*  \brief Constructor
*	Create an instance of the Scheme class and set the values of delta_t, delta_x, t_max, analytical_t and current_t.
*
*   \param deltaT : Time between two time steps.
*	\param deltaX : Distance between two points of the space grid.
*	\param tMax : Total time of the instance.
*	\param analytical_t : Time used to calculate the analytical solution.
*	\param current_t : Current time which will be increased while using the solvers.
*
*/
Scheme::Scheme(double deltaT, double deltaX, double tMax, double analytical_t, double current_t) : delta_t(deltaT), delta_x(deltaX), t_max(tMax), analytical_t(analytical_t), current_t(current_t), analyticalSolutionVector(vector<double>(nb_points+1)),baseVector(vector<double>(nb_points+1)) {

}

/*!
*  \brief Basic Constructor
*	Create an instance of the Scheme class.
*/
Scheme::Scheme()
{
}

Scheme::~Scheme()
{
}
