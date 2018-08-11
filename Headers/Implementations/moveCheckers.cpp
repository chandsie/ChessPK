#include "../ChessFuncts.h"

moveAddress userInput (bool color, cell board [8][8]) 
{
	string input; 
	bool isValid = false; 
	
	if (color)
		cout << "White Turn: ";
	else
		cout << "Black Turn: ";
		
	getline(cin, input);

	while (!isValid) 
	{
		if (input == "quit")
			break;

		isValid = checkMove(input, board, color);
		if(isValid)
			break;
		
		system("cls");
		dispBoard(board);

		if (color)
			cout << "Invalid move. Try again white: ";
		else
			cout << "Invalid move. Try again black: ";
		
		getline(cin, input);
	}

	moveAddress locs;

	if (input == "quit" || input == "QUIT")
	{
		locs.init.col = 0;
		locs.init.row = 0;
		locs.dest.col = 42;
		locs.dest.row = 0;
	}
	else
	{
		char icol = input[0];
		char irow = input[1];
		char dcol = input[3];
		char drow = input[4];

		locs.init.col = intConvert(icol);
		locs.init.row = intConvert(irow);
		locs.dest.col = intConvert(dcol);
		locs.dest.row = intConvert(drow);
	}

	return locs; 
}

bool checkMove (string input, cell board [8][8], bool color) 
{
	if (input.size() != 5)
		return false;

	moveAddress locs;

	char icol = input[0];
	char irow = input[1];
	char dcol = input[3];
	char drow = input[4];
	
	if (!(isalpha(icol) && isalpha(dcol)))
		return false;
	else if (!(isspace(input[2])))
		return false;
	else if (!(isdigit(irow) && isdigit(drow)))
		return false;

	locs.init.col = intConvert(icol);
	locs.init.row = intConvert(irow);
	locs.dest.col = intConvert(dcol);
	locs.dest.row = intConvert(drow);

	if (locs.init.row == -1 || locs.init.col == -1 || locs.dest.row == -1 || locs.dest.col == -1)
		return false;

	string piece = board[locs.init.row][locs.init.col].piece;
	char initPieceColor = piece[0];
	char destPieceColor = board[locs.dest.row][locs.dest.col].piece[0];

	if (locs.init.col == locs.dest.col && locs.init.row == locs.dest.row)
		return false;
	else if (initPieceColor == destPieceColor)
		return false;
	else if (initPieceColor == 'w' && !color)
		return false;
	else if (initPieceColor == 'b' && color)
		return false;

	if (piece=="wP"||piece=="bP")
		return checkPawnMove (locs, board);
	else if (piece=="wN"||piece=="bN")
		return checkKnightMove (locs, board);
	else if (piece=="wR"||piece=="bR")
		return checkRookMove (locs, board);
	else if (piece=="wB"||piece=="bB")
		return checkBishopMove (locs, board);
	else if (piece=="wQ"||piece=="bQ")
		return checkQueenMove (locs, board);
	else if (piece=="wK"||piece=="bK")
		return checkKingMove (locs, board);
	else
		return false;
}

bool checkKingMove (moveAddress locs, cell board [8][8])
{
	if ((locs.dest.row == (locs.init.row + 1) || locs.dest.row == (locs.init.row - 1) ) && locs.dest.col == locs.init.col)
		return true;
	else if ((locs.dest.col == (locs.init.col + 1) || locs.dest.col == (locs.init.col - 1)))
		if (locs.dest.row == (locs.init.row + 1))
			return true;
		else if (locs.dest.row == locs.init.row)
			return true;
		else if (locs.dest.row == (locs.init.row - 1))
			return true;

	return false;
}
bool checkQueenMove (moveAddress locs, cell board [8][8])
{
	if (checkBishopMove(locs, board) || checkRookMove(locs, board))
		return true;
	else
		return false;
}
bool checkPawnMove (moveAddress locs, cell board [8][8])
{
	if (locs.init.row == 1)
	{
		if (locs.dest.row == 2)
		{
			if (board[locs.dest.row][locs.dest.col].occupied)
			{
				if (locs.init.col + 1 == locs.dest.col || locs.init.col - 1 == locs.dest.col)
					return true;
				else
					return false;
			}
			else
			{
				if (locs.init.col == locs.dest.col)
					return true;
				else
					return false;
			}
		}
		else if (locs.dest.row == 3)
		{
			if (locs.dest.col == locs.init.col)
				return true;
			else 
				return false;
		}
	}
	else if (locs.init.row == 6)
	{
		if (locs.dest.row == 5)
		{
			if (board[locs.dest.row][locs.dest.col].occupied)
			{
				if (locs.init.col + 1 == locs.dest.col || locs.init.col - 1 == locs.dest.col)
					return true;
				else
					return false;
			}
			else
			{
				if (locs.init.col == locs.dest.col)
					return true;
				else
					return false;
			}
		}
		else if (locs.dest.row == 4)
		{
			if (locs.dest.col == locs.init.col)
				return true;
			else 
				return false;
		}
	}
	else
	{
		if(board[locs.init.row][locs.init.col].piece[0] == 'w')
		{
			if (locs.dest.row == (locs.init.row - 1))
			{
				if (board[locs.dest.row][locs.dest.col].occupied)
				{
					if (locs.init.col + 1 == locs.dest.col || locs.init.col - 1 == locs.dest.col)
						return true;
					else
						return false;
				}
				else
				{
					if (locs.init.col == locs.dest.col)
						return true;
					else
						return false;
				}
			}
		}
		else
		{
			if(board[locs.init.row][locs.init.col].piece[0] == 'b')
			{
				if (locs.dest.row == (locs.init.row + 1))
				{
					if (board[locs.dest.row][locs.dest.col].occupied)
					{
						if (locs.init.col + 1 == locs.dest.col || locs.init.col - 1 == locs.dest.col)
							return true;
						else
							return false;
					}
					else
					{
						if (locs.init.col == locs.dest.col)
							return true;
						else
							return false;
					}
				}
			}
		}
	}

	return false;
}


