
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


class OutputStream1// : public OutputStream enlever pour le moment
{
public:
	OutputStream1(string filename);
	~OutputStream1();
	void writeln(string str);
	void close();
	void create();

private:
	string path;
	ofstream new_file;// voir pq pas fstream
};