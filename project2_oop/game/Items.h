#pragma once
#include "Ball.h"
#include "paddle.h"
#include <stdlib.h>
#include <time.h>

const int numTypeItems = 6;

class Items
{
protected:
	string name;
	char shape;

	int x, x0;
	int y, y0;

	eDir direction;
	bool isExistent = true;

public:
	Items() {
		x = x0 = WidthGame / 2;
		y = y0 = 1 + rand() % (HeightGame - 1);

		direction = (rand() % 2) ? eDir::LEFT : eDir::RIGHT;
	}

	void setExistent(bool flag) {
		isExistent = flag;
	}

	bool getExistentItems() {
		return isExistent;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void existentItems(Ball* ball);
	void drawItems();

	virtual void attributeItems(cPaddle* player1, cPaddle* player2){}
};


class DoubleScore :public Items {
public:
	DoubleScore() {
		name = "Double Score";
		shape = 'D';
	}

	void attributeItems(cPaddle* player1, cPaddle* player2) {// gap doi diem
		player1->setScore(player1->getScore() * 2);
	}
};

class HalfScore :public Items {
public:
	HalfScore() {
		name = "Half Score";
		shape = 'H';
	}

	void attributeItems(cPaddle* player1, cPaddle* player2) {// giam 1 nua diem
		player1->setScore(player1->getScore() / 2);
	}
};

class FasterSpeed :public Items {
public:
	FasterSpeed() {
		name = "Faster";
		shape = 'F';
	}

	void attributeItems(cPaddle* player1, cPaddle* player2) {// tang toc do nguoi choi
		player1->setSpeed(player1->getSpeed() + 1);
	}
};

class SlowerSpeed :public Items {
public:
	SlowerSpeed() {
		name = "Slower Speed";
		shape = 'S';
	}

	void attributeItems(cPaddle* player1, cPaddle* player2) {// giam toc do nguoi choi
		player1->setSpeed(player1->getSpeed() - 1);
	}
};

class LongLength :public Items {
public:
	LongLength() {
		name = "Long Length";
		shape = 'L';
	}

	void attributeItems(cPaddle* player1, cPaddle* player2) { // tang chieu dai thanh truot
		player1->setMaxbar(player1->getMaxBarPlayer() + 2);
	}
};

class ShortLength :public Items {
public:
	ShortLength() {
		name = "Short Length";
		shape = 's';
	}

	void attributeItems(cPaddle* player1, cPaddle* player2) { // giam chieu dai thanh truot
		player1->setMaxbar(player1->getMaxBarPlayer() - 2);
	}

};

Items* createItems();
