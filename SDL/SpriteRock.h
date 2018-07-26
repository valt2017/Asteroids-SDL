#pragma once
#include <iostream>
#include <SDL.h>
#include "Sprite.h"

class SpriteRock : public Sprite
{
public:
	SpriteRock(int ID, int x, int y, int w, int h, int numSprites = 1, Sprite * coll = nullptr);
	bool colision(void) override;
	void move(void) override;
};
