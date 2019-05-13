#ifndef BOARD_H
#define BOARD_H
void turn_scan();
int chartoint(char turn[11]);
int white();
int black();
void move();
int checkY();
int checkX();
int checkD();
int checkWin(int status);

#endif
