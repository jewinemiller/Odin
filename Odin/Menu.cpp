#include "Menu.h"

Menu::Menu(){}

void Menu::Draw(SDL_Surface* screen, SDL_Surface* menuTex, int x, int y){
	SDL_Rect tempRect; 
	tempRect.w = menuTex->w;
	tempRect.h = menuTex->h;
	tempRect.x = x; 
	tempRect.y = y; 
	SDL_BlitSurface(menuTex, NULL, screen, &tempRect);  

	for(int i = 0; i < buttons.size(); i++){
		buttons[i]->Draw(screen); 
	}
}

void Menu::Update(){

}

void Menu::addButton(MenuButton* b){
	buttons.push_back(b); 
}

vector<MenuButton*> Menu::getButtons(){
	return buttons;
}