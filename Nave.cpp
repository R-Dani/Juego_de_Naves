#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "Player.h"

#define up 72
#define left 75
#define right 77
#define down 80

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X = x;
	dwpos.Y = y;

	SetConsoleCursorPosition(hcon, dwpos);
}

void ocultarCursor()
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 50;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hcon, &cci);
}


int main()
{
	ocultarCursor();
	int x = 10, y = 10;
	gotoxy(x,y); printf("*");

	bool game_over = false;
	while (!game_over)
	{
		char tecla = _getch();
		gotoxy(x,y); printf(" ");
		if (tecla == left) x--;
		if (tecla == right) x++;
		if (tecla == up) y--;
		if (tecla == down) y++;
		gotoxy(x,y); printf("*");

	}
	return 0;
}