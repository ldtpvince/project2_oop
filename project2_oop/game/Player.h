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

	vector<int> highScores;//top diem cao nhat
	bool isPlayer = true;//kiem tra che do choi

	vector<Items*> items;//mang vat pham
	int maxNumItems = 8;//so vat pham toi da
	int numItems = 0;
	//bool drawItems = false;//flag de ve cac vat pham

	int winner = 0;//xac dinh nguoi thang cuoc
public:
	Player();//Hàm tạo player
	~Player();//Hàm hủy player

	void DrawBox();//Hàm vẽ khung chơi
	//void Win(int, int);
	void Win();
	void Draw();//Hàm vẽ các player và bóng
	virtual void Input();//Hàm quản lý nhập liệu từ bàn phím
	virtual void Logic();//Hàm thực hiện chức năng xử lí va chạm
	bool getQuit();//Hàm trả về kết quả để thoát game

	void saveScore(int score);//luu diem cao
	void writeHighScores();//viet bang diem cao vo file

	void readHighScores();//doc bang diem tu file
	static void showHighScores();//hien bang diem ra man hinh

	void deleteOldPlayer(int x, int y, int length);//xoa player o vi tri cu
	void clearItems();//xoa vat pham
	void createArrayItems();//tao mang vat pham
	void initGame();//khao tao game

	void drawPathBall();//ve duong path cua bong

	virtual void saveGame();
	virtual void loadGame(string path);
};

void deleteTextOnScreen(int x, int y, string s);