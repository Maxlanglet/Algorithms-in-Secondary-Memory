#include "InputStream4.hpp"

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


InputStream4::InputStream4(string filename){
	path = filename;
	offset = 0;
}

InputStream4::~InputStream4(){}

void InputStream4::open2(){
	// open the file
	fd = open(path.c_str(), O_RDONLY);
	if (fd == -1)
	   handle_error("open");
}


void InputStream4::readln(){
	char *addr= NULL;
	
	//struct stat sb;
	char *p = NULL;
	char *m = NULL;

	struct stat sb;

	int pagesize = getpagesize();

	
	if (fd == -1)
	   handle_error("open");

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");

	//cout << sb.st_size << endl;

	while (sb.st_size > 0) {
		size_t len = 4096;//20*sizeof(char), same as pagesize
		ssize_t size = 0;

		if (sb.st_size < len){
			len = sb.st_size;
			sb.st_size = 0;
		}
		else {
			sb.st_size -= len;
			//cout << "\n" <<  sb.st_size << "\n" << endl;
		}

		addr =  static_cast<char*>(mmap(NULL, len, PROT_READ,MAP_PRIVATE, fd, offset*pagesize));//
		offset ++;

		if(addr == MAP_FAILED){
	        printf("Mapping Failed\n");
	        handle_error("mmap");
	    }
	    p = addr;
	    m = addr;
	    for ( int i = 0; i<len; i++ ){
	    	if (*p=='\n'){
	    		ssize_t n = write(1 ,m, size);
	    		if(n != size){
			        printf("Write failed\n");
			    }
	    		m+=size;
	    		size=0;
	    	}
	    	//cout << i << " " << *p << endl;
	    	p++;
	    	size++;
	    }
	    int err = munmap(addr, len);

	    if(err != 0){
	        printf("UnMapping Failed\n");
	    }


	}
    //cout << offset << endl;
}


void InputStream4::seek(int pos){
	lseek (fd, pos, SEEK_SET);
}

bool InputStream4::end_of_stream(){
	int bytes_read = 1;

	if((bytes_read = lseek (fd, offset, SEEK_SET)) == -1){
		return true;
	}
	else{
		return false;
	}
}

void InputStream4::close2(){
	close(fd);
}


