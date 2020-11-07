#include "Timer.hpp"

#include "InputStream.hpp"
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
//#define bswap_64(x) OSSwapInt64(x)
#endif
#include <stdio.h>


int main(int argc, char* argv[]){

	InputStream4 instream("./role_type.csv");
	instream.open();
	instream.readln();
	
	//stream.seek_pos(9); //test de seek_pos
{
	Timer timer;
	//instream.readln();
}
	instream.close();
/*
	if (stream.end_of_stream()){// test de end of stream
		cout << "end of stream" << endl;
	}
	*/
	/*ghita did this 
	OutputStream outstream;
	outstream.create("hello.txt");
	//fstream hello("hello.txt");//voir si y a pas un moyen mieux mais c est deja ca 
	outstream.writeln("hello");
	//outstream.close();  //segmentation fault a cause de close je pense pbm avec pointeur
	return 0;*/
}