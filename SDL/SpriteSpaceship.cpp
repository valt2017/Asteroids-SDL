#include "SpriteSpaceship.h"

SpriteSpaceship::SpriteSpaceship(int ID, int x, int y, int w, int h, int numSprites, Sprite * coll) :
	Sprite(ID, x, y, w, h, numSprites, coll)
{
	activeSprite = 1;
}

bool SpriteSpaceship::colision(void)
{
	if (collSprites.size() == 0)
		return false;
	// Spaceship -> board colision
//	if (SDL_HasIntersection(collSprite->getRect(), getRect())) {
//		collSprite->dy = -collSprite->dy;
//		return true;
//	}
	return false;
}

void SpriteSpaceship::keyDOWN_UP(void) 
{
	if (rect.y > 0)
		rect.y -= 10;
	rectText.y = rectText.h;
}

void SpriteSpaceship::keyDOWN_DOWN(void) 
{
	if (rect.y < collSprites[0]->rect.h - rect.h)
		rect.y += 10;
	rectText.y = 0;
}

void SpriteSpaceship::keyDOWN_LEFT(void) 
{
	if (rect.x > 0)
		rect.x -= 10;
	activeSprite = 0;
}

void SpriteSpaceship::keyDOWN_RIGHT(void) 
{
	if (rect.x < collSprites[0]->rect.w - rect.w)
		rect.x += 10;
	activeSprite = 2;
}

void SpriteSpaceship::keyUP_UP(void)
{
	if (rectText.y == rectText.h)
		rectText.y = 0;
}

void SpriteSpaceship::keyUP_DOWN(void)
{
}

void SpriteSpaceship::keyUP_LEFT(void)
{
	if (activeSprite == 0)
		activeSprite = 1;
}

void SpriteSpaceship::keyUP_RIGHT(void)
{
	if (activeSprite == 2)
		activeSprite = 1;
}

void SpriteSpaceship::move(void) 
{
	rectText.x = activeSprite * rectText.w;
}