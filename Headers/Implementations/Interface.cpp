#include "../ChessFuncts.h"

bool summary = true;
System::ConsoleColor pcolor = System::ConsoleColor::White;
System::ConsoleColor scolor = System::ConsoleColor::Black;
System::ConsoleColor bgcolor = System::ConsoleColor::Gray;
System::ConsoleColor fgcolor = System::ConsoleColor::Blue;

void startGame()
{
	string filename;
	int choice;
	
	PlaySound(TEXT("mozart"), 0, SND_LOOP|SND_ASYNC); 
	
	while (1)
	{
		System::Console::BackgroundColor::set(bgcolor);
		System::Console::ForegroundColor::set(fgcolor);
		System::Console::CursorVisible::set(false);
		system ("cls");
				
		choice = mainMenuInterface();
		system("cls");

		if (choice == 0)
			standard();
		else if (choice == 1)
		{
				cout << "\n\n\n\n\n\n"
				<< "		  CCCC  H    H  EEEEE    SSSS   SSSS		" << endl 
				<< "		 CC     H    H  E       S     S				" << endl
				<< "		C       HHHHHH  EEEE     SS     SS			" << endl
				<< "		C       HHHHHH  EEEE      SS     SS			" << endl
				<< "		 CC     H    H  E          S      S			" << endl
				<< "		  CCCC  H    H  EEEEE  SSSS   SSSS		\n\n" << endl;
			 
				System::Console::CursorVisible::set(true);
				cout << "\n\n\n\n\tPlease enter the name of the file you wish to load from: \n\t\t";
				getline(cin, filename);
				filename += ".dat";
				ifstream initfile(filename.c_str());
				if (!initfile.good()) 
				{
					cout << "\n\n\tInvalid Entry. Please Try Again." << endl;
					system("pause");
					system("cls");
				}
				else
				{	
					system("cls");
					fromFile(filename);
				}
		}
		else
			return;
		
	}
}

