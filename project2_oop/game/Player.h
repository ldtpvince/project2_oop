#pragma once

#include "paddle.h"
#include "Ball.h"
#include <vector>
#include <algorithm>
#include "Items.h"

const string fileHighScores = "highScores.txt";

class Player // Tạo class người chơi
{
protected:
	int score1, score2; //Điểm 
	bool quit; //biến dùng để thoát game
	Ball* ball; //Gọi lại class bóng để dùng
	cPaddle1* player1; //Tạo thanh trượt gán tên player1
	cPaddle2* player2;//Tạo thanh trượt gán tên player2

	vector<int> highScores;
	bool isPlayer = true;

	vector<Items*> items;

	int maxTime = 60;//gioi han thoi gian choi
	float time = 0;//thoi gian choi
	bool isTimeOut = false;//flag thoi gian

public:
	Player();//Hàm tạo player
	~Player();//Hàm hủy player

	void ScoreUp(cPaddle*);//Hàm tăng điểm
	void DrawBox();//Hàm vẽ khung chơi
	//void Win(int, int);
	void Win();
	void Win1(int, int);
	void Draw();//Hàm vẽ các player và bóng
	virtual void Input();//Hàm quản lý nhập liệu từ bàn phím
	void Logic();//Hàm thực hiện chức năng xử lí va chạm
	bool getQuit();//Hàm trả về kết quả để thoát game

	void saveScore(int score);
	void writeHighScores();

	void readHighScores();
	static void showHighScores();

	void deleteOldPlayer(int x, int y, int length);
	void clearItems();
};

