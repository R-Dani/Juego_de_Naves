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
	Player player(7, 7);
	player.pintar();
	bool game_over = false;
	while (!game_over)
	{
		player.mover();
	}
	return 0;
}