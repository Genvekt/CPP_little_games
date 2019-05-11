#include "Bot.h"
#include <iostream>

using namespace std;


Bot::Bot(char* str, int turn):Player(str, turn)
{
}


Bot::~Bot()
{
}


tuple<int, int> Bot::find_winning_move(Board *board) {
	for (int i = 0; i < 3; i++) {

		//Check all rows
		if (board->field[i][0] == board->field[i][1] && board->field[i][2] == -1 && board->field[i][0] == my_number) {
			return make_tuple(i, 2);
		}

		if (board->field[i][0] == board->field[i][2] && board->field[i][1] == -1 && board->field[i][0] == my_number) {
			return make_tuple(i, 1);
		}

		if (board->field[i][1] == board->field[i][2] && board->field[i][0] == -1 && board->field[i][1] == my_number) {
			return make_tuple(i, 0);
		}

		//Check all columns
		if (board->field[0][i] == board->field[1][i] && board->field[2][i] == -1 && board->field[0][i] == my_number) {
			return make_tuple(2, i);
		}

		if (board->field[0][i] == board->field[2][i] && board->field[1][i] == -1 && board->field[0][i] == my_number) {
			return make_tuple(1, i);
		}
		if (board->field[1][i] == board->field[2][i] && board->field[0][i] == -1 && board->field[i][i] == my_number) {
			return make_tuple(0, i);
		}
	}

	//Check main diaginal
	if (board->field[0][0] == board->field[1][1] && board->field[2][2] == -1 && board->field[0][0] == my_number) {
		return make_tuple(2, 2);
	}

	if (board->field[0][0] == board->field[2][2] && board->field[1][1] == -1 && board->field[0][0] == my_number) {
		return make_tuple(1, 1);
	}

	if (board->field[1][1] == board->field[2][2] && board->field[0][0] == -1 && board->field[1][1] == my_number) {
		return make_tuple(0, 0);
	}

	//Check secondary diaginal
	if (board->field[0][2] == board->field[1][1] && board->field[2][0] == -1 && board->field[0][2] == my_number) {
		return make_tuple(2, 0);
	}

	if (board->field[0][2] == board->field[2][0] && board->field[1][1] == -1 && board->field[0][2] == my_number) {
		return make_tuple(1, 1);
	}

	if (board->field[1][1] == board->field[2][0] && board->field[0][2] == -1 && board->field[1][1] == my_number) {
		return make_tuple(0, 2);
	}

	return make_tuple(-1, -1);
}

tuple<int, int> Bot::find_critic_move(Board *board)
{
	for (int i = 0; i < 3; i++) {

		//Check all rows
		if (board->field[i][0] == board->field[i][1] && board->field[i][2] == -1 && board->field[i][0] != my_number && board->field[i][0] != -1) {
			return make_tuple(i, 2);
		}

		if (board->field[i][0] == board->field[i][2] && board->field[i][1] == -1 && board->field[i][0] != my_number && board->field[i][0] != -1) {
			return make_tuple(i, 1);
		}

		if (board->field[i][1] == board->field[i][2] && board->field[i][0] == -1 && board->field[i][1] != my_number && board->field[i][1] != -1) {
			return make_tuple(i, 0);
		}

		//Check all columns
		if (board->field[0][i] == board->field[1][i] && board->field[2][i] == -1 && board->field[0][i] != my_number && board->field[0][i] != -1) {
			return make_tuple(2, i);
		}

		if (board->field[0][i] == board->field[2][i] && board->field[1][i] == -1 && board->field[0][i] != my_number && board->field[0][i] != -1) {
			return make_tuple(1, i);
		}
		if (board->field[1][i] == board->field[2][i] && board->field[0][i] == -1 && board->field[i][i] != my_number && board->field[i][i] != -1) {
			return make_tuple(0, i);
		}
	}

	//Check main diaginal
	if (board->field[0][0] == board->field[1][1] && board->field[2][2] == -1 && board->field[0][0] != my_number && board->field[0][0] != -1) {
		return make_tuple(2, 2);
	}

	if (board->field[0][0] == board->field[2][2] && board->field[1][1] == -1 && board->field[0][0] != my_number && board->field[0][0] != -1) {
		return make_tuple(1, 1);
	}

	if (board->field[1][1] == board->field[2][2] && board->field[0][0] == -1 && board->field[1][1] != my_number && board->field[1][1] != -1) {
		return make_tuple(0, 0);
	}

	//Check secondary diaginal
	if (board->field[0][2] == board->field[1][1] && board->field[2][0] == -1 && board->field[0][2] != my_number && board->field[0][2] != -1) {
		return make_tuple(2, 0);
	}

	if (board->field[0][2] == board->field[2][0] && board->field[1][1] == -1 && board->field[0][2] != my_number && board->field[0][2] != -1) {
		return make_tuple(1, 1);
	}

	if (board->field[1][1] == board->field[2][0] && board->field[0][2] == -1 && board->field[1][1] != my_number && board->field[1][1] != -1) {
		return make_tuple(0, 2);
	}

	return make_tuple(-1, -1);
		
}

tuple<int, int> Bot::find_move(Board *board)
{
	int x, y;
	do {
		x = rand() % 3;
		y = rand() % 3;
	} while (board->field[x][y] != -1);
	return make_tuple(x, y);
}

int Bot::make_move(Board *board)
{
	tuple<int, int> move = find_winning_move(board);
	if (get<0>(move) == -1) {
		move = find_critic_move(board);
	}
	if (get<0>(move) == -1) {
		move = find_move(board);
	}
	board->put(get<0>(move), get<1>(move), my_number);
	cout << name << " goes at [" << get<0>(move)+1 << "," << get<1>(move)+1 << "]\n";
	return 1;
}
