#include "Scheme.h"
class ExplicitScheme :
	public Scheme
{
protected:
	
	vector<double> finalVector;

public:

	//SOLVERS
	vector<vector<double>> solveUpwindExplicit();
	vector<vector<double>> solveLaxWendroff();

	//GETTER
	vector<double> get_finalVector();

	//CONSTRUCTORS / DESTRUCTORS
	ExplicitScheme();
	ExplicitScheme(Scheme scheme);
	~ExplicitScheme();
};

