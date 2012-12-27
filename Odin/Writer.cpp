#include "Writer.h"


Writer::Writer(EditorSurface* e){
	this->editor = e; 
}

bool Writer::write(string fileName){
	bool successful_write = false; 
	ofstream outdata; 

	outdata.open(fileName.c_str()); 
	if(outdata){
		for(int i = 0; i < editor->getManager().tiles.size(); i++){
			for(int j = 0; j < editor->getManager().tiles[i].size(); j++){
				outdata<<editor->getManager().tiles[i][j];
			}
			outdata<<endl; 
		}
		successful_write = true;
	}
	outdata.close(); 
	return successful_write; 
}