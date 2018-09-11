class Board
{
	struct Cell;
	Cell* board[3][3];
	public:
		Board();
		void updateBoard(int x, int y, bool* turn);
		bool isFull();
		bool spaceOccupied(int x, int y);
		void printBoard();
		void printValues();
};