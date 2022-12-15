#include "../include/aoc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>



bool	execute_test(t_data *data)
{
	int		*head;
	int		*tail;
	t_list	*coord_database;

	head = calloc(2, sizeof(int));
	tail = calloc(2, sizeof(int));
	coord_database = ft_lstnew(tail);

	for (int i = 0; data->str[i]; i++)
	{
		execute_head_move(data->str, head);
		if (!verify_tail(head, tail))
		{
			execute_tail_move(head, tail);
			update_database(tail, coord_database);
		}
	}
	// printf(GREEN BOLD"Maximum scenic score:	%d\n"RESET, max);
	return (true);
}
