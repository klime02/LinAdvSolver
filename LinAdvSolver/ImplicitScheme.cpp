#include "ImplicitScheme.h"



vector<double> ImplicitScheme::thomasAlgo(double a, double b, double c, vector<double> vectorInit)
{
	vector<double> vectorResult(nb_points + 1);
	double m = 0.0;
	double bk = 0.0;

	vector<double> vecD = vectorInit;

	m = a / b;
	bk = b - (m*c);

	for (int k = 2; k < nb_points + 1; k++) {

		vecD[k] -= m * vecD[k - 1];

	}
	vectorResult[nb_points] = vecD[nb_points] / bk;

	for (int k = nb_points - 1; k > 0; k--) {

		vectorResult[k] = (vecD[k] - (c*vectorResult[k + 1])) / bk;

	}



	return vectorResult;
}

vector<vector<double>> ImplicitScheme::solveUpwindImplicit() {
	vector<vector<double>> finalResults;
	current_t = 0.0;
	baseVecCalculator();
	double alpha = (u*delta_t) / delta_x;
	double a = -alpha;
	double b = 1.0 + alpha;
	double c = 0.0;
	vector<double> temp = baseVector;
	finalVector = thomasAlgo(a, b, c, temp);
	finalVector[0] = 0.0;
	finalVector[nb_points] = 0.0;


	while (current_t < (t_max + (delta_t / 4.0))) {
		cout << current_t << "\n";

		finalVector = thomasAlgo(a, b, c, temp);

		finalVector[0] = 0.0;
		finalVector[nb_points] = 0.0;
		temp = finalVector;

		if ((current_t < (0.1 + (delta_t / 4.0)) && current_t >(0.1 - (delta_t / 4.0))) || (current_t < (0.2 + (delta_t / 4.0)) && current_t >(0.2 - (delta_t / 4.0))) || (current_t < (0.3 + (delta_t / 4.0)) && current_t >(0.3 - (delta_t / 4.0))) || (current_t < (0.4 + (delta_t / 4.0)) && current_t >(0.4 - (delta_t / 4.0))) || (current_t < (0.5 + (delta_t / 4.0)) && current_t >(0.5 - (delta_t / 4.0)))) {

			finalResults.push_back(finalVector);

		}

		current_t += delta_t;

	}

	return finalResults;
}

vector<vector<double>> ImplicitScheme::solveFTCSImplicit() {
	vector<vector<double>> finalResults;
	current_t = 0.0;
	baseVecCalculator();
	double alpha = (u*delta_t) / (2.0*delta_x);
	double a = -alpha;
	double b = 1.0;
	double c = alpha;
	vector<double> temp = baseVector;
	finalVector = thomasAlgo(a, b, c, temp);
	finalVector[0] = 0.0;
	finalVector[nb_points] = 0.0;


	while (current_t < (t_max + (delta_t / 4.0))) {

		finalVector = thomasAlgo(a, b, c, temp);

		finalVector[0] = 0.0;
		finalVector[nb_points] = 0.0;
		temp = finalVector;

		if ((current_t < (0.1 + (delta_t / 4.0)) && current_t >(0.1 - (delta_t / 4.0))) || (current_t < (0.2 + (delta_t / 4.0)) && current_t >(0.2 - (delta_t / 4.0))) || (current_t < (0.3 + (delta_t / 4.0)) && current_t >(0.3 - (delta_t / 4.0))) || (current_t < (0.4 + (delta_t / 4.0)) && current_t >(0.4 - (delta_t / 4.0))) || (current_t < (0.5 + (delta_t / 4.0)) && current_t >(0.5 - (delta_t / 4.0)))) {

			finalResults.push_back(finalVector);

		}

		current_t += delta_t;

	}

	return finalResults;
}

vector<double> ImplicitScheme::get_finalVector()
{
	return finalVector;
}

ImplicitScheme::ImplicitScheme()
{
}

ImplicitScheme::ImplicitScheme(Scheme mother) : Scheme(mother), finalVector(vector<double>(nb_points))
{

}


ImplicitScheme::~ImplicitScheme()
{
}
