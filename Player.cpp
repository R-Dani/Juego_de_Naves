#include "Player.h"
#include "Nave.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

#define up 72 
#define left 75 
#define right 77 
#define down 80

Player::Player(int _x, int _y, int _corazones, int _vidas) : x(_x), y(_y), corazones(_corazones), vidas(_vidas) {}

void Player::pintar()
{
	gotoxy(x, y);     printf("  %c", 65);
	gotoxy(x, y + 1); printf(" %c%c%c", 40, 207, 41);
	gotoxy(x, y + 2); printf("%c%c %c%c", 60, 190, 190, 62);
}

void Player::borrar()
{
	gotoxy(x, y);     printf("        ");
	gotoxy(x, y + 1); printf("        ");
	gotoxy(x, y + 2); printf("        ");
}

void Player::mover()
{
	if (_kbhit())
	{
		char tecla = _getch();
		borrar();
		if (tecla == left && x > 3) x--;
		if (tecla == right && x + 5 < 77) x++;
		if (tecla == up && y > 4) y--;
		if (tecla == down && y + 3 < 33) y++;
		if (tecla == 'e') corazones--;
		pintar();
		pintarCorazones();
	}
}

void Player::pintarCorazones()
{
	gotoxy(50, 2); printf("Vidas %d", vidas);
	gotoxy(64, 2); printf("Salud");
	gotoxy(70, 2); printf("       ");
	for (int  i = 0; i < corazones; i++)
	{
		gotoxy(70 + i, 2); printf("%c", 157);
	}
}

void Player::morir()
{
	if (corazones == 0)
	{
		borrar();
		gotoxy(x, y);   printf(" *** ");
		gotoxy(x, y+1); printf("*****");
		gotoxy(x, y+2); printf(" *** ");
		Sleep(200);

		borrar();
		gotoxy(x, y);     printf("* * *");
		gotoxy(x, y + 1); printf(" *** ");
		gotoxy(x, y + 2); printf("* * *");
		Sleep(200);
		borrar();
		vidas--;
		corazones = 3;
		pintarCorazones();
		pintar();
	}
}
