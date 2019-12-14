#include "Machine.h"

void Machine::Input() {
	//ball->Move();//bóng trỏ đến hàm Move để lấy hướng di chuyển hiện tại

	int ballx = ball->getX();//lấy tọa độ bóng x
	int bally = ball->getY();//lấy tạo độ bóng y

	int player1x = player1->getX();//lấy tọa độ player1 x
	int player2x = player2->getX();//lấy tọa độ player2 x
	int player1y = player1->getY();//lấy tọa độ player1 y
	int player2y = player2->getY();//lấy tọa độ player2 y

	if (_kbhit())// _kbhit() kiểm tra xem phím đã được nhấn hay chưa
	{
		char key = _getch();//gán key bằng phím đã nhấn

		if (key == 'w' || key == 'W')//nếu người dùng nhấn phím w or W thì player1 di chuyển hướng lên 1 đơn vị
		{
			if (player1y - player1->getSpeed() > 1)
				player1->moveUp();
			else player1->moveUp(true);
		}
		
		if (key == 's' || key == 'S')//nếu người dùng nhấn phím s or S thì player1 di chuyển hướng xuống 1 đơn vị
		{
			if (player1y + player1->getMaxBarPlayer() + player1->getSpeed() < HeightGame - 1)
				player1->moveDown();
			else player1->moveDown(true);
		}
		
		if (key == 'q' || key == 'Q')//nếu nhấn q or Q thì quit game
		{
			quit = true;
		}

		if (key == 'v' || key == 'V') {
			saveGame();
		}

		if (ball->getDirection() == STOP)//nếu hướng bóng đang là STOP thì random hướng cho bóng
			ball->randomDirection();
	}

	speed += 0.4;
	if (speed >= 1) {//dat gioi han thi cho may di chuyen
		speed = 0;
		//neu toa do y cua may lon hon toa do y cua bong -> may di chuyen len
		if (player2y + player2->getMaxBarPlayer()/2 > bally) {
			if (player2y - player2->getSpeed() > 1)
				player2->moveUp();
			else player2->moveUp(true);//di chuyen qua pham vi
		}

		//neu toa do y cua may nho hon toa do y cua bong -> may di chuyen xuong 1 don vi
		if (player2y + player2->getMaxBarPlayer() / 2 < bally) {
			if (player2y + player2->getMaxBarPlayer() + player1->getSpeed() < HeightGame - 1)
				player2->moveDown();
			else player2->moveDown(true);//di chuyen qua pham vi
		}
	}

	
}

void Machine::Logic() {//ham logic
	Player::Logic();
	if (winner == 1 && level < maxLevel) {//nguoi choi 1 thang
		level++;
		winner = 0;
		int preScore = score1;//diem man choi truoc
		//thong bao man choi moi
		gotoxy(18, HeightGame / 2);
		cout << "Next Level";
		Sleep(1000);
		gotoxy(18, HeightGame / 2);
		cout << "          ";

		delete ball, player1, player2;//xoa vung nho
		initGame();//khoi tao lai game
		player1->setScore(preScore);//cai dat diem cu cho nguoi choi
	}
}

void Machine::saveGame() {
	string filename;
	ofstream listFileSave("listFileSave.saves", ios::app);
	for (int i = 1; i < HeightGame; i++)
	{
		gotoxy(2, i); cout << " ";//Xóa player1
	}
	for (int i = 1; i < HeightGame; i++)
	{
		gotoxy(WidthGame - 2, i); cout << " ";//Xóa player2
	}

	gotoxy(ball->getX0(), ball->getY0());//xoa bong
	cout << " ";
	gotoxy(ball->getX(), ball->getY());
	cout << " ";

	for (int i = 0; i < items.size(); i++) {
		items[i]->clear();
	}

	TextColor(10);//hàm đổi màu dòng chữ in ra bên dưới
	gotoxy(10, HeightGame / 2);
	cout << "Save game (name): ";
	cin >> filename;
	listFileSave << filename + ".save" << endl;
	listFileSave << 1 << endl;

	ofstream saveFile(filename + ".save", ios::out | ios::binary);
	saveFile.write((char*)&score1, sizeof(int));
	saveFile.write((char*)&score2, sizeof(int));
	ball->saveInfo(saveFile);
	player1->saveInfo(saveFile);
	player2->saveInfo(saveFile);

	for (int i = 0; i < items.size(); i++) {
		items[i]->saveInfo(saveFile);
	}

	saveFile.write((char*)&speed, sizeof(float));
	saveFile.write((char*)&maxLevel, sizeof(int));
	saveFile.write((char*)&level, sizeof(int));

	char option;
	gotoxy(10, HeightGame / 2 + 2);
	cout << "Continue? (Y/N): ";

	TextColor(11);

	while (1) {
		if (_kbhit()) {
			option = _getch();

			if (option == 'N' || option == 'n') {
				quit = true;
				break;
			}
			if (option == 'Y' || option == 'y') {
				break;
			}
		}
	}

	deleteTextOnScreen(10, HeightGame / 2, "Save game: (name)" + filename);
	deleteTextOnScreen(10, HeightGame / 2 + 2, "Continue? (Y/N): ");
	saveFile.close();
	listFileSave.close();

	//drawItems = false;
}

void Machine::loadGame(string path) {
	ifstream saveFile(path, ios::in | ios::binary);

	saveFile.read((char*)&score1, sizeof(int));
	saveFile.read((char*)&score2, sizeof(int));

	saveFile.read((char*)ball, sizeof(Ball));
	saveFile.read((char*)player1, sizeof(cPaddle));
	saveFile.read((char*)player2, sizeof(cPaddle));

	int cnt = 0;
	while (!saveFile.eof()) {
		Items* temp = new Items(0, 0);
		saveFile.read((char*)temp, sizeof(Items));
		Items* temp2 = nullptr;

		switch (temp->getType()) {
		case DOUBLESCORE: {
			temp2 = new DoubleScore(temp->getX(), temp->getY());
			break;
		}
		case HALFSCORE: {
			temp2 = new HalfScore(temp->getX(), temp->getY());
			break;
		}
		case FASTERSPEED: {
			temp2 = new FasterSpeed(temp->getX(), temp->getY());
			break;
		}
		case SLOWERSPEED: {
			temp2 = new SlowerSpeed(temp->getX(), temp->getY());
			break;
		}
		case LONGLENGTH: {
			temp2 = new LongLength(temp->getX(), temp->getY());
			break;
		}
		case SHORTLENGTH: {
			temp2 = new ShortLength(temp->getX(), temp->getY());
			break;
		}
		case BARRIER: {
			temp2 = new Barier(temp->getX(), temp->getY());
			break;
		}
		case PATHITEMS: {
			temp2 = new PathItems(temp->getX(), temp->getY());
			break;
		}
		}

		if (cnt >= items.size()) {
			items.push_back(temp2);
		}
		else {
			delete items[cnt];
			items[cnt] = temp2;
			cnt++;
		}
		delete temp;
	}

	cnt--;
	while (cnt < items.size()) {
		items.erase(items.begin() + cnt);
	}

	saveFile.read((char*)&speed, sizeof(float));
	saveFile.read((char*)&maxLevel, sizeof(int));
	saveFile.read((char*)&level, sizeof(int));

	saveFile.close();
}