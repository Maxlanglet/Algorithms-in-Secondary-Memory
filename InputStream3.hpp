#include <iostream>
#include <string>
#include <fstream>
#ifdef _WIN32
#include <io.h>

#elif defined(__APPLE__)
#include <unistd.h>
//#define bswap_64(x) OSSwapInt64(x)
#endif

#include <stdio.h>

using namespace std;


class InputStream3{
public:
	InputStream3(string filename);
	~InputStream3();
	void open();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	string path;
	fstream file;
	
};