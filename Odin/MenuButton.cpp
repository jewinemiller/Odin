#include "MenuButton.h"
#include "SDL_image.h"

using namespace std; 
MenuButton::MenuButton(){

}
MenuButton::MenuButton(int x, int y, int w, int h, string text, SDL_Surface* tex){
	this->X = x;
	this->Y = y;
	this->W = w;
	this->H = h;
	this->texture = tex;
	this->btnRect.x = X;
	this->btnRect.y = y;
	this->btnRect.w = W;
	this->btnRect.h = H;
	this->text = text; 

}

int MenuButton::getWidth(){
	return this->W;
}

int MenuButton::getHeight(){
	return this->H;
}

void MenuButton::Draw(SDL_Surface* screen){

	SDL_BlitSurface(this->texture, NULL, screen, &this->btnRect); 
}

SDL_Rect* MenuButton::getBounds(){
	return &this->btnRect;
}