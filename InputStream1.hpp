#ifndef INPUTSTREAM1_H
#define INPUTSTREAM1_H
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
#include <random>

using namespace std;


class InputStream1
{
public:
	InputStream1();
	~InputStream1();
	void open(string path);
	string readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
	int length(string file);
	int randjump(string file, int j);
private:
	off_t offset;
	int filp; 
	
};
#endif