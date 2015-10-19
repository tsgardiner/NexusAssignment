#pragma once

#ifndef	_GAMEBOARD_
#define _GAMEBOARD_


#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9
#define IMG_SIZE 40

public enum class Shapes {positionFree, green, blue, red, yellow, purple, selected};

public ref class GameBoard
{
private:
	array<int,2>^ board; 

public:
	GameBoard(void);

	void initGameBoard();
	int checkCellType(int positionX, int positionY);


};
#endif