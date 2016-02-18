#include <stdio.h>
#include "connect4_engine.h"
#include "CuTest.h"

#define EMPTY -1
#define NO_WINNER_YET -1

void ct_initialize(int num_rows, int num_cols, int array[num_rows][num_cols]) {
  int r, c;
  for (r = 0; r < num_rows; r++) {
    for (c = 0; c < num_cols; c++) {
      array[r][c] = EMPTY;
    }
  }
}

/*******************************************************************************************
 *
 * Test winner function
 *
 * Note: This is just a sample of how you can test your own winner
 * function.  You may need to modify this code depending on how your
 * organized your array.  I will not be testing your winner function
 * directly.
 *
 * Note:  Be sure to add tests for different directions, quadrants, and board sizes.
 *
 ******************************************************************************************/
void winner_horizontal_r0(CuTest *tc) {

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[0][0] = 0;
  array[0][1] = 0;
  array[0][2] = 0;
  array[0][3] = 0;

  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "0s in bottom row", 0, answer);
}

/*
* Custom Winner Tests
*
*
*
*
*/
/*Testing Horizontal*/
void winner_horizontalTop(CuTest *tc) {

  int num_rows = 6;
  int num_columns = 6;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][0] = 0;
  array[num_rows - 1][1] = 0;
  array[num_rows - 1][2] = 0;
  array[num_rows - 1][3] = 0;
  array[num_rows - 1][4] = 0;

  answer = winner(num_rows, num_columns, 5, array);
  CuAssertIntEquals_Msg(tc, "0s in top row", 0, answer);
}

void winner_horizontalTopFull(CuTest *tc) {

  int num_rows = 5;
  int num_columns = 5;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][0] = 1;
  array[num_rows - 1][1] = 1;
  array[num_rows - 1][2] = 1;
  array[num_rows - 1][3] = 1;
  array[num_rows - 1][4] = 1;

  answer = winner(num_rows, num_columns, 5, array);
  CuAssertIntEquals_Msg(tc, "1s in top row", 1, answer);
}

void winner_horizontalTopFail(CuTest *tc) {

  int num_rows = 5;
  int num_columns = 5;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][0] = 1;
  array[num_rows - 1][1] = 1;
  array[num_rows - 1][2] = 1;
  array[num_rows - 1][3] = 1;  

  answer = winner(num_rows, num_columns, 5, array);
  CuAssertIntEquals_Msg(tc, "1s in top row fail", -1, answer);
}

void winner_horizontalBottomTestOverload(CuTest *tc) {

  int num_rows = 5;
  int num_columns = 5;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][0] = 1;
  array[num_rows - 1][1] = 1;
  array[num_rows - 1][2] = 1;
  array[num_rows - 1][3] = 1;  

  answer = winner(num_rows, num_columns, 2, array);
  CuAssertIntEquals_Msg(tc, "1s bottom overload", 1, answer);
}

void winner_horizontalSingleToken(CuTest *tc) {

  int num_rows = 5;
  int num_columns = 5;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[2][3] = 1;  

  answer = winner(num_rows, num_columns, 1, array);
  CuAssertIntEquals_Msg(tc, "1 in center", 1, answer);
}

void winner_horizontalDoubleTokenBottomRight(CuTest *tc) {

  int num_rows = 20;
  int num_columns = 20;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[0][num_columns - 1] = 0;
  array[0][num_columns - 2] = 0;  

  answer = winner(num_rows, num_columns, 2, array);
  CuAssertIntEquals_Msg(tc, "1 in center", 0, answer);
}

void winner_horizontalSingleTokenBottomRight(CuTest *tc) {

  int num_rows = 5;
  int num_columns = 5;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[0][num_columns - 1] = 0;  

  answer = winner(num_rows, num_columns, 1, array);
  CuAssertIntEquals_Msg(tc, "1 in center", 0, answer);
}

/*Testing Vertical*/
void winner_verticalEdgeRight(CuTest *tc) {

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  /*Set winning condition for player 1: vertical far left col, 5 tokens to win*/
  array[2][num_columns - 1] = 1;
  array[3][num_columns - 1] = 1;
  array[4][num_columns - 1] = 1;
  array[5][num_columns - 1] = 1; 
  array[6][num_columns - 1] = 1;  

  answer = winner(num_rows, num_columns, 5, array);
  CuAssertIntEquals_Msg(tc, "1's Right Edge Vertical", 1, answer);
}

