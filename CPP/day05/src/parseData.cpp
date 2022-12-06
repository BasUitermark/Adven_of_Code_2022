#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <stack>
#include <aoc.hpp>

std::vector<std::string>	parseData(std::vector<std::string> inputArray)
{
	std::vector<std::string> stackArray;
	int	line = 0;
	int	column = 1;

	for (int x = 0; x < 9; x++)
	{
		stackArray.push_back("");
		for (int y = 0; y < 8 && line < 8; y++)
		{
			while (inputArray[line][column] == ' ')
				line++;
			stackArray[x].insert(0, &inputArray[line][column], 1);
			line++;
		}
		line = 0;
		column += 4;
	}
	return (stackArray);
}
