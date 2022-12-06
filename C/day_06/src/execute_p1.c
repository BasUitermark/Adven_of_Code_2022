#include "../include/aoc.h"
#include <stdio.h>
#include <string.h>

bool	execute_p1(char *input)
{
	char	*set;
	int		index;

	set = calloc(4, sizeof(char));
	if (!set)
		exit(EXIT_FAILURE);
	for (int i = 0; input[i]; i++)
	{
		index = i;
		if (!strchr(set, input[i]))
			strncat(set, &input[i], 1);
		if (strlen(set) == 4)
			break ;
	}

	printf(GREEN BOLD"first start-of-packet marker:	%d\n"RESET, index);
	return (true);
}
