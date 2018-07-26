#include "Game.h"

Game::Game(SDL_Renderer * renderer, SDL_Rect & rect)
{
	gameRenderer = renderer;
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		std::cerr << "SDL_image could not initialize! SDL_image Error:" << IMG_GetError() << std::endl;
	}
	sprites.push_back(new SpriteBoard(BOARD, rect.x, rect.y, rect.w, rect.h));
	sprites.push_back(new SpriteSpaceship(SPACESHIP, rect.w / 2, rect.h / 2, 40, 40, 1, sprites[BOARD]));
	for (int i = 0; i < 15; i++)
		sprites.push_back(new SpriteRock(ROCK, rand() % rect.w, rand() % rect.h, 64, 64, 16, sprites[SPACESHIP]));
}

bool Game::LoadBitmap(const char * file)
{
	SDL_Texture *texture = IMG_LoadTexture(gameRenderer, file);
	if (texture == nullptr) {
		std::cerr << file << " SDL_CreateTextureFromSurface error\n";
		return false;
	}
	else {
		std::cout << file << " SDL_CreateTextureFromSurface OK\n";
		Textures.push_back(texture);
	}
	return true;
}

bool Game::DrawScreen()
{
	SDL_RenderClear(gameRenderer);
	for (auto sprite = sprites.begin(); sprite != sprites.end();) {
		SDL_RenderCopyEx(gameRenderer, Textures[(*sprite)->getID()], &(*sprite)->rectText, &(*sprite)->rect, (*sprite)->Degree, nullptr, SDL_FLIP_NONE);
		(*sprite)->move();
		if ((*sprite)->colision()) {
			if ((*sprite)->getID() == ROCK) {
				sprites.push_back(new SpriteExplosion(EXPLOSION, (*sprite)->rect.x, (*sprite)->rect.y, 50, 50, 20, sprites[SPACESHIP]));
			}
			delete *sprite;
			sprite = sprites.erase(sprite);
		}
		else
			++sprite;
	}
	SDL_RenderPresent(gameRenderer);
	// All rocks, bullets and explosion removed ?
	if (sprites.size() == 2)
		return true;
	return false;
}

void Game::Input(SDL_Event & e)
{
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym) {
		case SDLK_SPACE:
			sprites.push_back(new SpriteBullet(BULLET, sprites[SPACESHIP]->rect.x, sprites[SPACESHIP]->rect.y, 32, 64, 16, sprites[BOARD]));
			for (auto sprite = sprites.begin(); sprite != sprites.end(); sprite++)
				if ((*sprite)->getID() == ROCK)
					(*sprite)->addCollision(sprites.back());
			break;
		case SDLK_UP:
			static_cast<SpriteSpaceship*>(sprites[SPACESHIP])->keyDOWN_UP();
			break;
		case SDLK_DOWN:
			static_cast<SpriteSpaceship*>(sprites[SPACESHIP])->keyDOWN_DOWN();
			break;
		case SDLK_LEFT:
			static_cast<SpriteSpaceship*>(sprites[SPACESHIP])->keyDOWN_LEFT();
			break;
		case SDLK_RIGHT:
			static_cast<SpriteSpaceship*>(sprites[SPACESHIP])->keyDOWN_RIGHT();
			break;
		default:
			std::cout << "Key not supported" << std::endl;
			break;
		}
	}
	if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.sym) {
		case SDLK_UP:
			static_cast<SpriteSpaceship*>(sprites[SPACESHIP])->keyUP_UP();
			break;
		case SDLK_DOWN:
			static_cast<SpriteSpaceship*>(sprites[SPACESHIP])->keyUP_DOWN();
			break;
		case SDLK_LEFT:
			static_cast<SpriteSpaceship*>(sprites[SPACESHIP])->keyUP_LEFT();
			break;
		case SDLK_RIGHT:
			static_cast<SpriteSpaceship*>(sprites[SPACESHIP])->keyUP_RIGHT();
			break;
		}
	}
}

Game::~Game()
{
	for (auto sprite : sprites)
		delete sprite;
	sprites.clear();
	for (auto texture : Textures)
		SDL_DestroyTexture(texture);
	Textures.clear();
	IMG_Quit();
	std::cout << "Game Quit\n";
}
