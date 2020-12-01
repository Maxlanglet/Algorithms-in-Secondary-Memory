#ifndef INPUTSTREAM4_H
#define INPUTSTREAM4_H
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <math.h> 

using namespace std;


class InputStream4// : public InputStream pour interface mais ca fait des erreurs de partout alors j'enleve pour le moment
{
public:
	InputStream4();
	~InputStream4();
	void open(string filename);
	int readln(int mult_page);
	void seek(int pos);
	bool end_of_stream();
	void close();
	int length(string file);
	int randjump(string file, int j);
private:
	//string path;
	int fd;
	off_t offset;
	char *addr;
	
};
#endif