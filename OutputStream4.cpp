#include "OutputStream4.hpp"
#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)



OutputStream4::OutputStream4(){
}

OutputStream4::~OutputStream4(){}


void OutputStream4::create(string filename){
	path = filename;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
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


	// size of our map
	size_t B = getpagesize();

	// size of our text
	size_t textsize = (strlen(str.c_str())+1); // + \0 null character
	
	int pagesize = getpagesize();
	int numberpages = (-1+pagesize+textsize)/pagesize;
	printf("textsize is %ld, pagsize is %d, number of pages is %d\n",textsize,pagesize, numberpages);
	printf("B is %ld, pagsize is %d, loop is %ld\n",B,pagesize, numberpages*pagesize/B);
	int result = ftruncate(new_file, (textsize-1));

	int leftover = textsize-(numberpages * pagesize);

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
		char* map = static_cast<char*>(mmap(NULL, B, PROT_READ | PROT_WRITE,MAP_SHARED, new_file, loop*getpagesize()));
		if (map == MAP_FAILED){
			close(new_file);
			perror("Error mmapping the file");
			exit(EXIT_FAILURE);
		}

		printf("0 \n");
		// add the char in the map
		// if there is still enough space to read an entire map of size B
		if((textsize-offset)>=B){
			// write B char of the string in the map
			//for (size_t j = 0; j < B; j++){
			//	printf("CASE1 Writing character %c at %zu\n", str[j+offset], j);
			//	map[j] = str[j+offset];
			//}
			memcpy(map, str.c_str(), B);
			printf("after writing \n");
		}
		else{
			// write the char remaining in the map (not of size B)
			//for (size_t j = 0; j < textsize-offset-1; j++){
			//	printf("CASE2 Writing character %c at %zu\n", str[j+offset], j);
			//	map[j] = str[j+offset];
			//}
			memcpy(map, str.c_str()+offset, textsize-offset-1);
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

