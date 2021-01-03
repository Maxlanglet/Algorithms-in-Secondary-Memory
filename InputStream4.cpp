#include "InputStream4.hpp" 

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


InputStream4::InputStream4(){
	offset = 0;		//page number in memory
	addr = NULL;	//our map
	init=0;	//if we have a map in memeory init = 1, else 0
	pos = 0; //position in the file
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
	string str = "";  //the line that will be output by the function
	struct stat sb;   // to mesure the size of the file
	bool edl=false;  //true when a end of line charater has been read

	int pagesize = getpagesize()*mult_page;  // gives the size of the buffer in our function call

	if (fd == -1)
	   handle_error("open");	//handling error when cannot open file

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");	//mesuring the size of the file

	pos = lseek(fd, 0, SEEK_CUR); //position in the file
	int off = (pos%pagesize);	  //position in the page 
	int page = floor(pos/pagesize); //number of page in which we are currently

	size_t len=pagesize;	//length to map/unmap
	rest = sb.st_size-pos;	//what remains to be read in the file

	if (rest == 0) return "";//if we are at the end, return emprty

	while(!edl || pos < sb.st_size){	//loop until we read a endo of line character or until we reached the end of file

		int idx=0;	//idx will keep track of how many characters we read so far

		if (offset != page || init!=1){		//if the page already in memory is different than the page number or if idx =0, then remap next page
			int err = munmap(addr, len+1);
			init=0;
		    if(err != 0){
		        printf("UnMapping Failed\n");
		    }

			offset = page;
			
			addr =  static_cast<char*>(mmap(NULL, len+1, PROT_READ,MAP_PRIVATE, fd, offset*pagesize));
			init=1;
		}

		if(addr == MAP_FAILED){
	        printf("Mapping Failed\n");
	        handle_error("mmap");
	    }

	    //This while loop reads the map in memory until we have a end of line character. Then seeks the position and returns the line.
	    //Else it will remap.
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
	struct stat sb;		//mesures the size of the file
	seek(0);			//making sure that we start from the beginning of the file
	int line_size =1;	//initialization of lin_size
	int sum=0;	 	 	//sum of all characters read so far

	offset = 1;			//to make sure we map the first page

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");


	while (sum < sb.st_size){	//loop until we reach the end of the file
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
	int sum=0; //sum of all characters read so far
	int k=0;	//number of random jumps done so far

	struct stat sb;	//mesures the size of the file
	seek(0);

	offset = 1;	//to make sure we map the first page

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");
	
	srand ( 2 );	//initialize the random number generator
	int pos = rand();
	
	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sb.st_size - 0 + 1));	//computation of the random position
		seek(pos);													//seeking to that position
		sum+=readln(M).size();										//reading the rest of the line
		k++;
	}
	int err = munmap(addr, getpagesize());//Unmap the last mapped region once we are finished from reading 
	init=0;	 	 	 	//to make sure we remap at the next call (for real benchmarking)
    if(err != 0){
        printf("UnMapping Failed\n");
    }
	return sum;
}