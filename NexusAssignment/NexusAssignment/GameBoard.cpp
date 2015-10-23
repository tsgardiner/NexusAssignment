#include "StdAfx.h"
#include "GameBoard.h"
#include "Engine.h"

void GameBoard::initGameBoard()
{
	board = gcnew array<int,2>(BOARD_HEIGHT ,BOARD_WIDTH);
	for(int i =0; i < BOARD_HEIGHT; i++)
	{
		for(int j = 0; j < BOARD_WIDTH; j++)
		{
			board[i,j] = (int)Shapes::positionFree;
			Cell ball = {i, j};
			freeCells.push_back(ball);
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

//Check for lines around added ball and call delete if there is a line of five.
void GameBoard::checkLines(int x, int y, int type)
{
	lineToDelete.clear();
	int count =0;
	int pY, pX;

	//Down
	pY = y - 1;
	while((pY >= 0) && (type == checkCellType(x, pY)))	
	{  	
		Cell ball = {x , pY};
		lineToDelete.push_back(ball);
		count++;
		pY--; 
	}
	//Up
	pY = y + 1;
	while((pY < BOARD_WIDTH) && (type == checkCellType(x , pY)))
	{
		Cell ball = {x , pY};
		lineToDelete.push_back(ball);
		count++;
		pY++;
	}
	if (count < 4)	lineToDelete.resize(lineToDelete.size() - count);
	count =0 ;  

	//Right
	pX = x - 1;
	while((pX >= 0) && (type == checkCellType(pX, y)))
	{
		Cell ball = {pX , y};
		lineToDelete.push_back(ball);
		count++;
		pX--;
	}
	//Left
	pX = x + 1;
	while((pX < BOARD_WIDTH) && (type == checkCellType(pX, y)))
	{
		Cell ball = {pX , y};
		lineToDelete.push_back(ball);
		count++;
		pX++;
	}
	if (count < 4)	lineToDelete.resize(lineToDelete.size() - count);
	count = 0;

	//DownRight
	pY = y - 1; 
	pX = x - 1;
	while((pX >=0) && (pY >=0) && (type == checkCellType(pX, pY)))
	{
		Cell ball = {pX, pY};
		lineToDelete.push_back(ball);
		count++;
		pY--;
		pX--;
	}
	//UpLeft
	pY = y + 1; 
	pX = x + 1;
	while((pX < BOARD_WIDTH) && (pY < BOARD_WIDTH) && (type == checkCellType(pX, pY)))
	{
		Cell ball = {pX, pY};
		lineToDelete.push_back(ball);
		count++;
		pY++;
		pX++;
	}

	if(count < 4) lineToDelete.resize(lineToDelete.size() - count);
	count = 0;
	
	//DownLeft 
	pY = y - 1; 
	pX = x + 1;
	while((pX < BOARD_WIDTH) && (pY >=0) && (type == checkCellType(pX, pY)))
	{
		Cell ball = {pX, pY};
		lineToDelete.push_back(ball);
		count++;
		pY--;
		pX++;
	}
	//UpRight
	pY = y + 1; 
	pX = x - 1;
	while((pX >=0) && (pY < BOARD_WIDTH) && (type == checkCellType(pX, pY)))
	{
		Cell ball = {pX, pY};
		lineToDelete.push_back(ball);
		count++;
		pY++;
		pX--;
	}

	if(count < 4) lineToDelete.resize(lineToDelete.size() - count);
	count = 0;

	if(lineToDelete.size() > 0)
	{
		Cell ball = { x, y };
		lineToDelete.push_back(ball);
		deleteLines(lineToDelete);
	}
}

  
void GameBoard::deleteLines(std::vector<Cell> toDelete)
{	
	for(unsigned int i =0; i < toDelete.size(); i++)
	{
		board[toDelete[i].x, toDelete[i].y] = (int)Shapes::positionFree;
		freeCells.push_back(toDelete[i]);
	} 
	

}	