#include "../include/aoc.h"
#include <stdio.h>

void	print_strarray(char **str, char *type, char *color)
{
	if (!str)
		return ;
	for (size_t i = 0; str[i] && type && color; i++)
		printf("%s%s%s\n"RESET, type, color, str[i]);
	for (size_t i = 0; str[i] && type && !color; i++)
		printf("%s%s\n"RESET, type, str[i]);
	for (size_t i = 0; str[i] && !type && color; i++)
		printf("%s%s\n"RESET, color, str[i]);
}

void	print(char *str, char *type, char *color)
{
	if (!str)
		return ;
	if (type && color)
		printf("%s%s%s\n"RESET, type, color, str);
	if (type && !color)
		printf("%s%s\n"RESET, type, str);
	if (!type && color)
		printf("%s%s\n"RESET, color, str);
}