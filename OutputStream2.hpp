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


class OuputStream2{
public:
	OuputStream2(string filename);
	~OuputStream2();
	void writeln(string str, fstream &output_file);
	void close();
	void create(string name_file);

private:
	string path;
	ofstream* new_file_pointer;// voir pq pas fstream
};