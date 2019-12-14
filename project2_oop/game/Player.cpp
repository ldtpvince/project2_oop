#include "Player.h"

Player::Player()//khoi tao game
{
	initGame();
	
}

void Player::initGame() {//khoi tao cac thong so
	quit = false;
	score1 = score2 = 0;//Khởi tạo cho biến score1 và score2 giá trị 0 ban đầu
	ball = new Ball(WidthGame / 2, (HeightGame / 2));//khởi tạo tọa độ ban đầu cho quả bóng

	player1 = new cPaddle1;//khoi tao nguoi choi 1
	player2 = new cPaddle2;//khoi tao nguoi choi 2

	readHighScores();//Doc nhung diem so cao nhat cua game

	createArrayItems();//tao mang vat pham
	//drawItems = false;
}

void Player::createArrayItems() {
	//numItems = 1 + rand() % (maxNumsItems);
	numItems = maxNumItems;
	int count = 0;
	while (count < numItems) {
		int x = 5 + rand()% (WidthGame - 5 + 1 - 5);//khoi tao vi tri ngau nhien
		int y = 1 + rand() % (HeightGame-1);

		bool exsist = false;
		for (int i = 0; i < items.size(); i++) {
			if (x == items[i]->getX() && y == items[i]->getY()) {//kiem tra co trung vi tri voi cac vat pham truoc
				exsist = true;
				break;
			}
		}

		if (!exsist) {
			items.push_back(createItems(x, y));
			if(!items[items.size()-1]->checkBarrier())//barier khong dc tinh la vat pham
				count++;
			
		}
	}
}

void Player::readHighScores() {//doc diem so cao cua game tu file
	ifstream in(fileHighScores);
	int score;
	
	while (in >> score) {
		highScores.push_back(score);
	}
	
	in.close();
}

void Player::writeHighScores() {//viet top diem cao vao file
	ofstream out(fileHighScores);
	int i = 0;
	for ( i = highScores.size()-1; i >= 0; i--) {
		out << highScores[i] << "\n";
	}

	out.close();
}

void Player::showHighScores() {//hien top diem cao ra man hinh
	
	ifstream in(fileHighScores);
	vector<int> highScores;

	int score;
	if (!in) {
		cout << "read" << endl;
		return;
	}
	while (in >> score) {//doc top diem tu file
		highScores.push_back(score);
	}

	system("cls");
	cout << "Top High Scores of Game" << endl;

	for (int i = 0; i < highScores.size(); i++) {
		cout << i + 1 << ". \t" << highScores[i] << endl;
	}
	cout << "\n\n\n";
	in.close();

	char c;
	cout << "Press any Key to back to the Menu of Game";
	_getch();

}
Player::~Player()//Hàm hủy ball, player1, player2
{
	delete ball, player1, player2;	
}


void Player::DrawBox()// Hàm vẽ khung chơi
{
	system("cls");//lệnh xóa màn hình

	for (int i = 0; i <= HeightGame; i++)
	{
		for (int j = 0; j <= WidthGame; j++)
		{
			if (i == 0 || i == HeightGame || j == 0 || j == WidthGame)
			{
				gotoxy(j, i);  cout << char(219);
			}
		}
	}
}
//xu ly thang game
void Player::Win()
{
	int maxScore;//diem cao nhat trong 2 nguoi choi

	score1 = player1->getScore();
	score2 = player2->getScore();
	maxScore = (score1 > score2) ? score1 : score2;
	
	if (winner == 1) {
		TextColor(10);//hàm đổi màu dòng chữ in ra bên dưới
		gotoxy(13, HeightGame / 2);//gọi hàm tọa độ để in ra đúng tọa độ mình cần in
		cout << "***** Player 1 WIN *****";
		TextColor(11);//Trả lại màu ban đầu trò chơi
		Sleep(1500);// xem kết quả
		

		saveScore(maxScore);//Kiem tra va luu diem so cao
		writeHighScores();//viet diem so cao vao file
	}
	else if (winner == 2) {
		TextColor(10);//hàm đổi màu dòng chữ in ra bên dưới
		gotoxy(13, HeightGame / 2);//gọi hàm tọa độ để in ra đúng tọa độ mình cần in
		cout << "***** Player 2 WIN *****";
		TextColor(11);//Trả lại màu ban đầu trò chơi
		Sleep(2000);// xem kết quả

		if (isPlayer) {//kiem tra nguoi choi hay may
			saveScore(maxScore);//Kiem tra nguoi choi va luu diem so cao
			writeHighScores();
		}
	}

	gotoxy(13, HeightGame / 2);//lam sach san bong
	cout << "                        ";
	
}


void Player::clearItems() {//xoa items va vung nho cua chung

	while (items.size())
	{
		items[0]->clear();//xoa hinh anh vat pham
		delete items[0];
		items.erase(items.begin());
	}
}

