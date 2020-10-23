#include "InputStream.hpp"
//#include <unistd.h>
#include <io.h>
#include <stdio.h>

InputStream::InputStream(string filename){
	path = filename;
}

InputStream::~InputStream(){}

void InputStream::open(){
	// open the file
	ifstream file (path);
	if(!file.is_open()){
		cout << "Impossible to open the file" << endl;
	}
}



//caractère par caractère
//peut etre faut il utiliser fonction read() de unistd mais pas reussis a faire fonctionner
//peut etre file.read(c,1)
void InputStream::readln1(){
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

void InputStream::readln2(){
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

void InputStream::readln3(){}

void InputStream::readln4(){}

void InputStream::seek(int pos){
	file.seekg(pos);
}

bool InputStream::end_of_stream(){
	if(file.eof()){
		return true;
	}
	else{
		return false;
	}
}

void InputStream::close(){
	file.close();
}


