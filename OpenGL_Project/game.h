#ifndef GAME_H
#define GAME_H
#include "mario.h"
#include "goomba.h"
#include <iostream>
#include "World.h"
#include "background.h"


struct Game {
	//static void upKey(unsigned char, int, int);
	static void mouse(int, int, int, int);
	bool checkPos(Mario* obj, World* obj2);
	bool checkH(Mario* obj, World* obj2);
	bool touch(Mario* obj, Goomba* obj2);
	void run();
	void load();
	Game(int);
	float vel = 0.0;
	float vel2 = 0.0;
	float vel3 = 0.0;
	float grav = 0.0;
	float landy = 0.0;
	bool up = false;
	bool down = false;
	bool right = true;
	bool jump = true;

	Mario* good;
	Goomba* bad;
	World* plat;
	World* plat2;
	Background* back;
};
#endif