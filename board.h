class Board
{
	struct Cell;
	Cell* board[3][3];

	bool testColumns();
	bool testRows();
	bool testDiags();
	public:
		Board();
		bool isFull();
		bool spaceOccupied(int x, int y);
		bool testWin(bool* playing, bool* won);

		void clear();
		void updateBoard(int x, int y, bool* turn);
		void printBoard();
		void printValues();
};