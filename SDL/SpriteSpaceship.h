#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

class SpriteSpaceship : public Sprite
{

public:
	SpriteSpaceship(int ID, int x, int y, int w, int h, int numSprites = 1, Sprite * coll = nullptr);
	bool colision(void) override;
	void keyDOWN_UP(void);
	void keyDOWN_DOWN(void);
	void keyDOWN_LEFT(void);
	void keyDOWN_RIGHT(void);
	void keyUP_UP(void);
	void keyUP_DOWN(void);
	void keyUP_LEFT(void);
	void keyUP_RIGHT(void);
	void move(void) override;
};
