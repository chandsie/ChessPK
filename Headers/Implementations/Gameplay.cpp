#include "../ChessFuncts.h"

void standard()
{
	System::Console::CursorVisible::set(true);

	cell board[8][8];
	char cont;
	bool con;

	initBoard(board);
	dispBoard(board);

	int i=1;

	for (;!isMate(board);i++) 
	{
		if(i%2==1) 
			con = updateBoard(board, userInput(WHITE, board));
		else 
			con = updateBoard(board, userInput(BLACK, board));

		if (con == false) 
		{
			System::Console::SetCursorPosition(0, 26);
			cout << "Are you sure you really want to quit? "; 
			cin >> cont;
			if (cont == 'y') 
			{	
				cout << "Save? "; 
				cin >> cont;
				if (cont=='y') 
				{
					cin.ignore();
					saveToFile(board);
				}
				break; 
			}
			
			cin.ignore();
			i-=1;
		}

		System::Console::SetCursorPosition(0,0);
		dispBoard(board);
		cout << "                                                                   " << endl;
		System::Console::SetCursorPosition(0, 26);
	}
	
	cout << "GAME OVER!" << endl;
	
	if(isMate(board))
		cout << winner(board) << " won the game! Congratulations!" << endl;
	cout << "Number of moves: " << i << endl;

	system("pause");
}

void fromFile(string filename)
{
	System::Console::CursorVisible::set(true);

	cell board[8][8];
	char cont;
	bool con;
	ifstream initfile(filename.c_str(), ios::binary);
	
	initBoard(board, initfile);
	dispBoard(board);

	int i=1;

	for (;!isMate(board);i++) 
	{
		if(i%2==1) 
			con = updateBoard(board, userInput(WHITE, board));
		else 
			con = updateBoard(board, userInput(BLACK, board));

		if (con == false) 
		{
			System::Console::SetCursorPosition(0, 26);
			cout << "Are you sure you really want to quit? "; 
			cin >> cont;
			if (cont == 'y') 
			{	
				cout << "Save? "; 
				cin >> cont;
				if (cont=='y') 
				{
					cin.ignore();
					saveToFile(board);
				}
				break; 
			}
			
			cin.ignore();
			i-=1;
		}

		system("cls");
		dispBoard(board);
	}
	
	cout << "GAME OVER!" << endl;
	
	if(isMate(board))
		cout << winner(board) << " won the game! Congratulations!" << endl;

	cout << "Number of moves: " << i << endl;

	system("pause");
}

void dispBoard (cell board[8][8]) 
{
	extern System::ConsoleColor pcolor;
	extern System::ConsoleColor scolor;
	extern System::ConsoleColor bgcolor;
	extern System::ConsoleColor fgcolor;

	cout <<  "\t    a     b     c     d     e     f     g     h\n\t ";
	cout << "Ú-----Â-----Â-----Â-----Â-----Â-----Â-----Â-----¿" << endl;

	for(int i=0;i!=8;i++) 
	{
		System::Console::BackgroundColor::set(bgcolor);
		cout << "\t" << i+1 << "³";
		for(int ii=0;ii!=8;ii++) 
			if (board[i][ii].color)
			{
				System::Console::BackgroundColor::set(pcolor);
				cout << "     "; 
				System::Console::BackgroundColor::set(bgcolor);
				cout << "³";
			}
			else 
			{
				System::Console::BackgroundColor::set(scolor);
				cout << "     "; 
				System::Console::BackgroundColor::set(bgcolor);
				cout << "³";
			} 
		System::Console::BackgroundColor::set(bgcolor);
		cout << "\n\t ³";

		for(int ii=0;ii!=8;ii++) 
			if (board[i][ii].occupied == false) 
				if (board[i][ii].color)
				{
					System::Console::BackgroundColor::set(pcolor);
					cout << "     "; 
					System::Console::BackgroundColor::set(bgcolor);
					cout << "³";
				}
				else 
				{
					System::Console::BackgroundColor::set(scolor);
					cout << "     "; 
					System::Console::BackgroundColor::set(bgcolor);
					cout << "³";
				} 
			else 
				if (board[i][ii].color)
				{
					System::Console::ForegroundColor::set(scolor);
					System::Console::BackgroundColor::set(pcolor);
					cout << "  " << board[i][ii].piece << " ";
					System::Console::BackgroundColor::set(bgcolor);
					System::Console::ForegroundColor::set(fgcolor);
					cout << "³"; 
				}
				else 
				{
					System::Console::BackgroundColor::set(scolor);
					System::Console::ForegroundColor::set(pcolor);
					cout << "  " << board[i][ii].piece << " ";
					System::Console::BackgroundColor::set(bgcolor);
					System::Console::ForegroundColor::set(fgcolor);
					cout << "³"; 
				} 
		if (i!=7)
			cout << "\n\t Ã-----Å-----Å-----Å-----Å-----Å-----Å-----Å-----´" << endl; 
		else 
			cout << "\n\t À-----Á-----Á-----Á-----Á-----Á-----Á-----Á-----Ù" << endl; 
	}
}


