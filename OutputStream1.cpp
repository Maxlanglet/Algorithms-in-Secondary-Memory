#include "OutputStream1.hpp"

OutputStream1::OutputStream1(){
}

OutputStream1::~OutputStream1(){}

/*
Creates the file which name is the parameter path
If the file already exists its content is emptied
*/
void OutputStream1::create(string path){
	new_file = open(path.c_str(), O_CREAT | O_WRONLY | O_TRUNC,S_IWUSR |S_IRUSR);
	if (new_file < 0) {
		cout<<errno<<endl;
		printf("Error creating output file\n");
		exit(1);
    }
	
}

/*Implementation of the writeln method that writes a line character by character using the write system call
*/
void OutputStream1::writeln(string str){	
	for (int i=0; i<str.length();i++){
		ssize_t n = write(new_file, &str[i], sizeof(char)); //write one byte at a time
		if (n != sizeof(char)){
			printf("Error writing output file\n");
			break;
		}
	}
}

/*
Closes the file associated to the stream
*/
void OutputStream1::close(){
	::close(new_file);
}
