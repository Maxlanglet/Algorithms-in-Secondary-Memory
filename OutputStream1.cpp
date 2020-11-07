#include "OutputStream.hpp"
//#include <unistd.h>


OutputStream::OutputStream(){
	//;
}

OutputStream::~OutputStream(){}


void OutputStream::create(string name_file){
	new_file.open(name_file.c_str());
	//new_file_pointer = &new_file;
}


void OutputStream::writeln(string str){
	new_file << str << endl;//ecrire a la suite pas overwrite a faire
}

void OutputStream::close(){
	new_file.close();
}

