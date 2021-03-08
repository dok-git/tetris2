// tetris.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <conio.h>
#include "ctime"
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include "MainController.h"
#include "GameConfig.h"

using namespace std;

void SetWindowSize(int Width, int Height)
{
	_COORD coord{};
	coord.X = Width+10;
	coord.Y = Height;

	_SMALL_RECT Rect{};
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}

void SetWindowPosition() {
	HWND hwd = GetDesktopWindow();
	HWND hwc = GetConsoleWindow();
	RECT rd, rc;
	GetWindowRect(hwd, &rd);
	GetWindowRect(hwc, &rc);
	MoveWindow(hwc, (rd.right - rc.right) / 2, (rd.bottom - rc.bottom) / 2, 550, 600, TRUE);
	SetWindowLong(hwc, GWL_STYLE, GetWindowLong(hwc, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void initWindow() {
	SetConsoleTitle(L"TETRIS");// вывод заголовка окна
	SetWindowSize(GameConfig::WIDTH, GameConfig::HEIGHT + 3);
	SetWindowPosition();
}


int main()
{
	initWindow();
	srand((unsigned)time(0));

	MainController mainController;
	mainController.start();
}