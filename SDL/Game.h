#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "SpriteBoard.h"
#include "SpriteRock.h"
#include "SpriteBullet.h"
#include "SpriteSpaceship.h"
#include "SpriteExplosion.h"

class Game
{
	SDL_Renderer * gameRenderer;
	std::vector<SDL_Texture *> Textures;
	std::vector<Sprite *> sprites;

public:
	enum { BOARD = 0, SPACESHIP, ROCK, BULLET, EXPLOSION };
	Game(SDL_Renderer * renderer, SDL_Rect & rect);
	bool LoadBitmap(const char * file);
	bool Game::DrawScreen(void);
	void Game::Input(SDL_Event & e);
	~Game();
};

