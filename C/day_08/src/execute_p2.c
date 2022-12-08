#include "../include/aoc.h"
#include <stdio.h>
#include <string.h>

static int	check_xneg(t_data *data, int line, int column)
{
	int	cur_line = line;
	int scenic_xneg = 0;

	for (line -= 1; line >= 0; line--)
	{
		scenic_xneg++;
		if (data->array[line][column] >= data->array[cur_line][column])
			return (scenic_xneg);
	}
	return (scenic_xneg);
}

static int	check_yneg(t_data *data, int line, int column)
{
	int	cur_column = column;
	int	scenic_yneg = 0;

	for (column -= 1; column >= 0; column--)
	{
		scenic_yneg++;
		if (data->array[line][column] >= data->array[line][cur_column])
			return (scenic_yneg);
	}
	return (scenic_yneg);
}

static int	check_xpos(t_data *data, int line, int column)
{
	int	cur_line = line;
	int	scenic_xpos = 0;

	for (line += 1; line < data->lines; line++)
	{
		scenic_xpos++;
		if (data->array[line][column] >= data->array[cur_line][column])
			return (scenic_xpos);
	}
	return (scenic_xpos);
}

static int	check_ypos(t_data *data, int line, int column)
{
	int	cur_column = column;
	int	scenic_ypos = 0;

	for (column += 1; column < data->columns; column++)
	{
		scenic_ypos++;
		if (data->array[line][column] >= data->array[line][cur_column])
			return (scenic_ypos);
	}
	return (scenic_ypos);
}

static int	check_paths(t_data *data)
{
	int score[4];
	int max = 0;
	int new = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < data->lines; i++)
	{
		for (j = 0; j < data->columns; j++)
		{
			score[0] = check_yneg(data, i, j);
			score[1] = check_ypos(data, i, j);
			score[2] = check_xneg(data, i, j);
			score[3] = check_xpos(data, i, j);
			new = score[0] * score[1] * score[2] * score[3];
			if (new > max)
				max = new;
		}
	}

	return (max);
}

bool	execute_p2(t_data *data)
{
	int max = 0;
	max = check_paths(data);
	printf(GREEN BOLD"Maximum scenic score:	%d\n"RESET, max);
	return (true);
}
