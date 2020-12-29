#include "OutputStream3.hpp"
//#define BUFFERSIZE 5


OutputStream3::OutputStream3(){
}

OutputStream3::~OutputStream3(){}


void OutputStream3::create(string filepath){ 
	new_file = open(filepath.c_str(), O_CREAT | O_WRONLY | O_TRUNC,S_IWUSR |S_IRUSR);

}


void OutputStream3::writeln(string str, int B){
	int offset = 0; //starts reading the string for the first time
	int over = 0; //1 if the line has been completely processed

	size_t nbytes = B*sizeof(char); //creating the buffer in memory
	char* buffer = (char*) malloc(B*sizeof(char)); 
	memset (buffer, 0, nbytes); //Initializing the buffer values
	if(buffer == NULL){printf("Memory allocation failed");}
	
	
	while(over==0){ //Still didn't find a \n in the buffered characters 
		//Substring going from the offset to offset+B, if string shorter, take as many characters as possible
		string buff = str.substr (offset,B); 
		
		//Puts the buffer string in the buffer, the last character is a terminating null character (so B-1 characters are stored)
		int j = snprintf(buffer, B, "%s\n", buff.c_str()); 
		
		char*ptr = NULL;
		ptr=buffer;
		int nb_bytes=0 ;
		//Iterating over the buffer to find the \n
		while (nb_bytes <B && *ptr != '\n' && *ptr != '\r') ptr++, nb_bytes++;
		if ( *ptr == '\n'){
			nbytes=nb_bytes+1;
			ssize_t n = write(new_file, buffer, nbytes);
			over=1; //ends the while loop 
		}
		else{
			
			//write what has been found so far, without the terminating character
			ssize_t n = write(new_file, buffer, nbytes-1);
			//loop another time starting from the next B characters 
			offset+=B-1;
		}
	}
	free(buffer);
}

void OutputStream3::close(){
	::close(new_file);
}