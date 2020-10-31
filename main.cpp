#include "Timer.hpp"
#include "OutputStream.hpp"
#include "InputStream.hpp"
#include "OutputStream2.hpp"
#include "InputStream2.hpp"
#include "OutputStream3.hpp"
#include "InputStream3.hpp"
#include "OutputStream4.hpp"
#include "InputStream4.hpp"
#ifdef _WIN32
#include <io.h>

#elif defined(__APPLE__)
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
//#define bswap_64(x) OSSwapInt64(x)
#endif
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


int main(int argc, char* argv[]){

	string title = "C:/Users/User/Downloads/MA1/DB ARCHITECTURE/projet/role_type.csv";
	InputStream2 instream(title.c_str());
	instream.open();
	//stream.seek_pos(9); //test de seek_pos
{
	Timer timer;
	instream.readln1();
}
	instream.close();

	 printf("\n");
//ESSAIS DE MMAP	 Essayer Boost
	int fd;
	fd = open(title.c_str(), O_RDONLY);
{
	Timer timer;
	char *addr;
	
	struct stat sb;

	

	if (fd == -1)
	   handle_error("open");

	if (fstat(fd, &sb) == -1)           /* To obtain file size */
	   handle_error("fstat");

	addr =  static_cast<char*>(mmap(NULL, sb.st_size, PROT_READ,
	           MAP_PRIVATE, fd, 0));

	if(addr == MAP_FAILED){
        printf("Mapping Failed\n");
        //handle_error("mmap");
        return 1;
    }

    ssize_t n = write(1,addr,sb.st_size);//obligé d etre 1 sinon pas de output

    if(n != sb.st_size){
        printf("Write failed\n");
    }
/*
    for(int i=0; i<length; i++){
        printf("[%d] ",addr[i]);
    }
    */

    printf("\n");
    
    int err = munmap(addr, sb.st_size);

    if(err != 0){
        printf("UnMapping Failed\n");
        return 1;
    }

}
    close(fd);


/*
	if (stream.end_of_stream()){// test de end of stream
		cout << "end of stream" << endl;
	}
	*/
	OutputStream outstream;
	outstream.create("hello.txt");
	//fstream hello("hello.txt");//voir si y a pas un moyen mieux mais c est deja ca 
	outstream.writeln("hello");
	//outstream.close();  //segmentation fault a cause de close je pense pbm avec pointeur
	return 0;
}