#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>

class App
{
public:
	App(int w, int h);
	~App();

	void set_image(std::string file, float w, float h);
	void update();
	void draw(int x, int y, int a, int b);

private:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT; 
	int step;
	float IMG_W;
	float IMG_H;
	void ApplySurface(int x, int y, int w, int h, SDL_Texture* tex, SDL_Renderer* rend);
	void make_message(const char* words);
	SDL_Texture* LoadImage(std::string file);

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Texture* message;
	SDL_Texture* banana;
	SDL_Event event;
};

