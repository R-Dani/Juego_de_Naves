#include <stdio.h>
#include <Windows.h>

int main()
{
	printf("*");

	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X = 4;
	dwpos.Y = 5;

	SetConsoleCursorPosition(hcon, dwpos);
	printf("*");

	return 0;
}