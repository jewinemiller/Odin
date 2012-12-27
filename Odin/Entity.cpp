
#include "Entity.h"

/*Entity Class
*The entity represents something drawn to the screen
*This can include tiles, tile types, platforms, terrain, etc.
*/

//Empty constructor
//Fills with default values
Entity::Entity(){
	this->X = 0;
	this->Y = 0;
	//Name that can be used for display/printing purposes. 
	this->name = "noname";
	//Numeric designation (Used for displaying/printing purposes)
	this->numDesignation = 0; 
}
//Parameterized Constructor. 
Entity::Entity(string name, int X, int Y, int designation){
	this->name = name;
	this->X = X;
	this->Y = Y; 
	this->numDesignation = designation;
	color = 0x5ca82a;
}

string Entity::getName(){
	return name;
}

int Entity::getX(){
	return X;
}

int Entity::getY(){
	return Y; 
}

void Entity::setLocation(int X, int Y){
	this->X = X;
	this->Y = Y;
}

void Entity::setName(string name){
	this->name = name;
}