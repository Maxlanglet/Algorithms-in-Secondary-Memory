#include "OutputStream3.hpp"


OuputStream3::OuputStream3(string filename){
	path = filename;
}

OuputStream3::~OuputStream3(){}


void OuputStream3::create(string name_file){
	ofstream new_file(name_file.c_str());
	new_file_pointer = &new_file;
}


void OuputStream3::writeln(string str, fstream &output_file){
	output_file << str << endl;
}

void OuputStream3::close(){
	new_file_pointer->close();
}

