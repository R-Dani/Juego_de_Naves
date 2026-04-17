#include "Asteroide.h"
#include "Nave.h"
#include "Player.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

Asteroide::Asteroide(int _x, int _y) : x(_x), y(_y){}

void Asteroide::pintar()
{
	gotoxy(x, y); printf("%c", 184);
}

void Asteroide::mover()
{
	gotoxy(x, y); printf(" ");
	y++;
	if (y>32)
	{
		x = rand() % 71 + 4;
		y = 4;
	}
	pintar();
}
void Asteroide::choque(class Player& P)
{
	if (x >= P.X() && x < P.X() + 6 && y >=P.Y() && y <=P.Y()+2)
	{
		P.cor();
		P.borrar();
		P.pintar();
		P.pintarCorazones();
		x = rand() % 71 + 4;
		y = 4;
	}
}