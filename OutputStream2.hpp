#ifndef OUTPUTSTREAM2_H
#define OUTPUTSTREAM2_H

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>

using namespace std;


class OutputStream2
{
public:
	OutputStream2();
	~OutputStream2();
	void writeln(string str);
	void close();
	void create(const char * filename);
private:
	FILE * new_file;
};
#endif