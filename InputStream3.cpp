#include "InputStream3.hpp"


#define BUFFER_SIZE 20

InputStream3::InputStream3(string filename){
	path = filename;
	offset = 0;
}

InputStream3::~InputStream3(){}

void InputStream3::open2(){
	fd = open(path.c_str(), O_RDONLY);
	if (!fd) { printf("Error: could not open file %s\n", path.c_str());}
}

//buffer by buffer
void InputStream3::readln(){

	if (fd){

		ssize_t bytes_read =1;
		char* buffer = (char*) malloc(BUFFER_SIZE*sizeof(char));
		size_t nbytes = BUFFER_SIZE*sizeof(char);

		while( bytes_read > 0){//temporary but read the entire file
			ssize_t idx = 0;
			ssize_t size = 0;
			char *p = NULL;


			if ((bytes_read = lseek (fd, offset, SEEK_SET)) != -1)
	        bytes_read = read (fd, buffer, nbytes);

	    	//ssize_t n = write(1, buffer, bytes_read);
			

			if (bytes_read == -1) {   /* read error   */
				cout << "Error" << endl;
		    }

		    p = buffer;    /* check each chacr */
		    while (idx < bytes_read && *p != '\n' && *p != '\r') p++, idx++;


		    if ( *p == '\n'){
		    	offset += idx +1;
		    	size = idx+1;
		    }
		    else offset += idx, size = idx;

			ssize_t n = write(1, buffer, size);//obligé d etre 1 sinon pas de output, je sais pas pq ca fonctionne pas avec file descriptor
			
		    if(n != size){
		        printf("Write failed\n");
		    }
		}
		free(buffer);
	}
	else{
		cout << "File is not open" << endl;
	}

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

void InputStream3::close2(){
	//file.close();
	close(fd);
}


