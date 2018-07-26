#include "SpriteBullet.h"

SpriteBullet::SpriteBullet(int ID, int x, int y, int w, int h, int numSprites, Sprite * coll) :
	Sprite(ID, x, y, w, h, numSprites, coll)
{
	dy = -5;
}

bool SpriteBullet::colision(void)
{
	if (collSprites.size() == 0)
		return false;
	if (rect.y <= 0) {
		rect.y = 0;
		return true;
	}
	return false;
}

void SpriteBullet::move(void)
{
	rect.x += dx;
	rect.y += dy;
	if (activeSprite < numSprites)
		activeSprite++;
	else
		activeSprite = 0;
	rectText.x = activeSprite * rectText.w;
}