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
	Player player(38, 30, 3, 3);
	player.pintar();
	player.pintarCorazones();
	 
	list<Asteroide*> A;
	list<Asteroide*>::iterator itA;

	for (int i=0; i<5; i++)
	{
		A.push_back(new Asteroide(rand() % 75 + 3, rand() % 5 + 4));
	}

	list<Bala*> B;
	list<Bala*>::iterator it;

	bool game_over = false;
	int puntos = 0;
	while (!game_over)
	{
		gotoxy(4, 2); printf("Puntos %d", puntos);
		if (_kbhit())
		{
			char tecla = _getch();
			if (tecla == 'a')
			{
				B.push_back(new Bala(player.X() + 2, player.Y() - 1));
			}
		}

		for (it = B.begin(); it != B.end(); it)
		{
			(*it)->mover();
			if ((*it)->fuera())
			{
				gotoxy((*it)->X(), (*it)->Y()); printf(" ");
				delete(*it);
				it = B.erase(it);
			}
			else it++;
		}

		for (itA = A.begin(); itA != A.end(); itA++)
		{
			(*itA)->mover();
			(*itA)->choque(player);
		}

		for (itA = A.begin(); itA != A.end(); itA++)
		{
			for (it = B.begin(); it != B.end(); it)
			{
				if ((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y()))
				{
					gotoxy((*it)->X(), (*it)->Y()); printf(" ");
					delete(*it);
					it = B.erase(it);

					A.push_back(new Asteroide(rand()%74 + 3, 4));
					gotoxy((*itA)->X(), (*itA)->Y()); printf(" ");
					delete(*itA);
					itA = A.erase(itA);

					puntos += 5;
				}
				else it++;
			}
		}

		if (player.vid() == 0) game_over = true;
		player.morir();
		player.mover();
		Sleep(30);
	}
	return 0;
}