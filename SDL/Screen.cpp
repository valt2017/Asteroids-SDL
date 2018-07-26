#include "Screen.h"

Screen::Screen(const char * title, const SDL_Rect & rect)
{
	this->screenRect = rect;
	srand(time(0));
	std::cout << "SDL_Init\n";
	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow(title, rect.x + 50, rect.y + 50, rect.w, rect.h, 0);
	if (win == nullptr) {
		std::cerr << "SDL_CreateWindow error\n";
	}
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		std::cerr << "SDL_CreateRenderer error\n";
	}
	game = new Game(renderer, screenRect);
	if (game == nullptr) {
		std::cerr << "Game could not be created\n";
	}
}

bool Screen::LoadBitmap(const char * file) 
{
	return game->LoadBitmap(file);
}


void Screen::DisplayLoop(void)
{
	while (!finish) {
		start = SDL_GetTicks();
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				finish = true;
				break;
			}
			// Look for a keypress
			if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
				game->Input(e);
		}
		finish = game->DrawScreen();
		// Animation
		if (ANIMATION_DELAY / FPS > SDL_GetTicks() - start)
			SDL_Delay(ANIMATION_DELAY / FPS - (SDL_GetTicks() - start));
	}
}

Screen::~Screen()
{
	delete game;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
	std::cout << "SDL_Quit\n";
}
