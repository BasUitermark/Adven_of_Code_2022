#include "../include/aoc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int	check_xneg(t_data *data, int line, int column)
{
	int	cur_line = line;

	for (line -= 1; line >= 0; line--)
	{
		if (data->array[line][column] >= data->array[cur_line][column])
			return (0);
	}
	return (1);
}

static int	check_yneg(t_data *data, int line, int column)
{
	int	cur_column = column;

	for (column -= 1; column >= 0; column--)
		if (data->array[line][column] >= data->array[line][cur_column])
			return (0);
	return (1);
}

static int	check_xpos(t_data *data, int line, int column)
{
	int	cur_line = line;

	for (line += 1; line < data->lines; line++)
		if (data->array[line][column] >= data->array[cur_line][column])
			return (0);
	return (1);
}

static int	check_ypos(t_data *data, int line, int column)
{
	int	cur_column = column;

	for (column += 1; column < data->columns; column++)
		if (data->array[line][column] >= data->array[line][cur_column])
			return (0);
	return (1);
}

static int	check_paths(t_data *data)
{
	int sum = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < data->lines; i++)
	{
		for (j = 0; j < data->columns; j++)
		{
			if (check_yneg(data, i, j) || check_ypos(data, i, j) || check_xneg(data, i, j) || check_xpos(data, i, j))
				sum++;
		}	
	}
	return (sum);
}

bool	execute_p1(t_data *data)
{
	int sum = 0;
	sum = check_paths(data);
	printf(GREEN BOLD"Visible trees:	%d\n"RESET, sum);
	return (true);
}