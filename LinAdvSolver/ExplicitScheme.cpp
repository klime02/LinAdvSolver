#include "ExplicitScheme.h"
#include "math.h"


void ExplicitScheme::solveUpwindExplicit()
{
	vector<double> temp;
	
	temp = baseVector;
	finalVector = baseVector;

	for (double currentComputeT(delta_t); currentComputeT <= this->t_max + delta_t; currentComputeT += delta_t)
	{
		finalVector[0] = 0.0;
		for (int i(1); i < nb_points; i++)
		{
			finalVector[i] = temp[i] - ((u * delta_t) / delta_x)*(temp[i] - temp[i - 1]);

		}
		temp = finalVector;
	}
	finalVector[finalVector.size() - 1] = 0.0;
}

void ExplicitScheme::solveLaxWendroff()
{
	vector<double> temp;

	temp = baseVector;
	finalVector = baseVector;

	for (double currentComputeT(delta_t); currentComputeT <= this->t_max + delta_t; currentComputeT += delta_t)
	{
		finalVector[0] = 0.0;
		double constant1 = (u * delta_t) / (2 * delta_x);
		double constant2 = (pow(u, 2) * pow(delta_t, 2)) / (2 * pow(delta_x, 2));
		for (int i(1); i < nb_points; i++)
		{
			finalVector[i] = temp[i] - constant1 * (temp[i+1] - temp[i-1]) + constant2 * (temp[i+1] + temp[i-1] - 2*temp[i]);
		
		}
		temp = finalVector;
	}
	finalVector[finalVector.size() - 1] = 0.0;

}


//Getter
vector<double> ExplicitScheme::get_finalVector()
{
	return finalVector;
}

//CONSTRUCTORS / Destructor
ExplicitScheme::ExplicitScheme()
{
}

ExplicitScheme::ExplicitScheme(Scheme scheme) : Scheme(scheme),finalVector(vector<double>(nb_points))
{
}


ExplicitScheme::~ExplicitScheme()
{
}
