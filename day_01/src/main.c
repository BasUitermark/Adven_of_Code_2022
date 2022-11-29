#include <aoc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	const char	*input;
	t_data		data_set;

	(void)		argc;
	if (!read_data(&input))
	{
		printf("Hello\n");
		printf("%s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	printf("%s", input);
	// if (!parse_data(&data_set, &input))
	// 	return (EXIT_FAILURE); 
	// if (argv[1][0] == '1')
	// 	if (!execute_p1(&data_set))
	// 		return (EXIT_FAILURE);
	// if (argv[1][0] == '2')
	// 	if (!execute_p1(&data_set))
	// 			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
