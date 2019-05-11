#pragma once
#include "Board.h"
#include "Player.h"
#include "Bot.h"

class Game
{
	Board board;
	Player P1;
	Player P2;
	int turn;
public:
	Game();
	~Game();
	void start();
};

class Game1Bot
{
	Board board;
	Player P1;
	Bot B;
	int turn;
public:
	Game1Bot(char* name);
	~Game1Bot();
	void start();
};