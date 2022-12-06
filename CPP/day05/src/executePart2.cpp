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

bool	executePart2(std::vector<std::string> inputArray, std::vector<std::string> stackArray)
{
	std::vector<int>	instr;
	std::string			str;

	for (int i = 0; i < inputArray.size(); i++)
	{
		instr = getNumbers(inputArray.at(i));
		stackArray.at(instr[2]).append(stackArray.at(instr[1]).end() - instr.at(0), stackArray.at(instr[1]).end());
		stackArray.at(instr[1]).resize(stackArray.at(instr[1]).size() - instr.at(0));
	}
	for (int j = 0; j < stackArray.size(); j++)
		str.push_back(stackArray.at(j).back());

	std::cout << GREEN BOLD "Final string: " << str << RESET << std::endl;
	return (true);
}