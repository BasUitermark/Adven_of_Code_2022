#include "aoc.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

bool	readData(std::vector<std::string> *inputArray, std::vector<std::vector<int>> &numArray)
{
	std::ifstream	inputFile(INPUT);
	std::string		temp;
	int				vec = 0;

	if (!inputFile)
	{
		std::cerr << "Cannot open the File : " << INPUT << std::endl;
		return false;
	}
	while (std::getline(inputFile, temp))
	{
		inputArray->push_back(temp);
		numArray.push_back(0);
		for (int i = 0; i < temp.size(); i++)
		{
			// numArray[vec][i].push_back(0);
			numArray[vec][i] = temp[i] - '0';
		}
		vec++;
	}
	return (true);
}