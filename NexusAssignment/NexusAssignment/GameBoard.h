#pragma once

#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9


class GameBoard
{
public:
	GameBoard(void);



private:
	enum {positionFree, green, blue, red, yellow, purple, selected};
	int board[BOARD_HEIGHT][BOARD_WIDTH];

};
