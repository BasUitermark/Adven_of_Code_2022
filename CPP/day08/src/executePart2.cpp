#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "../include/aoc.hpp"

static int findDirectorySizes(std::vector<long> &directorySizes, std::vector<std::string> inputArray, int index, int pos)
{
	int	i;
	int cur = pos;

	for (i = index; i < inputArray.size(); i++)
	{
		if (std::isdigit(inputArray.at(i).at(0)))
			directorySizes.at(cur) += std::stol(inputArray.at(i));
		if (inputArray.at(i).compare(0, 7, "$ cd ..") == 0)
			return (i);
		if (inputArray.at(i).compare(0, 5, "$ cd ") == 0 && inputArray.at(i).at(5) != '/')
		{
			directorySizes.push_back(0);
			while (directorySizes[pos + 1] != 0)
				pos++;
			i = findDirectorySizes(directorySizes, inputArray, i + 1, pos + 1);
			directorySizes[cur] += directorySizes[pos + 1];
		}
	}
	return (i);
}

static long	findLowest(std::vector<long> directorySizes)
{
	long free_space;
	long min;
	long cur;

	free_space = 70000000 - directorySizes.at(0);
	min = 30000000 - free_space;
	cur = directorySizes.at(0);
	for (int i = 0; i < directorySizes.size(); i++)
	{
		if (directorySizes.at(i) < cur && directorySizes.at(i) > min)
			cur = directorySizes.at(i);
	}
	return (cur);
}

bool	executePart2(std::vector<std::string> inputArray)
{
	long				total = 0;
	std::vector<long>	directorySizes;

	directorySizes.push_back(0);
	findDirectorySizes(directorySizes, inputArray, 0, 0);
	total = findLowest(directorySizes);
	std::cout << GREEN BOLD "Smallest directory to free up space:	" << total << RESET << std::endl;
	return (true);
}