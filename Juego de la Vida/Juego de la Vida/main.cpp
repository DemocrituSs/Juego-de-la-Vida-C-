#include "Game.h"
#include "GameofLife.h"
int main()
{
	GameofLife game;

	game.Initialize();
	game.Runloop();
	game.Shutdown();

	return 0;
}