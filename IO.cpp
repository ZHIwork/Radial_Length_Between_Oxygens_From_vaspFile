#include "IO.h"



IO::IO(std::string infileName, std::string outfileName, int num)
{
	importFileName = infileName;
	exportFileName = outfileName;
	OxygenQuantity = num;
}


IO::~IO()
{
}

void IO::readfromFile(double OCoor[][3])
{
	std::ifstream inFile;
	inFile.open(importFileName);
	if (!inFile.is_open()) // failed to open file
	{
		std::cout << "Could not open the file" << std::endl;
	}
	else {
		std::string temp;//store useless line
		double Coor;//get coordinates from file
		for (int i = 0; i < OxygenQuantity + 8; i++)
		{
			if (i >= 8)
			{
				inFile >> Coor;
				OCoor[i - 8][0] = Coor;
				inFile >> Coor;
				OCoor[i - 8][1] = Coor;
				inFile >> Coor;
				OCoor[i - 8][2] = Coor;
			}
			getline(inFile, temp);
		}
	};

	inFile.close();
};


void IO::output(double Ocoor[], int arrayNum)
{
	std::ifstream inFile;
	std::string temp;//store line
	std::ofstream Savefile(exportFileName);//create a file to output data

	//output position
	for (int i = 0; i < arrayNum; ++i)
	{
		Savefile << i;
		Savefile << "    ";
		Savefile << std::setprecision(3) << Ocoor[i];
		Savefile << "    ";
		Savefile << std::endl;

	}

}
