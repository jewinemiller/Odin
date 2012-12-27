
#include "Entity.h"

Entity::Entity(){
	this->X = 0;
	this->Y = 0;
	this->name = "noname";
	this->numDesignation = 0; 
}

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