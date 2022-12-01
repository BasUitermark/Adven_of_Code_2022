#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <aoc.hpp>

int main(int argc, char const *argv[])
{
	std::vector<std::string> inputArray;

	if (argc != 2 || std::stoi(argv[1]) > 2)
		std::cout << GREEN "Get fucked mate" << std::endl;

	if (!readData(inputArray))
		return (EXIT_FAILURE);
	// if (!parse_data(&data_set, &input))
	// 	return (EXIT_FAILURE);

	// if (argv[1][0] == '0')
	// 	if (!execute_test(&data_set))
	// 		return (EXIT_FAILURE);
	// if (argv[1][0] == '1')
	// 	if (!execute_p1(&data_set))
	// 		return (EXIT_FAILURE);
	// if (argv[1][0] == '2')
	// 	if (!execute_p2(&data_set))
	// 		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
