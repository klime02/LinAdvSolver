#include "Scheme.h"
class ExplicitScheme :
	public Scheme
{
protected:
	
	vector<double> finalVector;

public:

	//SOLVERS
	void solveUpwindExplicit();
	void solveLaxWendroff();

	//GETS 

	vector<double> get_finalVector();

	//CONSTRUCTORS / DESTRUCTORS
	ExplicitScheme();
	ExplicitScheme(Scheme sheme);
	~ExplicitScheme();
};

