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
	OutputStream();
	~OutputStream();
	void writeln(string str);
	void close();
	void create(string name_file);

private:
	string path;
	ofstream new_file;// voir pq pas fstream
};