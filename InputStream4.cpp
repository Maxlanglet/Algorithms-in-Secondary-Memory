#include "InputStream4.hpp"

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


InputStream4::InputStream4(string filename){
	path = filename;
}

InputStream4::~InputStream4(){}

void InputStream4::open2(){
	// open the file
	fd = open(path.c_str(), O_RDONLY);
	if (fd == -1)
	   handle_error("open");
}


void InputStream4::readln(){
	char *addr;
	
	struct stat sb;

	

	if (fd == -1)
	   handle_error("open");

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");

	addr =  static_cast<char*>(mmap(NULL, sb.st_size, PROT_READ,
	           MAP_PRIVATE, fd, 0));

	if(addr == MAP_FAILED){
        printf("Mapping Failed\n");
        handle_error("mmap");
    }

    ssize_t n = write(1 ,addr,sb.st_size);//obligé d etre 1 sinon pas de output

    if(n != sb.st_size){
        printf("Write failed\n");
    }

    printf("\n");
    
    int err = munmap(addr, sb.st_size);

    if(err != 0){
        printf("UnMapping Failed\n");
    }
}


void InputStream4::seek(int pos){
	//fd.seekg(pos);
}

bool InputStream4::end_of_stream(){
	/*
	if(fd.eof()){
		return true;
	}
	else{
		return false;
	}
	*/
}

void InputStream4::close2(){
	close(fd);
}


