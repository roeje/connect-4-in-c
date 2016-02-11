#include <stdio.h>
#include <math.h>
#include <objectarray.h>

int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]);
int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int checkFullBoard(int num_rows, int num_columns, int board[num_rows][num_columns]);
int checkForHeight(int num_rows,  int num_columns, int column, board[num_rows][num_columns]);
int checkHorizontal(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int checkVertical(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int checkDiagLeft(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int checkDiagRight(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);



