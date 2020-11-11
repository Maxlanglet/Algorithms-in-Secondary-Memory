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

	size_t len = 20*sizeof(char);
	char *p = NULL;

	ssize_t idx = 0;
	ssize_t size = 0;

	
	if (fd == -1)
	   handle_error("open");

	//if (fstat(fd, &sb) == -1) 
	  //handle_error("fstat");

	addr =  static_cast<char*>(mmap(NULL, len, PROT_READ,
	           MAP_PRIVATE, fd, offset));//

	if(addr == MAP_FAILED){
        printf("Mapping Failed\n");
        handle_error("mmap");
    }

    p = addr;
	while (idx < len && *p != '\n' && *p != '\r') p++, idx++;

	if ( *p == '\n'){
	    	offset += idx +1;
	    	size = idx+1;
	    }
    else offset += idx, size = idx;


    ssize_t n = write(1 ,addr, size);//obligé d etre 1 sinon pas de output
    cout << offset << endl;


    if(n != size){
        printf("Write failed\n");
    }

    printf("\n");

    int err = munmap(addr, sizeof(addr));

    if(err != 0){
        printf("UnMapping Failed\n");
    }

/*
////////////
    addr =  static_cast<char*>(mmap(NULL, len, PROT_READ,
	           MAP_PRIVATE, fd, offset));						//offset fait segfault


    n = write(1 ,addr, len);//obligé d etre 1 sinon pas de output

    if(n != size){
        printf("Write failed\n");
    }

    printf("\n");
    
    int err = munmap(addr, len);

    if(err != 0){
        printf("UnMapping Failed\n");
    }
    */
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


