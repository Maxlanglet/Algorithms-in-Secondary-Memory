#include <iostream>
#include <string>
#include <fstream>

//#ifdef _WIN32
//#include <io.h>

//#elif defined(__APPLE__)
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
//#define bswap_64(x) OSSwapInt64(x)
//#endif
//#include "InputStream.hpp"
#include <stdio.h>


using namespace std;


class InputStream4// : public InputStream pour interface mais ca fait des erreurs de partout alors j'enleve pour le moment
{
public:
	InputStream4(string filename);
	~InputStream4();
	void open2();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close2();
private:
	string path;
	int fd;
	off_t offset;
	
};