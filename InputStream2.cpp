#include "InputStream2.hpp"

InputStream2::InputStream2(const char * filename){
	path = filename;
}

InputStream2::~InputStream2(){}


void InputStream2::open(){
	// open the file
	file = fopen (path , "r");
	if (file == NULL) perror ("Error opening file");
}



//reads in a buffer
void InputStream2::readln(){
	// initialize a buffer of fixed size 100
	char buffer [100];
	// if we are not at the end of the file, we read the size of the buffer
	 if ( ! feof (file) ){
       
	   //while(buffer[99] != '\n' && buffer[99]!='\0')
		if ( fgets (buffer , 100 , file) == NULL ) cout<<"error, NULL"<<endl;
		// verify that we indeed read the right characters
       	fputs (buffer , stdout);
		
     }
	 /*
	 // this is the code to read the entire file
     while ( ! feof (file) ){
       if ( fgets (buffer , 100 , file) == NULL ) break;
       fputs (buffer , stdout);
     }*/
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


