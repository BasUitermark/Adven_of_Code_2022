#include "../include/aoc.h"
#include <stdio.h>

bool	execute_p2(t_data *data)
{
	int	score = 0;

	for (int i = 0; data->str[i]; i++)
	{
		if (data->str[i][0] == 'A' && data->str[i][2] == 'X') //Loss: Rock/Scissors 3
			score += 3;
		else if (data->str[i][0] == 'A' && data->str[i][2] == 'Y') //Draw: Rock/Rock 1+3
			score += 4;
		else if (data->str[i][0] == 'A' && data->str[i][2] == 'Z') //Win: Rock/Paper 8
			score += 8;

		else if (data->str[i][0] == 'B' && data->str[i][2] == 'X') //Loss: Paper/Rock 1
			score += 1;
		else if (data->str[i][0] == 'B' && data->str[i][2] == 'Y') //Draw: Paper/Paper 2+3
			score += 5;
		else if (data->str[i][0] == 'B' && data->str[i][2] == 'Z') //Win: Paper/Scissors 3+6
			score += 9;

		else if (data->str[i][0] == 'C' && data->str[i][2] == 'X') //Loss: Scissors/Paper 2
			score += 2;
		else if (data->str[i][0] == 'C' && data->str[i][2] == 'Y') //Draw: Scissors/Scissors 3+3
			score += 6;
		else if (data->str[i][0] == 'C' && data->str[i][2] == 'Z') //Win: Scissors/Rock 1+6
			score += 7;
	}
	printf(GREEN BOLD"Score Count:	%d\n"RESET, score);
	return (true);
}
