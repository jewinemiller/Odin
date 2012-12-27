#include "PreferenceManager.h" 
#include <exception>
/*Preference Manager Class
*This class manages preferences for the editor.
*These preferences are used in order to customize how the editor looks on startup.
*/
PreferenceManager::PreferenceManager(){
	//Default Values for the various preferences.
	//These are here in case the preferences do not load correctly.
	screenWidth = 1280;
	screenHeight = 720; 
	boxWidth = 20;
	boxHeight = 20;
	savePath = "default.txt";
	errorPath = "error.txt"; 
}

//Load Preferences Function
//Accepts a string (filename) and checks to see if it is a valid path.
//If the path is valid, continue to load the preferences. 
void PreferenceManager::loadPreferences(string filename){
	//Input stream
	ifstream fin; 
	//Attempt to open the preferences file
	fin.open(filename.c_str()); 
	//If the prefereneces file can open, run the reading function
	if(fin){
		//Close the existing file stream
		fin.close();
		//Run the open function (Opens a new file stream)
		readPreferences(filename);
	}
	//Otherwise, print a message to the error log stating that the preferences file does not exist. 
	else{
		//Output stream
		ofstream out; 
		//Open the stream and write the error
		out.open(errorPath.c_str());
		if(out){
			out<<"Error occurred in file opening"<<endl;
		}
		out.close();
	}
}

//Function used to read the prefrenences from the file. 
//The parsing code is pretty nasty and needs to be made better.
void PreferenceManager::readPreferences(string filename){
	//String to be read in
	string in = ""; 
	//File stream
	ifstream fin;
	//Open the file (If we are here, we know that it works already) 
	fin.open(filename);
	try{
		//How many lines have been read
		int count = 0;
		//Find a better way to do this. For the love of future configuration options, please. 
		//Read through the options, set the appropriate data values. 
		while(!fin.eof()){
			getline(fin, in); 
			switch (count){
			case 0:
				screenWidth = atoi(in.c_str()); 
				break;
			case 1:
				screenHeight = atoi(in.c_str()); 
				break;
			case 2:
				boxWidth = atoi(in.c_str());
				break;
			case 3: 
				boxHeight = atoi(in.c_str()); 
				break;
			case 4:
				savePath = in;
				break;
			}
			count++; 
		}
		fin.close();
	}
	//Print an error if any occur. 
	catch(exception& e){
		fin.close();
		ofstream out; 
		out.open(errorPath.c_str());
		if(out){
			out<<e.what()<<endl;
		}
		out.close();
	}
}