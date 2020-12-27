#ifndef RRMERGEMATHOD2_H
#define RRMERGEMATHOD2_H
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
#include "InputStream2.hpp" 
#include "OutputStream1.hpp"
#include "OutputStream2.hpp"
#include "OutputStream3.hpp"
#include "OutputStream4.hpp"

using namespace std;


class RrmergeMethod2// : public InputStream pour interface mais ca fait des erreurs de partout alors j'enleve pour le moment
{
public:
	RrmergeMethod2();
	~RrmergeMethod2();
	void rrmerge1(string outputfile, int num, ... );
	void rrmerge2(string outputfile, int num, ... );
	void rrmerge3(string outputfile, int B, int num, ... );
	void rrmerge4(string outputfile, int B, int num, ... );
private:
};
#endif