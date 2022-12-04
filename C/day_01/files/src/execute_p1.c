#include <aoc.h>
#include <stdio.h>

bool	execute_p1(t_data *data)
{
	int	highest = 0;
	int	cur = 0;

	highest = data->elfs[0].total_calories;
	for (size_t i = 0; i < data->elf_amount; i++)
	{
		if (data->elfs[i].total_calories > highest)
		{
			highest = data->elfs[i].total_calories;
			cur = i;
		}
	}
	printf(GREEN BOLD"Elf with the highest calories:	#%d\n"RESET, cur);
	printf(GREEN BOLD"Calorie amount:			%d calories\n"RESET, highest);
	return (true);
}
