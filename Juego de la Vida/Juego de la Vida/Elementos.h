#pragma once
#include "raylib.h"
class Celda
{
private:
	int cell_size = 30;
	int i;
	int j;
	bool vida;
	Vector2 posicion;
public:
	Celda();
	Celda(int fila, int columna);
	Celda(int fila, int columna, bool life);
	~Celda();
	Vector2 getPosition();
	bool vive();
	void muere();
	void revivir();
	void Draw();
};



