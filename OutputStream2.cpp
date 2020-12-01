#include "OutputStream2.hpp"


// path is either the path of the created file or the one of the file where we have to write
OutputStream2::OutputStream2(){
}

OutputStream2::~OutputStream2(){}

// fopen creates the file if it doesnt exist, else it suppress the file
void OutputStream2::create(const char * filename){
	new_file = fopen(filename,"w+");
}

// writes string in file and end with a new line
void OutputStream2::writeln(string str){
	str+="\n";
	fputs(str.c_str(),new_file);
	//fputs("\n",new_file); // a voir pcq on sait jamais que le \n soit deja compris
}


void OutputStream2::close(FILE * pFile){
	fclose(pFile);
}

