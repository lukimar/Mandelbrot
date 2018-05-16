#ifndef ENTRY_H
#define ENTRY_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>


class Entry{
	private:
		SDL_Rect* position=new SDL_Rect;
		SDL_Rect* border=new SDL_Rect;
		SDL_Rect* ecriture=new SDL_Rect;
		SDL_Rect* marker=new SDL_Rect;
		SDL_Renderer* render;
		SDL_Texture* texture;
		SDL_Color noir={0,0,0};
		SDL_Color blanc={255,255,255};
		TTF_Font* police;
		int bord_w=2;
		int HEIGHT;
		int WIDTH;
		int origin_max;
		bool ecrire;
		bool maj=false;

	public:
		Entry(SDL_Renderer* render_ex,SDL_Rect* rect, int max );
		bool selection=false;
        bool numbers=false;
		int limite;
		int length;
		void pressed(SDL_Event* event);
		void fill(SDL_Event* event);
		void draw();
		void write();
		void clear();
		void close();
		char* buffer[200];
};

#endif
