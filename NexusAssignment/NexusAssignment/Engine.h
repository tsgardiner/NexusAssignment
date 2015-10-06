#pragma once
#ifndef _ENGINE_
#define _ENGINE_

#include "GameBoard.h"

using namespace System::Drawing;

public ref class Engine
{
	GameBoard gameboard;

	static array<Image^>^ images = { 
		(Image^)Image::FromFile( "img\\free.png"),
		(Image^)Image::FromFile( "img\\greed.png"),
		(Image^)Image::FromFile( "img\\blue.png"),
		(Image^)Image::FromFile( "img\\red.png"),
		(Image^)Image::FromFile( "img\\yellow.png"),
		(Image^)Image::FromFile( "img\\purple.png")
	};
	
	static void imageLoader();

public:
	Engine(GameBoard gameboard);

	static void initEngine();

	
	

};
#endif