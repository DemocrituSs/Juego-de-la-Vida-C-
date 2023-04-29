#pragma once
#include "raylib.h"
#include "Elementos.h"
#include <vector>

class Game
{
public:
	Game();
	~Game();
	virtual void Initialize();
	virtual void Runloop();
	virtual void Shutdown();
private:
	std::vector<Celda*> Celdas;
	std::vector<Celda*> Celdas_Copia;
	int cell_size = 30;
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void comprobarVecinos();
};


