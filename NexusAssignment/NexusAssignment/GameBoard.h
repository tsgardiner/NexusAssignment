#pragma once

#ifndef	_GAMEBOARD_
#define _GAMEBOARD_


#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9
#define IMG_SIZE 40

#include <vector>  

using namespace System;
using namespace System::Collections;
using namespace System::Drawing; //Needed to use Point.

enum class Shapes {positionFree, green, blue, red, yellow, purple, selected};

struct Cell
{
	int x;
	int y;
};

static std::vector<Cell> lineToDelete;
static std::vector<Cell> freeCells;

ref class GameBoard
{
private:
	array<int,2>^ board;

public:

	void initGameBoard();
	int checkCellType(int positionX, int positionY);
	void addBall(int pX, int pY , int type);

	//Delete lines ideas that didn't work
	void deleteLines(std::vector<Cell> toDelete);
	void checkLines(int, int, int);
	//array<Point^>^ line;
	//void deleteLines(array<int, 2>^ line);	
	//array<int, 2>^ line;

};
#endif