#include "InputStream3.hpp"

#define BUFFER_SIZE 5

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

InputStream3::InputStream3(){
	offset = 0;
}

InputStream3::~InputStream3(){}

void InputStream3::open(string path){
	// Opens the file in reading mode
	fd = ::open(path.c_str(), O_RDONLY);
	if (!fd) { printf("Error: could not open file %s\n", path.c_str());}
}

/*Implementation of the readln method that reads a line bu filling a buffer of size buf_size
until the whole line has been read
Returns the string of the read line or an empty string if the end of file has been reached
*/
string InputStream3::readln(int buf_size){
	int buffer_size=buf_size;

	if (fd){
		ssize_t bytes_read =1;
		//Allocates memory for the buffer
		char* buffer = (char*) malloc(buffer_size*sizeof(char));
		if (!buffer) {
			printf("ERROR");
			exit(1);
		}

		size_t nbytes = buffer_size*sizeof(char);//number of bytes to read each time
		int sizeline = 0;
		string str="";

		offset = lseek(fd, 0, SEEK_CUR);

		struct stat sb;

		if (fstat(fd, &sb) == -1) 
	  		handle_error("fstat");

	  	int rest = sb.st_size - offset;

		char *p = NULL;
		bool edl=false;//end of line 
		
		while(!edl && bytes_read > 0){
			ssize_t idx = 0;

			
			if ((bytes_read = lseek (fd, offset, SEEK_SET)) != -1)
				bytes_read =  read(fd, buffer, nbytes); //continue reading from the offset

			
			if (bytes_read == -1) {   /* read error   */
				cout << "Error" << endl;
		    }

		    p = buffer;
			//Look inside the buffer for the end of the line 
		    while (idx < bytes_read && *p != '\n' && *p != '\r') str+=*p,p++, idx++;


		    if ( *p == '\n'){
		    	offset += idx +1; //adjust the offset for the next call
		    	lseek(fd, offset, SEEK_SET);
				sizeline+=idx+1;
				str+="\n";
				edl=true; //exit the while loop
				rest-=offset;
		    }
		    else{ //the end of line still hasn't been reached
				offset += idx;
				sizeline+=idx;
				lseek(fd, offset, SEEK_SET);
				rest-=offset;
			}
		}
		free(buffer);
		return str;
	}
	else{
		cout << "File is not open" << endl;
		exit(1);
	}

}

/*Sequential reading 
Reads the entire file sequentially by calling readln until the line size is equal to 0
Returns the length of everything read
*/
int InputStream3::length(int buf_size){
	int sum = 0 ;
	int line_size = 1 ;
	struct stat sb;
	seek(0);

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");

	 while (sum < sb.st_size ){
		line_size = readln(buf_size).size();
		sum += line_size ;
	 }
	 return sum ;
}

/*Change the position pointer place in the file*/
void InputStream3::seek(int pos){
	lseek (fd, pos, SEEK_SET);
}

/*Returns true if the end of the file is reached*/
bool InputStream3::end_of_stream(){
	int bytes_read = 1;

	if((bytes_read = lseek (fd, offset, SEEK_SET)) == -1){
		return true;
	}
	else{
		return false;
	}
}

/*Closes the file associated to the stream*/
void InputStream3::close(){
	::close(fd);
}

/*Reads through the file randomly
j is the number of randomized jumps and buffer the size of buffer to use
*/
int InputStream3::randjump(int j, int buffer){
	int sum=0;
	int k=0;

	struct stat sb;
	seek(0);

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");
	int line_size = 1 ;

	srand ( 2 );
	int pos = rand();
	
	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sb.st_size - 0 + 1));
		seek(pos);
		line_size = readln(buffer).size();
		sum+=line_size;
		k++;
	}
	return sum;
}


