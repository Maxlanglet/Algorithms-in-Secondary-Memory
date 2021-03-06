#ifndef INPUTSTREAM3_H
#define INPUTSTREAM3_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <random>


using namespace std;


class InputStream3
{
public:
	InputStream3();
	~InputStream3();
	void open(string filename);
	string readln(int buf_size);
	int length(int buf_size);
	void seek(int pos);
	bool end_of_stream();
	void close();
	int randjump(int j, int buffer);
private:
	int fd; 
	off_t offset;
	int buffer_size ; 
	
};
#endif