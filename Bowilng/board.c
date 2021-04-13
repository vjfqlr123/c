#include <stdio.h>
#include <stdlib.h>
#include "board.h"

static char board[7][44] = {
	"-------------------------------------------",
	"| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10  |",
	"-------------------------------------------",
	"| | | | | | | | | | | | | | | | | | | | | |",
	"-------------------------------------------",
	"|   |   |   |   |   |   |   |   |   |     |",
	"-------------------------------------------",
};

void printBoard(void)
{
	system("clear");
	
	for(int i=0; i<7; ++i)
		printf("%s\n", board[i]);			// board[i] == &board[i][0]
}

void setFrameScore(int frame, int bow, int score)
{

}

void setScore(int frame, int score)
{

}
