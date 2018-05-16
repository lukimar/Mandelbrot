#ifndef BUTTON_H
#define BUTTON_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>

class Button{
	private:
		SDL_Renderer* render;
		SDL_Rect* position=new SDL_Rect;
		SDL_Rect* ecriture=new SDL_Rect;
		SDL_Event event;
		TTF_Font* police;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Color noir={0,0,0};
		const char* name;
		int WIDTH=120, HEIGHT=50;
	public:
		Button(SDL_Renderer* render_ex, int x, int y, const char* text);
		int pressed(SDL_Event* event);
		void draw();
		void write();
        void close();
};


#endif
