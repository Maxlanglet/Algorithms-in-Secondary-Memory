#ifndef OUTPUTSTREAM1_H
#define OUTPUTSTREAM1_H

#include <iostream>
#include <string>
#include <fstream>

#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


using namespace std;


class OutputStream1// : public OutputStream enlever pour le moment
{
public:
	OutputStream1();
	~OutputStream1();
	void writeln(string str);
	void close();
	void create(string path);

private:
	//string path;
	int new_file;// voir pq pas fstream
};
#endif
