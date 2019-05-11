#pragma once
#include "Player.h"
#include <tuple>
#include "Board.h"
using namespace std;

class Bot :
	public Player
{
public:
	Bot(char* str, int turn);
	~Bot();
	tuple<int, int> find_winning_move(Board *board); //win the game 
	tuple<int, int> find_critic_move(Board *board);  //not let other player win
	tuple<int, int> find_move(Board *board);         //choose random empty cell
	int make_move(Board * board);
};

