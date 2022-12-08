#include "../include/aoc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int	find_directory_sizes(long *directory_sizes, char **str, int index, int pos, int size)
{
	int	i;
	int cur = pos;

	for (i = index; i < size; i++)
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

static long	find_lowest(long *directory_sizes, int n)
{
	long total = 0;

	for (int i = 0; i < n; i++)
	{
		if (directory_sizes[i] <= 100000)
			total += directory_sizes[i];
	}
	return (total);
}

bool	execute_p1(t_data *data)
{
	int	total = 0;
	long	*directory_sizes;

	directory_sizes = calloc(data->number_of_directories, sizeof(long));
	if (!directory_sizes)
		exit(EXIT_FAILURE);
	
	find_directory_sizes(directory_sizes, data->str, 0, 0, data->lines);
	total = find_lowest(directory_sizes, data->number_of_directories);
	printf(GREEN BOLD"Directories with a total size of at most 100000:	%d\n"RESET, total);
	return (true);
}
