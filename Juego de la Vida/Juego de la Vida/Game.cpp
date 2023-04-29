#include "Game.h"
#include "raylib.h"
#include <iostream>

Vector2 sumar(Vector2 v1, Vector2 v2)
{
	return { v1.x + v2.x,v1.y + v2.y };
}
bool igual(Vector2 v1, Vector2 v2)
{
	return v1.x == v2.x && v1.y == v2.y;
}
Game::Game()
{

}
Game::~Game()
{

}
//Métodos más importantes
void Game::Initialize()
{
	SetTargetFPS(60);
	InitWindow(800, 600, "Juego de la Vida");
	for (int i = -1; i < 1; i++)
	{
		
		for (int j = -1; j < 4; j++)
		{
			bool life = i == 0 && (j == 0 || j == 1 || j == 2);
			Celda* cell = new Celda(300 + i*cell_size, 400 + j*cell_size, life);
			Celdas.push_back(cell);
			Celdas_Copia.push_back(cell);
		}
	}
}
void Game::Runloop()
{
	while (!WindowShouldClose())
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}
void Game::Shutdown()
{
	CloseWindow();
}
//Métodos del loop de juego
void Game::ProcessInput()
{
	//No hay ningún input
}
void Game::UpdateGame()
{
	//comprobarVecinos();
}
void Game::GenerateOutput()
{
	double startTime = GetTime();
	//Wait(1000);
	while ((GetTime() - startTime) < 1)
	{
		BeginDrawing();
		//ClearBackground(BLACK);
		for (Celda* cell : Celdas)
		{
			if (cell->vive())
			{
				cell->Draw();
			}
		}
		EndDrawing();
	}
}
void Game::comprobarVecinos()
{
	for (Celda* celda : Celdas)
	{
		Vector2 pos = celda->getPosition();
		int cant_vivas = 0;
		int cant_muertas = 8;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (i != 0 && j != 0)
				{
					pos = sumar(pos, { (float)i*cell_size,(float)j*cell_size });
					for (Celda* cell : Celdas_Copia)
					{
						if (igual(cell->getPosition(), pos) && cell->vive())
						{
							cant_vivas++;
							cant_muertas--;
						}
					}
				}
			}
		}
		std::cout << "x= "<<celda->getPosition().x << " y= "<<celda->getPosition().x << std::endl;
		std::cout <<"cant vivas = "<<cant_vivas<< " cant muertas = " << cant_muertas << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		if (celda->vive())
		{
			if (cant_vivas != 2 && cant_vivas != 3)
			{
				celda->muere();
			}
		}
		else
		{
			if (cant_vivas == 3)
			{
				celda->revivir();
			}
		}
	}
	Celdas_Copia = Celdas;
}