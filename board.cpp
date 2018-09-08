#include <iostream>

class Board
{

	Board()
	{
		cell board[3][3];
		//iniBoard(0);
	}

	struct cell{
		int x;
		int y;
		int value;
	};
	
	void iniBoard(cell** board, int value)
	{
		/*
		for(int x = 0; x < 3; x++)
		{
			for(int y = 0; y < 3; y++)
		    {
		      **board[x][y].xPos = x;
		      **board[x][y].yPos = y;
		      **board[x][y].value = value;
		    }
		}
		*/
	}

	void printBoard(cell board[3][3])
	{
		std::cout << " 1 2 3 "<< std::endl;
  		for(int x = 0; x < 3; x++)
		{
		  std::cout << (char)(97 + x) << " ";
		  for(int y = 0; y < 3; y++)
		  {
		    if(board[x][y].value == 0)
		   	{
		      std::cout << " ";
		    }
		    else if(board[x][y].value == 1)
		    {
		      std::cout << "X";
		    }
		    else if(board[x][y].value = 2)
		    {
		      std::cout << "O";
		    }
		      std::cout << " ";
		  }
		  std::cout << std::endl;
		}
	}
	void clear(cell** board)
	{

	}
	bool isFull(cell** board)
	{

	}
};