#include "InputStream4.hpp"
#define BUFFER_SIZE 2

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


InputStream4::InputStream4(){
	offset = 0;
	addr = NULL;
	init=0;
	pos = 0;
}

InputStream4::~InputStream4(){}


void InputStream4::open(string filename){
	// open the file
	fd = ::open(filename.c_str(), O_RDONLY);
	if (fd == -1)
	   handle_error("open");
}


int InputStream4::readln(int mult_page){
	
	char *p = NULL;
	struct stat sb;

	int pagesize = getpagesize()*mult_page;

	
	if (fd == -1)
	   handle_error("open");

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");

	pos = lseek(fd, 0, SEEK_CUR);
	int off = pos%pagesize;
	int page = floor(pos / pagesize);

	size_t len=pagesize;
	int idx=0;
	

	rest = sb.st_size-pos;

	if (rest == 0) return 0;


	if (offset != page || init !=1){
		offset = page;
		if (offset*pagesize >= sb.st_size){
			pagesize = getpagesize();
			len=getpagesize();
		}
		addr =  static_cast<char*>(mmap(NULL, len, PROT_READ,MAP_PRIVATE, fd, offset*pagesize));//
		init=1;
	}

	if(addr == MAP_FAILED){
        printf("Mapping Failed\n");
        handle_error("mmap");
    }
    p = addr;
    p+=off;
    len-=off;

    while (idx < len-1 && *p != '\n' && *p != '\r') p++, idx++;


    if (*p == '\n' || *p == '\r'){
    	pos = lseek(fd,idx+1,SEEK_CUR);
    	return idx+1;
    }

    else{
    	pos = lseek(fd,idx+1,SEEK_CUR);					//true if randjump and then add the rest to account for when the line ends on the next page
    	if(jump){
    		page++;
    		offset++;
    		len = pagesize;
    		if (offset*pagesize >= sb.st_size){
    			pagesize = getpagesize();
    			len=getpagesize();
    		}
    		addr =  static_cast<char*>(mmap(NULL, len, PROT_READ,MAP_PRIVATE, fd, offset*pagesize));//
    		p = addr;
    		while (idx < len-1 && *p != '\n' && *p != '\r') p++, idx++;

    		if (*p == '\n' || *p == '\r'){
		    	pos = lseek(fd,idx+1,SEEK_CUR);
		    	return idx+1;//maybe add one problem maybe because of lseek but freezes if idx, at least resolves the problem
		    }
    	}
    	
    	if (idx!=0){
    		return idx+1;
    	}
    }
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

void InputStream4::close(){
	::close(fd);
}

int InputStream4::length(string file){
	open(file);//TODO: enlever car on le fait avant 
	struct stat sb;
	seek(0);
	int line_size =1;
	int sum=0;

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");

	while (line_size > 0 ){
		line_size = readln(BUFFER_SIZE);//mettre size of buffer in def of length
		sum+=line_size;
	}
	int err = munmap(addr, getpagesize());
	init=0;//to make sure we remap for real benchmarking
    if(err != 0){
        printf("UnMapping Failed\n");
    }
	return sum;
}

int InputStream4::randjump(string file, int j){
	int sum=0;
	int k=0;
	open(file);
	struct stat sb;
	seek(0);
	jump = true;

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");
	
	srand ( 2 );
	int pos = rand();
	
	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sb.st_size - 0 + 1));
		seek(pos);
		sum+=readln(BUFFER_SIZE);
		k++;
	}
	int err = munmap(addr, getpagesize());
	init=0;
    if(err != 0){
        printf("UnMapping Failed\n");
    }
	return sum;
}




