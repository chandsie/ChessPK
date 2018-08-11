#include "../ChessFuncts.h"

void initBoard (cell board[8][8], ifstream &file) 
{
	string temp;

	for (int i=0;i!=8;i++) 
	{
		if (i%2==0) 
			for (int ii=0;ii!=8;ii++) 
				if(ii%2==0) 
					board[i][ii].color= true; 
				else
					board[i][ii].color= false; 
		else
			for (int ii=0;ii!=8;ii++) 
				if(ii%2==0)
					board[i][ii].color= false; 
				else 
					board[i][ii].color= true;	
	}

	for(int i=0;i!=8;i++) 
		for(int ii=0;ii!=8;ii++) 
			board[i][ii].piece="";

	for (int i=0;i!=8;i++) 
		for (int ii=0;ii!=8;ii++) 	
		{
			file >> temp;
			if(temp=="bb")
				temp="";
			board[i][ii].piece=temp;
		}

	for(int i=0;i!=8;i++) 
		for(int ii=0;ii!=8;ii++) 
			if (board[i][ii].piece!="") 
				board[i][ii].occupied= true; 
			else 
				board[i][ii].occupied= false;
}

void initBoard (cell board[8][8]) 
{
	for (int i=0;i!=8;i++) 
	{
		if (i%2==0) 
			for (int ii=0;ii!=8;ii++) 
				if(ii%2==0) 
					board[i][ii].color= true; 
				else
					board[i][ii].color= false; 
		else
			for (int ii=0;ii!=8;ii++) 
				if(ii%2==0)
					board[i][ii].color= false; 
				else 
					board[i][ii].color= true;	
	}

	for(int i=0;i!=8;i++) 
		for(int ii=0;ii!=8;ii++) 
			board[i][ii].piece=""; 

	for(int i=0;i<8;i++) 
		if (i==0) 
			for (int ii=0;ii!=8;ii++) 
				if (ii==0 || ii==7) 
					board[i][ii].piece= "bR"; 
				else if (ii==1 || ii==6) 
					board[i][ii].piece= "bN"; 
				else if (ii==2 || ii==5) 
					board[i][ii].piece="bB"; 
				else if (ii==3) 
					board[i][ii].piece="bQ"; 
				else
					board[i][ii].piece="bK"; 
		else if (i==1)
			for (int ii=0;ii!=8;ii++) 
				board[i][ii].piece="bP"; 
		else if (i==6) 
			for (int ii=0;ii!=8;ii++) 
				board[i][ii].piece="wP"; 
		else if (i==7) 
			for (int ii=0;ii!=8;ii++) 
				if (ii==0 || ii==7) 
					board[i][ii].piece="wR"; 
				else if (ii==1 || ii==6) 
					board[i][ii].piece="wN"; 
				else if (ii==2 || ii==5) 
					board[i][ii].piece="wB"; 
				else if (ii==3)
					board[i][ii].piece="wQ";
				else 
					board[i][ii].piece="wK"; 
	
	for(int i=0;i!=8;i++) 
		for(int ii=0;ii!=8;ii++) 
			if (board[i][ii].piece!="") 
				board[i][ii].occupied= true; 
			else 
				board[i][ii].occupied= false; 
}
