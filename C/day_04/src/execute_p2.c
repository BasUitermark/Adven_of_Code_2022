#include "../include/aoc.h"
#include <stdio.h>
#include <ctype.h>

static int	calc_overlap(int elfs[4])
{
	if (elfs[0] >= elfs[2] && elfs[0] <= elfs[3])
		return (1);
	else if (elfs[1] >= elfs[2] && elfs[1] <= elfs[3])
		return (1);
	else if (elfs[2] >= elfs[0] && elfs[2] <= elfs[1])
		return (1);
	else if (elfs[3] >= elfs[0] && elfs[3] <= elfs[1])
		return (1);
	return (0);
}

bool	execute_p2(t_data *data)
{
	int elfs[4];
	int	e = 0;
	int	count = 0;
	
	for (size_t i = 0; data->str[i]; i++)
	{
		for (size_t j = 0; data->str[i][j]; j++)
		{
			if (j == 0 || data->str[i][j - 1] == '-' || data->str[i][j - 1] == ',')
			{
				elfs[e] = atoi(&data->str[i][j]);
				e++;
			}
		}
		e = 0;
		count += calc_overlap(elfs);
	}
	printf(GREEN BOLD"Number of overlapped sections:	%d\n"RESET, count);
	return (true);
}
