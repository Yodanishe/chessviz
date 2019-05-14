#include "board.h"
#include "board_print.h"
#include <stdio.h>

char turn[11];
int X1, X2, Y1, Y2;
char board[8][8] = {{'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'}};

int main()
{
    int status = 0;

    printboard();
    printf("Example of turn:'A1-A3' or 'A1xA3' for catch.\nPlease input a "
           "turn: ");
    while (1) {
	  printf("White (Big letters):");
        turn_scan(1);
        move();
        printboard();
        status = checkWin(1);
        if (status != 0) {
            break;
	   }

	  printf("Black (little letters):");
        turn_scan(2);
        move();
        printboard();
        status = checkWin(2);
        if (status != 0) {
            break;
        }
    }
    printf("Player %d win\n", status);

    return 0;
}
