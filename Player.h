#pragma once

class Player
{
	int x, y;
	int corazones;
	int vidas;
public:
	Player(int _x, int _y, int _corazones, int _vidas);
	void pintar();
	void borrar();
	void mover();
	void pintarCorazones();
	void morir();
};


