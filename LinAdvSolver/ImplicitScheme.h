#pragma once
#include "Scheme.h"
class ImplicitScheme :
	public Scheme
{
protected:
	vector<double> finalVector;
public:
	vector<double> thomasAlgo(double a, double b, double c, vector<double> vectorInit);
	ImplicitScheme();
	ImplicitScheme(Scheme mother);
	~ImplicitScheme();
	vector<double> get_finalVector();
};

