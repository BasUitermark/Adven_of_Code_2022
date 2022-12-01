#include <vector>
#include <iostream>
#include <fstream>

static int	getLineCount(void)
{
	std::ifstream	inputFile("/home/buiterma/Documents/Personal/Adven_of_Code_2022/CPP/day_01/files/input.txt");
	std::string	line;
	int			i = 0;
	int			count = 0;

	if (inputFile.is_open())
	{
		while (inputFile.peek() != EOF)
		{
			getline(inputFile, line);
			count++;
		}
	}
	else
		exit(1);
	inputFile.close();
	return (count);
}

bool	readData(std::string *inputArray)
{
	std::string		*temp;
	std::ifstream	inputFile("/home/buiterma/Documents/Personal/Adven_of_Code_2022/CPP/day_01/files/input.txt");
	int				i = 0;
	int				count = 0;

	count = getLineCount();
	temp = calloc(count, sizeof(std::string));
	// if (inputFile.is_open())
	// {
	// 	while (getline(inputFile, temp))
	// 	{
	// 		inputArray[i] = temp;
	// 		i++;
	// 	}
	// }
	// else
	// 	return (false);
	return (true);
}