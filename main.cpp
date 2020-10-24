<<<<<<< Updated upstream
#include "Timer.hpp"
#include "OutputStream.hpp"
#include "InputStream.hpp"
#include <io.h>
#include <stdio.h>


int main(int argc, char* argv[]){

	InputStream instream("/Users/langletmaxime/Desktop/Database Systems Architecture/Algorithms in Secondary Memory/imdb/role_type.csv");
	instream.open();
	//stream.seek_pos(9); //test de seek_pos
{
	Timer timer;
	instream.readln1();
}
/*
	if (stream.end_of_stream()){// test de end of stream
		cout << "end of stream" << endl;
	}
	*/
	OutputStream outstream("/Users/langletmaxime/Desktop/Database Systems Architecture/Algorithms in Secondary Memory/imdb/role_type.csv");
	outstream.create("hello.txt");
	fstream hello("hello.txt");//voir si y a pas un moyen mieux mais c est deja ca 
	outstream.writeln1("hello", hello);
	instream.close();
	return 0;
=======
#include "Timer.hpp"
#include "OutputStream.hpp"
#include "InputStream.hpp"
#include <io.h>
#include <stdio.h>


int main(int argc, char* argv[]){

	InputStream instream("/Users/langletmaxime/Desktop/Database Systems Architecture/Algorithms in Secondary Memory/imdb/role_type.csv");
	instream.open();
	//stream.seek_pos(9); //test de seek_pos
{
	Timer timer;
	instream.readln1();
}
/*
	if (stream.end_of_stream()){// test de end of stream
		cout << "end of stream" << endl;
	}
	*/
	OutputStream outstream("/Users/langletmaxime/Desktop/Database Systems Architecture/Algorithms in Secondary Memory/imdb/role_type.csv");
	outstream.create("hello.txt");
	fstream hello("hello.txt");//voir si y a pas un moyen mieux mais c est deja ca 
	outstream.writeln1("hello", hello);
	instream.close();
	return 0;
>>>>>>> Stashed changes
}