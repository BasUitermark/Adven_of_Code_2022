#include "../include/aoc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int	find_directory_sizes(long *directory_sizes, char **str, int index, int pos, int size)
{
	int	i;
	int cur = pos;

	for (i = index; i < size ; i++)
	{
		if (isdigit(str[i][0])) //add number to array
			directory_sizes[cur] += atol(str[i]);
		if (strncmp(str[i], "$ cd ..", 7) == 0) //return to prev dir
			return (i);
		if (strncmp(str[i], "$ cd ", 5) == 0 && str[i][5] != '/') //go to next dir
		{
			while (directory_sizes[pos + 1] != 0)
				pos++;
			i = find_directory_sizes(directory_sizes, str, i + 1, pos + 1, size);
			directory_sizes[cur] += directory_sizes[pos + 1];
		}
	}
	return (i);
}

bool	execute_test(t_data *data)
{
	int	total = 0;
	long	*directory_sizes;

	directory_sizes = calloc(data->number_of_directories, sizeof(long));
	if (!directory_sizes)
		exit(EXIT_FAILURE);
	
	find_directory_sizes(directory_sizes, data->str, 0, 0, data->lines);
	for (int i = 0; i < data->number_of_directories; i++)
	{
		printf("%d#	", i);
		printf("%ld\n", directory_sizes[i]);
	}
	// printf(GREEN BOLD"First start-of-packet marker:	%d\n"RESET, index + 4);
	return (true);
}
