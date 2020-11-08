#include "OutputStream2.hpp"



OutputStream2::OutputStream2(string filename){
	path = filename;
}

OutputStream2::~OutputStream2(){}


void OutputStream2::create(string name_file){
	ofstream new_file(name_file.c_str());
	new_file_pointer = &new_file;
}


void OutputStream2::writeln(string str, fstream &output_file){
	output_file << str << endl;
}


void OutputStream2::close(){
	new_file_pointer->close();
}

