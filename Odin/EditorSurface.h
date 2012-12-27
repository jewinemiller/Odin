#include "SDL.h"
#include <iostream>
#include "Manager.h"

class EditorSurface{
public:
	EditorSurface();
	void Draw(SDL_Surface* screen);
	void SetScreenDimensions(SDL_Surface*,int,int);
	void SetGridDimensions(int, int);
	void DrawGrid(SDL_Surface*);
	int GetGridWidth();
	int GetGridHeight();
	Manager getManager();
	void addEntity (Entity e);
	void eraseEntity(int x, int y); 

private:
	int ScreenWidth, ScreenHeight, BoxWidth, BoxHeight;
	Manager manager; 
	void generateTiles(); 
	SDL_Rect temp;
};