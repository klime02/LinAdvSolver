#pragma once
/*!
 * \file Scheme.h
 * \brief Header file of the Scheme Class
 * \author GARIKIPATI Bhargav and AMARIR Julien
 * \version Final Version
 */


#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

/*! \class Scheme
   * \brief Mother class of ExplicitScheme and ImplicitScheme classes.
   * This class gather all global variables needed for each Scheme (Explicit or Implicit).
   * It includes all the tool methods to calculate errors and norms for each scheme.
   */
class Scheme
{
protected:
	
	double delta_t; /*!< Time between two time steps.*/
	double delta_x;/*!< Distance between two points of the space grid.*/
	double current_t;/*!< Current time which will be increased while using the solvers.*/
	double analytical_t;/*!< Time used to calculate the analytical solution.*/
	int nb_points = 80;/*!< Number of points included in the grid.*/
	double t_max;/*!< Total time of the instance.*/

	const double x_max = 400.0;/*!< Right boundary of the space grid.*/
	const double x_min = 0.0;/*!< Left boundary of the space grid.*/
	const double L= 400.0; /*!< Total length of the space grid.*/
	const double u = 250.0; /*!< Speed of sound.*/

	vector<double> analyticalSolutionVector;/*!< Vector of doubles used to store analytical solution's values.*/
	vector<double> baseVector;/*!< Vector of doubles used to store initial conditions values.*/
	//******************************************//


public:
	
	//SOLVER
	/*!
	 *  \brief Analytical solution values calculation 
	 *
	 *  Using the initial conditions vector and the total time of the instance.
	 *  Store the values in the next vector : analyticalSolutionVector.
	 */
	void analyticalSolver();
	/*!
	 *  \brief Initial conditions values Calculation
	 *
	 *  Using the boundary conditions.
	 *  Store the values in the next vector : baseVector.
	 */
	void baseVecCalculator();
	//******************************************//

	//GETS
	/*!
	 *  \brief Method to get the next vector : analyticalSolutionVector
	 *  
	 *  \return the analyticalSolutionVector
	 */
	vector<double> get_analyticalSolution();
	/*!
	 *  \brief Method to get the next vector : baseVector
	 *
	 *  \return the baseVector
	 */
	vector<double> get_baseVector();
	//******************************************//
	

	//NORMS
	/*!
	 *  \brief Calculate the errors between two vectors of doubles and return them (vector of doubles)
	 *
	 *  \param vec1 : First vector of doubles which will be used to calculate errors
	 *  \param vec2 : Second vector of doubles which will be used to calculate errors
	 *  \return a vector of error values (doubles)
	 */
	vector<double> errorVectorCalc(vector<double> vec1, vector<double> vec2);
	/*!
	 *  \brief Calculate the One Norm of values from a vector and return it.
	 *
	 *  \param vec : vector of doubles
	 *  \return the value of the One Norm
	 */
	double normOne(vector<double> vec);
	/*!
	 *  \brief Calculate the Two Norm of values from a vector and return it.
	 *
	 *  \param vec : vector of doubles
	 *  \return the value of the Two Norm
	 */
	double normTwo(vector<double> vec);
	/*!
	 *  \brief Calculate the Uniform Norm of values from a vector and return it.
	 *
	 *  \param vec : vector of doubles
	 *  \return the value of the Uniform Norm
	 */
	double uniformNorm(vector<double> vec);

	//CONSTRUCTORS/DESTRUCTORS
	/*!
	 *  \brief Constructor
	 *	Create an instance of the Scheme class and set the values of delta_t, delta_x, t_max, analytical_t and current_t.
	 *
	 *  \param deltaT : Time between two time steps.
	 *	\param deltaX : Distance between two points of the space grid.
	 *	\param tMax : Total time of the instance.
	 *	\param analytical_t : Time used to calculate the analytical solution.
	 *	\param current_t : Current time which will be increased while using the solvers.
	 *
	 */
	Scheme(double deltaT, double deltaX, double tMax, double analytical_t, double current_t);
	/*!
	 *  \brief Basic Constructor
	 *	Create an instance of the Scheme class.
	 */
	Scheme();
	~Scheme();
};

