#include "Elementos.h"
Celda::Celda()
{
	i = 0; j = 0;
	posicion = { (float)i,(float)j };
	vida = true;
}
Celda::Celda(int fila, int columna, bool life)
{
	i = fila; j = columna;
	posicion = { (float)i,(float)j };
	vida = life;
}
Celda::Celda(int fila,int columna)
{
	i = fila; j = columna;
	posicion = { (float)i,(float)j };
	vida = true;
}
Celda::~Celda()
{

}
Vector2 Celda::getPosition()
{
	return posicion;
}
bool Celda::vive()
{
	return vida;
}
void Celda::muere()
{
	vida = false;
}
void Celda::revivir()
{
	vida = true;
}
void Celda::Draw()
{
	DrawRectangle(posicion.y, posicion.x, 29.0, 29.0, WHITE);
}