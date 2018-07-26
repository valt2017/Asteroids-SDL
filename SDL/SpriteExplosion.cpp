#include "SpriteExplosion.h"

SpriteExplosion::SpriteExplosion(int ID, int x, int y, int w, int h, int numSprites, Sprite * coll) :
	Sprite(ID, x, y, w, h, numSprites, coll)
{ // Random degree, random start and delay of the animation
	Degree = rand() % 360;
	delaySprite = 8;
}

bool SpriteExplosion::colision(void)
{
	if (collSprites.size() == 0)
		return false;
	// not colision, but not valid after end of animation
	if (activeSprite < numSprites)
		return false;
	return true;
}

void SpriteExplosion::move(void)
{
	delayCnt++;
	if (delayCnt >= delaySprite) {
		delayCnt = 0;
		return;
	}
	if (activeSprite++ < numSprites)
		rectText.x = activeSprite * rectText.w;
}