bool updateBoard (cell board[8][8], moveAddress locs) 
{
	extern bool summary;
	static int count = 1;
	static int i = 0;
	i++;

	if (locs.dest.col == 42)
		return false;

	string temp = board[locs.init.row][locs.init.col].piece;
	
	if (summary)
	{
		ofstream out;
		if (i == 1)
			out.open("GameSummary.txt", ios::out);
		else
			out.open("GameSummary.txt", ios::app);
		
		if (i%2 == 1)
		{
			out << count << ". ";
			count ++;
		}
		out << temp << " ";
		if (board[locs.dest.row][locs.dest.col].occupied)
			out << "x";
		out << charConvert(locs.dest.col);	
		out << locs.dest.row + 1;

		if (i%2 == 1)
			out << " ";
		else 
			out << "\n";

		out.close();
	}
	board[locs.init.row][locs.init.col].piece=""; 
	board[locs.init.row][locs.init.col].occupied=false;

	board[locs.dest.row][locs.dest.col].piece=temp;
	board[locs.dest.row][locs.dest.col].occupied=true; 

	

	return true;
}
//***UTIL***//
int  intConvert (char x) 
{
	if (x == '1' || tolower(x) == 'a') 
		return 0; 
	else if (x == '2' || tolower(x) == 'b') 
		return 1; 
	else if (x == '3' || tolower(x) == 'c') 
		return 2; 
	else if (x == '4' || tolower(x) == 'd') 
		return 3; 
	else if (x == '5' || tolower(x) == 'e') 
		return 4; 
	else if (x == '6' || tolower(x) == 'f') 
		return 5; 
	else if (x == '7' || tolower(x) == 'g')
		return 6; 
	else if (x == '8' || tolower(x) == 'h')
		return 7; 
	else 
		return -1; 
}
char charConvert (int x) 
{
	if (x == 0) 
		return 'a'; 
	else if (x == 1) 
		return 'b'; 
	else if (x == 2) 
		return 'c'; 
	else if (x == 3) 
		return 'd'; 
	else if (x == 4) 
		return 'e'; 
	else if (x == 5) 
		return 'f';
	else if (x == 6) 
		return 'g';
	else if (x == 7) 
		return 'h'; 
	else
		return '?';
}

bool isMate (cell board [8][8])
{
	bool isWhiteAlive = false;
	bool isBlackAlive = false;

	for (int i = 0; i != 8; i++)
		for (int ii = 0; ii != 8; ii++)
			if (board[i][ii].piece == "wK")
				isWhiteAlive = true;
			else if (board[i][ii].piece == "bK")
				isBlackAlive = true;
	return (!(isBlackAlive && isWhiteAlive));
}

string winner (cell board [8][8])
{
	bool isWhiteAlive = false;
	bool isBlackAlive = false;

	for (int i = 0; i != 8; i++)
		for (int ii = 0; ii != 8; ii++)
			if (board[i][ii].piece == "wK")
				isWhiteAlive = true;
			else if (board[i][ii].piece == "bK")
				isBlackAlive = true;

	if (isWhiteAlive)
		return "White";
	else
		return "Black";
}

void saveToFile (cell board [8][8])
{
	string saveFilename;

	cout << "Please enter a name for your save file: ";
	getline(cin, saveFilename);

	saveFilename += ".dat";

	ofstream saveFile (saveFilename.c_str(), ios::binary);

	for(int i=0;i!=8;i++)
		for(int ii=0;ii!=8;ii++)
			if (board[i][ii].piece !="")
			{	
				saveFile.write(board[i][ii].piece.c_str(), 2);
				saveFile.write(" ", 1);
			}
			else
				saveFile.write("bb ", 3);
	saveFile.close();	
}

