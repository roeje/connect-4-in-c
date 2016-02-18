/* Created By Jesse Roe
 * Connect4 Game: Implementation of the classic Connect4 game in C
 *
 */
#include "connect4_engine.h"

/*Global var to hold the current winner value*/
int winnerVal = 0;


int checkFullBoard(int num_rows, int num_columns, int board[num_rows][num_columns]) {
	for (int i = 0; i < num_columns; i++) {
		if (board[num_rows - 1][i] == -1) {
			return 0;
		}
	}
	return 1;
}

/* Checks for the first avalible cell to insert token in given column
   NOTE: This fuction is designed based on row 0 being the bottom (lowest row of the board)
   This means that tokens are inserted from row 0 upward. Based on your tests, this should not cause
   any problems.
*/
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
	
	/*Check for invalid Parameters*/
	if(column > (num_columns - 1) || column < 0 || player > 1 || player < 0 
		|| num_columns <= 0 || num_rows <= 0) {
		return -1;
	}	

	int firstOpenRow = checkForColHeight(num_rows, num_columns, column, board);
	if (firstOpenRow == -1) { 
		return -1;
	}else {
		board[firstOpenRow][column] = player;
		return 1;
	}
}

/*Case for each type of direction */
/*
  It seemed slighlty cleaner to use this switch instead of creating a 
  unique function for each case (due to the large number of parameters).
*/
int checkForSeries(int dir, int num_rows, int num_columns, int length_to_win, int r, int c, int board[num_rows][num_columns]) {
	switch (dir) {
		/*Horizontal*/
		case 0: 					
			for (int i = 1; i < length_to_win; i++) {
				if (board[r][c] == -1 ) {
					return -1;
				}else if (board[r][c] != board[r][c + i] ) {
					return -1;
				}
			}
			return board[r][c];
			break;			
		/*Vertical*/
		case 1: 
			for (int i = 1; i < length_to_win; i++) {
				if (board[r][c] == -1 ) {
					return -1;
				}else if (board[r][c] != board[r + i][c] ) {
					return -1;
				}
			}
			return board[r][c];			
			break;
		/*Left Diag*/
		case 2:
			for (int i = 1; i < length_to_win; i++) {
				if (board[r][c] == -1 ) {
					return -1;
				}else if (board[r][c] != board[r + i][c - i] ) {
					return -1;
				}
			}
			return board[r][c];	
			break;
		/*Right Diag*/
		case 3:
			for (int i = 1; i < length_to_win; i++) {
				if (board[r][c] == -1 ) {
					return -1;
				}else if (board[r][c] != board[r + i][c + i] ) {
					return -1;
				}
			}
			return board[r][c];	
			break;		
		return -1;
	}
}

/*Interate over each row and column. for each cell in the row, check for series of tokens*/
int checkHorizontal(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){
	// printf("%s\n", "Check Horizontal: ");
	int r, c;
	for (r = 0; r < num_rows; r++) {
		// printf("%s", "Row #: ");
		// printf("%d\n", r);
		for(c = 0; c < num_columns - (length_to_win - 1); c++) {
			// printf("%s", "Col #: ");
			// printf("%d\n", c);
			int winner = checkForSeries(0, num_rows, num_columns, length_to_win, r, c, board);
			if(winner != -1) {
				winnerVal = winner;
				// printf("%s", "Row Location: ");
				// printf("%d\n", r);
				// printf("%s", "Col Location: ");
				// printf("%d\n", c);
				return 1;
			}			
		}
	}
	return 0;
}

/*Interate over each row and column. for each cell in the row, check for series of tokens*/
int checkVertical(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){
	// printf("%s\n", "Check Vertical: ");
	int r, c;
	for (c = 0; c < num_columns; c++) {
		// printf("%s", "Row #: ");
		// printf("%d\n", r);
		for(r = 0; r < num_rows - (length_to_win - 1); r++) {
			// printf("%s", "Col #: ");
			// printf("%d\n", c);
			int winner = checkForSeries(1, num_rows, num_columns, length_to_win, r, c, board);
			if(winner != -1) {
				winnerVal = winner;
				// printf("%s", "Row Location: ");
				// printf("%d\n", r);
				// printf("%s", "Col Location: ");
				// printf("%d\n", c);
				return 1;
			}			
		}
	}
	return 0;
}

/*Interate over each row and column. for each cell in the row, check for series of tokens*/
int checkDiagLeft(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){
	// printf("%s\n", "Check Left Diag: ");
	int r, c;
	for (r = 0; r < num_rows - (length_to_win - 1); r++) {
		// printf("%s", "Row #: ");
		// printf("%d\n", r);
		for(c = num_columns - 1; c > (length_to_win - 2); c--) {
			// printf("%s", "Col #: ");
			// printf("%d\n", c);
			int winner = checkForSeries(2, num_rows, num_columns, length_to_win, r, c, board);
			if(winner != -1) {
				winnerVal = winner;
				// printf("%s", "Row Location: ");
				// printf("%d\n", r);
				// printf("%s", "Col Location: ");
				// printf("%d\n", c);
				return 1;
			}			
		}
	}
	return 0;
}

/*Interate over each row and column. for each cell in the row, check for series of tokens*/
int checkDiagRight(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){
	// printf("%s\n", "Check Right Diag: ");
	int r, c;
	for (r = 0; r < num_rows - (length_to_win - 1); r++) {
		// printf("%s", "Row #: ");
		// printf("%d\n", r);
		for(c = 0; c < num_columns - (length_to_win - 1); c++) {
			// printf("%s", "Col #: ");
			// printf("%d\n", c);
			int winner = checkForSeries(3, num_rows, num_columns, length_to_win, r, c, board);
			if(winner != -1) {
				winnerVal = winner;
				// printf("%s", "Row Location: ");
				// printf("%d\n", r);
				// printf("%s", "Col Location: ");
				// printf("%d\n", c);
				return 1;
			}			
		}
	}
	return 0;
}

/*Return the integer representation of the winning player, -1 if a tie or error*/
int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
	
	/*Check for invalid Parameters*/
	if (length_to_win <= 0 || length_to_win > num_columns || num_columns <= 0 || num_rows <= 0)	{
		return -1;
	}	
	if (checkHorizontal(num_rows, num_columns, length_to_win, array) 
		|| checkVertical(num_rows, num_columns, length_to_win, array)
		|| checkDiagLeft(num_rows, num_columns, length_to_win, array)
		|| checkDiagRight(num_rows, num_columns, length_to_win, array)
		) {
		return winnerVal;	
	}
	if(checkFullBoard(num_rows, num_columns, array)) {
		return -1;
	}
	return -1;
}
