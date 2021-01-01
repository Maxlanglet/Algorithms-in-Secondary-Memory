#include "OutputStream4.hpp"
#include "typeinfo"
#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


//Initializes the attributes of the class
OutputStream4::OutputStream4(){
	map = NULL;
	init=0;
	curpage=0;
	buf=0;
}

OutputStream4::~OutputStream4(){}

/*
Creates the file which name is the parameter path
If the file already exists its content is emptied
*/
void OutputStream4::create(string filename){
	path = filename;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	new_file = open(path.c_str(), O_RDWR | O_TRUNC| O_CREAT , mode);
	if (new_file == -1){
	   handle_error("open");
	}
}

/*
Implementation of the writeln method with mapping
B is the integer corresponding to the number of pages to map when calling mmap
*/
void OutputStream4::writeln(string str, size_t B){
	
	int pagesize = getpagesize();

	// size of our map
	if (B % getpagesize())
    	B = B + (getpagesize() - B % getpagesize());
	// size of file
	int filesize = lseek(new_file, 0, SEEK_END);

	// size of our text
	size_t textsize = (strlen(str.c_str())+1); // + \0 null character
	
	//resize the file
	int result = ftruncate(new_file, (textsize-1)+filesize);

	//number of pages occupied by the current file
	int numberpagesfile = (-1+pagesize+filesize)/pagesize;

	if(numberpagesfile!=0 && (filesize%pagesize)!=0){numberpagesfile--;}


	//what is left on the last page
	int restonpage = filesize-(numberpagesfile*pagesize);
	//number of pages needed for the text
	int numberpages = ceil(((-1+pagesize+textsize)/pagesize)+(restonpage/pagesize));


	//in case B is too big
	if(numberpages*pagesize/B == 0){
		B = getpagesize();
	}
	
	// offset is where the map is looking at in the string
	size_t offset = 0;

	int loop = 0;
	// this will loop until we reach the end of the string, if the offset is equal or greater than
	// the size of the string, we finished to write everything
	while(loop < numberpages*pagesize/B){

		// add the char in the map
		// if there is still enough space to read an entire map of size B
		if(loop==0){
			// in case we must write at a new page
			if ((numberpagesfile != curpage || init!=1)){
				if(init==1){
					// Write it now to disk
					if (msync(map, B, MS_SYNC) == -1){
						perror("Could not sync the file to disk");
					}
					int err = munmap(map, B);
					init=0;
					if(err != 0){
						printf("UnMapping Failed\n");
					}
				}
				

				map =  static_cast<char*>(mmap(NULL, B, PROT_READ | PROT_WRITE,MAP_SHARED, new_file, ((numberpagesfile+loop)*getpagesize())));
				buf=B;
				init=1;
				curpage=numberpagesfile+loop;
			}
			if(B!=buf){
				B=buf;
			}
			if((textsize)>=(B-restonpage)){
				// write B minus what is already on the page char of the string in the map
				// offset here will always be 0
				for (size_t j = 0; j < (B-restonpage); j++){
					map[restonpage+j] = str[j];
				}
			}
			else{
				// write the char remaining in the map (not of size B)
				for (size_t j = 0; j < textsize-1; j++){
					map[restonpage+j] = str[j];
				}
			}
		}
		else{
			// Write it now to disk
			if (msync(map, B, MS_SYNC) == -1){
				perror("Could not sync the file to disk");
			}
			int err = munmap(map, B);
			init=0;
			if(err != 0){
				printf("UnMapping Failed\n");
			}
			map = static_cast<char*>(mmap(NULL, B, PROT_READ | PROT_WRITE,MAP_SHARED, new_file, ((numberpagesfile+loop)*getpagesize())));
			curpage=numberpagesfile+loop;
			init=1;
			if((textsize-offset+restonpage)>=B){
				// write B char of the string in the map
				for (size_t j = 0; j < B; j++){
					map[j] = str[j+offset];
				}
			}
			else{
				// write the char remaining in the map (not of size B)
				for (size_t j = 0; j < (textsize-offset+restonpage-1); j++){
					map[j] = str[j+offset-restonpage];
				}
		}
		

	}

		// incremente the offset of B
		offset += B;
		loop+=1;
	}
	
}

/*
Closes the file associated to the stream
*/
void OutputStream4::close2(){
	close(new_file);
}

