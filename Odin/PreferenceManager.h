#include<iostream>
#include<string>
#include <fstream>

using namespace std; 

class PreferenceManager{
public:
	PreferenceManager();
	void loadPreferences(string filename); 
	int screenWidth, screenHeight;
	int boxWidth, boxHeight; 
	string savePath; 

private:
	void readPreferences(string filename); 
	string errorPath; 
};