#pragma once
#include "Player.h"

class Machine:public Player
{
	float speed = 0;//toc do di chuyen cua may
	int maxLevel = 10;//so man toi da
	int level = 1;;//man hien tai
public:
	void Input();//ham Input duoc override khi choi voi may
	void Logic();//override ham logic

	Machine() {//ham khoi tao
		isPlayer = false;
	}

	void saveGame();
	void loadGame(string path);
};

