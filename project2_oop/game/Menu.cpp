#include "Menu.h"

Menu::Menu()
{
}

void Menu::NameGame()//Hàm tên game
{
	ifstream FileIn("Name.txt", ios::in);//mở file Name.txt để đọc file

	if (FileIn.fail())//Nếu không mở được file thì báo lỗi
	{
		cout << "ERROR file data";
		Sleep(5000);
		exit(0);
	}

	while (!FileIn.eof())//Cho đọc đến hết file
	{
		string text;
		getline(FileIn, text);
		cout << text << endl;
	}

	FileIn.close();//Đóng file lại
}
Menu::Menu(vector<Menu*>& listSelect)//Danh sách các lựa chọn trong Menu
{
	Menu* items = new Menu(); //Khởi tạo các items, items1, items2, items3 & items4;
	Menu* items1 = new Menu();
	Menu* items2 = new Menu();
	Menu* items3 = new Menu();
	Menu* items4 = new Menu();
	
	items->x = 55;//di chuyển đến tọa độ x = 55
	items->y = 14;//di chuyển đến tọa độ y = 14
	items->data = "2 Player";//in ra dòng 1 Player
	listSelect.push_back(items);//Thêm dữ liệu vào danh sách


	items1->x = 55;//di chuyển đến tọa độ x = 55
	items1->y = 16;//di chuyển đến tọa độ y = 16
	items1->data = "1 Player";//in ra dòng 2 Player
	listSelect.push_back(items1);//Thêm dữ liệu vào danh sách


	items2->x = 55;//di chuyển đến tọa độ x = 55
	items2->y = 18;//di chuyển đến tọa độ y = 18
	items2->data = "Guide";//in ra dòng Guide 
	listSelect.push_back(items2);//Thêm dữ liệu vào danh sách

	items3->x = 55;//di chuyển đến tọa độ x = 55
	items3->y = 20;//di chuyển đến tọa độ y = 18
	items3->data = "High Scores";//in ra dòng Exit 
	listSelect.push_back(items3);//Thêm dữ liệu vào danh sách

	items4->x = 55;//di chuyển đến tọa độ x = 55
	items4->y = 22;//di chuyển đến tọa độ y = 18
	items4->data = "Exit";//in ra dòng Exit 
	listSelect.push_back(items4);//Thêm dữ liệu vào danh sách

}

Menu::~Menu()
{
}
void Menu::move(int& dir, bool& Choose, vector<Menu*> listMenu)//Hàm di chuyển để chọn các mục trong menu game
{
	while (true) // vòng lặp luôn đúng
	{
		if (_kbhit())//bắt sự kiện nhập từ bàn phím
		{
			int key = _getch();//Nhập 

			if (key == 72)  //nhấn mũi tên hướng lên
			{
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << "           ";//xóa mục cũ
				gotoxy(listMenu[dir]->getX(), listMenu[dir]->getY()); cout << listMenu[dir]->getData();//in ra mục mới với tên tương tự

				if (dir == 0)//nếu mục đang ở vị trí đầu nhưng vẫn nhân mũi tên lên thì nó sẽ đưa con trỏ xuống mục cuối cùng
					dir = listMenu.size()-1;
				else
					dir--;// lựa chọn mục trừ đi 1 nếu nhấn mũi tên lên
				
				//in ra lựa chọn của mình
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << "           ";
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << char(175) << " " << listMenu[dir]->getData();

				break;
			}
			else if (key == 80) //Nhấn mũi tên hướng xuống
			{
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << "           ";//xóa mục cũ
				gotoxy(listMenu[dir]->getX(), listMenu[dir]->getY()); cout << listMenu[dir]->getData();//in ra mục mới với tên tương tự

				if (dir == listMenu.size() - 1)//nếu mục đang ở vị trí cuối nhưng vẫn nhân mũi tên xuống thì nó sẽ đưa con trỏ lên mục đầu tiên
					dir = 0;
				else
					dir++;// lựa chọn mục cộng thêm 1
				
				//in ra lựa chọn của mình
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << "           ";
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << char(175) << " " << listMenu[dir]->getData();

				break;
			}
			else if (key == 13) //nhấn phím ENTER để chọn mục
			{
				Choose = true;
				break;
			}
		}
	}
}
void mButton()//quay về trang đầu sau khi nhấn vào Guide
{
	AnConTro();//Ẩn con trỏ đi
	int Check;//biến kiểm tra
	do {
		gotoxy(100, 20);
		cout << " 0: Back ";
		
		if (_kbhit())
		{
			Check = _getch(); //nếu nhập vào 1 thì thoát hàm Guide
			if (Check == 48)
				break;
		}
	} while (true);
}
void Menu::guide()//Hàm hướng dẫn chơi
{
	system("cls");
	NameGame();//In ra tên trò chơi 
	
	gotoxy(0, 14);//in ra huong dan choi
	cout << "Player 1: use button W to UP, S to DOWN" << endl;
	cout << "Player 2: use button O to UP, K to DOWN" << endl;
	cout << "Players try to pick up ball and items to achieve high score" << endl;
	cout << "The winner is the person who achieves higher score in the limit time of game" << endl;
	cout << "          Press Q to exit game           " << endl;
	
	system("pause");
}

int Menu::getX() { return x; }
int Menu::getY() { return y; }
string Menu::getData() { return data; }
