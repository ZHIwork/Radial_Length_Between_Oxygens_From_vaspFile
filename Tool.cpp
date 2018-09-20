#include "Tool.h"



Tool::Tool(const double(&latticeVector)[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			vector[i][j] = latticeVector[i][j];
	}
	
}


Tool::~Tool()
{
}


//convert coordinate from Direct to Cartesian
void Tool::directtoCart(const double(&direct)[3], double(&cart)[3])
{
	cart[0] = direct[0] * vector[0][0] + direct[1] * vector[1][0] + direct[2] * vector[2][0];

	cart[1] = direct[0] * vector[0][1] + direct[1] * vector[1][1] + direct[2] * vector[2][1];

	cart[2] = direct[0] * vector[0][2] + direct[1] * vector[1][2] + direct[2] * vector[2][2];
}


//get distance between two sets of Cartesian coordinates  
double Tool::distanceinCart(const double(&a)[3], const double(&b)[3])
{
	return sqrt((a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]) + (a[2] - b[2])*(a[2] - b[2]));
}






//get real direct shortest coordinates between center atom and bonded atom 
void Tool::directShortestCoor(const double(&center)[3], const double(&comp)[3], double(&shortest)[3])
{
	//for x
	double xcomp = fabs(center[0] - comp[0]);//x in comp not change
	shortest[0] = comp[0];
	double abs_xOsubs1 = fabs(center[0] - (comp[0] - 1));
	double abs_xOadds1 = fabs(center[0] - (comp[0] + 1));
	if (abs_xOsubs1 < xcomp)//x in comp -1
	{
		shortest[0] = comp[0] - 1;
		xcomp = abs_xOsubs1;
		if (abs_xOadds1 < xcomp)//x in comp +1
			shortest[0] = comp[0] + 1;

	}
	else
	{
		if (abs_xOadds1 < xcomp)//x in comp +1
			shortest[0] = comp[0] + 1;
	}

	//for y
	double ycomp = fabs(center[1] - comp[1]);//y in comp not change
	shortest[1] = comp[1];
	double abs_yOsubs1 = fabs(center[1] - (comp[1] - 1));
	double abs_yOadds1 = fabs(center[1] - (comp[1] + 1));
	if (abs_yOsubs1 < ycomp)//y in comp -1
	{
		shortest[1] = comp[1] - 1;
		ycomp = abs_yOsubs1;
		if (abs_yOadds1 < ycomp)//y in comp +1
			shortest[1] = comp[1] + 1;

	}
	else
	{
		if (abs_yOadds1 < ycomp)//y in comp +1
			shortest[1] = comp[1] + 1;
	}

	//for z
	double zcomp = fabs(center[2] - comp[2]);//z in comp not change
	shortest[2] = comp[2];
	double abs_zOsubs1 = fabs(center[2] - (comp[2] - 1));
	double abs_zOadds1 = fabs(center[2] - (comp[2] + 1));
	if (abs_zOsubs1 < zcomp)//z in comp -1
	{
		shortest[2] = comp[2] - 1;
		zcomp = abs_zOsubs1;
		if (abs_zOadds1 < zcomp)//z in comp +1
			shortest[2] = comp[2] + 1;

	}
	else
	{
		if (abs_zOadds1 < zcomp)//z in comp +1
			shortest[2] = comp[2] + 1;
	}
};


void Tool::GetLengthforAll(double atomCoordinate[][3], const int num, double lengthArray                                                                                                                   [])
{
	//get each real O atom coordinate x, y, x from Ocoordinates
	int a = 1, b = 0;
	for (int i = 0; i < num; ++i)// 
	{
		centerDirectO[0] = atomCoordinate[i][0];//get x
		centerDirectO[1] = atomCoordinate[i][1];//get y
		centerDirectO[2] = atomCoordinate[i][2];//get z

		//convert direct to cartisan for centerCartO
		directtoCart(centerDirectO, centerCartO);

		for (int j = a; j < num; ++j)
		{
			compDirectO[0] = atomCoordinate[j][0];//get x
			compDirectO[1] = atomCoordinate[j][1];//get y
			compDirectO[2] = atomCoordinate[j][2];//get z

			//get shortest coordinates
			directShortestCoor(centerDirectO, compDirectO, compShortDirectO);

			//convert direct to cartisan for compShortO
			directtoCart(compShortDirectO, compShortCartO);

			//get distance
			double length = distanceinCart(centerCartO, compShortCartO);

			if(length > 10)
				std::cout << "Length: " << length << "        " << i + 1 << "   " << j + 1 << std::endl;

			//store length
			lengthArray[b] = length;
			++b;
		}
		++a;
	}
}