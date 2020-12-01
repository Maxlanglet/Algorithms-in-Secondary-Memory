#include "InputStream2.hpp"

InputStream2::InputStream2(){
}

InputStream2::~InputStream2(){}


void InputStream2::open(const char* path){
	// open the file
	file = fopen (path , "r");
	if (file == NULL) perror ("Error opening file");
}



//reads in a buffer
int InputStream2::readln(){ //returns length of file read
	// initialize a buffer of fixed size 100
	char buffer [100];
	// if we are not at the end of the file, we read the size of the buffer
	 if ( ! feof (file) ){
       
	   //while(buffer[99] != '\n' && buffer[99]!='\0')
		if ( fgets (buffer , 100 , file) == NULL ){
			//cout<<"error, NULL"<<endl;
			return 0;
		}
     }
     return strlen(buffer);
}



void InputStream2::seek(int pos){
	fseek(file,pos,SEEK_SET);
}

int InputStream2::length(string filename){
	open(filename.c_str());
	int sum = 0 ;
	int line_size = 1 ;
	 while (line_size > 0 ){
		line_size = readln();
		sum += line_size ;
	 }
	 return sum ;
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

int InputStream2::randjump(string file, int j){
	
}


