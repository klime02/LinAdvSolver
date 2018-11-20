#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

class Scheme
{
protected:
	//VARIABLES
	double delta_t;
	double delta_x;
	double current_t;
	double analytical_t;
	int nb_points = 80;
	double t_max;

	const double x_max = 400.0;
	const double x_min = 0.0;
	const double L= 400.0;
	const double u = 250.0;

	vector<double> analyticalSolutionVector;
	vector<double> baseVector;
	//******************************************//


public:
	
	//SOLVER
	void analyticalSolver();
	void baseVecCalculator();
	//******************************************//

	//GETS
	vector<double> get_analyticalSolution();
	vector<double> get_baseVector();
	//******************************************//
	
	//DISPLAY

	//WRITE A VECTOR IN A .TXT
	void writeVec(string path, vector<double> vec);
	
	void write2Vec(string path, vector<double> vec1, vector<double> vec2);

	//******************************************//


	//******************************************//
	//NORMS
	vector<double> errorVectorCalc(vector<double> vec1, vector<double> vec2);
	double normOne(vector<double> vec);

	double normTwo(vector<double> vec);

	double uniformNorm(vector<double> vec);

	//CONSTRUCTORS/DESTRUCTORS
	Scheme(double deltaT, double deltaX, double tMax, double analytical_t, double current_t);
	Scheme();
	~Scheme();
};

