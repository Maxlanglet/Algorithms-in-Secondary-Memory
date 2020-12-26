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
	// open the file
	fd = ::open(filename.c_str(), O_RDONLY);
	if (fd == -1)
	   handle_error("open");
}


string InputStream4::readln(int mult_page){
	//42352
	string str = "";
	char *p = NULL;
	struct stat sb;
	bool edl=false;

	int pagesize = getpagesize()*mult_page;

	if (fd == -1)
	   handle_error("open");

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");

	pos = lseek(fd, 0, SEEK_CUR);

	//cout << pos << endl;

	int off = (pos%pagesize);

	//cout << off << endl;
	int page = floor((float)pos/pagesize);


	size_t len=pagesize;
	
	

	rest = sb.st_size-pos;

	if (rest == 0) return "";

	while(!edl || pos < sb.st_size){
		int idx=0;

		if (offset != page || init!=1){

			int err = munmap(addr, mult_page*getpagesize());
			init=0;
		    if(err != 0){
		        printf("UnMapping Failed\n");
		    }

			offset = page;
			
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
	    p = addr;
	    //cout << p[off] << endl;
	    p+=off;


	    while (idx+off < len && addr[idx+off] != '\n' && addr[idx+off] != '\r') str+=addr[idx+off], idx++;
	    //while (idx < len && *p != '\n' && *p != '\r') str+=*p, p++, idx++;//erreur ici sur macos bigsur ou m1
		//cout<<str<<endl;


	    if ( addr[idx+off] == '\n' || addr[idx+off] == '\r'){
	    	pos += idx+1;
	    	lseek(fd, pos, SEEK_SET);
			str+="\n";
			edl=true;
			rest-=pos;
			return str;
	    }
	    /*
	    if ( *p == '\n' || *p == '\r'){
	    	pos += idx+1;
	    	lseek(fd, pos, SEEK_SET);//changer offset
			str+="\n";
			edl=true;
			rest-=pos;
			return str;
	    }
	    */
	    else{ 
	    	//cout << "new page" << endl;
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

/*
if(jump){
	pos = lseek(fd,idx,SEEK_CUR);					//true if randjump and then add the rest to account for when the line ends on the next page
	//idx++;											//idx++ because jump to idx+1
	page++;
	offset++;
	len = pagesize;
	if (offset*pagesize >= sb.st_size){
		pagesize = getpagesize();
		len=getpagesize();
	}
	addr =  static_cast<char*>(mmap(NULL, len, PROT_READ,MAP_PRIVATE, fd, offset*pagesize));//
	p = addr;
	while (idx < len-1 && *p != '\n' && *p != '\r') str+=*p, p++, idx++;
	if (*p == '\n' || *p == '\r'){
    	pos = lseek(fd,idx+1,SEEK_CUR);
    	str+="\n";
    	return str;
    }
}
else{
	pos = lseek(fd,idx,SEEK_CUR);					//true if randjump and then add the rest to account for when the line ends on the next page
	if (idx!=0){
		return str;
	}
}
*/


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

int InputStream4::length(string file, int mult){
	//open(file);//TODO: enlever car on le fait avant 
	struct stat sb;
	seek(0);
	int line_size =1;
	int sum=0;

	offset = 1;

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");


	while (sum < sb.st_size){//sb.st_size-1
		line_size = readln(mult).size();//mettre size of buffer in def of length
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

	offset = 1;

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");
	
	srand ( 2 );
	int pos = rand();
	
	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sb.st_size - 0 + 1));
		seek(pos);
		sum+=readln(BUFFER_SIZE).size();
		k++;
	}
	int err = munmap(addr, getpagesize());
	init=0;
    if(err != 0){
        printf("UnMapping Failed\n");
    }
	return sum;
}