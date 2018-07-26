#include <iostream>
#include <fstream>
#include "Screen.h"

// Ported by @valt to SDL from https://www.youtube.com/user/FamTrinli asteroids tutorial in SFML
// Added classes for studying purposes...

const SDL_Rect screenSize = { 0, 0, 1200, 600 };

int main(int argc, char ** argv) {
	Screen screen("Asteroids", screenSize);
	// Load bitmaps
	screen.LoadBitmap("img/background.png");
	screen.LoadBitmap("img/spaceship.png");
	screen.LoadBitmap("img/rock.png"); // img/rock.png
	screen.LoadBitmap("img/fire_red.png");
	screen.LoadBitmap("img/explosions/type_A.png");
	// Screen displaying loop
	screen.DisplayLoop();
	return 0;
}