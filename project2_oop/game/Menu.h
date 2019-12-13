#pragma once
#include "Player.h"

class Menu//Tạo class Menu
{
private:
	int x, y;//khởi tạo biến giá trị x,y
	string data;//biến nhập dữ liệu 
public:
	Menu();//hàm tạo Menu
	Menu(vector<Menu*>&);//Danh sách các lựa chọn trong Menu
	~Menu();//hàm hủy Menu

	void move(int&, bool&, vector<Menu*>);//Hàm di chuyển để chọn các mục trong menu game
	void NameGame();//Hàm vẽ
	void guide();//Hàm hướng dẫn chơi
	int getX();//Hàm trả về tọa độ x
	int getY();//Hàm trả về tọa độ y
	string getData();//hàm trả về data 
	string loadGameMenu(int& type);
};

