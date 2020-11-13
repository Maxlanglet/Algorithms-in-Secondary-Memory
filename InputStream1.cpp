#include "InputStream1.hpp"
//#include <unistd.h>

using namespace std;

#define BUFFER_SIZE 20

InputStream1::InputStream1(string filename){
	path = filename;
	offset =0;
}

InputStream1::~InputStream1(){}

void InputStream1::open2(){
	// open the file
	filp = open(path.c_str(), O_RDONLY);
	
}



//caractère par caractère
//peut etre faut il utiliser fonction read() de unistd mais pas reussis a faire fonctionner
//peut etre file.read(c,1)
void InputStream1::readln(){

	if (filp){
		int bytes_read =1;
		char* c = (char*) malloc(sizeof(char));
		string line;

		while( bytes_read > 0){//temporary but read the entire file
						
			bytes_read = read(filp, c, sizeof(char));		//buffer overwritten not flushed
			line += c;
			offset ++;
			if (*c == '\n' || *c == '\r'){
				cout << line;
				line = "";
			}
		}
		free(c);
	}
	else{
		cout << "File is not open" << endl;
	}
	
}

void InputStream1::seek(int pos){
	lseek (filp, pos, SEEK_SET);
}

bool InputStream1::end_of_stream(){
	int bytes_read = 1;

	if((bytes_read = lseek (filp, offset, SEEK_SET)) == -1){
		return true;
	}
	else{
		return false;
	}
}

void InputStream1::close2(){
	close(filp);
}