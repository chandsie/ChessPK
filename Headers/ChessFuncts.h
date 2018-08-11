#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <cmath>

#pragma comment (lib, "winmm.lib")

#define BLACK false 
#define WHITE true

#define MAIN 0
	#define MAIN_PLAY 0
	#define MAIN_HELP 2
	#define MAIN_QUIT 3

#define PLAY 1
	#define PLAY_STD  0
	#define PLAY_FILE 1
	#define PLAY_MAIN 2

#define OPTIONS 2
	#define OPTIONS_MUSIC   0
	#define OPTIONS_COLOR   1
	#define OPTIONS_SUMMARY 2
	#define OPTIONS_MAIN    3

#define MUSIC 7
	#define MUSIC_POKEMON 0
	#define MUSIC_NIRVANA 1
	#define MUSIC_MOZART  2
	#define MUSIC_BEATLES 3

#define COLOR 4
	#define COLOR_BGCOLOR  0
	#define COLOR_FGCOLOR  1
	#define COLOR_PCOLOR   2
	#define COLOR_SCOLOR   3
	#define COLOR_DEFAULTS 4
	#define COLOR_OPTIONS  5

#define COLOR_CHOICES 6

#define SUMMARY 5

#define HELP 8
#define HELP_MENU 42
	#define HELP_BASIC   0
	#define HELP_MOVES   1
	#define HELP_INPUT   2
	#define HELP_SPECIAL 3
	#define HELP_ABOUT   4
	#define HELP_MAIN    5

using namespace std;

struct cell 
{ 
	bool color; 
	bool occupied; 
	string piece; 
};

struct cellAddress 
{ 
	int row; 
	int col; 
};

struct moveAddress 
{ 
	cellAddress init;
	cellAddress dest;
};


//**Shreyas**//
void  startGame ();
//**Kamil**//
	int  mainMenuInterface ();
	int  playGameMenu();
	void displayMenu (int menu, int pos);
	void musicChangerMenu ();
	void colorChangerMenu ();
	void colorChanger(System::ConsoleColor &color);
	void summaryChangerMenu ();
	void help ();
//**Shreyas**//
void standard ();

void fromFile (string filename); 

void initBoard (cell board[8][8]); 

void initBoard (cell board[8][8], ifstream &file);

void dispBoard (cell board[8][8]); 

int  intConvert (char x);

char charConvert (int x);

bool updateBoard (cell board[8][8], moveAddress add);
//**Gloria**//
bool checkMove (string input, cell board [8][8], bool color);
	bool checkPawnMove   (moveAddress locs, cell board [8][8]);
	bool checkRookMove   (moveAddress locs, cell board [8][8]);
	bool checkKnightMove (moveAddress locs, cell board [8][8]);
	bool checkBishopMove (moveAddress locs, cell board [8][8]);
	bool checkQueenMove  (moveAddress locs, cell board [8][8]);
	bool checkKingMove   (moveAddress locs, cell Board [8][8]);
//**Shreyas**//
moveAddress userInput (bool color, cell board[8][8]); 

void saveToFile (cell board[8][8]);

bool isMate(cell board [8][8]);

string winner (cell board[8][8]);
