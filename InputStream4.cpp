#include "InputStream4.hpp"

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


InputStream4::InputStream4(){
	offset = 0;
	addr = NULL;
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
	char *m = NULL;

	struct stat sb;

	int pagesize = getpagesize()*mult_page;

	
	if (fd == -1)
	   handle_error("open");

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");

	int pos = lseek(fd, 0, SEEK_CUR);
	int off = pos%getpagesize();
	int page = floor(pos / getpagesize());

	if (addr !=NULL && page == offset+1){//TODO: ici ne rentre jamais
		cout << "if" << endl;
		int idx=0;
		p = addr;
		p+=off;
	    while (idx < getpagesize() && *p != '\n' && *p != '\r') p++, idx++;
	    return idx+1;
	}
	else{
		cout << "else" << endl;
		while (sb.st_size > 0) {
			size_t len = 4096;//20*sizeof(char), same as pagesize
			int idx=0;

			if (sb.st_size < len){
				len = sb.st_size;
				sb.st_size = 0;
			}
			else {
				sb.st_size -= len;
			}
			offset = page;

			addr =  static_cast<char*>(mmap(NULL, len, PROT_READ,MAP_PRIVATE, fd, offset*pagesize));//
			offset ++;

			if(addr == MAP_FAILED){
		        printf("Mapping Failed\n");
		        handle_error("mmap");
		    }
		    p = addr;
		    p+=off;

		    while (idx < len && *p != '\n' && *p != '\r') p++, idx++;

		    if (*p == '\n' || *p == '\r'){
		    	return idx+1;//+1 for counting the \n also
		    }
		    //m = addr;
		    /*
		    for ( int i = 0; i<len; i++ ){
		    	if (*p=='\n'){
		    		//ssize_t n = write(1 ,m, size);
		    		
		    		if(n != size){
				        printf("Write failed\n");
				    }
					
		    		m+=size;
		    		size=0;
		    		break;
		    	}
		    	p++;
		    	size++;
		    }
		    */
		    int err = munmap(addr, len);

		    if(err != 0){
		        printf("UnMapping Failed\n");
		    }
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
	open(file);
	struct stat sb;

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");
	//cout << sb.st_size <<endl;
	int line_size =1;
	int sum=0;
	while (line_size > 0 ){
		line_size = readln(1);//mettre size of buffer in def of length
		sum+=line_size;
	}
	return sum;
}

int InputStream4::randjump(string file, int j){
	int sum=0;
	int k=0;

	open(file);
	struct stat sb;

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");
	
	srand ( 1 );
	int pos = rand();
	
	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sb.st_size - 0 + 1));
		seek(pos);
		sum+=readln(1);
		k++;
	}
	return sum;
}




