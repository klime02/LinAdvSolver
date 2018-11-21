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
	void writeVec1V2(double deltaT, double print_t, int schemeType, vector<double> vec);
	Display();



	~Display();
};
