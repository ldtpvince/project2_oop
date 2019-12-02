#include "Player.h"

Player::Player() //Hàm tạo player
{
	srand(time(NULL));//hỗ trợ cho hàm random
	quit = false;
	score1 = score2 = 0;//Khởi tạo cho biến score1 và score2 giá trị 0 ban đầu
	ball = new Ball(WidthGame / 2, (HeightGame / 2));//khởi tạo tọa độ ban đầu cho quả bóng
	player1 = new cPaddle(2, HeightGame / 2 - (MaxBarPlayer / 2));//Khởi tạo tọa độ ban đầu cho player1
	player2 = new cPaddle(WidthGame - 2, HeightGame / 2 - (MaxBarPlayer / 2));//Khởi tạo tọa độ ban đầu cho player2
}

Player::~Player()//Hàm hủy ball, player1, player2
{
	delete ball, player1, player2;
}

void Player::ScoreUp(cPaddle* player)//hàm tăng điểm cho người chơi
{
	if (player == player1) //nếu player = player1 thì score1++ (tức là người chơi 1 có thêm 1 điểm)
	{
		score1++;
	}
	else if (player == player2)//nếu player = player2 thì score2++ (tức là người chơi 2 có thêm 1 điểm)
	{
		score2++;
	}
	ball->Reset();//reset lại tọa độ bóng
	player1->Reset();// reset lại tọa độ người chơi 1
	player2->Reset();// reset lại tọa độ người chơi 2
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
void Player::Win(int score1, int score2)
{
	//Lệnh kiểm tra người chiến thắng và dừng game
	if (score1 == 3)//nếu người chơi 1 được 3 điểm thì in ra dòng chứ player 1 win và dừng game
	{
		TextColor(10);//hàm đổi màu dòng chữ in ra bên dưới
		gotoxy(13, HeightGame / 2);//gọi hàm tọa độ để in ra đúng tọa độ mình cần in
		cout << "***** Player 1 WIN *****";
		TextColor(11);//Trả lại màu ban đầu trò chơi
		quit = true;// hàm quit trả về true
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");//lệnh dừng màn hình xem kết quả
		exit(0);//thoát 
	}
	else
		if (score2 == 3)//nếu người chơi 2 được 3 điểm thì in ra dòng chứ player 2 win và dừng game
		{
			TextColor(10);//hàm đổi màu dòng chữ in ra bên dưới
			gotoxy(13, HeightGame / 2);//gọi hàm tọa độ để in ra đúng tọa độ mình cần in
			cout << "***** Player 2 WIN *****";
			TextColor(11);//Trả lại màu ban đầu trò chơi
			quit = true;// hàm quit trả về true
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			system("pause");//lệnh dừng màn hình xem kết quả
			exit(0);//thoát
		}
}
void Player::Win1(int score1, int score2)
{
	//Lệnh kiểm tra người chiến thắng và dừng game
	if (score1 > score2)//nếu người chơi 1 nhiều điểm hơn người chơi 2 thì in ra dòng chứ player 1 win và dừng game
	{
		TextColor(10);//hàm đổi màu dòng chữ in ra bên dưới
		gotoxy(13, HeightGame / 2);//gọi hàm tọa độ để in ra đúng tọa độ mình cần in
		cout << "***** Player 1 WIN *****";
		TextColor(11);//Trả lại màu ban đầu trò chơi
		quit = true;// hàm quit trả về true
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");//lệnh dừng màn hình xem kết quả
		exit(0);//thoát 
	}
	else
		if (score2 > score1)//nếu người chơi 2 nhiều điểm hơn người chơi 1 thì in ra dòng chứ player 2 win và dừng game
		{
			TextColor(10);//hàm đổi màu dòng chữ in ra bên dưới
			gotoxy(13, HeightGame / 2);//gọi hàm tọa độ để in ra đúng tọa độ mình cần in
			cout << "***** Player 2 WIN *****";
			TextColor(11);//Trả lại màu ban đầu trò chơi
			quit = true;// hàm quit trả về true
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			system("pause");//lệnh dừng màn hình xem kết quả
			exit(0);//thoát
		}
		else // nếu hai người chơi hào điểm nhau
		{
			TextColor(10);//hàm đổi màu dòng chữ in ra bên dưới
			gotoxy(13, HeightGame / 2);//gọi hàm tọa độ để in ra đúng tọa độ mình cần in
			cout << "***** The teams Drew *****";
			TextColor(11);//Trả lại màu ban đầu trò chơi
			quit = true;// hàm quit trả về true
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			system("pause");//lệnh dừng màn hình xem kết quả
			exit(0);//thoát
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

	gotoxy(WidthGame + 10, 10); cout << "Player 1: " << score1;//in ra điểm của player1
	gotoxy(WidthGame + 10, 12); cout << "Player 2: " << score2;//in ra điểm của player2
	gotoxy(WidthGame + 10, 14); cout << "Press Q to Exit";//in ra cách để thoát game
	Win(score1, score2);

	//draw ball and delete back it
	gotoxy(ballx0, bally0); cout << " ";//tại vị trí của bóng cũ t vẽ đè lên một khoảng trắng , tác dụng như xóa đi quả bóng
	gotoxy(ballx, bally); cout << "O";// vẽ quả bóng bằng chữ O


	//fix error don't delete back it
	if (ball->getDirection() == LEFT)//nếu bóng đi sang trái
	{
		gotoxy(ballx + 1, bally); cout << " ";//xóa bóng
	}
	if (ball->getDirection() == RIGHT)// nếu bóng đi sang phải
	{
		gotoxy(ballx - 1, bally); cout << " ";//xóa bóng
	}
	for (int i = 1; i < HeightGame - 1; i++)
	{
		gotoxy(4, i); cout << " ";//xóa bóng sau khi chạm vào thanh trượt 1
		gotoxy(WidthGame - 4, i); cout << " ";//xóa bóng sau khi chạm vào thanh trượt 2
	}

	//draw player
	for (int i = 0; i < MaxBarPlayer; i++)
	{
		gotoxy(player1x, player1y + i); cout << char(219);//vẽ player1
		gotoxy(player2x, player2y + i); cout << char(219);//vẽ player2
	}

	//delete back it
	if (ball->getDirection() != STOP)//nếu hướng của bóng khác STOP
	{
		if (player1y == 1) { gotoxy(player1x, player1y + 5); cout << " "; } //xóa player1 tại tọa độ y = 1

		if (player1y0 < player1y) //nếu tọa độ y cũ < y hiện tại của player1 thì xóa y cũ đi
		{
			gotoxy(player1x0, player1y0); cout << " ";
		}
		if (player2y0 < player2y)//nếu tọa độ y cũ < y hiện tại của player2 thì xóa y cũ đi
		{
			gotoxy(player2x0, player2y0); cout << " ";
		}
		if (player1y0 > player1y)//nếu tọa độ y cũ > y hiện tại của player1 thì xóa y cũ đi
		{
			gotoxy(player1x0, player1y0 + MaxBarPlayer - 1); cout << " ";
		}
		if (player2y0 > player2y)//nếu tọa độ y cũ > y hiện tại của player2 thì xóa y cũ đi
		{
			gotoxy(player2x0, player2y0 + MaxBarPlayer - 1); cout << " ";
		}
	}
}

void Player::Input()//Hàm quản lý nhập liệu từ bàn phím
{
	ball->Move();//bóng trỏ đến hàm Move để lấy hướng di chuyển hiện tại

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
			if (player1y > 1)
				player1->moveUp();
		}
		if (key == 'o' || key == 'O')//nếu người dùng nhấn phím o or O thì player2 di chuyển hướng lên 1 đơn vị
		{
			if (player2y > 1)
				player2->moveUp();
		}

		if (key == 's' || key == 'S')//nếu người dùng nhấn phím s or S thì player1 di chuyển hướng xuống 1 đơn vị
		{
			if (player1y + MaxBarPlayer < HeightGame - 1)
				player1->moveDown();
		}
		if (key == 'k' || key == 'K')//nếu người dùng nhấn phím k or K thì player2 di chuyển hướng xuống 1 đơn vị
		{
			if (player2y + MaxBarPlayer < HeightGame - 1)
				player2->moveDown();
		}
		if (key == 'q' || key == 'Q')//nếu nhấn q or Q thì quit game
		{
			quit = true;
			Win1(score1, score2);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
			exit(0);
		}

		if (ball->getDirection() == STOP)//nếu hướng bóng đang là STOP thì random hướng cho bóng
			ball->randomDirection();
	}
}

