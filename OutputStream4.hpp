#include <iostream>
#include <string>
#include <fstream>
//#include "OutputStream.hpp"
//#ifdef _WIN32
//#include <io.h>

//#elif defined(__APPLE__)
#include <unistd.h>
//#define bswap_64(x) OSSwapInt64(x)
//#endif
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

using namespace std;


class OutputStream4// : public OutputStream enlever pour le moment
{
public:
	OutputStream4(const char* filename);
	~OutputStream4();
	void writeln(const char* str);
	void close2();
	void create();

private:
	const char* path;
	int new_file;// voir pq pas fstream
};