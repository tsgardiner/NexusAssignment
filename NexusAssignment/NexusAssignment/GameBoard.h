#pragma once

#ifndef	_GAMEBOARD_
#define _GAMEBOARD_


#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9
#define IMG_SIZE 40

#include <vector>  //Can't use vectors in or with managed anything.

using namespace System;
using namespace System::Collections;
using namespace System::Drawing; //Needed to use Point.

enum class Shapes {positionFree, green, blue, red, yellow, purple, selected};

struct Cell
{
	int x;
	int y;
};

ref class GameBoard
{
private:
	array<int,2>^ board;

public:
	GameBoard(void);

	void initGameBoard();
	int checkCellType(int positionX, int positionY);
	void addBall(int pX, int pY , int type);
	//array<Cell>^ freeCells;  //Can't use unmanaged struct in managed class or array



	//Delete lines ideas that didn't work
	//void deleteLines(array<Point^>^ line);
	//array<Point^>^ line;
	//void deleteLines(array<int, 2>^ line);
	//void checkLines(int, int, int);
	//array<int, 2>^ line;

};
#endif