#include "InputStream4.hpp"
//#include <unistd.h>
#include <io.h>
#include <stdio.h>

InputStream4::InputStream4(string filename){
	path = filename;
}

InputStream4::~InputStream4(){}

void InputStream4::open(){
	// open the file
	ifstream file (path);
	if(!file.is_open()){
		cout << "Impossible to open the file" << endl;
	}
}



//caractère par caractère
//peut etre faut il utiliser fonction read() de unistd mais pas reussis a faire fonctionner
//peut etre file.read(c,1)
void InputStream4::readln(){
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


void InputStream4::seek(int pos){
	file.seekg(pos);
}

bool InputStream4::end_of_stream(){
	if(file.eof()){
		return true;
	}
	else{
		return false;
	}
}

void InputStream4::close(){
	file.close();
}


