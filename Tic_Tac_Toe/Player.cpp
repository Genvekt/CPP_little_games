#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string.h>
using namespace std;


Player::Player(char *str, int my_num)
{
	strcpy_s(name, str);
	my_number = my_num;
}

Player::Player(int num, int my_num)
{
	cout << "Player" << num << ", enter your name: ";
	cin >> name;
	my_number = my_num;
}


Player::~Player()
{
}

int Player::make_move(Board *board)
{
	int x, y;
move:
	cout << name << ", input row and column number:";
	cin >> x;
	cin >> y;

	if (x < 1 || x>3 || y < 1 || y>3) {
		cout << "!! Wrong input, there is 3 rows and 3 columns. Try again !! \n";
		goto move;
	}

	if (board->put(x - 1, y - 1, my_number) != 0) {
		cout << "!! Wrong input, cell already full. Try again !! \n";
		goto move;
	}
	return 0;
}
