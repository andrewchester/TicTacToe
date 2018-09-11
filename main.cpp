/*
* Andrew Chester - TicTacToe
* A text based tictactoe program with 2 players
*/
#include <iostream>
#include <string.h>

#include "board.h"

using namespace std;

int main()
{
  bool playerOneTurn = true; //Keep tracks of turns
  bool* turnP = &playerOneTurn; 
  bool playing = true; //Boolean for the while loop(although it just uses break anyways)
  bool* playingP = &playing;
  bool playerWon = true; //Boolean for which player won
  bool* playerWonP = &playerWon;

  char choice[100]; //The choice of the player(a1, a2, etc)
  char playAgain; //If they want to play again
  int x, y; //The x,y of their choice
  int xWins = 0, oWins = 0; //Number of wins by each player

  Board board; //Game board object

  GAME_START:  //Return here is they want to play again
  while(playing)
  {
  	board.printBoard(); //Print out the board at the start of each turn

  	GET_INPUT: //Return here if the input is invalid
  	if(playerOneTurn)
  		std::cout << "Player 1 enter your choice(ex: a1): ";
  	else
  		std::cout << "Player 2 enter your choice(ex: a1): ";
  	std::cin.get(choice, 100);
  	std::cin.clear();
  	std::cin.ignore(100, '\n');

    if(strlen(choice) != 2)
    {
      std::cout << "Improper input, please try again. " << std::endl;
      goto GET_INPUT;
    }

    //Set the x/y using the ascii character values of the first and second characters in their input
	  x = ((int)choice[0] - 97);
  	y = ((int)choice[1] - 49);

    //If the space they chose was unoccupied, update the board with their choice
  	if(!board.spaceOccupied(x, y))
  	{
  		board.updateBoard(x, y, turnP); //Updates the board
  		if(board.testWin(playerWonP, turnP)) //If they won, then break from the loop and print the final board
      {
        board.printBoard();
  			break;
      }
      if(board.isFull()) //IF the board is full and they didn't win
      {
        board.printBoard(); //Print out the board and exit the loop
        std::cout<< "It was a tie!" << endl;
        goto RESTART;
      }
      //If there wasn't a win, toggle the player's turn. We have to do this after testWin() otherwise we won't know who won
  		if(playerOneTurn) 
  			playerOneTurn = false;
  		else
  			playerOneTurn = true;
  	}
  	else //In case they chose a space that already occupied
  	{
  		std::cout << "Space Occupied, please try again." << std::endl;
  		goto GET_INPUT;
  	}
  }
  //Different scenerios based on which player won, also increments the win variable and tells the player
  if(playerWon)
  {
  	std::cout << "Player 1 won!" << std::endl;
    xWins++;
    std::cout << "Player 1 has won " << xWins << " times!" << std::endl;
  }
  else
  {
  	std::cout << "Player 2 won!" << std::endl;
    oWins++;
    std::cout << "Player 2 has won " << oWins << " times!" << std::endl;
  }
  RESTART:
  //Restarts the game if they want to play again
  std::cout << "Would you like to play again?(y or n): ";
  std::cin >> playAgain;
  if(playAgain == 'y')
  {
  	board.clear();//Fills the board with 0s
  	cin.clear();
  	cin.ignore(100, '\n');
  	goto GAME_START;
  }
  return 0;
}