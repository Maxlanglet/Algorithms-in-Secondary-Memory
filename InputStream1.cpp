#include "InputStream1.hpp"
//#include <unistd.h>
#ifdef _WIN32
#include <io.h>

#elif defined(__APPLE__)
#include <unistd.h>
//#define bswap_64(x) OSSwapInt64(x)
#endif

#include <stdio.h>

using namespace std;

InputStream1::InputStream1(string filename){
	path = filename;
}

InputStream1::~InputStream1(){}

void InputStream1::open(){
	// open the file
	file.open(path);
	if(!file.is_open()){
		cout << "Impossible to open the file" << endl;
	}
	
}



//caractère par caractère
//peut etre faut il utiliser fonction read() de unistd mais pas reussis a faire fonctionner
//peut etre file.read(c,1)
void InputStream1::readln(){
	
	if (file){
		string line;
		char c;
		while (file.get(c))//c == '\n' || c == '\r' pour lire la ligne en particulier
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

void InputStream1::seek(int pos){
	file.seekg(pos);
}

bool InputStream1::end_of_stream(){
	if(file.eof()){
		return true;
	}
	else{
		return false;
	}
}

void InputStream1::close(){
	file.close();
}