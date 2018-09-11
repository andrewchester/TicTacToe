//Header file for the board class
class Board
{
	struct Cell;
	Cell* board[3][3]; //Privately declaring the cell pointers

	//Functions for testWin()
	bool testColumns();
	bool testRows();
	bool testDiags();
	public:
		Board();
		//Boolean functions
		bool isFull();
		bool spaceOccupied(int x, int y);
		bool testWin(bool* playing, bool* won);

		//Void functions
		void clear();
		void updateBoard(int x, int y, bool* turn);
		void printBoard();
		void printValues();
};