#include "../include/aoc.h"
#include <stdio.h>
#include <memory.h>
#include <string.h>

bool	parse_data(t_data *data_set, char **input)
{
	data_set->str = ft_split(*input, '\n');
	if (!data_set->str)
		return (false);
	return (true);
}
