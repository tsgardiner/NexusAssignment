#include <SDL.h>
#include <stdio.h>


class Builder
{
public:
	Builder();


	void closeALL();
	const int getScreenHeight();
	const int getScreenWidth();

	
private:
	const int SCREEN_HEIGHT = 400;
	const int SCREEN_WIDTH = 600;
	
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool init();
};

