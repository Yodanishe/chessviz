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
        }
        if (flag == 1) {
            if (white() == 1) {
                break;
            } else {
                printf("Wrong input, try again:");
            }
        }
        if (flag == 2) {
            if (black() == 1) {
                break;
            } else {
                printf("Wrong input, try again:");
            }
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
    if ((X2 < 8) && (X2 >= 0) && (Y2 >= 0) && (Y2 < 8) && (X1 >= 0) && (X1 < 8)
        && (Y1 >= 0) && (Y1 < 8))
        return 1;
    return 0;
}

int white()
{
    if ((board[Y2][X2] > 'A') && (board[Y2][X2] < 'S')) {
        return 0;
    }
    switch (board[Y1][X1]) {
    case 'P': {
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if ((board[Y2][X2] == ' ') && (Y1 == 1) && (X1 == X2) && (Y2 - Y1 > 0)
            && (Y2 - Y1 < 3) && checkY()) {
            return 1;
        }
        if ((board[Y2][X2] == ' ') && (X2 == X1) && (Y2 - Y1 == 1)) {
            return 1;
        }
        if ((board[Y2][X2] < 's' && board[Y2][X2] > 'a')
            && ((X2 - X1 == 1) || (X2 - X1 == -1)) && (Y2 - Y1 == 1)
            && (turn[2] == 'x')) {
            return 1;
        }}
        break;
    case 'R':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if ((Y2 == Y1) && (checkX())) {
            return 1;
        }
        if ((X2 == X1) && (checkY())) {
            return 1;
        }
        break;
    case 'N':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if ((Y1 - Y2 == 2) && (X1 - X2 == 1)) {
            return 1;
        }
        if ((Y2 - Y1 == 2) && (X2 - X1 == 1)) {
            return 1;
        }
        if ((Y2 - Y1 == 2) && (X1 - X2 == 1)) {
            return 1;
        }
        if ((Y1 - Y2 == 2) && (X2 - X1 == 1)) {
            return 1;
        }
        if ((Y1 - Y2 == 1) && (X2 - X1 == 2)) {
            return 1;
        }
        if ((Y2 - Y1 == 1) && (X2 - X1 == 2)) {
            return 1;
        }
        if ((Y1 - Y2 == 1) && (X1 - X2 == 2)) {
            return 1;
        }
        if ((Y2 - Y1 == 1) && (X1 - X2 == 2)) {
            return 1;
        }
        break;
    case 'B':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if (checkD()) {
            return 1;
        }
        break;
    case 'K':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if ((Y1 - Y2 != 1) && (Y2 - Y1 != 1)
            && ((X1 - X2 != 1) && (X2 - X1 != 1))) {
            break;
        } else {
            return 1;
        }
        break;
    case 'Q':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if (checkX() || checkY() || checkD()) {
            return 1;
        }
        break;
    }
    return 0;
}
int black()
{
    if ((board[Y2][X2] > 'a') && (board[Y2][X2] < 's')) {
        return 0;
    }
    switch (board[Y1][X1]) {
    case 'p':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if ((board[Y2][X2] == ' ') && (Y1 == 6) && (X1 == X2) && (Y1 - Y2 > 0)
            && (Y1 - Y2 < 3) && checkY()) {
            return 1;
        }
        if ((board[Y2][X2] == ' ') && (X2 == X1) && (Y1 - Y2 == 1)) {
            return 1;
        }
        if ((board[Y2][X2] < 'S' && board[Y2][X2] > 'A')
            && ((X1 - X2 == 1) || (X1 - X2 == -1)) && (Y1 - Y2 == 1)) {
            return 1;
        }
        break;
    case 'r':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if ((Y2 == Y1) && (checkX())) {
            return 1;
        }
        if ((X2 == X1) && (checkY())) {
            return 1;
        }
        break;
    case 'n':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if ((Y1 - Y2 == 2) && (X1 - X2 == 1)) {
            return 1;
        }
        if ((Y2 - Y1 == 2) && (X2 - X1 == 1)) {
            return 1;
        }
        if ((Y2 - Y1 == 2) && (X1 - X2 == 1)) {
            return 1;
        }
        if ((Y1 - Y2 == 2) && (X2 - X1 == 1)) {
            return 1;
        }
        if ((Y1 - Y2 == 1) && (X2 - X1 == 2)) {
            return 1;
        }
        if ((Y2 - Y1 == 1) && (X2 - X1 == 2)) {
            return 1;
        }
        if ((Y1 - Y2 == 1) && (X1 - X2 == 2)) {
            return 1;
        }
        if ((Y2 - Y1 == 1) && (X1 - X2 == 2)) {
            return 1;
        }
        break;
    case 'b':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if (checkD()) {
            return 1;
        }
        break;
    case 'k':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if ((Y1 - Y2 != 1) && (Y2 - Y1 != 1)
            && ((X1 - X2 != 1) && (X2 - X1 != 1))) {
            break;
        } else {
            return 1;
        }
    case 'q':
        if ((turn[2] == '-') && (board[Y2][X2] != ' ')) {
            printf("You need to capture.\n");
            break;
        }
        if (checkX() || checkY() || checkD()) {
            return 1;
        }
        break;
    }
    return 0;
}

void move()
{
    board[Y2][X2] = board[Y1][X1];
    board[Y1][X1] = ' ';
}

int checkY()
{
    int i, c1 = Y1, c2 = Y2;
    if (X1 != X2) {
        return 0;
    }
    if (Y1 > Y2) {
        c1 = Y2;
        c2 = Y1;
    }
    for (i = c1 + 1; i < c2; i++) {
        if ((board[i][X1] > 'a' && board[i][X1] < 's')
            || (board[i][X1] > 'A' && board[i][X1] < 'S')) {
            return 0;
        }
    }
    return 1;
}

int checkX()
{
    int i, c1 = X1, c2 = X2;
    if (Y1 != Y2) {
        return 0;
    }
    if (X1 > X2) {
        c1 = X2;
        c2 = X1;
    }
    for (i = c1 + 1; i < c2; i++) {
        if ((board[Y1][i] > 'a' && board[Y1][i] < 's')
            || (board[Y1][i] > 'A' && board[Y1][i] < 'S')) {
            return 0;
        }
    }
    return 1;
}

int checkD()
{
    int i, j, c1 = Y2, c2 = Y1, ci, cj;
    if (((Y2 - Y1) != (X2 - X1)) && ((Y2 - Y1) != (X1 - X2))) {
        return 0;
    }
    if (Y2 > Y1) {
        c1 = Y1;
        c2 = Y2;
        ci = 1;
    } else {
        ci = -1;
    }
    if (X2 > X1) {
        cj = 1;
    } else {
        cj = -1;
    }
    i = Y1 + ci;
    j = X1 + cj;
    while ((i < c2) && (i > c1)) {
        if (((board[i][j] > 'a') && (board[i][j] < 's'))
            || ((board[i][j] > 'A') && (board[i][j] < 'S'))) {
            return 0;
        }
        i += ci;
        j += cj;
    }
    return 1;
}

int checkWin(int status)
{
    int i, j, player = 0;
    if (status == 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 'k') {
                    player = 1;
                }
            }
        }
    }
    if (status == 2) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 'K') {
                    player = 2;
                }
            }
        }
    }

    if (player == 0) {
        return status;
    }

    return 0;
}
