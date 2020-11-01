#include "InputStream3.hpp"


#define BUFFER_SIZE 20

InputStream3::InputStream3(string filename){
	path = filename;
}

InputStream3::~InputStream3(){}

void InputStream3::open(){
	// open the file
	//file.open(path);
	filp = fopen(path.c_str(), "rb"); 
	if (!filp) { printf("Error: could not open file %s\n", path.c_str());}
	/*
	if(!file.is_open()){
		cout << "Impossible to open the file" << endl;
	}*/
}

//buffer by buffer
void InputStream3::readln(){

	if (filp){

		int bytes_read =1;

		while( bytes_read > 0){//temporary but read the entire file
			char buffer[BUFFER_SIZE];

			bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, filp);		//buffer overwritten not flushed


			
			for (int j=0; j<BUFFER_SIZE;j++){
				//printf("%s",&buf[j]);
				//cout << buf[j];
				cout << buffer[j];
				buffer[j] = '\0';
				//buffer[j] = 0;
			}


			//delete[] buffer;
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
	//file.close();
	fclose(filp);
}


