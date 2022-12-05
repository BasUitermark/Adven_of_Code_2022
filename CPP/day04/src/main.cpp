#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <aoc.hpp>

int main(int argc, char const *argv[])
{
	std::vector<std::string> inputArray;

	if (argc != 2 || std::stoi(argv[1]) > 2)
	{
		std::cout << RED "Invalid input" RESET << std::endl;
		return (EXIT_FAILURE);
	}
	if (!readData(&inputArray))
		return (EXIT_FAILURE);

	// if (argv[1][0] == '0')
	// 	if (!executeTest(inputArray))
	// 		return (EXIT_FAILURE);
	if (argv[1][0] == '1')
		if (!executePart1(inputArray))
			return (EXIT_FAILURE);
	if (argv[1][0] == '2')
		if (!executePart2(inputArray))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
