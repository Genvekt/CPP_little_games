#include "SDL.h"
#include "App.h"
#include <string>
#include <iostream>
using namespace std;


int main(int argc, char* argv[]) {

	App app(400, 400);
	app.set_image("img.bmp",0.2*400, 0.2*400);
	app.update();
	return 0;
}