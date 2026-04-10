#include "Player.h"
#include "Nave.cpp"
#include <conio.h>
#include <stdio.h>

Player::Player(int _x, int _y) : x(_x), y(_y) {}

void Player::pintar()
{
	gotoxy(x, y); printf("  %c", 30);
	gotoxy(x, y + 1); printf(" %c%c%c", 40, 207, 41);
	gotoxy(x, y + 2); printf("%c%c %c%c", 30, 190, 190, 30);
}

void Player::borrar()
{
	gotoxy(x, y); printf("     ");
	gotoxy(x, y + 1); printf("     ");
	gotoxy(x, y + 2); printf("     ");
}

void Player::mover()
{
	char tecla = _getch();
	borrar();
	if (tecla == left) x--;
	if (tecla == right) x++;
	if (tecla == up) y--;
	if (tecla == down) y++;
	pintar();
}
