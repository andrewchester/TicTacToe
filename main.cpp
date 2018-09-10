/*
 * Andrew Chester
 * TicTacToe
 * value: 0 = empty, 1 = X, 2 = O
 */
#include <iostream>
#include <string.h>

//Cell struct that holds all data for a particular cell
struct Cell
{
  int x, y, value;
};

//A function that prints the board out
void printBoard(Cell* board[3][3])
{
  std::cout << "  1 2 3 " << std::endl; //Print the top of the board
  for(int x = 0; x < 3; x++)
  {
    std::cout << (char)(97 + x); //Print out the letter in front of the row
    for(int y = 0; y < 3; y++)
    {
      //Print out the letter
      std::cout << " ";
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

void updateBoard(Cell* board[3][3], char* choice[2], bool* turn, bool* noUpdate)
{
  int x = ((int)*choice[0] - 97);
  int y = ((int)*choice[1] - 49);

  if((*board[x][y]).value != 0)
  {
    *noUpdate = true;
    return;
  }

  if(*turn)
  {
    (*board[x][y]).value = 1;
    *turn = false;
  }
  else
  {
    (*board[x][y]).value = 2;
    *turn = true;
  }

  *noUpdate = false;
}

bool isFull(Cell* board[3][3])
{
  int count = 0;
  for(int y = 0; y < 3; y++)
  {
    for(int x = 0; x < 3; x++)
    {
      if((*board[x][y]).value != 0)
      {
        count++;
      }
    }
  }
  if(count == 9)
    return true;

  return false;
}

bool isGameOver(Cell* board[3][3], bool* playing)
{
  
}


int main()
{
  //2d cell array and pointer array
  Cell board[3][3];
  Cell* boardP[3][3];
  
  //Initializing the board and pointer array
  for(int y = 0; y < 3; y++)
  {
    for(int x = 0; x < 3; x++)
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
  bool noUpdate = false;
  bool* noUpdateP = &noUpdate;

  char choice[3];
  char* choiceP[3];

  while(playing)
  {
    //Check if there's a win

    GET_INPUT:
    if(playerOneTurn)
    {
      std::cout << "Player 1 enter your choice(ex: a1): ";
    }
    else
    {
      std::cout << "Player 2 enter your choice(ex: a1): ";
    }
    std::cin.get(choice, 3);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    if((int)choice[0] >= 65 && (int)choice[0] <= 90) //If it's uppercase
      choice[0] = (char)((int)choice[0] + 32); //Make it lowercase by increasing the ascii value by 32
    
    if((int)choice[0] < 97 || (int)choice[0] > 99 || (int)choice[1] < 49 || (int)choice[1] > 51)
    {
      std::cout << "Invalid input, please try again." << std::endl;
      goto GET_INPUT;
    }
    
    for(int i = 0; i < 3; i++)
      choiceP[i] = &choice[i];

    updateBoard(boardP, choiceP, turnP, noUpdateP);

    if(noUpdate)
    {
      std::cout << "That space is already occupied, please try again." << std::endl;
      goto GET_INPUT;
    }

    printBoard(boardP); 

    //Check if there's a win
  }

  return 0;
}
