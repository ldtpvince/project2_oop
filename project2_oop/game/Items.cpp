#include "Items.h"

void Items::existentItems(Ball* ball) {

	if (x == 1 && direction == eDir::LEFT) {//bien trai
		setExistent(0);
		return;
	}
	if (x == WidthGame - 1 && direction == eDir::RIGHT) {// bien phai
		setExistent(0);
		return;
	}

	if (x == ball->getX() && y - 1 == ball->getY()) {//va cham vs bong
		if (direction == eDir::LEFT && ball->getDirection() == eDir::DOWNLEFT) {
			setExistent(0);
			return;
		}
		if (direction == eDir::RIGHT && ball->getDirection() == eDir::DOWNRIGHT) {
			setExistent(0);
			return;
		}
	}

	if (x == ball->getX() && y + 1 == ball->getY()) {//va cham vs bong
		if (direction == eDir::LEFT && ball->getDirection() == eDir::UPLEFT) {
			setExistent(0);
			return;
		}
		if (direction == eDir::RIGHT && ball->getDirection() == eDir::UPRIGHT) {
			setExistent(0);
			return;
		}
	}

	if (y == ball->getY() && x - 1 == ball->getX())
		if (direction == eDir::LEFT && ball->getDirection() == eDir::RIGHT) {
			setExistent(0);
			return;
		}

	if (y == ball->getY() && x + 1 == ball->getX())
		if (direction == eDir::RIGHT && ball->getDirection() == eDir::LEFT) {
			setExistent(0);
			return;
		}

}

void Items::drawItems() {
	gotoxy(x, y);//delete old Items
	cout << " ";

	if (isExistent) {//kiem tra item co bi va cham
		if (direction == eDir::LEFT) {//di chuyen sang trai
			if (x > 1) {
				x--;
				gotoxy(x, y);
				cout << shape; //ve item o vi tri moi
			}
			else setExistent(0);
		}
		else {
			if (x < WidthGame - 1) {
				x++;
				gotoxy(x, y);
				cout << shape; //ve item o vi tri moi
			}
			else setExistent(0);
		}

		
	}
}

Items* createItems() {
	int type = 1 + rand() % (numTypeItems);

	switch (type)
	{
	case 1:
		return new DoubleScore;
		break;
	case 2:
		return new HalfScore;
		break;
	case 3:
		return new FasterSpeed;
		break;
	case 4:
		return new SlowerSpeed;
		break;
	case 5:
		return new LongLength;
		break;
	case 6:
		return new ShortLength;
		break;
	default:
		break;
	}
}

void clearItems(vector<Items*> items) {
	for (int i = 0; i < items.size(); i++) {

	}
	while (items.size())
	{
		gotoxy(items[0]->getX(), items[0]->getY());
		cout << " ";
		delete items[0];
		items.erase(items.begin());
	}
}