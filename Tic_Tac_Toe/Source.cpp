#include <iostream>
#include "Game.h"
using namespace std;


int main() {
	int mod = 0;
	cout << "Play with bot? (1 - yes, 0 - no)\n";
	cin >> mod;
	if (mod == 1) {
		char name[5] = "BOT";
		Game1Bot game(name);
		game.start();
		
	}
	else {
		Game game;
		game.start();
	}

	return 0;
}