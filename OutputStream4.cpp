#include "OutputStream4.hpp"


OutputStream4::OutputStream4(string filename){
	path = filename;
}

OutputStream4::~OutputStream4(){}


void OutputStream4::create(string name_file){
	ofstream new_file(name_file.c_str());
	new_file_pointer = &new_file;
}


void OutputStream4::writeln(string str, fstream &output_file){
	output_file << str << endl;
}


void OutputStream4::close(){
	new_file_pointer->close();
}

