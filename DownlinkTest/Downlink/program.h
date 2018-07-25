#pragma once
#include "SDL.h"
#include <stdio.h>
#include <iostream>


class Program
{
public:
	Program();
	~Program();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvent();
	void render();
	void clean();
	bool checkRunning();
	void drawLine();

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};



