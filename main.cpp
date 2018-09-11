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
  int x, y;

  Board board;

  while(playing)
  {
  	board.printBoard();

  	GET_INPUT:
  	if(playerOneTurn)
  		std::cout << "Player 1 enter your choice(ex: a1): ";
  	else
  		std::cout << "Player 2 enter your choice(ex: a1): ";
  	std::cin.get(choice, 3);
  	std::cin.clear();
  	std::cin.ignore(100, '\n');


	x = ((int)choice[0] - 97);
  	y = ((int)choice[1] - 49);

  	if(!board.spaceOccupied(x, y))
  	{
  		board.updateBoard(x, y, turnP);
  	}
  	else
  	{
  		std::cout << "Space Occupied, please try again." << std::endl;
  		goto GET_INPUT;
  	}
  	board.printBoard();

  	break;
  }

  return 0;
}