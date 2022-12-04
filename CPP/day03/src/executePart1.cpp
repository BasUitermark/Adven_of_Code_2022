#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <bits/stdc++.h>
#include "../include/aoc.hpp"

static char	findDup(std::string str1, std::string str2, int len)
{
	for (int i = 0; i < str1.length(); i++)
	{
		if (str2.find(str1[i]) != std::string::npos)
			return (str1[i]);
	}
	return (0);
}

bool	executePart1(std::vector<std::string> inputArray)
{
	int		score = 0;
	int 	len = 0;
	char	dup;

	for (int i = 0; i < inputArray.size(); i++)
	{
		len = inputArray.at(i).length() / 2;
		dup = findDup(inputArray.at(i), &inputArray.at(i)[len], len);
		if (std::islower(dup))
			score += dup - 96;
		else if (std::isupper(dup))
			score += dup - 38;
	}
	std::cout << GREEN BOLD "Total score: " << score << RESET << std::endl;
	return (true);
}