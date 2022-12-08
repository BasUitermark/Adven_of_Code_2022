#ifndef AOC_HPP
# define AOC_HPP

#include <vector>
#include <string>

# define INPUT "files/input.txt"
# define TEST "files/test.txt"

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

bool	readData(std::vector<std::string> *inputArray);
bool	executeTest(std::vector<std::string> inputArray);
bool	executePart1(std::vector<std::string> inputArray);
bool	executePart2(std::vector<std::string> inputArray);

void	printVectorString(std::vector<std::string> vectorString);
void	printVectorLong(std::vector<long> vectorLong);

#endif