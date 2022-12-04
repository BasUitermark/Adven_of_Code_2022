#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "../include/aoc.hpp"

static char	findDup(std::string str1, std::string str2, std::string str3)
{
	for (int i = 0; i < str1.length(); i++)
	{
		if (str2.find(str1[i]) != std::string::npos && str3.find(str1[i]) != std::string::npos)
			return (str1[i]);
	}
	return (0);
}

bool	executePart2(std::vector<std::string> inputArray)
{
	int		score = 0;
	char	dup;

	for (int i = 0; i < inputArray.size(); i += 3)
	{
		dup = findDup(inputArray.at(i), inputArray.at(i + 1), inputArray.at(i + 2));
		if (std::islower(dup))
			score += dup - 96;
		else if (std::isupper(dup))
			score += dup - 38;
	}
	std::cout << GREEN BOLD "Total score: " << score << RESET << std::endl;
	return (true);
}