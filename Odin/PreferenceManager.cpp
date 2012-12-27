#include "PreferenceManager.h" 
#include <exception>

PreferenceManager::PreferenceManager(){
	screenWidth = 1280;
	screenHeight = 720; 
	boxWidth = 20;
	boxHeight = 20;
	savePath = "default.txt";
	errorPath = "error.txt"; 
}

void PreferenceManager::loadPreferences(string filename){
	ifstream fin; 
	fin.open(filename.c_str()); 
	if(fin){
		fin.close();
		readPreferences(filename);
	}
	else{
		ofstream out; 
		out.open(errorPath.c_str());
		if(out){
			out<<"Error occurred in file opening"<<endl;
		}
		out.close();
	}
}

void PreferenceManager::readPreferences(string filename){
	string in = ""; 
	ifstream fin; 
	fin.open(filename);
	try{
		int count = 0;
		//Find a better way to do this. For the love of future configuration options, please. 
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