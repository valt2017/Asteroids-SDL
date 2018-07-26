#include "SpriteBoard.h"


SpriteBoard::SpriteBoard(int ID, int x, int y, int w, int h, int numSprites, Sprite * coll) :
	Sprite(ID, x, y, w, h, numSprites, coll)
{
}

bool SpriteBoard::colision(void)
{
	if (collSprites.size() == 0)
		return false;
	return false;
}
