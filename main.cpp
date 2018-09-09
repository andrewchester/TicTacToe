/*
 * Andrew Chester
 * TicTacToe
 * value, 0 = empty, 1 = x, 2 = 0
 */
#include <iostream>

#include "board.h"

using namespace std;

int main()
{
  //Variables and pointers for storing whose turn it is and whether they're playing
  bool playerOneTurn = true;
  bool* turnP = &playerOneTurn;
  bool playing = true;
  bool* playingP = &playing;

  Board board;

  board.iniBoard();
  board.printBoard();
  board.printValues();

  return 0;
}
