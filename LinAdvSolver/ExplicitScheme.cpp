#include "ExplicitScheme.h"
#include "math.h"


vector<vector<double>> ExplicitScheme::solveUpwindExplicit() {

	vector<double> temp;
	vector<vector<double>> finalResults;
	temp = baseVector;
	finalVector = baseVector;
	finalResults.push_back(temp);

	current_t = 0.0;
	for (double current_t(delta_t); current_t < this->t_max + delta_t; current_t += delta_t) {
		finalVector[0] = 0.0;

		for (int i(1); i < nb_points; i++) 
		{
			finalVector[i] = temp[i] - ((u * delta_t) / delta_x)*(temp[i] - temp[i - 1]);
		}
		temp = finalVector;

		if ((current_t < (0.1 + (delta_t / 4.0)) && current_t >(0.1 - (delta_t / 4.0))) || (current_t < (0.2 + (delta_t / 4.0)) && current_t >(0.2 - (delta_t / 4.0))) || (current_t < (0.3 + (delta_t / 4.0)) && current_t >(0.3 - (delta_t / 4.0))) || (current_t < (0.4 + (delta_t / 4.0)) && current_t >(0.4 - (delta_t / 4.0))) || (current_t < (0.5 + (delta_t / 4.0)) && current_t >(0.5 - (delta_t / 4.0)))) 
		{
			finalResults.push_back(finalVector);
		}
	}
	return finalResults;
}

vector<vector<double>> ExplicitScheme::solveLaxWendroff()
{
	vector<double> temp;
	vector<vector<double>> finalResults;
	temp = baseVector;
	finalVector = baseVector;
	finalResults.push_back(temp);
	
	current_t = 0.0;
	for (double current_t(delta_t); current_t < this->t_max + delta_t; current_t += delta_t)
	{
		finalVector[0] = 0.0;
		double constant1 = (u * delta_t) / (2 * delta_x);
		double constant2 = (pow(u, 2) * pow(delta_t, 2)) / (2 * pow(delta_x, 2));
		for (int i(1); i < nb_points; i++)
		{
			finalVector[i] = temp[i] - constant1 * (temp[i + 1] - temp[i - 1]) + constant2 * (temp[i + 1] + temp[i - 1] - 2 * temp[i]);

		}
		finalVector[0] = 0.0;
		finalVector[finalVector.size() - 1] = 0.0;
		temp = finalVector;

		if ((current_t < (0.1 + (delta_t / 4.0)) && current_t >(0.1 - (delta_t / 4.0))) || (current_t < (0.2 + (delta_t / 4.0)) && current_t >(0.2 - (delta_t / 4.0))) || (current_t < (0.3 + (delta_t / 4.0)) && current_t >(0.3 - (delta_t / 4.0))) || (current_t < (0.4 + (delta_t / 4.0)) && current_t >(0.4 - (delta_t / 4.0))) || (current_t < (0.5 + (delta_t / 4.0)) && current_t >(0.5 - (delta_t / 4.0)))) {

			finalResults.push_back(finalVector);

		}

	}

	return finalResults;
}

//GETTER
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
