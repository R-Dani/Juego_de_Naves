#include "Nave.h"
#include "Asteroide.h"
#include "Player.h"
#include "Bala.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <list>
using namespace std;



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
void pintarLimites()
{
	for (int i = 2; i<78; i++)
	{
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i, 33); printf("%c", 205);
	}

	for (int i = 4; i < 33; i++)
	{
		gotoxy(2, i); printf("%c", 186);
		gotoxy(77, i); printf("%c", 186);
	}

	gotoxy(2, 3); printf("%c", 201);
	gotoxy(2, 33); printf("%c", 200);
	gotoxy(77, 3); printf("%c", 187);
	gotoxy(77, 33); printf("%c", 188);
}


int main()
{
	ocultarCursor();
	pintarLimites();
	Player player(7, 7, 3, 3);
	player.pintar();
	player.pintarCorazones();

	Asteroide asteroide1(10, 4), asteroide2(4, 8), asteroide3(15, 10);

	list<Bala*> B;
	list<Bala*>::iterator it;

	bool game_over = false;
	while (!game_over)
	{
		if (_kbhit())
		{
			char tecla = _getch();
			if (tecla == 'a')
			{
				B.push_back(new Bala(player.X() + 2, player.Y() - 1));
			}
		}

		for (it = B.begin(); it != B.end(); it++)
		{
			(*it)->mover();
		}

		asteroide1.mover(); asteroide1.choque(player);
		asteroide2.mover(); asteroide2.choque(player);
		asteroide3.mover(); asteroide3.choque(player);
		player.morir();
		player.mover();
		Sleep(30);
	}
	return 0;
}