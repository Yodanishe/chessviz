#include <stdio.h>
#include "board.h"
#include "board_print.h"

char turn[11];
int X1, X2, Y1, Y2;
char board[9][9] = {{'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'},
	{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
	{'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'}};

int main() {
	printboard();
	while(1) {
		turn_scan(1);
		move();
		printboard();

		turn_scan(2);
		move();
		printboard();
	}
	return 0;
}