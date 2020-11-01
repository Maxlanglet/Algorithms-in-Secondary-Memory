#include "OutputStream.hpp"
//#include <unistd.h>


OutputStream::OutputStream(){
	//;
}

OutputStream::~OutputStream(){}


void OutputStream::create(string name_file){
	new_file.open(name_file.c_str(), ios::app);//app pour append et pas recreer un autre fichier
	//new_file_pointer = &new_file;
}


void OutputStream::writeln(string str){
	new_file << str << endl;
}

void OutputStream::close(){
	new_file.close();
}

