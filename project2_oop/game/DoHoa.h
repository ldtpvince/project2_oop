#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <ctime>
using namespace std;

#define WidthConsole            900 //chiều rộng cửa sổ console
#define HeightConsole           600 //chiều cao cửa sổ console 
#define WidthGame               50  //chiều rộng khung game
#define HeightGame              25  //chiều cao khung game
//#define MaxBarPlayer            5	//chiều dài thanh trượt


void gotoxy(int x, int y);//Hàm đưa con trỏ đến vị trí x, y
void TextColor(WORD color);//Hàm thay đổi màu 
void resizeConsole(int width, int height);//hàm thay đổi kích thước cửa sổ console 
void AnConTro();//Hàm ẩn con trỏ
