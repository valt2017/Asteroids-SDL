#pragma once
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

class Screen
{
	const int FPS = 60;
	const int ANIMATION_DELAY = 1000;
	bool finish = false;
	SDL_Window *win = nullptr;
	SDL_Renderer *renderer = nullptr;
	SDL_Rect screenRect = {0, 0, 0, 0};
	Uint32 start = 0;
	Game * game = nullptr;
	
public:
	bool LoadBitmap(const char * file);
	void DisplayLoop(void);
	Screen(const char * title, const SDL_Rect & rect);
	~Screen();
};

