#include "StdAfx.h"
#include "Engine.h"



Engine::Engine(GameBoard ^gb, Graphics^ g)
{
	this->gameboard = gb;
	this->graphics = g;	

	

}

void Engine::start()
{
	gameboard->initGameBoard();
	drawBoard();
}

void Engine::draw(int pX, int pY)
{
	TextureBrush^ texture = gcnew TextureBrush(images[gameboard->checkCellType(pX, pY)]);
	graphics->FillRectangle(texture, pX * IMG_SIZE, pY * IMG_SIZE, IMG_SIZE, IMG_SIZE);
	delete texture;
	//((Image^)images[(int)Shapes::positionFree], pX, pY);
}

void Engine::drawBoard()
{
	for(int i = 0; i < BOARD_HEIGHT; i++)
	{
		for(int j = 0; j < BOARD_WIDTH; j++)
		{
				int pj = j;
				int pi = i;
				draw(pj, pi);			
		}
	}
	
}


