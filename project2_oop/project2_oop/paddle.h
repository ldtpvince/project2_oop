#pragma once
#include "DoHoa.h"

class cPaddle //Tạo class thanh trượt
{
private:
	int x, y; //tọa độ x,y hiện tại
	int x0, y0;//tọa độ x,y cũ
	int originalX, originalY;//Tọa độ x, y gốc
public:
	cPaddle(int, int);//Khởi tạo tọa độ cho 2 thanh trượt
	void Reset();//Reset về tọa độ đầu tiên của 2 thanh
	void moveUp();//Hàm di chuyển thanh đi lên
	void moveDown();//Hàm di chuyển thanh đi xuống

	int getX();//Hàm trả về tọa độ X hiện tại của thanh
	int getY();//Hàm trả về tọa độ Y hiện tại của thanh
	int getX0();//Hàm trả về tọa độ X cũ của thanh
	int getY0();//Hàm trả về tọa độ y cũ của thanh

};