void displayMenu (int menu, int pos)
{
	System::Console::BackgroundColor::set(bgcolor);
	System::Console::ForegroundColor::set(fgcolor);
	if (menu == 42)
	{
		cout << "\n\n\n\n"
			 << "		  CCCC  H    H  EEEEE    SSSS   SSSS		" << endl 
			 << "		 CC     H    H  E       S     S				" << endl
			 << "		C       HHHHHH  EEEE     SS     SS			" << endl
			 << "		C       HHHHHH  EEEE      SS     SS			" << endl
			 << "		 CC     H    H  E          S      S			" << endl
			 << "		  CCCC  H    H  EEEEE  SSSS   SSSS		\n\n" << endl;
		if (pos == 0)
			cout << "			Basic Instructions			\n\n" << endl;
		else if (pos == 1)
			cout << "			Piece Moves					\n\n" << endl;
		if (pos == 2)
			cout << "			Input Help					\n\n" << endl;
		else if (pos == 3)
			cout << "			Special Features			\n\n" << endl;
		if (pos == 4)
			cout << "			About						\n\n" << endl;
	}
	else if (menu == MAIN)
	{
		
		cout << "\n\n\n\n\n\n"
			 << "		  CCCC  H    H  EEEEE    SSSS   SSSS		" << endl 
			 << "		 CC     H    H  E       S     S				" << endl
			 << "		C       HHHHHH  EEEE     SS     SS			" << endl
			 << "		C       HHHHHH  EEEE      SS     SS			" << endl
			 << "		 CC     H    H  E          S      S			" << endl
			 << "		  CCCC  H    H  EEEEE  SSSS   SSSS		\n\n" << endl
			 << "			Main Menu							\n\n" << endl;

		if(pos == 0)
			cout << "		      --> Play Game					" << endl;
		else
			cout << "		          Play Game					" << endl;

		if(pos == 1)
			cout << "		      --> Options					" << endl;
		else 
			cout << "		          Options					" << endl;

		if(pos == 2)
			cout << "		      --> Help						" << endl;
		else 
			cout << "		          Help						" << endl;
	
		if (pos == 3)
			cout << "		      --> Quit						" << endl;
		else
			cout << "		          Quit						" << endl;
	}
	else if (menu == PLAY)
	{
		cout << "\n\n\n\n\n\n"
			 << "		  CCCC  H    H  EEEEE    SSSS   SSSS		" << endl 
			 << "		 CC     H    H  E       S     S				" << endl
			 << "		C       HHHHHH  EEEE     SS     SS			" << endl
			 << "		C       HHHHHH  EEEE      SS     SS			" << endl
			 << "		 CC     H    H  E          S      S			" << endl
			 << "		  CCCC  H    H  EEEEE  SSSS   SSSS		\n\n" << endl
			 << "			Choose Game Type					\n\n" << endl;

		if(pos == 0)
			cout << "		      --> Standard					" << endl;
		else
			cout << "		          Standard					" << endl;

		if (pos == 1)
			cout << "		      --> From File					" << endl;
		else
			cout << "		          From File					" << endl;

		if (pos == 2)
			cout << "		      --> Return to Main			" << endl;
		else
			cout << "		          Return to Main			" << endl;
	}
	else if (menu == OPTIONS)
	{
		cout << "\n\n\n\n\n\n"
			 << "		  CCCC  H    H  EEEEE    SSSS   SSSS		" << endl 
			 << "		 CC     H    H  E       S     S				" << endl
			 << "		C       HHHHHH  EEEE     SS     SS			" << endl
			 << "		C       HHHHHH  EEEE      SS     SS			" << endl
			 << "		 CC     H    H  E          S      S			" << endl
			 << "		  CCCC  H    H  EEEEE  SSSS   SSSS		\n\n" << endl
			 << "			Options								\n\n" << endl;

		if(pos == 0)
			cout << "		      --> Music						" << endl;
		else
			cout << "		          Music						" << endl;

		if(pos == 1)
			cout << "		      --> Color						" << endl;
		else 
			cout << "		          Color						" << endl;
	
		if (pos == 2)
			cout << "		      --> Summary					" << endl;
		else
			cout << "		          Summary					" << endl;

		if (pos == 3)
			cout << "		      --> Return to Main			" << endl;
		else
			cout << "		          Return to Main			" << endl;
	}
	else if (menu == COLOR)
	{
		cout << "\n\n\n\n\n\n"
			 << "		  CCCC  H    H  EEEEE    SSSS   SSSS		" << endl 
			 << "		 CC     H    H  E       S     S				" << endl
			 << "		C       HHHHHH  EEEE     SS     SS			" << endl
			 << "		C       HHHHHH  EEEE      SS     SS			" << endl
			 << "		 CC     H    H  E          S      S			" << endl
			 << "		  CCCC  H    H  EEEEE  SSSS   SSSS		\n\n" << endl
			 << "			Color Option							\n" << endl;

		cout << "                          		Preview" << endl;

		if(pos == 0)
			cout << "      --> Background Color		Ú-----Â-----¿" << endl;
		else
			cout << "          Background Color		Ú-----Â-----¿" << endl;

		if(pos == 1)
			cout << "      --> Foreground Color		";
		else 
			cout << "          Foreground Color		";
		cout << "³";
		System::Console::BackgroundColor::set(pcolor);
		cout << "     ";
		System::Console::BackgroundColor::set(bgcolor);
		cout << "³";
		System::Console::BackgroundColor::set(scolor);
		cout << "     ";
		System::Console::BackgroundColor::set(bgcolor);
		cout << "³" << endl;

		if(pos == 2)
			cout << "      --> Primary Color  		";
		else
			cout << "          Primary Color  		";
		cout << "³";
		System::Console::BackgroundColor::set(pcolor);
		System::Console::ForegroundColor::set(scolor);
		cout << "  wK ";
		System::Console::ForegroundColor::set(fgcolor);
		System::Console::BackgroundColor::set(bgcolor);
		cout << "³";
		System::Console::BackgroundColor::set(scolor);
		System::Console::ForegroundColor::set(pcolor);
		cout << "  bK ";
		System::Console::ForegroundColor::set(fgcolor);
		System::Console::BackgroundColor::set(bgcolor);
		cout << "³" << endl;

		if(pos == 3)
			cout << "      --> Secondary Color		";
		else 
			cout << "          Secondary Color		";

		cout << "Ã-----Å-----´" << endl;

		if(pos == 4)
			cout << "      --> Restore to Default		";
		else 
			cout << "          Restore to Default		";
		cout << "³";
		System::Console::BackgroundColor::set(scolor);
		cout << "     ";
		System::Console::BackgroundColor::set(bgcolor);
		cout << "³";
		System::Console::BackgroundColor::set(pcolor);
		cout << "     ";
		System::Console::BackgroundColor::set(bgcolor);
		cout << "³\n";

		if(pos == 5)
			cout << "      --> Return To Options		";
		else 
			cout << "          Return To Options		";
		

		cout << "³";
		System::Console::BackgroundColor::set(scolor);
		cout << "     ";
		System::Console::BackgroundColor::set(bgcolor);
		cout << "³";
		System::Console::BackgroundColor::set(pcolor);
		cout << "     ";
		System::Console::BackgroundColor::set(bgcolor);
		cout << "³\n                          		À-----Á-----Ù" << endl;
	}
	else if (menu == SUMMARY)
	{
		cout << "\n\n\n\n\n\n"
			 << "		  CCCC  H    H  EEEEE    SSSS   SSSS		" << endl 
			 << "		 CC     H    H  E       S     S			    " << endl
			 << "		C       HHHHHH  EEEE     SS     SS		    " << endl
			 << "		C       HHHHHH  EEEE      SS     SS			" << endl
			 << "		 CC     H    H  E          S      S			" << endl
			 << "		  CCCC  H    H  EEEEE  SSSS   SSSS		\n\n" << endl
			 << "			Summary Option							\n" << endl;

		cout << "		    Currently: ";
		if (summary)
			cout << "Summarizing						" << endl;
		else
			cout << "Not Summarizing						" << endl;
		if(pos == 0)
			cout << "		      --> Generate Summary			" << endl;
		else
			cout << "		          Generate Summary			" << endl;

		if(pos == 1)
			cout << "		      --> Don't Generate Summary	" << endl;
		else 
			cout << "		          Don't Generate Summary	" << endl;
	}
	else if (menu == COLOR_CHOICES)
	{
		cout << "\n\n\n\n\n\n"
			 << "		  CCCC  H    H  EEEEE    SSSS   SSSS		" << endl 
			 << "		 CC     H    H  E       S     S				" << endl
			 << "		C       HHHHHH  EEEE     SS     SS			" << endl
			 << "		C       HHHHHH  EEEE      SS     SS			" << endl
			 << "		 CC     H    H  E          S      S			" << endl
			 << "		  CCCC  H    H  EEEEE  SSSS   SSSS		\n\n" << endl
			 << "			Color Choices 						\n\n" << endl;

		if(pos == 0)
			cout << "		      --> Black						" << endl;
		else
			cout << "		          Black						" << endl;

		if(pos == 1)
			cout << "		      --> Blue						" << endl;
		else 
			cout << "		          Blue						" << endl;
		if(pos == 2)
			cout << "		      --> Red						" << endl;
		else
			cout << "		          Red						" << endl;

		if(pos == 3)
			cout << "		      --> Green						" << endl;
		else 
			cout << "		          Green						" << endl;
		if(pos == 4)
			cout << "		      --> Yellow					" << endl;
		else
			cout << "		          Yellow					" << endl;

		if(pos == 5)
			cout << "		      --> White						" << endl;
		else 
			cout << "		          White						" << endl;

		if(pos == 6)
			cout << "		      --> Gray						" << endl;
		else 
			cout << "		          Gray						" << endl;
	}
	else if (menu == MUSIC)
	{
		cout << "\n\n\n\n\n\n"
			 << "		  CCCC  H    H  EEEEE    SSSS   SSSS		" << endl 
			 << "		 CC     H    H  E       S     S				" << endl
			 << "		C       HHHHHH  EEEE     SS     SS			" << endl
			 << "		C       HHHHHH  EEEE      SS     SS			" << endl
			 << "		 CC     H    H  E          S      S			" << endl
			 << "		  CCCC  H    H  EEEEE  SSSS   SSSS		\n\n" << endl
			 << "			Music								\n\n" << endl;

		if(pos == 0)
			cout << "		      --> Pokemon					" << endl;
		else
			cout << "		          Pokemon					" << endl;

		if(pos == 1)
			cout << "		      --> Nirvana					" << endl;
		else 
			cout << "		          Nirvana					" << endl;
	
		if (pos == 2)
			cout << "		      --> Mozart					" << endl;
		else
			cout << "		          Mozart					" << endl;

		if (pos == 3)
			cout << "		      --> Beatles					" << endl;
		else
			cout << "		          Beatles					" << endl;

		if (pos == 4)
			cout << "		      --> Mute						" << endl;
		else
			cout << "		          Mute						" << endl;
	}
	else if (menu == HELP)
	{
		cout << "\n\n\n\n\n\n"
			 << "		  CCCC  H    H  EEEEE    SSSS   SSSS		" << endl 
			 << "		 CC     H    H  E       S     S				" << endl
			 << "		C       HHHHHH  EEEE     SS     SS			" << endl
			 << "		C       HHHHHH  EEEE      SS     SS			" << endl
			 << "		 CC     H    H  E          S      S			" << endl
			 << "		  CCCC  H    H  EEEEE  SSSS   SSSS		\n\n" << endl
			 << "			Help								\n\n" << endl;

		if(pos == 0)
			cout << "		      --> Basic Instructions		" << endl;
		else
			cout << "		          Basic Instructions		" << endl;

		if(pos == 1)
			cout << "		      --> Chess Rules				" << endl;
		else 
			cout << "		          Chess Rules				" << endl;
		if(pos == 2)
			cout << "		      --> Move Input Help			" << endl;
		else
			cout << "		          Move Input Help			" << endl;

		if(pos == 3)
			cout << "		      --> Special Features			" << endl;
		else
			cout << "		          Special Features			" << endl;

		if(pos == 4)
			cout << "		      --> About						" << endl;
		else 
			cout << "		          About						" << endl;

		if(pos == 5)
			cout << "		      --> Return to Main			" << endl;
		else 
			cout << "		          Return to Main			" << endl;
	}

}


