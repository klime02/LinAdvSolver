#pragma once
#include "Scheme.h"
class ExplicitScheme :
	public Scheme
{
protected:
	
	vector<double> finalVector;

public:

	//SOLVERS
	void solveUpwind();

	vector<vector<double>> solveUpwindV2();

	void solveLaxWendroff();

	vector<vector<double>> solveLaxWendroffV2();

	//GETS 

	vector<double> get_finalVector();

	//CONSTRUCTORS / DESTRUCTORS
	ExplicitScheme();
	ExplicitScheme(Scheme sheme);
	~ExplicitScheme();
};

