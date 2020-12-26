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
	string readln(int mult_page);
	void seek(int pos);
	bool end_of_stream();
	void close();
	int length(string file, int mult);
	int randjump(int j, int M);
private:
	//string path;
	int fd;
	off_t offset;
	char *addr;
	int init;
	int pos;
	size_t rest;
	bool jump;
};
#endif