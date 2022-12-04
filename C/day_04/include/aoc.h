#ifndef AOC_H
# define AOC_H

# include <stdbool.h>
# include <stdlib.h>

# define TEST "files/test.txt"
# define ONE "files/input.txt"

//========== Colors ============//
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

# define BOLD		"\x1b[1m"
# define ITALIC		"\x1b[3m"
# define LINE		"\x1b[4m"
# define BLINK		"\x1b[5m"
# define CROSS		"\x1b[9m"

typedef struct s_elf
{
	int	n_items;
	int	*calories_item;
	int	total_calories;
}	t_elf;

typedef struct s_data
{
	char	**str;
	size_t	lines;
}	t_data;

//===== Functions =====//

int		main(int argc, char const *argv[]);
bool	read_data(char **input, t_data *data_set);
bool	parse_data(t_data *data_set, char **input);

bool	execute_test(t_data *data);
bool	execute_p1(t_data *data);
bool	execute_p2(t_data *data);

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	**ft_split(char const *s, char c);

void	print_strarray(char **str, char *type, char *color);
void	print(char *str, char *type, char *color);

#endif