#include <iostream>
#include <string>
#include <fstream>
#ifdef _WIN32
#include <io.h>

#elif defined(__APPLE__)
#include <unistd.h>
//#define bswap_64(x) OSSwapInt64(x)
#endif
#include "InputStream.hpp"
#include <stdio.h>

using namespace std;


class InputStream2{
public:
	InputStream2(char filename);
	~InputStream2();
	void open();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	const char* path;
	FILE * file;
	
};