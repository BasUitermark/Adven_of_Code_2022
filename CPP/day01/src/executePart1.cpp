#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/aoc.hpp"

bool	executePart1(std::vector<std::string> inputArray)
{
	int	amount = 0;
	int	temp = 0;

	for (int i = 0; i < inputArray.size(); i++)
	{
		while (inputArray[i].size() > 0 && i < inputArray.size())
		{
			temp += std::atoi(inputArray.at(i).c_str());
			i++;
		}
		if (temp > amount)
			amount = temp;
		temp = 0;
	}
	std::cout << GREEN BOLD "Biggest calorie amount: " << amount << RESET << std::endl;
	return (true);
}