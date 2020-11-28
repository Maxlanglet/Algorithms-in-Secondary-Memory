#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class InputStream1// : public InputStream pour interface mais ca fait des erreurs de partout alors j'enleve pour le moment
{
public:
	InputStream1();
	~InputStream1();
	void open(string path);
	int readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
	int length(string file);
private:
	//string path;
	off_t offset;
	int filp; 
	
};