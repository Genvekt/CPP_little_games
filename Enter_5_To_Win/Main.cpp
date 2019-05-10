#include <iostream>
using namespace std;
int main() {
	int a = 5;
	int num = 0;
	do {
		cout << "Please, enter number. But not 5! -> ";
		cin >> a;
		num ++;
	} while (a != 5 && num < 10 );
	if (a == 5) {
		cout << "Hey! you weren't supposed to enter 5!";
	}
	else {
		cout << "Wow, you're more patient then I am, you win.";
	}
	return(0);
}
