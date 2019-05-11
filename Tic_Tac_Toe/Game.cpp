#include "Game.h"
#include <iostream>
using namespace std;



Game::Game():board(),P1(1,1),P2(2,0)
{
	turn = 1;
}


Game::~Game()
{
}

void Game::start()
{
	board.display();
	while (!(board.if_win()) && !(board.if_draft())) {
		switch (turn) {
		case 1:					// Turn 1 == P1
			P1.make_move(&board);
			turn = 0;
			break;
		case 0:                 // Turn 0 == P2
			P2.make_move(&board);
			turn = 1;
			break;
		}
		board.display();
	}
	if (board.if_draft()) {
		//Draft case
		cout << "Friendship wins!";
	}
	else {
		//Turn now shows who failed.
		switch (turn) {
		case 1:
			cout << P2.name << ", You won! /n";
			break;
		case 0:
			cout << P1.name << ", You won! /n";
			break;
		}
	}
}

Game1Bot::Game1Bot(char* name) :board(), P1(1, 1), B(name, 0)
{
	turn = 1;
}

Game1Bot::~Game1Bot()
{
}

void Game1Bot::start()
{
	board.display();
	while (!(board.if_win()) && !(board.if_draft())) {
		switch (turn) {
		case 1:					// Turn 1 == P1
			P1.make_move(&board);
			turn = 0;
			break;
		case 0:                 // Turn 0 == P2
			B.make_move(&board);
			turn = 1;
			break;
		}
		board.display();
	}
	if (board.if_draft()) {
		//Draft case
		cout << "Friendship wins!";
	}
	else {
		//Turn now shows who failed.
		switch (turn) {
		case 1:
			cout << B.name << ", You won! /n";
			break;
		case 0:
			cout << P1.name << ", You won! /n";
			break;
		}
	}
}


