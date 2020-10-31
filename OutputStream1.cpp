#include "OutputStream1.hpp"
//#include <unistd.h>


OutputStream1::OutputStream1(){
	//;
}

OutputStream1::~OutputStream1(){}


void OutputStream1::create(){
	new_file.open(path.c_str());
	//new_file_pointer = &new_file;
}


void OutputStream1::writeln(string str){
	new_file << str << endl;//ecrire a la suite pas overwrite a faire
}

void OutputStream1::close(){
	new_file.close();
}

