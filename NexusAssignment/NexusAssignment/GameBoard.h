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
typedef array<array<int,2>^> boardsArray;

ref class GameBoard
{
private:
	array<int,2>^ board;
	
	boardsArray^ boardStates;
	static int rollBackCount = 1;

public:

	void initGameBoard();
	int getNumFreeCells();
	Cell getFreeCell(int); 
	int checkCellType(int positionX, int positionY);
	void addBall(int pX, int pY , int type); 
	void deleteLines(std::vector<Cell> toDelete);
	void checkLines(int, int, int);
	void move(Cell, Cell);
	void updateRollBack();
	void boardRollBack();
	void updateFreeCells();
};
#endif