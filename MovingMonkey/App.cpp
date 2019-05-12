#include "App.h"
#include <iostream>
using namespace std;



App::App(int w, int h)
{
	SCREEN_WIDTH = w;
	SCREEN_HEIGHT = h;
	IMG_W = 0.0;
	IMG_H = 0.0;
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
					if (y>9) {
						y -= 10;
					}
					break;
				case SDLK_DOWN:
					if (y + IMG_H + 9< SCREEN_HEIGHT) {
						y += 10;
					}
					break;
			}
		}

		const Uint8* keystates = SDL_GetKeyboardState(NULL);
		if (keystates[SDL_SCANCODE_LEFT] & x > 9) {
			x -= 10;
		}
		else if (keystates[SDL_SCANCODE_RIGHT] & x + IMG_W + 9 < SCREEN_WIDTH) {
			x += 10;
		}
		draw(x,y);
	}
}

void App::draw(int x, int y)
{
	SDL_UpdateWindowSurface(window);
	SDL_RenderClear(renderer);
	ApplySurface(x, y, texture, renderer);
	SDL_RenderPresent(renderer);
}

void App::ApplySurface(int x, int y, SDL_Texture* tex, SDL_Renderer* rend)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	pos.w = IMG_W;
	pos.h = IMG_H;
	SDL_RenderCopy(rend, tex, NULL, &pos);
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
