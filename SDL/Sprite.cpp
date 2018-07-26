#include "Sprite.h"

Sprite::Sprite(int ID, int x, int y, int w, int h, int numSprites, Sprite * coll)
{
	this->numSprites = numSprites;
	this->rect.x = x;
	this->rect.y = y;
	this->dx = 0;
	this->dy = 0;
	this->activeSprite = 0;
	this->rect.h = h;
	this->rect.w = w;
	this->ID = ID;
	this->rectText = { 0, 0, w, h };
	this->Degree = 0;
	this->delayCnt = 0;
	this->delaySprite = 0;
	if (coll != nullptr)
		collSprites.push_back(coll);
}

int Sprite::getID(void)
{
	return ID;
}

void Sprite::addCollision(Sprite * sprite)
{
	collSprites.push_back(sprite);
}

bool Sprite::colision(void) 
{
	return false;
	//return SDL_HasIntersection(&getRect(), &rect);
}

void Sprite::move(void)
{

}

Sprite::~Sprite()
{
	collSprites.clear();
}
