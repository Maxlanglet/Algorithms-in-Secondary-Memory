#include "InputStream3.hpp"
//#include <unistd.h>
#include <io.h>
#include <stdio.h>

InputStream3::InputStream3(string filename){
	path = filename;
}

InputStream3::~InputStream3(){}

void InputStream3::open(){
	// open the file
	ifstream file (path);
	if(!file.is_open()){
		cout << "Impossible to open the file" << endl;
	}
}

//caractère par caractère
//peut etre faut il utiliser fonction read() de unistd mais pas reussis a faire fonctionner
//peut etre file.read(c,1)
void InputStream3::readln(){
	if (file){
		string line;
		char c;
		while (file.get(c))
		{
			line += c;
			if (c == '\n' || c == '\r'){
				cout << line;
				line="";
			}
		}
	}
	else{
		cout << "File is not open" << endl;
	}
}

void InputStream3::seek(int pos){
	file.seekg(pos);
}

bool InputStream3::end_of_stream(){
	if(file.eof()){
		return true;
	}
	else{
		return false;
	}
}

void InputStream3::close(){
	file.close();
}


