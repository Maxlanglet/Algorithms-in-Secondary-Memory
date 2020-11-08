#include "OutputStream3.hpp"


OutputStream3::OutputStream3(string filename){
	path = filename;
}

OutputStream3::~OutputStream3(){}


void OutputStream3::create(string name_file){
	ofstream new_file(name_file.c_str());
	new_file_pointer = &new_file;
}


void OutputStream3::writeln(string str, fstream &output_file){
	output_file << str << endl;
}

void OutputStream3::close(){
	new_file_pointer->close();
}
