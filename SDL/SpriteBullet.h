#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

class SpriteBullet : public Sprite
{
public:
	SpriteBullet(int ID, int x, int y, int w, int h, int numSprites = 1, Sprite * coll = nullptr);
	bool colision(void) override;
	void move(void) override;
};
