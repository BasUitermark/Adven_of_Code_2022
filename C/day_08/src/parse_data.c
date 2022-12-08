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

static int **fill_array(t_data *data)
{
	data->array = calloc(data->lines, sizeof(int *))

}

bool	parse_data(t_data *data, char **input)
{
	data->str = ft_split(*input, '\n');
	if (!data->str)
		return (false);
	data->lines = calc_lines(data->str);
	fill_array(data);
	return (true);
}
