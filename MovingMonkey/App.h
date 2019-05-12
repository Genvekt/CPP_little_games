#pragma once
#include "SDL.h"
#include <iostream>

class App
{
public:
	App(int w, int h);
	~App();

	void set_image(std::string file, float w, float h);
	void update();
	void draw(int x, int y);
private:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	float IMG_W;
	float IMG_H;
	void ApplySurface(int x, int y, SDL_Texture* tex, SDL_Renderer* rend);
	SDL_Texture* LoadImage(std::string file);

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Event event;
};

