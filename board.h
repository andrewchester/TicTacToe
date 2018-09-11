class Board
{
	struct Cell;
	Cell* board[3][3];
	public:
		Board();
		void printBoard();
		void printValues();
};