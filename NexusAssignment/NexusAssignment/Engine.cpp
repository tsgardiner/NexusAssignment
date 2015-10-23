#include "StdAfx.h"
#include "Engine.h"



Engine::Engine(GameBoard ^gb, Graphics^ g)
{
	this->gameboard = gb;
	this->graphics = g;	
	
	gameboard->initGameBoard();
}

void Engine::init()
{
	drawBoard();
}

void Engine::draw(int pX, int pY)
{
	TextureBrush^ texture = gcnew TextureBrush(images[gameboard->checkCellType(pX, pY)]);
	graphics->FillRectangle(texture, pX * IMG_SIZE, pY * IMG_SIZE, IMG_SIZE, IMG_SIZE);
	delete texture;
}

void Engine::drawBoard()
{
	for(int i = 0; i < BOARD_HEIGHT; i++)
	{
		for(int j = 0; j < BOARD_WIDTH; j++)
		{
			draw(i, j);			
		}
	}	
}


void Engine::selectOrMove(int x, int y)
{


}

void Engine::draw(bool selected)
{
	drawBoard();
	if(selected && selectedCell->X && selectedCell->Y !=0)
	{
		draw(selectedCell->X, selectedCell->Y);
	}
}