void winner_verticalEdgeLeft(CuTest *tc) {

  int num_rows = 9;
  int num_columns = 9;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  /*Set winning condition for player 1: vertical far left col, 5 tokens to win*/  
  array[1][0] = 0;
  array[2][0] = 0;
  array[3][0] = 0;
  array[4][0] = 0;
  array[5][0] = 0; 
  array[6][0] = 0;  

  answer = winner(num_rows, num_columns, 6, array);
  CuAssertIntEquals_Msg(tc, "0's Left Edge Vertical", 0, answer);
}

void winner_verticalEdgeLeftFullHeight(CuTest *tc) {

  int num_rows = 6;
  int num_columns = 6;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);  
  
  array[0][0] = 0;  
  array[1][0] = 0;
  array[2][0] = 0;
  array[3][0] = 0;
  array[4][0] = 0;
  array[5][0] = 0; 

  answer = winner(num_rows, num_columns, 6, array);
  CuAssertIntEquals_Msg(tc, "0's Left Edge Vertical Full Height", 0, answer);
}

void winner_verticalEdgeRightFullHeight(CuTest *tc) {

  int num_rows = 6;
  int num_columns = 6;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);  
  
  array[0][num_columns - 1] = 0;  
  array[1][num_columns - 1] = 0;
  array[2][num_columns - 1] = 0;
  array[3][num_columns - 1] = 0;
  array[4][num_columns - 1] = 0;
  array[5][num_columns - 1] = 0; 

  answer = winner(num_rows, num_columns, 6, array);
  CuAssertIntEquals_Msg(tc, "0's Left Edge Vertical Full Height", 0, answer);
}

void winner_verticallSingleToken(CuTest *tc) {

  int num_rows = 4;
  int num_columns = 4;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[2][3] = 1;  

  answer = winner(num_rows, num_columns, 1, array);
  CuAssertIntEquals_Msg(tc, "1 in center", 1, answer);
}

void winner_verticallSingleTokenTopRight(CuTest *tc) {

  int num_rows = 4;
  int num_columns = 4;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][num_columns - 1] = 1;  

  answer = winner(num_rows, num_columns, 1, array);
  CuAssertIntEquals_Msg(tc, "1 in top right", 1, answer);
}

/*Testing Diagonal Left*/
void winner_diagLeftTopLeft4(CuTest *tc) {
  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][0] = 1;
  array[num_rows - 2][1] = 1;
  array[num_rows - 3][2] = 1; 
  array[num_rows - 4][3] = 1;   

  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "1 on left diag top", 1, answer);
}

void winner_diagLeftTopLeft2(CuTest *tc) {
  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][0] = 0;
  array[num_rows - 2][1] = 0;  

  answer = winner(num_rows, num_columns, 2, array);
  CuAssertIntEquals_Msg(tc, "1 in top left len 2", 0, answer);
}

/*Just to check the base case of 1. I know this is not a valid length*/
void winner_diagLeftTopLeft1(CuTest *tc) {
  int num_rows = 3;
  int num_columns = 3;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][0] = 0;  

  answer = winner(num_rows, num_columns, 1, array);
  CuAssertIntEquals_Msg(tc, "1 in top left len 1", 0, answer);
}

void winner_diagLeftFull(CuTest *tc) {
  int num_rows = 3;
  int num_columns = 3;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][0] = 1;
  array[num_rows - 2][1] = 1;
  array[num_rows - 3][2] = 1;   

  answer = winner(num_rows, num_columns, 3, array);
  CuAssertIntEquals_Msg(tc, "1 full board len 3", 1, answer);
}

void winner_diagLeftCenter(CuTest *tc) {
  int num_rows = 10;
  int num_columns = 10;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[num_rows - 1][2] = 1;
  array[num_rows - 2][3] = 1;
  array[num_rows - 3][4] = 1;
  array[num_rows - 4][5] = 1; 
  array[num_rows - 5][6] = 1; 
  array[num_rows - 6][7] = 1;

  answer = winner(num_rows, num_columns, 6, array);
  CuAssertIntEquals_Msg(tc, "1 in middle len 6", 1, answer);
}

void winner_diagLeftEdgeRight(CuTest *tc) {
  int num_rows = 6;
  int num_columns = 6;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[3][2] = 1;
  array[2][3] = 1; 
  array[1][4] = 1; 
  array[0][5] = 1; 

  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "1 in bottom right len 4", 1, answer);
}

void winner_diagLeftBottom1(CuTest *tc) {
  int num_rows = 6;
  int num_columns = 6;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[0][5] = 1; 

  answer = winner(num_rows, num_columns, 1, array);
  CuAssertIntEquals_Msg(tc, "1 in bottom right len 1", 1, answer);
}

