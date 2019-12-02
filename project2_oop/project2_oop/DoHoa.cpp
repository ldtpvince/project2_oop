#include "DoHoa.h"

void gotoxy(int x, int y)//Hàm đưa con trỏ đến vị trí x, y
{
	COORD co = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
}
void TextColor(WORD color)//Hàm thay đổi màu 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void resizeConsole(int width, int height)//hàm thay đổi kích thước cửa sổ console 
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void AnConTro()//Hàm ẩn con trỏ
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
