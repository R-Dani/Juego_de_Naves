#pragma once

class Player
{
	int x, y;
	int corazones;
	int vidas;
public:
	Player(int _x, int _y, int _corazones, int _vidas);
	int X() { return x; }
	int Y() { return y; }
	int vid() { return vidas; }
	void cor() { corazones--; }
	void pintar();
	void borrar();
	void mover();
	void pintarCorazones();
	void morir();
};