/*Testing Right Diagional*/
void winner_diagRightTopLeft5(CuTest *tc) {
  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[2][2] = 0;
  array[3][3] = 0;
  array[4][4] = 0; 
  array[5][5] = 0; 
  array[6][6] = 0;   

  answer = winner(num_rows, num_columns, 5, array);
  CuAssertIntEquals_Msg(tc, "1 on right diag top", 0, answer);
}

void winner_diagRightTopLeft2(CuTest *tc) {
  int num_rows = 4;
  int num_columns = 4;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);
  
  array[2][2] = 0; 
  array[3][3] = 0;   

  answer = winner(num_rows, num_columns, 2, array);
  CuAssertIntEquals_Msg(tc, "1 on right diag top len 2", 0, answer);
}

void winner_diagRightTopLeft1(CuTest *tc) {
  int num_rows = 4;
  int num_columns = 4;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);  
 
  array[3][3] = 0;   

  answer = winner(num_rows, num_columns, 1, array);
  CuAssertIntEquals_Msg(tc, "1 on right diag top len 1", 0, answer);
}

void winner_diagRightFull(CuTest *tc) {
  int num_rows = 4;
  int num_columns = 4;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);  
  
  array[0][0] = 0; 
  array[1][1] = 0;   
  array[2][2] = 0; 
  array[3][3] = 0;   

  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "1 on right diag top len 1", 0, answer);
}

/*
* End Custom Winner Tests
*/

/*******************************************************************************************
 *
 * Test place_token function
 *
 * Note: This is just a sample of how you can test your own
 * place_token function.  You may need to modify this code depending
 * on how your organized your array.  I will not be testing your
 * place_token function directly.
 *
 * Note:  Be sure to add tests for different directions, quadrants, and board sizes.
 *
 ******************************************************************************************/

void place_token_c1(CuTest *tc) {

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  ct_initialize(num_rows, num_columns, array);

  place_token(1, 3, num_rows, num_columns, array);

  // make sure there is a 1 at the bottom of column 3 and a -1 everywhere else
  /*EDIT: I modifed this test to account for the way I have structured my array.
    In my program, row 0 is considered the bottom of the board and thus all insertions are

  */
  CuAssertIntEquals_Msg(tc, "Drop 1 into empty column 3", 1, array[0][3]);
  int r, c;
  for (r = 0; r < num_rows; r++) {
    for (c = 0; c < num_columns; c++) {
      if (r != (0) || c != 3) {
	     CuAssertIntEquals_Msg(tc, "Should be empty", EMPTY, array[r][c]);
      }
    }
  }
}


/*******************************************************************************************
 *
 * Test overall game play
 *
 * These tests below demonstrate how I will be testing your game.
 * These tests below should run wihtout modification.  If they don't
 * then something in your design conflicts with the tests and we need
 * to figure out what it is.  Make sure you find any such conflicts
 * and work with me to resole them well before the assignment due
 * date.
 *
 * Because they test the interaction between several methods, these
 * tests below are not technically "unit" tests.  If your tests for
 * your connect4_engine functions are thorough, you need not add many
 * tests to this section.
 *
 ******************************************************************************************/

