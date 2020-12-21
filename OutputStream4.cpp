#include "OutputStream4.hpp"
#include "typeinfo"
#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)



OutputStream4::OutputStream4(){
}

OutputStream4::~OutputStream4(){}


void OutputStream4::create(string filename){
	path = filename;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	//new_file = open(path.c_str(), O_RDWR | O_APPEND| O_CREAT , mode);
	new_file = open(path.c_str(), O_RDWR | O_APPEND| O_CREAT , mode);
	if (new_file == -1){
	   handle_error("open");
	}
}

void OutputStream4::writeln(string str){
	if(str.substr(str.length()-1) != "\n"){
	str+="\n";
	}

	// open a file to write only ->OPEN IN ANOTHER METHOD

	/*new_file = open(path.c_str(), O_RDWR | O_APPEND); // en fait pas trop de sens on le fera toujours avant soit un open ou create
	if (new_file == -1){
	   handle_error("open");
	}*/

	int filesize = lseek(new_file, 0, SEEK_END);
	
	printf("filesize is %d\n",filesize);

	// size of our map
	size_t B = getpagesize();

	// size of our text
	size_t textsize = (strlen(str.c_str())+1); // + \0 null character
	
	int pagesize = getpagesize();
	int numberpages = (-1+pagesize+textsize)/pagesize;
	printf("textsize is %ld, pagsize is %d, number of pages is %d\n",textsize,pagesize, numberpages);
	printf("B is %ld, pagsize is %d, loop is %ld\n",B,pagesize, numberpages*pagesize/B);
	int result = ftruncate(new_file, (textsize-1)+filesize);
	//lseek(new_file, filesize, SEEK_SET);
	int leftover = textsize-(numberpages * pagesize);
	int numberpagesfile = (-1+pagesize+filesize)/pagesize;
	if(numberpagesfile!=0 && (filesize%pagesize)!=0){numberpagesfile--;}
	cout << typeid(numberpagesfile).name() << endl;
	int restonpage = filesize-(numberpagesfile*pagesize);
	printf("pagefile is %d, pagsize is %d, loop is %ld, nb rest %d\n",numberpagesfile,pagesize, numberpages*pagesize/B,restonpage);
	
	
	//in case B is too big
	if(numberpages*pagesize/B == 0){
		size_t B = getpagesize();
	}
	// offset is where the map is looking at in the string
	size_t offset = 0;
	int loop = 0;
	// this will loop until we reach the end of the string, if the offset is equal or greater than
	// the size of the string, we finished to write everything
	while(loop < numberpages*pagesize/B){
		printf("offset is %zu \n", offset);

		// now we can map the file, we map a size B and begin at the offset
		char* map = static_cast<char*>(mmap(NULL, B, PROT_READ | PROT_WRITE,MAP_SHARED, new_file, ((numberpagesfile+loop)*getpagesize())));
		if (map == MAP_FAILED){
			close(new_file);
			perror("Error mmapping the file");
			exit(EXIT_FAILURE);
		}

		printf("0 \n");
		// add the char in the map
		// if there is still enough space to read an entire map of size B
		if(loop==0){
			if((textsize)>=(B-restonpage)){
			// write B minus what is already on the page char of the string in the map
			// offset here will always be 0
			for (size_t j = 0; j < (B-restonpage); j++){
				printf("CASE1-1 Writing character %c at %zu\n", str[j], j);
				map[restonpage+j] = str[j];
			}
			printf("after writing \n");
			}
			else{
				// write the char remaining in the map (not of size B)
				for (size_t j = 0; j < textsize-1; j++){
					printf("CASE2-1 Writing character %c at %zu\n", str[j], j);
					//map[restonpage+((textsize-1))+j] = str[j];
					map[restonpage+j] = str[j];
				}
			}
		}
		else{
			if((textsize-offset+restonpage)>=B){
			// write B char of the string in the map
			for (size_t j = 0; j < B; j++){
				printf("CASE1-2 Writing character %c at %zu\n", str[j+offset], j);
				map[j] = str[j+offset];
			}

			// write the entire string (size of B)
			//memcpy(map, str.c_str(), B);
			printf("after writing \n");
			}
			else{
				// write the char remaining in the map (not of size B)
				for (size_t j = 0; j < (textsize-offset+restonpage-1); j++){
					printf("CASE2-2 Writing character %c at %zu\n", str[j+offset], j);
					//map[((textsize-offset-1))+j] = str[j+offset];
					map[j] = str[j+offset-restonpage];
				}
		}
		
			// map is the destination, str.c_str is the pointer to the string,
			//add offset to only copy where we are in the string
			// textsize-offset-1 is the rest
			//memcpy(map, str.c_str()+offset, textsize-offset-1);
			printf("after writing2 \n");
		}
		printf("1 \n");
		/*for (size_t j = 0; j < textsize-offset-1; j++){
				printf("Writing character %c\n", map[j]);
		}*/
		// Write it now to disk
		msync(map, B, MS_SYNC);
		if (msync(map, B, MS_SYNC) == -1){
			perror("Could not sync the file to disk");
		}
		printf("2 \n");
		// Don't forget to free the mmapped memory
		if (munmap(map, textsize) == -1){
			close(new_file);
			perror("Error un-mmapping the file");
			exit(EXIT_FAILURE);
		}
		printf("3 \n");
		// incremente the offset of B
		offset += B;
		loop+=1;
	}
	
}

void OutputStream4::close2(){
	close(new_file);
}

