#ifndef INPUTSTREAM2_H
#define INPUTSTREAM2_H
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
using namespace std;


class InputStream2
{
public:
	InputStream2();
	~InputStream2();
	void open(const char* path);
	string readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
	int length();
	int randjump(int j);
	int sizeoffile();
private:
	FILE * file;
	int offset;
	int res;

};
#endif