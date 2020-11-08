#include <iostream>
#include <string>
#include <fstream>
//#include "OutputStream.hpp"
#ifdef _WIN32
#include <io.h>

#elif defined(__APPLE__)
#include <unistd.h>
//#define bswap_64(x) OSSwapInt64(x)
#endif

#include <stdio.h>

using namespace std;


class OutputStream2// : public OutputStream enlever pour le moment
{
public:
	OutputStream2(const char * filename);
	~OutputStream2();
	void writeln(string str);
	void close(FILE * pFile);
	void create();

private:
	string path;
	FILE * new_file;// voir pq pas fstream
};