#pragma once

#include <iostream>
#include <cmath>

class Tool
{
private:
	double vector[3][3];
	double centerDirectO[3], compDirectO[3], compShortDirectO[3];
	double centerCartO[3], compShortCartO[3];
public:
	Tool(const double(&latticeVector)[3][3]);
	~Tool();

	void directtoCart(const double(&direct)[3], double(&cart)[3]);
	double distanceinCart(const double(&a)[3], const double(&b)[3]);
	void directShortestCoor(const double(&center)[3], const double(&comp)[3], double(&shortest)[3]);
	void GetLengthforAll(double atomCoordinate[][3], const int num, double lengthArray[]);
};

