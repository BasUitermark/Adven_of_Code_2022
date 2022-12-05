#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>
#include "../include/aoc.hpp"

static std::vector<int>	getNumbers(std::string str)
{
	std::vector<int>	range;
	std::stringstream ss;
	std::string temp;
	int found = 0;

	std::replace(str.begin(), str.end(), '-', ' ');
	std::replace(str.begin(), str.end(), ',', ' ');

	ss << str;
	while (!ss.eof())
	{
		ss >> temp;
		if (std::stringstream(temp) >> found)
			range.push_back(found);
		temp = "";
	}
	return (range);
}

static bool	inRange(unsigned low, unsigned high, unsigned x)         
{
	return (low <= x && x <= high);         
}

static int	result(std::vector<int> range)
{
	if (inRange(range[0], range[1], range[2]))
		return (1);
	else if (inRange(range[0], range[1], range[3]))
		return (1);
	else if (inRange(range[2], range[3], range[0]))
		return (1);
	else if (inRange(range[2], range[3], range[1]))
		return (1);
	return (0);
}

bool	executePart2(std::vector<std::string> inputArray)
{
	int		score = 0;
	std::vector<int>	range;

	for (int i = 0; i < inputArray.size(); i++)
	{
		range = getNumbers(inputArray.at(i));
		score += result(range);
	}

	std::cout << GREEN BOLD "Total overlap: " << score << RESET << std::endl;
	return (true);
}