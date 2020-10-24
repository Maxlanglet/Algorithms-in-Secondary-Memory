#include "InputStream2.hpp"
//#include <unistd.h>
#include <io.h>
#include <stdio.h>

InputStream2::InputStream2(string filename){
	path = filename;
}

InputStream2::~InputStream2(){}

void InputStream2::open(){
	// open the file
	ifstream file (path);
	if(!file.is_open()){
		cout << "Impossible to open the file" << endl;
	}
}



//caractère par caractère
//peut etre faut il utiliser fonction read() de unistd mais pas reussis a faire fonctionner
//peut etre file.read(c,1)
void InputStream2::readln(){
		/*
	FILE * pFile;
   char buffer [100];

   pFile = fopen ("myfile.txt" , "r");
   if (pFile == NULL) perror ("Error opening file");
   else
   {
     while ( ! feof (pFile) )
     {
       if ( fgets (buffer , 100 , pFile) == NULL ) break;
       fputs (buffer , stdout);
     }
     fclose (pFile);
	
	
	
	
	char line[100];
	//reads as long as the fgets does not encounter EOF (null value)
	while(fgets(line, 100, *(path))) {
    	printf("%s\n", line);
	}*/
}



void InputStream2::seek(int pos){
	file.seekg(pos);
}

bool InputStream2::end_of_stream(){
	if(file.eof()){
		return true;
	}
	else{
		return false;
	}
}

void InputStream2::close(){
	file.close();
}


