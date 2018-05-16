#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "Entry.h"

void write(SDL_Renderer* render, TTF_Font* police, const char* characters, SDL_Rect* rect){
	SDL_Rect* position=new SDL_Rect;
	SDL_Color noir={0,0,0};
	SDL_Surface* text=NULL;
	text=TTF_RenderText_Blended(police, characters,noir);
	if (text==NULL) printf("fail by surface");
	SDL_GetClipRect(text, position);
	position->x=rect->x+10;
	position->y=rect->y+10;
	SDL_Texture* texture=SDL_CreateTextureFromSurface(render,text);
	if (texture==NULL) printf("fail by texture");
	SDL_FreeSurface(text);
	SDL_RenderCopy(render, texture, NULL, position);
}

Entry::Entry(SDL_Renderer* render_ex, SDL_Rect* rect,int max){
	render=render_ex;
	*position=*rect;
	HEIGHT=rect->h;
	WIDTH=rect->w;
	police=TTF_OpenFont("Fonts/numero.ttf",position->h/2);
	*border={position->x+bord_w,position->y+bord_w,position->w-(bord_w*2),position->h-(bord_w*2)};
	draw();
	*ecriture=*border;
	limite=max;
	origin_max=max;
	length=0;
	*marker={0,border->y+2,2,border->h-4};
}

void Entry::draw(){
	SDL_SetRenderDrawColor(render, 0,0,0,255);
	SDL_RenderFillRect(render, position);
	SDL_SetRenderDrawColor(render, 255,255,255,255);
	SDL_RenderFillRect(render, border);
}

void Entry::pressed(SDL_Event* event){
	int mouse_x=event->button.x;
	int mouse_y=event->button.y;
	if (mouse_x>position->x && mouse_x<position->x+WIDTH && mouse_y>position->y && mouse_y<position->y+HEIGHT){
		selection=true;
	}
	else selection=false;
}

void Entry::write(){
	if (selection){
		SDL_SetRenderDrawColor(render, 210,210,210,255);
		SDL_RenderFillRect(render, border);
		}
	if (!selection){
		SDL_SetRenderDrawColor(render, 255,255,255,255);
		SDL_RenderFillRect(render, border);
    }
    int x=border->x+10;
	for ( int i=0; i<length;i++){
        SDL_Surface* surface=TTF_RenderText_Blended(police, (const char*)buffer[i], noir);
		SDL_GetClipRect(surface, ecriture);
		ecriture->x=x;
        ecriture->y=border->y+10;
        if ((x+ecriture->w+3)>(border->x+border->w)){
            limite=i;
            return;
        }
		texture=SDL_CreateTextureFromSurface(render,surface);
		if (texture==NULL) printf("fail by texture\n");
		SDL_FreeSurface(surface);
		SDL_RenderCopy(render, texture, NULL, ecriture);
		x+=ecriture->w+2;
	}
	marker->x=x+1;
	SDL_SetRenderDrawColor(render,0,0,0,255);
	SDL_RenderFillRect(render, marker);
}

void Entry::clear(){
	length=0;
}

void Entry::close(){
    TTF_CloseFont(police);
}

