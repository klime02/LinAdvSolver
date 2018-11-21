#include "Display.h"
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
/*void Display::writeVec(string path, vector<double> vec)
{
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
*/


Display::Display()
{
}
string Display::typeScheme(int type) {
	string stringTypeScheme = "NO TYPE";

	switch (type)
	{
	case 0:
		stringTypeScheme = "analyticalSolution";
		break;
	case 1:
		stringTypeScheme = "upwindExplicit";
		break;
	case 2:
		stringTypeScheme = "laxImplicit";
		break;
	case 3:
		stringTypeScheme = "upwindImplicit";
		break;
	case 4:
		stringTypeScheme = "ftcsExplicit";
		break;
	default:
		stringTypeScheme = "NO TYPE";
	}


	return stringTypeScheme;
}

string Display::createPath(double deltaT, int typeScheme1 ) {


	string path = to_string(deltaT) + "_" + typeScheme(typeScheme1); 

	return path;
}
/*void Display::writeVec(double deltaT, int typeSchemeVec1, vector<double> vec1)
{

	string path = createPath(deltaT, typeSchemeVec1)+".txt";
	ofstream fichier(path, ios::out | ios::trunc);

	if (fichier) {
		for (int i(0); i < vec1.size(); i++) {
			fichier << to_string(vec1[i]) << "\n";
		}
		fichier << "\n";
		fichier.close();
	}
	else
		cerr << "Erreur à l'ouverture !" << endl;


}*/

/*void Display::writeVec2(double deltaT, int typeSchemeVec1, int typeSchemeVec2, vector<double> vec1, vector<double> vec2)*/

/*void Display::writeVec5(double deltaT, int typeSchemeVec1, int typeSchemeVec2, int typeSchemeVec3, int typeSchemeVec4, int typeSchemeVec5, vector<double> vec1, vector<double> vec2, vector<double> vec3, vector<double> vec4, vector<double> vec5)
{
	string path = createPath(deltaT, typeSchemeVec1) + "_" + createPath(deltaT, typeSchemeVec2) + "_" + createPath(deltaT, typeSchemeVec3) + "_" + createPath(deltaT, typeSchemeVec4)+ "_" + createPath(deltaT, typeSchemeVec5)+ ".txt";
	ofstream fichier(path, ios::out | ios::trunc);

	if (fichier) {
		for (int i(0); i < vec1.size(); i++) {
			fichier << to_string(vec1[i]) << " " << vec2[i] << " " << to_string(vec3[i]) << " " << vec4[i] << " " << vec5[i] << "\n";
		}
		fichier << "\n";
		fichier.close();
	}
	else
		cerr << "Erreur à l'ouverture !" << endl;
}*/

void Display::writeVec1V2(double deltaT, double currentT,int schemeType, vector<double> vec){

	string path = to_string(deltaT) + typeScheme(schemeType) + to_string(currentT) + ".txt";
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
Display::~Display()
{
}
