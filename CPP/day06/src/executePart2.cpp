#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../include/aoc.hpp"

static bool	checkChar(std::string input, char c)
{
	int	count = 0;

	for (int i = 0; i < 14 && i < input.size(); i++)
	{
		if (input[i] == c)
			count++;
		if (count > 1)
			return(true);
	}
	return (false);
}

bool	executePart2(std::vector<std::string> inputArray)
{
	int	index;
	int	j = 0;

	for (int i = 0; inputArray[0][i]; i++)
	{
		index = i;
		while (j < 14 && !checkChar(inputArray.at(0).substr(i, 14), inputArray.at(0).at(i + j)))
			j++;
		if (j == 14)
			break ;
		j = 0;
	}
	std::cout << GREEN BOLD "First start-of-packet marker: " << index + 14 << RESET << std::endl;
	return (true);
}