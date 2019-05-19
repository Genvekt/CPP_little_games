#include "App.h"
#include <iostream>
#include <string>
using namespace std;



App::App(int w, int h)
{
	TTF_Init();
	SCREEN_WIDTH = w;
	SCREEN_HEIGHT = h;
	IMG_W = 0.0;
	IMG_H = 0.0;
	step = 10;
	window = SDL_CreateWindow("", 
							SDL_WINDOWPOS_CENTERED, 
							SDL_WINDOWPOS_CENTERED,
							SCREEN_WIDTH,
							SCREEN_HEIGHT,
							SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!window)
	{
		cout << "Failed to create window\n";
		cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}

	texture = nullptr;
	message = nullptr;
	banana = LoadImage("banana.bmp");
}


App::~App()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void App::set_image(std::string file, float w, float h)
{
	texture = LoadImage(file);
	IMG_W = w;
	IMG_H = h;
}

void App::update()
{
	int x = 0, y = 0;
	int bx = 0, by = 0;
	int score = 0;

	bx = rand() % SCREEN_WIDTH*0.9;
	by = rand() % SCREEN_HEIGHT*0.9;

	string s = "Score: " + to_string(score);
	const char* words = s.c_str();
	make_message(words);


	bool keep_window_open = true;
	while (keep_window_open)
	{
		while (SDL_PollEvent(&event) > 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				keep_window_open = false;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					if (y > 9) {
						y -= 10;
					}
					break;
				case SDLK_DOWN:
					if (y + IMG_H + 9 < SCREEN_HEIGHT) {
						y += 10;
					}
					break;
				}
			}

			const Uint8* keystates = SDL_GetKeyboardState(NULL);

			//LEFT
			switch (keystates[SDL_SCANCODE_LEFT]) {
			case 1:
				if (x >= step) {
					x -= step;
				}
				else {
					x = 0;
				}
			}

			//RIGHT
			switch (keystates[SDL_SCANCODE_RIGHT]) {
			case 1:
				if (x + IMG_W + (step - 1) < SCREEN_WIDTH) {
					x += step;
				}
				else {
					x = SCREEN_WIDTH - IMG_W;
				}
			}

			//UP
			switch (keystates[SDL_SCANCODE_UP]) {
			case 1:
				if (y >= step) {
					y -= step;
				}
				else {
					y = 0;
				}
			}

			//DOWN
			switch (keystates[SDL_SCANCODE_DOWN]) {
			case 1:
				if (y + IMG_H + (step - 1) < SCREEN_HEIGHT) {
					y += step;
				}
				else {
					y = SCREEN_HEIGHT - IMG_H;
				}
			}

			//increase step
			switch (keystates[SDL_SCANCODE_Q]) {
			case 1:
				if (step < 100){
					step += 5;
				}
			}

			//decrease step
			switch (keystates[SDL_SCANCODE_W]) {
			case 1:
				if (step > 5) {
					step -= 5;
				}
			}

			//catch banana
			if (bx >= x && bx <= (x + IMG_W) && by >= y && by < (y + IMG_H)) {
				score += 1;

				string s = "Score: " + to_string(score);
				const char* words = s.c_str();
				make_message(words);

				bx = rand() % SCREEN_WIDTH * 0.9;
				by = rand() % SCREEN_HEIGHT * 0.9;
			}




		}
	
		draw(x,y, bx, by);
	}

}

void App::draw(int x, int y, int a, int b) 
{
	SDL_UpdateWindowSurface(window);
	SDL_RenderClear(renderer);

	ApplySurface(a, b, SCREEN_WIDTH*0.1, SCREEN_HEIGHT*0.1, banana, renderer);
	ApplySurface(x, y,IMG_W, IMG_H, texture, renderer);
	ApplySurface(0, 0, 100, 50, message, renderer);

	SDL_RenderPresent(renderer);
}

void App::ApplySurface(int x, int y, int w, int h, SDL_Texture* tex, SDL_Renderer* rend)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	pos.w = w;
	pos.h = h;
	SDL_RenderCopy(rend, tex, NULL, &pos);
}

void App::make_message(const char* words)
{
	TTF_Font* font = TTF_OpenFont("Amatic.ttf", 50); //this opens a font style and sets a size

	SDL_Color White = { 255, 255, 255 , 0};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, words, White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
}

SDL_Texture* App::LoadImage(string file)
{
	SDL_Surface* loadedImage = nullptr;
	SDL_Texture* texture = nullptr;
	loadedImage = SDL_LoadBMP(file.c_str());
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	else
		cout << SDL_GetError() << endl;
	return texture;
}
