#include "OutputStream2.hpp"



OutputStream2::OutputStream2(const char * filename){
	path = filename;
}

OutputStream2::~OutputStream2(){}


void OutputStream2::create(){
	new_file = fopen(path.c_str(),"a");
}


void OutputStream2::writeln(string str){
	new_file = fopen(path.c_str(),"a");
	fputs(str.c_str(),new_file);
	fputs("\n",new_file); // a voir pcq on sait jamais que le \n soit deja compris
}


void OutputStream2::close(FILE * pFile){
	fclose(pFile);
}

