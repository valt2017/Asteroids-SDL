#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>


class Sprite
{
protected:
	std::vector<Sprite *> collSprites;
	int ID;
	int delaySprite;
	int delayCnt;
	int numSprites;
	int activeSprite;
	
public:
	int Degree;
	int dx, dy;
	SDL_Rect rect;
	SDL_Rect rectText;
	int getID(void);
	Sprite(int ID, int x, int y, int w, int h, int numSprites = 1, Sprite * coll = nullptr);
	virtual void addCollision(Sprite * sprite);
	virtual void move(void);
	virtual bool colision(void);
	virtual ~Sprite();
};
