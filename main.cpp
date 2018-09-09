/*
 * Andrew Chester
 * TicTacToe
 * value: 0 = empty, 1 = X, 2 = O
 */
#include <iostream>

struct Cell
{
  int x, y, value;
};

void printBoard(Cell* board[3][3])
{
  std::cout << "  1 2 3 " << std::endl;
  for(int x = 0; x < 3; x++)
  {
    std::cout << (97 + x);
    for(int y = 0; y < 3; y++)
    {
      if((*board[x][y]).value == 0)
      {
        std::cout << " ";
      }
      else if((*board[x][y]).value == 1)
      {
        std::cout << "X";
      }
      else if((*board[x][y]).value  == 2)
      {
        std::cout << "O";
      }
    }
    std::cout << std::endl;
  }
}

int main()
{
  Cell board[3][3];
  Cell* boardP[3][3];
  
  for(int x = 0; x < 3; x++)
  {
    for(int y = 0; y < 3; y++)
    {
      board[x][y].x = x;
      board[x][y].y = y;
      board[x][y].value = 0;
      boardP[x][y] = &board[x][y];
    }
  }

  //Variables and pointers for storing whose turn it is and whether they're playing
  bool playerOneTurn = true;
  bool* turnP = &playerOneTurn;
  bool playing = true;
  bool* playingP = &playing;

  printBoard(boardP);

  return 0;
}
