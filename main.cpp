/*
 * Andrew Chester
 * TicTacToe
 * value, 0 = empty, 1 = x, 2 = 0
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct cell
{
  int xPos;
  int yPos;
  int value;
};

void printBoard(cell board[3][3])
{
  for(int i = 0; i < 3; i++)
  {
    char rowString[3];
    for(int j = 0; j < 3; j++)
    {
      strcat(rowString, iota(board[j][i].value));
      strcat(rowString, " ");
    }
  }
}
int main()
{
  cell board[3][3];

  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      board[j][i].xPos = j;
      board[j][i].yPos = i;
      board[j][i].value = 0;
    }
  }
  
  return 0;
}
