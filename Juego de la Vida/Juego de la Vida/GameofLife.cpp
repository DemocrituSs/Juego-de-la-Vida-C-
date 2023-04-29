#include "GameofLife.h"
GameofLife::GameofLife()
{
	ancho=800;
	largo=800;
	cell_size=20;
	N = largo / cell_size; M = ancho / cell_size;
	for (int i = 0; i < N; i++)
	{
		std::vector<bool> fila;
		for (int j = 0; j < M; j++)
		{
			fila.push_back(false);
		}
		tablero.push_back(fila);
	}
	copia = tablero;
}
GameofLife::GameofLife(int x, int y,int size)
{
	ancho = x; largo = y; cell_size = size;
	N = largo / cell_size; M = ancho / cell_size;
	for (int i = 0; i < N; i++)
	{
		std::vector<bool> fila;
		for (int j = 0; j < M; j++)
		{
			fila.push_back(false);
		}
		tablero.push_back(fila);
	}
	copia = tablero;
}
GameofLife::~GameofLife()
{

}
/*
void GameofLife::setCelda(int i, int j, bool estado)
{
	tablero[i][j] = estado;
}
bool GameofLife::getVida(int i, int j)
{
	return tablero[i][j];
}
*/

void GameofLife::Initialize()
{
	SetTargetFPS(60);
	InitWindow(800, 800, "Juego de la Vida");
	//oscilador
	tablero[30][10] = true;
	tablero[31][10] = true;
	tablero[32][10] = true;
	//cuadrado fijo
	tablero[10][10] = true;
	tablero[10][11] = true;
	tablero[11][11] = true;
	tablero[11][10] = true;
	//
	tablero[9][31] = true;
	tablero[10][32] = true;
	tablero[11][30] = true;
	tablero[11][31] = true;
	tablero[11][32] = true;
	//tablero[12][12] = true;
	//tablero[21][21] = true;
	copia = tablero;
}
void GameofLife::Runloop()
{
	while (!WindowShouldClose())
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}
void GameofLife::Shutdown()
{
	CloseWindow();
}
void GameofLife::ProcessInput()
{
	//No hay ningún input
}
void GameofLife::UpdateGame()
{

	tablero = copia;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			bool estado = reglas(contarVecinos(i, j),tablero[i][j]);
			copia[i][j] = estado;
		}
	}
}
void GameofLife::GenerateOutput()
{
	double startTime = GetTime();
	//Wait(1000);
	while ((GetTime() - startTime) < 0.5)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		Draw();
		EndDrawing();
	}
}
void GameofLife::Draw()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tablero[i][j])
			{
				DrawRectangle(i * cell_size, j * cell_size, cell_size - 1, cell_size - 1, WHITE);
			}
		}
	}
}
bool GameofLife::reglas(std::vector<int> vector,bool vida)
{
	if(vida)
	{
		return (vector[0] == 3 || vector[0] == 4);
	}
	else
	{
		return(vector[0] == 3);
	}
}
std::vector<int> GameofLife::contarVecinos(int fila, int columna)
{
	int cont_vivos = 0; int cont_muertos = 9;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (fila + i >= 0 && fila + i < N && columna + j >= 0 && columna + j < M)
			{
				if (tablero[fila + i][columna + j])
				{
					cont_vivos++;
					cont_muertos--;
				}
			}
		}
	}
	std::vector<int> vector = { cont_vivos,cont_muertos };
	return vector;
}