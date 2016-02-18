#include <stdio.h>

int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]);
int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int checkFullBoard(int num_rows, int num_columns, int board[num_rows][num_columns]);
int checkForHeight(int num_rows,  int num_columns, int column, int board[num_rows][num_columns]);
int checkHorizontal(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int checkVertical(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int checkDiagLeft(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int checkDiagRight(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int checkForSeries(int dir, int num_rows, int num_columns, int length_to_win, int r, int c, int board[num_rows][num_columns]);


