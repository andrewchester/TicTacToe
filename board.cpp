#include <iostream>

#include "board.h"

struct Board::Cell{
  	int x, y, value;
};	

Board::Board()
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			board[x][y] = new Cell();
			(*board[x][y]).x = x;
			(*board[x][y]).y = y;
			(*board[x][y]).value = 0;
		}
	}
}

void Board::printBoard()
{
	std::cout << "  1 2 3 "<< std::endl;
    for(int x = 0; x < 3; x++)
  	{
    	std::cout << (char)(97 + x) << " ";
    	for(int y = 0; y < 3; y++)
    	{
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
		   	std::cout << " ";
    	}
     	std::cout << std::endl;
  	}
}

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