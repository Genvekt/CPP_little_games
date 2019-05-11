#pragma once
class Board
{
	
public:
	Board();  //constructor
	~Board(); //destructor
	int put(int x, int y, int value);
	bool if_win();
	bool if_draft();
	void display();
	int field[3][3];


};

