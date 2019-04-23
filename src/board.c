#include "board.h"
#include <stdio.h>
#include <string.h>

extern char turn[11];
extern int X1, X2, Y1, Y2;
extern char board[8][8];

void turn_scan(int flag)
{
    while (1) {
        while (1) {
            fgets(turn, 11, stdin);
            if (chartoint(turn)) {
                break;
            }
            printf("Wrong input, try again:");
            break;
        }
    }
}

int chartoint(char turn[11])
{
    if ((turn[2] != '-') && (turn[2] != 'x')) {
        return 0;
    }
    X1 = (int)turn[0] - 'A';
    Y1 = (int)turn[1] - '1';
    X2 = (int)turn[3] - 'A';
    Y2 = (int)turn[4] - '1';
    if ((turn[2] == 'x') && (board[Y2][X2] == ' ')) {
        printf("Nothing to capture.\n");
        return 0;
    }
    if ((X2 < 8) && (X2 >= 0) && (Y2 >= 0) && (Y2 < 8) && (X1 >= 0) && (X1 < 8) && (Y1 >= 0) && (Y1 < 8))
        return 1;
    return 0;
}

void move()
{
    board[Y2][X2] = board[Y1][X1];
    board[Y1][X1] = ' ';
}
