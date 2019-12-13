#pragma once
#include "Ball.h"
#include "paddle.h"
#include <stdlib.h>
#include <time.h>

const int numTypeItems = 8;
const int nameSize = 15;

class Items
{
protected:
	bool isBarrier = false;
	char shape;//hinh dang

	int x;
	int y;

	bool isExistent = true;//flag vat pham con ton tai

public:
	
	Items(int x, int y) {//ham khoi tao
		this->x = x;
		this->y = y;
	}

	void setExistent(bool flag) {//cat dat flag vat pham ton tai
		isExistent = flag;
	}

	bool getExistentItems() {//lay flag vat pham ton tai
		return isExistent;
	}

	int getX() {//vi tri x
		return x;
	}

	int getY() {//vi tri y
		return y;
	}

	bool checkBarrier() {
		return isBarrier;
	}

	virtual void existentItems(Ball* ball);//ham xac dinh vat pham co va cham vs bong
	void drawItems();//ve vat pahm

	virtual void attributeItems(cPaddle* player){}//tinh chat cua moi vat pham

	void clear() {//xoa vat pham tren man hinh
		gotoxy(x, y);
		cout << " ";
	}

	//string getNameItem() {//ten vat pham
	//	return name;
	//}

	void saveInfo(ofstream& out);
};


class DoubleScore :public Items {
public:
	DoubleScore(int x, int y):Items(x,y) {
		shape = 'D';
	}

	void attributeItems(cPaddle* player) {// gap doi diem
		player->setScore(player->getScore() * 2);
	}
};

class HalfScore :public Items {
public:
	HalfScore(int x, int y) :Items(x, y) {
		shape = 'H';
	}

	void attributeItems(cPaddle* player) {// giam 1 nua diem
		player->setScore(player->getScore() / 2);
	}
};

class FasterSpeed :public Items {
public:
	FasterSpeed(int x, int y) :Items(x, y) {
		shape = 'F';
	}

	void attributeItems(cPaddle* player) {// tang toc do nguoi choi
		player->setSpeed(player->getSpeed() + 1);
	}
};

class SlowerSpeed :public Items {
public:
	SlowerSpeed(int x, int y) :Items(x, y) {
		shape = 'S';
	}

	void attributeItems(cPaddle* player) {// giam toc do nguoi choi
		player->setSpeed(player->getSpeed() - 1);
	}
};

class LongLength :public Items {
public:
	LongLength(int x, int y) :Items(x, y) {
		shape = 'L';
	}

	void attributeItems(cPaddle* player) { // tang chieu dai thanh truot
		player->setMaxbar(player->getMaxBarPlayer() + 2);
	}
};

class ShortLength :public Items {
public:
	ShortLength(int x, int y) :Items(x, y) {
		shape = 's';
	}

	void attributeItems(cPaddle* player) { // giam chieu dai thanh truot
		player->setMaxbar(player->getMaxBarPlayer() - 2);
	}

};

class Barier :public Items {
public:
	Barier(int x, int y) :Items(x, y) {
		isBarrier = true;
		shape = 'B';
	}


	void existentItems(Ball* ball) {
		Items::existentItems(ball);
		isExistent = true;//vat pham khong bien mat
	}

};

class PathItems :public Items {
public:
	PathItems(int x, int y) :Items(x, y) {
		shape = 'P';
	}

	void existentItems(Ball* ball) {
		Items::existentItems(ball);
		if(isExistent==false)
			ball->setIsPath(true);//tao flag ve duong path
	}
};

Items* createItems(int x, int y);//tao ngau nhien cac vat pham

