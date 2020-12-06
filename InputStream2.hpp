#ifndef INPUTSTREAM2_H
#define INPUTSTREAM2_H
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
using namespace std;


class InputStream2// : public InputStream pour interface mais ca fait des erreurs de partout alors j'enleve pour le moment
{
public:
	InputStream2();
	~InputStream2();
	void open(const char* path);
	int readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
	int length(string filename);
	int randjump(string file, int j);
private:
	//const char * path;
	FILE * file;
	int offset;
};
#endif