#include "paddle.h"

void cPaddle::Reset() { x = x0 = originalX; y = y0 = originalY; }//Cho tọa độ bóng hiện tại về tọa độ gốc

void cPaddle::moveUp() { //di chuyen len
	y0 = y; 
	y-=speed; 
	
}//gán tọa độ x cũ = x , tọa độ y--
void cPaddle::moveDown() { //di chuyen xuong
	y0 = y;
	y+=speed;
	
}//gán tọa độ y cũ = y , tọa độ y++

void cPaddle::moveUp(bool overSpeed) { y0 = y; y=1; 
}//gán tọa độ x cũ = x , tọa độ y-=speed
void cPaddle::moveDown(bool overSpeed) { y0 = y; y=HeightGame- MaxBarPlayer; 
}//gán tọa độ y cũ = y , tọa độ y+=speed

int cPaddle::getX() { return x; }//Hàm trả về tọa độ X hiện tại của thanh
int cPaddle::getY() { return y; }//Hàm trả về tọa độ Y hiện tại của thanh
int cPaddle::getX0() { return x0; }//Hàm trả về tọa độ X cũ của thanh
int cPaddle::getY0() { return y0; }//Hàm trả về tọa độ y cũ của thanh

void cPaddle::setSpeed(int x) {//cat dat toc do cho nguoi choi
	if (x > maxSpeed)//toc do khong vuot qua toc do nho nhat va toc do lon nhat cua nguoi choi
		speed = maxSpeed;
	else if (x < minSpeed)
		speed = minSpeed;
	else
		speed = x;
}

void cPaddle::setMaxbar(int x) {//cat dat chieu dai cho thanh truot
	if (x > maxMaxBar) x = maxMaxBar;//chieu dai thanh truot khong vuot qua chieu dai lon nhat va chieu dai nho nhat
	if (x < minMaxBar) x = minMaxBar;

	oldMaxBar = MaxBarPlayer;//luu chieu dai truoc khi thay doi
	MaxBarPlayer = x;//thay doi chieu dai hien tai
}

void cPaddle::drawPaddle() {//ve nguoi choi
	//xoa nguoi choi o vi tri cu
	for (int i = 0; i < oldMaxBar; i++) {
		gotoxy(x0, y0+i);
		cout << " ";
	}

	for (int i = 0; i < oldMaxBar; i++) {
		gotoxy(x, y + i);
		cout << " ";
	}
	//ve nguoi choi o vi tri moi
	for (int i = 0; i < MaxBarPlayer; i++) {
		gotoxy(x, y + i);
		cout << char(219);
	}

	oldMaxBar = MaxBarPlayer;//dieu chinh chieu dai cu

}

void cPaddle::saveInfo(ofstream& out) {
	out.write((char*)this, sizeof(cPaddle));
}