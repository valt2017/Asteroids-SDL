#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

class SpriteBoard : public Sprite
{
public:
	SpriteBoard(int ID, int x, int y, int w, int h, int numSprites = 1, Sprite * coll = nullptr);
	bool colision(void) override;
};

