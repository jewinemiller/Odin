#include "EditorSurface.h"
#include "SDL.h"
#include <iostream>

//Constructor
EditorSurface::EditorSurface(){
	//Initialize you some variables. 
	ScreenWidth = 1280;
	ScreenHeight = 720;
	BoxWidth = 20;
	BoxHeight = 20;
	
}

//Draw the Editor's Surface
void EditorSurface::Draw(SDL_Surface* screen){
	//Draw the grid onto the screen
	DrawGrid(screen);

	for(int i = manager.getEntities().size()- 1; i >= 0; i--){
		temp.x = manager.getEntity(i).getX();
		temp.y = manager.getEntity(i).getY(); 
		temp.w = temp.h = BoxWidth; 
		SDL_FillRect(screen, &temp, manager.getEntity(i).color); 		
	}
}

void EditorSurface::addEntity(Entity e){
	manager.addEntity(e);
}

//Set the dimensions of the screen.
//This should change the window size
void EditorSurface::SetScreenDimensions(SDL_Surface* screen, int width, int height){
	//Set the video to the new screen dimensions
	screen = SDL_SetVideoMode( width, height, 0, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_NOFRAME);
	//Set the ScreenWidth and ScreenHeight to the width and height parameters. 
	ScreenWidth = width;
	ScreenHeight = height; 
	generateTiles(); 
}

//Set the dimensions of the Grid Boxes
void EditorSurface::SetGridDimensions(int boxWidth, int boxHeight){
	//Setting the Dimensions Here!
	BoxWidth = boxWidth;
	BoxHeight = boxHeight;
	generateTiles(); 
	manager.tileW = BoxWidth;
	manager.tileH = BoxHeight;
}

//Draw The Grid
void EditorSurface::DrawGrid(SDL_Surface* screen){
	//Draw all of the vertical lines
	for(int i = 0; i < ScreenWidth; i+= BoxWidth){
		temp.x = i;
		temp.y = 0;
		temp.w = 1;
		temp.h = (ScreenHeight - (ScreenHeight % BoxHeight));
		SDL_FillRect(screen, &temp, 0x000000);
	}

	//Draw all of the horizontal lines. 
	for(int j = 0; j < ScreenHeight; j += BoxHeight){
		temp.x = 0;
		temp.y = j;
		temp.w = (ScreenWidth - (ScreenWidth % BoxWidth));
		temp.h = 1;
		SDL_FillRect(screen, &temp, 0x000000);
	}
}

void EditorSurface::generateTiles(){
	manager.tiles.clear();
	for(int i = 0; i < ScreenHeight; i+= BoxHeight){
		vector<int> temp; 
		for(int j = 0; j < ScreenWidth; j += BoxWidth){
			temp.push_back(0);
		}
		manager.tiles.push_back(temp);
	}
}

//Get the width of the grid boxes.
int EditorSurface::GetGridWidth(){
	return BoxWidth;
}

//Get the height of the grid boxes. 
int EditorSurface::GetGridHeight(){
	return BoxHeight;
}

Manager EditorSurface::getManager(){
	return manager; 
}

void EditorSurface::eraseEntity(int x, int y){

	manager.tiles[y/manager.tileH][x/manager.tileW] = 0;
	manager.clearEntity(x, y);
	

	//manager.clearEntities();
}

