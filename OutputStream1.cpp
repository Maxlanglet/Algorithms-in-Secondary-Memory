#include "OuputStream1.hpp"
//#include <unistd.h>
#include <io.h>
#include <stdio.h>

OuputStream1::OuputStream1(string filename){
	path = filename;
}

OuputStream1::~OuputStream1(){}


void OuputStream1::create(string name_file){
	ofstream new_file(name_file.c_str());
	new_file_pointer = &new_file;
}


void OuputStream1::writeln(string str, fstream &output_file){
	output_file << str << endl;
}

void OuputStream1::close(){
	new_file_pointer->close();
}

