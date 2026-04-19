#include "Bala.h"
#include "Nave.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>


void Bala::mover()
{
	gotoxy(x, y); printf(" ");
	y--;
	gotoxy(x, y); printf("*");
}

bool Bala::fuera()
{
	if (y == 4) return true;

}