#include "../include/aoc.h"
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

static int	calc_lines(char **str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

static int	find_directories(char **str)
{
	int	found = 0;

	for (int i = 0; str[i]; i++)
		if (strncmp(str[i], "dir", 3) == 0)
			found++;
	return (found);
}

bool	parse_data(t_data *data, char **input)
{
	data->str = ft_split(*input, '\n');
	if (!data->str)
		return (false);
	data->lines = calc_lines(data->str);
	data->number_of_directories = find_directories(data->str) + 1;
	return (true);
}