void Entry::fill(SDL_Event* event){
    printf("%d\n",length);
	if (length<limite || event->key.keysym.sym==SDLK_BACKSPACE){
		ecrire=true;
		switch(event->key.keysym.sym){
			case SDLK_1:
				buffer[length]=(char*)"1";
				break;
			case SDLK_2:
				buffer[length]=(char*)"2";
				break;
			case SDLK_3:
				buffer[length]=(char*)"3";
				break;
			case SDLK_4:
				buffer[length]=(char*)"4";
				break;
			case SDLK_5:
				buffer[length]=(char*)"5";
				break;
			case SDLK_6:
				buffer[length]=(char*)"6";
				break;
			case SDLK_7:
				buffer[length]=(char*)"7";
				break;
			case SDLK_8:
				buffer[length]=(char*)"8";
				break;
			case SDLK_9:
				buffer[length]=(char*)"9";
				break;
			case SDLK_0:
				buffer[length]=(char*)"0";
				break;
			case SDLK_BACKSPACE:
				ecrire=false;
				limite=origin_max;
				break;
			default:
			    buffer[length]=0;
				break;
		}
        if (!numbers){
            const Uint8* state=SDL_GetKeyboardState(NULL);
            if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
                maj=true;
            else maj=false;
            switch(event->key.keysym.sym){
                case SDLK_a:
                    buffer[length]=(char*)"a";
                    if (maj)
                        buffer[length]=(char*)"A";
                    break;
                case SDLK_b:
                    buffer[length]=(char*)"b";
                    if (maj)
                        buffer[length]=(char*)"B";
                    break;
                case SDLK_c:
                    buffer[length]=(char*)"c";
                    if (maj)
                        buffer[length]=(char*)"C";
                    break;
                case SDLK_d:
                    buffer[length]=(char*)"d";
                    if (maj)
                        buffer[length]=(char*)"D";
                    break;
                case SDLK_e:
                    buffer[length]=(char*)"e";
                    if (maj)
                        buffer[length]=(char*)"E";
                    break;
                case SDLK_f:
                    buffer[length]=(char*)"f";
                    if (maj)
                        buffer[length]=(char*)"F";
                    break;
                case SDLK_g:
                    buffer[length]=(char*)"g";
                    if (maj)
                        buffer[length]=(char*)"G";
                    break;
                case SDLK_h:
                    buffer[length]=(char*)"h";
                    if (maj)
                        buffer[length]=(char*)"H";
                    break;
                case SDLK_i:
                    buffer[length]=(char*)"i";
                    if (maj)
                        buffer[length]=(char*)"I";
                    break;
                case SDLK_j:
                    buffer[length]=(char*)"j";
                    if (maj)
                        buffer[length]=(char*)"J";
                    break;
                case SDLK_k:
                    buffer[length]=(char*)"k";
                    if (maj)
                        buffer[length]=(char*)"K";
                    break;
                case SDLK_l:
                    buffer[length]=(char*)"l";
                    if (maj)
                        buffer[length]=(char*)"L";
                    break;
                case SDLK_m:
                    buffer[length]=(char*)"m";
                    if (maj)
                        buffer[length]=(char*)"M";
                    break;
                case SDLK_n:
                    buffer[length]=(char*)"n";
                    if (maj)
                        buffer[length]=(char*)"N";
                    break;
                case SDLK_o:
                    buffer[length]=(char*)"o";
                    if (maj)
                        buffer[length]=(char*)"O";
                    break;
                case SDLK_p:
                    buffer[length]=(char*)"p";
                    if (maj)
                        buffer[length]=(char*)"P";
                    break;
                case SDLK_q:
                    buffer[length]=(char*)"q";
                    if (maj)
                        buffer[length]=(char*)"Q";
                    break;
                case SDLK_r:
                    buffer[length]=(char*)"r";
                    if (maj)
                        buffer[length]=(char*)"R";
                    break;
                case SDLK_s:
                    buffer[length]=(char*)"s";
                    if (maj)
                        buffer[length]=(char*)"S";
                    break;
                case SDLK_t:
                    buffer[length]=(char*)"t";
                    if (maj)
                        buffer[length]=(char*)"T";
                    break;
                case SDLK_u:
                    buffer[length]=(char*)"u";
                    if (maj)
                        buffer[length]=(char*)"U";
                    break;
                case SDLK_v:
                    buffer[length]=(char*)"v";
                    if (maj)
                        buffer[length]=(char*)"V";
                    break;
                case SDLK_w:
                    buffer[length]=(char*)"w";
                    if (maj)
                        buffer[length]=(char*)"W";
                    break;
                case SDLK_x:
                    buffer[length]=(char*)"x";
                    if (maj)
                        buffer[length]=(char*)"X";
                    break;
                case SDLK_y:
                    buffer[length]=(char*)"y";
                    if (maj)
                        buffer[length]=(char*)"Y";
                    break;
                case SDLK_z:
                    buffer[length]=(char*)"z";
                    if (maj)
                        buffer[length]=(char*)"Z";
                    break;
                case SDLK_SPACE:
                    printf("a");
                    buffer[length]=(char*)" ";
                    break;

                }
        }
		if (ecrire && buffer[length] && length+1<limite){
			length++;
			write();
		}
		else if (!ecrire && length!=0){
			length--;
			write();
		}

	}
}

