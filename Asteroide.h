#pragma once
class Asteroide
{
	int x, y;
public:
	Asteroide(int _x, int _y);
	void pintar();
	void mover();
	void choque(class Player &P);
	int X() { return x; }
	int Y() { return y; }
};

