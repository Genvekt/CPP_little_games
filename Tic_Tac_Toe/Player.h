#pragma once
#include <tuple>
#include "Board.h"
class Player
{
	
public:
	int my_number;
	Player(char*str, int my_num);
	Player(int num, int my_num);
	~Player();
	char name[20];
	int make_move(Board *board);
};

