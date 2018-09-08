class Board
{
	public:
		Board();
		struct cell;
		void iniBoard(cell** board, int value);
		void printBoard(cell board[3][3]);
		void clear(cell** board);
		bool isFul(cell** board);
};