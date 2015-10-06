#pragma once

#ifndef	_GAMEBOARD_
#define _GAMEBOARD_

#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9

using namespace System::Drawing;

public ref class GameBoard
{

	//Can't use enum or int in managed class//can't inclued unmanaged class in managed class.
	//enum {positionFree, green, blue, red, yellow, purple, selected};
	//int board[BOARD_HEIGHT][BOARD_WIDTH];
	
	static int positionFree = 0;
	static array<array<int>^>^ board = gcnew array<array<int>^>(2);

public:
	GameBoard(void);

	void initGameBoard();
	void draw();

	


	
};
#endif