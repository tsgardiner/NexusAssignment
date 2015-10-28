#pragma once
#ifndef _ENGINE_
#define _ENGINE_

#include "GameBoard.h"

using namespace System::Drawing;

static bool selected;


ref class Engine
{
private:
	
	GameBoard^ gameboard;
	Graphics^ graphics;
	Random^ random;
	//Point^ selectedCell;   Tried using type Point^ it just doesn't work for anything and can't be set to 0.
	

	void drawBoard();

public:
	Engine(GameBoard ^gb, Graphics ^g);

	void draw(int, int);
	void init();
	void drawSelected(bool selected);
	void selectOrMove(int, int);
	void generateBalls();
	Cell *selectedCell;
	
	static array<Bitmap^>^ images = { 
		(Bitmap^)Image::FromFile( "img\\free.png"),
		(Bitmap^)Image::FromFile( "img\\green.png"),
		(Bitmap^)Image::FromFile( "img\\blue.png"),
		(Bitmap^)Image::FromFile( "img\\red.png"),
		(Bitmap^)Image::FromFile( "img\\yellow.png"),
		(Bitmap^)Image::FromFile( "img\\purple.png"),
		(Bitmap^)Image::FromFile( "img\\selected.png")
	};


};
#endif