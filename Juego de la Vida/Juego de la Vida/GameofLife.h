#pragma once
#include "raylib.h"
#include<vector>

class GameofLife
{
	int ancho;
	int largo;
	int cell_size;
	int N;
	int M;
	std::vector<std::vector<bool>> tablero;
	std::vector<std::vector<bool>> copia;
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	//void setCelda(int i, int j, bool estado);
	//bool getVida(int i, int j);
	std::vector<int> contarVecinos(int fila, int columna);
	bool reglas(std::vector<int> vector,bool vida);
public:
	GameofLife();
	GameofLife(int x, int y,int size);
	~GameofLife();
	virtual void Initialize();
	virtual void Runloop();
	virtual void Shutdown();
	void Draw();
	
};

