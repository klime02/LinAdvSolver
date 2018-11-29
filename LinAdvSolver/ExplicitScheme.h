/*!
 * \file ExplicitScheme.h
 * \brief Header file of the ExplicitScheme Class
 * \author GARIKIPATI Bhargav and AMARIR Julien
 * \version Final Version
 */

#include "Scheme.h"
class ExplicitScheme :
	public Scheme
{
protected:
	
	vector<double> finalVector;/*!< Vector of doubles used to store values for a time equals to t_max.*/

public:

	//SOLVERS
	/*!
	*  \brief Solve the problem using the explicit Upwind Scheme characteristics, 
	*	modify the values of the next attribut : finalVector 
	*	and return a vector composed by vectors of doubles one for time = 0.1, 0.2, 0.3, 0.4 and 0.5.
	*  \return vector of vectors of doubles
	*/
	vector<vector<double>> solveUpwindExplicit();
	/*!
	*  \brief Solve the problem using the explicit LaxWendroff Scheme characteristics,
	*	modify the values of the next attribut : finalVector
	*	and return a vector composed by vectors of doubles one for time = 0.1, 0.2, 0.3, 0.4 and 0.5.
	*  \return vector of vectors of doubles
	*/
	vector<vector<double>> solveLaxWendroff();

	//GETTER
	/*!
	*  \brief Method to get the next vector : finalVector
	*
	*  \return the finalVector
	*/
	vector<double> get_finalVector();

	//CONSTRUCTORS / DESTRUCTORS
	/*!
	 *  \brief Basic Constructor
	 *	Create an instance of the ExplicitScheme class.
	 */
	ExplicitScheme();
	/*!
	*  \brief Constructor
	*	Create an instance of the ExplicitScheme class and set the values of delta_t, delta_x, t_max, analytical_t and current_t coming from an instance of the Scheme class.
	*
	*  \param mother : mother instance from which will .
	*
	*/
	ExplicitScheme(Scheme mother);
	~ExplicitScheme();
};

