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

//#include <boost/iostream/devices/mmapped_file.hpp>




int main(int argc, char* argv[]){

	string title = "./role_type.csv";
	//string title = "C:/Users/User/Downloads/MA1/DB ARCHITECTURE/projet/role_type.csv";

	printf("Test InputStream1\n\n");

	InputStream1 instream(title.c_str());

	//InputStream2 instream2(title.c_str());
	instream.open2();
	//stream.seek_pos(9); //test de seek_pos
{
	Timer timer;
	instream.readln();
}
	instream.close2();



	printf("Test InputStream2\n\n");
//Test InputStream2

	InputStream2 instream2(title.c_str());

	instream2.open();
	//stream.seek_pos(9); //test de seek_pos
{
	Timer timer;
	instream2.readln();
}
	instream2.close();
	printf("Fin Test InputStream2\n\n");

	printf("Test InputStream3\n\n");
//Test InputStream3
	InputStream3 instream3(title.c_str());

	instream3.open2();
	//stream.seek_pos(9); //test de seek_pos
{
	Timer timer;
	instream3.readln();
}
	instream3.close2();

	 printf("Test MMAP\n\n");

//ESSAIS DE MMAP	 Essayer Boost
	 InputStream4 instream4(title.c_str());

	 instream4.open2();
{
	Timer timer;
	instream4.readln();
}
	instream4.close2();

/*
	if (stream.end_of_stream()){// test de end of stream
		cout << "end of stream" << endl;
	}
	*/
/*
	string title2="hello2.txt";
	OutputStream1 outstream(title2.c_str());
	outstream.create();
	outstream.writeln("hello");
	outstream.close2();
*/	

	string title3="testwriteln3.txt";
	OutputStream3 outstream3(title3.c_str());
	outstream3.create();
	outstream3.writeln("mama zwina et baba zwin et koulna zwinin et denya zwina layali\n");
	outstream3.close2();

	/*
	OutputStream2 outstream2(title2.c_str());
	outstream2.create();
	outstream2.writeln("hello");
	*/
	//outstream.close();  //segmentation fault a cause de close je pense pbm avec pointeur
	return 0;
}