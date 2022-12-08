#include <iostream>
#include <string>
#include <vector>
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
	long total = 0;

	for (int i = 0; i < directorySizes.size(); i++)
	{
		if (directorySizes.at(i) <= 100000)
			total += directorySizes.at(i);
	}
	return (total);
}

bool	executePart1(std::vector<std::string> inputArray)
{
	long				total = 0;
	std::vector<long>	directorySizes;

	directorySizes.push_back(0);
	findDirectorySizes(directorySizes, inputArray, 0, 0);
	total = findLowest(directorySizes);
	std::cout << GREEN BOLD "Directories with a total size of at most 100000:	" << total << RESET << std::endl;
	return (true);
}