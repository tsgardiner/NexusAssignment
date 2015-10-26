#pragma once
#ifndef _ENGINE_
#define _ENGINE_

#include "GameBoard.h"

using namespace System::Drawing;

static bool selected = false;

ref class Engine
{
private:
	
	GameBoard^ gameboard;
	Graphics^ graphics;	

	void drawBoard();

public:
	Engine(GameBoard ^gb, Graphics ^g);

	void draw(int, int);
	void init();
	void drawSelected(bool selected);
	void selectOrMove(int,int);
	
	Point^ selectedCell;
	

	static array<Bitmap^>^ images = { 
		(Bitmap^)Image::FromFile( "img\\free.png"),
		(Bitmap^)Image::FromFile( "img\\green.png"),
		(Bitmap^)Image::FromFile( "img\\blue.png"),
		(Bitmap^)Image::FromFile( "img\\red.png"),
		(Bitmap^)Image::FromFile( "img\\yellow.png"),
		(Bitmap^)Image::FromFile( "img\\purple.png")
	};


};
#endif