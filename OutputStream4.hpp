#ifndef OUTPUTSTREAM4_H
#define OUTPUTSTREAM4_H
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

using namespace std;


class OutputStream4 
{
public:
	OutputStream4();
	~OutputStream4();
	void writeln(string str, size_t B);
	void close2();
	void create(string filename);

private:
	string path;
	int new_file;
	int init;
	char *map;
	int curpage;
	int buf;
};
#endif