#include "OutputStream1.hpp"
//#include <unistd.h>


OutputStream1::OutputStream1(string filename){
	path = filename;

}

OutputStream1::~OutputStream1(){}


void OutputStream1::create(){
	new_file = open(path.c_str(), O_WRONLY | O_APPEND);
	if (new_file < 0) {
		printf("Error creating output file");
    }
	//new_file_pointer = &new_file;
}


void OutputStream1::writeln(string str){//pour respliquer le vis a vis avec le input 1

	string line = "";

	for (int i=0; i<str.length();i++){
		ssize_t n = write(new_file, &str[i], sizeof(line));
		if (n != sizeof(line)){
			printf("Error writing output file");
			break;
		}
		/*
		line += str[i];
		if (str[i] == '\n' || i==str.length()-1){
			ssize_t n = write(new_file, &line, sizeof(line));
			cout << line << endl;
			line = "";
			
		}
		*/
	}

}

void OutputStream1::close2(){
	close(new_file);
}

