#include "InputStream4.hpp"
#define BUFFER_SIZE 1

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
	// opens the file in reading mode
	fd = ::open(filename.c_str(), O_RDONLY);
	if (fd == -1)
	   handle_error("open");
}

/*Implementation of the readln method with mapping
mult_page is an integer that specifies the number of pages to map when calling mmap
Returns the string of the read line 
*/
string InputStream4::readln(int mult_page){
	string str = "";
	struct stat sb;
	bool edl=false;

	int pagesize = getpagesize()*mult_page;

	if (fd == -1)
	   handle_error("open");

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");

	pos = lseek(fd, 0, SEEK_CUR); //position in the file
	int off = (pos%pagesize);	  //position in the page 
	int page = floor(pos/pagesize); //number of page in which we are currently

	size_t len=pagesize;	//length to map/unmap
	rest = sb.st_size-pos;

	if (rest == 0) return "";

	while(!edl || pos < sb.st_size){
		int idx=0;
		if (offset != page || init!=1){
			int err = munmap(addr, len+1);
			init=0;
		    if(err != 0){
		        printf("UnMapping Failed\n");
		    }

			offset = page;
			if (offset*pagesize >= sb.st_size){
				pagesize = getpagesize();
				len=offset*pagesize - sb.st_size;
			}
			addr =  static_cast<char*>(mmap(NULL, len+1, PROT_READ,MAP_PRIVATE, fd, offset*pagesize));
			init=1;
		}

		if(addr == MAP_FAILED){
	        printf("Mapping Failed\n");
	        handle_error("mmap");
	    }


	    while (idx+off < len && addr[idx+off] != '\n' && addr[idx+off] != '\r') str+=addr[idx+off], idx++;
	    if ( addr[idx+off] == '\n' || addr[idx+off] == '\r'){
	    	pos += idx+1;
	    	lseek(fd, pos, SEEK_SET);
			str+="\n";
			edl=true;
			rest-=pos;
			return str;
	    }
	    else{ 
			pos += idx;
			lseek(fd, pos, SEEK_SET);
			len=pagesize;
			rest-=pos;
			idx=0;
			off=0;
			page++;
		}
	}
	return str;
}

/*Change the position pointer place in the file*/
void InputStream4::seek(int pos){
	lseek (fd, pos, SEEK_SET);
}

/*Returns true if the end of the file is reached*/
bool InputStream4::end_of_stream(){
	int bytes_read = 1;

	if((bytes_read = lseek (fd, offset, SEEK_SET)) == -1){
		return true;
	}
	else{
		return false;
	}
}

/*Closes the file associated to the stream*/
void InputStream4::close(){
	::close(fd);
}

/*Sequential reading 
Reads the entire file sequentially by calling readln until the line size is equal to 0
mult is the number of pages to map at a time
Returns the length of everything read
*/
int InputStream4::length(int mult){
	struct stat sb;
	seek(0);
	int line_size =1;
	int sum=0;

	offset = 1;

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");


	while (sum < sb.st_size){
		line_size = readln(mult).size();
		sum+=line_size;
	}

	int err = munmap(addr, getpagesize()); //Unmap the last mapped region once we are finished from reading 
	init=0;			//to make sure we remap at the next call (for real benchmarking)
    if(err != 0){
        printf("UnMapping Failed\n");
    }
	return sum;
}

/*Reads through the file randomly
j is the number of randomized jumps M the number of pages to map
*/
int InputStream4::randjump(int j, int M){
	int sum=0;
	int k=0;

	struct stat sb;
	seek(0);

	offset = 1;

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");
	
	srand ( 2 );
	int pos = rand();
	
	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sb.st_size - 0 + 1));
		seek(pos);
		sum+=readln(M).size();
		k++;
	}
	int err = munmap(addr, getpagesize());
	init=0;
    if(err != 0){
        printf("UnMapping Failed\n");
    }
	return sum;
}