#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "../include/aoc.hpp"

int main(int argc, char const *argv[])
{
	std::vector<std::string> inputArray;
	std::vector<std::string> movesArray;
	std::vector<std::string> stackArray;

	if (argc != 2 || std::stoi(argv[1]) > 2)
	{
		std::cout << RED "Invalid input" RESET << std::endl;
		return (EXIT_FAILURE);
	}
	if (!readData(&inputArray))
		return (EXIT_FAILURE);
	stackArray = parseData(inputArray);
	inputArray.erase(inputArray.begin(), inputArray.begin() + 10);
	// if (argv[1][0] == '0')
	// 	if (!executeTest(inputArray))
	// 		return (EXIT_FAILURE);
	if (argv[1][0] == '1')
		if (!executePart1(inputArray, stackArray))
			return (EXIT_FAILURE);
	if (argv[1][0] == '2')
		if (!executePart2(inputArray, stackArray))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
