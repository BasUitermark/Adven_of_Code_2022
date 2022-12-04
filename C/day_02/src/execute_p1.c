#include "../include/aoc.h"
#include <stdio.h>

bool	execute_p1(t_data *data)
{
	int	score = 0;

	for (int i = 0; data->str; i++)
	{
		if (data->str[i][0] == 'A' && data->str[i][2] == 'X') //Draw: Rock/Rock 1+3
			score += 4;
		else if (data->str[i][0] == 'A' && data->str[i][2] == 'Y') //Win: Rock/Paper 2+6
			score += 8;
		else if (data->str[i][0] == 'A' && data->str[i][2] == 'Z') //Loss: Rock/Scissors 3
			score += 3;

		else if (data->str[i][0] == 'B' && data->str[i][2] == 'X') //Loss: Paper/Rock 1
			score += 1;
		else if (data->str[i][0] == 'B' && data->str[i][2] == 'Y') //Draw: Paper/Paper 5
			score += 5;
		else if (data->str[i][0] == 'B' && data->str[i][2] == 'Z') //Win: Paper/Scissors 3+6
			score += 9;

		else if (data->str[i][0] == 'C' && data->str[i][2] == 'X') //Win: Scissors/Rock 1+6
			score += 7;
		else if (data->str[i][0] == 'C' && data->str[i][2] == 'Y') //Loss: Scissors/Paper 2
			score += 2;
		else if (data->str[i][0] == 'C' && data->str[i][2] == 'Z') //Draw: Scissors/Scissors 3+3
			score += 6;
	}
	printf(GREEN BOLD"Score Count:	%d\n"RESET, score);
	return (true);
}