void Player::Draw()//Hàm vẽ các player và bóng
{
	int ballx = ball->getX();//Lấy tọa độ x của bóng
	int bally = ball->getY();//Lấy tọa độ y của bóng

	int ballx0 = ball->getX0();//Lấy tọa độ x cũ của bóng
	int bally0 = ball->getY0();//Lấy tọa độ y cũ của bóng

	int player1x = player1->getX();//Lấy vị trí tọa độ x của player1
	int player2x = player2->getX();//Lấy vị trí tọa độ x của player2
	int player1y = player1->getY();//Lấy vị trí tọa độ y của player1
	int player2y = player2->getY();//Lấy vị trí tọa độ y của player2

	int player1x0 = player1->getX0();//Lấy vị trí tọa độ x cũ của player1
	int player2x0 = player2->getX0();//Lấy vị trí tọa độ x cũ của player2
	int player1y0 = player1->getY0();//Lấy vị trí tọa độ y cũ của player1
	int player2y0 = player2->getY0();//Lấy vị trí tọa độ y cũ của player2

	gotoxy(WidthGame + 10, 4); cout << "Player 1: " << player1->getScore();//in ra điểm của player1
	gotoxy(WidthGame + 10, 6); cout << "Player 2: " << player2->getScore();//in ra điểm của player2
	gotoxy(WidthGame + 10, 8); cout << "Press Q to Exit";//in ra cách để thoát game
	gotoxy(WidthGame + 10, 10); cout << "Press V to save game";

	gotoxy(WidthGame + 10, 14); cout << "Instruction Items:";
	gotoxy(WidthGame + 10, 16); cout << "L: increasing the length - s: decreasing the length";
	gotoxy(WidthGame + 10, 18); cout << "F: incresing the speed - S: decreasing the speed";
	gotoxy(WidthGame + 10, 20); cout << "D: doubling the score - H: Halfing the score";
	gotoxy(WidthGame + 10, 22); cout << "B: barier to change the direction of ball";
	gotoxy(WidthGame + 10, 24); cout << "P: showing the direction of ball";

	//ve vat pham
	for (int i = 0; i < items.size(); i++) {
		if(items[i]->getExistentItems())
			items[i]->drawItems();
	}
	
	ball->drawBall();//ve bong

	for (int i = 1; i < HeightGame - 1; i++)
	{
		gotoxy(4, i); cout << " ";//xóa bóng sau khi chạm vào thanh trượt 1
		gotoxy(WidthGame - 4, i); cout << " ";//xóa bóng sau khi chạm vào thanh trượt 2
	}

	player1->drawPaddle();//ve nguoi choi 1
	player2->drawPaddle();//ve nguoi choi 2
}

void Player::Input()//Hàm quản lý nhập liệu từ bàn phím
{
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
			else player1->moveUp(true);//di chuyen qua pham vi cua san bong
		}
		if (key == 'o' || key == 'O')//nếu người dùng nhấn phím o or O thì player2 di chuyển hướng lên 1 đơn vị
		{
			if (player2y - player2->getSpeed() > 1)
				player2->moveUp();
			else player2->moveUp(true);//di chuyen qua pham vi cua san bong
		}

		if (key == 's' || key == 'S')//nếu người dùng nhấn phím s or S thì player1 di chuyển hướng xuống 1 đơn vị
		{
			if (player1y + player1->getMaxBarPlayer() + player1->getSpeed() < HeightGame - 1)
				player1->moveDown();
			else player1->moveDown(true);//di chuyen qua pham vi cua san bong
		}
		if (key == 'k' || key == 'K')//nếu người dùng nhấn phím k or K thì player2 di chuyển hướng xuống 1 đơn vị
		{
			
			if (player2y + player2->getMaxBarPlayer() + player2->getSpeed() < HeightGame - 1)
				player2->moveDown();
			else player2->moveDown(true);//di chuyen qua pham vi cua san bong

		}
		if (key == 'q' || key == 'Q')//nếu nhấn q or Q thì quit game
		{
			quit = true;
		}
		if (key == 'v' || key == 'V') 
		{
			saveGame();
		}

		if (ball->getDirection() == STOP)//nếu hướng bóng đang là STOP thì random hướng cho bóng
			ball->randomDirection();
	}
}

