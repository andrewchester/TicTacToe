#include <iostream>

#include "board.h"
	
Board::Board()
{

}

struct Board::Cell{
  	int x, y, value;
};

void Board::iniBoard()
{
	Cell board[3][3];
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
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			std::cout << x << ", " << y << " Address: " << &board[x][y] << " Value: " << board[x][y].value << std::endl;
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
     		if((*boardP[x][y]).value == 2)
		    {
		    	std::cout << "O";
		    }
		    else if((*boardP[x][y]).value == 1)
		    {
		    	std::cout << "X";
		    }
		    else if((*boardP[x][y]).value == 0)
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
			std::cout << x << ", " << y << " Address: " << boardP[x][y] << " Value: " << (*boardP[x][y]).value << std::endl;
		}
	}
}