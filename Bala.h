#pragma once
class Bala
{
	int x, y;
public:
	Bala(int _x, int _y): x(_x), y(_y){}
	int X() { return x; }
	int Y() { return y; }
	void mover();
	bool fuera();
};



