#pragma once

#include "paddle.h"
#include "Ball.h"

class Player // Tạo class người chơi
{
private:
	int score1, score2; //Điểm số
	bool quit; //biến dùng để thoát game
	Ball* ball; //Gọi lại class bóng để dùng
	cPaddle* player1; //Tạo thanh trượt gán tên player1
	cPaddle* player2;//Tạo thanh trượt gán tên player2
public:
	Player();//Hàm tạo player
	~Player();//Hàm hủy player

	void ScoreUp(cPaddle*);//Hàm tăng điểm
	void DrawBox();//Hàm vẽ khung chơi
	void Win(int, int);
	void Win1(int, int);
	void Draw();//Hàm vẽ các player và bóng
	void Input();//Hàm quản lý nhập liệu từ bàn phím
	void Logic();//Hàm thực hiện chức năng xử lí va chạm
	bool getQuit();//Hàm trả về kết quả để thoát game
};

