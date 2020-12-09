#ifndef OUTPUTSTREAM3_H
#define OUTPUTSTREAM3_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

using namespace std;


class OutputStream3// : public OutputStream enlever pour le moment
{
public:
	OutputStream3();
	~OutputStream3();
	void writeln(string str);
	void close();
	void create(string filepath);

private:
	//string path;
	int new_file;
	//ofstream* new_file_pointer;// voir pq pas fstream
};
#endif