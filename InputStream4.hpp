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


class InputStream4
{
public:
	InputStream4();
	~InputStream4();
	void open(string filename);
	string readln(int mult_page);
	void seek(int pos);
	bool end_of_stream();
	void close();
	int length(int mult);
	int randjump(int j, int M);
private:
	int fd;	//file descriptor
	off_t offset; //page number in memory
	char *addr; //our map
	int init;	//if we have a map in memeory init = 1, else 0
	int pos;	//position in the file
	size_t rest;//what remains to be read in the file
};
#endif