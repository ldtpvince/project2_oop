#include "Menu.h"
#include"DoHoa.h"

int main()
{
	resizeConsole(WidthConsole, HeightConsole);//Khởi tạo cửa sổ console
	AnConTro();//Ẩn con trỏ đi

	vector<Menu*> listMenu;//tạo một danh sách các lựa chọn
	Menu* m = new Menu(listMenu);//khởi tạo menu
	TextColor(11);//đổi màu trò chơi
	m->NameGame();//ghi tên game ra màn hình
	
	int dir = 0, dir0 = 0;// Khởi tạo biến dir = 0 dùng để chọn các mục trong menu
	bool Choose = false;//khởi tại biến lựa chọn bằng false
	char dChoose = 175;// kí tự <<

	//mainloop
	while (true)
	{

		for (int i = 0; i < listMenu.size(); i++)//duyệt từ đầu đến hết menu
		{
			gotoxy(listMenu[i]->getX(), listMenu[i]->getY()); cout << listMenu[i]->getData();//in ra các lựa chọn trong menu
		}

		gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << dChoose << " " << listMenu[dir]->getData() << "  "; //tạo kí tự đứng trước các mục ( cho đẹp )

		m->move(dir, Choose, listMenu); //trỏ đến hàm di chuyển để chọn các mục

		if (Choose == true)// nếu lựa chọn bằng true
		{
			Choose = false;//gán choose bằng false
			if (dir == 0) // play game;
			{
				Player* game = new Player();//tạo ra player để bắt đầu game
				game->DrawBox();//Vẽ khung game

				while (!game->getQuit())// khi game khác Quit thì tiếp tục vẽ rồi ,chơi game , xử lí
				{
					game->Draw();//vẽ bóng và thanh trượt
					Sleep(50);
					game->Input();//chơi game
					game->Logic();//xử lý va chạm
				}

				delete game;//xóa game
			}
			else if (dir == 1) // Guide
			{
				m->guide();//hiện hàm hướng dẫn 

				system("cls");
				m->NameGame();
			}
			else if (dir == 2)//lựa chọn bằng 2 tức exit game
			{
				delete m;
				exit(0);
			}
		}
	}
	return 0;
}