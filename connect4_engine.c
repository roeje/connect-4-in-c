/* Created By Jesse Roe
 * Connect4 Game: Implementation of the classic Connect4 game in C
 *
 */
// #include <stdlib.h>
// #include <string.h>
// #include "connect4_engine.h"

/*Initialize the board state boardstate default is -1*/

int checkFullBoard(int num_rows, int num_columns, int board[num_rows][num_columns]) {
	
}

int checkForHeight(int num_rows, int num_columns, int column, int board[num_rows][num_columns]) {
	for (int i = 0; i < num_rows; i++) {
		if (board[i][column] == -1) {
			return i;
		}		
	}
}

/*Return weather the token is validly placed*/
int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]) {
	int colHeight = checkForHeight(num_rows, num_columns, column, board);
	return colHeight;
	
}

int checkHorizontal(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){
	
}

int checkVertical(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){

}

int checkDiagLeft(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){

}

int checkDiagRight(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){

}

/*Return the integer representation of the winning player, -1 if a tie*/
int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {

}
