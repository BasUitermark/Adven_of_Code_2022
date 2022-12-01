#include <aoc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

static int	count_line(char *input)
{
	size_t i = 0;
	size_t count = 0;

	while (input[i])
	{
		if (input[i] == '\n')
			count++;
		i++;
	}
	count++;
	return (count);
}

static void make_2d(char *input, t_data *data_set)
{
	int		lines = 0;
	int		lines_n = 0;
	int		i = 0;
	int		start = 0;
	char	**array;

	lines = count_line(input);
	array = calloc(lines + 1, sizeof(char *));
	while (input[i])
	{
		if (input[i - 1] == '\n')
		{
			array[lines_n] = ft_substr(input, start, i - start);
			lines_n++;
			start = i;
		}
		i++;
	}
	array[lines - 1] = strdup("\n");
	data_set->str = array;
	// for (int j = 0; data_set->str[j]; j++)
	// 	printf("%s", data_set->str[j]);
}

bool	read_data(char **input, t_data *data_set)
{
	long	length;
	FILE	*fd = NULL;

	*input = 0;
	fd = fopen("files/input.txt", "rw+");
	if (!fd)
		printf("%s\n", strerror(errno));
	if (fd)
	{
		if (fseek (fd, 0, SEEK_END) == -1)
			return (false);
		length = ftell (fd);
		if (length < 0)
			return (false);
		if (fseek (fd, 0, SEEK_SET) == -1)
			return (false);
		*input = malloc (length);
		if (!*input)
			return (false);
		if (*input)
			fread (*input, 1, length, fd);
		fclose (fd);
	}

	make_2d(*input, data_set);
	return (true);

	return (false);
}