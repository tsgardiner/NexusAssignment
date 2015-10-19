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
			board[i,j] = (int)Shapes::positionFree;
		}
	}
}

int GameBoard::checkCellType(int pX, int pY)
{
	
	return (int)board[pX,pY];
	

}