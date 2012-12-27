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

//Editor Surface, Validator, File Writer, and Preference Manager
EditorSurface odinSurface;
Validator validate;  
Writer writer(&odinSurface);
PreferenceManager prefMan; 

bool drawPopup = false;

//Run and Draw Functions
void run();
void draw(SDL_Surface*);
//Function to load an image from a file
SDL_Surface *load_image(string filename );
//Initialization function
void initialize(); 

void generateMenu(); 

//Tile that is being spawned, how many types of tiles, and tile color.
//Note that this is hard coded and needs to be changed to actual textures later. 
int tileSpawned = 1;
int maxTiles = 5; 
Uint32 color = 0x111111;

int main(int argc, char **argv)
{
	//Initialize the editor
	initialize(); 
	//Run the Editor
	run();
	//Once running is done, quit.
	SDL_Quit();
	return 0;
} 
//Main screen
SDL_Surface* screen;

void initialize(){
	//Initialize Everything
	SDL_Init( SDL_INIT_EVERYTHING);
	screenInfo = SDL_GetVideoInfo();
	//Set the caption of the window to "Odin"
	SDL_WM_SetCaption( WINDOW_TITLE, 0 );
	SDL_putenv("SDL_VIDEO_CENTERED=center");
	//Load preferences from the designated file.
	prefMan.loadPreferences("odin.cfg");
	//The Screen that the editor uses
	screen = SDL_SetVideoMode(screenInfo->current_w, screenInfo->current_h, 0, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_NOFRAME);
	//Reset the screen to the proper dimensions. This needs to be done for the editor. 
	odinSurface.SetScreenDimensions(screen, prefMan.screenWidth, prefMan.screenHeight);
	//Set the grid dimensions to those listed in the preferences.
	odinSurface.SetGridDimensions(prefMan.boxWidth, prefMan.boxHeight);
	//Draw the screen for the first time. 
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
		//Is the game Drawing? 
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
					//If the write is successful, exit the program.
					//This will be changed later. 
					if(writer.writeInteger(prefMan.savePath)){
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
				//If the right mouse button is pressed, remove the selected entity from the screen
				else if(event.button.button == SDL_BUTTON_RIGHT){
					//Get the mouse's x and y
					int x, y;
					SDL_GetMouseState(&x, &y);
					//Set them to the top left corner of their host box
					x = validate.validatePosition(x, odinSurface.GetGridWidth());
					y = validate.validatePosition(y, odinSurface.GetGridHeight());
					//Erase said entity. 
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
 