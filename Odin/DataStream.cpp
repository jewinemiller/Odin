#include "DataStream.h"
using namespace std;

DataStream::DataStream(string file_stream){
	this->file_stream = file_stream; 

	should_quit = false;
	should_write = false; 

	output_path = "Exports/default.txt";
}

bool DataStream::runStream(){
	ifstream fin; 
	fin.open(file_stream.c_str());
	if(!fin.fail()){
		commands.clear(); 
		while(!fin.eof()){
			string temp  = ""; 
			getline(fin, temp);
			commands.push_back(temp); 
		}
		fin.close();
		remove(file_stream.c_str());
		parseCommands(); 
	}
	else{
		return false;
	}


	return true; 
}

void DataStream::parseCommands(){
	for(int i = 0; i < commands.size(); i++){
		if(strcmp(commands[i].c_str(), "quit") == 0){
			//should_quit = true;
		}
		else if(strcmp(commands[i].c_str(), "output") == 0){
			i++; 
			should_write = true;
			output_path = commands[i];
		}
	}
}