#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std; 

class DataStream{
public:
	DataStream(string file_stream);
	bool runStream(); 

	//Flags
	bool should_quit;
	bool should_write;

	//Data
	string output_path;

private:
	string file_stream; 
	vector<string> commands; 

	void parseCommands(); 
};