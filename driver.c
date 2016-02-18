#include <stdio.h>
#include <stdlib.h>
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
   puts("\n    ****** Connect Four ******\n");
   // puts("    0   1    2    3    4    5    6\n");
   puts("--------------------------------------------------------------");
   for(row = num_rows - 1; row >= 0; row--){
      for(col = 0; col < num_columns; col++){
      	if(board[row][col] == 0 || board[row][col] == 1) {
      		printf("|  %d ", board[row][col]);
      	}
      	else {
      		printf("| %d ", board[row][col]);
      	}        
      }
      puts("|");
      puts("--------------------------------------------------------------");
   }
}

void winner_horizontal() {
  puts("\n");
  printf("%s\n", "*********************");
  printf("%s\n", "Testing Horizontal");
  printf("%s\n", "*********************");
  puts("\n");

  int num_rows = 5;
  int num_columns = 5;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][0] = 0;
  array[num_rows - 1][1] = 0;
  array[num_rows - 1][2] = 0;
  array[num_rows - 1][3] = 0;
  array[num_rows - 1][4] = 0;    

  answer = winner(num_rows, num_columns, 5, array);
  printf("%d\n", answer);
  printBoard(num_rows, num_columns, array);
  puts("\n");
}

void winner_vertical() {
  puts("\n");
  printf("%s\n", "*********************");
  printf("%s\n", "Testing Vertical");
  printf("%s\n", "*********************");
  puts("\n");

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);  

  array[3][6] = 1;
  array[4][6] = 1;
  array[5][6] = 1; 
  array[6][6] = 1;

  answer = winner(num_rows, num_columns, 4, array);
  printf("%d\n", answer);
  printBoard(num_rows, num_columns, array);
  puts("\n");
}

void winner_diagleft() {
  puts("\n");
  printf("%s\n", "*********************");
  printf("%s\n", "Testing Left Diag");
  printf("%s\n", "*********************");
  puts("\n");

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);
  
  array[0][3] = 1;
  array[1][2] = 1;
  array[2][1] = 1; 
  array[3][0] = 1;   

  answer = winner(num_rows, num_columns, 4, array);
  printf("%d\n", answer);
  printBoard(num_rows, num_columns, array);
  puts("\n");
}

void winner_diagright() {
  puts("\n");
  printf("%s\n", "*********************");
  printf("%s\n", "Testing Right Diag");
  printf("%s\n", "*********************");
  puts("\n");

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  // array[0][0] = 0;
  // array[1][0] = 0;
  // array[2][0] = 0; 
  // array[3][0] = 0;

  array[0][3] = 0;
  array[1][4] = 0;
  array[2][5] = 0; 
  array[3][6] = 0;  

  answer = winner(num_rows, num_columns, 4, array);
  printf("%d\n", answer);
  printBoard(num_rows, num_columns, array);
  puts("\n");
}

void testPutToken() {
  puts("\n");
  printf("%s\n", "*********************");
  printf("%s\n", "Testing Insert Token");
  printf("%s\n", "*********************");
  puts("\n");

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
  answer = place_token(1, 3, num_rows, num_columns, array);
  printf("%d", answer);
  printBoard(num_rows, num_columns, array);
}

int main (int argc, char *argv[]) { 
  setvbuf(stdout, NULL, _IONBF, 0);
  printf("Starting Game\n");
  // testPutToken();
  // winner_horizontal();
  // winner_vertical();
  // winner_diagleft();
  // winner_diagright();

  int num_rows = 0;
  int num_columns = 0;
  int length_to_win = 0;
  if(argc > 4) {
    printf("You Entered Too Many Parameters. Please Run Again.");
    puts("\n");
    return 0;
  }
  if(argc < 4) {
    printf("You Entered Too Few Parameters. Please Run Again.");
    puts("\n");
    return 0;
  }
  num_rows = atoi(argv[1]);
  num_columns = atoi(argv[2]);
  length_to_win = atoi(argv[3]);
  if (num_rows <= 0 || num_columns <= 0 ){
    printf("%s\n","You entered a width or length that was invalid." );
  }
  if (length_to_win <= 0 || length_to_win > (num_rows - 1)) {
    printf("%s\n","You entered a winning length that was invalid." );
  }
  int array[num_rows][num_columns];
  ct_initialize(num_rows, num_columns, array);
  int answer;
  int player = 0;
  puts("\n****** Connect Four: By Jesse Roe ******   \n");
  printf("%s\n", "*********************");
  printf("%s\n", "   Starting Board   ");
  printf("%s\n", "*********************");
  puts("\n");
  printBoard(num_rows, num_columns, array);
  puts("\n");
  printf("Player: %ds Turn\n", player);  
  
  while(1) {       
    printf("%s\n", "Enter Column # To Place Token"); 
    int column;
    char temp[20];       
    scanf("%s", temp); 
    column = atoi(temp);  
   
    if (column <= 0 || column > (num_columns - 1)) {
      printf("%s\n","You entered a column that was invalid." );
      continue;
    }

    int attmpt = place_token(player, column, num_rows, num_columns, array);
    if (attmpt != 1) {
      printf("%s\n","This row is already full. Please try again." );
      continue;
    }
    
    printf("%s\n", "************************");
    printf("%s\n", "      Board Updated     ");
    printf("%s\n", "************************");    
    printBoard(num_rows, num_columns, array);
    puts("\n");

    if (checkFullBoard(num_rows, num_columns, array)) {
      printf("%s\n","This game is a tie. Thanks for Playing.");
      return 0;
    }
    int isWin = winner(num_rows, num_columns, length_to_win, array);
    if(isWin != -1) {
      printf("Player: %d has Won! Thanks for Playing.", isWin);
      return 0;
    }

    if (player == 1) {
      player = 0;
    }
    else {
      player = 1;
    }
    printf("Player: %ds Turn\n\n", player);
  }
  return 0;
}