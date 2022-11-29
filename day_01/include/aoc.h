#ifndef AOC_H
# define AOC_H

# include <stdbool.h>

typedef struct s_data
{

}	t_data;

//===== Functions =====//

int 	main(int argc, char const *argv[]);
bool	read_data(char **input);
bool	parse_data(t_data *data_set, char **input);

#endif