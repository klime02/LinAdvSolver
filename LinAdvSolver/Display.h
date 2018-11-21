#pragma once
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Display
{
public:
	string typeScheme(int type);
	string createPath(double deltaT, int typeScheme1);
	void writeVec1V2(double deltaT, double currentT, int schemeType, vector<double> vec);
	Display();
	
	

	~Display();
};

