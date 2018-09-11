#include <iostream>

#include "board.h"

using namespace std;

int main()
{
  bool playerOneTurn = true;
  bool* turnP = &playerOneTurn;
  bool playing = true;
  bool* playingP = &playing;

  char choice[3];
  char* choiceP = &choice;

  Board board;
  board.printBoard();

  while(playing)
  {
  	
  }

  return 0;
}