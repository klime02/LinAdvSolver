#include "Display.h"
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

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
		stringTypeScheme = "laxExplicit";
		break;
	case 3:
		stringTypeScheme = "upwindImplicit";
		break;
	case 4:
		stringTypeScheme = "ftcsImplicit";
		break;
	default:
		stringTypeScheme = "NO TYPE";
	}

	return stringTypeScheme;
}


void Display::writeVec1V2(double deltaT, double print_t, int schemeType, vector<double> vec) {

	string path = to_string(deltaT) + typeScheme(schemeType) + to_string(print_t) + ".txt";
	cout << "Data wrote to: " << path << "\n";
	ofstream file(path, ios::out | ios::trunc);

	if (file)
	{
		for (int i(0); i < vec.size(); i++) {
			file << to_string(vec[i]) << "\n";
		}
		file << "\n";
		file.close();
	}
	else
	{
		cerr << "Error Opening File" << endl;
	}
		
}

Display::Display()
{
}

Display::~Display()
{
}