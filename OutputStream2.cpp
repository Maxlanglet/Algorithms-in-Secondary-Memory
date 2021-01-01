#include "OutputStream2.hpp"


OutputStream2::OutputStream2(){
}

OutputStream2::~OutputStream2(){}

//  creates the file if it doesnt exist, else it empties it
void OutputStream2::create(const char * filename){
	new_file = fopen(filename,"w+");
}

// writes the string str in the opened file
void OutputStream2::writeln(string str){
	fputs(str.c_str(),new_file);
}

/*
Closes the file associated to the stream
*/
void OutputStream2::close(){
	fclose(new_file);
}

