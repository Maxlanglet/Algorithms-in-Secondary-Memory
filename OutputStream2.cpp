#include "OuputStream2.hpp"
//#include <unistd.h>
#include <io.h>
#include <stdio.h>

OuputStream2::OuputStream2(string filename){
	path = filename;
}

OuputStream2::~OuputStream2(){}


void OuputStream2::create(string name_file){
	ofstream new_file(name_file.c_str());
	new_file_pointer = &new_file;
}


void OuputStream2::writeln(string str, fstream &output_file){
	output_file << str << endl;
}


void OuputStream2::close(){
	new_file_pointer->close();
}

