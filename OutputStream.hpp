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


class OutputStream{
public:
	OutputStream(string filename);
	~OutputStream();
	virtual void writeln(string str, fstream &output_file);
	virtual void close();
	virtual void create(string name_file);

};