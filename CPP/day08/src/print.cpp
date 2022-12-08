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