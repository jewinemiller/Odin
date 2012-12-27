#include <iostream>
#include <fstream>
#include <string> 
#include "EditorSurface.h"

using namespace std; 
class Writer{
public:
	Writer(EditorSurface* e);
	bool writeInteger(string fileName);

private:
	EditorSurface* editor; 

};