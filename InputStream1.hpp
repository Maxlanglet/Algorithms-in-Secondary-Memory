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


class InputStream1{
public:
	InputStream1(string filename);
	~InputStream1();
	void open();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	string path;
	ifstream file;
	
};