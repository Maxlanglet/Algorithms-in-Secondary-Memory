#ifndef INPUTSTREAM3_H
#define INPUTSTREAM3_H
#endif
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


using namespace std;


class InputStream3// : public InputStream pour interface mais ca fait des erreurs de partout alors j'enleve pour le moment
{
public:
	InputStream3();
	~InputStream3();
	void open(string filename);
	int readln();
	int length(string filename);
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	//string path;
	int fd; 
	off_t offset;
	
};