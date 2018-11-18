#include "Scheme.h"
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>

void Scheme::analitycalSolver()
{
	double Pi = 3.141592;
	for (int i(0); i < nb_points; i++) {

		if (i*delta_x <= 50.0) {
			analitycalSolutionVector[i] = 0.0;
		}
		else if (50 < (i * delta_x) && (i*delta_x) < 110) {
			analitycalSolutionVector[i] = 100.0 * sin(Pi*(((i*delta_x) - 50.0 - (250.0 * t_max)) / 60.0));

		}
		else {
			analitycalSolutionVector[i] = 0.0;
		}


	}
}

void Scheme::baseVecCalculator()
{
	double Pi = 3.141592;
	for (int i(0); i < nb_points + 1; i++) {

		if (i*delta_x <= 50.0) {
			baseVector[i] = 0.0;
		}
		else if (50.0 < (i * delta_x) && (i*delta_x) < 110.0) {
			baseVector[i] = 100.0 * sin(Pi*(((i*delta_x) - 50.0 )/ 60.0));

		}
		else {
			baseVector[i] = 0.0;
		}
	}
}

vector<double> Scheme::get_analitycalSolution()
{
	return analitycalSolutionVector;
}

vector<double> Scheme::get_baseVector()
{
	return baseVector;
}

//WRITE A VECTOR IN A .TXT
void Scheme::writeVec(string path, vector<double> vec) {
	ofstream fichier(path, ios::out | ios::trunc);

	if (fichier) {
		for (int i(0); i < vec.size(); i++) {
			fichier << to_string(vec[i]) << "\n";
		}
		fichier << "\n";
		fichier.close();
	}
	else
		cerr << "Erreur à l'ouverture !" << endl;

}

void Scheme::write2Vec(string path, vector<double> vec1, vector<double> vec2)
{
	ofstream fichier(path, ios::out | ios::trunc);

	if (fichier) {
		for (int i(0); i < vec1.size(); i++) {
			fichier << to_string(vec1[i]) <<";"<< vec2[i]<< "\n";
		}
		fichier << "\n";
		fichier.close();
	}
	else
		cerr << "Erreur à l'ouverture !" << endl;

}

vector<double> Scheme::errorVectorCalc(vector<double> vec1, vector<double> vec2)
{
	//Creation of the returned error vector
	vector<double> errorVec(nb_points);

	for (int i = 0; i < nb_points; i++) {

		errorVec[i] = abs(vec1[i] - vec2[i]);

	}


	return errorVec;
}

double Scheme::normOne(vector<double> vec)
{
	double result = 0.0;

	for (int i = 0; i < nb_points; i++) {
		result += abs(vec[i]);
	}

	return result/nb_points;
}

double Scheme::normTwo(vector<double> vec)
{
	double result = 0.0;

	for (int i = 0; i < nb_points; i++) {
		result += (vec[i]*vec[i]);
	}

	return sqrt(result) / nb_points;
}

double Scheme::uniformNorm(vector<double> vec)
{
	double result = abs(vec[0]);

	for (int i = 1; i < nb_points; i++) {
		if (vec[i] > result)  result = vec[i];
	}

	return result;
}

Scheme::Scheme(double deltaT, double deltaX, double tMax) : delta_t(deltaT), delta_x(deltaX), t_max(tMax), analitycalSolutionVector(vector<double>(nb_points+1)),baseVector(vector<double>(nb_points+1)) {

}


Scheme::Scheme()
{
}

Scheme::~Scheme()
{
}
