#include "../src/board.h"
#include "../src/board_print.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <string.h>

int status = 0, i, j;
int X1, X2, Y1, Y2;
char board[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char turn[11];

CTEST(inputdata, chartointer)
{
    strcpy(turn, "E2#E4"); // Wrong input
    int c1 = chartoint(turn);

    strcpy(turn, "E2xE4"); // Capture
    int c2 = chartoint(turn);

    strcpy(turn, "E2-E4"); // Turn
    int c3 = chartoint(turn);

    strcpy(turn, "E2-E9"); // Turn beyond limits
    int c4 = chartoint(turn);

    strcpy(turn, "hello!"); // Input not turn
    int c5 = chartoint(turn);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
}

CTEST(moving, movewhitepawn) // Test P
{
    strcpy(turn, "E2-E3"); // First turn on 1
    chartoint(turn);
    board[Y1][X1] = 'P';
    int c1 = white();

    strcpy(turn, "E2-E4"); // First turn on 2
    chartoint(turn);
    int c2 = white();

    board[Y1][X1] = ' ';

    strcpy(turn, "E3-E5"); // Not first turn on 2
    chartoint(turn);
    board[Y1][X1] = 'P';
    int c3 = white();

    strcpy(turn, "E3-F4"); // Diagonaly step
    chartoint(turn);
    int c4 = white();

    strcpy(turn, "E3-E2"); // Step back
    chartoint(turn);
    int c5 = white();

    strcpy(turn, "E3xF4"); // Catch
    chartoint(turn);
    board[Y2][X2] = 'p';
    int c6 = white();

    board[Y2][X2] = ' ';
    board[Y1][X1] = ' ';

    strcpy(turn, "E2-E4"); // First turn though figure 
    chartoint(turn);
    board[Y1][X1] = 'P';
    board[Y1 + 1][X1] = 'p';
    int c7 = white();

    board[Y1][X1] = ' ';
    board[Y1 + 1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moveblackpawn) // Test p
{
    strcpy(turn, "D7-D6"); // First turn on 1
    chartoint(turn);
    board[Y1][X1] = 'p';
    int c1 = black();

    strcpy(turn, "D7-D5"); // First turn on 2
    chartoint(turn);
    int c2 = black();

    board[Y1][X1] = ' ';

    strcpy(turn, "D6-D4"); // Not first turn on 2
    chartoint(turn);
    board[Y1][X1] = 'p';
    int c3 = black();

    strcpy(turn, "D6-C5"); // Diagonaly step
    chartoint(turn);
    int c4 = black();

    strcpy(turn, "D6-D7"); // Step back
    chartoint(turn);
    int c5 = black();

    strcpy(turn, "D6xC5"); // Catch
    chartoint(turn);
    board[Y2][X2] = 'P';
    int c6 = black();

    board[Y2][X2] = ' ';
    board[Y1][X1] = ' ';

    strcpy(turn, "D7-D5"); // First turn though figure 
    chartoint(turn);
    board[Y1][X1] = 'P';
    board[Y1 + 1][X1] = 'P';
    int c7 = black();

    board[Y1][X1] = ' ';
    board[Y1 + 1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moverook) // Test R
{
    strcpy(turn, "D4-D7"); // Step forward
    chartoint(turn);
    board[Y1][X1] = 'R';
    int c1 = white();

    strcpy(turn, "D4-D2"); // Step back
    chartoint(turn);
    int c2 = white();

    strcpy(turn, "D4-F4"); // Step right
    chartoint(turn);
    int c3 = white();

    strcpy(turn, "D4-B4"); // Step left
    chartoint(turn);
    int c4 = white();

    strcpy(turn, "D4-F6"); // Diagonaly step
    chartoint(turn);
    int c5 = white();

    strcpy(turn, "D4xD5"); // Catch
    chartoint(turn);
    board[Y2][X2] = 'r';
    int c6 = white();

    strcpy(turn, "D4-D6"); // Turn though figure 
    chartoint(turn);
    int c7 = white();

    board[Y1][X1] = ' ';
    board[Y2 - 1][X2] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moveknight) // Test N
{
    strcpy(turn, "D4-D7"); // Step forward
    chartoint(turn);
    board[Y1][X1] = 'N';
    int c1 = white();

    strcpy(turn, "D4-D2"); // Step back
    chartoint(turn);
    int c2 = white();

    strcpy(turn, "D4-F4"); // Step right
    chartoint(turn);
    int c3 = white();

    strcpy(turn, "D4-B4"); // Step left
    chartoint(turn);
    int c4 = white();

    strcpy(turn, "D4-F6"); // Diagonaly step
    chartoint(turn);
    int c5 = white();

    strcpy(turn, "D4-C6"); // Knight turn forward-left
    chartoint(turn);
    int c61 = white();

    strcpy(turn, "D4-E6"); // Knight turn forward-right
    chartoint(turn);
    int c62 = white();

    strcpy(turn, "D4-F5"); // Knight turn right-forward
    chartoint(turn);
    int c63 = white();

    strcpy(turn, "D4-F3"); // Knight turn right-back
    chartoint(turn);
    int c64 = white();

    strcpy(turn, "D4-E2"); // Knight turn back-right
    chartoint(turn);
    int c65 = white();

    strcpy(turn, "D4-C2"); // Knight turn back-left
    chartoint(turn);
    int c66 = white();

    strcpy(turn, "D4-B5"); // Knight turn left-forward
    chartoint(turn);
    int c67 = white();

    strcpy(turn, "D4-B3"); // Knight turn left-back
    chartoint(turn);
    int c68 = white();

    strcpy(turn, "D4xE6"); // Turn though figure 
    chartoint(turn);
    board[X1 + 1][Y1] = 'p';
    board[Y2][X2] = 'n';
    int c7 = white();

    board[Y1][X1] = ' ';
    board[X1 + 1][Y1] = ' ';
    board[Y2][X2] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp61 = 1;
    const int exp62 = 1;
    const int exp63 = 1;
    const int exp64 = 1;
    const int exp65 = 1;
    const int exp66 = 1;
    const int exp67 = 1;
    const int exp68 = 1;
    const int exp7 = 1;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp61, c61);
    ASSERT_EQUAL(exp62, c62);
    ASSERT_EQUAL(exp63, c63);
    ASSERT_EQUAL(exp64, c64);
    ASSERT_EQUAL(exp65, c65);
    ASSERT_EQUAL(exp66, c66);
    ASSERT_EQUAL(exp67, c67);
    ASSERT_EQUAL(exp68, c68);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, movebishop) // Test bishop
{
    strcpy(turn, "D4-D7"); // Forward
    chartoint(turn);
    board[Y1][X1] = 'B';
    int c1 = white();

    strcpy(turn, "D4-D2"); // Back
    chartoint(turn);
    int c2 = white();

    strcpy(turn, "D4-F4"); // Right
    chartoint(turn);
    int c3 = white();

    strcpy(turn, "D4-B4"); // Left
    chartoint(turn);
    int c4 = white();

    strcpy(turn, "D4-F6"); // D f-r
    chartoint(turn);
    int c51 = white();

    strcpy(turn, "D4-B6"); // D f-l
    chartoint(turn);
    int c52 = white();

    strcpy(turn, "D4-F2"); // D b-r
    chartoint(turn);
    int c53 = white();

    strcpy(turn, "D4xB2"); // D f-r catch
    chartoint(turn);
    board[Y2][X2] = 'p';
    int c54 = white();

    board[Y2][X2] = ' ';

    strcpy(turn, "D4-F6"); // D b-r through figure
    chartoint(turn);
    board[Y2 - 1][X2 - 1] = 'p';
    int c6 = white();

    board[Y1][X1] = ' ';
    board[Y2 - 1][X2 - 1] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp51 = 1;
    const int exp52 = 1;
    const int exp53 = 1;
    const int exp54 = 1;
    const int exp6 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp51, c51);
    ASSERT_EQUAL(exp52, c52);
    ASSERT_EQUAL(exp53, c53);
    ASSERT_EQUAL(exp54, c54);
    ASSERT_EQUAL(exp6, c6);
}

CTEST(moving, moveking) // Test king
{
    strcpy(turn, "D4-D5"); // F
    chartoint(turn);
    board[Y1][X1] = 'K';
    int c1 = white();

    strcpy(turn, "D4-D3"); // B
    chartoint(turn);
    int c2 = white();

    strcpy(turn, "D4-C4"); // L
    chartoint(turn);
    int c3 = white();

    strcpy(turn, "D4-E4"); // R
    chartoint(turn);
    int c4 = white();

    strcpy(turn, "D4-E5"); // F-r
    chartoint(turn);
    int c5 = white();

    strcpy(turn, "D4-C5"); // F-l
    chartoint(turn);
    int c6 = white();

    strcpy(turn, "D4-E3"); // B-r
    chartoint(turn);
    int c7 = white();

    strcpy(turn, "D4xC3"); // B-l catch
    chartoint(turn);
    board[Y2][X2] = 'p';
    int c8 = white();

    board[Y2][X2] = ' ';

    strcpy(turn, "D4-D6"); // F 2
    chartoint(turn);
    int c9 = white();

    strcpy(turn, "D4-F2"); // B 2
    chartoint(turn);
    int c10 = white();

    board[Y1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
}

CTEST(moving, movequeen) // Test Q
{
    strcpy(turn, "D4-D7"); // F
    chartoint(turn);
    board[Y1][X1] = 'Q';
    int c1 = white();

    strcpy(turn, "D4-D1"); // B
    chartoint(turn);
    int c2 = white();

    strcpy(turn, "D4-A4"); // L
    chartoint(turn);
    int c3 = white();

    strcpy(turn, "D4-G4"); // R
    chartoint(turn);
    int c4 = white();

    strcpy(turn, "D4-G7"); // D f-r
    chartoint(turn);
    int c5 = white();

    strcpy(turn, "D4-A7"); // D f-l
    chartoint(turn);
    int c6 = white();

    strcpy(turn, "D4-A1"); // D b-l
    chartoint(turn);
    int c7 = white();

    strcpy(turn, "D4xG1"); // D f-r catch
    chartoint(turn);
    board[Y2][X2] = 'p';
    int c8 = white();

    board[Y2][X2] = ' ';

    strcpy(turn, "D4-G7"); // D f-r throuh figure
    chartoint(turn);
    board[Y2 - 1][X2 - 1] = 'p';
    int c9 = white();

    board[Y2 - 1][X2 - 1] = ' ';

    strcpy(turn, "D4-F7"); // Knight turn d f-r
    chartoint(turn);
    int c10 = white();

    board[Y1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
}