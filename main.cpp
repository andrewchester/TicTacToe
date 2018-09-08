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
  cout << " 1 2 3 "<< endl;
  for(int x = 0; x < 3; x++)
  {
    cout << (char)(97 + x) << " ";
    for(int y = 0; y < 3; y++)
    {
      if(board[x][y].value == 0)
      {
        cout << " ";
      }
      else if(board[x][y].value == 1)
      {
        cout << "X";
      }
      else if(board[x][y].value = 2)
      {
        cout << "O";
      }
      cout << " ";
    }
    cout << endl;
  }
}
int main()
{
  cell board[3][3];

  for(int x = 0; x < 3; x++)
  {
    for(int y = 0; y < 3; y++)
    {
      board[x][y].xPos = x;
      board[x][y].yPos = y;
      board[x][y].value = 0;
    }
  }
  printBoard(board);
  
  return 0;
}
