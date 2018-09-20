#include <iostream>
#include "IO.h"
#include "Tool.h"
#include <stdio.h> 

int main() {

	const int num = 128;
	const int arrayNum = num*(num-1) / 2;
	double Ocoordinates[num][3];
	double lengthArray[arrayNum];
	double latticeVector[3][3] = 
	{
		{14.3319997787,         0.0000000000,         0.0000000000},
		{0.0000000000,        14.3319997787,         0.0000000000},
		{0.0000000000,         0.0000000000,        14.3319997787 }
	};

	IO mainIO("SiO2.vasp", "final.vasp", num);
	mainIO.readfromFile(Ocoordinates);

	Tool mainTool(latticeVector);
	mainTool.GetLengthforAll(Ocoordinates, num, lengthArray);

	mainIO.output(lengthArray, arrayNum);
	system("Pause");

	return 0;

	
}