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
	drawSelected(selected);
	//selectedCell =0;
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
	int pX = x;
	int pY = y;
	if(gameboard->checkCellType(x, y) != (int)Shapes::positionFree)
	{
		if(selectedCell == 0)
		{
			selectedCell = new Cell();
		}
		selectedCell->x = x;
		selectedCell->y = y;
	}
	else if(!selectedCell)
	{
		return;
	}
	else
	{
		Cell *b = new Cell();
		b->x = x;
		b->y = y;
		delete b;
		b = 0;
		delete selectedCell;
		selectedCell = 0;
	}


}

void Engine::drawSelected(bool selected)
{
	
	   if(selected && selectedCell !=0) 
	   {
		   draw(selectedCell->x, selectedCell->y);

	   }
}
