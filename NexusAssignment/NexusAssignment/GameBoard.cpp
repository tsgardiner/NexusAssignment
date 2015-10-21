#include "StdAfx.h"
#include "GameBoard.h"
#include "Engine.h"



GameBoard::GameBoard(void)
{  	
	
}

void GameBoard::initGameBoard()
{
	board = gcnew array<int,2>(BOARD_HEIGHT ,BOARD_WIDTH);
	for(int i =0; i < BOARD_HEIGHT; i++)
	{
		for(int j = 0; j < BOARD_WIDTH; j++)
		{
			board[j,i] = (int)Shapes::positionFree;
		}
	}
}

int GameBoard::checkCellType(int pX, int pY)
{  	
	return board[pX,pY];
}

void GameBoard::addBall(int pX, int pY, int type)
{	
	board[pX,pY] = type;
}

//Keeps throwing out of bounds
//void GameBoard::checkLines(int x , int y , int type)
//{
//	int count = 0;
//	if((board[x, y-1] == type) && (y -1 >=0)) count++;
//	if(board[x, y -2] == type && y -2 >=0) count++;

//}

/* Tried int array instead of Point^ didn't work either.
void GameBoard::checkLines(int x, int y, int c)
{
	int count = 0;	
	//line = gcnew array<Point^>(count);
	line = gcnew array<int,2>(BOARD_HEIGHT, BOARD_WIDTH);
	
	int pX, pY;	 	
	
	//Left
	pY = y - 1;
	while(board[x,pY] == c && pY >=0)
	{
		line[count, count] = (x, pY);
		count++;
	}
	if(count > 5)
	{
		//deleteLines(line);
	}

	

}

void GameBoard::deleteLines(cli::array<int,2> ^line)
{
	for(int i = 0; i < line->Length; i++)
	{
		//board[line[i,i]

	} 
}	*/ 

	/*Nothing works trying something else
	//Left
	pY = y -1;
	while(board[x,pY] == c && pY >= 0)
	{
		p = gcnew Point(x, pY);
		line[count] = p;
		count++;
		pY--;
	}
	//Right
	pY = y + 1;
	while(board[x, pY] == c && pY < BOARD_WIDTH)
	{
		p = gcnew Point(x, pY);
		line[count] = p;
		count++;
		pY++;
	}

	if (count < 4)	
	{
		while(count>0)
		{
			deleteLines(line[count]);
		}
		count--;
	} 


  Nothing works trying something else
  void GameBoard::deleteLines(array<Point^>^ line)
{	
	for(int i =0; i < line->Length; i++)
	{
		board[line[i]->X, line[i]->Y] = (int)Shapes::positionFree;		
	} 
	//board[point->X, point->Y] = (int)Shapes::positionFree;

}	*/ 