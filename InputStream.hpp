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

// Abstract class representing the input streams
class InputStream{
public:
	InputStream(string filename);
	~InputStream();
	virtual void open();
	virtual void readln();
	virtual void seek(int pos);
	virtual bool end_of_stream();
	virtual void close();
};