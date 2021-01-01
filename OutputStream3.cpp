#include "OutputStream3.hpp"

OutputStream3::OutputStream3(){
}

OutputStream3::~OutputStream3(){}

//  creates the file in writting mode if it doesnt exist, else it empties it
void OutputStream3::create(string filepath){ 
	new_file = open(filepath.c_str(), O_CREAT | O_WRONLY | O_TRUNC,S_IWUSR |S_IRUSR);

}


/*Implementation of the writeln method 
B is the size of the buffer to use to write to the file
*/
void OutputStream3::writeln(string str, int B){
	//If the line is empty the function returns immediatly
	if(str.size()==0){
		return;
	}

	int offset = 0; //Starts reading the string for the first time
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
			over=1; //Ends the while loop 
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

/*
Closes the file associated to the stream
*/
void OutputStream3::close(){
	::close(new_file);
}