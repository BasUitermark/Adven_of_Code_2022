#include "../include/aoc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void	run_instructions(int *moves, t_data *data)
{
	int	pos;
	int	src;
	int	dest;

	for (int i = 0; i < moves[0]; i++)
	{
		src = moves[1] - 1;
		dest = moves[2] - 1;
		pos = strlen(data->stack[src]) - 1;
		strncat(data->stack[dest], &data->stack[src][pos], 1);
		data->stack[src][pos] = '\0';
	}
}

static char	*make_final_str(char **stack)
{
	char	*str;
	int		pos;

	str = calloc(9, sizeof(char));
	if (!str)
		exit(EXIT_FAILURE);
	for (int i = 0; i < 9; i++)
	{
		pos = strlen(stack[i]) - 1;
		strncat(str, &stack[i][pos], 1);
	}
	return (str);
}

bool	execute_p1(t_data *data)
{
	int		*moves;
	char	*str;

	moves = calloc(3, sizeof(int));
	if (!moves)
		exit (EXIT_FAILURE);
	for (int i = 0; data->moves[i]; i++)
	{
		sscanf(data->moves[i], "%*[^0123456789]%d%*[^0123456789]%d%*[^0123456789]%d", &moves[0], &moves[1], &moves[2]);
		run_instructions(moves, data);
	}
	str = make_final_str(data->stack);
	printf(GREEN BOLD"Final string:	%s\n"RESET, str);
	return (true);
}
