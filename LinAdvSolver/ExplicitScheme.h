#pragma once
#include "Scheme.h"
class ExplicitScheme :
	public Scheme
{
protected:
	
	vector<double> TESTCHANGE2

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

