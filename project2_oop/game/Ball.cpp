#include "Ball.h"

Ball::Ball(int posX, int posY) //khởi tạo tọa độ quả bóng
{
	originalX = posX;//Gán tọa độ ban đầu cho biến x
	originalY = posY;//Gán tọa độ ban đầu cho biến x
	x = x0 = posX; y = y0 = posY; //Gán tọa độ ban đầu cho bóng
	direction = STOP;//Lúc này bóng không di chuyển
}

void Ball::Reset()//reset lại tọa độ quả bóng về ban đầu
{
	x = x0 = originalX; y = y0 = originalY;//Gán tọa độ ban đầu cho bóng
	direction = STOP;//Lúc này bóng không di chuyển
}

void Ball::changeDirection(eDir dir)//Đổi hướng di chuyển của bóng
{
	direction = dir;
}

void Ball::invertDirection() {//doi huong bong
	
	switch (direction)
	{
	case LEFT:
		direction = RIGHT;
		break;
	case RIGHT:
		direction = LEFT;
		break;
	case UPLEFT:
		direction = DOWNLEFT;
		break;
	case UPRIGHT:
		direction = DOWNRIGHT;
		break;
	case DOWNLEFT:
		direction = UPLEFT;
		break;
	case DOWNRIGHT:
		direction = UPRIGHT;
		break;
	default:
		break;
	}
}
void Ball::randomDirection()//Random hướng di chuyển của bóng
{
	direction = (eDir)((rand() % 6) + 1);// Sinh số ngẫu nhiên từ 1 -> 7 <=> các hướng tương ứng ở eDir (LEFT, UPLEFT, DOWNLEFT, RIGHT, UPRIGHT, DOWNRIGHT)
}

void Ball::Move()//Hàm cho bóng di chuyển
{
	if (invertDir) 
		invertDirection();

	if (direction == STOP) //Nếu hướng bằng STOP thì không làm gì và return luôn
	{
		return;
	}
	else if (direction == LEFT)//Nếu hướng = LEFT thì cho X cũ giữ tọa độ của x và sau đó tọa độ x giảm đi 1
	{
		x0 = x;
		x--;
		invertDir = false;
		return;
	}
	else if (direction == RIGHT)//Nếu hướng = RIGHT thì cho X cũ giữ tọa độ của x và sau đó tọa độ x tăng lên 1
	{
		x0 = x;
		x++;
		invertDir = false;
		return;
	}
	else if (direction == UPLEFT)//Nếu hướng = UPLEFT thì cho X cũ giữ tọa độ của x và sau đó tọa độ x và y giảm đi 1
	{
		x0 = x;
		y0 = y;
		x--; y--;
		invertDir = false;
		return;
	}
	else if (direction == DOWNLEFT)//Nếu hướng = UPLEFT thì cho X cũ giữ tọa độ của x và sau đó tọa độ x giảm đi 1 và tọa độ y tăng lên 1
	{
		x0 = x;
		y0 = y;
		x--; y++;
		invertDir = false;
		return;
	}
	else if (direction == UPRIGHT)//Nếu hướng = UPLEFT thì cho X cũ giữ tọa độ của x và sau đó tọa độ x tăng lên 1 và tọa độ y giảm đi 1
	{
		x0 = x;
		y0 = y;
		x++; y--;
		invertDir = false;
		return;
	}
	else if (direction == DOWNRIGHT)//Nếu hướng = UPLEFT thì cho X cũ giữ tọa độ của x và sau đó tọa độ x và y tăng lên 1
	{
		x0 = x;
		y0 = y;
		x++; y++;
		invertDir = false;
		return;
	}

	
}

void Ball::drawBall() {
	//draw ball and delete back it
	gotoxy(x0, y0); cout << " ";//tại vị trí của bóng cũ t vẽ đè lên một khoảng trắng , tác dụng như xóa đi quả bóng
	gotoxy(x, y); cout << "O";// vẽ quả bóng bằng chữ O


	if (direction == LEFT)//nếu bóng đi sang trái
	{
		gotoxy(x + 1, y); cout << " ";//xóa bóng
	}
	if (direction == RIGHT)// nếu bóng đi sang phải
	{
		gotoxy(x - 1, y); cout << " ";//xóa bóng
	}

}

int Ball::getX() { return x; }//Hàm trả về tọa độ x hiện tại
int Ball::getY() { return y; }//Hàm trả về tọa độ y hiện tại
int Ball::getX0() { return x0; }//Hàm trả về tọa độ x cũ
int Ball::getY0() { return y0; }//Hàm trả về tọa độ y cũ
eDir Ball::getDirection() { return direction; }//Hàm trả về hướng di chuyển của bóng

