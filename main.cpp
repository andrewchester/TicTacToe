#include <iostream>

#include "board.h"

using namespace std;

int main()
{
  bool playerOneTurn = true;
  bool* turnP = &playerOneTurn;
  bool playing = true;
  bool* playingP = &playing;
  bool playerWon = true;
  bool* playerWonP = &playerWon;

  char choice[3];
  char playAgain;
  int x, y;

  Board board;

  GAME_START:
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
  		if(board.testWin(playerWonP, turnP))
  			break;

  		if(playerOneTurn)
  			playerOneTurn = false;
  		else
  			playerOneTurn = true;
  	}
  	else
  	{
  		std::cout << "Space Occupied, please try again." << std::endl;
  		goto GET_INPUT;
  	}
  }
  if(playerWon)
  {
  	std::cout << "Player 1 won!" << std::endl;
  }
  else
  {
  	std::cout << "Player 2 won!" << std::endl;
  }

  std::cout << "Would you like to play again?(y or n): ";
  std::cin >> playAgain;
  if(playAgain == 'y')
  {
  	board.clear();
  	cin.clear();
  	cin.ignore(100, '\n');
  	goto GAME_START;
  }
  return 0;
}