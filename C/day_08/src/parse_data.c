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

static void fill_array(t_data *data)
{
	data->array = calloc(data->lines, sizeof(int *));
	for (int i = 0; i < data->lines; i++)
	{
		data->array[i] = calloc(data->columns, sizeof(int));
		for (int j = 0; j < data->columns; j++)
			data->array[i][j] = data->str[i][j] - '0';
	}
}

bool	parse_data(t_data *data, char **input)
{
	data->str = ft_split(*input, '\n');
	if (!data->str)
		return (false);
	data->lines = calc_lines(data->str);
	data->columns = strlen(data->str[0]);
	fill_array(data);
	return (true);
}
