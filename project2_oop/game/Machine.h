#pragma once
#include "Player.h"

class Machine:public Player
{
	int speed = 5;
	int count = 0;
public:
	void Input();//ham Input duoc override khi choi voi may
	Machine() {
		isPlayer = false;
	}
};

