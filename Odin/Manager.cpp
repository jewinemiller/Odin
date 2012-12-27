#include "Manager.h"

/*
*Manager Class
*This class creates a manager which will keep track of all entities and other pieces of information
*that are deemed important to the running of the level editor. 
*/
Manager::Manager(){
	tileW = 20;
	tileH = 20;

}

//Return the entity at the chosen index. 
//If the entity doesn't exist, do not return anything.
Entity Manager::getEntity(int index){
	if(index < this->entities.size() && index >= 0){
		return this->entities[index]; 
	}
}

//Add an entitiy to the list of entities that the Manager keeps track of. 
void Manager::addEntity(Entity e){
	this->entities.push_back(e);
	if(tileW > 0 && tileH > 0){
		this->tiles[e.getY()/tileH][e.getX()/tileW] = e.numDesignation;
	}
}

//Return the entire list of entities. 
vector<Entity> Manager::getEntities(){
	return this->entities; 
}

//Remove the entire list of entities.
void Manager::clearEntities(){
	this->entities.clear();
}

//Clear a single entity from the manager's list of entities. 
void Manager::clearEntity(int x, int y){
	//Iterator to move through the entities. 
	vector<Entity>::iterator it = entities.begin();
	//While there are still entities
	while (it != entities.end()) {
		//Remove the entity that has the x and y passed in
		if (it->getX() == x && it->getY() == y) {
		 it = entities.erase(it);
		}
		//Otherwise, iterate through the list. 
		 else {
			 ++it;
		}
	}
}