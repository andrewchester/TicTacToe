class Board
{
	struct Cell;
	Cell* boardP[3][3];
	public:
		Board();
		void iniBoard();
		void printBoard();
		void printValues();
};