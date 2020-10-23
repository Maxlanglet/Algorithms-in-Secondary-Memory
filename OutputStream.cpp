#include "OutputStream.hpp"
//#include <unistd.h>
#include <io.h>
#include <stdio.h>

OutputStream::OutputStream(string filename){
	path = filename;
}

OutputStream::~OutputStream(){}


void OutputStream::create(string name_file){
	ofstream new_file(name_file.c_str());
	new_file_pointer = &new_file;
}


void OutputStream::writeln1(string str, fstream &output_file){
	output_file << str << endl;
}

void OutputStream::writeln2(string str, fstream &output_file){
}

void OutputStream::writeln3(string str, fstream &output_file){
}

void OutputStream::writeln4(string str, fstream &output_file){
}

void OutputStream::close(){
	new_file_pointer->close();
}

