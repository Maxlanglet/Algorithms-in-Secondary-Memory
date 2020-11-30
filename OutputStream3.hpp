#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
//#include "OutputStream.hpp"
//#ifdef _WIN32
//#include <io.h>

//#elif defined(__APPLE__)
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
//#define bswap_64(x) OSSwapInt64(x)
//#endif

#include <stdio.h>

using namespace std;


class OutputStream3// : public OutputStream enlever pour le moment
{
public:
	OutputStream3(string filename);
	~OutputStream3();
	void writeln(string str);
	void close2();
	void create();

private:
	string path;
	int new_file;
	//ofstream* new_file_pointer;// voir pq pas fstream
};