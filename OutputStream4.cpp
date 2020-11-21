#include "OutputStream4.hpp"
#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)



OutputStream4::OutputStream4(string filename){
	path = filename;
}

OutputStream4::~OutputStream4(){}

/*
The open() function shall establish the connection between a file and a file descriptor. 
It shall create an open file description that refers to a file and a file descriptor that refers to that open 
file description. 
The file descriptor is used by other I/O functions to refer to that file. The path argument points to a pathname naming the file.

O_WRONLY
Open for writing only.

O_CREAT
If the file exists, this flag has no effect except as noted under O_EXCL below. 
Otherwise, the file shall be created; the user ID of the file shall be set to the effective user ID of the process; 
the group ID of the file shall be set to the group ID of the file's parent directory or to the effective group ID of the process; 
and the access permission bits of the file mode shall be set to the value of the third argument taken as type mode_t modified as follows: a bitwise AND is performed on the file-mode bits and 
the corresponding bits in the complement of the process' file mode creation mask. 
Thus, all bits in the file mode whose corresponding bit in the file mode creation mask is set are cleared. 
When bits other than the file permission bits are set, the effect is unspecified. 
The third argument does not affect whether the file is open for reading, writing, or for both. 
Implementations shall provide a way to initialize the file's group ID to the group ID of the parent directory.
Implementations may, but need not, provide an implementation-defined way to initialize the file's group ID to the effective group ID of the calling process.

O_TRUNC:
If the file exists and is a regular file, and the file is successfully opened O_RDWR or O_WRONLY, 
its length shall be truncated to 0, and the mode and owner shall be unchanged. 
It shall have no effect on FIFO special files or terminal device files. 
Its effect on other file types is implementation-defined. The result of using O_TRUNC with O_RDONLY is undefined.

*/
void OutputStream4::create(){
	//new_file =open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	new_file = creat(path.c_str(), mode);
	if (new_file == -1){
	   handle_error("open");
	}
}


void OutputStream4::open2(){
	// open the file
	new_file = open(path.c_str(), O_RDWR | O_APPEND); 
	if (new_file == -1){
	   handle_error("open");
	}
}

void OutputStream4::writeln(string str){
	// open a file to write only ->OPEN IN ANOTHER METHOD
	/*
	new_file = open(path.c_str(), O_APPEND); // en fait pas trop de sens on le fera toujours avant soit un open ou create
	if (new_file == -1){
	   handle_error("open");
	}
	*/

	int offset = 0;

	char *addr= NULL;

	struct stat sb;

	int pagesize = getpagesize();

	//string + \n

	if (fstat(new_file, &sb) == -1) 
	  handle_error("fstat");

	int sizetobe = sb.st_size+str.size()/pagesize;

	int result = ftruncate(new_file, sizetobe);

	if (result == -1){
		handle_error("ftruncate");
	}
	cout << sb.st_size+str.size() << endl;
	//check result

	size_t len = 4096;

	if (sb.st_size==0){
		len=0;
	}

	else offset = (int)floor(sb.st_size/pagesize);

	int rest = sb.st_size%pagesize;
	int leftover = rest+str.size();

	while (leftover>0){

		if (leftover>pagesize){
			len = pagesize;
			leftover-=pagesize;
		}
		else{
			len = leftover;
			leftover=0;
		}

		addr =  static_cast<char*>(mmap(NULL, len, PROT_READ,MAP_PRIVATE, new_file, offset*pagesize));//
		offset++;

		if(addr == MAP_FAILED){
	        printf("Mapping Failed\n");
	        handle_error("mmap");
	    }

	    for (int i=0; i<len; i++){
			addr[rest+i] = str[i];
		}
		//addr[len+str.size()] = '\n';

		addr+=rest;
		rest=0;


		ssize_t n = write(new_file ,addr, len);


	    int err = munmap(addr, len);

	    if(err != 0){
	        printf("UnMapping Failed\n");
	    }
	}


	//TODO: pas oublier condition au cas ou page presque remplie
	// et voir comment augmenter taille char* sans par apres devoir copier
	//TODO: pas oublier condition au cas ou page presque remplie

	//char* addr2 = (char*) malloc(sizeof(char)*len+str.size()+1);
	//addr = addr2;


	//TODO: trouver meilleur moyen que for loop

	

	//free(addr2); //TODO: voir pq on doit pas le mettre
	
}
/*
	// size of our map
	size_t B = 2*sizeof(char);

	// size of our text
	size_t textsize = (strlen(str)+1); // + \0 null character
	printf("text is %lu long\n",textsize);

	int result = ftruncate(new_file, (textsize-1)*getpagesize());


	// offset is where the map is looking at in the string
	size_t offset = 0;
	int loop = 0;
	// this will loop until we reach the end of the string, if the offset is equal or greater than
	// the size of the string, we finished to write everything
	while(offset < textsize){
		printf("offset is %zu \n", offset);

		// now we can map the file, we map a size B and begin at the offset
		char* map = static_cast<char*>(mmap(NULL, B, PROT_READ | PROT_WRITE,MAP_SHARED, new_file, loop*getpagesize()));
		if (map == MAP_FAILED){
			close(new_file);
			perror("Error mmapping the file");
			exit(EXIT_FAILURE);
		}


		// add the char in the map
		// if there is still enough space to read an entire map of size B
		if((textsize-offset)>=B){
			// write B char of the string in the map
			//for (size_t j = 0; j < B; j++){
			//	printf("CASE1 Writing character %c at %zu\n", str[j+offset], j);
			//	map[j] = str[j+offset];
			//}
			memcpy(map, str, B);
		}

		else{
			// write the char remaining in the map (not of size B)
			//for (size_t j = 0; j < textsize-offset-1; j++){
			//	printf("CASE2 Writing character %c at %zu\n", str[j+offset], j);
			//	map[j] = str[j+offset];
			//}
			memcpy(map, str, textsize-offset-1);
		}
		printf("1 \n");
		for (size_t j = 0; j < textsize-offset-1; j++){
				printf("Writing character %c\n", map[j]);
		}
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
	
	

    // Un-mmaping doesn't close the file, so we still need to do that.
    close2();
    */

	// we want the file to be the size of the string we put
	/*if (lseek(new_file, getpagesize(), SEEK_SET) == -1){
        close(new_file);
        perror("Error calling lseek() to 'stretch' the file");
        exit(EXIT_FAILURE);
    }
	// add this to have the right size
	if (write(new_file, "", 1) == -1){
        close(new_file);
        perror("Error writing last byte of the file");
        exit(EXIT_FAILURE);
    }*/

void OutputStream4::close2(){
	close(new_file);
}

