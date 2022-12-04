#include <aoc.h>
#include <stdio.h>

bool	execute_p2(t_data *data)
{
	int	*cur;
	int	*highest;
	int	sum = 0;

	highest = calloc(3, sizeof(int));

	highest[0] = data->elfs[0].total_calories;
	for (size_t i = 0; i < data->elf_amount; i++)
	{
		if (data->elfs[i].total_calories > highest[0])
		{
			highest[2] = highest[1];
			highest[1] = highest[0];
			highest[0] = data->elfs[i].total_calories;
		}
	}
	sum = highest[0] + highest[1] + highest[2];
	printf(GREEN BOLD"Calorie amount:			%d calories\n"RESET, sum);
	return(true);
}
