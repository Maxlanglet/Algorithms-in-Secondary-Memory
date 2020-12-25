#ifndef MERGESORT
#define MERGESORT
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <cstdarg>
#include <math.h>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cctype>
#include<assert.h>
#include <vector>
#include "InputStream2.hpp"
#include "InputStream3.hpp"//remove after
#include "OutputStream1.hpp"
#include "OutputStream2.hpp"
#include "OutputStream3.hpp"
#include "OutputStream4.hpp"

using namespace std;


class mergesort
{
public:
	mergesort();
	~mergesort();
	void extsort(string inputfile, int k, int M, int d);
	//bool compare(const string& first, const string& sec, const int k);
private:
	//InputStream4 instream4;
	int column;
};
#endif