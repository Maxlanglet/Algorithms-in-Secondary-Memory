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


class OuputStream3// : public OutputStream enlever pour le moment
{
public:
	OuputStream3(string filename);
	~OuputStream3();
	void writeln(string str, fstream &output_file);
	void close();
	void create(string name_file);

private:
	string path;
	ofstream* new_file_pointer;// voir pq pas fstream
};