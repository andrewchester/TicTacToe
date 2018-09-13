//Board class, handles checking win, updating board, board initialization, and also printing the board out
#include <iostream>

#include "board.h"

//Cell struct for holding the values and positions of values
struct Board::Cell{
  	int x, y, value;
};
//Constructor, initializes the board
Board::Board()
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			board[x][y] = new Cell(); //Use new so the cells are allocated to the heap and not overwritten at the end of the function
			(*board[x][y]).x = x;
			(*board[x][y]).y = y;
			(*board[x][y]).value = 0; //Start all cells at 0
		}
	}
}
//A function that changes the value depending on whose turn it was
void Board::updateBoard(int x, int y, bool* turn)
{
	if(*turn)
		(*board[x][y]).value = 1;
	else
		(*board[x][y]).value = 2;
}
//Returns true if the space isn't empty
bool Board::spaceOccupied(int x, int y)
{
	if((*board[x][y]).value != 0)
		return true;
	return false;
}
//A function for testing if there are 3 in a row in the columns
bool Board::testColumns()
{
	//Total count of x's and o's in a column
	int xCount = 0;
	int oCount = 0;

	for(int row = 0; row < 3; row++)
	{
		//If either of them are three at the end of the loop, return true early
		if(xCount == 3 || oCount == 3)
			return true;
		xCount = 0; //Reset the values
		oCount = 0;
		for(int column = 0; column < 3; column++)
		{
			//Increment the values according to the value of the cell
			if((*board[row][column]).value == 1)
			{
				xCount++;
			}
			else if((*board[row][column]).value == 2)
			{
				oCount++;
			}
		}
	}
	return false;
}
//Function for testing rows
bool Board::testRows()
{
	//Total count of x's and o's in a row
	int xCount = 0;
	int oCount = 0;

	for(int column = 0; column < 3; column++)
	{
		//Return true early if we find a row with 3 in a row
		if(xCount == 3 || oCount == 3)
			return true;
		xCount = 0; //Reset values
		oCount = 0;
		for(int row = 0; row < 3; row++)
		{
			//Incremement values accordingly
			if((*board[row][column]).value == 1)
			{
				xCount++;
			}
			else if((*board[row][column]).value == 2)
			{
				oCount++;
			}
		}
	}
	return false;
}
//Tests the diagonals
bool Board::testDiags()
{
	int xCount = 0; //Total count of x's and o's
	int oCount = 0;

	//Loops from top left to bottom right and increments the values accordingly
	for(int i = 0; i < 3; i++)
	{
		if((*board[i][i]).value == 1)
			xCount++;
		else if((*board[i][i]).value == 2)
			oCount++;
	}
	//If there are 3 in a row, return true
	if(xCount == 3 || oCount == 3)
		return true;

	xCount = 0; //Reset the counter variables
	oCount = 0;

  int i = 2; //Variables for counting x/y position and counting backwards from a3 to c1
  int j = 0;

  //While loop for going from a3 to c1
  while(i >= 0 && j <= 2)
  {
    //Increment the xCount of oCount variables depending on the value of the cell
    if((*board[i][j]).value == 1)
  		xCount++;
  	else if((*board[i][j]).value == 2)
  		oCount++;

    //Incerement the iterator variables, goes from (2,0) to (1,1) and then finally (0,2)
    i--;
    j++;
  }
  /*
	//The next three if/else if statements are for testing each cell from top right to bottom left individually and incrementing the appropriate variables
	if((*board[2][0]).value == 1) //a3
		xCount++;
	else if((*board[2][0]).value == 2)
		oCount++;

	if((*board[2][2]).value == 1) //b2
		xCount++;
	else if((*board[2][2]).value == 2)
		oCount++;

	if((*board[0][2]).value == 1) //c1
		xCount++;
	else if((*board[0][2]).value == 2)
		oCount++;

  */

	//If there are there in a row of either x's or o's, return true
	if(xCount == 3 || oCount == 3)
		return true;

	return false;
}
//A function for testing if there is a 3 in a row on the board
bool Board::testWin(bool* won, bool* turn)
{
	//If there is 1 three in a row on the board, return true and set the won variable depending on whoever moved last
	if(testColumns() || testRows() || testDiags())
	{
		if(*turn)
			*won = true;
		else
			*won = false;
		return true;
	}
	return false;
}
//A function that clears the board
void Board::clear()
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			(*board[x][y]).value = 0; //Loop through all the values and set them to empty
		}
	}
}
//A function that tests if the board is full
bool Board::isFull()
{
	int count = 0;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			//Counting up the variable if it isn't empty
			if((*board[x][y]).value != 0)
				count++;
		}
	}
	if(count == 9) //Returning true if all of them are filled
		return true;
	return false;
}
//Function for printing the board
void Board::printBoard()
{
	std::cout << "  1 2 3 "<< std::endl; //The 1 2 3 at the top
    for(int x = 0; x < 3; x++)
  	{
    	std::cout << (char)(97 + x) << " "; //Prints a, b, or c depending on the ascii character value
    	for(int y = 0; y < 3; y++)
    	{
    		//Depending on  the value of the cell, print a certain character
     		if((*board[x][y]).value == 2)
		    {
		    	std::cout << "O";
		    }
		    else if((*board[x][y]).value == 1)
		    {
		    	std::cout << "X";
		    }
		    else if((*board[x][y]).value == 0)
		    {
		    	std::cout << " ";
		    }
		   	std::cout << " "; //Space the chacters out in the row
    	}
     	std::cout << std::endl; //Return after the end of each row
  	}
}
//Prints out the values of the pointer array, used for bugtesting
void Board::printValues()
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			std::cout << x << ", " << y << " Address: " << board[x][y] << " Value: " << (*board[x][y]).value << std::endl;
		}
	}
}
