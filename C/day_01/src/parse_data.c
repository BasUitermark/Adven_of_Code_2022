#include <aoc.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

static bool	count_elfs(t_data *data_set, char **input)
{
	size_t	i = 0;
	size_t	count = 0;

	if (!data_set->str)
		return (false);
	while (data_set->str[i])
	{
		if (data_set->str[i][0] == '\n')
			count++;
		i++;
	}
	if (count)
		data_set->elf_amount = count;
	return (true);
}


static bool	init_elfs(t_data *data)
{
	size_t	cur = 0;
	size_t	i = 0;

	data->elfs = calloc(data->elf_amount, sizeof(t_elf));
	while (data->str[i] || cur < data->elf_amount)
	{
		while (data->str[i][0] != '\n')
		{
			data->elfs[cur].total_calories += atoi(data->str[i]);
			// data->elfs[cur].n_items++;
			i++;
		}
		i++;
		cur++;
	}
	return (true);
}

bool	parse_data(t_data *data_set, char **input)
{
	if (!count_elfs(data_set, input))
		return (false);
	if (!init_elfs(data_set))
		return (false);
	return (true);
}