void Player::Logic()//Hàm thực hiện chức năng xử lí va chạm
{
	int ballx = ball->getX();//Lấy tọa độ x của bóng
	int bally = ball->getY();//Lấy tọa độ y của bóng

	int player1x = player1->getX();//Lấy tọa độ x của player1
	int player2x = player2->getX();//Lấy tọa độ x của player2
	int player1y = player1->getY();//Lấy tọa độ y của player1
	int player2y = player2->getY();//Lấy tọa độ y của player2

	int score1 = 0;//khởi tạo điểm của player1 bằng 0
	int score2 = 0;//khởi tạo điểm của player2 bằng 0
	
	//left paddle
	for (int i = 0; i < MaxBarPlayer; i++)
	{
		if (ballx == player1x + 1)//nếu tọa độ x của bóng bằng tọa độ x của player1 +1 
		{
			if (bally == player1y + i)// và tọa độ y của bóng nằm trong tọa độ y của player1 tức là bóng sẽ va chạm vào thanh trượt
				ball->changeDirection((eDir)((rand() % 3) + 4));//thì hướng của bóng sẽ bị thay đổi
		}
	}

	//right paddle
	for (int i = 0; i < MaxBarPlayer; i++)
	{
		if (ballx == player2x - 1)//nếu tọa độ x của bóng bằng tọa độ x của player2 - 1 
		{
			if (bally == player2y + i)// và tọa độ y của bóng nằm trong tọa độ y của player2 tức là bóng sẽ va chạm vào thanh trượt
				ball->changeDirection((eDir)((rand() % 3) + 1));//thì hướng của bóng sẽ bị thay đổi
		}
	}

	//bottom wall
	if (bally == HeightGame - 1)//nếu bóng chạm vào tường dưới thì sẽ thay đổi hướng
	{
		//nếu bóng đang hướng DOWNRIGHT thì sẽ chuyển hướng thành UPRIGHT ,ngược lại thì UPLEFT
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
	}

	//top wall
	if (bally == 1)//nếu bóng chạm vào tường trên thì sẽ thay đổi hướng
	{
		//nếu bóng đang hướng UPRIGHT thì sẽ chuyển hướng thành DOWNRIGHT ,ngược lại thì DOWNLEFT
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
	}

	//right wall
	if (ballx == WidthGame - 1)//nếu chạm tường phải
	{
		//delete 2 player
		for (int i = 1; i < HeightGame; i++)
		{
			gotoxy(2, i); cout << " ";//Xóa player1
		}
		for (int i = 1; i < HeightGame; i++)
		{
			gotoxy(WidthGame - 2, i); cout << " ";//Xóa player2
		}
		ScoreUp(player1); //score1++
	}

	//left wall
	if (ballx == 1)//nếu chạm tường trái
	{
		//delete 2 player
		for (int i = 1; i < HeightGame; i++)
		{
			gotoxy(2, i); cout << " ";//Xóa player1
		}
		for (int i = 1; i < HeightGame; i++)
		{
			gotoxy(WidthGame - 2, i); cout << " ";//Xóa player2
		}
		ScoreUp(player2);//score2++;
	}
}
bool Player::getQuit() { return quit; }//Hàm trả ra giá trị để quit game