#include "InputStream3.hpp"


#define BUFFER_SIZE 5

InputStream3::InputStream3(){
	offset = 0;
}

InputStream3::~InputStream3(){}

void InputStream3::open(string path){
	fd = ::open(path.c_str(), O_RDONLY);
	if (!fd) { printf("Error: could not open file %s\n", path.c_str());}
}

//buffer by buffer
int InputStream3::readln(){
//NEED TO SEE HOW TO COUNT OF BUFFER TOO SMALL 
	if (fd){

		ssize_t bytes_read =1;
		char* buffer = (char*) malloc(BUFFER_SIZE*sizeof(char));
		size_t nbytes = BUFFER_SIZE*sizeof(char);
		int sizeline = 0;

		while( bytes_read > 0){//temporary but read the entire file
			ssize_t idx = 0;
			ssize_t size = 0;
			char *p = NULL;


			if ((bytes_read = lseek (fd, offset, SEEK_SET)) != -1)
	        bytes_read = read (fd, buffer, nbytes);

			if (bytes_read == -1) {   /* read error   */
				cout << "Error" << endl;
		    }

		    p = buffer;
		    while (idx < bytes_read && *p != '\n' && *p != '\r') p++, idx++;


		    if ( *p == '\n'){
		    	offset += idx +1;
		    	size = idx+1;
				sizeline+=idx+1;
				break;
		    }
		    else{ 
				offset += idx, size = idx;
				sizeline+=idx;}
			
			
			
		}
		free(buffer);
		return sizeline;
	}
	else{
		cout << "File is not open" << endl;
		exit(1);
	}

}

int InputStream3::length(string filename){
	open(filename);
	int sum = 0 ;
	int line_size = 1 ;
	 while (line_size > 0 ){
		line_size = readln();
		sum += line_size ;
	 }
	 return sum ;
}

void InputStream3::seek(int pos){
	lseek (fd, pos, SEEK_SET);
}

bool InputStream3::end_of_stream(){
	int bytes_read = 1;

	if((bytes_read = lseek (fd, offset, SEEK_SET)) == -1){
		return true;
	}
	else{
		return false;
	}
}

void InputStream3::close(){
	//file.close();
	::close(fd);
}


