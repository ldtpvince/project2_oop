#include "paddle.h"

/*
cPaddle::cPaddle(int posX, int posY)//Khởi tạo tọa độ cho 2 thanh trượt
{
	originalX = posX; // gán tọa độ gốc cho x
	originalY = posY;// gán tọa độ gốc cho y
	x = x0 = posX;//Gán tọa độ cho x và x0
	y = y0 = posY;//Gán tọa độ cho y và y0
}*/
void cPaddle::Reset() { x = x0 = originalX; y = y0 = originalY; }//Cho tọa độ bóng hiện tại về tọa độ gốc

void cPaddle::moveUp() { y0 = y; y-=speed; }//gán tọa độ x cũ = x , tọa độ y--
void cPaddle::moveDown() { y0 = y; y+=speed; }//gán tọa độ y cũ = y , tọa độ y++

void cPaddle::moveUp(bool overSpeed) { y0 = y; y=1; }//gán tọa độ x cũ = x , tọa độ y-=speed
void cPaddle::moveDown(bool overSpeed) { y0 = y; y=HeightGame-1 - MaxBarPlayer; }//gán tọa độ y cũ = y , tọa độ y+=speed

int cPaddle::getX() { return x; }//Hàm trả về tọa độ X hiện tại của thanh
int cPaddle::getY() { return y; }//Hàm trả về tọa độ Y hiện tại của thanh
int cPaddle::getX0() { return x0; }//Hàm trả về tọa độ X cũ của thanh
int cPaddle::getY0() { return y0; }//Hàm trả về tọa độ y cũ của thanh

void cPaddle::setSpeed(int x) {
	if (x > maxSpeed)
		speed = maxSpeed;
	else if (x < minSpeed)
		speed = minSpeed;
	else
		speed = x;
}

void cPaddle::setMaxbar(int x) {
	if (x > maxMaxBar) x = maxMaxBar;
	if (x < minMaxBar) x = minMaxBar;

	oldMaxBar = MaxBarPlayer;
	MaxBarPlayer = x;
}