int  mainMenuInterface ()
{
	int currentMenu = MAIN;
	int position = 0;

	while (1)
	{
		system("cls");
		displayMenu(currentMenu, position);

		while(1)
		{
			if(_kbhit())
			{
				int mvmtVar1=_getch();

				if(mvmtVar1==224)
				{
					int mvmtVar2=_getch();	

					if (mvmtVar2==80 || mvmtVar2==77) 
					{
						if(position<3) 
						{
							position++;
							System::Console::SetCursorPosition(0,0);
							displayMenu(currentMenu, position);
						}
						else
						{
							position = 0;
							System::Console::SetCursorPosition(0,0);
							displayMenu(currentMenu, position);
						}
					} 
					else if (mvmtVar2==72 || mvmtVar2==75)
					{
						if(position>0) 
						{
							position--;
							System::Console::SetCursorPosition(0,0);
							displayMenu(currentMenu, position);
						}
						else
						{
							position = 3;
							System::Console::SetCursorPosition(0,0);
							displayMenu(currentMenu, position);
						}
					}
				}
				else if (mvmtVar1==13)
					break;
			}
		}
		if (currentMenu == MAIN)
			if (position == MAIN_QUIT)
				return -1;
			else if (position == MAIN_HELP)
			{
				help();
				currentMenu = MAIN;
			}
			else if (position == MAIN_PLAY)
			{
				int gameMode = playGameMenu();
				if (gameMode == PLAY_MAIN)
					currentMenu = MAIN;
				else
					return gameMode;
			}
			else
				currentMenu = position + 1;
		else if (currentMenu == OPTIONS)
			if (position == OPTIONS_MAIN)
				currentMenu = MAIN;
			else if (currentMenu == OPTIONS)
				if (position == OPTIONS_MUSIC)
				{
					musicChangerMenu();
					currentMenu = OPTIONS;
				}
				else if (position == OPTIONS_COLOR)
				{
					colorChangerMenu();
					currentMenu = OPTIONS;
				}
				else if (position == OPTIONS_SUMMARY)
				{
					summaryChangerMenu();
					currentMenu = OPTIONS;
				}

		position = 0;
	}
}
int  playGameMenu()
{
	int position = 0;

	system("cls");
	displayMenu(PLAY, position);

	while(1)
	{
		if(_kbhit())
		{
			int mvmtVar1=_getch();

			if(mvmtVar1==224)
			{
				int mvmtVar2=_getch();	

				if (mvmtVar2==80 || mvmtVar2==77) 
				{
					if(position<2) 
					{
						position++;
						System::Console::SetCursorPosition(0,0);
						displayMenu(PLAY, position);
					}
					else
					{
						position = 0;
						System::Console::SetCursorPosition(0,0);
						displayMenu(PLAY, position);
					}
				} 
				else if (mvmtVar2==72 || mvmtVar2==75)
				{
					if(position>0) 
					{
						position--;
						System::Console::SetCursorPosition(0,0);
						displayMenu(PLAY, position);
					}
					else
					{
						position = 2;
						System::Console::SetCursorPosition(0,0);
						displayMenu(PLAY, position);
					}
				}
			}
			else if (mvmtVar1==13)
				break;
		}
	}
	return position;

	
}
void musicChangerMenu ()
{	
	int position = 0;

	system("cls");
	displayMenu(MUSIC, position);

	while(1)
	{
		if(_kbhit())
		{
			int mvmtVar1=_getch();

			if(mvmtVar1==224)
			{
				int mvmtVar2=_getch();	

				if (mvmtVar2==80 || mvmtVar2==77) 
				{
					if(position<4) 
					{
						position++;
						System::Console::SetCursorPosition(0,0);
						displayMenu(MUSIC, position);
					}
					else
					{
						position = 0;
						System::Console::SetCursorPosition(0,0);
						displayMenu(MUSIC, position);
					}
				} 
				else if (mvmtVar2==72 || mvmtVar2==75)
				{
					if(position>0) 
					{
						position--;
						System::Console::SetCursorPosition(0,0);
						displayMenu(MUSIC, position);
					}
					else
					{
						position = 4;
						System::Console::SetCursorPosition(0,0);
						displayMenu(MUSIC, position);
					}
				}
			}
			else if (mvmtVar1==13)
				break;
		}
	}

	PlaySound(0,0,0);

	if (position == MUSIC_POKEMON)
		PlaySound(TEXT("pokemon"), 0, SND_LOOP|SND_ASYNC); 
	else if (position == MUSIC_NIRVANA)
		PlaySound(TEXT("nirvana"), 0, SND_LOOP|SND_ASYNC); 
	else if (position == MUSIC_MOZART)
		PlaySound(TEXT("mozart"), 0, SND_LOOP|SND_ASYNC); 
	else if (position == MUSIC_BEATLES)
		PlaySound(TEXT("beatles"), 0, SND_LOOP|SND_ASYNC); 

}

