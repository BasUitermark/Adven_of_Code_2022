#include "../include/aoc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static char	find_dup(char *str, size_t len)
{
	for (size_t i = 0; str[i]; i++)
	{
		for (size_t j = len; str[j]; j++)
		{
			if (str[i] == str[j])
				return (str[i]);
		}
	}
	return (0);
}

bool	execute_p1(t_data *data)
{
	int		sum = 0;
	size_t	len = 0;
	char	dup;

	for (int i = 0; data->str[i]; i++)
	{
		len = strlen(data->str[i]) / 2;
		dup = find_dup(data->str[i], len);
		if (islower(dup))
			sum += dup - 96;
		else if (isupper(dup))
			sum += dup - 38;
	}
	printf(GREEN BOLD"Sum duplicate items:	%d\n"RESET, sum);
	return (true);
}
