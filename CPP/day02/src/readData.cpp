#include "aoc.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>

bool	readData(std::vector<std::string> *inputArray)
{
	std::ifstream	inputFile(INPUTFILE);
	std::string		temp;

	if (!inputFile)
	{
		std::cerr << "Cannot open the File : " << INPUTFILE << std::endl;
		return false;
	}
	while (std::getline(inputFile, temp))
		inputArray->push_back(temp);
	return (true);
}