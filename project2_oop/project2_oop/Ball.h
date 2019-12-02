#pragma once
#include "DoHoa.h"

enum eDir { STOP, LEFT, UPLEFT, DOWNLEFT, RIGHT, UPRIGHT, DOWNRIGHT };//Dùng enum để gán tên cho các hằng số để dễ quản lí

class Ball //Tạo class quản lí bóng
{
private:
	int x, y; //tọa độ x,y hiện tại
	int x0, y0;//tọa độ x,y cũ             
	int originalX, originalY;//Tọa độ x, y gốc
	eDir direction; //Hướng di chuyển của bóng
public:

	Ball(int, int);//khởi tạo tọa độ quả bóng
	void Reset();//reset lại tọa độ quả bóng về ban đầu
	void changeDirection(eDir);//Đổi hướng di chuyển của bóng
	void randomDirection();//Random hướng di chuyển của bóng
	void Move();//Hàm cho bóng di chuyển
	int getX();//Hàm trả về tọa độ x hiện tại
	int getY();//Hàm trả về tọa độ y hiện tại
	int getX0();//Hàm trả về tọa độ x cũ
	int getY0();//Hàm trả về tọa độ y cũ
	eDir getDirection();//Hàm trả về hướng di chuyển của bóng

};
