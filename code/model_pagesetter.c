#include "model_pagesetter.h"


void INIT_PAGE(){
	//system("mode con cols=100 lines=50 | title �ð�ǥ ���� ������");
	//system("mode con cols=%d lines=%d | title �ð�ǥ ���� ������", TOTAL_VIEW_COL, TOTAL_VIEW_ROW);
	char console[256];
	sprintf(console, "mode con cols=%d lines=%d | title �ð�ǥ ���� ������", TOTAL_VIEW_COL, TOTAL_VIEW_ROW);
	system(console);
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX); // �ܼ� ũ�� set
}

void gotoxy(int x, int y){
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void COLORSET(int backgroundColor, int textColor){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, (backgroundColor << 4) + textColor);
}