#include "SDL.h"
#include <string>
using namespace std; 

class Entity{
public: 
	Entity();
	Entity(string name, int X, int Y, int designation);
	void setLocation(int X, int Y);
	void setName(string name);
	int getX();
	int getY();
	string getName();
	int numDesignation; 
	Uint32 color; 
private:
	string name; 
	int X, Y; 
};