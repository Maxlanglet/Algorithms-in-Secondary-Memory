#include "OutputStream3.hpp"
#define BUFFER_SIZE 5


OutputStream3::OutputStream3(){
}

OutputStream3::~OutputStream3(){}


void OutputStream3::create(string filepath){ 
	//ofstream outfile (path);
	//outfile.close();
	new_file = open(filepath.c_str(), O_CREAT | O_WRONLY | O_TRUNC,S_IWUSR |S_IRUSR);

}


void OutputStream3::writeln(string str){
	//str+="\n";
	/*
	if(str.substr(str.length()-1) == "\n"){
		str=str.substr(0,str.length()-1);
	}
	*/
	int offset = 0; //starts reading the string for the first time
	int over = 0; //1 if the line has been completely processed

	size_t nbytes = BUFFER_SIZE*sizeof(char); //creating the buffer in memory
	char* buffer = (char*) malloc(BUFFER_SIZE*sizeof(char)); 
	memset (buffer, 0, nbytes); //Initializing the buffer values
	if(buffer == NULL){printf("Memory allocation failed");}
	
	
	while(over==0){ //Still didn't find a \n in the buffered characters 
		//Substring going from the offset to offset+BUFFER_SIZE, if string shorter, take as many characters as possible
		string buff = str.substr (offset,BUFFER_SIZE); 
		
		//Puts the buffer string in the buffer, the last character is a terminating null character (so BUFFER_SIZE-1 characters are stored)
		int j = snprintf(buffer, BUFFER_SIZE, "%s\n", buff.c_str()); 
		
		char*ptr = NULL;
		ptr=buffer;
		int nb_bytes=0 ;
		//Iterating over the buffer to find the \n
		while (nb_bytes <BUFFER_SIZE && *ptr != '\n' && *ptr != '\r') ptr++, nb_bytes++;
		if ( *ptr == '\n'){
			nbytes=nb_bytes+1;
			ssize_t n = write(new_file, buffer, nbytes);
			over=1; //ends the while loop 
		}
		else{
			
			//write what has been found so far, without the terminating character
			ssize_t n = write(new_file, buffer, nbytes-1);
			//loop another time starting from the next BUFFER_SIZE characters 
			offset+=BUFFER_SIZE-1;
		}
	}
}

void OutputStream3::close(){
	::close(new_file);
}