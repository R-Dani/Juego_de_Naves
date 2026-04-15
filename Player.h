#pragma once

class Player
{
	int x, y;
	int corazones;
public:
	Player(int _x, int _y, int _corazones);
	void pintar();
	void borrar();
	void mover();
	void pintarCorazones();
};


