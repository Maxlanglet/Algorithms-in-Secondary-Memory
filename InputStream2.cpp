#include "InputStream2.hpp"

InputStream2::InputStream2(char filename){
	path = &filename;
}

InputStream2::~InputStream2(){}

void InputStream2::open(){
	// open the file
	file = fopen (path , "r");
	if (file == NULL) perror ("Error opening file");
}



//reads in a buffer
void InputStream2::readln(){
	char buffer [100];
     while ( ! feof (file) ){
       if ( fgets (buffer , 100 , file) == NULL ) break;
       fputs (buffer , stdout);
     }
}



void InputStream2::seek(int pos){
	fseek(file,pos,SEEK_SET);
}

bool InputStream2::end_of_stream(){
	if(feof(file)){
		return true;
	}
	else{
		return false;
	}
}

void InputStream2::close(){
	fclose (file);
}


