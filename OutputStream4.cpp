#include "OutputStream4.hpp"
#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)



OutputStream4::OutputStream4(const char* filename){
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
	new_file = creat(path, mode);
	if (new_file == -1){
	   handle_error("open");
	}
}


void OutputStream4::writeln(const char* str){
	// open a file to write only
	new_file = open(path,  O_RDWR|O_APPEND|O_TRUNC|O_CREAT,S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (new_file == -1){
	   handle_error("open");
	}
	// size of our map
	size_t B = 20*sizeof(char);

	// size of our text
	size_t textsize = strlen(str) + 1; // + \0 null character

	printf("before seeking \n");
	// we want the file to be the size of the string we put
	if (lseek(new_file, textsize-1, SEEK_SET) == -1)
    {
        close(new_file);
        perror("Error calling lseek() to 'stretch' the file");
        exit(EXIT_FAILURE);
    }
	if (write(new_file, "", 1) == -1)
    {
        close(new_file);
        perror("Error writing last byte of the file");
        exit(EXIT_FAILURE);
    }
	
	printf("before mapping \n");
	// this loop will check until we reach the end of the string
	size_t offset = 0;
	while(offset < textsize){
		
		// now we can map the file
		char* map = static_cast<char*>(mmap(NULL, B, PROT_READ | PROT_WRITE,MAP_SHARED, new_file, offset));
		if (map == MAP_FAILED)
		{
			close(new_file);
			perror("Error mmapping the file");
			exit(EXIT_FAILURE);
		}
		// for the size of our map, we write what is in the string str
		
				//as long as there is a character
		if((textsize-offset>=B)){
			for (size_t j = 0; j < B; j++){
				printf("Writing character %c at %zu\n", str[j+offset], j);
				map[j] = str[j+offset];
			}
		}
		else{
			for (size_t j = 0; j < textsize-offset-1; j++){
				printf("Writing character %c at %zu\n", str[j+offset], j);
				map[j] = str[j+offset];
			}
		}
		printf("1 \n");
		// Write it now to disk
		if (msync(map, B, MS_SYNC) == -1)
		{
			perror("Could not sync the file to disk");
		}
		printf("2 \n");
		// Don't forget to free the mmapped memory
		if (munmap(map, textsize) == -1)
		{
			close(new_file);
			perror("Error un-mmapping the file");
			exit(EXIT_FAILURE);
		}
		printf("3 \n");
		// incremente the offset of B
		offset += B;
	}
	
	

    // Un-mmaping doesn't close the file, so we still need to do that.
    close2();
}

void OutputStream4::close2(){
	close(new_file);
}

