#include <iostream>
#include <fstream>
#include <string> 
#include "EditorSurface.h"

using namespace std; 
class Writer{
public:
	Writer(EditorSurface* e);
	bool write(string fileName);

private:
	EditorSurface* editor; 

};