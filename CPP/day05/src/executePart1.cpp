#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../include/aoc.hpp"

static std::vector<int>	getNumbers(std::string str)
{
	std::vector<int>	instr;
	std::stringstream 	ss;
	std::string			temp;
	int 				found = 0;

	ss << str;
	while (!ss.eof())
	{
		ss >> temp;
		if (std::stringstream(temp) >> found)
			instr.push_back(found);
		temp = "";
	}
	instr[1] -= 1;
	instr[2] -= 1;
	return (instr);
}

bool	executePart1(std::vector<std::string> inputArray, std::vector<std::string> stackArray)
{
	std::vector<int>	instr;
	std::string			str;

	for (int i = 0; i < inputArray.size(); i++)
	{
		instr = getNumbers(inputArray.at(i));
		for (int j = 0; j < instr.at(0); j++)
		{
			stackArray.at(instr[2]).push_back(stackArray.at(instr[1]).back());
			stackArray.at(instr[1]).pop_back();
		}
	}
	for (int x = 0; x < stackArray.size(); x++)
		str.push_back(stackArray.at(x).back());
	std::cout << GREEN BOLD "Final string: " << str << RESET << std::endl;
	return (true);
}