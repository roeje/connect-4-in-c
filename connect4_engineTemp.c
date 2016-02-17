/* Created By Jesse Roe
 * Connect4 Game: Implementation of the classic Connect4 game in C
 *
 */
// #include <stdlib.h>
// #include <string.h>
// #include "connect4_engine.h"

/*Initialize the board state boardstate default is -1*/

int player = -1;
int column = 0;
int num_rows = 0;
int num_columns = 0;
int board[num_rows][num_columns];
int length_to_win = 0;

void setupVals(int num_rows, int num_columns, int board[num_rows][num_columns]) {


}

int checkFullBoard(int num_rows, int num_columns, int board[num_rows][num_columns]) {
	for (int i = 0; i < num_columns; i++) {
		if (board[num_rows][i] == -1) {
			return -1;
		}
	}
	return 1;
}

int checkForColHeight(int num_rows, int num_columns, int column, int board[num_rows][num_columns]) {
	for (int i = 0; i < num_rows; i++) {
		if (board[i][column] == -1) {
			return i;
		}			
	}
	return -1;
}

/*Return weather the token is validly placed*/
int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]) {
	int firstOpenRow = checkForColHeight(num_rows, num_columns, column, board);
	if (firstOpenRow == -1) { 
		return -1;
	}
	else {
		board[firstOpenRow][column] = player;
		return 1;
	}
}

int checkForSeries(int dir, int num_rows, int num_columns, int length_to_win, int r, int c, int board[num_rows][num_columns]) {
	
	if(dir = 0) {
		int i;
		int flag;
		for (i = 1; i < length_to_win - 1; i++) {
			if (board[r][c] != -1 ) {
				return -1;
			}
			if (board[r][c] != board[r][c + i] ) {
				return -1;
			}
		}
		return board[r][c];
	}else if (dir = 1) {
		int i;
		int flag;
		for (i = 1; i < length_to_win - 1; i++) {
			if (board[r][c] != -1 ) {
				return -1;
			}
			if (board[r][c] != board[r][c + i] ) {
				return -1;
			}
		}
		return board[r][c];		
	}
}

int checkHorizontal(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){
	int r, c;
	for (r = 0; r < num_rows; r++) {
		for(c = 0; c < num_columns - (length_to_win - 1); c++) {
			int winner = checkForSeries(0, num_rows, num_columns, length_to_win, r, c, board);
			if(winner == -1) {
				return 0;
			}
			else {
				winnerVal = winner;
				return 1;
			}
		}
	}
}

int checkVertical(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){

}

int checkDiagLeft(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){

}

int checkDiagRight(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){

}

/*Return the integer representation of the winning player, -1 if a tie*/
int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
	if (checkHorizontal(num_rows, num_columns, length_to_win, array))
}
