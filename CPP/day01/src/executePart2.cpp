#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "../include/aoc.hpp"

bool	executePart2(std::vector<std::string> inputArray)
{
	int	amount[3] = {0, 0, 0};
	int	temp = 0;

	for (int i = 0; i < inputArray.size(); i++)
	{
		while (inputArray[i].size() > 0 && i < inputArray.size())
		{
			temp += std::atoi(inputArray.at(i).c_str());
			i++;
		}
		if (temp > amount[0])
		{
			amount[2] = amount[1];
			amount[1] = amount[0];
			amount[0] = temp;
		}
		temp = 0;
	}
	std::cout << GREEN BOLD "Sum of top 3 calorie amounts: " << amount[0] + amount[1] + amount[2]<< RESET << std::endl;
	return (true);
}