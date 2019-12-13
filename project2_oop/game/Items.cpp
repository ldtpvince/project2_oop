#include "Items.h"


void Items::existentItems(Ball* ball) {//xac dinh va cham giua vat pham vs bong
	if (y == ball->getY() && x == ball->getX() + 1 && ball->getDirection() == RIGHT) {
		setExistent(0);
		ball->setInverDir(true);
	}

	else if (y == ball->getY() && x == ball->getX() - 1 && ball->getDirection() == LEFT) {
		setExistent(0);
		ball->setInverDir(true);
	}

	else if (y == ball->getY() + 1 && x == ball->getX() + 1 && ball->getDirection() == DOWNRIGHT) {
		setExistent(0);
		ball->setInverDir(true);
	}

	else if (y == ball->getY() - 1 && x == ball->getX() + 1 && ball->getDirection() == UPRIGHT) {
		setExistent(0);
		ball->setInverDir(true);
	}

	else if (y == ball->getY() + 1 && x == ball->getX() - 1 && ball->getDirection() == DOWNLEFT) {
		setExistent(0);
		ball->setInverDir(true);
	}

	else if (y == ball->getY() - 1 && x == ball->getX() - 1 && ball->getDirection() == UPLEFT) {
		setExistent(0);
		ball->setInverDir(true);
	}
	
}

void Items::drawItems() {
	gotoxy(x, y);//delete old Items
	cout << shape;
}


//xoa vat pham
void clearItems(vector<Items*> items) {
	for (int i = 0; i < items.size(); i++) {

	}
	while (items.size())
	{
		//gotoxy(items[0]->getX(), items[0]->getY());
		//cout << " ";
		items[0]->clear();
		delete items[0];
		items.erase(items.begin());
	}
}

//tao ngau nhien cac vat pham
Items* createItems(int x, int y) {
	int type = 1 + rand() % (numTypeItems);//ran dom

	switch (type)
	{
		/*
	case 1: case 2: case 3: case 4: case 5:
		return new PathItems(x, y);
		break;
		
	*/
	case 1:
		return new DoubleScore(x, y);
		break;
	case 2:
		return new HalfScore(x, y);
		break;
	case 3:
		return new FasterSpeed(x, y);
		break;
	case 4:
		return new SlowerSpeed(x, y);
		break;
	case 5:
		return new LongLength(x, y);
		break;
	case 6:
		return new ShortLength(x, y);
		break;
	case 7:
		return new Barier(x, y);
		break;
	case 8: 
		return new PathItems(x, y);
		break;
	default:
		break;
	}
}

void Items::saveInfo(ofstream& out) {
	out.write((char*)this, sizeof(Items));
}