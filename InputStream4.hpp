#include <iostream>
#include <string>
#include <fstream>
#ifdef _WIN32
#include <io.h>

#elif defined(__APPLE__)
#include <unistd.h>
//#define bswap_64(x) OSSwapInt64(x)
#endif
//#include "InputStream.hpp"
#include <stdio.h>


using namespace std;


class InputStream4// : public InputStream pour interface mais ca fait des erreurs de partout alors j'enleve pour le moment
{
public:
	InputStream4(string filename);
	~InputStream4();
	void open();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	string path;
	fstream file;
	
};