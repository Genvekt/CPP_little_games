#include "Board.h"
#include <iostream>
using namespace std;

Board::Board()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = -1;
		}
	}
}


Board::~Board()
{
}

int Board::put(int x, int y, int value) {
	if (field[x][y] == -1) { 
		field[x][y] = value;
		return(0);              //0 if cell is emply
	}
	return(-1);					//1 if cell is full
}

bool Board::if_win() {
	for (int i = 0; i < 3; i++) {
		if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != -1) {   //case there is row
			return true;
		}

		if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != -1) {   //case there is column
			return true;
		}
	}

	if (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[1][1] != -1) {       //main diagonal
		return true;
	}

	if (field[2][0] == field[1][1] && field[1][1] == field[0][2] && field[1][1] != -1) {       //secondary diaginal
		return true;
	}
	return false;
}

bool Board::if_draft()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (field[i][j] == -1) return false;
		}
	}
	return true;
}

void Board::display() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			switch (field[i][j]) {
			case 0:
				cout << " 0 ";
				break;
			case 1:
				cout << " X ";
				break;
			case -1:
				cout << " _ ";
				break;
			default:
				cout << " * ";
			}
		}
		cout << "\n";
	}
}