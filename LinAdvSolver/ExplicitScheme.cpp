#include "ExplicitScheme.h"



void ExplicitScheme::solveUpwind()
{
	vector<double> temp;
	
	temp = baseVector;
	finalVector = baseVector;

	for (double currentT(delta_t); currentT < this->t_max; currentT += delta_t) {
		finalVector[0] = 0.0;

		for (int i(1); i < nb_points; i++) {
			finalVector[i] = temp[i] - ((u * delta_t)/delta_x)*(temp[i] - temp[i - 1]);


		}
		temp = finalVector;
	}
	finalVector[finalVector.size() - 1] = 0.0;
}




//CONSTRUCTORS / Destructor

vector<double> ExplicitScheme::get_finalVector()
{
	return finalVector;
}

ExplicitScheme::ExplicitScheme()
{
}

ExplicitScheme::ExplicitScheme(Scheme scheme) : Scheme(scheme),finalVector(vector<double>(nb_points))
{
}


ExplicitScheme::~ExplicitScheme()
{
}
