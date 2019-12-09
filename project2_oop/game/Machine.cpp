#include "Machine.h"

void Machine::Input() {
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

		

		if (ball->getDirection() == STOP)//nếu hướng bóng đang là STOP thì random hướng cho bóng
			ball->randomDirection();
	}

	speed += 0.3;
	if (speed >= 1) {
		speed = 0;
		//neu toa do y cua may lon hon toa do y cua bong -> may di chuyen len
		if (player2y + player2->getMaxBarPlayer()/2 > bally) {
			if (player2y - player2->getSpeed() > 1)
				player2->moveUp();
			else player2->moveUp(true);
		}

		//neu toa do y cua may nho hon toa do y cua bong -> may di chuyen xuong 1 don vi
		if (player2y + player2->getMaxBarPlayer() / 2 < bally) {
			if (player2y + player2->getMaxBarPlayer() + player1->getSpeed() < HeightGame - 1)
				player2->moveDown();
			else player2->moveDown(true);
		}
	}

	
}