void colorChangerMenu ()
{
	int position = 0;

	while (1)
	{
		system ("cls");
		displayMenu(COLOR, 0);
		while(1)
		{
			
			
			if(_kbhit())
			{
				int mvmtVar1=_getch();

				if(mvmtVar1==224)
				{
					int mvmtVar2=_getch();	

					if (mvmtVar2==80 || mvmtVar2==77) 
					{
						if(position<5) 
						{
							position++;
							System::Console::SetCursorPosition(0,0);
							displayMenu(COLOR, position);
						}
						else
						{
							position = 0;
							System::Console::SetCursorPosition(0,0);
							displayMenu(COLOR, position);
						}
					} 
					else if (mvmtVar2==72 || mvmtVar2==75)
					{
						if(position>0) 
						{
							position--;
							System::Console::SetCursorPosition(0,0);
							displayMenu(COLOR, position);
						}
						else
						{
							position = 5;
							System::Console::SetCursorPosition(0,0);
							displayMenu(COLOR, position);
						}
					}
				}
				else if (mvmtVar1==13)
					break;
			}
		}

		if (position == COLOR_OPTIONS)
			return;
		else if (position == COLOR_BGCOLOR)
			colorChanger(bgcolor);
		else if (position == COLOR_FGCOLOR)
			colorChanger(fgcolor);
		else if (position == COLOR_PCOLOR)
			colorChanger(pcolor);
		else if (position == COLOR_SCOLOR)
			colorChanger(scolor);
		else if (position == COLOR_DEFAULTS)
		{
			pcolor = System::ConsoleColor::White;
			scolor = System::ConsoleColor::Black;
			bgcolor = System::ConsoleColor::Gray;
			fgcolor = System::ConsoleColor::Blue;
		}
		
		System::Console::BackgroundColor::set(bgcolor);
		position = 0;
	}
}

