#include "SpriteRock.h"

SpriteRock::SpriteRock(int ID, int x, int y, int w, int h, int numSprites, Sprite * coll) :
	Sprite(ID, x, y, w, h, numSprites, coll)
{ // Random degree, random start and delay of the animation
	activeSprite = rand() % numSprites;
	Degree = rand() % 360;
	delaySprite = rand() % 10;
	dy = 1 + rand() % 2;
}

bool SpriteRock::colision(void)
{
	if (collSprites.size() == 0)
		return false;
	// colision
	for(int i = 0; i < collSprites.size(); i++)
		if(collSprites[i] != nullptr)
			if (SDL_HasIntersection(&collSprites[i]->rect, &rect))
				return true;
	return false;
}

void SpriteRock::move(void) 
{
//	std::cout << delayCnt << " " << delaySprite << " " << activeSprite <<  std::endl;
	rect.x += dx;
	rect.y += dy;
	// !!! fixed nums
	if (rect.y > 600) {
		rect.y = 0;
		rect.x = rand() % 1200;
	}
	delayCnt++;
	if (delayCnt >= delaySprite) {
		delayCnt = 0;
		return;
	}
	activeSprite++;
	if (activeSprite >= numSprites)
		activeSprite = 0;
	rectText.x = activeSprite * rectText.w;
}