bool checkKnightMove (moveAddress locs, cell board [8][8])
{
	if (board[locs.init.row][locs.init.col].color != board[locs.dest.row][locs.dest.col].color)
		if ((locs.dest.col == (locs.init.col + 1) || locs.dest.col == (locs.init.col - 1)) && (locs.dest.row == (locs.init.row + 2) || locs.dest.row == (locs.init.row - 2)))
			return true;
		else if ((locs.dest.col == (locs.init.col + 2) || locs.dest.col == (locs.init.col - 2)) && (locs.dest.row == (locs.init.row + 1) || locs.dest.row == (locs.init.row - 1)))
			return true;
		else
			return false;
	else
		return false;
}

bool checkRookMove (moveAddress locs, cell board [8][8])
{
	if (locs.dest.col == locs.init.col || locs.dest.row == locs.init.row)
	{
		if (locs.dest.col == locs.init.col)
		{
			if (locs.dest.row > locs.init.row)
			{
				for (int i = locs.init.row + 1; i != locs.dest.row; i++)
				{
					if (board[i][locs.init.col].occupied)
						return false;
					else
						return true;
				}
				return true;
			}
			else
			{
				for (int i = locs.init.row - 1; i != locs.dest.row; i--)
				{
					if (board[i][locs.init.col].occupied)
						return false;
					else
						return true;
				}
				return true;
			}
		}
		else
		{
			if (locs.dest.col > locs.init.col)
			{
				for (int i = locs.init.col + 1; i != locs.dest.col; i++)
				{
					if (board[locs.init.row][i].occupied)
						return false;
					else
						return true;
				}
				return true;
			}
			else
			{
				for (int i = locs.init.col - 1; i != locs.dest.col; i--)
				{
					if (board[locs.init.row][i].occupied)
						return false;
					else
						return true;
				}
				return true;
			}
		}
	}
	
	return false;
}

bool checkBishopMove (moveAddress locs, cell board [8][8])
{
	if (locs.init.col == locs.dest.col || locs.init.row == locs.dest.row)
		return false;
	else if (board[locs.dest.row][locs.dest.col].color == board[locs.init.row][locs.init.col].color)
		if (abs(locs.dest.col - locs.init.col) == abs(locs.dest.row - locs.init.row))
			if (locs.dest.col - locs.init.col > 0)
				if (locs.dest.row - locs.init.row > 0)
				{
					int i = locs.init.row + 1;
					int ii = locs.init.col + 1;

					while (i != locs.dest.row && ii != locs.dest.col)
					{
						if (board[i][ii].occupied)
							return false;
						i++;
						ii++;
					}
					return true;
				}
				else
				{
					int i = locs.init.row - 1;
					int ii = locs.init.col + 1;

					while (i != locs.dest.row && ii != locs.dest.col)
					{
						if (board[i][ii].occupied)
							return false;
						i--;
						ii++;
					}
					return true;
				}
			else
				if (locs.dest.row - locs.init.row > 0)
				{
					int i = locs.init.row + 1;
					int ii = locs.init.col - 1;

					while (i != locs.dest.row && ii != locs.dest.col)
					{
						if (board[i][ii].occupied)
							return false;
						i++;
						ii--;
					}
					return true;
				}
				else
				{
					int i = locs.init.row - 1;
					int ii = locs.init.col - 1;

					while (i != locs.dest.row && ii != locs.dest.col)
					{
						if (board[i][ii].occupied)
							return false;
						i--;
						ii--;
					}
					return true;
				}
		else
			return false;
	else
		return false;
}
