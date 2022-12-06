#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../include/aoc.hpp"

static bool	checkChar(std::string *input, char c)
{
	int	count = 0;

	for (int i = 0; i < 4 && input[i]; i++)
	{
		if (input[i] == c)
			count++;
		if (count > 1)
			return(true);
	}
	return (false);
}

bool	executePart1(std::vector<std::string> inputArray)
{
		int	index;
	int	j = 0;

	for (int i = 0; inputArray[0][i]; i++)
	{
		index = i;
		while (j < 4 && !checkChar(inputArray.at(0)., input[i + j]))
			j++;
		if (j == 4)
			break ;
		j = 0;
	}
	// std::cout << GREEN BOLD "Final string: " << str << RESET << std::endl;
	return (true);
}
