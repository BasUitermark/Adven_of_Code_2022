#include "../include/aoc.h"
#include <stdio.h>
#include <string.h>

static bool	check_char(char *input, char c)
{
	int	count = 0;

	for (int i = 0; i < 14 && input[i]; i++)
	{
		if (input[i] == c)
			count++;
		if (count > 1)
			return(true);
	}
	return (false);
}

bool	execute_p2(char *input)
{
	int	index;
	int	j = 0;

	for (int i = 0; input[i]; i++)
	{
		index = i;
		while (j < 14 && !check_char(&input[i], input[i + j]))
			j++;
		if (j == 14)
			break ;
		j = 0;
	}
	printf(GREEN BOLD"First start-of-packet marker:	%d\n"RESET, index + 14);
	return (true);
}
