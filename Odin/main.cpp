#include "SDL.h"
#include "SDL_image.h"
#include "Validator.h"
#include "Writer.h"
#include "PreferenceManager.h"
#include <string>

using namespace std;
 const SDL_VideoInfo* screenInfo;


//Title of the Window
const char* WINDOW_TITLE = "Odin";

EditorSurface odinSurface;
Validator validate;  
Writer writer(&odinSurface);
PreferenceManager prefMan; 

bool drawPopup = false;

//Run and Draw Functions
void run();
void draw(SDL_Surface*);
SDL_Surface *load_image(string filename );
void initialize(); 
void generateMenu(); 

int tileSpawned = 1;
int maxTiles = 5; 
Uint32 color = 0x111111;

int main(int argc, char **argv)
{
	initialize(); 
	//Run the Editor
	run();
	//Once running is done, quit.
	SDL_Quit();
	return 0;
} 
SDL_Surface* screen;

void initialize(){
	//Initialize Everything
	SDL_Init( SDL_INIT_EVERYTHING);
	screenInfo = SDL_GetVideoInfo();
	//Set the caption of the window to "Odin"
	SDL_WM_SetCaption( WINDOW_TITLE, 0 );
	SDL_putenv("SDL_VIDEO_CENTERED=center");

	prefMan.loadPreferences("odin.cfg");
	//The Screen that the editor uses
	screen = SDL_SetVideoMode(screenInfo->current_w, screenInfo->current_h, 0, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_NOFRAME);
	odinSurface.SetScreenDimensions(screen, prefMan.screenWidth, prefMan.screenHeight);
	odinSurface.SetGridDimensions(prefMan.boxWidth, prefMan.boxHeight);
	draw(screen);
}

//Whether or not the editor should be running
bool editorRunning = true;
void run(){
	//An event in SDL Land. This will be intercepted when it changes.
	SDL_Event event;
	
	//While the editor is running, perform some logic and then draw.
	while (editorRunning)
	{
		
			bool isDrawing = false; 
		//Poll the event. If there has been an event, do something.
		if (SDL_PollEvent(&event))
		{
			//If the application is quitting, the editor should not be running
			if (event.type == SDL_QUIT)
			{
				editorRunning = false;
			}
			//If the Escape Key has been pressed, the editor should not be running
			if (event.type == SDL_KEYDOWN){
				if(event.key.keysym.sym == SDLK_ESCAPE){
					if(writer.write(prefMan.savePath)){
						editorRunning = false;
					}
					
				}
				/*Project Hardcoding. Replace with interface later!*/
				if(event.key.keysym.sym == SDLK_e){
					if(tileSpawned < maxTiles){
						tileSpawned++; 
					}
					else{
						tileSpawned = 1;
						color = 0x111111;
					}

					switch(tileSpawned){
					case 2:
						color = 0xa64d00;
						break;
					case 3:
						color = 0x555555;
						break;
					case 4:
						color = 0xaaaaaa;
						break;
					case 5:
						color = 0xffdb00;
						break;
					}
					
				}
			}
			//If the Left Mouse Button has been pressed, add a new entity to the screen. 
			if(event.type == SDL_MOUSEBUTTONDOWN){
				isDrawing = true; 
				if(event.button.button == SDL_BUTTON_LEFT){
					//Get the X anxd Y of the mouse. 
					int x,y;
					SDL_GetMouseState(&x, &y);
					//Change the x and the y to valid spawning positions. 
					x = validate.validatePosition(x, odinSurface.GetGridWidth());
					y = validate.validatePosition(y, odinSurface.GetGridHeight());
					//Create an entity in the x and y position that have been validated with a name of "temp"
					//Note, this code will be going away at some point to allow for dynamic naming.
					Entity e("temp", x, y, tileSpawned);
					e.color = color;
					//Add the entitiy to the surface and, by extension, its manager. 
					odinSurface.addEntity(e);
					
				}
				else if(event.button.button == SDL_BUTTON_RIGHT){
					int x, y;
					SDL_GetMouseState(&x, &y);
					x = validate.validatePosition(x, odinSurface.GetGridWidth());
					y = validate.validatePosition(y, odinSurface.GetGridHeight());
					odinSurface.eraseEntity(x, y); 
				}
			}
		}
		//Draw the editor.
		//Drawing takes place after all logic. This enables what is drawn to be the most up-to-date information. 
		if(isDrawing){
			draw(screen);}
		
	}


}

//Draw Function. Accepts the screen that everything will be drawn on.
void draw(SDL_Surface* screen){
	
	//Create a rectangle the size of the screen and white
	SDL_FillRect(screen,NULL, 0x5ca82a); 

	//Make this the only thing on the screen (Clear the screen)
	odinSurface.Draw(screen);

	
	//Refresh the screen. 
	SDL_Flip(screen); 
}
 