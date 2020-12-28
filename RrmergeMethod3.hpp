#ifndef RRMERGEMATHOD3_H
#define RRMERGEMATHOD3_H
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
#include "InputStream3.hpp" 
#include "OutputStream1.hpp"
#include "OutputStream2.hpp"
#include "OutputStream3.hpp"
#include "OutputStream4.hpp"

using namespace std;


class RrmergeMethod3
{
public:
	RrmergeMethod3();
	~RrmergeMethod3();
	void rrmerge1(string outputfile, int Br, int num, ... );
	void rrmerge2(string outputfile, int Br, int num, ... );
	void rrmerge3(string outputfile, int Br, int Bw, int num, ... );
	void rrmerge4(string outputfile, int Br, int Bw, int num, ... );
private:
};
#endif