void colorChanger (System::ConsoleColor &color)
{
	int position = 0;

	system ("cls");
	displayMenu(COLOR_CHOICES, position);

	while(1)
	{
		if(_kbhit())
		{
			int mvmtVar1=_getch();

			if(mvmtVar1==224)
			{
				int mvmtVar2=_getch();	

				if (mvmtVar2==80 || mvmtVar2==77) 
				{
					if(position<6) 
					{
						position++;
						System::Console::SetCursorPosition(0,0);
						displayMenu(COLOR_CHOICES, position);
					}
					else
					{
						position = 0;
						System::Console::SetCursorPosition(0,0);
						displayMenu(COLOR_CHOICES, position);
					}
				} 
				else if (mvmtVar2==72 || mvmtVar2==75)
				{
					if(position>0) 
					{
						position--;
						System::Console::SetCursorPosition(0,0);
						displayMenu(COLOR_CHOICES, position);
					}
					else
					{
						position = 6;
						System::Console::SetCursorPosition(0,0);
						displayMenu(COLOR_CHOICES, position);
					}
				}
			}
			else if (mvmtVar1==13)
				break;
		}
	}

	if (position == 0)
		color = System::ConsoleColor::Black;
	else if (position == 1)
		color = System::ConsoleColor::Blue;
	else if (position == 2)
		color = System::ConsoleColor::Red;
	else if (position == 3)
		color = System::ConsoleColor::Green;
	else if (position == 4)
		color = System::ConsoleColor::Yellow;
	else if (position == 5)
		color = System::ConsoleColor::White;
	else if (position == 6)
		color = System::ConsoleColor::Gray;

}
void summaryChangerMenu ()
{
	int position = 0;

	system("cls");
	displayMenu(SUMMARY, position);

	while(1)
	{
		if(_kbhit())
		{
			int mvmtVar1=_getch();

			if(mvmtVar1==224)
			{
				int mvmtVar2=_getch();	

				if (mvmtVar2==80 || mvmtVar2==77) 
				{
					if(position<1) 
					{
						position++;
						System::Console::SetCursorPosition(0,0);
						displayMenu(SUMMARY, position);
					}
					else
					{
						position = 0;
						System::Console::SetCursorPosition(0,0);
						displayMenu(SUMMARY, position);
					}
				} 
				else if (mvmtVar2==72 || mvmtVar2==75)
				{
					if(position>0) 
					{
						position--;
						System::Console::SetCursorPosition(0,0);
						displayMenu(SUMMARY, position);
					}
					else
					{
						position = 1;
						System::Console::SetCursorPosition(0,0);
						displayMenu(SUMMARY, position);
					}
				}
			}
			else if (mvmtVar1==13)
				break;
		}
	}

	if (position == 0)
		summary = true;
	else 
		summary = false;
}

