#include "../include/aoc.h"
#include <stdio.h>
#include <ctype.h>

static char	find_dup(char *str1, char *str2, char *str3)
{
	for (size_t i = 0; str1[i]; i++)
	{
		for (size_t j = 0; str2[j]; j++)
		{
			for (size_t k = 0; str3[k]; k++)
			{
				if (str1[i] == str2[j] && str2[j] == str3[k])
					return (str1[i]);
			}
		}
	}
	return (0);
}

bool	execute_p2(t_data *data)
{
	int		sum = 0;
	char	dup;

	for (int i = 0; data->str[i]; i += 3)
	{
		dup = find_dup(data->str[i], data->str[i + 1], data->str[i + 2]);
		if (islower(dup))
			sum += dup - 96;
		else if (isupper(dup))
			sum += dup - 38;
	}
	printf(GREEN BOLD"Sum group shared items:	%d\n"RESET, sum);
	return (true);
}
