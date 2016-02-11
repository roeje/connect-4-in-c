#include <stdio.h>
#include "connect4_engine.c"

void ct_initialize(int num_rows, int num_cols, int array[num_rows][num_cols]) {
  int r, c;
  for (r = 0; r < num_rows; r++) {
    for (c = 0; c < num_cols; c++) {
      array[r][c] = -1;
    }
  }
};

void printBoard(int num_rows, int num_columns, int board[num_rows][num_columns]){
   int row, col;

   //system("clear");
   puts("\n    ******Connect Four******\n");
   puts("    0   1    2    3    4    5    6\n");
   puts("------------------------------------");
   for(row = num_rows - 1; row >= 0; row--){
      for(col = 0; col < num_columns; col++){
      	if(board[row][col] == 0) {
      		printf("|  %d ", board[row][col]);
      	}
      	else {
      		printf("| %d ", board[row][col]);
      	}        
      }
      puts("|");
      puts("------------------------------------");
   }

}

int main () {

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[0][0] = 0;
  array[0][1] = 0;
  array[0][2] = 0; 
  array[0][3] = 0;

  printBoard(num_rows, num_columns, array);
 
  // answer = winner(num_rows, num_columns, 4, array);

  answer = place_token(1, 1, num_rows, num_columns, array);
  printf("%d", answer);

}