#ifndef INPUTSTREAM3_H
#define INPUTSTREAM3_H
#endif
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>//a voir si sur windows

//#ifdef _WIN32
//#include <io.h>

//#elif defined(__APPLE__)
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
//#define bswap_64(x) OSSwapInt64(x)
//#endif
//#include "InputStream.hpp"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


using namespace std;


class InputStream3// : public InputStream pour interface mais ca fait des erreurs de partout alors j'enleve pour le moment
{
public:
	InputStream3(string filename);
	~InputStream3();
	void open2();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close2();
private:
	string path;
	fstream file;
	int fd; 
	
};