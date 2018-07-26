#pragma once
#include "Sprite.h"

class SpriteExplosion : public Sprite
{
public:
	SpriteExplosion(int ID, int x, int y, int w, int h, int numSprites = 1, Sprite * coll = nullptr);
	bool colision(void) override;
	void move(void) override;
};

