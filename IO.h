#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>


class IO
{

private:
	std::string importFileName;
	std::string exportFileName;
	int OxygenQuantity;

public:
	IO(std::string infileName, std::string outfileName, int num);
	~IO();

	void readfromFile(double OCoor[][3]);
	void output(double Ocoor[], int arrayNum);
};

