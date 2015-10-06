#include "StdAfx.h"
#include "GameBoard.h"


  

GameBoard::GameBoard(void)
{  	
	initGameBoard();

	
}

void GameBoard::initGameBoard()
{
	for(int i =0; i < BOARD_HEIGHT; i++)
	{
		for(int j = 0; j < BOARD_WIDTH; j++)
		{
			board[i][j] = positionFree;
		}
	}
}




void GameBoard::draw()
{
	
}
