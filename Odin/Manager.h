#include "SDL.h"
#include "Entity.h"
#include <vector>

using namespace std; 

class Manager{
public:
	Manager();
	void addEntity(Entity e); 
	Entity getEntity(int id); 
	vector<Entity> getEntities();
	vector<vector<int>> tiles;  
	int tileW, tileH; 
	void clearEntities();
	void clearEntity(int x, int y);
private:
	vector<Entity> entities; 

};