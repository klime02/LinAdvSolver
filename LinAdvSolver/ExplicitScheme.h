#include "Scheme.h"
class ExplicitScheme :
	public Scheme
{
protected:
	
	vector<double> finalVector;

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

