#include "Timer.hpp"
#include "OutputStream1.hpp"
#include "InputStream1.hpp"
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

//#include <boost/iostream/devices/mmapped_file.hpp>



#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


int main(int argc, char* argv[]){

	string title = "/Users/langletmaxime/Desktop/Database Systems Architecture/Algorithms in Secondary Memory/imdb/role_type.csv";

	printf("Test InputStream1\n\n");

	InputStream1 instream(title.c_str());

	//InputStream2 instream2(title.c_str());
	instream.open();
	//stream.seek_pos(9); //test de seek_pos
{
	Timer timer;
	instream.readln();
}
	//instream.close();



	printf("Test InputStream3\n\n");
//Test InputStream3
	InputStream3 instream3(title.c_str());

	instream3.open();
	//stream.seek_pos(9); //test de seek_pos
{
	Timer timer;
	instream3.readln();
}
	instream3.close();
	instream.close();

	 printf("Test MMAP\n\n");
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
	OutputStream1 outstream;
	outstream.create();
	//fstream hello("hello.txt");//voir si y a pas un moyen mieux mais c est deja ca 
	outstream.writeln("hello");
	//outstream.close();  //segmentation fault a cause de close je pense pbm avec pointeur
	return 0;
}