#include <stdio.h>
#include <Windows.h>
#include <conio.h>

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X = 4;
	dwpos.Y = 5;

	SetConsoleCursorPosition(hcon, dwpos);
}

int main()
{
	int x = 10, y = 10;
	gotoxy(x, y); printf("*");

	bool game_over = false;
	while (!game_over)
	{
		if (_kbhit())
		{
			char tecla = _getch();
			gotoxy(x, y);
			printf(" ");
			if (tecla == 'j') x--;
			if (tecla == 'l') x++;
			if (tecla == 'i') y--;
			if (tecla == 'k') y++;
			gotoxy(x, y);
			printf("*");
		}

		Sleep(30);
	}
	return 0;
}