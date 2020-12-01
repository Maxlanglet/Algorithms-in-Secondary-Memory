#include "InputStream3.hpp"


#define BUFFER_SIZE 5


#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

InputStream3::InputStream3(){
	offset = 0;
}

InputStream3::~InputStream3(){}

void InputStream3::open(string path){
	fd = ::open(path.c_str(), O_RDONLY);
	if (!fd) { printf("Error: could not open file %s\n", path.c_str());}
}

//buffer by buffer
int InputStream3::readln(int buf_size){
	int buffer_size=buf_size;
	if (fd){

		ssize_t bytes_read =1;
		char* buffer = (char*) malloc(buffer_size*sizeof(char));
		size_t nbytes = buffer_size*sizeof(char);
		int sizeline = 0;

		offset = lseek(fd, 0, SEEK_CUR);

		while( bytes_read > 0){
			ssize_t idx = 0;
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
				sizeline+=idx+1;
				break;
		    }
		    else{ 
				offset += idx;
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
		line_size = readln(5);
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

int InputStream3::randjump(string file, int j){
	int sum=0;
	int k=0;


	open(file);
	struct stat sb;

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");
	
	srand ( time(NULL) );//for true random else seeded
	int pos = rand();
	
	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sb.st_size - 0 + 1));
		seek(pos);
		int line_size = readln(5);
		sum+=line_size;
		k++;
	}
	return sum;
}


