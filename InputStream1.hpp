#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>//a voir si sur windows

//#ifdef _WIN32
//#include <io.h>

//#elif defined(__APPLE__)
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
//#define bswap_64(x) OSSwapInt64(x)
//#endif
//#include "InputStream.hpp"
#include <stdio.h>

using namespace std;


class InputStream1// : public InputStream pour interface mais ca fait des erreurs de partout alors j'enleve pour le moment
{
public:
	InputStream1(string filename);
	~InputStream1();
	void open2();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close2();
private:
	string path;
	ifstream file;
	int filp; 
	
};