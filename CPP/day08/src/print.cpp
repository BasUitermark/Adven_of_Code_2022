#include "../include/aoc.hpp"
#include <vector>
#include <string>
#include <iostream>

void	printVectorString(std::vector<std::string> vectorString)
{
	for (int i = 0; i < vectorString.size(); i++)
		std::cout << vectorString[i] << std::endl;
}

void	printVectorLong(std::vector<long> vectorLong)
{
	for (int i = 0; i < vectorLong.size(); i++)
		std::cout << vectorLong[i] << std::endl;
}

void	printVectorInt(std::vector<std::vector<int>> vectorInt)
{
	for (int i = 0; i < vectorInt.size(); i++)
	{
		for (int j = 0; j < vectorInt.at(i).size(); j++)
			std::cout << vectorInt[i][j] << ' ';
		std::cout << std::endl;
	}
}