void Player::Logic()//Hàm thực hiện chức năng xử lí va chạm
{
	//kiem tra su va cham cua cac items
	for (int i = 0; i < items.size(); i++) {
		items[i]->existentItems(ball);//kiem tra su va cham giua bong va vat pham
		
		if (!items[i]->getExistentItems()) {
			if (ball->getPlayer() == 1)//tac dong len  nguoi choi nao da don duoc bong truoc do
				items[i]->attributeItems(player1);
			else if (ball->getPlayer() == 2)
				items[i]->attributeItems(player2);

			items[i]->clear();//xoa vat pham khoi mang
			delete items[i];
			items.erase(items.begin() + i);
			i--;

			numItems--;//giam so luong vat pham
		}
	}

	
	ball->Move();//cho bong di chuyen

	if (ball->getIsPath()) {
		drawPathBall();
		ball->setIsPath(false);
	}

	int ballx = ball->getX();//Lấy tọa độ x của bóng
	int bally = ball->getY();//Lấy tọa độ y của bóng

	int player1x = player1->getX();//Lấy tọa độ x của player1
	int player2x = player2->getX();//Lấy tọa độ x của player2
	int player1y = player1->getY();//Lấy tọa độ y của player1
	int player2y = player2->getY();//Lấy tọa độ y của player2

	
	//left paddle
	for (int i = 0; i < player1->getMaxBarPlayer(); i++)
	{
		if (ballx == player1x + 1)//nếu tọa độ x của bóng bằng tọa độ x của player1 +1 
		{
			if (bally == player1y + i)// và tọa độ y của bóng nằm trong tọa độ y của player1 tức là bóng sẽ va chạm vào thanh trượt
			{
				ball->changeDirection((eDir)((rand() % 3) + 4));//thì hướng của bóng sẽ bị thay đổi
				player1->upScore();
				ball->setPlayer(1);
				//ball->increaseSpeed();
			}
		}
	}

	
	//right paddle
	for (int i = 0; i < player2->getMaxBarPlayer(); i++)
	{
		if (ballx == player2x - 1)//nếu tọa độ x của bóng bằng tọa độ x của player2 - 1 
		{
			if (bally == player2y + i)// và tọa độ y của bóng nằm trong tọa độ y của player2 tức là bóng sẽ va chạm vào thanh trượt
			{
				ball->changeDirection((eDir)((rand() % 3) + 1));//thì hướng của bóng sẽ bị thay đổi
				player2->upScore();
				ball->setPlayer(2);
				//ball->increaseSpeed();
			}
		}
	}

	//bottom wall
	if (bally == HeightGame - 1)//nếu bóng chạm vào tường dưới thì sẽ thay đổi hướng
	{
		//nếu bóng đang hướng DOWNRIGHT thì sẽ chuyển hướng thành UPRIGHT ,ngược lại thì UPLEFT
		ball->setInverDir(true);
	}

	//top wall
	if (bally == 1)//nếu bóng chạm vào tường trên thì sẽ thay đổi hướng
	{
		//nếu bóng đang hướng UPRIGHT thì sẽ chuyển hướng thành DOWNRIGHT ,ngược lại thì DOWNLEFT
		ball->setInverDir(true);
	}

	//right wall
	if (ballx == WidthGame - 1)//nếu chạm tường phải
	{
		player1->upScore();//tang diem
		winner = 1;
		quit = true;
	}

	//left wall
	if (ballx == 1)//nếu chạm tường trái
	{
		player2->upScore();//tang diem
		winner = 2;
		quit = true;
	}

	if (numItems == 0) {//het vat pham
		quit = true;//ket thuc game
	}

	if (quit == true) {
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
		
		clearItems();//xoa vat pham

		Win();// hien man hinh khi thang game
	}

	
}
bool Player::getQuit() { return quit; }//Hàm trả ra giá trị để quit game

void Player::saveScore(int score) {//luu top diem cao nhat
	int numScore = 10;//gioi han top diem cao nhat

	highScores.push_back(score);
	sort(highScores.begin(), highScores.end());//sap xep bang diem

	while (highScores.size() > numScore)//chi lay top diem trong pham vi
		highScores.erase(highScores.begin());

}
//ve duong path cho bong
void Player::drawPathBall() {
	Ball* virtualBall = new Ball(ball->getX(), ball->getY());//tao bong ao
	virtualBall->setDirection(ball->getDirection());

	TextColor(4);
	while (virtualBall->getX() > 2 && virtualBall->getX() < WidthGame - 2) {
		//virtualBall->drawBall();
		//

		gotoxy(virtualBall->getX(), virtualBall->getY());
		cout << "O";

		for (int i = 0; i < items.size(); i++) {
			items[i]->existentItems(virtualBall);
			items[i]->setExistent(true);
		}

		//bottom wall
		if (virtualBall->getY() == HeightGame - 1)//nếu bóng chạm vào tường dưới thì sẽ thay đổi hướng
		{
			virtualBall->setInverDir(true);
		}

		//top wall
		if (virtualBall->getY() == 1)//nếu bóng chạm vào tường trên thì sẽ thay đổi hướng
		{
			virtualBall->setInverDir(true);
		}

		virtualBall->Move();//cho bong di chuyen
	}

	TextColor(11);//cai dat mau 
	delete virtualBall;//xoa bong ao
}

void deleteTextOnScreen(int x, int y, string s) {
	gotoxy(x, y);

	for (int i = 0; i <= s.size(); i++) {
		cout << " ";
	}
}

void Player::saveGame() {
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
	listFileSave << 0 << endl;
	
	ofstream saveFile(filename + ".save", ios::out | ios::binary);
	saveFile.write((char*)&score1, sizeof(int));
	saveFile.write((char*)&score2, sizeof(int));
	ball->saveInfo(saveFile);
	player1->saveInfo(saveFile);
	player2->saveInfo(saveFile);

	for (int i = 0; i < items.size(); i++) {
		items[i]->saveInfo(saveFile);
	}

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

}

void Player::loadGame(string path) {
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

	saveFile.close();
}