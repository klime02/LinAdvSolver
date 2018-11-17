#pragma once
#include "Scheme.h"
class ExplicitScheme :
	public Scheme
{
protected:
	
	vector<double> TESTCHANGE3

public:

	//SOLVERS
	void solveUpwind();

	//GETS 

	vector<double> get_finalVector();

	//CONSTRUCTORS / DESTRUCTORS
	ExplicitScheme();
	ExplicitScheme(Scheme sheme);
	~ExplicitScheme();
};

