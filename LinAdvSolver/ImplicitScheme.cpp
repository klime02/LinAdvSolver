#include "ImplicitScheme.h"



vector<double> ImplicitScheme::thomasAlgo(double a, double b, double c, vector<double> vectorInit)
{
	vector<double> vectorResult(nb_points+1);
	double m = 0.0;
	double bk = 0.0;
	
	vector<double> vecD = vectorInit;

	m = a / b;
	bk = b - (m*c);
	
	for (int k = 2; k < nb_points + 1; k++) {
	
		vecD[k] -= m * vecD[k - 1];

	}
	vectorResult[nb_points] = vecD[nb_points] / bk;

	for (int k = nb_points - 1; k > 0;k--) {

		vectorResult[k] = (vecD[k] - (c*vectorResult[k + 1])) / bk;

	}



	return vectorResult;
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

vector<double> ImplicitScheme::get_finalVector()
{
	return finalVector;
}
