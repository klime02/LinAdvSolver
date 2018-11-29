/*!
 * \file ImplicitScheme.h
 * \brief Header file of The Implicit Scheme Class
 * \author GARIKIPATI Bhargav and AMARIR Julien
 * \version Final Version
 */


#include "Scheme.h"
class ImplicitScheme :
	public Scheme
{
protected:
	vector<double> finalVector;/*!< Vector of doubles used to store values for a time equals to t_max.*/

public:
	/*!
	*   \brief Solve a linear system of equations with a tridiagonal matrix.
	*   \param a : Coefficient of the lower diagonal.
	*   \param b : Coefficient of the main diagonal.
	*   \param c : Coefficient of the upper diagonal.
	*   \param vectorInit : The vector at time step n.
	*	\return the vector at time step n+1.
	*/
	vector<double> thomasAlgo(double a, double b, double c, vector<double> vectorInit);
	/*!
	*  \brief Basic Constructor
	*	Create an instance of the ImplicitScheme class.
	*/
	ImplicitScheme();
	/*!
	 *  \brief Constructor
	 *	Create an instance of the ImplicitScheme class and set the values of delta_t, delta_x, t_max, analytical_t and current_t coming from an instance of the Scheme class.
	 *
	 *  \param mother : mother instance from which will .
	 *
	 */
	ImplicitScheme(Scheme mother);
	
	~ImplicitScheme();
	/*!
	 *  \brief Method to get the next vector : finalVector
	 *
	 *  \return the finalVector
	 */
	vector<double> get_finalVector();
	/*!
	*  \brief Solve the problem using the implicit FTCS Scheme characteristics,
	*	modify the values of the next attribut : finalVector
	*	and return a vector composed by vectors of doubles one for time = 0.1, 0.2, 0.3, 0.4 and 0.5.
	*  \return vector of vectors of doubles
	*/
	vector<vector<double>> solveFTCSImplicit();
	/*!
	*  \brief Solve the problem using the implicit Upwind Scheme characteristics,
	*	modify the values of the next attribut : finalVector
	*	and return a vector composed by vectors of doubles one for time = 0.1, 0.2, 0.3, 0.4 and 0.5.
	*  \return vector of vectors of doubles
	*/
	vector<vector<double>> solveUpwindImplicit();
};
