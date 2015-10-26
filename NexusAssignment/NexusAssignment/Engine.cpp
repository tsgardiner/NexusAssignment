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

void Engine::generateBalls()
{
	random = gcnew Random();
	for(int i = 0; i < 3 && gameboard->getNumFreeCells() > 0; i++)
	{
	int type = random->Next(1, 6);
	int point = random->Next(gameboard->getNumFreeCells());
	Cell freeCell = gameboard->getFreeCell(point);
	gameboard->addBall(freeCell.x, freeCell.y, type);
	gameboard->checkLines(freeCell.x, freeCell.y, type);	
	}
	gameboard->updateRollBack();
	gameboard->updateFreeCells();
}


void Engine::selectOrMove(int x, int y)
{


}

void Engine::drawSelected(bool selected)
{
	drawBoard();
	if(selected && selectedCell->X && selectedCell->Y !=0)
	{
		draw(selectedCell->X, selectedCell->Y);
	}
}
