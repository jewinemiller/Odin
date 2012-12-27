#include "Writer.h"

/*
*Writer Class
*This class is used in order to write out the map to a file.
*/
Writer::Writer(EditorSurface* e){
	this->editor = e; 
}

//Write Method
//For now, this is the only supported method of writing.
//This will write a map as integers representing what tiles will be placed in the later copies of the map.
bool Writer::writeInteger(string fileName){
	//Has the write been successful?
	bool successful_write = false; 
	//Crete the output stream
	ofstream outdata; 
	//Attempt to open the output file
	outdata.open(fileName.c_str()); 
	//If the output opens, start to print.
	if(outdata){
		//Loop through all of the tiles on the map.
		for(int i = 0; i < editor->getManager().tiles.size(); i++){
			for(int j = 0; j < editor->getManager().tiles[i].size(); j++){
				//Print the integer representation of each tile.
				outdata<<editor->getManager().tiles[i][j];
			}
			//Newline
			outdata<<endl; 
		}
		//The write has been successful
		successful_write = true;
	}
	//Close the stream
	outdata.close(); 
	//Return whether or not the write worked. 
	return successful_write; 
}