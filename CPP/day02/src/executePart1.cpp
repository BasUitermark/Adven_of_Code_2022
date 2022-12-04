#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/aoc.hpp"

static int	gamePlay(hand me, hand opponent)
{
	int	score = me;

	if (me == opponent)
		return (score + draw);

	switch (me)
	{
		case Rock:
			switch (opponent)
			{
				case Paper:
					score += loss;
					break;
				case Scissors:
					score += win;
					break;
			}
			break;
		case Paper:
			switch (opponent)
			{
				case Rock:
					score += win;
					break;
				case Scissors:
					score += loss;
					break;
			}
			break;
		case Scissors:
			switch (opponent)
			{
				case Rock:
					score += loss;
					break;
				case Paper:
					score += win;
					break;
			}
			break;
	}
	return score;
}

static void	findHand(hand *me, hand *opponent, std::string str)
{
	if (str.at(0) == 'A')
		*opponent = Rock;
	if (str.at(0) == 'B')
		*opponent = Paper;
	if (str.at(0) == 'C')
		*opponent = Scissors;

	if (str.at(2) == 'X')
		*me = Rock;
	if (str.at(2) == 'Y')
		*me = Paper;
	if (str.at(2) == 'Z')
		*me = Scissors;
}

bool	executePart1(std::vector<std::string> inputArray)
{
	int	score = 0;
	hand	me;
	hand	opponent;

	for (int i = 0; i < inputArray.size(); i++)
	{
		findHand(&me, &opponent, inputArray.at(i));
		score += gamePlay(me, opponent);
	}
	std::cout << GREEN BOLD "Total score: " << score << RESET << std::endl;
	return (true);
}