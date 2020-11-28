#include "Timer.hpp"
#include "OutputStream1.hpp"
#include "InputStream1.hpp"
#include "OutputStream2.hpp"
#include "InputStream2.hpp"
#include "OutputStream3.hpp"
#include "InputStream3.hpp"
#include "OutputStream4.hpp"
#include "InputStream4.hpp"

int main(int argc, char* argv[]){

	string title = "./role_type.csv";
	//string title = "C:/Users/User/Downloads/MA1/DB ARCHITECTURE/projet/role_type.csv";

	printf("Test InputStream1\n\n");
	InputStream1 instream ; //if () considers it a function in main 
	instream.open(title.c_str());
{
	Timer timer;
	cout << "length is " << instream.length(title) << endl;
}
	instream.close();



	printf("Test InputStream2\n");
//Test InputStream2

	InputStream2 instream2;
	
	instream2.open(title.c_str());
	//stream.seek_pos(9); //test de seek_pos
{
	Timer timer;
	/*cout<< instream2.readln() <<endl;
	cout<< instream2.readln() <<endl;
	cout<< instream2.readln() <<endl;*/
	cout<<"length is " << instream2.length(title) <<endl;
}
	instream2.close();

/*
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
	 string titlemap = "../imdb/complete_cast.csv";//role_type.csv
	 InputStream4 instream4(titlemap.c_str());

	 instream4.open2();
{
	Timer timer;
	instream4.readln();
}
	instream4.close2();
*/
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
	/*
	OutputStream2 outstream2(title2.c_str());
	outstream2.create();
	outstream2.writeln("hello");
	*/
/*
	string title4="hellonew.txt";
	OutputStream4 outstream4(title4.c_str());
	//outstream4.create();
	outstream4.open2();
	string str = "yoyoyoyyoy";
	cout << "beginning" << endl;
	outstream4.writeln(str.c_str());
	outstream4.close2();
	//outstream.close();  //segmentation fault a cause de close je pense pbm avec pointeur
	*/
	return 0;
}