void help ()
{	
	int position = 0;

	while (1)
	{
		system("cls");
		displayMenu(HELP, 0);
		while(1)
		{
			
			
			if(_kbhit())
			{
				int mvmtVar1=_getch();

				if(mvmtVar1==224)
				{
					int mvmtVar2=_getch();	

					if (mvmtVar2==80 || mvmtVar2==77) 
					{
						if(position<5) 
						{
							position++;
							System::Console::SetCursorPosition(0,0);
							displayMenu(HELP, position);
						}
						else
						{
							position = 0;
							System::Console::SetCursorPosition(0,0);
							displayMenu(HELP, position);
						}
					} 
					else if (mvmtVar2==72 || mvmtVar2==75)
					{
						if(position>0) 
						{
							position--;
							System::Console::SetCursorPosition(0,0);
							displayMenu(HELP, position);
						}
						else
						{
							position = 5;
							System::Console::SetCursorPosition(0,0);
							displayMenu(HELP, position);
						}
					}
				}
				else if (mvmtVar1==13)
					break;
			}
		}

		if (position == HELP_MAIN)
			return;
		else if (position == HELP_ABOUT)
		{
			system ("cls");
			displayMenu(42, HELP_ABOUT);
			cout << "	Made by: Shreyas Chand, Kamil Radecki, and Gloria Jang" << endl;
			cout << "	Class of 2012" << endl;
			cout << "	Company: MCA" << endl;
			cout << "	Year: 2009" << endl;
			cout << "\n\n	Press any key to return..." << endl;
			_getch();
		}
		else if (position == HELP_SPECIAL)
		{
			system ("cls");
			displayMenu(42, HELP_SPECIAL);
			cout << "  Summary" << endl
				 << "  	History of all moves made during a game,        " << endl
				 << "  	saved as a text file in game directory.         " << endl
				 << endl
				 << "  Save/Load Game   " << endl
				 << "  	Store the game as a data file to resume later   " << endl;
			cout << "\n\nPress any key to return..." << endl; 
			_getch();
			System::Console::SetCursorPosition(0, 16);
			cout << "  Color            " << endl
				 << "  	Change the background, foreground, primary     " << endl
				 << "  	and secondary board cell colors to colors of   " << endl
				 << "  	your choice, or restore to predefined defaults " << endl
				 << endl
				 << "  Music            " << endl
				 << "  	Choose a song that best matches your genre     " << endl
				 << "  	preference, or mute it all together.           " << endl;
			cout << "\n\nPress any key to return..." << endl; 
			_getch();
		}

		else if (position == HELP_INPUT)
		{
			system ("cls");
			displayMenu(42, HELP_INPUT);
			cout << "To move a piece enter the column letter and the\n" 
				 << "row number of the current position of the piece you\n"
				 << "want to move. Then enter the position you want to\n" 
				 << "move the piece to. Separate the two locations with\n"
				 << "a space.\n (eg: g7 g5) \nTo confirm the move press enter\n"
				 << "If the move is invalid, you will be asked to retry.\n"
				 << "If you wish to exit the game, enter 'quit' and\n"
				 << "the game will end after asking for a confirmation\n"
				 << " and providing you with the choice to save the game.";
			cout << "\n\nPress any key to return..." << endl;
			_getch();
		}
		else if (position == HELP_MOVES)
		{
			system ("cls");
			displayMenu(42, HELP_MOVES);
			cout << "In chess, there are sixteen pieces and six types of pieces:\n"
				 << "8 pawns, 2 rooks, 2 knights, 2 bishops, 1 queen, and 1 king.\n"
				 << "Each piece has a rule that limits the amount of spaces it can go.";
			cout << "\nPawns are considered the piece of the lowest class.\n"
				 << "Pawns can only move towards the opposite side. They can\n"
				 << "only move one cell at a time, other than on the first move.\n"
				 << "They may only capture on one cell diagnolly.\n";
			cout << "\n\nPress any key to continue..." << endl;
			_getch();
			system ("cls");
			displayMenu(42, HELP_MOVES);
			cout << "Rooks have more power than pawns. Rooks can move horizonally\n"
				 << "and vertically for as many spaces but cannot jump over pieces.\n"
				 << "They can take an enemy's piece if it is in the same row or\n"
				 << "column as the rook without any pieces in between them.\n";
			cout << "Knights have an interesting way of movement. They move in\n"
				 << "what is commonly known as the 'L' shape--three spaces then\n"
				 << "two spaces.  The space the knight is included in this pattern.\n"
				 << "Either they move one row then three columns or they move one\n"
				 << "column and then three rows.\n";
			cout << "\n\nPress any key to continue..." << endl;
			_getch();
			system ("cls");
			displayMenu(42, HELP_MOVES);
			cout << "Unlike rooks, knights can jump over pieces as long as their\n"
				 << "final destination is empty. If an anemy piece is in the space\n"
				 << "of the knight's final destination, it can take it.\n";
			cout << "The two bishops work similar to rooks. However, instead of\n"
				 << "moving row by row or column by column, they move diagonally.\n" 
				 << "They can also move an unlimited amount of spaces but they\n"
				 << "cannot jump over pieces like the rooks.\n";
			cout << "The queen can be seen as the most powerful piece in chess.\n"
				 << "It can be seen as a combination of a rook and a bishop.\n"
				 << "It can move as horizonally, vertically, and diagonally for unlimited spaces";
			cout << "\n\nPress any key to continue..." << endl;
			_getch();
			system ("cls");
			displayMenu(42, HELP_MOVES);
			cout << "Lastly, the king can be seen as the most important piece\n"
				 << "of the game since the player's fate rests on the survival\n"
				 << "of his or her king. The king is not as powerful as the\n"
				 << "queen since it can only move one space in whichever direction.\n"
				 << "The king is more of the life source of the team that\n"
				 << "the pieces must well defend.";
			cout << "\n\nPress any key to return..." << endl;
			_getch();
		}
		else if (position == HELP_BASIC)
		{
			system ("cls");
			displayMenu(42, HELP_BASIC);
			cout << "Chess can be simple to play once you know the rules.\n"
				 << "Basically, it is a two player game that allows each player to move\n" 
				 << "pieces around on the 8X8 chess board until either king is taken.\n";
			cout << "Each player has control over sixteen pieces:\n" 
				 << "8 pawns, 2 rooks, 2 knights, 2 bishops, 1 queen, and 1 king.\n" 
				 << "Each piece has a limit of space it can travel to on the board.\n"  
				 << "For more information on each piece, look under 'Piece Moves'.\n";
			cout << "There are two sides, white and black, and the objective of the game\n"
				 << "is to kill the other team's king.";
			cout << "\n\nPress any key to return..." << endl;
			_getch();
		}
		position = 0;
	}
}