void horizontal_row0(CuTest* tc) 
{
  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  place_token(0, 0, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Single 0 in column 0", NO_WINNER_YET, answer);

  place_token(0, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "0s in columns {0,1}", NO_WINNER_YET, answer);


  place_token(0, 2, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "0s in columns {0,1, 2}", NO_WINNER_YET, answer);


  place_token(0, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "4 in a row, horizontal", 0, answer);
}


void vertical_column1(CuTest* tc) 
{
  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  place_token(0, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Single 0 in column 1", NO_WINNER_YET, answer);

  place_token(0, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Two 0s in column 1", NO_WINNER_YET, answer);


  place_token(0, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Three 0s in column 1", NO_WINNER_YET, answer);


  place_token(0, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "4 in a row, vertical", 0, answer);
}

void forward_diagonal(CuTest* tc) 
{
 /*
    . . . . . . .
    . . . . . . .
    . . . . . . .
    . . . 0 . . .
    . . . 1 0 . .
    . . . 0 0 0 .
    1 . . 1 1 1 0
  */ 

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  /* column 6*/
  place_token(0, 6, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 1", NO_WINNER_YET, answer);

  /* column 5*/
  place_token(1, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 2", NO_WINNER_YET, answer);

  place_token(0, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 3", NO_WINNER_YET, answer);


  /* column 4*/
  place_token(1, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 4", NO_WINNER_YET, answer);

  place_token(0, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 5", NO_WINNER_YET, answer);

  place_token(1, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 6", NO_WINNER_YET, answer);

  place_token(0, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 7", NO_WINNER_YET, answer);

 /* column 3 */
  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 8", NO_WINNER_YET, answer);

  place_token(0, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 9", NO_WINNER_YET, answer);

  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 10", NO_WINNER_YET, answer);

  place_token(0, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 11 -- Winner!", 0, answer);
}


void backward_diagonal(CuTest* tc) 
{
 /*
    . . . . . . .
    . . . . . . .
    . . . . . . .
    . . . 0 . . .
    . . 0 1 . . .
    . 0 0 0 . . .
    0 1 1 1 . 1 .
  */ 

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  /* column 0*/
  place_token(0, 0, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 1", NO_WINNER_YET, answer);

  /* column 1*/
  place_token(1, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 2", NO_WINNER_YET, answer);

  place_token(0, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 3", NO_WINNER_YET, answer);


  /* column 2*/
  place_token(1, 2, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 4", NO_WINNER_YET, answer);

  place_token(0, 2, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 5", NO_WINNER_YET, answer);

  place_token(1, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 6", NO_WINNER_YET, answer);

  place_token(0, 2, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 7", NO_WINNER_YET, answer);

 /* column 3 */
  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 8", NO_WINNER_YET, answer);

  place_token(0, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 9", NO_WINNER_YET, answer);

  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 10", NO_WINNER_YET, answer);

  place_token(0, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 11 -- Winner!", 0, answer);
}



/* setup */

CuSuite* c4_engine_suite() {
   CuSuite* suite = CuSuiteNew();

   SUITE_ADD_TEST(suite, winner_horizontal_r0);
   SUITE_ADD_TEST(suite, winner_horizontalTop);
   SUITE_ADD_TEST(suite, winner_horizontalTopFull);
   SUITE_ADD_TEST(suite, winner_horizontalTopFail);
   SUITE_ADD_TEST(suite, winner_horizontalBottomTestOverload);
   SUITE_ADD_TEST(suite, winner_horizontalSingleToken);
   SUITE_ADD_TEST(suite, winner_horizontalSingleTokenBottomRight);
   SUITE_ADD_TEST(suite, winner_horizontalDoubleTokenBottomRight);
   SUITE_ADD_TEST(suite, winner_verticalEdgeRight);
   SUITE_ADD_TEST(suite, winner_verticalEdgeLeft);
   SUITE_ADD_TEST(suite, winner_verticalEdgeLeftFullHeight);
   SUITE_ADD_TEST(suite, winner_verticalEdgeRightFullHeight);
   SUITE_ADD_TEST(suite, winner_verticallSingleToken);
   SUITE_ADD_TEST(suite, winner_verticallSingleTokenTopRight);
   SUITE_ADD_TEST(suite, winner_diagLeftTopLeft4);
   SUITE_ADD_TEST(suite, winner_diagLeftTopLeft2);
   SUITE_ADD_TEST(suite, winner_diagLeftTopLeft1);
   SUITE_ADD_TEST(suite, winner_diagLeftFull);
   SUITE_ADD_TEST(suite, winner_diagLeftCenter);
   SUITE_ADD_TEST(suite, winner_diagLeftEdgeRight);
   SUITE_ADD_TEST(suite, winner_diagLeftBottom1);
   SUITE_ADD_TEST(suite, winner_diagRightTopLeft5);
   SUITE_ADD_TEST(suite, winner_diagRightTopLeft2);
   SUITE_ADD_TEST(suite, winner_diagRightTopLeft1);
   SUITE_ADD_TEST(suite, winner_diagRightFull);

   SUITE_ADD_TEST(suite, place_token_c1);

   SUITE_ADD_TEST(suite, horizontal_row0);
   SUITE_ADD_TEST(suite, vertical_column1);
   SUITE_ADD_TEST(suite, forward_diagonal);
   SUITE_ADD_TEST(suite, backward_diagonal);
   return suite;
}


void RunC4Tests(void) {
   CuString *output = CuStringNew();
   CuSuite* suite = CuSuiteNew();

   CuSuiteAddSuite(suite, c4_engine_suite());
   CuSuiteRun(suite);
   CuSuiteSummary(suite, output);
   CuSuiteDetails(suite, output);
   printf("%s\n", output->buffer);
}

int main(void) {
   RunC4Tests();
   return 0;
}
