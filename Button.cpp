#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "Button.h"

Button::Button(SDL_Renderer* render_ex,int x, int y, const char* text){
	*position={x,y,WIDTH,HEIGHT};
	render=render_ex;
	police=TTF_OpenFont("Fonts/numero.ttf",20);
	name=text;
	write();
	draw();
}
void Button::write(){

	surface=TTF_RenderText_Blended(police, name ,noir);
	if (surface==NULL) printf("fail by surface");
	SDL_GetClipRect(surface, ecriture);
	ecriture->x=position->x+(WIDTH/2)-(strlen(name)*3.25)-17;
	ecriture->y=position->y+10;
	texture=SDL_CreateTextureFromSurface(render,surface);
	if (texture==NULL) printf("fail by texture");
	SDL_FreeSurface(surface);
}

void Button::draw(){
	SDL_SetRenderDrawColor(render,200,200,200,255);
	SDL_RenderFillRect(render, position);

	SDL_RenderCopy(render, texture, NULL,ecriture);
}

int Button::pressed(SDL_Event* event){
	int mouse_x=event->button.x;
	int mouse_y=event->button.y;
	if (mouse_x>position->x && mouse_x<position->x+WIDTH && mouse_y>position->y && mouse_y<position->y+HEIGHT) return 1;
	else return 0;
}

void Button::close(){
    TTF_CloseFont(police);
    SDL_DestroyTexture(texture);
}
