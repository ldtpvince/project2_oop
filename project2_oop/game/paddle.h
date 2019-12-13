#pragma once
#include "DoHoa.h"

class Items;

class cPaddle //Tạo class thanh trượt
{
protected:
	int x, y; //tọa độ x,y hiện tại
	int x0, y0;//tọa độ x,y cũ
	int originalX, originalY;//Tọa độ x, y gốc

	int score = 0;//diem cua nguoi choi
	int incrementScore = 1;
	int speed = 2;//toc do di chuyen
	int minSpeed = 1;//toc do di chuyen nho nhat
	int maxSpeed = 3;//toc do di chuyen lon nhat

	int MaxBarPlayer = 5;	//chiều dài thanh trượt moi
	int oldMaxBar = 5; // chieu dai thanh truot cu
	int minMaxBar = 3; // chieu dai nho nhat
	int maxMaxBar = 7; // chieu dai lon nhat

	bool misfortune = false;//lag doi huong bong

public:
	
	void Reset();//Reset về tọa độ đầu tiên của 2 thanh
	void moveUp();//Hàm di chuyển thanh đi lên
	void moveDown();//Hàm di chuyển thanh đi xuống

	void moveUp(bool overSpeed);//Hàm di chuyển thanh đi lên
	void moveDown(bool overSpeed);//Hàm di chuyển thanh đi xuống

	int getX();//Hàm trả về tọa độ X hiện tại của thanh
	int getY();//Hàm trả về tọa độ Y hiện tại của thanh
	int getX0();//Hàm trả về tọa độ X cũ của thanh
	int getY0();//Hàm trả về tọa độ y cũ của thanh

	int getMaxBarPlayer() {//lay chieu dai hien tai cua thanh truot
		return MaxBarPlayer;
	}

	int getSpeed() {//lay toc do cua nguoi choi
		return speed;
	}

	void setSpeed(int x);//cai dat toc do cho nguoi choi

	void setMaxbar(int x);//cai dat chieu dai cho thanh truot

	int getScore() {//lay diem cua nguoi choi
		return score;
	}

	void upScore() {//tang diem cho nguoi choi
		score++;
	}

	void setScore(int Score) {//cat dat diem cho nguoi choi
		score = Score;
	}

	int getOldMarBar() {//lay chieu dai cu cua thanh truot
		return oldMaxBar;
	}

	void drawPaddle();//ve nguoi choi
	void saveInfo(ofstream& out);
};

class cPaddle1 :public cPaddle {
public:
	cPaddle1() {
		originalX = 2; // gán tọa độ gốc cho x
		originalY = HeightGame / 2 - (MaxBarPlayer / 2);// gán tọa độ gốc cho y
		x = x0 = 2;//Gán tọa độ cho x và x0
		y = y0 = HeightGame / 2 - (MaxBarPlayer / 2);//Gán tọa độ cho y và y0
	}

};

class cPaddle2 :public cPaddle {
public:
	cPaddle2() {
		originalX = WidthGame - 2; // gán tọa độ gốc cho x
		originalY = HeightGame / 2 - (MaxBarPlayer / 2);// gán tọa độ gốc cho y
		x = x0 = WidthGame - 2;//Gán tọa độ cho x và x0
		y = y0 = HeightGame / 2 - (MaxBarPlayer / 2);//Gán tọa độ cho y và y0
	}
};