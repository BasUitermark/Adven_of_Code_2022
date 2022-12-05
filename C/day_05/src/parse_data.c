#include "../include/aoc.h"
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

// static int	detect_filler(t_data *str)
// {
// 	if (data->str[line][column] == '[');
// 		return (1);

// 	return (0);
// }

static char	**parse_stack(char **str)
{
	char	**stacks;
	int		line = 0;
	int		column = 1;
	int		i;
	int		j;

	stacks = calloc(10, sizeof(char *));
	if (!stacks)
		return (NULL);
	for (i = 0; i < 9; i++)
	{
		stacks[i] = calloc(1024, sizeof(char));
		if (!stacks[i])
		{
			free (stacks);
			return (NULL);
		}
		for (j = 0; j < 8 && line < 8; j++)
		{
			while (str[line][column] == ' ')
				line++;
			strncat(stacks[i], &str[line][column], 1);
			stacks[i][j] = str[line][column];
			line++;
		}
		line = 0;
		column += 4;
	}
	return (stacks);
}

bool	parse_data(t_data *data_set, char **input)
{
	data_set->str = ft_split(*input, '\n');
	if (!data_set->str)
		return (false);
	data_set->stack = parse_stack(data_set->str);
	if (!data_set->stack)
		exit (EXIT_FAILURE);
	print_strarray(data_set->stack, NULL, NULL);
	return (true);
}
